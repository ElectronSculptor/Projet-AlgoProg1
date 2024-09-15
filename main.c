#include <stdio.h> //Initialisation des headers
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "init.h" //Include du fichier init.h


// Fonctions utilisées dans le main
int ventAlea(int ventAvant, float V[TAILLE_MATRICE_TRANSITION][TAILLE_MATRICE_TRANSITION]); // Prototypage des fonctions
bool probabilitePanne();
float MoyEoliennesFonctionnement(int tab[], int taille);
float trouverMaximum(float liste[], int taille);
float trouverMinimum(float liste[], int taille);





int main(void) {
    

    initTemps(); //initialisations des fonctions pour le programme
    initMatrice();
    initEolienne();
    srand(time(NULL)); //Initie la graine de génération d'aléatoire par rapport au temps

    float puissanceTotale = 0; //initialisations des variables pour le main()
    float puissanceJournaliere = 0.0;
    int vitesseVent = 0;
    int vitesseVentPrec = 0;
    int coutTotal = 0;
    int nbInterventionTotales = 0;
    vitesseVent = 0; //Intialisation de la vitesse du vent à vitesse faible pour le premier jour    
    float prod[3] = {PROD_V_NULLE, PROD_V_MOYENNE, PROD_V_MAX};

    float TABeoliennesFonctionnement[TEMPS_SIM];

    for (int jour=1; jour<=TEMPS_SIM; jour++) { //première boucle permettant de parcourir jour par jour
        int nbEoliennesFonctionnement = 0;
        int nbInterventionJournalieres = 0;
        int coutJournalier = 0;
        vitesseVent = ventAlea(vitesseVentPrec, V);

        for (int numEolienne=0; numEolienne < NOMBRE_EOLIENNES; numEolienne++) { 
            //Deuxième boucle qui, pour un jour donné, parcourt chaque éolienne du parc et simule alors son fonctionnement
            
            if (vitesseVent == 2) { //On distingue d'abord si le vent est fort, alors si l'éolienne n'est pas déjà en panne, on simule qu'elle peut tomber en panne
                if (probabilitePanne() == true && parc[numEolienne].fontionne == true) {
                    parc[numEolienne].fontionne = false;
                    nbInterventionJournalieres++;
                    coutJournalier += COUT_INTERVENTION;
                }
            }
            if (parc[numEolienne].joursIntervention == 3) {  //On distingue 3 cas permettant de gérer les éoliennes qui sont en maintenance
                parc[numEolienne].fontionne = true;
                parc[numEolienne].joursIntervention = 0;
            }
            if (parc[numEolienne].fontionne == false && vitesseVent != 2) {
                parc[numEolienne].joursIntervention++;
            }
            if (parc[numEolienne].fontionne == true) {
                nbEoliennesFonctionnement++;
            }
        }
        
        nbInterventionTotales += nbInterventionJournalieres; //On incrémente de façon journalière chaque variable de la simulation
        coutTotal += coutJournalier;
        puissanceJournaliere = nbEoliennesFonctionnement*prod[vitesseVent];
        TABeoliennesFonctionnement[jour] = puissanceJournaliere;
        puissanceTotale = puissanceTotale + puissanceJournaliere;

        if (AFFICHAGE_JOURNALIER) {
            affichageJournalier(puissanceJournaliere, vitesseVent, coutJournalier, nbInterventionJournalieres, jour, nbEoliennesFonctionnement);
            //On affiche journalièrement les informations qui nous intéresse si on a mit AFFICHAGE_JOURNALIER à true
        }
        
        vitesseVentPrec = vitesseVent;
    }
    affichageFinal(puissanceTotale, coutTotal, nbInterventionTotales, trouverMaximum(TABeoliennesFonctionnement, TEMPS_SIM), trouverMinimum(TABeoliennesFonctionnement, TEMPS_SIM));
    //Une fois la simulation terminée, on affiche les informations finales relatives au fonctionnement du parc
    return EXIT_SUCCESS;
}









/////////////////////////////////////////////////////////////////////////////////////////////////////
//Déclarations des fonctions internes au main.c

int ventAlea(int ventAvant, float V[TAILLE_MATRICE_TRANSITION][TAILLE_MATRICE_TRANSITION]) {
//fonction permettant de simuler le vent sur le parc éolien. Elle prend en paramètre la vitesse du vent du jour
//précédent, ainsi que la matrice de transition du vent. Elle renvoie alors la vitesse du vent : 0 vitesse de vent nulle,
//1 vent moyen et 2 vent fort.

    double rd = (double)rand() / RAND_MAX;
    if (rd < V[ventAvant][0]) {
            return 0;
        }
    else if (rd < V[ventAvant][0] + V[ventAvant][1])
    {
        return 1;
    }
    else {
        return 2;
    }
}

bool probabilitePanne() {
//fonction qui générère les pannes pouvant survenir sur les éoliennes, elle retourne true si l'éolienne tombe
//en panne, false sinon

    double rd = (double)rand() / RAND_MAX;
    if (rd < P_PANNE) {
        return true;
    }
    else {
        return false;
    }
}

float trouverMaximum(float liste[], int taille) {
//fonction permettant de trouver le maximum de puissance produite pendant le temps de simulation


    float maximum = liste[0];

    for (int i = 1; i < taille; i++) {
        if (liste[i] > maximum) {
            maximum = liste[i];
        }
    }

    return maximum;
}

float trouverMinimum(float liste[], int taille) {
//fonction permettant de trouver le minimum de puissance produite pendant le temps de simulation

    float minimum = liste[0];

    for (int i = 1; i < taille; i++) {
        if (liste[i] < minimum) {
            minimum = liste[i];
        }
    }

    return minimum;
}

