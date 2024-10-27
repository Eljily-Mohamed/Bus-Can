# Bus-Can# Projet de Gestion de Capteurs via Bus CAN

## Description du Projet

Ce projet consiste à programmer trois cartes microcontrôleurs pour interagir avec différents capteurs, envoyer les données collectées via un bus CAN, et afficher ces informations sur une interface PC (IHM) développée avec Qt.

## Tâches à Réaliser
- Programmer chaque carte pour interagir avec les capteurs.
- Envoyer les données collectées sur le bus CAN.
- Côté PC, afficher les mesures des capteurs via une interface utilisateur.

## Composants du Projet

### 1. Première Carte
- **Servomoteur** : Contrôle de la vitesse du moteur via des trames RS232.
- **Anémomètre** : Mesure de la vitesse du vent par comptage des impulsions.

### 2. Deuxième Carte
- **Capteur de Luminosité/Distance** : Permet de basculer entre la mesure de luminosité et la distance grâce à un bouton. La distance est limitée à 180 par défaut, mais un bouton permet d'étendre cette mesure.
- **Capteur de Pression et d'Humidité** : Utilise une communication I2C pour récupérer les données.

### 3. Troisième Carte
- **Accéléromètre et Gyroscope** : Mesure des mouvements et de l'orientation.

## Détails Techniques

### Première Carte

#### Capteur 1 : Luminosité/Distance
- Un bouton permet de basculer entre la luminosité et la distance. Par défaut, la mesure de distance s'arrête à 180, mais un autre bouton permet de mesurer une distance plus grande.
- Les données de luminosité (32 bits) doivent être envoyées via le bus CAN sous forme de trames de 8 bits. Chaque octet est envoyé séparément en décalant la variable 32 bits par multiples de 8.
- **Problème de Transmission via CAN** : Le `printf` dans le fichier `vl6180x_lib.c` envoie les données via UART. Pour envoyer ces données via le bus CAN, il est nécessaire de découper les valeurs 32 bits en octets et de les envoyer dans des trames de 8 bits.
- **Filtrage des Messages Reçus** : Si l'identifiant de la trame reçue correspond à un identifiant autorisé, la fonction `can_callback` est exécutée pour traiter la trame. Un test peut être réalisé avec la commande suivante :
  ```bash
  cansend can0 004#message

# Interface Utilisateur (IHM)

L'interface utilisateur développée en Qt permet :

- D'afficher les données des capteurs envoyées via le bus CAN.
- De basculer entre les différents capteurs (par exemple, entre luminosité et distance).
- D'envoyer des commandes pour ajuster la vitesse du moteur.

## Installation et Utilisation

1. Clonez ce dépôt :

    ```bash
    git clone https://votre-repo.git
    ```

2. Configurez le bus CAN avec les commandes mentionnées plus haut.
3. Compilez et chargez le firmware sur chaque carte microcontrôleur.
4. Lancez l'interface Qt pour visualiser les données.

## Détails Supplémentaires

Pour plus d'informations sur le projet et sa documentation, consultez le lien suivant :
[Documentation complète du projet](https://www.linkedin.com/posts/mohamed-eljily_nouvelle-fin-de-semaine-nouveau-projet-termin%C3%A9-activity-7253391508148563969-rXOX?utm_source=share&utm_medium=member_desktop)

## Licence

Ce projet est sous licence MIT. Consultez le fichier `LICENSE` pour plus de détails.
