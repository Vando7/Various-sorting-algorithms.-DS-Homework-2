#include "resultheap.h"

resultheap::resultheap()
	:
	size(0),
	capacity(10),
	asc(false)
{
	dataArr = new result[10];
}

resultheap::~resultheap(){
		delete[] dataArr;
}

void resultheap::print(){
	if (!asc)
		for (int i = 0; i < size-1; ++i) 
			dataArr[i].print();	
	else
		for (int i = size - 2; i >= 0; --i) 
			dataArr[i].print();	
}

void resultheap::insert(const char * buffer){

	if (size == capacity-1) {
		// Whenever the array is full, expand by 10.
		result* newArr = new result[capacity + 10];

		for (int i = 0; i < size; ++i) 
			newArr[i].copyFrom(dataArr[i]);
		
		newArr[size].processBuffer(buffer);
		
		++size;
		capacity += 10;

		dataArr = newArr;
		newArr = nullptr;

		return;
	}

	dataArr[size].processBuffer(buffer);
	++size;
}

void resultheap::Heapify(unsigned int idx)
{
	unsigned int l = 2 * idx;
	unsigned int r = 2 * idx + 1;;
	unsigned int lowest;

	if (dataArr[l].ageLess(dataArr[idx]) && l < size)
		lowest = l;
	else
		lowest = idx;

	if (dataArr[r].ageLess(dataArr[lowest]) && r < size)
		lowest = r;

	if (lowest != idx){
		swap(dataArr[idx], dataArr[lowest]);
		Heapify(lowest);
	}
}

void resultheap::BuildMaxHeap() {
	for (int i = size / 2; i > 1; --i) {
		Heapify(i);
	}
}


void resultheap::sort(const char* way){
	int sizeBackup = size;
	BuildMaxHeap();
	
	--size;

	while (size>2) {
		--size;
		Heapify(0);
		swap(dataArr[0], dataArr[size]);
	}

	if (strcmp(way, "asc") == 0)
		asc = true;

	size = sizeBackup;
}

void resultheap::swap(result & a, result &b){
	result temp;
	temp.copyFrom(a);
	a.copyFrom(b);
	b.copyFrom(temp);
}
