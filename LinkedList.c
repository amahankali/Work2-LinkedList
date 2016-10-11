#include <stdio.h>
#include <stdlib.h>

struct node {

	int i;
	struct node* next;

};

void printlistH(struct node* start)
{
	if(start == NULL)
	{
		printf("]");
		return;
	}
	printf("%d ", start->i);
	printlistH(start->next);
}

void printlist(struct node* start)
{
	printf("[ ");
	printlistH(start);
	printf("\n");
}

struct node* insertFront(struct node* startI, int val)
{
	struct node *newStart = (struct node*) malloc(sizeof(struct node));
	newStart->i = val;
	newStart->next = startI;
	return newStart;
}

struct node* freeList(struct node* start)
{
	if(start->next == NULL)
	{
		free(start);
		return NULL;
	}
	freeList(start->next);
	free(start);
	return NULL;
}

int main () {

	struct node *start = (struct node*) malloc(sizeof(struct node));
	start->i = 10;
	start->next = NULL;

	printf("===========================printlist and insertFront test===========================\n");
	printlist(start);

	start = insertFront(start, 20);
	printf("inserted 20:\n");
	printlist(start);
	//printlist(start->next);
	printf("\n");

	start = insertFront(start, 30);
	printf("inserted 30:\n");
	printlist(start);
	//printlist(start->next);
	//printlist(start->next->next);
	//printlist(start->next->next->next);
	printf("\n");

	printf("===========================freeList test===========================\n");
	start = freeList(start);
	printf("start freed:\n");
	printlist(start);
}