#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include "shortestPath.hpp"
#include "readGraph.hpp"
#include <chrono>

using namespace std;

int main(int argc, char *argv[])
{
 if(argc!=5)
   {
     cout<<"Please enter the graph file, output file, source vertex and destination vertex as command line arguments"<<endl;
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
string destinationVertex=argv[4];

double** matrix;
string* vLabels;
string** eLabels;
int vertices=readGraph(inFile, matrix, vLabels, eLabels); //creates an adjacency matrix

//for Dijsktra, we have matrix and vertices, but need source
int source=0;
int i=0;
while(sourceVertex!=vLabels[i])
{
    i++;
}
source=i;


double* distance;
int* previous;

std::chrono::time_point<std::chrono::system_clock> start, end; 
start = std::chrono::system_clock::now(); 
dijkstra(matrix, vertices, source, distance, previous);
end = std::chrono::system_clock::now(); 

//for getPath
int dest=0;
int j=0;
while(destinationVertex!=vLabels[j])
{
    j++;
}
dest=j;

int* path;
int pathlength=getPath(source, dest, previous, path);  //we get previous from dijkstra

outFile<<vertices<<" "<<(pathlength-1)<<endl; //cause pathlength includes own vertex too
for(int i=0; i<vertices;i++) 
{
    outFile<<vLabels[i]<<endl; 
}


int pre = path[0];
int cur;
for (int i = 1; i < pathlength; i++)
{
    cur = path[i];
    outFile << pre <<" ";
    outFile<< cur <<" ";
    outFile<<matrix[pre][cur]<<" "; //for weight
    outFile<<eLabels[pre][cur]<< " ";
    outFile<<endl;  
    
    pre = cur;
}

//calculating total weight of the shortest path
double shortestpathWeight=0.0;
int pr = path[0];
int curr = 1;
int temp;
while(curr <= pathlength-1)
{
    temp = path[curr];
    shortestpathWeight=shortestpathWeight+matrix[pr][temp];

    pr = temp;
    curr++;
}
cout<<endl;
cout<<"Total Weight of the shortest path= "<<shortestpathWeight<<endl;
cout<<endl;


//microseconds taken to run and print
std::chrono::duration<double> elapsed_seconds = end - start; 

std::time_t end_time = std::chrono::system_clock::to_time_t(end);   

cout << "finished computation at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n"; 

cout<<"Number of microseconds taken by Dijkstra's algorithm to run: "<<elapsed_seconds.count()<<endl;

}
