#include <iostream>
using namespace std;

class Stack     //declares a class stack
{
private:        //makes variables private
        int s[20];      //declares an array of size 20 max.
        int n;          //declares a variable of int data type

public:         //makes variables private
        Stack(){        //constructor
                n=0;
        }

        void push(int d){       //pushes an element at the top
                s[n]=d;
                n++;
        }
        void pop(){             //pops out an element from the top
            s[n]='\0';
                n--;
        }
        void display(){
                cout << "Elements in the stack are" << endl;
                for(int i=n-1;i>=0;i--){        //loop which displays the element
                        cout << s[i] << endl;
                }
        }
};


int main(){     //main function
        Stack s1;       //creates a stack s1
        s1.push(3);     //calls the function push
        s1.push(4);
        s1.push(2);
        s1.display();   //calls the display function
        s1.pop();
        s1.display();
return 0;               //returns 0 to the shell
}
