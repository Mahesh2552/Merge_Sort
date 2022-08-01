//.....
/* 								LabAssignment-9
   Name : Mahesh Ramdas Dubal 
   Roll No. : 658
   Question :Write a C-program to Implement various operations on Doubly Linear Linked List

------------------------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include"validations.h"
struct node
{
	int data;
	struct node *next,*prev;
};

struct node *head,*temp,*newnode,*ptr;

void insertFirst(int);
void insertLast(int);
void insertAtPos(int,int);
void deleteFirst();
void deleteLast();
void deleteAtPos(int);
int count();
void display();

int Count = 0,Pos = 0;


int AcceptValue()
{
	int value = 0,invalid = 1;
	char val[10];
	
	while(invalid == 1)
	{
		printf("\nEnter the data : ");
		gets(val);
		
		if(checkInteger(val) == 1)
		{
			value = atoi(val);
			invalid = 0;
		}
		else
		{
			printf("\n\tEnter valid data !!\n");
			invalid = 1;
		}
	}
	
	return value;
}

int AcceptPos()
{
	int pos = 0,invalid = 1;
	char val[10];
	
	while(invalid == 1)
	{
		printf("\nEnter the Position : ");
		gets(val);
		
		if(checkInteger(val) == 1)
		{
			pos = atoi(val);
			invalid = 0;
		}
		else
		{
			printf("\n\tEnter valid Position !!\n");
			invalid = 1;
		}
	}
	
	return pos;
}

int AcceptChoice()
{
	int choice = 0,invalid = 1;
	char ch[2];
	
	while(invalid == 1)
	{
		printf("\nEnter your choice : ");
		gets(ch);
		
		if(checkChoice(ch) == 1)
		{
			choice = atoi(ch);
			invalid = 0;
		}
		else
		{
			printf("\n\tEnter valid choice !!\n");
			invalid = 1;
		}
	}
	
	return choice;
}

int main()
{
	int choice = 0,cnt = 0,item = 0,pos= 0,invalid = 1,size = 0;
	char ch[2];
	
	printf("\n\tImplementation of Doubly Linear Linked List\t\n");
	printf("____________________________________________________\n");
	while(choice != 9)
	{
		invalid = 1;
		
		printf("\n1.InsertFirst\n2.InsertAtPos\n3.InsertLast\n4.DeleteFirst\n5.DeleteAtPos");
		printf("\n6.DeleteLast\n7.Count\n8.Display\n9.Exit\n");
		choice = AcceptChoice();
		
		switch(choice)
		{
			case 1: {
						item = AcceptValue();
						insertFirst(item);	
						printf("\n\tNode Inserted\n");	
						break;
					}
			
			case 2: {
			 			item = AcceptValue();
						while(invalid == 1)
						{
							pos = AcceptPos();
							size = count();
							if(pos < 1 || pos > size+1)
							{
								printf("\n\tEnter valid position !!\n");
								invalid = 1;
							}
							else
							{
								insertAtPos(item,pos);
								invalid = 0;
							}
						}
						invalid = 1;
						printf("\n\tNode Inserted\n");
						break;
					}
				
			case 3: {
						item = AcceptValue();
						insertLast(item);
						printf("\n\tNode Inserted\n");
						break;
				    }
				    
			case 4: {
						deleteFirst();
						break;
					}
					
			case 5: {
						while(invalid == 1)
						{
							pos = AcceptPos();
							size = count();
							if(pos < 1 || pos > size)
							{
								printf("\n\tEnter valid position !!\n");
								invalid = 1;
							}
							else
							{
								deleteAtPos(pos);
								invalid = 0;
							}
						}
						invalid = 1;
						
						if(item != 0)
						{
							printf("\n\tNode deleted\n\nValue of Deleted node : %d\n",item);
						}
						break;
					} 
					
			case 6: {
						deleteLast();
						break;
					}
					
			case 7: {
						cnt = count();
						printf("\nNumber of Elements : %d\n",cnt);
						break;
					}
					
			case 8: {
						display();
						break;
					}
					
			case 9: 
					{
						exit(0);			
					}
				
			
			default: printf("\n\tEnter Valid choice !!\n");
			
		}
		printf("_________________________________________\n");
	}
	
	
	return 0;
}
void insertFirst(int value) 
{
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->prev = NULL;
	newnode->next = NULL;
	
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode ;
	}
	
	Count++;
	
}
void insertLast(int value)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->prev = NULL;
	newnode->next = NULL;
	
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		temp = head;  //storing address inside head in temp 
		while(temp->next != NULL)
		{
			temp = temp->next; 
		}
		temp->next = newnode;  //storing base address of newnode in temp->next
		newnode->prev = temp;
	}
	
	Count++;
	
}

void insertAtPos(int value,int Pos)
{
	int i = 0;
	
	if(Pos == 1)
	{
		insertFirst(value);
	}
	else if(Pos == Count+1)
	{
		insertLast(value);
	}
	else
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = value;
		newnode->prev = NULL;
		newnode->next = NULL;
		
		temp = head;
		
		for(i = 1; i < Pos-1; i++)
		{
			temp = temp->next; //to reach one position before to desire position
		}
		newnode->next = temp->next;
		temp->next->prev =newnode;
		newnode->prev = temp;
		temp->next = newnode;
		
		Count++;
	}

}
void deleteFirst()
{
	if(head == NULL)
	{
		printf("Linked List is empty\n");
	}
	else if(head->next == NULL) // if Linked list contaim only one node
	{
		temp = head;
		free(temp);
		head = NULL;
	}
	else
	{
		temp = head;
		head->next->prev = NULL;
		head = temp->next;
		Count--;
	}
}

void deleteLast()
{
	if(head == NULL)
	{
		printf("Linked List is empty\n");
	}
	else if(head->next == NULL) // if Linked list contaim only one node
	{
		temp = head;
		free(temp);
		head = NULL;
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
		{
			ptr = temp;
			temp = temp->next;
		}
		
		ptr->next = NULL;
		temp->next = NULL;
		free(temp);
		Count--;
	}
}

void deleteAtPos(int Pos)
{
	int i = 1;
	
	if(head == NULL)
	{
		printf("Linked List is empty\n");
	}
	else if(Pos == 1)
	{
		deleteFirst();
	}
	else if(Pos == Count)
	{
		deleteLast();
	}
	else
	{
		temp = head;
		
		for(i = 1; i<Pos; i++)
		{
			temp = temp->next;
		}
		
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
		Count--;
	}
	
}
int count()
{
	return Count;	
}
void display()
{
	if(head == NULL)
	{
		printf("Linked List is Empty\n");
	}
	else
	{
		temp = head;
		printf("\n");
		
		while(temp != NULL)
		{
			printf("|%d|->",temp->data);
			temp = temp ->next;
		}
		printf("NULL\n");
	}
}

