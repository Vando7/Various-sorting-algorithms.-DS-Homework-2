#pragma once
#include"result.h"

struct node {
	node* next = nullptr;
	result data;
};

class resultqueue {
public:
	resultqueue();
	~resultqueue();

	void enqueue(result &);
	void dequeue();
	void printFront();

	bool isEmpty();

private:
	node* front;
	node* back;
	size_t size;
};