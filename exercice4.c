#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Client Client;
struct Client {
    char nom[30];
    char prenom[30];
    int num_compte;
    float solde;
    Client *suivant;
};

typedef struct File File;
struct File {
    Client *sommet;
    Client *queue;
};

File* initialisationFile() {
    File *f = malloc(sizeof(*f));
    f->sommet = NULL;
    f->queue = NULL;
    return f;
}

// Ajouter un client
void ajouterClient(File *f, int num, char *nom, char *prenom, float solde) {
    Client *c = malloc(sizeof(*c));
    c->num_compte = num;
    strcpy(c->nom, nom);
    strcpy(c->prenom, prenom);
    c->solde = solde;
    c->suivant = NULL;

    if (f->sommet == NULL)
        f->sommet = f->queue = c;
    else {
        f->queue->suivant = c;
        f->queue = c;
    }
}

// Servir un client
Client* servir(File *f) {
    if (f->sommet == NULL) return NULL;
    Client *tmp = f->sommet;
    f->sommet = tmp->suivant;
    if (f->sommet == NULL) f->queue = NULL;
    return tmp;
}

// Afficher touts les clients en attente
void afficherClients(File *f) {
    Client *c = f->sommet;
    printf("\nClients en attente :\n");
    while (c != NULL) {
        printf("%d - %s %s (solde %.2f)\n",
               c->num_compte, c->nom, c->prenom, c->solde);
        c = c->suivant;
    }
}

int main() {
    File *f = initialisationFile();

    ajouterClient(f, 1, "Diop", "Abibou", 150000);
    ajouterClient(f, 2, "Sy", "Elhadj", 250000);

    afficherClients(f);

    Client *c = servir(f);
    printf("\nClient servi : %s %s\n", c->prenom, c->nom);

    afficherClients(f);

    return 0;
}
