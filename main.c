#include "Gestion_reservation_voitures.h"
//♦Ce projet a ete cree et presente par: {☺♥ MOHAMED SABR ♥☺}

/*Rapport:------------------------------------------------------------------------------------*
                                                                                              |
  Ce projet de gestion de location de voitures et de réservations offre des fonctionnalités   |
  essentielles pour assurer une gestion efficace des clients, des voitures, des réservations  |
  et des emprunts. Les fonctionnalités de gestion des clients et des voitures permettent      |
  d'ajouter, de modifier et de supprimer les informations correspondantes, tandis que les     |
  fonctionnalités de gestion des réservations et des emprunts permettent d'effectuer des      |
  opérations de réservation, de location et de retour de voitures, ainsi que de consulter     |
  les voitures réservées, les voitures louées et les détails associés à chaque réservation    |
  ou emprunt, Enfin, l'option de quitter.                                                     |
  Le projet vise à développer un logiciel permettant la gestion efficace des clients, des     |
  voitures et des réservations dans une entreprise de location de voitures.                   |                                                                               |
                                                                                              |
----------------------------------------------------------------------------------------------*/

int main(){
    const int taille=200; //Déterminer le taille maximum d'informations;
    clients cl[taille];   //Créer un tableau (liste) des clients;
    voiture ve[taille];   //Créer un tableau (liste) des voitures;
    int bornec=0,bornev=0;//Créer un compteur et un indicateur pour chacune de tableau de clients et le tableau de voitures;
    int choix1,choix2;    //Pour la première et la deuxième réponse de l'utilisateur;
    fichier_fscanf_clients(cl,&bornec);      //La fonction dans #include "clients.h";
    fichier_fscanf_voitures(ve,&bornev);     //La fonction dans #include "Voiture.h";
//      HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);//Pour changer la couleur;
start_principale:                            //Pour revenir à la liste principale;
//     SetConsoleTextAttribute(H,12);           //Pour changer la couleur;
    printf(RED"\n\n\n{{{{{{{{{{{{{{{{{{{{{{{*Menu Principale*}}}}}}}}}}}}}}}}}}}}}}}\n\n");
    printf("\t\t 1- Gestion des Clients....................\n");
    printf("\t\t 2- Gestion des Voitures ..................\n");
    printf("\t\t 3- Gestion des Reservations...............\n");
    printf("\t\t 4- Enregistrer et Quitter le Programme ...\n");
    dessiner_voiture ();//La fonction dans #include "Reservation.h";
    printf("\t\tDonner Votre Choix: ");
    scanf("%d",&choix1); system("clear");
    do{
switch(choix1){
case 1:{
    start_clients://Pour revenir à la liste des clients;
//       SetConsoleTextAttribute(H,11);//Pour changer la couleur;
            printf(YELLOW"\n\n\n\t****************** Menu des Clients ******************\n\n");
            printf("\t\t 1- Ajouter un Client.                                      \n");
            printf("\t\t 2- Modifier un Client.                                     \n");
            printf("\t\t 3- Supprimer un Client.                                    \n");
            printf("\t\t 4- Afficher la liste des Clients par ordre Alphabetique.   \n");
            printf("\t\t 5- Retour en Arriere.                                      \n");
            dessiner_clients ();//La fonction dans #include "Reservation.h";
            printf("\t\tDonner votre choix: ");
            scanf("%d",&choix2); system("clear");
            switch(choix2){
              case 1:{ajouter_client(cl,&bornec,taille);getch();system("clear");
                     break;}//La fonction dans #include "clients.h";
              case 2:{modifier_client(cl,bornec);       getch();system("clear");
                     break;}//La fonction dans #include "clients.h";
              case 3:{supprimer_client(cl,&bornec);     getch();system("clear");
                     break;}//La fonction dans #include "clients.h";
              case 4:{afficher_clients(cl,bornec);      getch();system("clear");
                     break;}//La fonction dans #include "clients.h";
              case 5:{goto start_principale;                    system("clear");
                     break;}//Pour revenir à la liste principale;
              default:{
                     // SetConsoleTextAttribute(H,13);//Pour changer la couleur;
                  printf("\tDonner un nombre entre [1-5]");
                    goto start_clients;//Pour revenir à la liste des clients;
                     break;}
                          }//Fin switch 2 ;
              break;
}//Fin case 1;
case 2:{
    start_voitures://Pour revenir à la liste des voitures;
       //  SetConsoleTextAttribute(H,10);//Pour changer la couleur;
            printf(GREEN"\n\n\n\t****************** Menu des Voitures ******************\n\n");
            printf("\t\t1- Ajouter une Voiture.                                      \n");
            printf("\t\t2- Modifier une Voiture.                                     \n");
            printf("\t\t3- Supprimer une Voiture.                                    \n");
            printf("\t\t4- Afficher la liste des Voitures par ordre Alphabetique.    \n");
            printf("\t\t5- Retour en Arriere.                                        \n");
            dessiner_voiture ();//La fonction dans #include "Reservation.h";
            printf("\t\tDonner votre choix: ");
            scanf("%d",&choix2);system("clear");
            switch(choix2){
              case 1:{ajouter_voiture(ve,&bornev,taille);getch();system("clear");
                    break;}//La fonction dans #include "Voiture.h";
              case 2:{modifier_voiture(ve,bornev);       getch();system("clear");
                    break;}//La fonction dans #include "Voiture.h";
              case 3:{supprimer_voiture(ve,&bornev);     getch();system("clear");
                    break;}//La fonction dans #include "Voiture.h";
              case 4:{afficher_voitures(ve,bornev);      getch();system("clear");
                    break;}//La fonction dans #include "Voiture.h";
              case 5:{goto start_principale;                     system("clear");
                    break;}//Pour revenir à la liste principale;
              default:{
                     // SetConsoleTextAttribute(H,13);//Pour changer la couleur;
                  printf("\tDonner un nombre entre [1-5]");
                    goto start_voitures;//Pour revenir à la liste des voitures;
                    break;}
                          }//Fin switch 2 ;
              break;
}//Fin case 2;
case 3:{
    start_Reservation://Pour revenir à la liste de Reservation;
       //  SetConsoleTextAttribute(H,14);//Pour changer la couleur;
            printf(CYAN"\n\n\n\t****************** Menu des Reservations ******************\n\n");
            printf("\t\t1- Reservation de voiture.                                   \n");
            printf("\t\t2- Rendre une Voiture.                                       \n");
            printf("\t\t3- Afficher la liste des voitures reservees.                 \n");
            printf("\t\t4- Afficher qui a reserve la voiture (recherche).            \n");
            printf("\t\t5- Retour en Arriere.                                        \n");
            dessiner_voiture ();//La fonction dans #include "Reservation.h";
            printf("\t\tDonner votre choix: ");
            scanf("%d",&choix2);system("clear");
            switch(choix2){
              case 1:{Reservation_voiture(cl,ve,bornec,bornev);getch();system("clear");
                     break;}//La fonction dans #include "Reservation.h";
              case 2:{Rendre_voiture(cl,ve,bornec,bornev);     getch();system("clear");
                     break;}//La fonction dans #include "Reservation.h";
              case 3:{Voitures_reservees(ve,bornev);           getch();system("clear");
                     break;}//La fonction dans #include "Reservation.h";
              case 4:{Reservant_voiture(cl,ve,bornec,bornev);  getch();system("clear");
                     break;}//La fonction dans #include "Reservation.h";
              case 5:{goto start_principale;                           system("clear");
                     break;}//Pour revenir à la liste principale;
               default:{
                     // SetConsoleTextAttribute(H,13);//Pour changer la couleur;
                   printf("\tDonner un nombre entre [1-5]");
                    goto start_Reservation;//Pour revenir à la liste de Reservation;
                     break;}
                           }//Fin switch 2 ;
              break;
}//Fin case 3;
case 4:{
/*Cette fonctionnalité permet à l'utilisateur de quitter le programme de gestion de location de voitures
  et de réservations de manière propre et sécurisée. Lorsque cette option est sélectionnée, toutes les
  opérations en cours sont enregistrées, les ressources sont libérées et le programme se ferme correctement.*/

       //   SetConsoleTextAttribute(H,14);//Pour changer la couleur;
            printf(YELLOW"\n\n\n\t******************************Fin de Traitement !!!******************************\n\n");
       //   SetConsoleTextAttribute(H,11);//Pour changer la couleur;
            printf(GREEN"\tCe projet a ete cree et presente par:\n\n\n");
       //   SetConsoleTextAttribute(H,10);//Pour changer la couleur;
            printf(RED"\t\t MM     MM  OOOOOOOO  HH    HH  AAAAAAAA  MM     MM  EEEEEEE  DDDDDD   \n");
            printf("\t\t MMM   MMM  OO    OO  HH    HH  AA    AA  MMM   MMM  EE       DD   DD  \n");
            printf("\t\t MMMM MMMM  OO    OO  HHHHHHHH  AAAAAAAA  MMMM MMMM  EEEEEEE  DD    DD \n");
            printf("\t\t MM MMM MM  OO    OO  HH    HH  AA    AA  MM MMM MM  EE       DD   DD  \n");
            printf("\t\t MM  M  MM  OOOOOOOO  HH    HH  AA    AA  MM  M  MM  EEEEEEE  DDDDDD \n\n");
       //   SetConsoleTextAttribute(H,12);//Pour changer la couleur;
            printf(MAGENTA"\t\t                   SSSSSSS  AAAAAAAA  BBBBBBB   RRRRRR             \n");
            printf("\t\t                   SS       AA    AA  BB    BB  RR   RR            \n");
            printf("\t\t                   SSSSSSS  AAAAAAAA  BBBBBBB   RRRRRR             \n");
            printf("\t\t                        SS  AA    AA  BB    BB  RR   RR            \n");
            printf("\t\t                   SSSSSSS  AA    AA  BBBBBBB   RR    RR       \n\n\n");
       //   SetConsoleTextAttribute(H,13);//Pour changer la couleur;
             break;
}//Fin case 4;
default:{
              // SetConsoleTextAttribute(H,13);//Pour changer la couleur;
              printf("\tDonner un nombre entre [1-4]");
              goto start_principale;//Pour revenir à la liste principale;
             break;
}//Fin case default;
}//fin switch 1;
              getch();
}while(choix1!=4);//Fin do...while();
       fichier_fprintf_clients (cl,bornec);//La fonction dans #include "clients.h";
       fichier_fprintf_voitures(ve,bornev);//La fonction dans #include "Voitures.h";
    return 0;
}
//****************************************************************************

//♦Ce projet a ete cree et presente par: {☺♥ MOHAMED SABR ♥☺}
