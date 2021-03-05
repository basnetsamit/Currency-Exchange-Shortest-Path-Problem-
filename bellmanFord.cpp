#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "shortestPath.hpp"
#include "readGraph.hpp"
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

int** edgeList;
double* weights;
int numEdges;  
string* vLabels;
string* eLabels;

int vertices=readGraph(inFile, edgeList, weights, numEdges, vLabels, eLabels);

int source=0;
int i=0;

while(sourceVertex!=vLabels[i])
{
    i++;
}
source=i;

//we need dist and prev to pass into bellman-ford
double* distance;
int* previous;

std::chrono::time_point<std::chrono::system_clock> start, end; 
start = std::chrono::system_clock::now(); 

int negcyc=bellmanFord(edgeList, weights, vertices, numEdges, source, distance, previous); 

end = std::chrono::system_clock::now(); 

std::chrono::duration<double> elapsed_seconds = end - start; 


if(negcyc!=-1)
{
    cout<<"Negative Cycle Detected! "<<endl;
    cout<<"Total Weight: "<<weights[negcyc]<<endl;
    cout<<"Runtime: "<<elapsed_seconds.count()<<"microseconds"<<endl;


outFile<<vertices<<" "<<negcyc-1 <<endl; 
for(int i=0; i<vertices;i++) 
{
    outFile<<vLabels[i]<<endl; 
}

int* cycle;
int cycsize=getCycle(negcyc,previous, vertices, cycle);
cout<<"cyclesize: "<<cycsize<<endl;

for(int i=1; i<cycsize;i++)
  {
  outFile<<cycle[i-1]<<" "<<cycle[i]<<endl;
  }

}

else
{
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
      outFile<<source<<" "<<i<<" "<<distance[i]<<" "<<endl;
    }
  }
}


}