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

void eliberareMemorieTelefon(Telefon* t) {
    free(t->model);
    t->model = NULL;
}

void afisareVector(Telefon* vector, int dim) {
    for (int i = 0; i < dim; i++) {
        afisareTelefon(vector[i]);
    }
}

void eliberareVector(Telefon* vector, int dim) {
    for (int i = 0; i < dim; i++) {
        eliberareMemorieTelefon(&vector[i]);
    }
}

int main() {
    Telefon vector[3];
    vector[0] = creareTelefon("Samsung S23", 4399.99f);
    vector[1] = creareTelefon("iPhone 15", 6299.50f);
    vector[2] = creareTelefon("Huawei P60", 3699.00f);

    printf("=== Vector de telefoane ===\n");
    afisareVector(vector, 3);

    eliberareVector(vector, 3);
    return 0;
}
