#include <stdio.h>
#include <stdlib.h>



struct int_list *insert(struct int_list**, int);   // funtion which inserts numbers(elements) in list //
void Sum(struct int_list *head, struct int_list *last, int athr);  // sum function //

struct int_list  // integral list //
{
	int x;
	struct int_list *next;
};


main()
{
	int s, a, i;
	char ans;
	
	do
	{
		struct int_list *head=NULL;  // create of head //
		do
		{
			printf("How many elements you want to put:");  
			scanf("%d", &s);
		}while (s<1);				// check for negative elements //

		for(i=0;i<s;i++)
		{
			printf("Put the %d element:", i+1);
			scanf("%d", &a);
			head=insert(&head, a);  // insert elements //
		}
	
		Sum(head, head, 0);  // sum of the elements //

		printf("\nPress any button to repeat or press 'e' to exit:\n"); 
		fflush(stdin);
		scanf("%c", &ans);
	}while (ans!='e');  // repeat program //

}


struct int_list *insert(struct int_list **head, int a)
{
	struct int_list *temp=*head;  // create temp //
	struct int_list *temp2;    // create temp2 //

	temp2=(struct int_list*)malloc(sizeof(struct int_list*));  // memory alocation of temp2 //

	temp2->x=a;        // put element in temp2 //
	temp2->next=NULL;  // put NULL in the next node of the list (end of list) //

	if (*head==NULL)   // if the head is NULL then put number(element) in that (begin of list) //
	{
		*head=temp2;
		return *head;
	}

	while(temp->next!=NULL)  // temp point to NULL //
		temp=temp->next;

	temp->next=temp2;   // put the number(element) in temp (in list) //
	return *head;

}



void Sum(struct int_list *head, struct int_list *last, int athr)
{

	if((head->x==100 && head->next->x==0) || (head->x==0 && head->next->x==100))  // if the head is 100 and the next node is 0 or the opposite then there is sum 100 (2 numbers 0,100) //
	{
		printf("Success sum of 100 between the numbers %d, %d!!\n", head->x, head->next->x);
		return;
	}

	if(head->x==100 && head->next!=NULL)  
	{
		Sum(head->next, head->next, 0);  // if the head is 100 and is not the last element of the list then we call the function sum and we have as begging the next element of the list (with head to the next element) //
		return;
	}
	if(last->next==NULL)   // if the last goes to the last element of the list then //
	{
		if(athr+last->x==100 && last->x!=100)  // if the sum is 100 and the last element is not 100 then success sum 100 //
		{
			printf("Success sum of 100 between the numbers %d, %d!!\n", head->x, last->x);
			return;
		}
		else if(athr+last->x>100 && head->next!=NULL)  // if the sum is bigger than 100 and the head is not in the last element of the list then we call the function Sum and we have as begging the next element of the list (with head to the next element) // 
		{
			Sum(head->next, head->next, 0);
			return;
		}
		else    // else we have not sum 100 in list //
		{
			printf("There is not sum of 100 in the list!!\n");
			return;
		}
	}

	athr+=last->x;  // sum //

	if(athr<100)    // if sum is less than 100 then we call the function Sum with the last point to the next element //
		Sum(head, last->next, athr);
	else if(athr>100)   // if sum is bigger than 100 then we call the function Sum with the last point to the next element //
		Sum(head, last->next, athr);
	else          // else we have sum 100 //
		printf("Success sum of 100 between the numbers %d, %d!!\n", head->x, last->x);
}





	


