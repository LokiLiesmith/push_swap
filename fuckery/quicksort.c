#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

/* Definition of a singly linked list node */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Utility function to get the tail of the list */
Node* getTail(Node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

/* Partitions the list around the end node as pivot
   newHead and newEnd will be updated to the new head and end of the partitioned list */
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* cur = head;
    Node* tail = pivot;

    // During partition, we build lists of < pivot and >= pivot
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the pivot becomes new head
            if (*newHead == NULL)
                *newHead = cur;

            prev = cur;
            cur = cur->next;
        } else {
            // Move nodes greater or equal to pivot to the tail
            if (prev)
                prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if (*newHead == NULL)
        *newHead = pivot;

    // Update newEnd to the current last node
    *newEnd = tail;

    return pivot;
}

/* The main recursive quicksort for linked list. Returns new head of the list. */
Node* quickSortRecur(Node* head, Node* end) {
    // Base case: empty list or single node
    if (!head || head == end)
        return head;

    Node* newHead = NULL;
    Node* newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated
    Node* pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element, it is already at head
    if (newHead != pivot) {
        // Recurse on the left side
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for left part
        newHead = quickSortRecur(newHead, tmp);

        // Connect the sorted left list with pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    // Recurse on the right side of pivot
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

/* QuickSort entry function */
void quickSort(Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

/* Utility to insert a node at the beginning */
void push(Node** headRef, int newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

/* Utility to print the linked list */
void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int arr[] = {44, 28, 37, 18, 27, 31, 21, 10, 1, 16, 19, 20, 26, 22, 14, 11, 12, 5, 9, 13, 6, 49, 23, 48, 25, 33, 38, 30, 34, 45, 41, 2, 24, 36, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    for (int i = n - 1; i >= 0; i--) {
        push(&head, arr[i]);
    }

    printf("Original list:\n");
    printList(head);

    quickSort(&head);

    printf("Sorted list:\n");
    printList(head);

    return 0;
}
