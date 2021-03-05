#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "shortestPath.hpp"
#include "readGraph.hpp"
#include "BinaryHeap.hpp"
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
 if(argc!=4)
   {
     cout<<"Please enter the graph file, output file and source vertex as command line arguments"<<endl;
     return 1;
   }

   ifstream inFile;
   ofstream outFile;

   inFile.open(argv[1]);
   outFile.open(argv[2]);


if (!inFile) 
{
   cerr << "Unable to open file"<<endl;
   exit(1);   // call system to stop
}

string sourceVertex=argv[3];

int** adj;
double** weights;
int* lengths;  
string* vLabels;
string** eLabels;

int vertices=readGraph(inFile, adj,weights,lengths, vLabels, eLabels); //we can adjacency list from this second function of readGraph

//for Dijsktra, we have adjacency list, weights, lengths, and no of vertices, but need source 
int source=0;
int i=0;
while(sourceVertex!=vLabels[i])
{
    i++;
}
source=i;

//we need dist and prev to pass into dijkstra
double* distance;
int* previous;

std::chrono::time_point<std::chrono::system_clock> start, end; 
start = std::chrono::system_clock::now(); 

dijkstra(adj,weights, lengths, vertices, source, distance, previous); //running dijkstra again using adjacency list

end = std::chrono::system_clock::now(); 

//shortest paths from source to all other vertices in O(e log v) time
outFile<<vertices<<" "<<6<<endl; //cause pathlength includes own vertex too
for(int i=0; i<vertices;i++) 
{
    outFile<<vLabels[i]<<endl; 
}
outFile<<endl;
for (int i = 0; i < vertices; i++) //cause 1 will be the source
{
    if(source!=i)
    {
      outFile<<source<<" "<<i<<" "<<distance[i]<<endl;
    }
}


//microseconds taken to run and print
std::chrono::duration<double> elapsed_seconds = end - start; 

std::time_t end_time = std::chrono::system_clock::to_time_t(end);   

cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n"; 

cout<<"Number of microseconds taken by Dijkstra's algorithm to run: "<<elapsed_seconds.count()<<endl;



}