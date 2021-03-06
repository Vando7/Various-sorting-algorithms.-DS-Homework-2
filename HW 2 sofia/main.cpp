///
/// Data Structures homework. It basically reads a csv file and sorts it
/// by a column selected by the user and wether it shoud be in descending
/// or ascending order.
///
#include "stdafx.h"

int main()
{
	// Buffers.
	char filePath[_MAX_PATH];
	char column[10];
	char sortOrder[10];

	std::cin >> filePath >> column >> sortOrder;

	if (strcmp(column, "grade") == 0)	bucketSort(filePath, sortOrder);
	if (strcmp(column, "age")	== 0)	heapSort(filePath, sortOrder);
	if (strcmp(column, "date")  == 0)	mergeSort(filePath, sortOrder);
	if (strcmp(column, "name")  == 0)	insSort(filePath, sortOrder);
	if (strcmp(column, "subject") == 0) selSort(filePath, sortOrder);

	return 0;
}

/*
GOALS:

1) STABLE AND UNSTABLE SORT.
2) A SORT THAT DOESNT COMPARE ELEMENTS.
3) TWO O( nlog(n) ) AVERAGE TIME SORTS.
4) ATLEAST ONE SORT THAT IS MAX O( n(log(n)) ).
5) ONE LINEAR TIME SORT.
6) EACH ONE MUST SORT IN ASC. AND DESC. ORDER.

//------------------------------------------------------------------

PLAN:
- Sorting names: DONE
	Insertion sort. (all other criterias were completed at this point)

- Sorting age: DONE
	Heap sort: Unstable, in-place, n(log(n)) average, n(log(n)) max
		1),3),4),7)

- Sorting subject: DONE
	Selection sort.

- Sorting grade: DONE
	Bucket sort: Stable, O(n), doesn't compare
		1) 2) 5)

- Sorting date: DONE
	Merge sort: n(log(n)) average
		3)
*/
