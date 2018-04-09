#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* left = NULL;
	node* right = NULL;
	node* parent = NULL;
};

class bTree {
public:
	node* root;

	bTree(){
		root = NULL;
	}

	void insert(node* p, node* temp){
		
		int x = temp->data;

		if (root==NULL){
			root = temp;
		}
		
		else{
			
	
				if(x < p->data){
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

				else if (x > p->data){
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

	void display(node* temp){
			if(temp == NULL){
				return;
			}

			else{
				
				display(temp->left);
				cout << temp->data << endl;
				display(temp->right);

				
			
			}			
	}

	node* search(node* temp, int key){
		if (temp == NULL) {
			cout << "key not found" << endl << endl;
			return temp;
		} 

		if (temp->data == key) {
			cout << "key found" << endl;
			return temp;
		}

		else if (temp->data > key) {
			search(temp->left, key);
		} 

		else {
			search(temp->right, key);
		}
		
	} 

	node* minValue(node* temp)
	{
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}

	void deleteNode(node* temp, int key)
	{
		node* p = search(temp,key);


		if (p!=NULL){

			if(p->left == NULL && p->right == NULL)
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

			else if(p->left == NULL || p->right == NULL)
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

			else if(p->left != NULL && p->right != NULL){
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
		else {
			cout << "key not found" << endl;
			return;
		}
	}
}

};

int main(){
	bTree b1;
	for (int i=0; i<20; i=i+2) {
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
	
	b1.display(b1.root);

	b1.search(b1.root,9);

	b1.display(b1.root);
	b1.deleteNode(b1.root,19);
	b1.display(b1.root);
	b1.deleteNode(b1.root,16);
	b1.display(b1.root);
	b1.deleteNode(b1.root,0);
	b1.display(b1.root);

	return 0;
}
