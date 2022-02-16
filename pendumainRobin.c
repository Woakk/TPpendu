#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int initialisation(char s_mot[100], int n_mot[100]); // On déclare la fonction initialisation
void affiche_pendu(int n_vie); // On déclare la procédure affiche_pendu
void fin_jeu(int n_vie, int n_win, char s_mot[100]); // On déclare la procédure fin_jeu
int trouve_lettres(int n_nbltr, int n_vie, char s_mot[100], int n_mot[100]); //On déclare la fonction trouve_lettres
int affiche_lettres(int n_nbltr, int n_mot[100], char s_mot[100], int n_nbaffiche); //On déclare la fonction affiche_lettres

int main() {
// Variables
    int n_nbltr = 0; // Variable du nombre de lettres dans le mot
    int n_vie = 10; // Variable du nombre de vies du joueur, initialisée à 10
    int n_mot[100]; // Nombre max de lettres du mot
    int n_win = 0; // Variable définissant la condition de victoire
    char s_mot[100]; // Chaine de caractères entrée par l'utilisateur, notre mot à deviner;


// Initialisation et Instructions
    n_nbltr = initialisation(s_mot, n_mot); // On appelle la fonction initialisation

// Jeu
    while ((n_vie > 0 && n_win != 1)) { // Boucle while du jeu, interrompue si l'une des deux conditions est fausse

        affiche_pendu(n_vie); // On appelle la procédure affiche_pendu



// Affichage des lettres

        int n_nbaffiche = affiche_lettres(n_nbltr, n_mot, s_mot, n_nbaffiche); // On initialise une variable qui va se voir affecter le nombre de lettres trouvées, et on appelle la fonction affiche_lettres

        if(n_nbaffiche==n_nbltr) { // Condition de victoire, si notre nombre de caractères affichés (et donc trouvés) est égal au nombre de caractères dans le mot
            n_win=1; // On sort de notre while, condition définie ligne 29
            break;
        }

// Trouver les lettres

        n_vie = trouve_lettres(n_nbltr, n_vie, s_mot, n_mot); //On affecte à la valeur n_vie le résultat de la fonction trouve_lettres qu'on appelle

    }
    system("cls"); // On efface l'écran pour afficher un message de victoire ou de défaite par la suite

// Conditions de Défaite ou de Victoire

    fin_jeu(n_vie, n_win, s_mot); // On appelle la procédure fin_jeu

return 0;
// FIN
}

int initialisation(char s_mot[100], int n_mot[100]) { // On définit la fonction initialisation qui va nous permettre de mettre en place le jeu
    printf("Veuillez entrer le mot a deviner, en majuscules\n"); // On demande à l'utilisateur le mot à faire deviner, à entrer en majuscules
    scanf(" %s", s_mot); // On lit la réponse de l'utilisateur à l'instruction précédente et on stocke sa réponse dans une chaine de caractères
    // DEBUT
    for (int i = 0; i <= 100; i++) {
        n_mot[i] = 0;
    } // Initialisation du tableau du mot, on met toutes les valeurs à 0 pour "faux"
    system("cls"); // On efface l'écran pour que la personne devant deviner ne puisse pas voir la réponse
    return strlen(s_mot); // On affecte une valeur à la variable de la longueur de notre mot à l'aide d'une commande qui va compter le nombre de caractères
}

void affiche_pendu(int n_vie) { // On définit la procédure affiche_pendu qui affichera petit à petit le pendu pendant la boucle de jeu
    system("cls"); // On efface l'écran à chaque nouvelle répétition de la boucle


    switch (n_vie) {

        case 10 : // Le joueur a 10 vies
            printf("\n");
            break;
        case 9 : // Le joueur a 9 vies
            printf("_|__\n"); // Le joueur perd une vie, on construit la potence
            break;
        case 8 : // Le joueur a 8 vies
            printf(" " "|\n"); // Le joueur perd une vie, on construit la potence
            printf("_|__\n");
            break;
        case 7 : // Le joueur a 7 vies
            printf(" " "|\n"); // Le joueur perd une vie, on construit la potence
            printf(" " "|\n");
            printf("_|__\n");
            break;
        case 6 : // Le joueur a 6 vies
            printf(" " "|\n"); // Le joueur perd une vie, on construit la potence
            printf(" " "|\n");
            printf(" " "|\n");
            printf("_|__\n");
            break;
        case 5 : // Le joueur a 5 vies
            printf(" " "|\n"); // Le joueur perd une vie, on construit la potence
            printf(" " "|\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf("_|__\n");
            break;
        case 4 : // Le joueur a 4 vies
            printf("____________\n"); // Le joueur perd une vie, on construit la potence
            printf(" " "|\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf("_|__\n");
            break;
        case 3 : // Le joueur a 3 vies
            printf("____________\n"); // Le joueur perd une vie, on construit la potence
            printf(" " "|" " " " " " " " " " " " " " " "|\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf("_|__\n");
            break;
        case 2 : // Le joueur a 2 vies
            printf("____________\n"); // Le joueur perd une vie, on construit la potence
            printf(" " "|" " " " " " " " " " " " " " " "|\n");
            printf(" " "|" " " " " " " " " " " " " " " "O\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf("_|__\n");
            break;
        case 1 : // Le joueur a 1 vie
            printf("____________\n"); // Le joueur perd une vie, on construit la potence
            printf(" " "|" " " " " " " " " " " " " " " "|\n");
            printf(" " "|" " " " " " " " " " " " " " " "O\n");
            printf(" " "|" " " " " " " " " " "" " "/" "|" "\\\n");
            printf(" " "|\n");
            printf(" " "|\n");
            printf("_|__\n");
            break;
    }

    printf("\n");

}

void fin_jeu(int n_vie, int n_win, char s_mot[100]) { // On définit la procédure fin_jeu qui définit l'écran de victoire ou de défaite
        if(n_vie==0){ // Si le joueur n'a plus de vies, donc si la condition ligne 29 n'est plus vraie, on affiche la suite, à savoir la potence complète, accompagnée d'un message de Game Over
            printf("_" "_" "_" "_" "_" "_" "_" "_" "_" "_" "_" "_\n");
            printf(" " "|" " " " " " " " " " " " " " " "|\n");
            printf(" " "|" " " " " " " " " " " " " " " "O\n");
            printf(" " "|" " " " " " " " " " "" " "/" "|" "\\\n");
            printf(" " "|" " " " " " " " " " " " " "/" " " "\\\n");
            printf(" " "|\n");
            printf("_|__\n");
            printf("\n Vous avez perdu. Le mot a deviner etait: %s", s_mot); // Le message de Game Over, on affiche également le mot à deviner

        } else if (n_win == 1) { // Sinon, ici on contredit l'autre condition de la ligne 29 en ayant la variable qui vaut 1...
            printf("Le mot etait bien: %s\n\nFelicitations, vous avez gagne !", s_mot); // ...et on affiche le mot ainsi qu'un message de félicitations
        }

        system("pause>nul");
}

int trouve_lettres(int n_nbltr, int n_vie, char s_mot[100], int n_mot[100]) { // On définit la fonction trouve_lettres qui va permettre de tester si l'entrée du joueur est bonne ou pas
    char c_ltrchoix; // Caractère simple, lettre que l'utilisateur va entrer pour deviner le mot
    printf("Veuillez entrer une lettre majuscule:\n"); // On demande au joueur d'entrer une lettre
    scanf(" %c", &c_ltrchoix); // On affecte cette lettre à une variable

    int n_trouve = 0; // On initialise une variable qui permettra de dire si notre lettre est la bonne ou non

    for (int i = 0; i < n_nbltr; i++) {
        if(c_ltrchoix == s_mot[i]) { // On teste si notre lettre entrée est présente dans la chaine de caractères
            n_mot[i] = 1; // Si oui, on affecte 1 à la position de la lettre...
            n_trouve = 1; // ...et on affecte également 1 à la variable initialisée précédemment, pour dire que la lettre est la bonne
        }
    }

    if(n_trouve == 0){ // Si l'affectation n'est pas égale à 1, c'est donc faux
        n_vie=n_vie - 1; // Alors on enlève une vie au joueur
    }
    return n_vie;
}

int affiche_lettres(int n_nbltr, int n_mot[100], char s_mot[100], int n_nbaffiche) { // On définit la fonction affiche_lettres qui va afficher ou non la lettre en fonction de si le joueur trouve ou non
    int n_tmp = 0;
    for (int i = 0; i < n_nbltr; i++) {
        if (n_mot[i]==1){ // Ici le 1 définit le "vrai" dans notre jeu. 1: On a trouvé le caractère, 0: On n'a pas trouvé le caractère. On a initialisé ça à la ligne 18
            printf("%c ", s_mot[i]); // On affiche la lettre trouvée à sa place
            n_tmp++; // On incrémente pour chaque lettre trouvée cette variable
        } else {
            printf("_ "); // Autrement, si on n'a pas trouvé, on garde un vide, symbolisé par un tiret
        }
    }
    printf("\n\n");
    return n_tmp;
}
