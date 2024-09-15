#define TEMPS_SIM 365 //Durée de simulation en jour
#define NOMBRE_EOLIENNES 70 //Nombre d'éoliennes dans le parc éolien

#define P_PANNE 0.15 //Probabilité pour qu'une éolienne tombe en panne

//Production en MW en fonction de la vitesse du vent
#define PROD_V_NULLE 0 //Vitesse du vent nulle
#define PROD_V_MOYENNE 0.4 //Vitesse du vent moyenne
#define PROD_V_MAX 0.65 //Vitesse du vent maximale

//Conditions de maintenance
#define DUREE_MAINTENANCE_PANNE 3 //Durée en jours en cas de maintenance
#define COUT_INTERVENTION 150000 //Cout d'une intervention en euros

#define TAILLE_MATRICE_TRANSITION 3 //Taille de la matrice de transition de la force du vent

#define AFFICHAGE_JOURNALIER true //true pour afficher l'affichage journalier, false sinon


extern float V[3][3];
extern int temps[TEMPS_SIM];


typedef struct {
    bool fontionne;
    int coutEolienne;
    int nbIntervention;
    int joursIntervention;
}eolienne;

extern eolienne parc[NOMBRE_EOLIENNES];

void initMatrice();
void initTemps();
void initEolienne();
void affichageJournalier(float puissance, int vitesseVent, int cout, int nbIntervention, int jour, int nbEoliennesFonctionnement);
void affichageFinal(float puissance, int cout, int nbIntervention, float prodMax, float prodMin);
void affichageStatutEolienne (eolienne listeEolienne_);
void afficherListe(int *liste, int taille);
