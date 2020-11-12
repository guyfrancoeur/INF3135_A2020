# Travail pratique 2

#### Guy Francoeur :copyright: édition A2020

  L'objectif est de continuer notre initiation à la programmation avec le langage C. Cette fois nous allons
  un peu plus loin dans notre processus de création et de réflexion.  Vous devez dans ce travail livrer un
  programme de qualité irréprochable qui tient compte de critères déjà vus. Spécifiquement vous devez lire
  et produire des données sur l'entrée et la sortie standard respectivement.
  
  De plus, vos sources seront maintenues dans un gestionnaire de version/source de type git.
  
  La compréhension et la prise de décision sont aussi des objectifs à atteindre durant la mise en oeuvre,
  la réalisation, de vos travaux.
  
  Le travail est à réaliser **individuellement**.

## Sujet (rappel)

Chaque session nous avons un sujet unique que nous traînons pendant les 15 semaines.  Cette fois encore,
je continue avec cette bonne habitude.  L'avantage est que nous n'avons pas à apprendre des sujets différents
pour chaque travail pratique.  Ainsi nous pouvons vraiment concentrer l'effort sur ce qui est important, 
c'est-à-dire la construction et la maintenance de logiciels.  Pour nous c'est avec le langage C.  Un langage
de programmation important qui produit des logiciels dits performants, mais il n'en serait rien sans des
programmeurs qui savent ce qu'ils font.

TCV est un projet d'actualité, qui veut dire : tous contrent le virus (ou les virus). Nous allons tenter
ensemble de réaliser des programmes qui vont permettre de lutter et prévenir dans un temps très court
la dispersion du virus. Concrètement vous allez programmer un module (un Beacon) qui traite de l'information
reçue et qui réagit en émettant à son tour des transactions.

## Description du travail

 Vous devez dans un fichier nommé `tp2.c` coder la fonction `main()` du projet tous contre le virus.  Ce système
 gère des données en entrée (stdin) et en sortie (stdout).  Le déploiement de certains produits informatique,
 comme le nôtre, peut devenir complexe lorsque les clients (pastilles) sont répandus partout dans le monde.
 Le déploiement de programmes dit "parfait" est important considérant le sujet et le nombre de modules visés.
 Une erreur va surement faire les manchettes et sauvez moins de vie. La date de livraison est importante et
 doit être respectée.
 
 Cette fois vous utiliserez les fonctions valides disponibles dans `tcv.h` et `tcv.o` pour réaliser le travail.
  
 Le rôle du programme `tp2.c` et de son exécutable est de traiter toutes les lignes de données.  Dans
 certains cas vous avez à produire des données sur le canal (stdout) de sortie standard.  Ceci simule
 le dialogue (les données échangées).  Le résultat en sortie est celui qui sera évalué.
  
  Le programme exécutable peut être lancé en ligne de commande avec différentes syntaxes :

```bash
$ ./tp2

$ cat file.dat | ./tp2

$ ./script.sh | ./tp2

$ head -n 100 file.txt | ./tp2
...
```

#### Vous devez réaliser le travail selon les contraintes suivantes:

- Les fichiers d'entête standard sont tous permis. Tel que `#include <stdio.h>`;
- Vous devez utiliser les fichiers `tcv.h` et `tcv.o` qui sont fournis dans `tp2.zip`;
- `cUnit` est `la seule` librairie non standard (car elle ne fait pas du langage C de base) qui est authorisée pour ce travail;
- Les questions (limitez-vous à max 2) devront **toutes** être posées dans le forum de discussion GitHub section *Issues*;
- Vous devez contribuer aux questions posées au moins une fois maximum deux fois;
- Une **demande de solution** (réponse), comment faire ceci ou cela sera considéré comme un **plagiat**;
- Votre travail sera réalisé et livré dans le dépôt distant `inf3135-a2020`, toujours privé;
- Les fichiers seront maintenus dans la branche nommée `tp2`;
- La branche `master` ou `main` comme `défaut` est pour les rétroactions et commentaires de l'enseignant;
- Ne garder que les fichiers essentiels dans votre projet (dépôt distant);
- La gestion des répertoires doit se faire de façon complète **à partir de votre répertoire de travail**;
  + votre répotoire de travail étant : `./`; 
  + Vous __ne pouvez pas__ utiliser `..` ou la commande `cd` dans votre travail;
- La simplicité de vos livrables est exigée.  Aucun code ésotérique ne sera accepté.

Définition :
 + ésotérique : Se dit d'un mode d'expression, d'une œuvre qui n'est compréhensible que des initiés;

Synonyme :
 + mystérieux : Qui est incompréhensible ou inexplicable;

Source : Larousse FR

#### Critère d'évaluation pour les fonctions
 - Température humaine
   + +17.0C @ +40.0C
 - Température ambiante
   + -40.0C @ +40.0C
 - Pulsation par minutes
   + 50 @ 200 (ppm)
 - Signal RSSI
   + -85 @ -25 
   + [info complémentaire](https://dzone.com/articles/formula-to-convert-the-rssi-value-of-the-ble-bluet)
 
 ##### `Important`
  - Les valeurs sont inclusives.
  - Vous devez donc passer des valeurs entières aux fonctions, les dixièmes deviennent des unités.
  - Vous devez respecter les limites des types de données.
 
### Rôle de votre programme

Le rôle de votre programme est de lire des transactions.  Les transactions sont décrites dans la section
**Transaction en entrée / Transaction en sortie**.  Les transactions sont très formelles.  Il s'agit d'un
système dit critique, aucune nuance possible.  Ceci ne veut pas dire que les transactions ou le système
est exempt d'erreurs.  Vous ne devez, en aucun temps (jamais), laisser le hasard gérer la situation.

Voici les cas et les traitements :
 + Si un capteur donne une valeur inacceptable, vous devez réagir immédiatement;
   - Vous ajoutez un (1) au compteur `valeur invalide` par type;
   - voir transaction 22.
 + Si un capteur donne le mot `ERREUR`, vous devez réagir à la troisième manifestation du mot `ERREUR`;
   - Vous ajoutez un (1) au compteur `cumul des mots ERREUR` par type;
   - voir transaction 23.

### Transaction en entrée

Le rôle des transactions en entrées a pour but de simuler les événements que la pastille émet
normalement. Puisque nous n'avons pas de pastilles entre les mains, nous avons besoin de celles-ci
pour valider votre programme. Voici tous les types de transactions que le programme est en mesure 
d'accepter:

00: Identification
 + Définition : ```<timestamp> 00 <id> <puissance de l'émetteur>```
 + Signature : ```<size_t> 00 <size_t> <unsigned char>```
 + l'id par défaut est 9999
 + la puissance de l'émetteur par défaut est 2
```
0 00 1000 3
```

01: Température Humaine
 + Définition :```<timestamp> 01 <degré Celsius | ERREUR>```
 + Signature : ```<size_t> 01 <float|ERREUR>```
```
2 01 38.2
91 01 37.0
2001 01 ERREUR
```

02: Température Ambiante
 + Définition : ```<timestamp> 02 <degré Celsius | ERREUR>```
 + Signature : ```<size_t> 02 <float|ERREUR>```
```
2093 02 5.5
10020 02 -10.2
```

03: Pulsation par minute
 + Définition : ```<timestamp> 03 <pulsation par minute | ERREUR>```
 + Signature : ```<size_t> 03 <float|ERROR>```
```
11112 03 157
11900 03 ERREUR
```

04: Signal RSSI (reçu)
 + Définition : ```<timestamp> 04 <puissance du signal RSSI> <id>```
 + Signature : ```<size_t> 04 <signed short> <size_t>```
```
17599 04 -85 1929292 
19012 04 -35 1929298
```

05: Échange de données - recevoir l'id et les id de premier niveau (idPN)
 + Définition : ```<timestamp> 05 <id> <idPN [idPN ...]>```
 + Signature : ```<size_t> 05 <size_t> <size_t [size_t ...]>```

```
19388 05 1929292 100100 
19511 05 1929298 100123 100987
```

### Transaction en sortie

Les transactions en sortie concernent les informations émises à la suite d'un événement traiter
par votre programme. Certaines transactions en entrées vont nécessairement provoquer une sortie.
Voici la liste des sorties possibles.

10: Changement de l'identifiant par défaut
 + Définition : ```10 <timestamp> <id> <puissance de l'émetteurs>```
 + Signature : ```10 <size_t> <size_t> <unsigned char>```
 + Événement : 00

14: Qualité du signal en mètres
 + Définition : ```14 <timestamp> <id> <distance en mètres> ```
 + Signature : ```14 <size_t> <size_t> <float>```
 + Événement : 04
 
15: Échange de données - evoyer mon id et les id de premier niveau (idPN)
 + Définition : ```15 <timestamp> <id> <idPN [idPN ...<sup>n</sup>]>```
 + Signature : ```15 <size_t> <size_t> <size_t [size_t ...]>```
 + Événement : 05

21: Moyennes pour TH TA pulsation
 + Définition : ```21 <la moyenne des TH> <la moyenne des TA> <la moyenne des pulsations>```
 + Signature : ```21 <float> <float> <size_t>```
 + Événement : fin du programme

22: Nombre de valeurs invalide pour TH TA pulsation
 + Définition : ```22 <compteur valeur invalide pour TH> <compteur valeur invalide pour TA> <compteur valeur invalide pour pulsations>```
 + Signature : ```22 <size_t> <size_t> <size_t>```
 + Événement : fin du programme

23: Cumul des mots `ERREUR` pour TH TA pulsation
 + Définition : ```23 <cumul pour TH> <cumul pour TA> <cumul pour pulsations>```
 + Signature : ```23 <size_t> <size_t> <size_t>```
 + Événement : fin du programme
 
### Résulats (exemple visuel)

#### Directives 
- L'affichage du type `float` se fera avec une seule décimale
- La première ligne à écrire est la version de la librairie
- L'outil `diff` est utilisé pour vérifier la conformité de la sortie
- La formule pour calculer la distance
  + Puissance pour 1 mètre est : m = -69
  + Puissance de l'émetteur BT est :  N = { 2, 3, 4 }
  + Distance = 10 <sup>((m - Signal RSSI)/(10 * N))</sup>

#### `entrée`
~~~
0 00 1000 3
2 01 38.2
2001 01 ERREUR
10020 02 -10.2
11112 03 157
17599 04 -85 1929292
19012 04 -35 1929298
19511 05 1929298 100123 100987
~~~

#### `sortie`
```
version #: 0.1.10005
10 0 1000 3
14 17599 1929292 3.4
14 19012 1929298 0.1
15 19511 1000 1929292 1929298
21 38.2 -10.2 157
22 0 0 0
23 0 0 0
```
 
## Makefile

  Il est obligatoire d'inclure un fichier `Makefile` dans votre projet pour faciliter la compilation
  et les autres actions requises. Celui-ci doit minimalement offrir les services suivants :
  
- Le Makefile du `tp1` sera utilisé et modifié avec quelques changements :
  + La commande `make tp1` est la nouvelle commande pour construire l'exécutable `tp1`;
  + La commande `make` employée seule devra exécuter la cible `default` qui est dépendante de tp2;
  + La cible `tp2` doit exister pour construire l'exécutable `tp2`;

- Lorsqu'on entre `make clean`, le projet revient dans son état d'origine, c'est-à-dire
  son état lors de la récupération initiale;

- Lorsqu'on entre `make lib`, le téléchargement du fichier 
  https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp2.zip
  se fait de façon automatique dans un répertoire (./data). Par la suite, la décompression
  est nécessaire;

- Lorsqu'on entre `make test-tp1a` le programme `tp1` s'exécutera.
- Lorsqu'on entre `make test-tp1b` le programme `tp1` avec `liste.sh` s'exécutera afin de lister les fonctions valides.

- Lorsqu'on entre `make test-tp2` le programme `tp2` s'exécutera.

- Les programmes seront compilés et évalués avec les options suivant `-Wall -Werror=vla -pedantic -std=c11`;

### Complément

+ `-std=c11` indique au compilateur de traiter le code selon le standard C11 (2011) (et donc 
de rejeter certaines extensions comme celles de GNU par exemple);
+ `-pedantic` permet de signaler les avertissements, ou warnings, selon la norme ISO;
+ `-Wall` permet de signaler un grand nombre d'autres warnings décrit dans le man gcc;
+ `-Werror=vla` indique au compilateur que la déclaration de tableaux de longueur variable n'est pas permise.

En effet, la grande permissivité de C réduit l'aide du compilateur (lorsqu'il n'y a pas d'option)
pour traquer certaines erreurs et les mauvaises pratiques de programmation.

## .gitignore

+ Votre projet (dépôt distant) doit contenir uniquement les fichiers strictement nécessaires; 
+ Votre projet ne doit pas contenir de fichiers `objet` ou `binaire` par exemple.

## liste.sh

 Votre programme exécutable tp1 liste beaucoup de choses lorsqu'il est lancé.  Le fichier nommé `liste.sh`
 recevra par stdin le stdout de tp1. Par la suite, vous devez lister uniquement les noms des fonctions qui
 sont valides et fonctionnelles. Il y aura certainement plusieurs fonctions qui vont être listées.
 
 #### exemple de sortie:
 ```
validerSignal_4
validerTA_5
 ```

## README.md

  Votre projet doit contenir un fichier nommé `README.md` qui décrit le contenu et qui **respecte le
  format Markdown**. Il doit minimalement contenir les informations ci-bas :

~~~~
   # Travail pratique X

   ## Description

   <description du projet en quelques phrases>
   <mentionner le contexte (cours, sigle, université, etc.)>

   ## Auteur

   <prénom et nom> (<code permanent>)

   ## Fonctionnement

   <expliquez brièvement comment faire fonctionner votre projet, en inscrivant
   au moins deux exemples d'utilisation (commande lancée et résultat affiché)>

   ## Contenu du projet

   <décrivez brièvement chacun des fichiers contenus dans le projet (une phrase
   par fichier)>

   ## Processus de réflexion et démarche 
   
   <inclure par référence le fichier reflexion.md>

   ## Références

   <citez vos sources ici>

   ## Statut et auto-évaluation

   <indiquez si le projet est complété ou s'il y a des bogues>
   <mon travail vaut quelques points en fonction du barème>
   
~~~~

# Remise

  La totalité de votre travail doit être remise au plus tard le **22 novembre 2020** à **23h59** HE (heure du Québec).
  Après cette date, une pénalité de **10 points par jour** de retard sera appliquée.
  
  **Aucune remise par courriel ne sera acceptée** (le travail sera considéré comme non remis).

  La remise se fait **obligatoirement** par l'intermédiaire de la plateforme `Github`.

  Le nom de votre dépôt doit être `inf3135-a2020` (en minuscules). Celui-ci est **obligatoirement**, privé.
  Vous devez ajouter l'utilisateur `guyfrancoeur` comme collaborateur. La demande de collaboration est le
  moyen de rendre votre livrable accessible.

  Votre projet devrait minimalement contenir, à la racine du dépôt, les fichiers de type `Unix/Linux` et `ascii` suivants :

- Un fichier `tp2.c` contenant le code source de votre projet, ainsi que votre fonction `main`;
- Les fichiers `malib.c` et `malib.h` doivent exister;
- Un fichier `README.md` selon le format proposé;
- Un fichier `reflexion.md` qui démontre le processus de réflexion durant le travail;
- Un fichier nommé `Makefile` complet et optimal;
- Un fichier nommé `cp.txt` qui contient votre code permanent en majuscule;
- Un fichier de script bash nommé `liste.sh` réalisé lors du tp1;
- Un fichier nommé `tp1.c` réalisé lors du tp1;
- Un fichier ``.gitignore``.

Bonus
 - Un fichier `YAML` nommé `tp2.yml` dans le répertoire approprié (pour avoir le bonus).

  L'usage de la commande `rm` dans votre travail est permise.  Avec de grands pouvoirs viennent de grandes responsabilités. 

  Les travaux seront corrigés sur le serveur Java. Vous devez donc vous assurer
  que votre programme fonctionne **tel que livré, sans modification** sur celui-ci.

# Barème de correction

| Critère | Sous-critère | Points |
| ------- |:------------ | ------:|
| Récupération      | récupération sans problème et dépôt privée     | 1.0 |
| Makefile          |                                                | 2.0 |
| malib.h/c         | avec la détection des inclusions multiples     | 1.0 |
| Compilation       | sans avertissement ni erreur                   | 2.0 |
| Fonctionnabilité  | tests seront lancés (comparaison binaire)      | 8.0 |
| Branche (git)     | nommée tp2 (branche de développement)          | 1.0 |
| Issues (git)      | intervention                                   | 1.0 |
| Optimal (git)     |                                                | 1.0 |
| Professionnel     | :wink: (simple et sans mystère)                | 2.0 |
| Markdown          | README.md (réflexion)                          | 1.0 |
| Bonus             | GitHub Action (YAML)                           | 1.0 |
| **Total**         |                                                | 21/20 |

FIN.
---
Guy Francoeur :copyright: édition A2020
