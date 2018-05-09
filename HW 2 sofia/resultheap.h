#pragma once
#include"stdafx.h"
#include"result.h"
class resultheap {
public:
	resultheap();
	~resultheap();

	void print();
	void insert(const char*);
	void sort(const char*);

private:
	void BuildMaxHeap();
	void Heapify(unsigned int);
	void swap(result&, result&);

private:
	result* dataArr;
	int size, capacity;

	bool asc; // Order of the sort.
};