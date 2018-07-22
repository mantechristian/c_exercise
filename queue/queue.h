#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_SIZE 5


typedef struct queue
{
	int list[MAX_SIZE];
	int head;
	int tail;
	int size;
} queue;


void showMenu();
void printQueue(queue q);
int askInput(int menuChoice);
int isIntString(char input[]);
queue shiftLeft(queue q, int removeIndex);
queue enqueue(queue q, int item);
queue dequeue(queue q);


void showMenu()
{
	printf("\nQueue Array Implementation:\n");
	printf("\n1.) Enqueue item");
	printf("\n2.) Dequeue item");
	printf("\n3.) Exit\n\n");
}

void printQueue(queue q)
{
	int i;
	fflush(stdout);
	printf("\nQueue (");

	for(i = 0; i < MAX_SIZE; i++)
    {
		if(q.list[i] == '\0' && sizeof(q.list[i] ==8))
		{
			printf("[%d] => NULL", i);
		}

		else
		{
			printf("[%d] => %d", i, q.list[i]);
		}

		if(i + 1 < MAX_SIZE)
		{
			printf(", ");
		}
	}

	printf(")\n");
	printf("queue.size = %d\n", q.size);
	printf("queue.head = q[%d] = %d\n", q.head, q.list[q.head]);
	printf("queue.tail = q[%d] = %d\n", q.tail, q.list[q.tail]);

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

queue shiftLeft(queue q, int removeIndex)
{
	int i;

    for(i = removeIndex; i + 1 < MAX_SIZE; i++)
    {
        q.list[i] = q.list[i+1];
    }

    q.list[MAX_SIZE-1] = '\0';

	return q;
}

queue enqueue(queue q, int item)
{
    q.list[q.size] = item;
    q.size += 1;

    if(q.size == 0)
    {
        q.tail = 0;
    }

    else
    {
        q.tail = q.size-1;
    }
    return q;
}

queue dequeue(queue q)
{
    if(q.size > 0)
    {
        q = shiftLeft(q, 0);
        q.size -= 1;
    }

    else
    {
        printf("\nThe queue is already empty.\n");
        system("pause");
    }

    if(q.size == 0)
    {
        q.tail = 0;
    }

    else
    {
        q.tail = q.size-1;
    }

    return q;
}
