// Implementation of queue using pointers.

#include<stdio.h>
#include<malloc.h>
typedef struct queue
{ 
    int data;
    struct queue *next;
}NODE;
     
NODE * insert(NODE *rear,int data)
{   
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->next=NULL;
    if(rear==NULL)
    { 
       rear=temp;
    } 
    else
    { 
       rear->next=temp;
       rear=temp;   
        
    }
}   
         
NODE* delete(NODE*front)
{   
    NODE *temp;
    if(front==NULL)
    { 
        printf("Queue is empty\n");
    }
    else
    { 
        temp=front;
        front=front->next;
        free(temp);
    } 
    return(front);  
}
         
void display(NODE *front)
{ 
    NODE *t;
    if(front==NULL)
   {
        printf("Queue is empty\n");
   }
   else
    { 
        t=front;
        while(t)
        {
            printf("%d,",t->data);
            t=t->next;
        }
    }
}            
         
void main()      
{  
    NODE *front=NULL,*rear=NULL;
    int ch,data;
    do{
      printf("\nMain Menu\n1] Insert\n2] Display\n3] Delete\n4] Exit\n");
      printf("Enter Ur Choice?");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
            printf("Enter Data:");
            scanf("%d",&data);
            rear=insert(rear,data);
            if(front==NULL)
            { front=rear;
            }
            break;
        case 2:
            display(front); 
            break;      
        case 3:
            front=delete(front);
            if(front==NULL)
            { rear=NULL;
            }
            break;  
        case 4:
            printf("Exit");
            break;
        default:
            printf("Wrong Option");
      }
      printf("\n");
   }while(ch!=4);
}        

