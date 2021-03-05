#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "readGraph.hpp"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

TEST_CASE("TESTING readGraph"){
  
  SECTION("Part 1")
  {
      
      ifstream myfile;
      myfile.open("graph.txt");

      double** matrix;
      string* vLabels;
      string** eLabels;

      int vertices=readGraph(myfile, matrix, vLabels, eLabels);

      REQUIRE(vertices==4);

      for(int i=0; i<vertices; i++)
      {
          for(int j=0; j<vertices; j++)
          {
              cout<<matrix[i][j]<< "    ";
          }
          cout<<endl;
      }

      cout<<endl;

      myfile.close();
  }

  SECTION("Part 2")
  {
      ifstream myfile;
      myfile.open("graph.txt");

      int** adj;
      double** weights;
      int* lengths;  
      string* vLabels;
      string** eLabels;

      int vertices=readGraph(myfile, adj,weights,lengths, vLabels, eLabels);

      REQUIRE(vertices==4);

      //adj
      for(int i=0;i<vertices;i++)
      {
        cout << "adj" << "[" << i << "]: [";
			  for(int j = 0; j < lengths[i]; j++)
		  	{
			  	cout << adj[i][j];
				  if(j < lengths[i]-1)
				  {
					  cout << ", ";
				  }
        }
        cout << "]" << endl;
      }
    
      cout<<endl;

    //weights
    for(int i=0;i<vertices;i++)
      {
        cout << "weights" << "[" << i << "]: [";
			for(int j = 0; j < lengths[i]; j++)
			{
				cout << weights[i][j];
				if(j < lengths[i]-1)
				{
					cout << ", ";
				}
            }
            cout << "]" << endl;
      }
      cout<<endl;

      //lengths
    cout << "lengths: [";
      for(int i=0;i<vertices;i++)
      {
        cout << lengths[i];
        if(i<vertices-1)
            cout<<", ";
      }
      cout<<"]";

      cout<<endl;
      cout<<endl;

      //vlabels
      cout << "vLabels: [";
      for(int i=0;i<vertices;i++)
      {
        cout << vLabels[i];
        if(i<vertices-1)
            cout<<", ";
      }
      cout<<"]";
      cout<<endl;
      cout<<endl;

      //eLabels
      for(int i=0;i<vertices;i++)
      {
        cout << "eLabels" << "[" << i << "]: [";
			for(int j = 0; j < lengths[i]; j++)
			{
				cout << eLabels[i][j];
				if(j < lengths[i]-1)
				{
					cout << ", ";
				}
            }
            cout << "]" << endl;
      }
      cout<<endl;


    
      myfile.close();
  }

cout<<endl;
cout<<"Tests for edge list: "<<endl;
cout<<endl;

SECTION("Part 3")
  {
      ifstream myfile;
      myfile.open("graph.txt");

      int** edgeList;
      double* weights;
      int numEdges;  
      string* vLabels;
      string* eLabels;

      int vertices=readGraph(myfile, edgeList,weights,numEdges, vLabels, eLabels);

      REQUIRE(vertices==4);

      //edgeList
      for(int i=0;i<numEdges;i++)
      {
        cout << "edgeList" << "[" << i << "]: [";
			  for(int j = 0; j < 2; j++)
		  	{
			  	cout << edgeList[i][j];
				  if(j < 1)
				  {
					  cout << ", ";
				  }
        }
        cout << "]" << endl;
      }
    cout<<endl;

    //weights
    cout << "weights: [";
    for(int i=0;i<numEdges;i++)
      {
        cout << weights[i];
				if(i < numEdges-1)
				{
					cout << ", ";
				}
        
      }
    cout << "]" << endl;
    cout<<endl;
    //numEdges
    cout << "numEdges: " <<numEdges<< endl;
      cout<<endl;


      //vlabels
      cout << "vLabels: [";
      for(int i=0;i<vertices;i++)
      {
        cout << vLabels[i];
        if(i<vertices-1)
            cout<<", ";
      }
      cout<<"]";
      cout<<endl;
      cout<<endl;


      //eLabels
      cout << "eLabels: [";
      for(int i=0;i<numEdges;i++)
      {
        cout<<eLabels[i];
        if(i < numEdges-1)
				{
					cout << ", ";
				}
      }
      cout<<"]"<<endl;
      cout<<endl;


    
      myfile.close();
    


  }




}
