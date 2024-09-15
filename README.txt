SIMULATION D'UN PARC EOLIEN
======================


Description du projet
----------------------
On se propose d'étudier ici la production d'un parc éolien à travers une simulation en prenant en compte différents facteurs
qui peuvent influencer la production : taille du parc, vitesse du vent, robustesse des éoliennes...


Fonctionnalités
---------------------------
-Affichage journaliers des données (Vent, Puissance, Interventions, Coût, Eoliennes qui fonctionnent)
-Récapitulatif de la production (avec la production minimale, maximale et moyenne), des coûts, pannes à la fin de la simulation (ici une année)
-Changement aisé des constantes de simulation (dans init.h)



Choix Algorithmiques
--------------------
Structures de Fichiers
~~~~~~~~~~~~~~~~~~~~~
Le dossier de la simulation contient deux fichiers :
    -main.c qui contient le main() du programme
        -init.h qui est appelé par main.c
        -init.c appele init.h
            -matrice_transition_vent.txt : qui contient la matrice de probabilité de transition, jour après jour, de la vitesse du vent qui va influencer la production journalière
    -Makefile : fichier Makefile de compilation des fichiers sources du programme

Structures de Données
~~~~~~~~~~~~~~~~~~~~
Afin de condenser toutes les informations intrinsèques à chaque éolienne, une structure eolienne est écrée contenant : 
    -un booléen qui vaut true si l'eolienne fonctionne, 0 sinon  (fontionne)
    -un entier représentant le coût total de l'éolienne au fur et à mesure de l'année (coutEolienne)
    -un entier représentant le nombre d'interventions total à la fin de la simulation (nbIntervention)
    -un entier qui permet de savoir quand une intervention sur l'eolienne considérée est terminée (joursIntervention)

Découpage en Modules
~~~~~~~~~~~~~~~~~~~~
Les deux modules du programme :
    -main.c : qui contient la fonction main() qui execute les fonctions du programme pour la simulation
    -init.c (ini.h) : qui contient la définition des variables tels que la vitesse du vent, le cout d'intervention, les vecteurs de production...
    

Bibliothèques
~~~~~~~~~~~~~~
    <stdio.h> : Gestion des inputs / outputs
    <stdlib.h> : Bilbiotheque standard
    <stdbool.h> : Implementation des booléens
    <time.h> : Gestion du temps (pour la generation de la graine d'aléatoire)


Compiler/Exécuter (Linux / Windows)
-----------------------------------
Linux :

Le script Shell crée permet d'afficher les résultats, puis de les stocker dans un fichier.
Ouvrir un terminal dans le dossier source du projet et executer : ./Shell

Ceci va alors exécuter le code Shell, qui va à son tour:
- compiler grâce a make
- exécuter la simulation
- afficher les résultats
- stocker ces résultats dans un fichier Resultats

Windows :

Ouvrir l'invite de commande
Puis d'aller dans le dossier source du projet
Ensuite executer : Simulation_windows
(Attention : sur windows le programme n'enregistre pas les résultats, pour cela aller sur Linux)



Difficultés rencontrées
------------------------
Nous avons eu un souci pour l'execution du programme. En effet, dans un premier temps le travail à été fait sur Windows, avec un .exe à lancer.
Nous nous somme rendus compte que le gcc ne fonctionnait pas sur Linux (pas sur Kali en tout cas). 
Le souci était du à un oubli de notre part de redefinir les variables externes dans le init.h en indiquant bien extern.


----------------------------------------------------------------------------------------------
RESULTATS:

Voir le fichier Resultats