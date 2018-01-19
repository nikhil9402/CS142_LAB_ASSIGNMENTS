#include <iostream>
using namespace std;

class node{		//creates a node containing data and a pointer 'next'
	public:     	//makes the data and the pointer accessible from outside
	int data;
	node* next;
};

class linkedList{	//creates a linked list
	private:	
		node *head;
		node *tail;	// creates two private pointers head and tail of the linked list which cannot be accessed from outside the class

	public:			// can be accessed through outside the class
	
	linkedList(){		//constructer which automatically works whenever the class linkedList is called
		head = NULL;
		tail = NULL; 	//makes the pointers head and tail to point towards NULL
	}

	void insert(int x){	//inserts a node to the linked list
		node* temp = new node;	//creates a new node with pointer temp pointing towards that node
		temp->data = x;		//makes the data = x 
		temp->next = NULL;	//makes the pointer next to points towards NULL
		if (head != NULL){	//if there already exist a linked list, then inserts the node at the last
			tail->next = temp;		
			tail = temp;
		}
		else {	//if there doesnot exist any in the linked list node then creates a node and makes both head and tail points towards that single node
		head = temp;
		tail = temp;
		}
			
	}

	int size(){		//counts the no. of nodes in the linked list
		node* q;
		q=head;
		int a = 0;
		for (int i=0; q!=NULL; i++){
			q=q->next;
			a++;
		}
		return a;
		}

	void insertAT(int pos, int x){  //here, in the linked list, 1st node has pos = 1 and so on
		

 		int size = this->size();	// uses size function of the linked list to calculate the no. of nodes 
		if (pos<=size+1){
		node *temp = new node;
		temp->data = x;
		temp->next = NULL;
		
		
		node *p =head;

		for(int i=1; i<pos-1; i++) 
		{
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
		}
		else {
			cout << "Linked list does not have that many elements." << endl;
		
		}
	}	


	void display(){		//displays the element of the linked list
		node *temp = head;
		
		while (temp != NULL){
		cout << temp->data << " -> ";
		temp = temp->next;
		}
		
		cout << "NULL" << endl;
	}

	void delete_end(){	//deletes the end node of the linked list
		node *temp;
		temp = head;
		while (temp->next != tail){
			temp = temp->next;
		}
		tail = temp;
		temp = temp->next;
		tail->next = NULL;
		delete temp;
	} 
	
	void deleteAt(int pos){		//deletes the node at a particular position	
		
		node *p;
		node *temp;
		p=head;
		temp=head;

		for(int i=1; i<pos-1; i++) 
		{
			temp = temp->next;
		}
	
		
		for(int i=1; i<pos; i++) 
		{
			p = p->next;
		}
		temp->next = p->next;
		delete p;
		
	}
};

int main(){

	linkedList l1;   //creating a linked list l1
	l1.insert(1);	//calls the insert function and inserts a node in the linked list
        l1.display();	//displays the linked list using display function of the linked list
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.display();
	l1.insertAT(2,3); // inserting node containing data = 3  at position 2	
        l1.display();
	l1.deleteAt(2);
        l1.display();
	l1.delete_end();
	l1.display();
	
return 0;
}
