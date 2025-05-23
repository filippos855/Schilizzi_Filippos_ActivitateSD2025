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
    FILE* f = fopen("telefoane.txt", "r");
    if (!f) {
        printf("Eroare la deschiderea fișierului.\n");
        return -1;
    }

    int n;
    fscanf(f, "%d", &n);

    Telefon* vector = (Telefon*)malloc(n * sizeof(Telefon));
    if (!vector) {
        fclose(f);
        return -2;
    }

    char buffer[100];
    for (int i = 0; i < n; i++) {
        float pret;
        fscanf(f, "%s %f", buffer, &pret);
        vector[i] = creareTelefon(buffer, pret);
    }

    fclose(f);

    printf("=== Telefoane citite din fișier ===\n");
    for (int i = 0; i < n; i++) {
        afisareTelefon(vector[i]);
    }

    for (int i = 0; i < n; i++) {
        eliberareMemorie(&vector[i]);
    }

    free(vector);
    return 0;
}
