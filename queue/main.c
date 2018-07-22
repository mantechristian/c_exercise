#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "queue.h"

int main(void)
{
	queue q;
	q.size = 0;
	q.head = 0;
	q.tail = 0;

	int menuChoice = 0;
	int exit = 0;
	int item = 0;

	char input[50];
	int i;

	for(i = 0; i < MAX_SIZE; i++)
    {
		q.list[i] = '\0';
	}

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

                printQueue(q);
                printf("\nPlease enter the item to enqueue.\nType in 'exit' to stop enqueueing:");

                do
                {
                    printf("\nEnqueue Item: ");
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

                        else if (q.size >= MAX_SIZE && strcmp(input, "exit") != 0)
                        {
                            printf("\nThe queue is full. Please dequeue.\n");
                            system("pause");
                            strcpy(input, "exit");
                        }

                        else
                        {
                            printf("Enqueueing item %d", item);
                            q = enqueue(q, item);
                            printQueue(q);
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

                printQueue(q);
                printf("\nDequeueing item.\n");
                //system("pause");

                q = dequeue(q);
                printQueue(q);

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
