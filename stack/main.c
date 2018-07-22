#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "stack.h"

int main(void)
{
	myStack s;
	initStack(&s);

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

                printStack(&s);
                printf("\nPlease enter the item to push.\nType in 'exit' to stop pushing to the stack:");

                do
                {
                    printf("\nPush Item: ");
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
                            printf("\nPushing item %d to the stack\n", item);
                            push(&s, item);
                            printStack(&s);
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

                if(s.size > 0)
                {
                    printStack(&s);
                }
                printf("\nPopping item from the stack.\n");
                //system("pause");

                pop(&s);

                if(s.size > 0)
                {
                    printStack(&s);
                }

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
