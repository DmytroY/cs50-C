#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* curNode = head;
    while(curNode->next) {
        struct ListNode* nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = head;
        head = nextNode;
    }
    return head;
}

int main() {
  
    struct ListNode* node2 = &(struct ListNode){2, NULL};
    struct ListNode* node1 = &(struct ListNode){1, node2};
    struct ListNode* node0 = &(struct ListNode){0, node1};

    printf("node0: %d\n", node0->val);
    printf("node1: %d\n", node0->next->val);
    printf("node2: %d\n", node0->next->next->val);

    struct ListNode* reversed = reverseList(node0);
    printf("reversed node0: %d\n", reversed->val);
    printf("reversed node1: %d\n", reversed->next->val);
    printf("reversed node2: %d\n", reversed->next->next->val);

    return 0;
}