#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

// Fonctions pour les listes simplement chaînées
Node* creerListe() {
    Node *head = NULL;
    Node *temp = NULL;
    Node *newNode = NULL;
    int valeur, i = 1;

    printf("=== Creation d'une LSC (-1 pour terminer la saisie) ===\n");
    while (1) {
        printf("Merci d'indiquer le terme n°%d : ", i++);
        scanf("%d", &valeur);
        if (valeur == -1) break;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = valeur;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

void afficherListe(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int trouverMax(Node *head) {
    int max = head->data;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int longueurListe(Node *head) {
    int longueur = 0;
    Node *temp = head;
    while (temp != NULL) {
        longueur++;
        temp = temp->next;
    }
    return longueur;
}

int trouverElement(Node *head, int valeur) {
    int position = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == valeur) {
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1; // Si la valeur n'est pas trouvée
}

int estCroissante(Node *head) {
    if (head == NULL || head->next == NULL) {
        return 1; // Une liste vide ou avec un seul élément est croissante
    }
    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->data >= temp->next->data) {
            return 0; // Si un élément est supérieur ou égal au suivant, la liste n'est pas croissante
        }
        temp = temp->next;
    }
    return 1;
}

Node* ajouterAIndex(Node *head, int index, int valeur) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = valeur;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }

    Node *temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* supprimerAIndex(Node *head, int index) {
    if (head == NULL) {
        return NULL;
    }

    Node *temp = head;
    if (index == 0) {
        head = head->next;
        free(temp);
        return head;
    }

    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return head;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Fonctions pour les listes doublement chaînées
DNode* creerListeDouble() {
    DNode *head = NULL;
    DNode *tail = NULL;
    DNode *newNode = NULL;
    int valeur, i = 0;

    printf("=== Creation d'une LDC (-1 pour terminer la saisie) ===\n");
    while (1) {
        printf("Merci d'indiquer le terme d’index [%d] : ", i++);
        scanf("%d", &valeur);
        if (valeur == -1) break;

        newNode = (DNode*)malloc(sizeof(DNode));
        newNode->data = valeur;
        newNode->next = NULL;
        newNode->prev = tail;

        if (tail != NULL) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }
    return head;
}

void afficherListeDouble(DNode *head) {
    DNode *temp = head;
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

DNode* ajouterAIndexDouble(DNode *head, int index, int valeur) {
    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = valeur;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (index == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    DNode *temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
}

DNode* supprimerAIndexDouble(DNode *head, int index) {
    if (head == NULL) {
        return NULL;
    }

    DNode *temp = head;
    if (index == 0) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    for (int i = 0; i < index && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}
