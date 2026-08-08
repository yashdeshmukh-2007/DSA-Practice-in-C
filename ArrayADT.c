#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void CreateArray(struct Array *arr) {
    int n;

    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);

    if (n > arr->size) {
        printf("Error: Number of elements exceeds the array size.\n");
        return;
    }

    arr->length = n;

    for (int i = 0; i < n; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr->A[i]);
    }

    printf("Array created successfully!\n");
}

void DisplayArray(struct Array *arr) {
    if (arr->length == 0) {
        printf("\nArray is empty.\n");
        return;
    }

    printf("\nElements in the array are: ");

    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }

    printf("\n");
}

void InsertAtFirst(struct Array *arr, int x) {
    if (arr->length >= arr->size) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    for (int i = arr->length; i > 0; i--) {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[0] = x;
    arr->length++;

    printf("Element inserted successfully at the beginning.\n");
}

void InsertAtLast(struct Array *arr, int x) {
    if (arr->length >= arr->size) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    arr->A[arr->length] = x;
    arr->length++;

    printf("Element inserted successfully at the end.\n");
}

void InsertAtIndex(struct Array *arr, int x, int index) {
    if (arr->length >= arr->size) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    if (index < 0 || index > arr->length) {
        printf("Invalid index. Cannot insert at index %d.\n", index);
        return;
    }

    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
    }

    arr->A[index] = x;
    arr->length++;

    printf("Element inserted successfully at index %d.\n", index);
}

void DeleteAtFirst(struct Array *arr) {
    if (arr->length == 0) {
        printf("Array is empty, element can't be deleted.\n");
        return;
    }

    for (int i = 0; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }

    arr->length--;

    printf("First element deleted successfully.\n");
}

void DeleteAtLast(struct Array *arr) {
    if (arr->length == 0) {
        printf("Array is empty, element can't be deleted.\n");
        return;
    }

    arr->length--;

    printf("Last element deleted successfully.\n");
}

void DeleteAtIndex(struct Array *arr, int index) {
    if (arr->length == 0) {
        printf("Array is empty, element can't be deleted.\n");
        return;
    }

    if (index < 0 || index >= arr->length) {
        printf("Invalid index. Cannot delete element at index %d.\n", index);
        return;
    }

    for (int i = index; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }

    arr->length--;

    printf("Element at index %d deleted successfully.\n", index);
}

void SortArray(struct Array *arr) {
    int temp;

    for (int i = 0; i < arr->length - 1; i++) {
        int swapped = 0;

        for (int j = 0; j < arr->length - i - 1; j++) {
            if (arr->A[j] > arr->A[j + 1]) {
                temp = arr->A[j];
                arr->A[j] = arr->A[j + 1];
                arr->A[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0) {
            break;
        }
    }

    printf("Array sorted successfully!\n");
}

void SearchArray(struct Array *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) {
            printf("Element found at index %d.\n", i);
            return;
        }
    }

    printf("Element not found in the given array.\n");
}

int main() {
    struct Array arr;
    int ch, x, y, z, index, p, q;
    int isCreated = 0;

    printf("Enter the maximum size for the array: ");
    scanf("%d", &arr.size);

    arr.A = (int *)malloc(arr.size * sizeof(int));

    if (arr.A == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    arr.length = 0;

    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Create an Array\n");
        printf("2. Display the Array\n");
        printf("3. Insert at first\n");
        printf("4. Insert at last\n");
        printf("5. Insert at index\n");
        printf("6. Delete at first\n");
        printf("7. Delete at last\n");
        printf("8. Delete at index\n");
        printf("9. Sort the Array\n");
        printf("10. Search in the Array\n");
        printf("11. Exit\n");
        printf("-----------------------------\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch != 1 && ch != 11 && isCreated == 0) {
            printf("\nPlease create and populate an array first (Option 1).\n");
            continue;
        }

        switch (ch) {
            case 1:
                CreateArray(&arr);
                isCreated = 1;
                break;

            case 2:
                DisplayArray(&arr);
                break;

            case 3:
                printf("Enter the element to insert at first: ");
                scanf("%d", &x);
                InsertAtFirst(&arr, x);
                break;

            case 4:
                printf("Enter the element to insert at last: ");
                scanf("%d", &y);
                InsertAtLast(&arr, y);
                break;

            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &z);

                printf("Enter the index: ");
                scanf("%d", &index);

                InsertAtIndex(&arr, z, index);
                break;

            case 6:
                DeleteAtFirst(&arr);
                break;

            case 7:
                DeleteAtLast(&arr);
                break;

            case 8:
                printf("Enter the index to delete: ");
                scanf("%d", &p);
                DeleteAtIndex(&arr, p);
                break;

            case 9:
                SortArray(&arr);
                break;

            case 10:
                printf("Enter the element to search: ");
                scanf("%d", &q);
                SearchArray(&arr, q);
                break;

            case 11:
                printf("Exiting the program. Freeing memory...\n");
                free(arr.A);
                return 0;

            default:
                printf("Invalid Input. Please try again.\n");
        }
    }
}