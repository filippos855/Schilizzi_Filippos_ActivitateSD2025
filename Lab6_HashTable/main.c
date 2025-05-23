#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 26  // litere A-Z

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

// Funcție hash: în funcție de prima literă (A-Z)
int functieHash(const char* model) {
    return (toupper(model[0]) - 'A') % DIM;
}

void inserareHash(Nod** tabela, Telefon t) {
    int poz = functieHash(t.model);
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->info = creareTelefon(t.model, t.pret);
    nou->next = tabela[poz];
    tabela[poz] = nou;
}

void afisareTabela(Nod** tabela) {
    for (int i = 0; i < DIM; i++) {
        if (tabela[i]) {
            printf("\nClasa %c:\n", 'A' + i);
            Nod* p = tabela[i];
            while (p) {
                afisareTelefon(p->info);
                p = p->next;
            }
        }
    }
}

void eliberareTabela(Nod** tabela) {
    for (int i = 0; i < DIM; i++) {
        Nod* p = tabela[i];
        while (p) {
            Nod* temp = p;
            p = p->next;
            eliberareTelefon(&temp->info);
            free(temp);
        }
        tabela[i] = NULL;
    }
}

int main() {
    Nod* tabela[DIM] = { 0 };

    inserareHash(tabela, creareTelefon("Apple iPhone", 6299.50f));
    inserareHash(tabela, creareTelefon("Samsung S23", 4399.99f));
    inserareHash(tabela, creareTelefon("Realme 11", 1899.00f));
    inserareHash(tabela, creareTelefon("Asus Zenfone", 3599.00f));
    inserareHash(tabela, creareTelefon("Xiaomi 13", 2699.49f));

    printf("=== Tabela de dispersie ===\n");
    afisareTabela(tabela);

    eliberareTabela(tabela);
    return 0;
}
