#include <iostream>
using namespace std;


int length = 0;
int heap[100];				//declares a heap

void insert(int key){			//inserts an element
	heap[length] = key;
	int i=length;
	int p=(i-1)/2;

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

void delete_root(){

	int a = heap[0];             //copy the last element of the array in the root.
	int b = heap[length-1];
	heap[0] = b;
	heap[length-1] = a;

	length--;			//decreases the loop length by 1.
	
	int current_node = 0;
	int i = current_node;

	while(heap[current_node] < (heap[(2*i)+1] || heap[(2*i)+2])){ 
		if(2*current_node+1 > length-1){		//no children
			break;
		}

		else if(2*current_node+1 == length-1){		//one children
			if(heap[current_node] < heap[2*current_node+1]){
				a = heap[current_node];
				b = heap[2*current_node+1];
				heap[current_node] = b;
				heap[2*current_node+1] = a;
			}
		}

		else if(2*current_node+1 < length-1){ 		//two children
			if(heap[current_node] < heap[2*current_node+1]){
				
			}
		}	
	}


}


int main(){
	
	insert(30);
	insert(40);
	insert(20);
	insert(25);
	insert(50);
	insert(100);
	insert(12);

	for (int j=0;j<length;j++){
		cout << heap[j] << endl;
	}
	return 0;
}
