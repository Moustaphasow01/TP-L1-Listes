#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main() {
    int choix;

    do {
        printf("=== MENU ===\n");
        printf("1. Exercice 1: Trouver le plus grand nombre dans un tableau\n");
        printf("2. Exercice 2: Creer et afficher une LSC\n");
        printf("3. Exercice 3: Trouver la position d'un element dans une LSC\n");
        printf("4. Exercice 4: Retourner la longueur d'une LSC\n");
        printf("5. Exercice 5: Verifier si une LSC est croissante\n");
        printf("6. Exercice 6: Creer et afficher une LDC\n");
        printf("7. Exercice 7: Ajouter un element a une LSC\n");
        printf("8. Exercice 8: Supprimer un element d'une LSC\n");
        printf("9. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                int n, max;
                printf("Combien de termes composent votre tableau de nombres ? ");
                scanf("%d", &n);
                int tableau[n];
                for (int i = 0; i < n; i++) {
                    printf("Merci d’indiquer le terme n°%d : ", i + 1);
                    scanf("%d", &tableau[i]);
                }
                max = tableau[0];
                for (int i = 1; i < n; i++) {
                    if (tableau[i] > max) {
                        max = tableau[i];
                    }
                }
                printf("Le plus grand nombre dans le tableau est : %d\n", max);
                break;
            }
            case 2: {
                Node *head = creerListe();
                afficherListe(head);
                break;
            }
            case 3: {
                Node *head = creerListe();
                afficherListe(head);
                int valeur;
                printf("Veuillez indiquer le nombre a trouver dans la liste : ");
                scanf("%d", &valeur);
                int index = trouverElement(head, valeur);
                if (index != -1) {
                    printf("=> Le terme qui est recherche se trouve en place %d [index %d]\n", index + 1, index);
                } else {
                    printf("Le terme n'a pas été trouvé dans la liste.\n");
                }
                break;
            }
            case 4: {
                Node *head = creerListe();
                afficherListe(head);
                int longueur = longueurListe(head);
                printf("La liste est composee de %d termes\n", longueur);
                break;
            }
            case 5: {
                Node *head = creerListe();
                afficherListe(head);
                if (estCroissante(head)) {
                    printf("La liste est croissante\n");
                } else {
                    printf("La liste n'est PAS croissante\n");
                }
                break;
            }
            case 6: {
                DNode *head = creerListeDouble();
                afficherListeDouble(head);
                break;
            }
            case 7: {
                Node *head = creerListe();
                afficherListe(head);
                int valeur, index;
                printf("Quelle valeur souhaitez-vous ajouter a la liste ? ");
                scanf("%d", &valeur);
                printf("Ajouter la valeur %d a quel index ? ", valeur);
                scanf("%d", &index);
                head = ajouterAIndex(head, index, valeur);
                afficherListe(head);
                break;
            }
            case 8: {
                Node *head = creerListe();
                afficherListe(head);
                int index;
                printf("Le terme de quel index souhaitez-vous supprimer ? ");
                scanf("%d", &index);
                head = supprimerAIndex(head, index);
                afficherListe(head);
                break;
            }
            case 9:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez essayer a nouveau.\n");
        }
    } while (choix != 9);

    return 0;
}
