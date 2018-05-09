#include "resultqueue.h"

resultqueue::resultqueue(){
	front = new node;
	back = front;
	size = 0;
}

resultqueue::~resultqueue(){
	while (front) {
		node * temp = front;
		front = front->next;
		delete temp;
	}
}

void resultqueue::enqueue(result & _result){
	back->data.copyFrom(_result);
	back->next = new node;
	back = back->next;
	++size;
}

void resultqueue::dequeue(){
	if (front) {
		node* temp = front;
		front = front->next;
		delete temp;
		--size;
	}
}

void resultqueue::printFront(){
	front->data.print();
}

bool resultqueue::isEmpty(){
	return !front;
}
