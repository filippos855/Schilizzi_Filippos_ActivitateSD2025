#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* model;
    float pret;
} Telefon;

typedef struct Nod {
    Telefon info;
    struct Nod* next;
} Nod;

// Funcții pentru Telefon
Telefon creareTelefon(const char* model, float pret) {
    Telefon t;
    t.model = (char*)malloc(strlen(model) + 1);
    if (t.model) strcpy(t.model, model);
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

// Inserare la începutul listei
Nod* inserareInceput(Nod* cap, Telefon t) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->info = creareTelefon(t.model, t.pret); // copiem datele
    nou->next = cap;
    return nou;
}

void afisareLista(Nod* cap) {
    Nod* p = cap;
    while (p) {
        afisareTelefon(p->info);
        p = p->next;
    }
}

void eliberareLista(Nod** cap) {
    while (*cap) {
        Nod* temp = *cap;
        *cap = (*cap)->next;
        eliberareTelefon(&temp->info);
        free(temp);
    }
}

int main() {
    Nod* lista = NULL;

    lista = inserareInceput(lista, creareTelefon("Samsung S22", 3999.99f));
    lista = inserareInceput(lista, creareTelefon("iPhone 13", 5099.50f));
    lista = inserareInceput(lista, creareTelefon("Huawei P50", 2899.00f));

    printf("=== Lista simplu înlănțuită ===\n");
    afisareLista(lista);

    eliberareLista(&lista);
    return 0;
}
