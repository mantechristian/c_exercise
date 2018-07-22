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

typedef struct myList
{
	node *head, *tail;
	int size;
} myList;

void init(node *n, int item);
void initList(myList *l);
void addListItem(myList *l, int item);
void removeListItem(myList *l, int item);
void showMenu();
void printList(myList *l);
int askInput(int menuChoice);
int isIntString(char input[]);


void init(node *n, int item)
{
    // memcpy(n1, n2, s)
    // copy to memory area n1 from  memory area n2 s characters
    memcpy(&n->item, &item, sizeof(int));
    n->next = n->prev = NULL;
}

void initList(myList *l)
{
    l->head = l->tail = NULL;
    l->size = 0;
}

void addListItem(myList *l, int item)
{
    node *n = (node*)malloc(sizeof(node));
    node *tmp, *tmpTail, *tmpHead;

    init(n, item);
    tmp = l->head;

    if(l->size == 0)
    {
        l->head = l->tail = n;
    }

    else
    {
        while(tmp->item < n->item && tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        if(l->size == 1)
        {
            if(n->item > tmp->item)
            {
                tmp->next = n;
                n->prev = tmp;
                l->tail = n;
            }

            else
            {
                tmp->prev = n;
                n->next = tmp;
                l->head = n;
            }
            l->size += 1;
            return;
        }

        else
        {
            if(tmp->item < n->item)
            {
                n->prev = tmp;
                tmp->next = n;
            }

            else
            {
                n->next = tmp;
                if(tmp->prev != NULL)
                {
                    n->prev = tmp->prev;
                    tmp->prev->next = n;
                    tmp->prev = n;
                }
                else
                {
                    tmp->prev = n;
                    l->head = n;
                }
            }
        }

        tmpTail = l->head;

        while(tmpTail->next != NULL)
        {
            tmpTail = tmpTail->next;
        }

        l->tail = tmpTail;

        tmpHead = l->head;

        while(tmpHead->prev != NULL)
        {
            tmpHead = tmpHead->prev;
        }

        l->head = tmpHead;
    }

    l->size += 1;
}


void removeListItem(myList *l, int item)
{
    node *tmp;

    if(l->size == 0)
    {
        printf("\nThe list is empty.\n");
        return;
    }

    else
    {
        tmp = l->head;

        while(tmp->item != item)
        {
            tmp = tmp->next;
            if(tmp == NULL)
            {
                printf("\nThe item '%d' is not in the list.\n", item);
                return;
            }
        }

        if(l->size > 1)
        {
            if(l->head == tmp)
            {
                l->head = tmp->next;
                tmp->next->prev = NULL;
            }

            else if(l->tail == tmp)
            {
                l->tail = tmp->prev;
                tmp->prev->next = NULL;
            }

            else
            {
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
            }

            tmp->next = NULL;
            tmp->prev = NULL;
        }

        else
        {
            l->head = NULL;
            l->tail = NULL;
        }

        free(tmp);

        l->size -= 1;
    }
}

void showMenu()
{
	printf("\nOrdered List Pointer Implementation:\n");
	printf("\n1.) Add item");
	printf("\n2.) Delete item");
	printf("\n3.) Exit\n\n");
}

void printList(myList *l)
{
	int i;
	node *tmp;

	i = 0;

	if(l->size == 0)
    {
        printf("\nThe ordered list is empty.\n");
        // system("pause");
        return;
	}

    tmp = l->head;

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
    printf("\nlist.head = %d\nlist.tail = %d\n", l->head->item, l->tail->item);
	printf("list.size = %d\n", l->size);
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
