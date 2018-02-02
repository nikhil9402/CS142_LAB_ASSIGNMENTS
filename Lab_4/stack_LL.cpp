#include <iostream>
using namespace std;
	
class node{	//declares a class
	public:
	int data;
	node* next;
};

class stackLL{	//again declares another class
	private:
	node* top;	
	
	public:
	stackLL(){	//constructor
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
			cout << "The stack is : "<< endl;
			while(temp != NULL) {
			 	cout << temp->data << endl;
				temp = temp->next;
				}
			}
		cout << endl;
		}
	};

int main (){
	stackLL s1;
	s1.display();	//calls the display function
	for(int i=0; i<5; i++){	//uses a loop to push
		s1.push(i);
		}
	s1.display();	//displays stack
	s1.pop();
	s1.display();

	return 0;
	}

			
		

