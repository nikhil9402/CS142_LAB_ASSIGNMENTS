#include<iostream>
#include "SLList.h"
using namespace std;

class BinarySearch {
/*
 * BinarySearch class.
 * Searches for an element in an array/linked list in which
 * all elements are arranged in ascending order.
 */

	private:
		
		int searchLList(SLList l, int start, int end, int key);

	public:
		
		int searchLList(SLList l, int key);
};


int BinarySearch::searchLList(SLList l, int start, int end, int key) {
/*
 * Returns -1 if the key is not found in the linked list.
 * Returns the index of the key otherwise.
 */
	if (key > l.get(end) || key < l.get(start)) { // Checks if the key is in the LL.
		cout << "Search unsuccessful." << endl;
		return -1;
	}

	int p = (start+end)/2;
	if (l.get(p) == key) {
		return p;
	} else if (l.get(p) > key) {
		searchLList(l, p, end, key);
	} else {
		searchLList(l, start, p, key);
	}
}

int BinarySearch::searchLList(SLList l, int key) {
/*
 * Returns -1 if the key is not found in the linked list.
 * Returns the index of the key otherwise.
 */
	return searchLList(l, 1, l.countItems(), key);
}

int main() {

	return 0;
}
