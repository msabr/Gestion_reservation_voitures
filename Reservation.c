/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reservation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 22:45:43 by msabr             #+#    #+#             */
/*   Updated: 2025/05/18 22:52:47 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gestion_reservation_voitures.h"

//♦Ce projet a ete cree et presente par: {☺♥ MOHAMED SABR ♥☺}

/*Gestion des Réservations :--------------------------------------------------------------------*
																								|
La gestion des réservations permet aux clients de réserver ou loue une voiture disponible pour  |
une période donnée. L'utilisateur peut sélectionner une voiture et enregistrer les informations |
du client réservant. Une liste des voitures réservées est disponible pour afficher les voitures |
actuellement réservées ou louées et les détails de chaque réservation.Lorsqu'une réservation    |
est terminée, la voiture est marquée comme disponible pour de nouvelles réservations.           |                                                                                   |
																								|
*-----------------------------------------------------------------------------------------------*/
//****************************************************************************

/*Pour Une voiture spécifique choisie par l'utilisateur est louée avec un client
 spécifique qui est également choisi par l'utilisateur, et le nombre de jours est
 spécifié afin de démarrer une minuterie inverse qui calcule la période de location */
void Reservation_voiture(clients *c,voiture *v,int bornec,int bornev){
	int i,k=0,l=0;//des index;
	int nbrj;     //le nombre de jour Reservation;
	int index;    //l'index de voiture reservee;
	int re_index; //l'index de reservant;
	 printf("Donner l\'index de voiture reservee: ");
	 scanf("%d",&index);
	 for(i=0;i<bornev;i++){
		if(index==(v+i)->ve_index){//si index donné Correspond avec quelconque index dans le tableau des voitures;
		   printf("Donner l\'index de reservant: ");
		   scanf("%d",&re_index);
		   (v+i)->ve_reservant=re_index;
		   printf("Donner le nombre de jour reservation: ");
		   scanf("%d",&nbrj);
			(v+i)->ve_nbrjour=nbrj;
			 time_t t=time(0); //Pour déclarer la variable temporelle.
			 (v+i)->ve_duree=t+(nbrj*86400);
		   k=1;
}}
	 if (k==0){//si Il n'y a aucun index dans le tableau des voitures Correspond avec index donné;
		printf("\n\n\t*************** La voiture n\'exist pas***************\n");
		dessiner_voiture ();//La fonction dans #include "Reservation.h";
	 }
		else{
	 for(i=0;i<bornec;i++){
		if(re_index==(c+i)->cl_index){
		   l=1;
}}
			if(l==0){//si Il n'y a aucun index dans le tableau des clients Correspond avec index donné;
				 printf("\n\n\t*************** Le client n\'exist pas***************\n");
				 dessiner_clients ();//La fonction dans #include "Reservation.h";
			}

		 }
	if (l!=0 && k!=0){
		printf("\n\n\t***************La voiture a ete reservee avec succes. Le chronometre a maintenant commence***************\n");
		dessiner_voiture ();//La fonction dans #include "Reservation.h";
	}
	 }
//****************************************************************************

/*Pour Une voiture est restituée et il est confirmé si elle a été louée ou non,
 de sorte qu'elle redevienne disponible à la location*/
void Rendre_voiture(clients *c,voiture *v,int bornec,int bornev){
	int index_ve,index_cl,i,j=0,l=0;
	printf("Donner l\'index de voiture reservee: ");
	scanf("%d",&index_ve);
	 for(i=0;i<bornev;i++){
		if(index_ve==(v+i)->ve_index){//si index donné Correspond avec quelconque index dans le tableau des voitures;
		   index_cl=(v+i)->ve_reservant;
		   if((v+i)->ve_nbrjour==0){
			printf("\n\n\t*************** La voiture n\'est pas reservee !!!***************\n");
			dessiner_voiture ();//La fonction dans #include "Reservation.h";
		   }
		   (v+i)->ve_nbrjour=0;
		   (v+i)->ve_reservant=0;
		   l=1;
}
}
	if(l==0){//si Il n'y a aucun index dans le tableau des voitures Correspond avec index donné;
		printf("\n\n\t*************** La voiture n\'existe pas !!!***************\n");
		dessiner_voiture ();//La fonction dans #include "Reservation.h";
	}

   for(i=0;i<bornec;i++){
	if((c+i)->cl_index==index_cl){
		j=1;
		printf("\n\n\t*************** La voiture est rendre avec succes***************\n");
		dessiner_voiture ();//La fonction dans #include "Reservation.h";
	 }
}
	  if(j==0){//si Il n'y a aucun index dans le tableau des clients Correspond avec index donné;
		 printf("\n\n\t*************** Le client n\'existe pas !!!***************\n");
		 dessiner_clients ();//La fonction dans #include "Reservation.h";
	  }
}
//****************************************************************************

/*Pour afficher une liste qui comprend les informations des voitures louées,
 le client qui les loue et la période restante pour l'expiration de la période de location.*/
void Voitures_reservees(voiture *v,int bornev){
	int i,k=0,d;
	printf("\n\n\t******************Les voitures reservees******************\n\n");
	  for(i=0;i<bornev;i++){
		if((v+i)->ve_nbrjour!=0){
			printf("\t\tL\'index de voiture: %d\n",(v+i)->ve_index);
			printf("\t\tLe type de voiture: %s\n",(v+i)->ve_type);
			printf("\t\tLe matricule de voiture: %s\n",(v+i)->ve_matricule);
			printf("\t\tLe couleur de voiture: %s\n",(v+i)->ve_couleur);
			printf("\t\tLe prix totale de voiture: %d DH\n",((v+i)->ve_prix)*((v+i)->ve_nbrjour));
			 time_t t=time(0); //Pour déclarer la variable temporelle.
			 if(((v+i)->ve_duree)>t){
				d=(v+i)->ve_duree-t;
				printf("\t\tLa duree restant: ");
				conversion_secondes(d);//La fonction dans #include "Reservation.h";
			}
			 else{
				d=t-(v+i)->ve_duree;
				printf("\t\tLa duree est expire depuis: ");
				conversion_secondes(d);//La fonction dans #include "Reservation.h";
			 }
			printf("\t\tL\'index de reservant est: %d\n",(v+i)->ve_reservant);
			printf("\n-------------------------------------------------------------------------------\n\n");
			k=1;
		}
		}
		if(k==0)
			printf("\n\n\n\n\t******************Il n\'exist pas de voiture reservees !!!******************\n");
		dessiner_voiture ();//La fonction dans #include "Reservation.h";
		}
//****************************************************************************

/*Pour afficher toutes les informations du client qui loue une voiture spécifique choisie
par l'utilisateur et la période restante jusqu'à la fin de la période de location*/
void Reservant_voiture(clients *c,voiture *v,int bornec,int bornev){
	int indexv,indexc,i,j,k=0,l=0,d;
	printf("Donner l\'index de voiture: ");
	scanf("%d",&indexv);
	 for(i=0;i<bornev;i++){
		if(indexv==(v+i)->ve_index){
				indexc=(v+i)->ve_reservant;
		if(indexc!=0){
				for(j=0;j<bornec;j++){
					if(indexc==(c+j)->cl_index ){
						 printf("\n\t\tL\'index de reservant est: %d\n",(c+j)->cl_index);
						 printf("\t\tLe nom de reservant est: %s\n",(c+j)->cl_nom);
						 printf("\t\tLe prenom de reservant est: %s\n",(c+j)->cl_prenom);
						 printf("\t\tL\'adresse de reservant est: %s\n",(c+j)->cl_adresse);
						 printf("\t\tLe numero de telephone de reservant est: (+212)%d\n",(c+j)->cl_numerotete);
						 printf("\t\tLe prix totale de voiture: %d DH\n",((v+i)->ve_prix)*((v+i)->ve_nbrjour));
						   time_t t=time(0);//Pour déclarer la variable temporelle.
			 if(((v+i)->ve_duree)>t){
				d=(v+i)->ve_duree-t;
				printf("\t\tLa duree restant: ");
				conversion_secondes(d);//La fonction dans #include "Reservation.h";
			}
			 else{
				d=t-(v+i)->ve_duree;
				printf("La duree est expire depuis: ");
				conversion_secondes(d);//La fonction dans #include "Reservation.h";
			 }
						 l=1;
	 }
 }
  dessiner_voiture ();//La fonction dans #include "Reservation.h";
		if(l==0){//si Il n'y a aucun index dans le tableau des clients Correspond avec index donné;
			 printf("\n\n\t*************** Le client n\'exist pas***************\n");
			 dessiner_clients ();//La fonction dans #include "Reservation.h";
		}

}
		k=1;
	}
}
	   if (k==0){//si Il n'y a aucun index dans le tableau des voitures Correspond avec index donné;
		printf("\n\n\t*************** La voiture n\'exist pas***************\n");
		dessiner_voiture ();//La fonction dans #include "Reservation.h";
		}
	   if(indexc==0){
		 printf("\n\n\t*************** La voiture n\'est pas reservee !!!***************\n");
		 dessiner_voiture ();//La fonction dans #include "Reservation.h";
	   }
}
//****************************************************************************

/*Pour Affiche la durée en secondes sur les catégories suivantes : jours, heures, minutes, secondes*/
void conversion_secondes(int n){
	 int r,a;
	if (n>0){
	r=n%86400;
	a=(n-r)/86400;
	if (a != 0){
		if (a==1)
			printf(" %d jour", a);
		else
			printf(" %d jours", a);
		}
	n=r;
	r=n%3600;
	a=(n-r)/3600;
	if (a != 0){
		if (a==1)
			printf(" %d heure", a);
		else
			printf(" %d heures", a);
		}
	n=r;
	r=n%60;
	a=(n-r)/60;
	if (a != 0){
		if (a==1)
			printf(" %d minute", a);
		else
			printf(" %d minutes", a);
		}
	a=r;
	if (a != 0){
		if (a==1)
			printf(" %d seconde\n", a);
		else
			printf(" %d secondes\n", a);
		}
	}
}
//****************************************************************************

/*Pour dessiner une voiture sur l'écran*/
void dessiner_voiture(){
	printf("\t                                    \n");
	printf("\t                                    \n");
	printf("\t          _______________           \n");
	printf("\t         /       |       \\         \n");
	printf("\t     ___/________|________\\____@   \n");
	printf("\t    /            |             \\   \n");
	printf("\t   /       o     |  o           \\  \n");
	printf("\t  /______________|_______________\\ \n");
	printf("\t      (O)                  (O)      \n");
	printf("\t------------------------------------\n");
	printf("\t************************************\n");
	printf("\t                                    \n");
	printf("\t                                    \n");
}
//****************************************************************************

/*Pour dessiner des clients sur l'écran*/
void dessiner_clients(){
	printf("\t                                    \n");
	printf("\t                                    \n");
	printf("\t    O     O     O     O     O       \n");
	printf("\t   /|\\   /|\\   /|\\   /|\\   /|\\ \n");
	printf("\t   / \\   / \\   / \\   / \\   / \\ \n");
	printf("\t  /   \\ /   \\ /   \\ /   \\ /   \\\n");
	printf("\t / CL  \\  I  /  E  \\  N  /  TS \\ \n");
	printf("\t/_______\\___/_______\\___/_______\\\n");
	printf("\t====================================\n");
	printf("\t                                    \n");
}
//****************************************************************************

//♦Ce projet a ete cree et presente par: {☺♥ MOHAMED SABR ♥☺}

char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}


