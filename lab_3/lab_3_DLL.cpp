#include <iostream>
using namespace std;

class node{	//declares a class node
	public:		// makes the data assessible to all
	int data;	//defines data in the node as integer type
	node* next;	 
	node* prev; 	//declares two pointers next and prev
};

class dll{		//declares a class doubly linked list
	private:	//stores private pointers pointers head and tail
	node* head;
	node* tail;	
	
	public:		//makes the function assessible from outside
	dll(){		//a constructer
		head = NULL;
	 	tail = NULL;
	}
	
	void insert(int d){	//inserts a node at the end of linked list
		node *temp = new node;	//creates a new node with a temporary pointer
		temp->data = d;		//stores data in the node
		temp->next = NULL;	//makes the next pointer points to NULL
		
		if (head == NULL){	//condition (if no node is present in the dll
			head = temp;	
			temp->prev = NULL;
		}

		else {
			temp->prev = tail;
			tail->next = temp;
		}

		tail = temp;
	}

	int countItems(){	//counts the no. of nodes in the dll
		int N=0;	//initialises N to be integer with value = 0
		node *temp = head;	//makes a new pointer temp pointing to first node
 		while (temp != NULL){	//a loop to count
			temp = temp->next;
			N++;
			}
		return N;	//returns the value of N whenever it is called
		}

	void insertAt(int pos, int d){	//inserts node at a given position
		int n = this->countItems();	//uses another function to count 

		if (pos>n+1){
			cout << "Linked list does not have that many elements!!!" << endl;
		}

		else {
		node *p = new node;
		p->data = d;
		node *temp =head;
		for (int i=0;i<pos-2;i++){
			temp = temp->next;
			}
		temp->next->prev = p;
		p->next = temp->next;
		p->prev = temp;
		temp->next = p;
		}
	}
	
	void display(){		//displays the nodes
	node* temp = head;
	while (temp != NULL){
		cout << temp->data << " -> ";
		temp = temp->next;
	} 
	cout << "NULL" << endl;
	}

	void deleteEnd(){	//deletes the node at the end
		node* temp = tail->prev;
		tail = temp;
		temp = temp->next;
 		tail->next = NULL;
		delete temp;
	}
	
	void deleteAt(int pos){	//deletes the node at a given position
		node* temp = head;
		int n = this->countItems(); 
		if(pos>1 && pos<n){	//use of conditions
			for (int i=0; i<pos-1; i++){
				temp = temp->next;
				}
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			}
		else if (pos == 1){
			head = head->next;
			head->prev = NULL;
		        cout << head->data << endl;
			delete temp;
		 	}
		else if (pos == n){	//deletes the last node
			temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
 			}
		else{
			cout << "This linked list has not that many elements" << endl;
			}
	}
};

int main(){
	dll l1;
	for (int i=0; i<5; ++i) {	/*loop to make nodes in the linked list*/
		l1.insert(i+1);
	}
	l1.display();
	l1.insert(6);		
	l1.display();
	cout << "No. of nodes in the linked list now = " << l1.countItems() << endl;
	l1.insertAt(2,0);	//calls the function insertAt of dll
	l1.display();
	l1.insertAt(9,23);
	l1.display();
	l1.deleteEnd();
	l1.display();
	l1.deleteAt(2);
	l1.display();
	l1.deleteAt(5);
	l1.display();
	l1.deleteAt(1);
	l1.display();
	l1.deleteAt(13);
	l1.display();
        return 0;
}
