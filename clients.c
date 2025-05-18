#include "Gestion_reservation_voitures.h"
//♦Ce projet a ete cree et presente par: {☺♥ MOHAMED SABR ♥☺}

/*Gestion des clients : -----------------------------------------------------------------------*
                                                                                               |
La fonctionnalité de gestion des clients permet d'ajouter, de modifier et de supprimer les     |
 informations relatives aux clients de l'entreprise de location de voitures. Cela inclut les   |
 détails personnels des clients tels que leur nom, prenom, adresse et numéro de téléphone.     |
  De plus, une fonction d'affichage de la liste des clients par ordre alphabétique est         |
  disponible pour faciliter la recherche et la navigation.                                     |                        |
                                                                                               |
*----------------------------------------------------------------------------------------------*/
//****************************************************************************


/*Pour ajouter un client dans la liste des clients*/
void ajouter_client(clients *c,int *pborne,int taille){
    int index,i,j,l;//des index;
    int k=(*pborne);
    int nbr;//le nombre de clients a ajouter:
    printf("Donner le nombre de clients a ajouter: ");
    scanf("%d",&nbr);
     if((*pborne)+nbr-1>=taille){//si taille infireieure de 200;
         printf("\n\n\t*************** Impossible d'ajouter ce nombre de clients***************\n");
        dessiner_clients();//La fonction dans #include "Reservation.h";
     }
     else{
            for(i=k;i<k+nbr;i++){
        printf("------------------------------------------------\n\n");
      do{
        printf("Donner l\'index de client %d: ",i+1);
        scanf("%d",&index);
         j=0;
         for(l=0;l<k+nbr;l++){
            if(index==(c+l)->cl_index){//si index donné Correspond avec quelconque index dans le tableau des clients;
            printf("\n\n\t*************** Le clinet est deja existe !!!***************\n");
            dessiner_clients ();//La fonction dans #include "Reservation.h";
            j++;
            }
          }
        }while(j!=0);
         (c+i)->cl_index=index;
         do{
        printf("Donner le nom de client %d: ",i+1);
        scanf("%s",(c+i)->cl_nom);
         }while((c+i)->cl_nom[0]=='0'|| (c+i)->cl_nom[0]=='1'|| (c+i)->cl_nom[0]=='2'|| (c+i)->cl_nom[0]=='3'|| (c+i)->cl_nom[0]=='4'|| (c+i)->cl_nom[0]=='5'|| (c+i)->cl_nom[0]=='6'|| (c+i)->cl_nom[0]=='7'|| (c+i)->cl_nom[0]=='8'|| (c+i)->cl_nom[0]=='9');
        printf("Donner le prenom de client %d: ",i+1);
        scanf("%s",(c+i)->cl_prenom);
        printf("Donner l\'adresse de client %d: ",i+1);
        scanf("%s",(c+i)->cl_adresse);
        printf("Donner le numero de telephone de client %d:(+212)",i+1);
        scanf("%d",&(c+i)->cl_numerotete);

        (*pborne)++;
        }
         printf("\n\n\t*************** Les clinets a ete ajoutee !!!***************\n");
         dessiner_clients ();//La fonction dans #include "Reservation.h";
     }
}
//****************************************************************************

/*Pour modifier les information d'un client dans la liste des clients*/
void modifier_client(clients *c,int borne){
    int index,i,j=0;
      printf("Donner l\'index de client a modifier: ");
      scanf("%d",&index);
      for(i=0;i<borne;i++){
        if((c+i)->cl_index==index){//si index donné Correspond avec quelconque index dans le tableau des clients;
          do{
           printf("Donner le nouveau nom: ");
           scanf("%s",(c+i)->cl_nom);
         }while((c+i)->cl_nom[0]=='0'|| (c+i)->cl_nom[0]=='1'|| (c+i)->cl_nom[0]=='2'|| (c+i)->cl_nom[0]=='3'|| (c+i)->cl_nom[0]=='4'|| (c+i)->cl_nom[0]=='5'|| (c+i)->cl_nom[0]=='6'|| (c+i)->cl_nom[0]=='7'|| (c+i)->cl_nom[0]=='8'|| (c+i)->cl_nom[0]=='9');
           printf("Donner le nouveau prenom: ");
           scanf("%s",(c+i)->cl_prenom);
           printf("Donner le nouveau adresse: ");
           scanf("%s",(c+i)->cl_adresse);
           printf("Donner le nouveau numero de telephone: ");
           scanf("%d",&(c+i)->cl_numerotete);
           printf("\n\n\t***************le client est modifier !!!***************");
           dessiner_clients ();//La fonction dans #include "Reservation.h";
           j=1;
        }
      }
      if(j==0){//si Il n'y a aucun index dans le tableau des voitures Correspond avec index donné;
         printf("\n\n\t*************** le client n\'existe pas !!!***************\n");
        dessiner_clients ();//La fonction dans #include "Reservation.h";
      }
}
//****************************************************************************

/*Pour supprimer les information d'un client dans la liste des clients*/
void supprimer_client(clients *c,int *pborne){
     int i=0,j,k,l,index;
     printf("Donner l\'index de client a supprimer: ");
     scanf("%d",&index);
   for(j=0;j<(*pborne);j++){
    if((c+j)->cl_index==index)
        i=j;

   }
     if(i==0){//si Il n'y a aucun index dans le tableau des clients Correspond avec index donné;
         printf("\n\n\t*************** le client n\'existe pas !!!***************\n");
         dessiner_clients ();//La fonction dans #include "Reservation.h";
     }
     else{
        for(j=i;j<(*pborne);j++){//supprimer les information d'un client dans la liste des vclients;
            (c+j)->cl_index=(c+j+1)->cl_index;
                for(k=0;k<20;k++){
            (c+j)->cl_nom[k]=(c+j+1)->cl_nom[k];
            (c+j)->cl_prenom[k]=(c+j+1)->cl_prenom[k];
                }
                for(k=0;k<100;k++){
            (c+j)->cl_adresse[k]=(c+j+1)->cl_adresse[k];
                }
            (c+j)->cl_numerotete=(c+j+1)->cl_numerotete;
        }
         printf("\n\n\t***************le client est supprimee !!!***************");
         dessiner_clients ();//La fonction dans #include "Reservation.h";
        (*pborne)--;
     }
}
//****************************************************************************

/*Pour afficher les information d'un client dans la liste des clients*/
void afficher_clients(clients *c,int borne){
    int i,k=65,l=97,j=0;
    //65 est code ASCII de "A" majuscule;
    //97 est code ASCII de "a" minuscule;
    printf("\n La liste des Clients par ordre Alphabetique:");
        do{
     for (i=0;i<borne;i++){
       if((c+i)->cl_nom[0]==k || (c+i)->cl_nom[0]==l ){
            printf("\n\n\t******************Client %d******************\n",j+1);
            printf("\t\tIndex : %d\n",(c+i)->cl_index);
            printf("\t\tNom : %s\n",(c+i)->cl_nom);
            printf("\t\tPrenom : %s\n",(c+i)->cl_prenom);
            printf("\t\tAdresse : %s\n",(c+i)->cl_adresse);
            printf("\t\tNumero de telephone : (+212)%d\n",(c+i)->cl_numerotete);
            printf("\n-------------------------------------------------------");
            j++;
        }
     }
     l++;k++;
}while(l<=122 && k<=90);
    //90 est code ASCII de "Z" majuscule;
    //122 est code ASCII de "z" minuscule;
    if(j==0)
        printf("\n\n\t*************** Il n\'existe pas de clients !!!***************\n");
       dessiner_clients ();//La fonction dans #include "Reservation.h";
}
//****************************************************************************

/*Pour transporter les donnes au fichier*/
void fichier_fprintf_clients(clients *c,int borne){
    int i;
    cl=fopen("clients.txt","w");
    //Le mode "w" pour ouverture d’un fichier texte en ´ecriture;
     if(cl==NULL){//si le fichier est null n'est existe pas;
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        dessiner_clients ();//La fonction dans #include "Reservation.h";
        exit(1);//Pour la sortie finale du programme
    }
    for(i=0;i<borne;i++){//pour copier les donnes de la liste des clients au fichier;
        fprintf(cl,"%d\n",(c+i)->cl_index);
        fprintf(cl,"%s\n",(c+i)->cl_nom);
        fprintf(cl,"%s\n",(c+i)->cl_prenom);
        fprintf(cl,"%s\n",(c+i)->cl_adresse);
        fprintf(cl,"%d\n",(c+i)->cl_numerotete);
    }
    fclose(cl);
}
//****************************************************************************

/*Pour transporter les donnes au tableu*/
void fichier_fscanf_clients(clients *c,int *pborne){
     int i=0;
    cl=fopen("clients.txt","a+");
    //Le mode "a+" pour ouverture d’un fichier texte en lecture/écriture a la fin;
     if(cl==NULL){//si le fichier est null n'est existe pas;
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        dessiner_clients ();//La fonction dans #include "Reservation.h";
        exit(1);//Pour la sortie finale du programme
    }
    //Repeter Jusqu'à ce que toutes les informations à saisir soient terminées;
    while(fscanf(cl,"%d\n %s\n %s\n %s\n %d\n",&(c+i)->cl_index,(c+i)->cl_nom,(c+i)->cl_prenom,(c+i)->cl_adresse,&(c+i)->cl_numerotete)!=EOF){
        i++;
        (*pborne)++;
    }
    fclose(cl);
}
//****************************************************************************

//♦Ce projet a ete cree et presente par: {☺♥ MOHAMED SABR ♥☺}
