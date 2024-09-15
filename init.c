#include <stdio.h> //Initialisation des headers
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "init.h" //Include du fichier init.h


eolienne parc[NOMBRE_EOLIENNES];
float V[3][3];
int temps[TEMPS_SIM];


void initMatrice() {
    //Initialisation de la matrice du vent à partir du fichier "matrice_transition_vent.txt"
    FILE *fichier;
    fichier = fopen("matrice_transition_vent.txt","r");

    for (int i=0; i<TAILLE_MATRICE_TRANSITION; i++) {
        for (int j=0; j<TAILLE_MATRICE_TRANSITION; j++) {
            fscanf(fichier, "%f", &V[i][j]);
        }
    }

    fclose(fichier);
}

void initTemps() { //Création de la liste des jours de simulation
    for (int i=1; i<=TEMPS_SIM; i++) {
        temps[i-1] = i;
    }
}

void initEolienne() {
    // Fonction pour initialiser les informations intrinsèques de chaque éolienne
    for (int numEolienne = 0; numEolienne < NOMBRE_EOLIENNES; numEolienne++) {
        parc[numEolienne].coutEolienne = 0;
        parc[numEolienne].nbIntervention = 0;
        parc[numEolienne].joursIntervention = 0;
        parc[numEolienne].fontionne = true; //Toutes les éoliennes sont à l'état neuf au début
    }
}

void affichageJournalier(float puissance, int vitesseVent, int cout, int nbIntervention, int jour, int nbEoliennesFonctionnement) {
    // Fonction pour afficher les statistiques journalières
    printf("Jour numero %d : ",jour);
    printf("Vitesse du vent : %d", vitesseVent);
    printf("\n");
    printf("Puissance journaliere : %.2f MW\n", puissance);
    printf("Cout journalier : %d euros\n", cout);
    printf("Nombres d'interventions journalieres : %d\n", nbIntervention);
    printf("Nombre eoliennes fonctionnement : %d", nbEoliennesFonctionnement);
    printf("\n");
    printf("\n");
}

void affichageFinal(float puissance, int cout, int nbIntervention, float prodMax, float prodMin) {
    // Fonction pour afficher les statistiques finales de la simulation
    float cout_M = cout/1000000;
    printf("-------------------------------------");
    printf("\n");
    printf("Puissance totale : %.2f MW\n", puissance);
    printf("Cout total : %.2f millions d'euros\n", cout_M);
    printf("Nombres d'interventions total : %d\n", nbIntervention);
    printf("Production max : %.2f MW\n", prodMax);
    printf("Production min : %.2f MW\n", prodMin);
    printf("Production moyenne : %.2f MW\n", puissance/TEMPS_SIM);
}

void affichageStatutEolienne (eolienne listeEolienne_) {
    // Fonction pour afficher le statut des éoliennes
    for (int numEolienne = 0; numEolienne < NOMBRE_EOLIENNES; numEolienne++) {
        printf("Statut de l'eolienne numero %d : ", numEolienne);
    }
}
