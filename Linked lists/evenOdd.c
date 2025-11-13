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
        new_node->next=start;
        start=new_node;
    }

    return start;
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
void count_odd(struct node *start){
    int oddCount=0;
    while(start!=NULL){
        if(((start->data)%2)!=0){
            oddCount++;
        }
        start=start->next;
    }
    printf("\ncount of odd numbers is : ");
    printf("%d",oddCount);
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
   
   count_odd(start);
    return 0;
}