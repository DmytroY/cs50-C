#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// Declare myLL as a global variable
LinkedList myLL;

void createLinkedList(){
    LinkedList myLL ={NULL, 0};
}

void addNodeEnd(int val){
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    node->val = val;
    node->next = NULL;

    if(myLL.size == 0){
        myLL.head = node;
        
    } else {
        Node* tempNode = myLL.head;
        while(tempNode->next) {
            tempNode = tempNode->next;
        }
        tempNode->next = node;
    }
    myLL.size++;
}

int getNode(int n){
    if(myLL.size <= n) { return -1;}
    Node* tempNode = myLL.head;
    for(int i = 0; i < n; i++) {
        tempNode = tempNode->next;
    }

    return tempNode->val;
}

void freeLL(){
    Node* tempNode = myLL.head;
    while(tempNode){
        Node* nextNode = tempNode->next;
        free(tempNode);
        tempNode = nextNode;
    }
    myLL.head = NULL;
    myLL.size = 0;

}

int main() {

    createLinkedList();
    printf("%d\n", getNode(0));
    addNodeEnd(5);
    addNodeEnd(10);
    printf("%d\n", getNode(0)); 
    printf("%d\n", getNode(1));

    freeLL();
    return 0;
}