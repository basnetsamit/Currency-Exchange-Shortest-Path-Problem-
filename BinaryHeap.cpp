#include <iostream>
#include "BinaryHeap.hpp"
#include <cmath>
#include <string>

using namespace std;

BinaryHeap::BinaryHeap(const double* priorities, int numItems)
{
    this->numItems=numItems; 
    size=numItems; 

    heap=new int[numItems]; //holds the actual numbers in order of its priorities based on weights
    weights=new double[numItems]; //holds priorities
    position=new int[numItems]; //array that holds the position of n

    for (int i=0; i<numItems; i++)
    {
        heap[i]=i; //initializes heap array to a number from 0 to n-1 serially
        weights[i]=priorities[i]; 
        position[i]=i; 
    }

    for(int i=floor((numItems-1)/2);i>=0;i--)  //from GeeksforGeeks algorithm
    {
        heapify(i);
    }
}

BinaryHeap::~BinaryHeap() //destructor
{
    delete[]heap;
    delete []weights;
    delete []position;
}

int BinaryHeap::getLeft(int pos)
{
    return (2*pos)+1;
}
   

int BinaryHeap::getRight(int pos)
{
    return (2*pos)+2;
}

void BinaryHeap::heapify(int pos) //heapify based on minheap properties //from GeeksforGeeks
{
    int min=pos;

    if(getLeft(pos)<numItems && weights[heap[getLeft(pos)]]<weights[heap[min]]) //
    {
        min=getLeft(pos);
    }

    if(getRight(pos)<numItems && weights[heap[getRight(pos)]]<weights[heap[min]]) 
    {
        min=getRight(pos);
    }

    if(min!=pos)
    {
        int temp=heap[pos];
        int copy=heap[min];

        heap[pos]=copy;

        position[copy]=pos;

        heap[min]=temp;
        
        position[temp]=min;

        heapify(min);
    }
}

int BinaryHeap::getMin() const //must me O(1), returns item with minimum priority
{
    return heap[0];
}

void BinaryHeap::popMin() //removes minimum element from the heap
{
    if(numItems>=1)
    {
        position[heap[0]]=-1; //position for that item set to -1 indicating that it doesn't contain it anymore
        heap[0]=heap[numItems-1];
        size--;
        heapify(0);
    }
}

bool BinaryHeap::contains(int item) const //returns true if item is in the heap,  O(1) cause we are using position array to track its index
{
    if(item<0 or item>=size)
        return false;
    
    else if(position[item]==-1)
        return false;
    
    else
    {
        return true;
    }
    
}

double BinaryHeap::getPriority(int item) const //returns priority of the given item. must be O(1)
{
    return weights[item];
}

void BinaryHeap::decreasePriority(int item, double newPriority) //like bubble up, O(logn)
{
    if(contains(item)==false or newPriority>=weights[item])
    {
        //do nothing
    }

    else
    {
        weights[item]=newPriority; 
        arrange(position[item]); //fixes the heap n O(logn) time
    }
    
}
int BinaryHeap::getSize() const //returns numbers of items in the heap. O(1)
{
    return size;
}

int BinaryHeap::getItem(int pos) const //returns item at given position, O(1)
{
    return heap[pos];
}

int BinaryHeap::getPos(int item) const //position of given item, O(1)
{
    return position[item];
}

void BinaryHeap::arrange(int pos) //new position of the item, arranges the heap, from GeeksforGeeks
{
    int temp=pos;
    int before=floor((temp-1)/2);

    while(temp>0 and weights[heap[temp]]<weights[heap[before]])
    {
        int tempo=heap[temp];
        heap[temp]=heap[before];
        position[heap[before]]=temp;
        heap[before]=tempo;
        position[tempo]=before;
        temp=before;
        before=floor((temp-1)/2);
    }

}