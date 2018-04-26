#include <iostream>
using namespace std;


int length = 0;
int heap[100];				//declares a heap

void insert(int key){			//inserts an element
	heap[length] = key;
	int i=length;			//new element will be added to last	
	int p=(i-1)/2;			//its parent

	while(heap[i]>=heap[p] && i!=0){	//a loop to swap the elements if it violates heap property

		int a = heap[p];		//swaps the elements if heap[i] > heap[p]
		int b = heap[i];
		heap[p] = b;
		heap[i] = a;

	    i=p;
	    p=(i-1)/2;
	    cout << "hi" << endl;
	}

	cout << "hello " << heap[length-1] << endl;
	length++;
}

void swap(int &a, int &b){		//swaps the elements
	int c = a;
	int d = b;
	a = d;
	b = c;
	return;

}

void remove_root(){				//removes the node
	heap[0] = heap[length-1];		//changes the value of the root
	length--;				//decreases the length by 1
	int i = 0;
	int l = 0;
	int r = 0;
	cout << endl;

	for(int i = 0;i<length;i++){
		l = (2*i)+1;			//left child
		r = (2*i)+2;			//right child
		if(heap[i] < heap[l]){		//if element with index i is less than its left child
			swap(heap[i],heap[(2*i)+1]);	//swap with its left child
		}
		if(heap[i] < heap[r]){		//if element with index i is less than its right child
			swap(heap[i],heap[(2*i)+2]);	//swap with its right child
		}
		
	}
}




int main(){
	
	insert(30);			//inserts element
	insert(40);
	insert(20);
	insert(25);
	insert(50);
	insert(100);
	insert(12);

	for (int j=0;j<length;j++){		//prints the heap
		cout << heap[j] << endl;
	}
	
	remove_root();			//removes the root
	for (int j=0;j<length;j++){
		cout << heap[j] << endl;
	}
	
	return 0;
}
