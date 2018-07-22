#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "orderedList.h"

int main(void)
{
	orderedList listArr;
	listArr.size = 0;

	int menuChoice = 0;
	int exit = 0;
	int item = 0;

	char input[50];
	int i;

	for(i = 0; i < MAX_SIZE; i++)
    {
		listArr.list[i] = '\0';
	}

	do
	{
        system("cls");
		fflush(stdin);

		showMenu();
		menuChoice = askInput(menuChoice);

        switch(menuChoice)
        {
            case 1:
                system("cls");
                fflush(stdin);

                printList(listArr);
                printf("\nPlease enter the item to insert into the list.\nType in 'exit' to stop adding:");

                do
                {
                    printf("\nInsert Item: ");
                    gets(input);
                    //scanf("%s", input);
                    // system("cls");

                    if(isIntString(input) && input[0] != '\0')
                    {
                        item = atoi(input);
                        printf("\n%d\n", item);

                        if(item > INT_MAX || item < INT_MIN)
                        {
                            printf("\nItem exceeds valid integer size.\n");
                            system("pause");
                        }

                        else if (listArr.size >= MAX_SIZE && strcmp(input, "exit") != 0)
                        {
                            printf("\nThe ordered list is full. Please remove items.\n");
                            system("pause");
                            strcpy(input, "exit");
                        }

                        else
                        {
                            printf("Adding item %d", item);
                            listArr = addListItem(listArr, item);
                            printList(listArr);
                        }
                    }

                    else
                    {
                        if(strcmp(input, "exit") != 0)
                        {
                            printf("\nItem not an integer.\n");
                            system("pause");
                        }
                    }

                } while(strcmp(input, "exit") != 0);
                break;

            case 2:
                system("cls");
                fflush(stdin);

                printf("\nRemove item from list:\nType in 'exit' to stop:");

                do
                {
                    printList(listArr);
                    printf("\nItem to remove: ");
                    scanf("%s", input);

                    if(isIntString(input))
                    {
                        item = atoi(input);
                        listArr = removeListItem(listArr, item);
                    }
                    else
                    {
                        if(strcmp(input, "exit") != 0)
                        {
                            printf("\nItem not an integer.\n");
                            system("pause");
                        }
                    }
                } while(strcmp(input, "exit") != 0);
                break;

            case 3:
                system("cls");
                fflush(stdin);

                exit = 1;
                break;

            default:
                system("cls");
                fflush(stdin);

                printf("\nInvalid choice. Please try again.\n");
                system("pause");
                break;
        }

	} while(!exit);

	printf("\n\nThe program will now terminate.\n\n");
	return 0;

}
