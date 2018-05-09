#include "resultlist.h"

resultlist::resultlist()
	:
	size(0)
{
	first = new Node;
	last = first;
}

resultlist::~resultlist(){
	while (first)
		remove();
}

resultlist::resultlist(const char *path)
{
	size = 0;
	first = new Node;
	last = first;

	std::fstream file;
	file.open(path, std::fstream::in);

	if (!file.is_open()) {
		std::cout << "\n>Error opening file.\n";
		return;
	}

	char buffer[128];
	file.getline(buffer, 128);

	while (file) {
		file.getline(buffer, 128);
		insert(buffer);
	}
}

void resultlist::insert(result &a){
	if (!size) {
		first->data.copyFrom(a);
		++size;
		return;
	}
	last->next = new Node;
	last = last->next;
	last->data.copyFrom(a);
	++size;
}

void resultlist::insert(const char *a){

	last->next = new Node;
	last = last->next;
	last->data.processBuffer(a);
	++size;
}

void resultlist::remove(){
	if (first) {
		Node* temp = first;
		first = first->next;
		delete temp;
		--size;
	}
}

void resultlist::print(){
	Node* temp = first;
	
	if (!asc) 
		reversePrint(temp);
	
	else
		while (temp) {
			temp->data.print();
			temp = temp->next;
		}
}

void resultlist::reversePrint(Node* temp){
	if (temp->next) {
		reversePrint(temp->next);
	}
	temp->data.print();
}

bool resultlist::isEmpty(){
	return !size;
}

void resultlist::sort(const char* order){
	if (strcmp(order, "asc") == 0)
		asc = true;
	else
		asc = false;

	Node* temp = first;
	mergesort(&temp);
}

Node * resultlist::mergeSorted(Node *temp1, Node *temp2)
{
	Node* output = nullptr;

	if (!temp1)
		return temp2;
	else if (!temp2)
		return temp1;

	if (temp1->data.dateLess(temp2->data)) {
		output = temp1;
		output->next = mergeSorted(temp1->next, temp2);
	}
	else {
		output = temp2;
		output->next = mergeSorted(temp1, temp2->next);
	}

	return output;
}

void resultlist::split(Node *main, Node **front, Node **rear){
	Node* alpha;
	Node* beta;
	if (!main || !main->next) {
		*front = main;
		*rear = nullptr;
	}
	else {
		beta = main;
		alpha = main->next;
		
		while (alpha) {
			alpha = alpha->next;
			if (alpha) {
				beta = beta->next;
				alpha = alpha->next;
			}
		}

		*front = main;
		*rear = beta->next;
		beta->next = nullptr;
	}
}

void resultlist::mergesort(Node **main){
	Node* peak = *main;
	Node* temp1;
	Node* temp2;
	if (!peak || !peak->next)
		return;
	split(peak, &temp1, &temp2);
	mergesort(&temp1);
	mergesort(&temp2);
	*main = mergeSorted(temp1, temp2);
}

void resultlist::push(Node& beg,result &a)
{
	Node* tmp = new Node;
	tmp->data.copyFrom(a);
	tmp->next = &beg;
	beg = *tmp;
}

void resultlist::insertAfter(Node* member,result& ins ){
	if (member == last) {
		insert(ins);
	}

	Node* temp = new Node;
	temp->next = member->next;
	member->next = temp;
	temp->data.copyFrom(ins);
}

Node * resultlist::findNameLess(Node* beg,const result a)
{
	while (beg&&beg->next) {
		if (beg->data.nameLess(a) && beg->next->data.nameGreater(a)) {
			return beg;
		}
		beg = beg->next;
	}

	while (beg->next) 
		beg = beg->next;
	
	return beg;
}


void resultlist::insertionSort(const char* way)
{
	asc = (strcmp(way, "asc") == 0);

	if (!first)
		return;

	first = first->next;
	Node* output = new Node;
	Node* iterator = first->next;
	output->data.copyFrom(first->data);

	while (iterator&& !iterator->data.isEmpty()) {

		if (output->data.nameGreater(iterator->data)) {
			Node* temp = new Node;
			temp->data.copyFrom(iterator->data);
			temp->next = output;
			output = temp;
			iterator = iterator->next;
			continue;
		}

		Node* tmp = findNameLess(output, iterator->data);
		insertAfter(tmp, iterator->data);
		iterator = iterator->next;
	}
	
	while (size)
		remove();

	first = new Node;
	last = first;

	while (output) {
		insert(output->data);
		output = output->next;
	}
}

void resultlist::selectionSort(const char * way)
{
	asc = (strcmp(way, "asc") == 0);
	
	if (!first)
		return;

	Node* it1 = first->next;
	Node* it2 = it1;
	Node* min = it1;

	while(it1){
		while (it2) {
			if (it2->data.subjectLess(min->data)) 
				min = it2;
			
			it2 = it2->next;
		}

		// The turtle wins the race.
		if (it1 != min) {
			Node* swap = new Node;
			swap->data.copyFrom(min->data);
			min->data.copyFrom(it1->data);
			it1->data.copyFrom(swap->data);
		}

		it1 = it1->next;
		if (!it1)
			return;
		it2 = it1->next;
		min = it1;
	}
}

