#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* model;
    float pret;
} Telefon;

Telefon creareTelefon(const char* model, float pret) {
    Telefon t;
    t.model = (char*)malloc(strlen(model) + 1);
    strcpy(t.model, model);
    t.pret = pret;
    return t;
}

void afisareTelefon(Telefon t) {
    printf("Model: %s | Pret: %.2f RON\n", t.model, t.pret);
}

void eliberareTelefon(Telefon* t) {
    free(t->model);
    t->model = NULL;
}

void swap(Telefon* a, Telefon* b) {
    Telefon temp = *a;
    *a = *b;
    *b = temp;
}

void filtrareHeap(Telefon* heap, int n, int index) {
    int max = index;
    int st = 2 * index + 1;
    int dr = 2 * index + 2;

    if (st < n && heap[st].pret > heap[max].pret)
        max = st;
    if (dr < n && heap[dr].pret > heap[max].pret)
        max = dr;

    if (max != index) {
        swap(&heap[index], &heap[max]);
        filtrareHeap(heap, n, max);
    }
}

void inserareHeap(Telefon* heap, int* dim, Telefon t) {
    heap[*dim] = t;
    int i = *dim;
    (*dim)++;

    while (i > 0 && heap[(i - 1) / 2].pret < heap[i].pret) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Telefon extragereMax(Telefon* heap, int* dim) {
    Telefon max = heap[0];
    heap[0] = heap[*dim - 1];
    (*dim)--;
    filtrareHeap(heap, *dim, 0);
    return max;
}

void afisareHeap(Telefon* heap, int dim) {
    for (int i = 0; i < dim; i++) {
        afisareTelefon(heap[i]);
    }
}

int main() {
    Telefon heap[20];
    int dim = 0;

    inserareHeap(heap, &dim, creareTelefon("iPhone 15", 6399.99f));
    inserareHeap(heap, &dim, creareTelefon("Samsung S23", 4299.99f));
    inserareHeap(heap, &dim, creareTelefon("Motorola Edge", 1899.50f));
    inserareHeap(heap, &dim, creareTelefon("Xiaomi 13", 3599.00f));

    printf("=== Heap după inserări ===\n");
    afisareHeap(heap, dim);

    printf("\nExtragere maxim:\n");
    Telefon max = extragereMax(heap, &dim);
    afisareTelefon(max);
    eliberareTelefon(&max);

    printf("\nHeap după extragere:\n");
    afisareHeap(heap, dim);

    for (int i = 0; i < dim; i++) {
        eliberareTelefon(&heap[i]);
    }

    return 0;
}
