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
    if (t.model != NULL) {
        strcpy(t.model, model);
    }
    t.pret = pret;
    return t;
}

void afisareTelefon(Telefon t) {
    printf("Model: %s | Pret: %.2f RON\n", t.model, t.pret);
}

void eliberareMemorie(Telefon* t) {
    free(t->model);
    t->model = NULL;
}

int main() {
    Telefon t1 = creareTelefon("Samsung Galaxy S23", 4399.99f);
    afisareTelefon(t1);
    eliberareMemorie(&t1);
    return 0;
}
