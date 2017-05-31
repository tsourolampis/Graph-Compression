# Simple graph compression 

Generates a compressed representation of a graph, given as 
an edge file with the following format. The first line contains the number of nodes n, and edges m, and then m lines follow, one per edge. Nodes are numbered from 0 to n-1. 

- Compile using g++ -o compress compress.cc 
- Example: ./compress < toy.txt > toycompressed.txt

