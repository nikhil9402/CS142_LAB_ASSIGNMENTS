#include <iostream>
using namespace std;

class Node{	//declares a class Node
public:
	int data;
	Node* next;
};

class queue	//declares a class queue
{
private:	
	Node* front;	//declares a pointer front
	Node* rear;	//declares a pointer rear
	int k;		//declares an integer variable k
public:
	queue(){	//constructor
		front = NULL;
		rear = NULL;
		k = 0;
	}
	
	void enqueue(int d){	//pushes a node at the end
		Node* temp =new Node;
		temp->data = d;
		temp->next = NULL;
		if (front == NULL)	//condition if no node exists
		{
			front = temp;
			rear = temp;
		}
		else			//if already the queue exists
		{
			front->next = temp;
			front = temp;
		}
		k++;
	}
	void dequeue()		//pops a node out from the front
	{
		Node* temp = rear;
		rear = temp->next;
		delete temp;
		k--;
	}
	void display()		//displays the data of the node
	{	
		if(front==NULL){
			cout << "Nothing to display" << endl;
			}
		else{
			Node*temp = rear;
			for (int i = 0; i < k-1; ++i)	//loop used to display
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
		cout << endl;
		}
	}
	
	
};

int main()	//main function
{
	queue q1;	//declares a queue
	for (int i = 0; i < 5; ++i)	//pushes nodes in the queue using loop
	{
		q1.enqueue(i);
	}
	q1.display();
	q1.dequeue();
	q1.display();
	return 0;	//returns 0 to the shell
}
