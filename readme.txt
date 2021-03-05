README FILE_PROJECT 3: Samit Basnet
CPS222: Computer Science III
==================================================================================================

Project 3: Shortest Path
--------------------------------------------------------------------------------------------------
This project applies different algorithms to find out the shortest path in the graph. It uses Dijkstra's algorithm (adjacency matrix), Dijkstra's algorithm (adjacency list) and bellmanFord Algorithms to calculate the shortest path between the source and other vertices. It uses <chrono> to calculate the most efficient algorithm for this purpose
--------------------------------------------------------------------------------------------------

Files included in the project:
**************************************************************************************************
readGraph.hpp/cpp, shortestPath.hpp/cpp, BinaryHeap.hpp/cpp, bellmanFord.cpp,
readGraph_TEST.cpp, shortestPath_TEST.cpp, BinaryHeap_TEST.cpp, Makefile
**************************************************************************************************
readGraph.hpp/cpp, readGraph_TEST.cpp

-This is the backbone of the program that reads the graph file fed in the program. There are three implementations of readGraph. The first version gives out a matrix consisting of weights between the two vertices. The second implementation gives adjacency list and the third implementation gives out edge list for the weight.

Compile: make readGraph_TEST
Run: ./readGraph_TEST
**************************************************************************************************
shortestPath.hpp/cpp
shortestPath_TEST.cpp	

-This is a core part of our program that contains the implementation of Dijkstra's algorithm using adjacency matrix and adjacency list, and the bellmanFord algorithm. These algorithms are individually used in the program to calculate the shortest path in the given graph file from a source vertex to the destination vertices.

Compile: make shortestPath_TEST
Run: ./shortestPath_TEST
**************************************************************************************************
BinaryHeap.hpp/cpp
BinaryHeap_TEST.cpp

-This is the implementation of Binary Heap of the form minimum heap that sorts the graph such that the first item is always the minimum of all the numbers. It uses percolation in order to sort the heap when an item is removed.

Compile: make BinaryHeap_TEST
Run: ./BinaryHeap_TEST 
**************************************************************************************************
matrixDijkstra.cpp, listDijkstra.cpp, bellmanFord.cpp

-These files are the main functions for the three implementations we use in this program in order to run through a graph and find the shortest path.It is implemented using File I/O such that it reads an input graph file and prints out the edges and to each vertex along the shortest path in a different file. It takes four command line arguments:  

Compile: make matrixDijkstra,make listDijkstra, make bellmanFord
Run: [input file] [output file] [source vertex name] [destination vertex name]
Note: destination vertex is not required for listDijkstra and bellmanFord as it calculates the shortest path to all the vertices from the source
**************************************************************************************************
Makefile: This facilitates compilation of all the abovementioned files including finding out their coverage using make coverage. 
**************************************************************************************************

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Issues
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
1. The implementation of BinaryHeap is not perfect. It doesn't meet many edge cases.
2. The algorithm used for some methods are certainly not the most efficient ones.
3. Although best efforts were made, some of the edge cases might have gone unnoticed in some functions.
4. getPath fails to track down the path in some cases. 
5. matrixDijkstra, listDijkstra haven't been tested for graphs with negative weights.
6. The implementation of Bellman-Ford Algorithm might have some bugs.
7. bellmanFord.cpp doesn't given the output file in the same format as shown in the project.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Coverage for Unit Tests: passed

