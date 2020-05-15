
//QUEUES Data Structure by LIKHITA26

#include <stdio.h>
#include <stdlib.h>

struct Qnode
{
int JobId;
int JobTime;
struct Qnode* next;
}; 

struct Queues
{
struct Qnode *front,*rear;
};

int N=0;//initial no.of jobs
int time=0;//initial time
int Quantum=50; //time quantum

//function
struct Qnode* Newnode(int id,int time);
struct Queues* RandomQueue(int size);
void enQueue(struct Queues* q,int id,int time);
void printQueue(struct Queues* q);
int randomInt();
void deQueue(struct Queues* q);
void deQueueandenQueue(struct Queues* q);
void AppendQueue(struct Queues* q);


int main()
{
   int t=50;
   struct Queues* q = RandomQueue(100);
   printf("100 jobs created\n");
   printf("Initial Queue:");
   printQueue(q);
   while(q->front !=NULL)
   {
      q->front->JobTime -= 1;
      time ++;
      t--;
      if(q->front->JobTime == 0)
       {
         deQueue(q);
         t=50;
       }
      if(t == 0)
       {
         deQueueandenQueue(q);
         t=50;
       }
      if(time%50 == 0)
       {
         printf("Queue at end of %d us:",time);
         printQueue(q);
       }
      if(time%200 == 0)
       {
         AppendQueue(q);
       }
   }
      if(time%50 !=0)
       {
         time=((time/50)+1)*50;
         printf("Queue at end of %d us:",time);
         printQueue(q);
       }
return 0;
}

//creating a queue of given size
struct Queues* RandomQueue(int size)
{
  struct Queues* q = (struct Queues*)malloc(sizeof(struct Queues));
  for(int i=0;i<size;i++)
  {
  enQueue(q,N+1,randomInt());
  N++;
  }
 return q;
}

//adding nodes to the queue
void enQueue(struct Queues* q,int id,int time)
{
  struct Qnode* temp = Newnode(id,time);
  if(q->rear == NULL)
  {
   q->front=temp;
   q->rear=temp;
   return;
  }
 q->rear->next=temp;
 q->rear=temp;
}

//creating new nodes
struct Qnode* Newnode(int id,int time)
{
  struct Qnode* temp = (struct Qnode*)malloc(sizeof(struct Qnode));
  temp->JobId=id;
  temp->JobTime=time;
  temp->next=NULL;
  return temp;
}

//printing all elements of queue
void printQueue(struct Queues* q)
{
  struct Qnode* temp = q->front;
  if(temp == NULL)
   {
     printf("  Empty");
   }
  while(temp != NULL)
   {
     printf("  J%d:%d",temp->JobId,temp->JobTime);
     temp=temp->next;
   }
  printf("\n");
  printf("\n");
}

//Creating a random integer between 0 and 300
int randomInt()
{
  return (rand() % 300)+1;
}

//removing the first element of queue
void deQueue(struct Queues* q)
{
   if(q->front == NULL)
   return;
   q->front =q->front->next;
   if(q->front == NULL)
   q->rear=NULL;
}

//removing the first node and adding it at the end of queue
void deQueueandenQueue(struct Queues* q)
{
  struct Qnode* temp = q->front;
 if(q->front == NULL)
  return;
 if(q->front!= q->rear)
  {
  q->front =q->front->next;
  temp->next=NULL;
  q->rear->next=temp;
  q->rear=temp;
  }
}

//function to add extra jobs at particular time
// size of jobs added is 64 at time=200,32 at time =400 and so on. 
void AppendQueue(struct Queues* q)
{
   static int n=64;  //change the value of n to y to add y jobs at the end of 200u sec
   if(n==0)
     return;
   printf("\n\n******%d us passed, added %d new jobs to end\n",time,n);
   struct Queues* temp=RandomQueue(n);
   q->rear->next=temp->front; 
   q->rear=temp->rear;
   n /= 2;
   printf("New queue:");
   printQueue(q);
}

//END OF QUEUE DATA STRUCTURE BY LIKHITA26
