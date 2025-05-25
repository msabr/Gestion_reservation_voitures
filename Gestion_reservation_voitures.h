#ifndef GESTION_RESERVATION_VOITURES_H
#define GESTION_RESERVATION_VOITURES_H

#include <time.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
// #include <conio.h> // Uncomment the above line if using conio.h for getch() on Windows
// #include <windows.h> // Uncomment the above line if using Windows-specific functions on Windows


# define RED "\033[31m"
# define GREEN   "\033[32m"
# define RESET "\033[0m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define MAGENTA "\033[35m"

/*en declaré un type clients contient index, nom, prenom, adresse et numéro de téléphone */
typedef struct clients{
   int cl_index;
   int cl_numerotete;
   char cl_nom[20];
   char cl_prenom[20];
   char cl_adresse[100];
}clients;
FILE *cl;
//****************************************************************************


/*en declaré un type voiture  contient index, type, matricule, couleur,et prix*/
typedef struct voiture{
  char ve_type[20];
  char ve_matricule[20];
  char ve_couleur[20];
   int ve_index;
   int ve_prix;
   int ve_duree;    //pour les fonctions de Reservation;
   int ve_nbrjour;  //pour les fonctions de Reservation;
   int ve_reservant;//pour les fonctions de Reservation;
}voiture;
FILE *ve;
//****************************************************************************


//reservation de voiture fonction
void Reservation_voiture(clients *c,voiture *v,int bornec,int bornev);
void Rendre_voiture(clients *c,voiture *v,int bornec,int bornev);
void Voitures_reservees(voiture *v,int bornev);
void Reservant_voiture(clients *c,voiture *v,int bornec,int bornev);
void conversion_secondes(int n);
void dessiner_voiture();
void dessiner_clients();
char getch();

//client fonction
void ajouter_client(clients *c,int *pborne,int taille);
void modifier_client(clients *c,int borne);
void supprimer_client(clients *c,int *pborne);
void afficher_clients(clients *c,int borne);
void afficher_clients(clients *c,int borne);
void fichier_fprintf_clients(clients *c,int borne);
void fichier_fscanf_clients(clients *c,int *pborne);

//voiture fonction
void ajouter_voiture(voiture *v,int *pborne,int taille);
void modifier_voiture(voiture *v,int borne);
void supprimer_voiture(voiture *v,int *pborne);
void afficher_voitures(voiture *v,int borne);
void fichier_fprintf_voitures(voiture *v,int borne);
void fichier_fscanf_voitures(voiture *v,int *pborne);

#endif