#include"resultlist.h"
#include"resultheap.h"
#include"resultqueue.h"
#include"sortFunctions.h"

void bucketSort(const char *path, const char *way)
{
	std::fstream file;

	file.open(path, std::fstream::in);

	if (!file.is_open()) {
		std::cout << "\n>Error opening file.\n";
		return;
	}

	char buffer[128];
	file.getline(buffer, 128);
	resultqueue buckets[5];

	while (file) {
		file.getline(buffer, 128);
		result a(buffer);
		if (a.getGrade() >= 2 && a.getGrade() <= 6)
			buckets[a.getGrade() - 2].enqueue(a);
	}

	if (strcmp(way, "asc") == 0) {
		unsigned short i = 0;
		while (i < 5) {
			while (!buckets[i].isEmpty()) {
				buckets[i].printFront();
				buckets[i].dequeue();
			}
			++i;
		}
	}
	else if (strcmp(way, "desc") == 0) {
		short i = 4;
		while (i >= 0) {
			while (!buckets[i].isEmpty()) {
				buckets[i].printFront();
				buckets[i].dequeue();
			}
			--i;
		}
	}
	file.close();
}

void mergeSort(const char * path, const char * way) {
	resultlist list(path);
	list.sort(way);
	list.print();
}

void selSort(const char * path, const char * way) {
	resultlist list(path);
	list.selectionSort(way);
	list.print();
}

void insSort(const char * path, const char * way) {
	resultlist list(path);
	list.insertionSort(way);
	list.print();
}

void heapSort(const char *path, const char *way) {
	std::fstream file;
	file.open(path, std::fstream::in);

	if (!file.is_open()) {
		std::cout << "\n>Error opening file.\n";
		return;
	}

	// Make the buffer bigger, maybe?
	char buffer[180];
	file.getline(buffer, 180);

	resultheap hey; // That's pretty good.

	while (file) {
		file.getline(buffer, 180);
		hey.insert(buffer);
	}

	hey.sort(way);
	hey.print();
}

