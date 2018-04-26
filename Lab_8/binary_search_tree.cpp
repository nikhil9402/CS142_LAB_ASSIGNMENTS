#include <iostream>
using namespace std;

class node{			//creates a node
public:
	int data;
	node* left = NULL;
	node* right = NULL;
	node* parent = NULL;
};

class bTree{			//creates a binary tree			
public:
	node* root;

	bTree(){
		root = NULL;
	}

	void insert(node* p, node* temp){       //inserts node in a bst
						//p is a pointer which will move
		int x = temp->data;

		
		if (root==NULL){		//if nothing exists
			root = temp;
		}
		
		else{
			
				if(x == p->data){	
					cout << "Element already exists" << endl;
				}
	
				if(x < p->data){		//if key is to be inserted in the left subtree
					if(p->left==NULL)
					{
							p->left = temp;
					}
					else
					{
						insert(p->left,temp);
					}
					
				}

				else{				//if key is to be inserted in the right subtree
					if(p->right==NULL){
						p->right = temp;
					}
					
					else{
						insert (p->right,temp);
					}
				}

	
			
		}
	}

	void display(node* temp){		//displays the elements
			if(temp == NULL){
				return;
			}

			else{
				
				display(temp->left);		//go to left
				cout << temp->data << endl;	//print
				display(temp->right);		//go to right

				
			
			}			
	}

	bool search(node* temp, int key){			//search key
		if (temp == NULL) {				//if key is not found
			cout << "key not found" << endl;	
			return false;
		} 

		if (temp->data == key) {			//if key is found
			cout << "key found" << endl;
			return true;
		}

		else if (temp->data < key) {			//search in right subtree
			search(temp->right, key);
		} 
		
		else {						//search in left subtree
			search(temp->left, key);
		}
		
	} 

	node* minValue(node* temp)			//gives minimum value
	{
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}

	void deleteNode(node* temp, int key)		//deletes a node
	{
		bool d = search(temp,key);		//call search function to check whether it exist or not

		if (d==true){
			

			if(temp->left == NULL && temp->right == NULL)	//if it has no child
			{
				cout << "Hello";
				delete temp;
				return;
			}

			else if(temp->left == NULL || temp->right == NULL)	//if it has 1 child
			{
				if(temp->left == NULL){
					temp->data = temp->right->data;
					delete temp->right;
				}
				
				else
				{
					temp->data = temp->left->data;
					delete temp->left;
				}
			}
			
			


		}
		else {
			cout << "key not found" << endl;
			return;
		}
	}

};

int main(){
	bTree b1;
	for (int i=0; i<20; ++i) {
		node* temp = new node;
		temp->data = i;
		b1.insert(b1.root, temp);
	}

	for (int i=0; i>-10; --i) {
		node* temp = new node;
		temp->data = i;
		b1.insert(b1.root,temp);
	}

	
	node* p = b1.root;
	/*while (p != NULL) {
		cout << p->data << endl;
		p = p->left;
	}  */
	b1.display(b1.root);
	b1.search(b1.root,9);
	b1.deleteNode(b1.root,19);
	b1.display(b1.root);

return 0;
}
