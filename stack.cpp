#include <iostream> 
#include<stdlib.h> 
using namespace std; 
struct Node 
{ 
int data; 
struct Node *next; 
}; 
struct Node* top = NULL; 
void push(int val) 
 { 
  struct Node* newnode = (struct Node*) malloc(sizeof(struct Node)); 
  newnode->data = val; 
  newnode->next = top; 
  top = newnode; 
 } 
  
void pop() 
 { 
  if(top==NULL) 
   cout<<"\n Stack Underflow"<<endl; 
  else 
   { 
    cout<<"\n The popped element is "<< top->data <<endl; 
    top = top->next; 
   } 
    
 } 
void display() 
  { 
   struct Node* ptr; 
   if(top==NULL) 
    cout<<"\n stack is empty"; 
   else 
   { 
    ptr = top; 
    cout<<"\n Stack elements are: "; 
    while (ptr != NULL) 
    { 
     cout<< ptr->data <<" "; 
     ptr = ptr->next; 
    } 
    cout<<endl; 
    cout << "\n Top element is" << top->data << endl; 
   } 
  } 
 
int main() 
 { 
  int ch, val; 
  cout<<"\n 1) Push in stack"; 
  cout<<"\n 2) Pop from stack"; 
  cout<<"\n 3) Display stack"; 
  cout<<"\n 4) Exit"; 
   
  do 
  { 
   cout<<"\n Enter choice: "; 
   cin>>ch; 
    
   switch(ch) 
   { 
    case 1: 
    cout<<"\n Enter value to be pushed:"; 
    cin>>val; 
    push(val); 
    break; 
    case 2: 
    pop(); 
    break; 
    case 3: 
    display(); 
    break; 
    case 4: 
    cout<<"\n Exit"; 
    break; 
   } 
  }while(ch!=4); 
   
  return 0; 
} 
