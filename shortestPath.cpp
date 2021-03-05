#include <fstream>
#include <string>
#include "shortestPath.hpp"
#include "BinaryHeap.hpp"
#include <limits>
#include <math.h>
#include <iostream>

using namespace std;

void dijkstra(const double* const *matrix, int numVertices, int source, double*& dist, int*& prev)
{
    dist=new double[numVertices]; // The output array.  dist[i] will hold the shortest distance from source to i 
    prev=new int[numVertices]; //should be the index of the vertex just before vertex i along the shortest path
    
    for(int i=0; i<numVertices;i++)
    {
        if(i==source)
        {
            dist[i]=0;
        }
        else
        {
            dist[i]=numeric_limits<double>::infinity();
        }
        
    }

    prev[source]=-1;
    

    for(int x=0; x<numVertices;x++)         //issue with prev for vertex 2 in graph.txt
    {
        for(int y=0; y<numVertices;y++)
        {
    
           if(isinf(matrix[x][y])==false&&matrix[x][y]!=0)
            {
                if((dist[x]+matrix[x][y])<=dist[y])
                {
                    /*
                    cout<<"x: "<<x<<endl;
                    cout<<"y: "<<y<<endl;
                    cout<<"previous: "<< prev[y]<<endl;
                    cout<<"distance: "<< dist[y]<<endl;
                    **/

                    prev[y]=x;
                    dist[y]=dist[x]+matrix[x][y];
                    
                    //cout<<"updated previous: "<< prev[y]<<endl;
                    //cout<<"updated distance: "<< dist[y]<<endl;
                }
            }
        }
    }

    for(int x=0; x<numVertices;x++)         //issue with prev for vertex 2 in graph.txt
    {
        for(int y=0; y<numVertices;y++)
        {
    
           if(isinf(matrix[x][y])==false&&matrix[x][y]!=0)
            {
                if((dist[x]+matrix[x][y])<=dist[y])
                {
                    prev[y]=x;
                    dist[y]=dist[x]+matrix[x][y];
                }
            }
        }
    }

}

int getPath(int source, int dest, const int* prev, int*& path)
{
    int pathsize=1;
    int cur=dest;

    while(cur!=source)  //find the shortest number of path from source to destination
    {
        cur=prev[cur];
        pathsize++;
    }

    path=new int[pathsize]; //new array with size equal to pathsize

    //fill in the path array with the vertices in order
    cur=dest;
    path[pathsize-1]=cur; //last idx with destination
    
    for(int i=pathsize-2; i>=0; i--)
    {
        path[i]=prev[cur];
        cur=prev[cur];
    }

    return pathsize;
}

//Dijkstra's Algorithm on graphs using an adjacency list
//uses minHeap
void dijkstra(const int* const* adj, const double* const* weights, const int* lengths, int numVertices, int source, double*& dist, int*& prev)
{   
    dist=new double[numVertices];
    prev=new int[numVertices];

   for(int i=0; i<numVertices;i++)
    {
        if(i==source)
        {
            dist[i]=0;
        }
        else
        {
            dist[i]=numeric_limits<double>::infinity();
        }
        
    }

    prev[source]=-1;

    BinaryHeap binheap=BinaryHeap(dist, numVertices);
    binheap.decreasePriority(source,0); //priority of source is set to 0

    int min=binheap.getMin();
    binheap.popMin();
    dist[min]=0;

    for(int i=0; i<numVertices;i++) //from GeeksforGeeks algorithm 
    {
        for(int j=0; j<lengths[min]; j++)
        {
            int adjmatrix=adj[min][j]; //adjmatrix is an item that it gets by double indexing the adj matrix

            if(binheap.contains(adjmatrix) && ((dist[min]+weights[min][j])<binheap.getPriority(adjmatrix) ))
            {
                binheap.decreasePriority(adjmatrix,(dist[min]+weights[min][j]));
                prev[adjmatrix]=min;
            }
        }
        min=binheap.getMin();
        dist[min]=binheap.getPriority(min);
        binheap.popMin();
    }   
}

int bellmanFord(const int* const* edges, const double* weights, int numVertices, int numEdges, int source, double*& dist, int*& prev)
{
    dist=new double[numVertices]; // The output array.  dist[i] will hold the shortest distance from source to i 
    prev=new int[numVertices]; //should be the index of the vertex just before vertex i along the shortest path

    for(int i=0; i<numVertices;i++)
    {
        if(i==source)
        {
            dist[i]=0;
            
        }
        else
        {
            dist[i]=numeric_limits<double>::infinity();
            prev[i]=-1;
        }
        
    }

    for(int x=0; x<numVertices;x++)         //relaxation happens |v|-1 times
    {
        for(int y=0; y<numEdges;y++)        //goes through every edge in each iteration of x
        {
            int sourVert=edges[y][0];
            int destVert=edges[y][1];

            if((dist[sourVert]+weights[y])<dist[destVert])  //weights[y] instead of weights[destVert] 
            {
                dist[destVert]=dist[sourVert]+weights[y];  
                prev[destVert]=sourVert;

            }
        }
    }

    //CHECK FOR NEGATIVE CYCLE
    double* distArray=new double[numVertices];
    int* prevArray=new int[numVertices];

    for(int i=0; i<numVertices;i++)
    {
        distArray[i]=dist[i];
        prevArray[i]=prev[i];
    }

    int negcycle=-1; //-1 if no negative cycles

    //running the vth iteration to check if the values for dist changes
    for(int y=0; y<numEdges;y++)        //goes through every edge in each iteration of x
        {
            int sourVert1=edges[y][0];
            int destVert1=edges[y][1];

            if((dist[sourVert1]+weights[y])<dist[destVert1])
            {   
                //update dist and prev as it performs vth iteration
                dist[destVert1]=dist[sourVert1]+weights[y];  
                prev[destVert1]=sourVert1;

                //index of the vertex that was updated
                negcycle=destVert1; 

            }
        }
    return negcycle;
}

int getCycle(int vertex, const int* prev, int numVertices, int*& cycle)
{
    //vertex index returned by bellmanFord
    //use prev array to find the cycle
    //cycle is a reference to uninitialized pointer
    ////returns size of the cycle array
   
    bool* check=new bool[numVertices];
    for(int i=0;i<numVertices;i++)
    {
        check[i]=false;
    }

    int verIdx=vertex; //given by Bellman-Ford

    int i=0;
    while(i<numVertices)
    {
        i++;
        if(check[prev[verIdx]]==false)  //previous vertex from the one given by BF
        {
            check[prev[verIdx]]=true;
            verIdx=prev[verIdx];
        }
        else 
        {
            verIdx=prev[verIdx];
            break; //end as soon as a complete cycle is seen
        }
    }
    cycle=new int[i+1];  //cause we started from 0
    verIdx=vertex;
    for(int a=i; a>=0; a--)
    {
        cycle[a]=verIdx; //last item is vertex where change occured then we track back
        verIdx=prev[verIdx];

    }

    return i+1;

}


