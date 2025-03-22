#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

// helper func for creating new node
Node* createNode(int val){
    Node* node = malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    return node;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size) {return -1;}
    if(obj->head){
        Node* tempNode = obj->head;
        for(int i = 0; i < index; i++){
            if(tempNode->next) {
                tempNode = tempNode->next;
            } else {
                return -1;
            }
        }
        return tempNode->value;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = createNode(val);
    if(obj->head) {newNode->next = obj->head;}
    obj->head = newNode;
    obj->size++;
    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = createNode(val);
    if(obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* tempNodeptr = obj->head;
        while(tempNodeptr->next){
            tempNodeptr = tempNodeptr->next;
        }
        tempNodeptr->next = newNode;
    }
    obj->size++;
    return;    
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
    if(index < 0 || index > obj->size) {return;}
    if(index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
        
    Node* tempNode = obj->head;
    for(int i = 1; i < index; i++){
        if(tempNode->next) {
            tempNode = tempNode->next;
        } else {
            return;
        }
    }

    Node* newNode = createNode(val);
    newNode->next = tempNode->next;
    tempNode->next = newNode;
    obj->size++;
    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size) {return;}
    if(!obj->head) {return;}
    if(index == 0) {
        Node* tempNode = obj->head;
        obj->head = obj->head->next;
        free(tempNode);
        obj->size--;
        return;
    }
    Node* tempNode = obj->head;
    for(int i = 1; i < index; i++){
        if(tempNode->next) {
            tempNode = tempNode->next;
        } else {
            return;
        }
    }
    Node* nodeToDelete = tempNode->next;
    if(nodeToDelete) {
        tempNode->next = nodeToDelete->next;
        free(nodeToDelete);
    }
    obj->size--;
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* tmpNode = obj->head;
    while(tmpNode){
        Node* nextNode = tmpNode->next;
        free(tmpNode);
        tmpNode = nextNode;
    }
    free(obj);
    return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/

int main() {

    MyLinkedList* obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 2);
    myLinkedListDeleteAtIndex(obj, 0);

    printf("LinkedList[0] value is %d\n", myLinkedListGet(obj, 0));
    printf("LinkedList[0] value is %d\n", myLinkedListGet(obj, 1));
    printf("LinkedList[0] value is %d\n", myLinkedListGet(obj, 2));

    myLinkedListFree(obj);
 
    return 0;
}