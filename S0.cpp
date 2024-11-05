#include<iostream>
using namespace std;
//stack<int> st;
//last in first out
//st.push()-push element into stack
//st.pop()-delete the element at top
//st.top()-element at top
//st.empty()-if stack is empty
class stack
{//properties
int* arr;
int top;
int size;
 public:
//behaviour
stack(int size)
{
  this ->size=size;
  arr= new int[size];
  top=-1;
}
void push(int element)
{
  if(size-top>1)
  {
    top++;
    arr[top]=element;
  }
  else cout<<"stack overflow"; 
}

bool isfull()
{
  if(size-top<=0)
  {cout<<"stack is full";return true;}else return false;
}

bool isempty()
{
  if(top==-1) {cout<<"stack is empty";return true;}else return false;
}

void pop()
{
  if(top>=0)top--;
  else cout<<"stack underflow";
  
}

int peek()
{
  if(top>=0&&top<=size-1)  
  return arr[top];
  else {cout<<"stack is empty";return -1;}
}
void display()
{
  while(top!=-1)
  {
    cout<<arr[top]<<"\n";
    top--;
    
  }
}
};
int main()
{
  stack st(5);st.push(5);st.push(0);
  st.display();     
}
//implementation by linked list
struct Node{
int data;
struct Node *next;
}*top;
void init()
{ top = NULL;}
void push(int value)
 {
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));//Allocates memory dynamically for one node of type struct Node
   newNode->data = value;
   if(top == NULL)
     newNode->next = NULL;
   else
     newNode->next = top;
   top = newNode;
 }
void pop()
{
 if(top == NULL)
 printf("\nUnderflow\n");
 else{
 struct Node *temp = top;
 printf("\nDeleted element: %d", temp->data);
 top = temp->next;
 free(temp);
 }
}
void display()
 {
 if(top == NULL)
 printf("\nStack is Empty!!!\n");
 else{
 struct Node *temp = top;
 while(temp->next != NULL){
 printf("%d--->",temp->data);
 temp = temp -> next;
 }
 printf("%d--->NULL",temp->data);
 }
 }
