class bubble_sort		//class bubble sort
{
public:
	int* arraySort(int arr[], int size){	//sorts the array
		int b = 0;
		int a = 0;
		if (size == 1){			//if size==1, no need for sorting
			return arr;
		}
		else{
			for(int i=0; i<size; i++){	//two loops to swap the elements
					
				for(int j=0; j<size; j++){
					
					if(arr[i]<arr[j]){		//swaps the elements
						a = arr[i];
						b= arr[j];
						arr[i] = b;
						arr[j] = a;
					}

				}
			}
			return arr;			//returns the pointer
		}
	}

	dll linkedListSort(dll l1, int size){
		int b=0;
		int a=0;
		node* p = l1.head;		//declared pointer p = head of l1
		
		while (p != NULL){		//loops to swap the elements wherever required
			node* q = l1.head;
			while (q != NULL){	
				if (p->data < q->data){	//loop to swap
					int a = p->data;
					int b = q->data;
					p->data = b;		//swaping
					q->data = a;
				}
				q = q->next;	//points to next element
			}
			p = p->next;
		}
		return l1;		//returns the linked list

	}
};
