#pragma once
#include <vector>
using namespace std;

class MinHeap
{
	vector<int> theHeap;
	int numElements;

	void heapifyDown();
	void heapifyUp();

public:
	void insert(int value);
	void remove();
	void traverse();
	void print();
	int GetSize();
};

