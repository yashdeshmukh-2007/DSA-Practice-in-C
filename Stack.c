#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int *S;
    int size;
};

int isFull(struct stack * W){
    if (W->top == W->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack * W){
    if (W->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * W, int element){
    if(isFull(W)){
        printf("Stack Overflow! Cannot push %d\n", element);
    }
    else{
        W->top++;
        W->S[W->top] = element;
        printf("%d pushed to stack\n", element);
    }
}

void pop(struct stack * W){
    if(isEmpty(W)){
        printf("Stack Underflow! Cannot pop from empty stack\n");
    }
    else{
        printf("%d popped from stack\n", W->S[W->top]);
        W->top--;
    }
}

void Stacktop(struct stack * W){
    if(isEmpty(W)){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is: %d\n", W->S[W->top]);
    }
}

void display(struct stack * W){
    if(isEmpty(W)){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack elements: ");
        for(int i=W->top; i>=0; i--){
            printf("%d ", W->S[i]);
        }
        printf("\n");
    }
}
// void Peek(struct stack * W, int index){
//     if(isEmpty(W)){
//         printf("Stack is empty\n");
//     }
//     else{
//         printf("Element at index %d from top is: %d\n", index, W->S[W->top - index -1]);
//     }
// }



int main(){
    struct stack * W;
    W=(struct stack*)malloc(sizeof(struct stack));
    W->top=-1;

    printf("Enter Size of Stack: ");
    scanf("%d",&W->size);

    W->S=(int*)malloc(W->size*sizeof(int));
    int choice;

    while(1){
        
        printf("\n1.Push\n2.Pop\n3.Display\n4.Stacktop\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the number of elements you want to push: ");
                int numElements;
                scanf("%d", &numElements);
                for(int i=0; i<numElements; i++){
                    printf("Enter Element to Push: ");
                    int element;
                    scanf("%d", &element);
                    push(W, element);
                }
                break;
            case 2:
                pop(W);
                break;
            case 3:
                display(W);
                break;
            // case 4:
            //     while(1){
            //         printf("Enter the index of the element to peek from the top (0 for top element): ");
            //         int index;
            //         scanf("%d", &index);

            //         if(index < 0 || index > W->top){
            //             printf("Invalid index! Please try again.\n");
            //         } else {
            //             Peek(W, index);
            //             break;
            //         }
            //     }
            //     break;

            case 4:
                Stacktop(W);
                break;

            case 5:
                free(W->S);
                free(W);
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid Choice! Please try again.\n");
                break;
        }
    }
    return 0;
}