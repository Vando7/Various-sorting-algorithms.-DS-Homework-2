#pragma once
#include"result.h"
#include<iostream>
#include<fstream>

struct Node 
{
	Node* next = nullptr;
	result data;
};

class resultlist {
public:
	resultlist();
	~resultlist();
	resultlist(const char*);

	void insert(result &);
	void insert(const char*);
	void remove();
	void print();
	void reversePrint(Node*);

	bool isEmpty();

public:
	void sort(const char*);
	Node* mergeSorted(Node*, Node*);
	void split(Node*, Node**, Node**);
	void mergesort(Node**);
	void push(Node&,result&);

public:
	void insertAfter(Node*,result&);
	Node* findNameLess(Node*,const result);
	void insertionSort(const char*);

public:
	void selectionSort(const char*);

private:
	bool asc;
	Node* first;
	Node* last;
	size_t size;
};