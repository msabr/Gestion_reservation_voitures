#ifndef VOITURE_H_INCLUDED
#define VOITURE_H_INCLUDED
//♦Ce projet a ete cree et presente par: {☺♥ MOHAMED SABR ♥☺}

/*Gestion des voitures :-----------------------------------------------------------------------*
                                                                                               |
La gestion des voitures permet d'effectuer des opérations telles que l'ajout, la modification  |
 et la suppression des informations sur les voitures disponibles à la location. Les détails    |
 tels que le type, la couleur, matricule et le prix de location peuvent être enregistrés pour  |
  chaque voiture. Une fonction d'affichage de la liste des voitures par ordre alphabétique     |
  (titre) est également disponible pour faciliter la recherche et la visualisation des         |
  voitures disponibles.                                                                        |
                                                                                               |
*----------------------------------------------------------------------------------------------*/
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

/*Pour ajouter une voiture dans la liste des voitures*/
void ajouter_voiture(voiture *v,int *pborne,int taille){
    int index,i,j,l;//des index;
    int k=(*pborne);
    int nbr;//le nombre des voitures a ajouter;
    printf("Donner le nombre des voitures a ajouter: ");
    scanf("%d",&nbr);
     if((*pborne)+nbr-1>=taille){//si taille infireieure de 200;
        printf("\n\n\t*************** Impossible d'ajouter ce nombre de voitures***************\n");
        dessiner_voiture ();//La fonction dans #include "Reservation.h";
     }
     else{
            for(i=k;i<k+nbr;i++){
        printf("-------------------------------------------------------------------\n\n");
        do{
        printf("Donner l\'index de voiture %d: ",i+1);
        scanf("%d",&index);
             j=0;
             for(l=0;l<k+nbr;l++){
             if(index==(v+l)->ve_index){//si index donné Correspond avec quelconque index dans le tableau des voitures;
             printf("\n\n\t*************** La voiture est deja existe !!!***************\n");
             dessiner_voiture ();//La fonction dans #include "Reservation.h";
             j++;
             }
             }
             }while(j!=0);
           (v+i)->ve_index=index;

        do{
        printf("Donner le type de voiture %d: ",i+1);
        scanf("%s",(v+i)->ve_type);
        }while((v+i)->ve_type[0]=='0' ||(v+i)->ve_type[0]=='1'||(v+i)->ve_type[0]=='2'||(v+i)->ve_type[0]=='3'||(v+i)->ve_type[0]=='4'||(v+i)->ve_type[0]=='5'||(v+i)->ve_type[0]=='6'||(v+i)->ve_type[0]=='7'||(v+i)->ve_type[0]=='8'||(v+i)->ve_type[0]=='9');
        printf("Donner le matricule de voiture %d: ",i+1);
        scanf("%s",(v+i)->ve_matricule);
        printf("Donner le couleur de voiture %d: ",i+1);
        scanf("%s",(v+i)->ve_couleur);
        printf("Donner le prix de voiture par jour: ",i+1);
        scanf("%d",&(v+i)->ve_prix);
        (*pborne)++;}
        printf("\n\n\t*************** Les voitures a ete ajoutee !!!***************\n");
        dessiner_voiture ();//La fonction dans #include "Reservation.h";
     }
}
//****************************************************************************

/*Pour modifier les information d'une voiture dans la liste des voitures*/
void modifier_voiture(voiture *v,int borne){
    int index,i,j=0;
      printf("\t Donner l\'index de voiture a modifier: ");
      scanf("%d",&index);
      for(i=0;i<borne;i++){
        if((v+i)->ve_index==index){//si index donné Correspond avec quelconque index dans le tableau des voitures;
         do{
           printf("Donner le noveau type: ");
           scanf("%s",(v+i)->ve_type);
        }while((v+i)->ve_type[0]=='0' ||(v+i)->ve_type[0]=='1'||(v+i)->ve_type[0]=='2'||(v+i)->ve_type[0]=='3'||(v+i)->ve_type[0]=='4'||(v+i)->ve_type[0]=='5'||(v+i)->ve_type[0]=='6'||(v+i)->ve_type[0]=='7'||(v+i)->ve_type[0]=='8'||(v+i)->ve_type[0]=='9');
           printf("Donner le matricule type: ");
           scanf("%s",(v+i)->ve_matricule);
           printf("Donner le couleur type: ");
           scanf("%s",(v+i)->ve_couleur);
           printf("Donner le noveau prix: ");
           scanf("%d",&(v+i)->ve_prix);
           j=1;
           printf("\n\n\t***************La voiture est modifier !!!***************");
           dessiner_voiture ();//La fonction dans #include "Reservation.h";
        }
      }
      if(j==0){//si Il n'y a aucun index dans le tableau des voitures Correspond avec index donné;
         printf("\n\n\t*************** La voiture n\'existe pas !!!***************\n");
         dessiner_voiture ();//La fonction dans #include "Reservation.h";
      }
}
//****************************************************************************

/*Pour supprimer les information d'une voiture dans la liste des voitures*/
void supprimer_voiture(voiture *v,int *pborne){
     int i=0,j,k,index;
     printf("Donner l\'index de voiture a supprimer: ");
     scanf("%d",&index);
   for(j=0;j<(*pborne);j++){
    if((v+j)->ve_index==index)
        i=j;
   }
     if(i==0){//si Il n'y a aucun index dans le tableau des voitures Correspond avec index donné;
        printf("\n\n\t*************** La voiture n\'existe pas !!!***************\n");
        dessiner_voiture ();
     }
     else{
        for(j=i;j<(*pborne);j++){ //supprimer les information d'une voiture dans la liste des voitures;
            (v+j)->ve_index=(v+j+1)->ve_index;
                for(k=0;k<20;k++){
            (v+j)->ve_type[k]=(v+j+1)->ve_type[k];
                }
                for(k=0;k<20;k++){
            (v+j)->ve_matricule[k]=(v+j+1)->ve_matricule[k];
                }
                for(k=0;k<20;k++){
            (v+j)->ve_couleur[k]=(v+j+1)->ve_couleur[k];
                }
            (v+j)->ve_prix=(v+j+1)->ve_prix;
            (v+j)->ve_duree=(v+j+1)->ve_duree;
            (v+j)->ve_nbrjour=(v+j+1)->ve_nbrjour;
            (v+j)->ve_reservant=(v+j+1)->ve_reservant;
        }
         printf("\n\n\t***************La voiture est supprimee !!!***************");
         dessiner_voiture ();//La fonction dans #include "Reservation.h";
        (*pborne)--;
     }
}
//****************************************************************************

/*Pour afficher les information d'une voiture dans la liste des voitures*/
void afficher_voitures(voiture *v,int borne){
    int i,k=65,l=97,j=0;
    //65 est code ASCII de "A" majuscule;
    //97 est code ASCII de "a" minuscule;
    printf("\n La liste des Voitures par ordre Alphabetique:");
    do{
     for (i=0;i<borne;i++){
        if((v+i)->ve_type[0]==k || (v+i)->ve_type[0]==l ){
            printf("\n\n\t****************** Voiture %d ******************\n",j+1);
            printf("\t\tIndex : %d\n",(v+i)->ve_index);
            printf("\t\tType : %s\n",(v+i)->ve_type);
            printf("\t\tMatricule : %s\n",(v+i)->ve_matricule);
            printf("\t\tCouleur : %s\n",(v+i)->ve_couleur);
            printf("\t\tPrix par jour : %d DH\n",(v+i)->ve_prix);
            printf("\n-------------------------------------------------------");
            j++;

        }
     }
     l++;k++;
}while(l<123 && k<91);
    //91 est code ASCII de "Z" majuscule;
    //123 est code ASCII de "z" minuscule;
     if(j==0)
        printf("\n\n\t*************** Il n\'existe pas de voitures !!!***************\n");
        dessiner_voiture ();//La fonction dans #include "Reservation.h";
}
//****************************************************************************

/*Pour transporter les donnes au fichier*/
void fichier_fprintf_voitures(voiture *v,int borne){
    int i;
    ve=fopen("voitures.txt","w");
    //Le mode "w" pour ouverture d’un fichier texte en ecriture;
     if(ve==NULL){//si le fichier est null n'est existe pas;
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        dessiner_voiture ();//La fonction dans #include "Reservation.h";
        exit(1);//Pour la sortie finale du programme
    }
    for(i=0;i<borne;i++){ //pour copier les donnes de la liste des voitures au fichier;
        fprintf(ve,"%d\n",(v+i)->ve_index);
        fprintf(ve,"%s\n",(v+i)->ve_type);
        fprintf(ve,"%s\n",(v+i)->ve_matricule);
        fprintf(ve,"%s\n",(v+i)->ve_couleur);
        fprintf(ve,"%d\n",(v+i)->ve_prix);
        fprintf(ve,"%d\n",(v+i)->ve_duree);
        fprintf(ve,"%d\n",(v+i)->ve_nbrjour);
        fprintf(ve,"%d\n",(v+i)->ve_reservant);
    }
    fclose(ve);
}
//****************************************************************************

/*Pour transporter les donnes au tableu*/
void fichier_fscanf_voitures(voiture *v,int *pborne){
    int i=0;
    ve=fopen("voitures.txt","a+");
    //Le mode "a+" pour ouverture d’un fichier texte en lecture/écriture a la fin;

     if(ve==NULL){//si le fichier est null n'est existe pas;
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        dessiner_voiture ();//La fonction dans #include "Reservation.h";
        exit(1);//Pour la sortie finale du programme
    }
    //Repeter Jusqu'à ce que toutes les informations à saisir soient terminées;
    while(fscanf(ve,"%d\n %s\n %s\n %s\n %d\n %d\n %d\n %d\n",&(v+i)->ve_index,(v+i)->ve_type,(v+i)->ve_matricule,(v+i)->ve_couleur,&(v+i)->ve_prix,&(v+i)->ve_duree,&(v+i)->ve_nbrjour,&(v+i)->ve_reservant)!=EOF){
        i++;
        (*pborne)++;
    }
    fclose(ve);
}
//****************************************************************************

//♦Ce projet a ete cree et presente par: {☺♥ MOHAMED SABR ♥☺}

#endif // VOITURE_H_INCLUDED
