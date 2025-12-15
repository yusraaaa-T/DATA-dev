#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* ekle(Node *head, int x) {
    Node *yeni = malloc(sizeof(Node));
    yeni->data = x;
    yeni->next = NULL;
    if (!head) return yeni;
    Node *tmp = head;
    while (tmp->next) tmp = tmp->next;
    tmp->next = yeni;
    return head;
}

void bastanSona(Node *head) {
    if (!head) return;
    printf("%d ", head->data);
    bastanSona(head->next);
}

void sondanBasa(Node *head) {
    if (!head) return;
    sondanBasa(head->next);
    printf("%d ", head->data);
}

int main() {
    Node *head = NULL;
    head = ekle(head, 1);
    head = ekle(head, 2);
    head = ekle(head, 3);
    head = ekle(head, 4);

    bastanSona(head);
    printf("\n");
    sondanBasa(head);

    return 0;
}

