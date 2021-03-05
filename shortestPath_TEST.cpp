#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <iostream>
#include <fstream>
#include <limits>
#include <list>

using namespace std;

TEST_CASE("TESTING shortestPath")
{

  
SECTION("Dijkstra")
{
    ifstream myfile;
    myfile.open("graph.txt");

    double** matrix;
    string* vLabels;
    string** eLabels;

    int vertices=readGraph(myfile, matrix, vLabels, eLabels);
    
    int source=0;
    
    double* distance;
    int* previous;

    dijkstra(matrix, vertices, source, distance, previous);
    

    double myints[] = {0,4.5,10, 3.2 } ;

    for(int i=0; i<vertices; i++)
    {
        //cout<<distance[i]<<endl;
        REQUIRE(distance[i]==myints[i]);

        //cout<<"previous: "<< i <<" " << previous[i]<<endl;
    }
    myfile.close();
}
    
    
SECTION("Pathsize")
{  
    ifstream myfile;
    myfile.open("graph.txt");

    double** matrix;
    string* vLabels;
    string** eLabels;

    int vertices=readGraph(myfile, matrix, vLabels, eLabels);
    
    int source=0;
    
    double* distance;
    int* previous;

    dijkstra(matrix, vertices, source, distance, previous);

    
    int destination=1;
    int* path;
    int pathsize= getPath(source, destination, previous, path);
        
    //0 to 1
    REQUIRE(pathsize==3);
        
    //Test for pathsize from 0 to 2
    source=0;
    destination=2;
    pathsize= getPath(source, destination, previous, path);
    REQUIRE(pathsize==4);
    /**
        //infinite loop, need a condition for no path
        //Test for pathsize from 2 to 0
        source=2;
        destination=0;
        pathsize= getPath(source, destination, previous, path);
        REQUIRE(pathsize==4);
      */ 
    
    //1 to 3
    source=1;
    destination=3;
    dijkstra(matrix, vertices, source, distance, previous);
    pathsize= getPath(source, destination, previous, path);
    cout<<"pathsize: "<<pathsize<<endl;
       

    for(int i=0; i<pathsize;i++)
    {
       cout<<path[i]<< " >>>>" ;
    }

    myfile.close();
}
/**
SECTION("Waleed's test case")
{
    ifstream myfile;
    myfile.open("graph.txt");

    double** matrix;
    string* vLabels;
    string** eLabels;
    int vertices=readGraph(myfile, matrix, vLabels, eLabels);

    
    
    int start = 1;
    int destination = 3;
    double* distance;
    int* previous;

    dijkstra(matrix, vertices, start, distance, previous);
    

    int* path;
        
    int pathsize = getPath(start, destination, previous, path);
    cout << "--------------------ERROR--------------" << endl;
    REQUIRE(pathsize == 3);

       

    double checkList2[] = {2, -1, 1, 2}; //to check the previous
    double checkList3[] = {1, 2, 3};
    
    for(int j = 0; j <= pathsize; j++)
        {
            REQUIRE(path[j] == checkList3[j]);
            REQUIRE(previous[j] == checkList2[j]);
        }

    myfile.close();


}

*/
SECTION("Bellman-Ford")
{
    ifstream myfile;
    myfile.open("graph.txt");

    int** edgeList;
    double* weights;
    int numEdges;
    string* vLabels;
    string* eLabels;

    int vertices=readGraph(myfile, edgeList, weights, numEdges, vLabels, eLabels);

    int source=0;
    
    double* dist;
    int* prev;

    int negcycle=bellmanFord(edgeList, weights, vertices, numEdges, source, dist, prev);

    REQUIRE(negcycle==-1); 
    double results[]={0, 4.5, 10, 3.2};

    for(int i=0; i<vertices;i++)
    {
        REQUIRE(dist[i]==results[i] );
    }
    
    double check[]={0, 3, 1, 0};
    for(int j=0; j<vertices;j++)
    {
        REQUIRE(prev[j]==check[j]);
    }



}

SECTION("Bellman-Ford with source 2")
{
    ifstream myfile;
    myfile.open("graph.txt");

    int** edgeList;
    double* weights;
    int numEdges;
    string* vLabels;
    string* eLabels;

    int vertices=readGraph(myfile, edgeList, weights, numEdges, vLabels, eLabels);

    int source=1;
    
    double* dist;
    int* prev;

    int negcycle=bellmanFord(edgeList, weights, vertices, numEdges, source, dist, prev);

    REQUIRE(negcycle==-1); 
    double results[]={8.2, 0, 5.5, 8.4};

    for(int i=0; i<vertices;i++)
    {
        REQUIRE(dist[i]==results[i] );
    }
    
    double check[]={2, 0, 1, 2};
    for(int j=0; j<vertices;j++)
    {
        REQUIRE(prev[j]==check[j]);
    }



}

SECTION("Bellman-Ford with graph2 that has negative cycle")
{
    ifstream myfile;
    myfile.open("graph2.txt");

    int** edgeList;
    double* weights;
    int numEdges;
    string* vLabels;
    string* eLabels;

    int vertices=readGraph(myfile, edgeList, weights, numEdges, vLabels, eLabels);

    int source=0;
    
    double* dist;
    int* prev;

    int negcycle=bellmanFord(edgeList, weights, vertices, numEdges, source, dist, prev);

    REQUIRE(negcycle!=-1); //cause neg cycle exists
    
    //double results[]={8.2, 0, 5.5, 8.4};

    for(int i=0; i<vertices;i++)
    {
        //REQUIRE(dist[i]==results[i] );
        cout<<dist[i];
    }
    /**
    double check[]={2, 0, 1, 2};
    for(int j=0; j<vertices;j++)
    {
        REQUIRE(prev[j]==check[j]);
    }
**/


}

SECTION("Testing getCycle")
{
    ifstream myfile;
    myfile.open("graph2.txt");

    int** edgeList;
    double* weights;
    int numEdges;
    string* vLabels;
    string* eLabels;

    int vertices=readGraph(myfile, edgeList, weights, numEdges, vLabels, eLabels);

    int source=0;
    
    double* dist;
    int* prev;

    int negcycle=bellmanFord(edgeList, weights, vertices, numEdges, source, dist, prev);

    int* cycle;

    int sizeOfCycleArray=getCycle(negcycle, prev, vertices, cycle);

    REQUIRE(sizeOfCycleArray==5);


}



}