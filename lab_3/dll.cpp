#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
};

class dll{
	public:
	node* head;
	node* tail;
	
	dll(){
		head = NULL;
	 	tail = NULL;
	}
	
	void insert(int d){
		node *temp = new node;
		temp->data = d;
		temp->next = NULL;
		
		if (head == NULL){
			head = temp;
			temp->prev = NULL;
		}

		else {
			temp->prev = tail;
			tail->next = temp;
		}

		tail = temp;
	}

	int countItems(){
		int N=0;
		node *temp = head;
 		while (temp->next != NULL){
			temp = temp->next;
			N++;
			}
		return N;
		}

	void insertAt(int pos, int d){
		int n = this->countItems();

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
	
	void display(){
	node* temp = head;
	while (temp != NULL){
		cout << temp->data << " -> ";
		temp = temp->next;
	} 
	cout << "NULL" << endl;
	}

	void deleteEnd(){
		node* temp = tail->prev;
		tail = temp;
		temp = temp->next;
 		tail->next = NULL;
		delete temp;
	}
	
	void deleteAt(int pos){
		node* temp = head;
		int n = this->countItems(); 
		if(pos>1 && pos<n){
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
		else if (pos == n){
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
	l1.insert(1);
	l1.insert(2);
	l1.display();
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	cout << "No. of nodes in the linked list now = " << l1.countItems() << endl;
	l1.display();
	l1.insertAt(2,6);
	l1.display();
	l1.insertAt(9,23);
	l1.display();
	l1.deleteEnd();
	l1.display();
	l1.deleteAt(1);
	l1.display();
	l1.deleteAt(4);
	l1.display();
	l1.deleteAt(4);
	l1.display();
	l1.deleteAt(4);
	l1.display();	
        return 0;
}
