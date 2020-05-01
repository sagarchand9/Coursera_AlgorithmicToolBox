import networkx as nx
from itertools import permutations

# This function takes as input a graph g.
# The graph is complete (i.e., each pair of distinct vertices is connected by an edge),
# undirected (i.e., the edge from u to v has the same weight as the edge from v to u),
# and has no self-loops (i.e., there are no edges from i to i).
#
# The function should return the weight of a shortest Hamiltonian cycle.
# (Don't forget to add up the last edge connecting the last vertex of the cycle with the first one.)
#
# You can iterate through all permutations of the set {0, ..., n-1} and find a cycle of the minimum weight.

def cycle_length(g, cycle):
    # Checking that the number of vertices in the graph equals the number of vertices in the cycle.
    assert len(cycle) == g.number_of_nodes()
    prev = cycle[len(cycle)-1]
    ans=0
    
    for curr in cycle:
      ans += g[prev][curr]['weight']
      prev = curr
    return ans
    
def all_permutations(g):
    # n is the number of vertices.
    n = g.number_of_nodes()
    ans = -1
    # Iterate through all permutations of n vertices
    for p in permutations(range(n)):
      l = cycle_length(g, p)
      if(ans == -1):
        ans = l
      else:
        ans = min(ans, l)

    return ans
