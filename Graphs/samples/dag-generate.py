#!/usr/bin/env python3
"""
DAG Generator - Creates random Directed Acyclic Graphs with customizable parameters
Outputs format: "Vertex Vertex Weight" (one edge per line)

Usage:
  python dag_generator.py --vertices 10 --connectivity 0.4 --min-weight 1 --max-weight 10 [--seed 123]
  python dag_generator.py --type random --vertices 10 --connectivity 0.4 --min-weight 1 --max-weight 10 [--seed 123]
  python dag_generator.py --type layered --layers 3 --vertices-per-layer 4 --connectivity 0.6 --min-weight 1 --max-weight 10 [--seed 123]
  python dag_generator.py --help
"""

import argparse
import random
import sys
from typing import List, Tuple


class DAGGenerator:
    def __init__(self, vertices: int, min_weight: int = 1, max_weight: int = 10, 
                 connectivity: float = 0.3, seed: int = None):
        """
        Initialize the DAG generator with the given parameters.
        
        Args:
            vertices (int): Number of vertices in the graph
            min_weight (int): Minimum edge weight
            max_weight (int): Maximum edge weight
            connectivity (float): Probability of edge existence (between 0 and 1)
            seed (int, optional): Random seed for reproducibility
        """
        self.vertices = vertices
        self.min_weight = min_weight
        self.max_weight = max_weight
        self.connectivity = connectivity
        
        # Set random seed if provided
        if seed is not None:
            random.seed(seed)
    
    def generate_random_dag(self) -> List[Tuple[int, int, int]]:
        """
        Generate a random DAG with the specified parameters.
        
        Returns:
            List[Tuple[int, int, int]]: List of edges as (source, destination, weight) tuples
        """
        edges = []
        
        # To ensure acyclicity, we assign a topological order to vertices
        # and only allow edges from lower to higher vertices
        for i in range(self.vertices):
            for j in range(i + 1, self.vertices):
                # Decide if this edge exists based on connectivity parameter
                if random.random() < self.connectivity:
                    weight = random.randint(self.min_weight, self.max_weight)
                    edges.append((i, j, weight))
        
        return edges
    
    @staticmethod
    def generate_layered_dag(layers: int, vertices_per_layer: int, connectivity: float = 0.5,
                            min_weight: int = 1, max_weight: int = 10, 
                            seed: int = None) -> List[Tuple[int, int, int]]:
        """
        Generate a layered DAG where edges only go from one layer to the next.
        
        Args:
            layers (int): Number of layers
            vertices_per_layer (int): Number of vertices in each layer
            connectivity (float): Probability of edge existence between any two vertices in adjacent layers
            min_weight (int): Minimum edge weight
            max_weight (int): Maximum edge weight
            seed (int, optional): Random seed for reproducibility
            
        Returns:
            List[Tuple[int, int, int]]: List of edges as (source, destination, weight) tuples
        """
        if seed is not None:
            random.seed(seed)
            
        edges = []
        
        for layer in range(layers - 1):
            start_vertex = layer * vertices_per_layer
            next_layer_start = (layer + 1) * vertices_per_layer
            
            for i in range(start_vertex, start_vertex + vertices_per_layer):
                for j in range(next_layer_start, next_layer_start + vertices_per_layer):
                    if random.random() < connectivity:
                        weight = random.randint(min_weight, max_weight)
                        edges.append((i, j, weight))
        
        return edges


def format_edges(edges: List[Tuple[int, int, int]]) -> str:
    """
    Format the edges into the required output format.
    
    Args:
        edges (List[Tuple[int, int, int]]): List of edges as (source, destination, weight) tuples
        
    Returns:
        str: Formatted string with one edge per line
    """
    return '\n'.join(f"{src} {dst} {weight}" for src, dst, weight in edges)


def parse_args():
    """Parse and validate command line arguments."""
    parser = argparse.ArgumentParser(description='Generate a Directed Acyclic Graph (DAG) with custom parameters.')
    parser.add_argument('--type', choices=['random', 'layered'], default='random',
                        help='Type of DAG to generate (default: random)')
    parser.add_argument('--vertices', default=10, type=int, help='Number of vertices in the graph (default: 10)')
    parser.add_argument('--min-weight', type=int, default=1, help='Minimum edge weight (default: 1)')
    parser.add_argument('--max-weight', type=int, default=10, help='Maximum edge weight (default: 10)')
    parser.add_argument('--connectivity', default=0.5, type=float, help='Probability of edge existence (0.0 to 1.0)')
    parser.add_argument('--seed', type=int, help='Random seed for reproducibility')
    
    # Parameters specific to layered DAG
    parser.add_argument('--layers', type=int, help='Number of layers (for layered DAG)')
    parser.add_argument('--vertices-per-layer', type=int, help='Vertices per layer (for layered DAG)')
    
    args = parser.parse_args()
    
    # Validate arguments based on the DAG type
    if args.type == 'random' and args.vertices is None:
        parser.error("--vertices is required for random DAG type")
    
    if args.type == 'random' and args.connectivity is None:
        parser.error("--connectivity is required for random DAG type")
    
    if args.type == 'layered' and (args.layers is None or args.vertices_per_layer is None):
        parser.error("--layers and --vertices-per-layer are required for layered DAG type")
    
    if args.type == 'layered' and args.connectivity is None:
        parser.error("--connectivity is required for layered DAG type")
    
    # Validate connectivity range
    if args.connectivity is not None and not (0.0 <= args.connectivity <= 1.0):
        parser.error("--connectivity must be between 0.0 and 1.0")
    
    # Validate weight range
    if args.min_weight > args.max_weight:
        parser.error("--min-weight cannot be greater than --max-weight")
    
    return args


def main():
    """Main function to process arguments and generate the DAG."""
    args = parse_args()
    
    edges = []
    
    # Generate the appropriate type of DAG
    if args.type == 'random':
        generator = DAGGenerator(args.vertices, args.min_weight, args.max_weight, 
                                args.connectivity, args.seed)
        edges = generator.generate_random_dag()
    
    elif args.type == 'layered':
        edges = DAGGenerator.generate_layered_dag(args.layers, args.vertices_per_layer, 
                                                args.connectivity, args.min_weight, 
                                                args.max_weight, args.seed)
    
    # Print the edges in the required format
    print(format_edges(edges))


if __name__ == "__main__":
    main()
