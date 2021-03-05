CC = g++
CFLAGS = -Wall
DEBUG = -DDEBUG -g  #-D means to define a macro name
COVERAGE = --coverage

all: shortestPath_TEST

readGraph_TEST: readGraph_TEST.cpp readGraph.cpp readGraph.hpp
	$(CC) $(CFLAGS) -o readGraph_TEST readGraph_TEST.cpp readGraph.cpp

shortestPath_TEST: shortestPath_TEST.cpp shortestPath.cpp shortestPath.hpp readGraph.hpp readGraph.cpp BinaryHeap.hpp BinaryHeap.cpp
	$(CC) $(CFLAGS) -o shortestPath_TEST shortestPath_TEST.cpp shortestPath.cpp readGraph.cpp BinaryHeap.cpp

matrixDijkstra: matrixDijkstra.cpp shortestPath.cpp shortestPath.hpp readGraph.hpp readGraph.cpp BinaryHeap.hpp BinaryHeap.cpp
	$(CC) $(CFLAGS) -o matrixDijkstra matrixDijkstra.cpp shortestPath.cpp readGraph.cpp BinaryHeap.cpp

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.hpp
	$(CC) -c BinaryHeap.cpp

BinaryHeap_TEST: BinaryHeap_TEST.cpp BinaryHeap.o catch.hpp
	$(CC) $(CFLAGS) $(CATCHINC) -o BinaryHeap_TEST.cpp BinaryHeap.o

listDijkstra: listDijkstra.cpp shortestPath.cpp shortestPath.hpp readGraph.hpp readGraph.cpp BinaryHeap.hpp BinaryHeap.cpp
	$(CC) $(CFLAGS) -o listDijkstra.cpp shortestPath.cpp readGraph.cpp BinaryHeap.cpp

bellmanFord: bellmanFord.cpp shortestPath.cpp shortestPath.hpp readGraph.hpp readGraph.cpp BinaryHeap.hpp BinaryHeap.cpp
	$(CC) $(CFLAGS) -o bellmanFord.cpp shortestPath.cpp readGraph.cpp BinaryHeap.cpp
	
readGraph_TESTcoverage: readGraph_TEST.cpp readGraph.cpp readGraph.hpp catch.hpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) readGraph_TEST.cpp readGraph.cpp

shortestPath_TESTcoverage: shortestPath_TEST.cpp shortestPath.cpp shortestPath.hpp readGraph.hpp readGraph.cpp BinaryHeap.hpp BinaryHeap.cpp catch.hpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) shortestPath_TEST.cpp shortestPath.cpp readGraph.cpp BinaryHeap.cpp

BinaryHeap_TESTcoverage: BinaryHeap_TEST.cpp BinaryHeap.o  catch.hpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) BinaryHeap_TEST.cpp BinaryHeap.o

bellmanFordcoverage: bellmanFord.cpp shortestPath.cpp shortestPath.hpp readGraph.hpp readGraph.cpp BinaryHeap.hpp BinaryHeap.cpp catch.hpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) bellmanFord.cpp shortestPath.cpp readGraph.cpp BinaryHeap.cpp

listDijkstracoverage:listDijkstra.cpp shortestPath.cpp shortestPath.hpp readGraph.hpp readGraph.cpp BinaryHeap.hpp BinaryHeap.cpp catch.hpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) shortestPath.cpp readGraph.cpp BinaryHeap.cpp

matrixDijkstracoverage: matrixDijkstra.cpp shortestPath.cpp shortestPath.hpp readGraph.hpp readGraph.cpp BinaryHeap.hpp BinaryHeap.cpp catch.hpp
	$(CC) $(CFLAGE) $(CATCHINC) $(COVERAGE) matrixDijkstra.cpp shortestPath.cpp readGraph.cpp BinaryHeap.cpp


clean:
	rm *.o; rm main;rm listDijkstra; rm shortestPath_TEST; rm readGraph_TEST;rm matrixDijkstra; rm BinaryHeap_TEST; rm bellmanFord
