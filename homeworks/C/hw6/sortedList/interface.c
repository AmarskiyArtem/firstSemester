#include <stdio.h>
#include <stdbool.h>

#include "sortedList.h"

void main() {
    if (!tests()) {
        printf("Tests failed");
        return;
    }
    SortedList* sortedlist = createSortedList();
    if (sortedlist == NULL) {
        printf("All bad");
        return;
    }
    printf("ACTIONS:\n"
        "0 - exit\n"
        "1 - add new element\n"
        "2 - delete element\n"
        "3 - print sorting list\n");
    bool isContinue = true;
    while (isContinue) {
        int currentAction = 0;
        printf("Input action: \n");
        scanf_s("%d", &currentAction);
        switch (currentAction) {
            case 0: {
                isContinue = false;
                printf("Good bye!");
                break;
            }
            case 1: {
                int value = 0;
                printf("Input a number:\n");
                scanf_s("%d", &value);
                if (push(sortedlist, value) != ok) {
                    printf("Problems with memory allocation\n");
                }
                else {
                    printf("Insert successfull\n");
                }
                break;
            }
            case 2: {
                int value = 0;
                printf("Input a number:\n");
                scanf_s("%d", &value);
                if (deleteValue(sortedlist, value) != ok) {
                    printf("No such element in list\n");
                }
                else {
                    printf("deletion successfull\n");
                }
                break;
            }
            case 3: {
                printf("===========\n");
                if (printSortedList(sortedlist) != ok) {
                    printf("Sorted list is empty\n");
                }
                break;
            }
            default: {
                printf("Incorrect input\n");
                break; 
            }
        }
    }
    deleteSortedList(&sortedlist);
}