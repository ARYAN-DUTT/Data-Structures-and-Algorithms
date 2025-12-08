#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int val)
{
 struct node * new_node= (struct node *)malloc(sizeof(struct node));
 new_node->data=val;
 new_node->next=NULL;
 return new_node;
}

struct node *insert_beg(struct node *start, int val)
{
    struct node* new_node=createNode(val);
    if(start==NULL)
    {
        start=new_node;
    }
    else{
        //2nd 3rd 4th
        new_node->next=start;
        start=new_node;
    }

    return start;
}
struct node *insert_end(struct node *start, int val)
{
    struct node* new_node=createNode(val);
    if(start==NULL)
    {
        start=new_node;
        return start;
    } 
    struct node *ptr = start;
    while(ptr->next!=0){
        ptr=ptr->next;
    }
    ptr->next=new_node;

    return start;
}

struct node *delete_beg(struct node *start){
    start=start->next;
    return start;
}

void *delete_end(struct node *start){
    while(start->next!=NULL){
        if(start->next->next==NULL){
            start->next=NULL;
            break;
        }
        start=start->next;
    }
}

reverse(struct node *start){
  struct node *x = start;
  struct node *y = start;
  int count=0;
  while(x!=NULL){
    count++;
    x=x->next;
  }
  int i=0;
  int l=0;
  while(y!=NULL){
    int x=y->data;
    
  }

}

void print_LL(struct node *start)
{
    struct node *ptr=start;

    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{
   struct node *start=NULL;
   int n,val;
   scanf("%d",&val);
   while(val!=-1)
   {
       start=insert_beg(start,val);
        scanf("%d",&val);
   }
   print_LL(start);
   reverse(start);
   print_LL(start);
    return 0;
}