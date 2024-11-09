//queue is a data structure with fist in first out implementation
//implementing a queue
class queue
{
int *arr;
int front;
int rear;
int size;
public:
queue(){
  int size =5000;//random number
  arr= new int[size];
  front =0;
  rear=0;
}
bool isempty()
{
  if(front==rear)retunr true;
  return false;
}
bool isfull()
{
  if(rear==size)return true;
  return false;
}
void enqueue(int data)
{
  if(rear==size) isfull();
  else{
    arr[rear]=data;
    rear++;}
}
int dequeue()
{
  int ans =arr[front];
  if(front==rear) return -1;
  else {arr[front]=-1;
       front++;
       if(front==rear)
       {front=0;rear=0;}
       return ans;
       }
}
int front()
{
  return arr[front];
}
};
//circular queue implementation===========================
class circularqueue
{
int arr*;
int front;
int rear; int size;
private:
circularqueue(int n)
{
  size=n;
  arr= new int[size];
  front=rear=-1;
  rear =-1;
}
bool enqueue(int x)
{
  if((front==-1&&rear==size-1)||(rear==(front-1)%(size-1)))
    {
      cout<<"queue is full";
      return false;
    }
 else if(front ==rear ==-1) {front++;rear++;
  arr[rear]=x;}
  else if(rear=size-1 && front!=0)
  {rear=0;
  arr[rear]=x;}
  else
{rear++;
arr[rear]=x;}
  return true;
}
int dequeue()
{
  if(front==-1)
  {cout<<"queue is empty";
  return -1;}
  int ans = arr[front];
  arr[fromt]=-1;
  if (front==rear)//single element
    front=rear=-1;
  else if(front==size-1)//front at last
    front=0;
  else front++;
  return ans;
}
};
//double ended queue............

