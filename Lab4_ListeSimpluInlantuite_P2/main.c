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

// Inserare la sfârșit
Nod* inserareFinal(Nod* cap, Telefon t) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->info = creareTelefon(t.model, t.pret);
    nou->next = NULL;

    if (cap == NULL)
        return nou;

    Nod* p = cap;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = nou;
    return cap;
}

// Căutare telefon după model
Telefon* cautaTelefon(Nod* cap, const char* model) {
    Nod* p = cap;
    while (p != NULL) {
        if (strcmp(p->info.model, model) == 0) {
            return &p->info;
        }
        p = p->next;
    }
    return NULL;
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

    lista = inserareFinal(lista, creareTelefon("Motorola G100", 1999.99f));
    lista = inserareFinal(lista, creareTelefon("OnePlus 11", 3099.00f));
    lista = inserareFinal(lista, creareTelefon("Xiaomi 13", 2699.49f));

    printf("=== Lista simplu înlănțuită ===\n");
    afisareLista(lista);

    // căutare
    char modelCautat[] = "OnePlus 11";
    Telefon* rezultat = cautaTelefon(lista, modelCautat);
    if (rezultat)
        printf("\nTelefon găsit: %s, %.2f RON\n", rezultat->model, rezultat->pret);
    else
        printf("\nTelefonul %s nu a fost găsit.\n", modelCautat);

    eliberareLista(&lista);
    return 0;
}
