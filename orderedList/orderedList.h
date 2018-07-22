#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_SIZE 5


typedef struct orderedList
{
	int list[MAX_SIZE];
	int size;
} orderedList;


void showMenu();
void printList(orderedList listArr);
int askInput(int menuChoice);
int isIntString(char input[]);
int findItem(orderedList listArr, int item);
int findInsertIndex(orderedList listArr, int item);
orderedList insertToPlace(orderedList listArr, int item, int insertIndex);
orderedList shiftLeft(orderedList listArr, int removeIndex);
orderedList shiftRight(orderedList listArr, int insertIndex);
orderedList addListItem(orderedList listArr, int item);
orderedList removeListItem(orderedList listArr, int item);


void showMenu()
{
	printf("\nOrdered List Array Implementation:\n");
	printf("\n1.) Add item to list");
	printf("\n2.) Delete item from list");
	printf("\n3.) Exit\n\n");
}

void printList(orderedList listArr)
{
	int i;
	fflush(stdout);
	printf("\nList (");

	for(i = 0; i < MAX_SIZE; i++)
    {
		if(listArr.list[i] == '\0' && sizeof(listArr.list[i] ==8))
		{
			printf("[%d] => NULL", i);
		}

		else
		{
			printf("[%d] => %d", i, listArr.list[i]);
		}

		if(i + 1 < MAX_SIZE)
		{
			printf(", ");
		}
	}

	printf(")\n");
	printf("listArr.size = %d\n", listArr.size);
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

int findItem(orderedList listArr, int item)
{
	int i;

	for(i = 0; i < MAX_SIZE; i++)
    {
		if(listArr.list[i] == item)
		{
			return i;
		}
	}

	return (-1);
}

int findInsertIndex(orderedList listArr, int item)
{
	int i;

	if(listArr.size == 0)
    {
		return 0;
	}

	for(i = 0; i  < MAX_SIZE; i++)
    {
		if(item < listArr.list[i] || listArr.list[i] == '\0')
		{
			return i;
		}
	}
	return -1;
}

orderedList insertToPlace(orderedList listArr, int item, int insertIndex)
{
	listArr.list[insertIndex] = item;
    return listArr;
}


orderedList shiftLeft(orderedList listArr, int removeIndex)
{
	int i;

	if(removeIndex == (MAX_SIZE - 1))
    {
        listArr.list[MAX_SIZE-1] = '\0';
		return listArr;
	}

	else
    {
		for(i = removeIndex; i + 1 < MAX_SIZE; i++)
		{
            listArr.list[i] = listArr.list[i+1];
		}

        listArr.list[MAX_SIZE-1] = '\0';
	}

	return listArr;
}

orderedList shiftRight(orderedList listArr, int insertIndex)
{
	int i;

	for(i = listArr.size; i  >= insertIndex; i--)
    {
		if(i != insertIndex)
		{
			listArr.list[i] = listArr.list[i-1];
		}

        else
        {
			listArr.list[i] = '\0';
		}
	}

	return listArr;
}

orderedList addListItem(orderedList listArr, int item)
{
	int insertIndex = 0;
	insertIndex = findInsertIndex(listArr, item);
	printf("\ninsert index: %d\n", insertIndex);

	if(insertIndex >=0)
    {
		listArr = shiftRight(listArr, insertIndex);
		listArr = insertToPlace(listArr, item, insertIndex);
		listArr.size += 1;
	}
	else
    {
		printf("\nCannot insert item.\n");
	}

	return listArr;
}

orderedList removeListItem(orderedList listArr, int item)
{
	int removeIndex;
	removeIndex = findItem(listArr, item);

	if(removeIndex >= 0)
    {
		//listArr = removeItem(listArr, item, removeIndex);
		listArr = shiftLeft(listArr, removeIndex);
		listArr.size -= 1;
	}
	else
    {
	    if(listArr.size == 0)
	    {
            printf("\nThe list is empty.\n");
	    }
	    else
	    {
            printf("\nItem not in list.\n");
	    }
	}

	return listArr;
}
