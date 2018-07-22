#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_SIZE 5

typedef struct node {
    int item;
    struct node *next, *prev;
} node;

typedef struct myStack
{
	node *top;
	int size;
} myStack;

void init(node *n, int item);
void initStack(myStack *s);
void push(myStack *s, int item);
void pop(myStack *s);
void showMenu();
void printStack(myStack *s);
int askInput(int menuChoice);
int isIntString(char input[]);


void init(node *n, int item)
{
    // memcpy(n1, n2, s)
    // copy to memory area n1 from  memory area n2 s characters
    memcpy(&n->item, &item, sizeof(int));
    n->next = n->prev = NULL;
}

void initStack(myStack *s)
{
    s->top = NULL;
    s->size = 0;
}

void push(myStack *s, int item)
{
    node *n = (node*)malloc(sizeof(node));
    init(n, item);

    if(s->size == 0)
    {
        s->top = n;
    }
    else
    {
        n->prev = s->top;
        s->top->next = n;
        s->top = n;
    }
    s->size += 1;
}

void pop(myStack *s)
{
    node *tmp;
    if(s->size == 0)
    {
        printf("\nThe stack is empty.\n");
        system("pause");
    }

    else if(s->size == 1)
    {
        tmp = s->top;
        s->top = NULL;
        free(tmp);
        s->size -=1;
        return;
    }

    else
    {
        tmp = s->top;
        s->top = s->top->prev;
        s->top->next = NULL;
        tmp->prev = NULL;
        free(tmp);
        s->size -= 1;
    }
}

void showMenu()
{
	printf("\nStack Pointer Implementation:\n");
	printf("\n1.) Push item");
	printf("\n2.) Pop item");
	printf("\n3.) Exit\n\n");
}

void printStack(myStack *s)
{
	int i;
	node *n, *tmp;

	i = 0;
	n = s->top;

	if(s->size == 0)
    {
        printf("\nThe stack is empty.\n");
        // system("pause");
        return;
	}

	while(n->prev != NULL)
    {
        n = n->prev;
        // printf("\nbacktracking: %d\n", n->item);
        //system("pause");
    }

    tmp = n;

    fflush(stdout);
	printf("\nStack (");

    while(tmp != NULL)
    {
        if(tmp->item == '\0' && sizeof(tmp->item == 8))
        {
            printf("[%d] => NULL", tmp->item);
        }

        else
        {
            printf("[%d] => %d", i, tmp->item);
        }

        if(tmp->next != NULL)
        {
            printf(", ");
        }
        i += 1;
        tmp = tmp->next;
        //system("pause");
    }

	printf(")\n");
	printf("stack.size = %d\n", s->size);
}

int askInput(int menuChoice)
{
	scanf("%d", &menuChoice);
	fflush(stdin);
	return menuChoice;
}

int isIntString(char input[])
{
	int i;
	int len = strlen(input);

	for(i = 0; i < len; i++)
    {
		if(input[i] == '-' && i != 0)
		{
			return 0;
		}
	}

	for(i = 0; i < len; i++)
    {
		if((!isdigit(input[i])) && input[i] != '-')
		{

		// if(input[i] > 57 && input[i] < 48) {
			return 0;
		}
	}

	return 1;
}
