#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "BinaryHeap.hpp"
#include <iostream>

TEST_CASE("TESTING BinaryHeap class")
{
  
  SECTION("Default Constructor")
  {
    int numItems=5;
    double* priorities=new double[numItems];

    for(int i=0; i<numItems;i++)
    {
      priorities[i]=i;
    }

    BinaryHeap a=BinaryHeap(priorities, numItems);

    REQUIRE(a.getPriority(1)==1);
    REQUIRE(a.getItem(1)==1);
    REQUIRE(a.getPos(1)==1);

    a.decreasePriority(1,0.5);

    REQUIRE(a.getPriority(1)==0.5);

    REQUIRE(a.getMin()==0);

    REQUIRE(a.contains(10)==false);
    REQUIRE(a.contains(3)==true);

    a.popMin();
    REQUIRE(a.contains(0)==false);
    REQUIRE(a.getMin()==1);

    REQUIRE(a.getSize()==4);

    REQUIRE(a.getItem(3)==4); 
    REQUIRE(a.getPos(4)==3);

    /*
      Testing with double weights && not in the same increasing order as our heap
    **/
    
  }
}


