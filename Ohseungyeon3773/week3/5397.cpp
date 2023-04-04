


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
#define MAX 2000000
  
typedef struct __listnode {
    char ch; 
  
    struct __listnode *next;
    struct __listnode *prev;
} Node;
  
Node *createNewNode(char ch) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->ch = ch;
    newNode->next = newNode;
    newNode->prev = newNode;
  
    return newNode;
}

/// @brief 노드를 삽입한다
/// @param newNode 삽입하려는 새 노드
/// @param prev 이전 노드
/// @param next 다음 노드
void insertNode(Node *newNode, Node *prev, Node *next) {
    newNode->next = next;
    newNode->prev = prev;
  
    prev->next = newNode;
    next->prev = newNode;
}
  
void removeNode(Node *remove) {
    remove->prev->next = remove->next;
    remove->next->prev = remove->prev;
  
    free(remove);
}
  
void destroy(Node *head) {
    Node *t1 = head->next;
    Node *t2 = NULL;
  
    while (t1 != head) {
        t2 = t1->next;
        removeNode(t1);
        t1 = t2;
    }
}
  
void print(Node *head) {
    Node *t1 = head->next;
  
    while (t1 != head) {
        printf("%c", t1->ch);
        t1 = t1->next;
    } printf("\n");
}
  
int main(void) {
    Node *head = createNewNode(0);
    Node *q = NULL;
    int T = 0, i = 0;
    char str[MAX], *p = 0;
  
    scanf("%d", &T);
 
    for (i=0;i<T;i++) {
        scanf("%s", str);
 
        p = str;
        q = head;
  
        while (*p) {
            if (*p == '<') {
                if (q != head){
                    q = q->prev;
                }
            } else if (*p == '>') {
                if (q->next != head){
                    q = q->next;
                }
            } else if (*p == '-') {
                if (q != head) {
                    q = q->prev;
                    removeNode(q->next);
                }
            } else {
                insertNode(createNewNode(*p), q, q->next);
                q = q->next;
            }
  
            p++;
        }
  
        print(head);
        destroy(head);
    }
  
    free(head);
    return 0;
}