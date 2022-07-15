A console application "Working with graphs" has been developed.
Application algorithm:
The application allows users to work with oriented and undirected unweighted graphs without multiple edges and loops.
The functionality described below is implemented as a console menu. The application must support the following graph storage methods:
1. Adjacency matrix
2. Incidence matrix
3. Adjacency list
4. List of edges
The application supports the following methods of input and output of the graph and results:
1. Console I/O
2. Input/output to a text file
The following functions for working with graphs are available:
1. Counting degrees of vertices for an undirected graph and half-degrees of vertices for a directed graph.
2. Counting the number of edges (for undirected)/arcs (for
oriented) graph.
3. Displaying the graph in a different representation (for example, if the graph was saved in the program as an adjacency matrix, you can display it and save it not only as a matrix adjacencies, but also in the form of an incidence matrix, an adjacency list or a list of edges).
Additional functionality:
1. graph storage in FO and FI, MFO and MFI, BFO and BMFO representations.
2. Depth and breadth traversal functions (DFS and BFS). Detour in
depth is implemented in two forms - recursively and non-recursively.

Incorrect data is not processed here, so everything must be entered according to the rules.
Cyrillic is not entered into the console.
The graphs are entered as (B)(M)F(O/I)-representations, each is entered as a string describing the list. The standard separators are zeros. Everything is also separated by spaces. Attention: for M-representations the number of vertices is entered first on a separate line. For a directed graph the default degrees are the outdegrees. Example for BMFO: 4 2 4 3 4 4 1 4 5 5

File input-output: everything is entered into the file "input.txt", output - into "output.txt". They have already been created. "output.txt" itself is cleared after the end of the program, "input.txt" is not. In order for something to be displayed in "output.txt", you need to end the program. Only directed or undirected graphs are allowed, mixed graphs are forbidden. Graph vertices must be strictly from 1 to n, where n is the number of graph vertices. If the graph has a vertex with degree 0, it is displayed in the adjacency list, depending on whether you called the degree list before. In order to enter something you need to press Enter.
