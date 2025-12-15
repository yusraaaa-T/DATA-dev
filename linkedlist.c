#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

void dllSonaEkle(DNode** head, int data) {
    DNode* yeni = malloc(sizeof(DNode));
    yeni->data = data;
    yeni->next = NULL;
    yeni->prev = NULL;

    if (*head == NULL) {
        *head = yeni;
        return;
    }

    DNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = yeni;
    yeni->prev = temp;
}

void dllArayaEkle(DNode* head, int aranan, int data) {
    DNode* temp = head;

    while (temp != NULL && temp->data != aranan)
        temp = temp->next;

    if (temp == NULL)
        return;

    DNode* yeni = malloc(sizeof(DNode));
    yeni->data = data;

    yeni->next = temp->next;
    yeni->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = yeni;

    temp->next = yeni;
}

void dllYazdir(DNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void sllSonaEkle(SNode** head, int data) {
    SNode* yeni = malloc(sizeof(SNode));
    yeni->data = data;
    yeni->next = NULL;

    if (*head == NULL) {
        *head = yeni;
        return;
    }

    SNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = yeni;
}

void sllRecursiveSil(SNode* head) {
    if (head == NULL)
        return;

    sllRecursiveSil(head->next);
    free(head);
}

void cllYazdir(SNode* head) {
    if (head == NULL)
        return;

    SNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    DNode* dhead = NULL;
    dllSonaEkle(&dhead, 10);
    dllSonaEkle(&dhead, 30);
    dllArayaEkle(dhead, 10, 20);
    dllYazdir(dhead);

    SNode* shead = NULL;
    sllSonaEkle(&shead, 1);
    sllSonaEkle(&shead, 2);
    sllSonaEkle(&shead, 3);
    sllRecursiveSil(shead);
    shead = NULL;

    SNode* c1 = malloc(sizeof(SNode));
    SNode* c2 = malloc(sizeof(SNode));
    SNode* c3 = malloc(sizeof(SNode));

    c1->data = 5;
    c2->data = 10;
    c3->data = 15;

    c1->next = c2;
    c2->next = c3;
    c3->next = c1;

    cllYazdir(c1);

    return 0;
}
