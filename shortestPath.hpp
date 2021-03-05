#include <fstream>
#include <string>
#include "BinaryHeap.hpp"

using namespace std;

void dijkstra(const double* const *matrix, int numVertices, int source, double*& dist, int*& prev);

int getPath(int source, int dest, const int* prev, int*& path);

void dijkstra(const int* const* adj, const double* const* weights, const int* lengths, int numVertices, int source, double*& dist, int*& prev);

int bellmanFord(const int* const* edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev);

int getCycle(int vertex, const int* prev, int numVertices, int*& cycle);