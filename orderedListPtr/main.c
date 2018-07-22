#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "orderedList.h"

int main(void)
{
	myList l;
	initList(&l);

	int menuChoice = 0;
	int exit = 0;
	int item = 0;

	char input[50];

	do
	{
        // system("cls");
		fflush(stdin);

		showMenu();
		menuChoice = askInput(menuChoice);

        switch(menuChoice)
        {
            case 1:
                system("cls");
                fflush(stdin);

                printList(&l);
                printf("\nPlease enter the item to add.\nType in 'exit' to stop adding to the list:");

                do
                {
                    printf("\nAdd Item: ");
                    gets(input);
                    // scanf("%s", input);
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

                        else
                        {
                            printf("\nAdding item %d to the stack\n", item);
                            addListItem(&l, item);
                            printList(&l);
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
                    printList(&l);
                    printf("\nRemove item: ");
                    scanf("%s", input);

                    if(isIntString(input))
                    {
                        item = atoi(input);
                        removeListItem(&l, item);
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
                printf("\nInvalid choice. Please try again.\n");
                system("pause");
                break;
        }

	} while(!exit);

	printf("\n\nProgram Exit\n\n");
	return 0;

}
