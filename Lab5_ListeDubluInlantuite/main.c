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
    struct Nod* prev;
    struct Nod* next;
} Nod;

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

// Inserare la final
void inserareFinal(Nod** cap, Nod** coada, Telefon t) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->info = creareTelefon(t.model, t.pret);
    nou->next = NULL;
    nou->prev = *coada;

    if (*coada)
        (*coada)->next = nou;
    else
        *cap = nou;  // listă goală inițial

    *coada = nou;
}

void afisareLista(Nod* cap) {
    Nod* p = cap;
    while (p) {
        afisareTelefon(p->info);
        p = p->next;
    }
}

void eliberareLista(Nod** cap) {
    Nod* p = *cap;
    while (p) {
        Nod* temp = p;
        p = p->next;
        eliberareTelefon(&temp->info);
        free(temp);
    }
    *cap = NULL;
}

int main() {
    Nod* cap = NULL;
    Nod* coada = NULL;

    inserareFinal(&cap, &coada, creareTelefon("Sony Xperia 5", 2999.99f));
    inserareFinal(&cap, &coada, creareTelefon("Nokia XR21", 2299.50f));
    inserareFinal(&cap, &coada, creareTelefon("Realme GT", 1899.00f));

    printf("=== Listă dublu înlănțuită ===\n");
    afisareLista(cap);

    eliberareLista(&cap);
    return 0;
}
