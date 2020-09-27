//Employee detail
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
	int Eid;
	char Ename[30];
	float Esalary;
	
	struct employee* next;
	struct employee* prev;
};
typedef struct employee EMP;
typedef struct employee* PEMP;
typedef struct employee** PPEMP;

int Count(PEMP Head)
{
	int count=0;
	while(Head != NULL)
	{
		count++;
		
		Head=Head->next;
	}
	return count;
}
void InsertFirst(PPEMP Head, int eid, char name[],float salary)
{
	
	PEMP newn =NULL;
	newn=(PEMP)malloc(sizeof(EMP));
	newn->next=NULL;
	newn->prev=NULL;
	newn->Eid=eid;
	strcpy(newn->Ename,name);
	newn->Esalary=salary;
	
	
	if(*Head == NULL)
	{
		
		*Head =newn;
	}
	else
	{
		
		newn->next=*Head;
		*Head=newn;
	}
}
void InsertLast(PPEMP Head, int eid, char name[],float salary)
{
	PEMP temp =*Head;
	PEMP newn =NULL;
	newn=(PEMP)malloc(sizeof(EMP));
	newn->next=NULL;
	newn->prev=NULL;
	newn->Eid=eid;
	strcpy(newn->Ename,name);
	newn->Esalary=salary;
	
	
	if(*Head == NULL)
	{
		
		*Head =newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp= temp->next;
		}
		temp->next=newn;
		newn->prev= temp;
		
	}
}
void InsertAtPos(PPEMP Head,int eid ,char name[], int pos,float salary)
{
    int size = 0,i = 0;
    PEMP newn = NULL;
    PEMP temp = *Head;
    
    size = Count(*Head);
    
    if((pos < 1) || (pos > size+1))
    {
        return;
    }
    
    if(pos == 1)
    {
        InsertFirst(Head,eid ,name,salary);
    }
    else if(pos == size + 1)
    {
        InsertLast(Head, eid,name,salary);
    }
    else
    {
        newn= (PEMP)malloc(sizeof(EMP));
        newn->Eid = eid;
		strcpy(newn->Ename,name);
		newn->Esalary=salary;
		
		
        newn->next = NULL;
        newn->prev = NULL;
        
        for(i = 1; i<pos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        
        temp->next = newn;
        newn->prev = temp;
    }
}
void DeleteFirst(PPEMP Head)
{
	if(Head == NULL)
	{
		printf("NO data available\n");
		return;
	}
	 else if((*Head)->next  == NULL)     // Single node
    {
        free(*Head);
        *Head = NULL;
    }
	else
	{
		(*Head) = (*Head) -> next;
          free((*Head) -> prev);
        (*Head) -> prev = NULL;
		
	}
}
void DeleteLast(PPEMP Head)
{
	 PEMP temp = *Head;
    
    if(*Head == NULL)           // Empty LL
    {
        return;
    }
    else if((*Head)->next  == NULL)     // Single node
    {
        free(*Head);
        *Head = NULL;
    }
    else                         
    {
        while(temp->next->next != NULL)       // More than one node
        {
            temp = temp->next;
        }
        
        free(temp->next);
        temp->next = NULL;
        
    }
}

void DeleteAtPos(PPEMP Head ,int pos)
{
    int size = 0, i = 0;
    PEMP temp = NULL;
    
    size = Count(*Head);
    
    if((pos < 1) || (pos > size))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(pos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        temp = *Head;
        for(i = 1; i < pos-1;i++)
        {
            temp = temp->next;
        }
        temp->next =  temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}
void Display(PEMP Head)
{
	if(Head == NULL)
	{
		printf("No employee detail available\n");
	}
	else
	{
		while(Head != NULL)
		{
			printf("\nEmployee ID :%d\n",Head->Eid);
			printf("Employee Name :%s\n",Head->Ename);
			printf("Employee Salary : %f\n",Head->Esalary);
			
			Head=Head->next;
		}
	}
}


int main()
{
	PEMP First=NULL;
	int choice = 1, no = 0, pos = 0;
	int Eid=0;
	float salary;
	char name[50];
				
    printf("-------------------------------------------\n");
    printf("Employee Details\n");
    printf("-------------------------------------------\n");
    
    while(choice!= 0)   
    {
        printf("-------------------------------------------\n");
        printf("Enter your choice : \n");
        printf("1:Insert first\n2:Insert Last\n3:Insert at position\n4:Delete first\n5:Delete Last\n");
        printf("6:Delete at position\n7:Display\n8:Count: \n0: Exit\n");
        scanf("%d", &choice);
        printf("-------------------------------------------\n");
        
        switch(choice)
        {
            case 1:
              
				printf("Enter Employee id\n");
				scanf("%d",&Eid);
				printf("Enter Employee name\n");
				scanf(" %[^'\n']s",name);
				printf("Enter Employee salary\n");
				scanf("%f",&salary);
				
                InsertFirst(&First,Eid,name,salary);
                break;
                
            case 2:
                printf("Enter Employee id\n");
				scanf("%d",&Eid);
				printf("Enter Employee name\n");
				scanf(" %[^'\n']s",name);
				printf("Enter Employee salary\n");
				scanf("%f",&salary);
				
                InsertLast(&First,Eid,name,salary);
                break;
               
            case 3 :
				printf("Enter Employee id\n");
				scanf("%d",&Eid);
				printf("Enter Employee name\n");
				scanf(" %[^'\n']s",name);
                printf("Enter position : \n");
                scanf("%d",&pos);
				printf("Enter Employee salary\n");
				scanf(" %f",&salary);
				
                InsertAtPos(&First,Eid,name,pos,salary);
                break;
            
            case 4:
			   DeleteFirst(&First);
                break;
                
            case 5 :
                DeleteLast(&First);
                break;
                
            case 6:
                 printf("Enter position : \n");
                 scanf("%d",&pos);
                 DeleteAtPos(&First,pos);
                 break;
                
            case 7:
                Display(First);
                break;
                
            case 8:
                printf("Number of node are %d\n", Count(First));
                break;
                
            case 0:
                printf("Thank you for using the application...\n");
                break;
                
            default:
                printf("Error : Wrong choice..\n");
        }
    }
    
	
	return 0;
}

