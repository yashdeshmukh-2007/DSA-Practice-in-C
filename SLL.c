#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void CreateSLL(struct Node **N){
    struct Node *temp, *last = NULL;
    int n;

    printf("Enter the number of nodes you want to make in the singly linked list : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        if(temp == NULL){
            printf("Memory Allocation failed.\n");
            return;
        }
        printf("Enter the data for node %d : ", i+1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if(*N == NULL){
            *N = temp;
            last = temp;
        }
        else{
            last->next = temp;
            last = temp;
        }
    }
}

void InsertatfirstinSLL(struct Node** N, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Memory Allocation failed.\n");
        return;
    }
    temp->data = x;
    temp->next = *N;
    *N = temp;
}

void InsertatlastinSLL(struct Node **N, int y){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL){
        printf("Memory Allocation failed.\n");
        return;
    }
    temp->data = y;
    temp->next = NULL;

    if(*N == NULL){
        *N = temp;
    }
    else{
        struct Node* p = *N;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

void InsertatindexinSLL(struct Node** N, int z, int index){
    if(index < 0){
        printf("Enter a valid Index !!\n");
    }
    else if(index == 0){
        InsertatfirstinSLL(N, z);
    }
    else{
        int c = 0;
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        if(temp == NULL){
            printf("Memory Allocation failed.\n");
            return;
        }
        temp->data = z;
        struct Node* p = *N;

        while(c < index - 1){
            if(p == NULL){
                printf("Index out of bounds.\n");
                free(temp);
                return;
            }
            c++;
            p = p->next;
        }

        if(p == NULL){
            printf("Index out of bounds.\n");
            free(temp);
            return;
        }

        temp->next = p->next;
        p->next = temp;
    }
}

void DeleteatfirstinSLL(struct Node** N){
    if(*N == NULL){
        printf("The Singly Linked List is EMPTY.\n");
    }
    else{
        struct Node *temp = *N;
        *N = (*N)->next;
        free(temp);
    }
}

void DeleteatlastinSLL(struct Node** N){
    if(*N == NULL){
        printf("The Singly Linked List is EMPTY.\n");
        return;
    }
    if((*N)->next == NULL){
        free(*N);
        *N = NULL;
        return;
    }
    struct Node *temp1 = (*N)->next;
    struct Node *temp2 = *N;
    while(temp1->next != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp2->next = NULL;
    free(temp1);
}

void DeleteatindexinSLL(struct Node** N, int index){
    if(*N == NULL){
        printf("The Singly Linked List is EMPTY.\n");
        return;
    }
    else if(index < 0){
        printf("Enter a valid Index !!\n");
        return;
    }
    else if(index == 0){
        DeleteatfirstinSLL(N);
        return;
    }

    int ct = 0;
    struct Node* temp1 = (*N)->next;
    struct Node* temp2 = *N;

    while(ct < index - 1){
        if(temp1 == NULL){
            printf("Index out of bounds.\n");
            return;
        }
        ct++;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(temp1 == NULL){
        printf("Index out of bounds.\n");
        return;
    }

    temp2->next = temp1->next;
    free(temp1);
    return;
}

void SortSLL(struct Node** N) {
    if(!(*N) || !(*N)->next) return;
    int swapped, temp;
    struct Node* p;
    do {
        swapped = 0;
        p = *N;
        while(p->next) {
            if(p->data > p->next->data) {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                swapped = 1;
            }
            p = p->next;
        }
    } while(swapped);
}

void SearchSLL(struct Node** N, int q){
    struct Node* p = *N;
    int index = 0;
    while(p != NULL){
        if(p->data == q){
            printf("The element %d is found at index %d in the Singly Linked List.\n", q, index);
            return;
        }
        else{
            p = p->next;
            index++;
        }
    }
    printf("The element %d is not found in the Singly Linked List.\n", q);
}

void DisplaySLL(struct Node **N){
    struct Node *p = *N;
    if(p == NULL){
        printf("The Singly Linked List is EMPTY.\n");
        return;
    }
    while(p != NULL){
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

void FreeSLL(struct Node** N){
    struct Node* p = *N;
    struct Node* temp;
    while(p != NULL){
        temp = p;
        p = p->next;
        free(temp);
    }
    *N = NULL;
}

int main(){
    struct Node* head = NULL;
    int ch, x, y, z, index, p, q;

    while(1){
        printf("Perform the following operations : \n");
        printf("1]  Create Singly Linked List.\n");
        printf("2]  Display Singly Linked List.\n");
        printf("3]  Insert at first in Singly Linked List.\n");
        printf("4]  Insert at last Singly Linked List.\n");
        printf("5]  Insert at index in Singly Linked List.\n");
        printf("6]  Delete at first in Singly Linked List.\n");
        printf("7]  Delete at last in Singly Linked List.\n");
        printf("8]  Delete at index in Singly Linked List.\n");
        printf("9]  Sort Singly Linked List.\n");
        printf("10] Search in Singly Linked List.\n");
        printf("11] Exit.\n");
        printf("\n\n");

        printf("Enter the operation you want to perform : ");
        scanf("%d", &ch);

        if((ch != 1 && ch != 11) && head == NULL){
            printf("Please create a Singly Linked List first.\n");
            continue;
        }
        if(ch == 1 && head != NULL){
            printf("A Singly Linked List already exists.\n");
            continue;
        }
        switch(ch){
            case 1:
                CreateSLL(&head);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 2:
                DisplaySLL(&head);
                printf("\n\n");
                break;
            case 3:
                printf("Enter the element you want to insert at first in the Singly Linked List : ");
                scanf("%d", &x);
                InsertatfirstinSLL(&head, x);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 4:
                printf("Enter the element you want to insert at last in the Singly Linked List : ");
                scanf("%d", &y);
                InsertatlastinSLL(&head, y);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 5:
                printf("Enter the element you want to insert in the Singly Linked List : ");
                scanf("%d", &z);
                printf("Enter the index where you want to insert the element : ");
                scanf("%d", &index);
                InsertatindexinSLL(&head, z, index);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 6:
                DeleteatfirstinSLL(&head);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 7:
                DeleteatlastinSLL(&head);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 8:
                printf("Enter the index where you want to delete the element : ");
                scanf("%d", &p);
                DeleteatindexinSLL(&head, p);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 9:
                SortSLL(&head);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 10:
                printf("Enter the element you want to search in the Singly Linked List : ");
                scanf("%d", &q);
                SearchSLL(&head, q);
                printf("\n\nDisplay the Singly Linked List to see the result of the operations performed.\n\n\n");
                break;
            case 11:
                printf("Exiting the program.\n");
                FreeSLL(&head);
                return 0;
            default:
                printf("Invalid Input. Please try again.\n\n\n");
                break;
        }
    }
}