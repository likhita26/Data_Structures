// STACKS BY LIKHITA26 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining structs
struct node
{
    char data;
    int index;
    struct node*next;
};
struct node*head=NULL;

struct node2
{
    int data;
    struct node2*next;
};
struct node2*top=NULL;

//Defining priority for operations as in BODMAS
int priority(char data)
   {
       int p;

       switch(data)
         {
            case '+': p=1;
            break;

            case '-': p=1;
            break;

            case '*': p=2;
            break;

            case '/': p=2;
            break;

            case '(': p=0;
            break;

            case '{': p=0;
            break;

            case '[': p=0;
            break;
         }

       return p;
   }
//Push function for stack
struct node* push(struct node*head,char a,int n)
   {
      if (head==NULL)
        {
           head=(struct node*)malloc(sizeof(struct node));
           head->data=a;
           head->index=n;
           head->next=NULL;
        }

      else
        {
           struct node*temp;
           struct node*p=head;
           temp=(struct node*)malloc(sizeof(struct node));
           temp->data=a;
           temp->index=n;
           temp->next=p;
           head=temp;
        }
        return head;
   }
//Pop function for stack
struct node* pop(struct node*head)
   {
      struct node*temp;
      temp=(struct node*)malloc(sizeof(struct node));
      char p;

      if (head->next!=NULL)
        {
           struct node*temp;
           p=head->data;
           temp=head->next;
           head->next=NULL;
           head=temp;
        }

      else if(head->next==NULL)
        {
           p=head->data;
           head=NULL;
        }

      temp->data=p;
      temp->next=head;
      return temp;
   }
//Push function
struct node2* push2(struct node2*head,int a)
   {
      if (head==NULL)
        {
           head=(struct node2*)malloc(sizeof(struct node2));
           head->data=a;
           head->next=NULL;
        }

      else
        {
           struct node2*temp;
           struct node2*p=head;
           temp=(struct node2*)malloc(sizeof(struct node2));
           temp->data=a;
           temp->next=p;
           head=temp;
        }
        return head;
   }
//Pop function
struct node2* pop2(struct node2*head)
   {
      struct node2*temp;
      temp=(struct node2*)malloc(sizeof(struct node2));
      int p;

      if (head->next!=NULL)
        {
           struct node2*temp;
           p=head->data;
           temp=head->next;
           head->next=NULL;
           head=temp;
        }

      else if(head->next==NULL)
        {
           p=head->data;
           head=NULL;
        }

      temp->data=p;
      temp->next=head;
      return temp;
   }
//Function for operations
int operation(int a,int b,char c)
   {
       int p; //local variable
       switch(c)
         {
            case '+': p=a+b;
            break;
            case '-': p=b-a;
            break;
            case '*': p=a*b;
            break;
            case '/': p=b/a;
            break;
         }
       return p;
   }

char comp(char a)
   {
      char c; 
      switch(a)

         {
            case '(': c=')';
            break;
            case '[': c=']';
            break;
            case '{': c='}';
            break;
            case ')': c='(';
            break;
            case ']': c='[';
            break;
            case '}': c='{';
            break;
            default : c='.';
         }
      return c;
   }
// The main function
int main()
{
    char input[100];
    printf("Enter the input:\n");
    scanf("%s",input);
//program begins here
    int i=0;
    struct node*head_of_stack=NULL;
    while(input[i]!='\0')
      {

         if(input[i]=='('||input[i]=='['||input[i]=='{')
                {
                   head_of_stack = push(head_of_stack,input[i],i);
                }

         else if (head_of_stack!=NULL&&input[i]==comp(head_of_stack->data))
                {

                   struct node*X;
                   X=pop(head_of_stack);
                   head_of_stack=X->next;
                }
         i=i+1;
      }

     if (head_of_stack==NULL)
       {
          printf("Valid input.\n");
       }
     else
       {
          printf("Invalid input:");
          printf("Error of '%c' at position %d .\n",head_of_stack->data,head_of_stack->index); //prints invalid input at what position //positions start from 0
       }

    i=0;
    int j=0;
    char output[100];

    while(input[i]!='\0')
      {
         if(input[i]=='('||input[i]=='{'||input[i]=='[')
            {
                   char p=input[i];
                   char q=comp(p);
                   head=push(head,input[i],i);
                   i=i+1;

                   while(input[i]!='\0'&&input[i]!=q)
                    {
                       if (input[i]=='*'||input[i]=='/'||input[i]=='+'||input[i]=='-')
                         {
                            if(head==NULL)
                              {
                                head=push(head,input[i],i);
                              }

                            else if(head!=NULL)
                              {
                                if (priority(input[i])>priority(head->data))
                                  {
                                    head=push(head,input[i],i);
                                  }

                                else if (priority(input[i])<=priority(head->data))
                                  {
                                    struct node*p=head;
                                    while(p!=NULL&&priority(input[i])<=priority(p->data))
                                      {
                                        struct node*A;
                                        A=pop(head);
                                        output[j]=' ';
                                        j=j+1;
                                        output[j]=A->data;
                                        p=p->next;
                                        j=j+1;
                                        output[j]=' ';
                                        j=j+1;
                                       }
                                 head=push(p,input[i],i);
                                  }
                              }
                         }

                       else if(input[i]=='0'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9')
                         {
                            output[j]=input[i];
                            j=j+1;
                            if (input[i+1]!='\0')
                              {
                                if (input[i+1]>'9'||input[i+1]<'0')
                                  {
                                    output[j]=' ';
                                    j=j+1;
                                  }
                              }
                        }
                        i=i+1;
                    }

//when closed bracket arrives
                   while(head->data!=p)
                     {
                        struct node*B;
                        B=pop(head);
                        output[j]=' ';
                        j=j+1;
                        output[j]=B->data;
                        j=j+1;
                        head=B->next;
                     }
                    struct node*C;
                    C=pop(head);
                    head=C->next;

            }

         else
            {
              if (input[i]=='*'||input[i]=='/'||input[i]=='+'||input[i]=='-')
                        {
                            if(head==NULL)
                              {
                                head=push(head,input[i],i);
                              }

                            else if(head!=NULL)
                              {
                                if (priority(input[i])>priority(head->data))
                                  {
                                    head=push(head,input[i],i);
                                  }

                                else if (priority(input[i])<=priority(head->data))
                                  {
                                    struct node*p;
                                    p=head;
                                    while((p!=NULL&&priority(input[i])<priority(p->data))||(p!=NULL&&priority(input[i])==priority(p->data)))
                                      {
                                        struct node*A;
                                        A=pop(p);
                                        output[j]=' ';
                                        j=j+1;
                                        output[j]=A->data;
                                        j=j+1;
                                        output[j]=' ';
                                        j=j+1;
                                        p=A->next;
                                       }
                                 head=push(p,input[i],i);
                                  }
                              }
                        }

              else if(input[i]=='0'||input[i]=='1'||input[i]=='2'||input[i]=='3'||input[i]=='4'||input[i]=='5'||input[i]=='6'||input[i]=='7'||input[i]=='8'||input[i]=='9')
                        {
                            output[j]=input[i];
                            j=j+1;
                            if (input[i+1]!='\0')
                              {
                                if (input[i+1]>'9'||input[i+1]<'0')
                                  {
                                    output[j]=' ';
                                    j=j+1;
                                  }
                              }
                        }
            }

           i=i+1;
      }

      while(head!=NULL)
       {
         struct node*B;
         B=pop(head);
         output[j]=' ';
         j=j+1;
         output[j]=B->data;
         j=j+1;
         head=B->next;
       }

    for(int k=0;k<j;k++)
    {
        printf("%c",output[k]);
    }

    for(int p=0;p<j;p++)
    {
        if (p==0)
          {
             if (output[p]>='0'&&output[p]<='9')
               {
                 top=push2(top,output[p]-'0');
               }
          }


        else if (output[p]=='+'||output[p]=='-'||output[p]=='*'||output[p]=='/')
          {
             struct node2*q,*w;
             q=pop2(top);
             w=pop2(q->next);
             int value=operation(q->data,w->data,output[p]);
             top=w->next;
             top=push2(top,value);
          }
        else if (p>=1 &&output[p-1]>='0'&&output[p-1]<='9')
          {
              if (output[p]>='0'&&output[p]<='9')
                {
                  top->data=(10*top->data)+output[p]-'0';
                }
          }
        else if ((p>=1&&output[p-1]<='0')||(p>=1&&output[p-1]>='9'))
          {
              if (output[p]>='0'&&output[p]<='9')
                {
                  top=push2(top,output[p]-'0');
                }
          }
    }
    struct node2*y;
    y=pop2(top);
    printf("\nresult=%d",y->data);

    return 0;
}

//END OF STACKS_DATASTRUCTURE BY LIKHITA26
