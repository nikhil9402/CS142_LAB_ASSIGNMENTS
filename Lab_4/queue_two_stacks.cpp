#include <iostream>
using namespace std;

class node{  	//declares a node
public:
	int data;
	node* next;
};

class stack{	//again declares another class stack
	public:
	node* top;	
	
	public:
	stack(){	//constructor
		top=NULL;
		}
	
	void push(int d){	//pushes an element at the top
		node* temp = new node;
		temp->data = d;
		temp->next = NULL;
		if(top==NULL){
			top = temp;
			}
		else{
			temp->next = top;
			top = temp;
			}
		}

	void pop(){		//pops out an element from the top
		node* temp = top;
		top = top->next;
		delete temp;
		}
		
	void display(){		//displays the data contained in the stack
		if (top==NULL){	//handles an empty stack
			cout << "Nothing to display." << endl;
			}
		else{
			node* temp = top;
			cout << "displaying.... " << endl;
			
			while(temp != NULL) {	//loop to all the elements
			 	cout << temp->data << endl;
				temp = temp->next;
				}
			}
		cout << endl;
		}
	};


class queue_two_stacks  //another class
{

public:	

	stack s1;
	stack s2;		//declares two stack in the queue

	void enqueue(int d){	//enqueues the integer d
		cout << "Enqueueing..." << d << endl;
		s1.push(d);		//calls push function of stack
	}

	void dequeue(){		//dequeues the element from first
		cout << "Dequeueing....." << endl;
		if(s1.top == NULL){
			cout << "Nothing to enqueue" << endl;
		}
		else{
			node* temp = s1.top;
			while(s1.top != NULL){	//transfers element from s1 to s2 and reverses the order
				s1.top = s1.top->next;
				temp->next = s2.top;
				s2.top = temp;
				temp = s1.top;
			}
			s2.pop();	//pops out an element from top of s2
			node* p = s2.top;
			while(s2.top != NULL){ //puts back the elements from s2 to s1
				s2.top = s2.top->next;
				p->next = s1.top;
				s1.top = p;
				p = s2.top;
			}
		}
	}

	void displayQueue(){	//displays the queue
		s1.display();
	}

};

int main (){
	queue_two_stacks q1;
	q1.displayQueue();	//calls the display function
	for(int i=0; i<5; i++){	//uses a loop to enqueue
		q1.enqueue(i);
		}
	q1.displayQueue();	//displays queue
	q1.dequeue();	//dequeues an element first entered
	q1.displayQueue();

	return 0;
	}
