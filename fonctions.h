#ifndef FONCTIONS_H
#define FONCTIONS_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// Fonctions pour les listes simplement chaînées
Node* creerListe();
void afficherListe(Node *head);
int trouverMax(Node *head);
int longueurListe(Node *head);
int trouverElement(Node *head, int valeur);
int estCroissante(Node *head);
Node* ajouterAIndex(Node *head, int index, int valeur);
Node* supprimerAIndex(Node *head, int index);

// Fonctions pour les listes doublement chaînées
DNode* creerListeDouble();
void afficherListeDouble(DNode *head);
DNode* ajouterAIndexDouble(DNode *head, int index, int valeur);
DNode* supprimerAIndexDouble(DNode *head, int index);

#endif // FONCTIONS_H
