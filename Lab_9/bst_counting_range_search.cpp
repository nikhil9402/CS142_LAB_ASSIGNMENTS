#include <iostream>
using namespace std;

class node{				//creates a node
public:
	int data;
	node* left = NULL;
	node* right = NULL;
	node* parent = NULL;
};

class bTree {				//creates a binary tree
public:
	node* root;

	bTree(){
		root = NULL;
	}

	void insert(node* p, node* temp){	//inserts node in a bst
						//p is 
		int x = temp->data;

		if (root==NULL){		//if nothing exists
			root = temp;
		}
		
		else{				
			
	
				if(x < p->data){	//if key is to be inserted in the left subtree
					if(p->left==NULL)
					{
						p->left = temp;
						temp->parent = p;
						return;
					}
					else
					{
						insert(p->left,temp);
					}
					
				}

				else if (x > p->data){ //if key is to be inserted in the right subtree
					if(p->right==NULL){
						p->right = temp;
						temp->parent = p;
						return;
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
				cout << temp->data << endl;	//print the data
				display(temp->right);		//move to right

				
			
			}			
	}

	node* search(node* temp, int key){		//search key
		if (temp == NULL) {			//if key is not in the bst
			cout << "key not found" << endl << endl;
			return temp;
		} 

		if (temp->data == key) {		//if key is found
			cout << "key found" << endl;	//print key found
			return temp;			//and return
		}

		else if (temp->data > key) {		//search key in left subtree
			search(temp->left, key);
		} 

		else {					//search key in right subtree
			search(temp->right, key);
		}
		
	} 

	node* minValue(node* temp)  			//gives minimum value in the 
	{
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}

	void deleteNode(node* temp, int key)		//deletes a node
	{
		node* p = search(temp,key);


		if (p!=NULL){				

			if(p->left == NULL && p->right == NULL)	//no child
			{
				
				if(p->parent->left == p){
					p->parent->left = NULL;
				}
				else if(p->parent->right == p){
					p->parent->right = NULL;
					cout << "Hello" << endl;
				}

				return;
			}

			else if(p->left == NULL || p->right == NULL) 	//1 child
			{
				if(p->left == NULL){
					p->right->parent = p->parent;
					if(p->parent->left == p){
						p->parent->left = p->right;
					}
					else{
						p->parent->right = p->right;
					}
					delete p;
				}

				
				else if(p->right == NULL)
				{
					p->left->parent = p->parent;
					if(p->parent->left == p){
						p->parent->left = p->right;
					}
					else{
						p->parent->right = p->right;
					}
					delete p;
				}
			}

			else if(p->left != NULL && p->right != NULL){ //2 child
				node* c = p->left;

				while(c->right != NULL)
				{
					c = c->right;
				}

				if(c->left==NULL){
					p->data = c->data;
					c->parent->right = NULL;
				}

				else{
					c->parent->right = c->left;
					c->left->parent = c->parent;
					p->data = c->data;
				}
		    }
		else {						//if key not found
			cout << "key not found" << endl;
			return;
		}
	}
	}
	
	int n=0;

	int count(node* temp){				//counts the no. of nodes in the bst
		if(temp == NULL){			//base case
			return 0;
		}
		else{
			count(temp->left);		//go to left 
			n++;				//increase value of n 
			count(temp->right);		//go to right
		}
		return n;
	}

	void range_search(int k1,int k2,node* temp){
		
		if(temp==NULL){				//base case
			return;
		}
		if(temp->data > k1){			//if we are right to k1
			range_search(k1,k2,temp->left);	//go with left subtree
		}
		if(temp->data >= k1 && temp->data <= k2){//if we are in the range
			cout << temp->data << endl;	//prints the element
		}
		if(temp->data < k2 ){			//if we are left to k2
			range_search(k1,k2,temp->right);//go with right subtree
		}
	}

};

int main(){
	bTree b1;
	for (int i=0; i<20; i=i+2) {		//inserts nodes using loop
		node* temp = new node;
		temp->data = i;
		b1.insert(b1.root, temp);
	}

	for (int i=7; i>-10; i=i-2) {
		node* temp = new node;
		temp->data = i;
		b1.insert(b1.root,temp);
	}

	for (int i=2; i>-10; i=i-3) {
		node* temp = new node;
		temp->data = i;
		b1.insert(b1.root,temp);
	}

	
	node* p = b1.root;
	
	b1.display(b1.root);		//displays the bst

	b1.search(b1.root,9);		//search the location of '9' in the bst

	b1.display(b1.root);
	b1.deleteNode(b1.root,19);	//deletes a leaf node
	b1.display(b1.root);
	b1.deleteNode(b1.root,16);	//deletes an internal node having 1 child
	b1.display(b1.root);
	b1.deleteNode(b1.root,0);	//deletes an internal node having 2 child
	b1.display(b1.root);
	cout << endl << "No. of nodes = " << b1.count(b1.root) << endl;	//counts the no. of nodes
	b1.range_search(-9,-4,b1.root);		// prints elements between -9 and -4

	return 0;
}
