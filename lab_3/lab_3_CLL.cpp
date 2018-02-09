#include <iostream>
using namespace std;

class node{	//declares a class node
	public:	// makes the data assessible to all
	int data;	//defines data in the node as integer type
	node* next;
	};
	
class cll{		//declares a class circular linked list
	node* head;	//stores private pointer head
	public:		//makes the function assessible from outside
	
	cll(){		//a constructer
		head = NULL;
		}

	

	void insert(int d){		//inserts a node at the end of linked list
		int n = countItems();
		node* temp = new node;	//creates a new node with a temporary pointer
		temp->data = d;			//stores data in the node
		if (head==NULL){		//conditionn
			head = temp;
			temp->next = head;	//makes the next pointer points to head
			}
		else if(head->next == head){
			node* p = head;
			p->next = temp;
			temp->next = head;	//makes the next pointer points to head
			}
		else{
			node* p = head;
			for(int i=0;i<n-1;i++){
				p = p->next;
				}
			p->next = temp;
			temp->next = head;
			}
		}

	int countItems(){ //counts the no. of items
		int N=0;	
		node* p = head;
		if (head == NULL){
			N=0;
		}
		else if(p->next==head){
			N=1;
		}
		else{
		while(p->next!= head){
			p = p->next;
			N++;
			}
		N++;
		}
		return N;
		}

	

	void insertAt(int pos,int d){	//inserts the node at some given position
		int n = this->countItems();
		node* temp = new node;
		temp->data = d;

		if(pos == 1){		//condition if node id to be inserted at first position
			node* p = head;
			while(p->next!=head){
				p = p->next;
				}
			p->next = temp;
			temp->next = head;
			head = temp;
			}
		else if(pos==n+1){
                        node* p = head;
                        while(p->next!=head){	//makes the pointer reach at the last node
                                p = p->next;
                                }
                        p->next = temp;
                        temp->next = head;
                        }
                	
		else if(pos<n+1 && pos>1){
			node* p = head;
			int i = 0;
			while(i<pos-2){		//makes the pointer reach at required position
				p = p->next;
				i++;
				}
			temp->next = p->next;
			p->next = temp;
			}
		else 			//if unacceptable position given
			cout << "This linked list doesnot have that many elements " << endl;
		}

	void deleteEnd(){				//deletes the end element
		node* p = head;
		int n = this->countItems();
		if(n==1){
			head = NULL;
			delete p;
		}
		else{
			for(int i=0;i<n-2;i++){
				p=p->next;
			}
			node* temp = p->next;
			p->next = head;
			temp->next = NULL;
			delete temp;
		}
	}
	
	void deleteAt(int pos){		//deletes the element from some given position
		node* p = head;			
		int n=this->countItems();
		
		if(pos < 1 || pos > n){		//condition
			cout << "Linked list does not have that many nodes" << endl;
		}
		else if (pos==1 && n==1){
			
			head = NULL;
			delete p;
		}
		else if(pos==1 && n!=1){
			
			head = head->next;
			node* q = p;
			while (p->next!=q){
				p=p->next;
			}
			p->next = head;
			delete q;
		}
		else{
			int i = 0;
			while(i!=pos-2){ //makes the pointer reach at location where the node is to be deleted
				p=p->next;
				i++;
			}
			node* q = p->next; //another pointer
			p->next = q->next;
			delete q;
		}
	}



	void display(){			//displays the elements of the cll
		int n = this->countItems();
		node* temp = head;
		for(int i=0;i<n;i++){	//loop
			cout << temp->data;	
			if(temp->next != head){
				cout << "->";
				}
			temp = temp->next;
			}
		cout<< endl;
		}
};

int main(){
	cll l1; 
	int s = l1.countItems();
        l1.insert(1);
        l1.display();
       cout << "No. of nodes in the linked list now = " << l1.countItems() << endl;
		l1.insert(2);
		l1.display();
        l1.insertAt(2,0);       //calls the function insertAt of dll
        l1.display();
         cout << "No. of nodes in the linked list now = " << l1.countItems() << endl;
      	l1.insertAt(9,23);
        l1.display();
        l1.deleteEnd();
        l1.display();
        l1.deleteAt(2);
        l1.display();
        l1.deleteAt(5);
        l1.insert(2);
        l1.display();
        l1.insert(3);
        l1.display();
        l1.deleteAt(1);
        l1.display();
        l1.deleteAt(1);
        l1.display();
        return 0;
}
