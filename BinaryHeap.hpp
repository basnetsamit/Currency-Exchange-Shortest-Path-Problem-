#ifndef BINARYHEAP_HPP
#define BINARYHEAP_HPP
#include <string>

using namespace std;

class BinaryHeap
{ 

protected:
    int size;
    int numItems;
 
    int* position; 
    double *weights;
    int* heap;

    int getLeft(int pos);
    int getRight(int pos);
    void heapify(int pos); //minimum heapify



public:

BinaryHeap(const double* priorities, int numItems); //constructor

~BinaryHeap(); //destructor

int getMin() const; //must me O(1), returns item with minimum priority

void popMin(); //removes minimum element from the heap

bool contains(int item) const; //returns true if item is in the heap, must be O(1)

double getPriority(int item) const; //returns priority of the given item. must be O(1)

void decreasePriority(int item, double newPriority); //like bubble up, O(logn)

int getSize() const; //returns numbers of items in the heap. O(1)

int getItem(int pos) const; //returns item at given position, O(1)

int getPos(int item) const; //position of given item, O(1)

void arrange(int pos); //swaps everything based on the new priority
 





};

#endif