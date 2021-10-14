#include <stdio.h>
#include <stdlib.h>

void createList(int data);
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void insertNodeAtPosition(int data,int pos);
void displayList();


struct Node
{
	struct Node *prev;
    int data;
    struct Node *next;
}*start=NULL;
typedef struct Node node;
int main()
{
	node *cptr;
	int n,i,data;
    printf("enter no u want in linked list:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d",&data);
    createList(data);
}
    cptr=start;
    while(cptr!=NULL)
    {
    	printf("%d->",cptr->data);
    	cptr=cptr->next;
	}
return 0;
}


void createList(int data)
{
    node *newNode,*newNode1,*temp,*cptr;
    int i;
    newNode= (node *)malloc(sizeof(node));
        newNode->prev=NULL;
        newNode->data = data; 
        newNode->next = NULL; 
    if(start == NULL)
    {
        start =newNode;
    }
    else
    {  
               cptr=start;
                while(cptr->next!=NULL)
                {
                	cptr=cptr->next;
				}
                cptr->next=newNode;
                newNode->prev=cptr;
    }
 }

          

/*

void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = head; 

        head = newNode;        

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void insertNodeAtEnd(int data)
{
	struct node *nn,*temp;
	nn=(struct node*)malloc(sizeof(struct node));
	if(nn==NULL){
		printf("can't allocate memory");
		}
		else{
			temp=head;
			while(temp->next!=NULL)
			{
			temp=temp->next;
		}
			nn->data=data;
			nn->next=NULL;
		temp->next=nn;
	//	temp->next=NULL;
}
}


void insertNodeAtPosition(int data,int pos)
{
	struct node *nn,*temp;
	nn=(struct node*)malloc(sizeof(struct node));
	if(nn==NULL){
		printf("can't allocate memory");
		}
		else{
			int cnt=1;
			temp=head;
			while(cnt<(pos-1))
			{
				cnt++;
				temp=temp->next;
			}
			nn->data=data;
			nn->next=NULL;
			nn->next=temp->next;
			temp->next=nn;
		}
	}

void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                
        }
    }
}

*/
	
	
