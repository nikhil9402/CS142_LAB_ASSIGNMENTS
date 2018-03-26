#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* left = NULL;
	node* right = NULL;
	node* parent = NULL;
};

class bTree{
public:
	node* root;

	bTree(){
		root = NULL;
	}

	void insert(node* p, node* temp){
		
		int x = temp->data;
		temp->data = x;
		temp->parent = temp->right = temp->left = NULL;

		if (root==NULL){
			root = temp;
		}
		
		else{
			
				/*if(x = p->data){
					cout << "Element already exists" << endl;
				}*/
	
				if(x < p->data){
					if(p->left==NULL)
					{
							p->left = temp;
					}
					else
					{
						insert(p->left,temp);
					}
					
				}

				else{
					if(p->right==NULL){
						p->right = temp;
					}
					
					else{
						insert (p->right,temp);
					}
				}

	
			
		}
	}

	void display(node* temp){
			if(temp->left != NULL){
				return;
			}

			else{
				display(temp->left);
				cout << temp->data << endl;
				
				display(temp->right);
				cout << temp->data << endl;
			
			}			
	}
};

int main(){
	bTree b1;
	

	node* temp = new node;
	temp->data = 7;
	b1.insert(b1.root,temp);
	b1.display(b1.root);

	temp->data = 6;
	b1.insert(b1.root,temp);
	b1.display(b1.root);

return 0;
}
