# 🚗 Gestion de Réservation de Voitures – Projet en Langage C

## 📋 Présentation

Ce projet est une application console développée en langage C permettant la gestion d’un système de réservation de voitures. Il simule le fonctionnement d’une agence de location de véhicules : les clients peuvent réserver une voiture pour une période donnée et les administrateurs peuvent gérer le parc automobile.

## 🎯 Fonctionnalités

- **Gestion des voitures** :
  - Ajout d'une nouvelle voiture.
  - Suppression d’une voiture.
  - Modification des informations (marque, modèle, disponibilité, prix/jour).
  - Affichage de la liste des voitures disponibles.

- **Gestion des clients** :
  - Enregistrement des informations clients.
  - Consultation des réservations associées à un client.

- **Réservations** :
  - Création d'une réservation (voiture, client, date de début et de fin).
  - Vérification de la disponibilité du véhicule.
  - Calcul de la durée de la location.
  - Historique des réservations.

- **Persistance des données** :
  - Utilisation de fichiers texte (`voitures.txt`, `clients.txt`, `reservations.txt`) pour enregistrer les données.

## 🛠️ Technologies utilisées

- **Langage** : C
- **Compilateur** : GCC
- **IDE recommandé** : Code::Blocks, Dev-C++, VS Code
- **Système d’exploitation** : Windows, Linux

## 📁 Structure du projet

    Gestion_reservation_voitures/
    ├── main.c
    ├── Voiture.c
    ├── Reservation.c
    ├── clients.c
    ├── Gestion_reservation_voitures.h
    ├── voitures.txt
    ├── clients.txt
    └── Makefile

## 🚀 Installation et exécution

### 1. Cloner le dépôt

```bash
git clone https://github.com/msabr/Gestion_reservation_voitures.git
cd Gestion_reservation_voitures
````
### 2. Compiler le projet

Si un Makefile est fourni :

```bash
make
````
Sinon, compilez manuellement :

```bash
gcc main.c voiture.c reservation.c client.c -o gestion_reservation_voitures
````
### 3. Exécuter l'application
```bash
./gestion_reservation_voitures
````
⚠️ Assurez-vous que les fichiers voitures.txt, clients.txt et reservations.txt existent dans le dossier data/. L'application les créera si nécessaire.


💡 Exemples d'utilisation
Ajouter une voiture : saisir les détails de la voiture (marque, modèle, prix, disponibilité).

Réserver une voiture : choisir une voiture disponible, entrer les dates de début/fin et les infos du client.

Afficher les voitures disponibles : liste filtrée par disponibilité.
