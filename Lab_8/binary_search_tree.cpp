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

		

		if (root==NULL){
			root = temp;
		}
		
		else{
			
				if(x == p->data){
					cout << "Element already exists" << endl;
				}
	
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
			if(temp == NULL){
				return;
			}

			else{
				
				display(temp->left);
				cout << temp->data << endl;
				display(temp->right);

				
			
			}			
	}

	bool search(node* temp, int key){
		if (temp == NULL) {
			cout << "key not found" << endl;
			return false;
		} 

		if (temp->data == key) {
			cout << "key found" << endl;
			return true;
		}

		else if (temp->data < key) {
			search(temp->right, key);
		} 

		else {
			search(temp->left, key);
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
		bool d = search(temp,key);

		if (d==true){
			

			if(temp->left == NULL && temp->right == NULL)
			{
				cout << "Hello";
				delete temp;
				return;
			}

			else if(temp->left == NULL || temp->right == NULL)
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
