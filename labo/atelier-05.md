# Atelier 05: Entrées et sorties et Linux

**Note** : (_facultatif_) S'il y a des questions dans ce labo, répondez y dans un fichier nommé
`./labo/reponse-labo-XX.md`. `XX` étant le numéro de l'atelier. Le fichier doit être dans un format `Markdown`. 
Utiliser un projet `privé` nommé `inf3135-a2020` pour déposer le fichier demandé.
Utiliser le même format de fichier pour tous les exercices.

##### Format du fichier Markdown
 + Atelier XX (Header 1)
 + Exercice {1..n} (H2)
 + Question {1..n} (H4)
 + S`2`.E`3`.Q`1` (strong) `est une valeur qui change bien sûr`
 + La réponse dans une section script (code block)

**Note**: Il est recommandé de versionner vos réponses aux exercices à l'aide
de Git (en ligne de commande). Un seul dépôt est amplement suffisant pour tous les laboratoires.

 > > Pourquoi versionner vos exercices avec Git: afin de
vous entraîner à utiliser le logiciel (les commandes) naturellement.
----

## 1 - Lecture, traitement et affichage formaté (bash)

Écrivez un programme qui reçoit en entrée des données en format ascii/texte
contenant une liste de villes avec certaines caractéristiques et qui affiche
sous forme de tableau formaté ces informations.

Par exemple, si le fichier d'entrée contient les lignes suivantes (ce sont
les 10 villes les plus populeuses selon la base de données GeoNames):

```
Shanghai,China,22315474
Buenos Aires,Argentina,13076300
Mumbai,India,12691836
Mexico City,Mexico,12294193
Beijing,China,11716620
Karachi,Pakistan,11624219
Istanbul,Turkey,11174257
Tianjin,China,11090314
Guangzhou,China,11071424
Delhi,India,10927986
```

alors, on obtiendrait l'affichage suivant:

```
Rang  Nom           Pays  Population
----  ---           ----  ----------
0001  Shanghai      Chin    22315474
0002  Buenos Aires  Arge    13076300
0003  Mumbai        Indi    12691836
0004  Mexico City   Mexi    12294193
0005  Beijing       Chin    11716620
0006  Karachi       Paki    11624219
0007  Istanbul      Turk    11174257
0008  Tianjin       Chin    11090314
0009  Guangzhou     Chin    11071424
0010  Delhi         Indi    10927986
```

Plus précisément, vous devez respecter les contraintes suivantes:

- Le rang doit occuper 4 colonnes en ajoutant des zéros en préfixe si nécessaire;
- Le nom de la ville doit occuper au plus 15 colonnes (il faut couper le mot s'il y a un excédent);
- Le pays doit occuper exactement 4 colonnes aussi (il faut couper sinon);
- La population doit être alignée à droite.

#### Questions
- Q1. De quelle manière allez-vous procéder? Vous allez commencer par quoi?
- Q2. Comment pourrait-on s'y prendre pour valider rapidement que la sortie de votre programme est exacte?
- Q3. Sur 10 quelle est la difficulté de cet exercice?

## 2 - Commandes d'une ligne (Linux)

À l'aide des programmes spécifiés entre parenthèses et des tubes (pipes),
écrivez une commande d'une ligne qui effectue les tâches demandées:

#### Questions
+ Q1. (man, head) Sauvegardez les 20 premières lignes du "manuel d'instructions"
   de la fonction `printf` dans un fichier nommé `man-printf.txt`.
   
+ Q2. (curl, grep) Affichez toutes les lignes qui contiennent le mot `tableau` dans
   `ce fichier`, ou un fichier `Markdown` de votre choix, disponible dans le dépôt distant.
   
+ Q3. (git log, grep, sort, uniq) Affichez tous les contributeurs d'un projet
   versionné avec git. Par exemple, j'obtiens le résultat suivant pour le
   projet [TMX](https://github.com/baylej/tmx), que j'ai utilisé par le passé:

    ```
    Author: Alex Tennant <adtennant@gmail.com>
    Author: Alex Tennant <alex.tennant@desynit.com>
    Author: Alex Tennant <alte@Alexs-MBP.home>
    Author: Alexandre Blondin Massé <alexandre.blondin.masse@gmail.com>
    Author: Bayle Jonathan <bayle.jonathan@gmail.com>
    Author: Bayle Jonathan <baylej@mrhide.fr>
    Author: RPG Hacker <markus_wall@web.de>
    Author: U-hide-hard\hide <hide@hide-hard.(none)>
    Author: baylej <baylej@mrhide.fr>
    Author: baylej <hide@hide-hard.(none)>
    Author: pedrohlc <pedro.laracampos@gmail.com>
    ```

+ Q4. (git log, grep, sed, sort, uniq) Modifiez la commande précédente pour
   obtenir la liste sans prénom et nom en double et sans le préfixe "Author:
   ". Le résultat deviendrait donc (il y en a encore des doublons, puisque
   "Bayle Jonathan" et "baylej" sont sans doute les mêmes personnes, mais
   nous ne traiterons pas ce cas) :

    ```
    Alex Tennant
    Alexandre Blondin Massé
    Bayle Jonathan
    RPG Hacker
    U-hide-hard\hide
    baylej
    pedrohlc
    ```
 
+ Q5. Vous devez créer un script `bash` nommé `creer_depot.sh` qui accepte le nom nouveau 
  projet comme paramètre.  Le même paramètre sera utilisé comme nom de `répertoire` pour héberger
  votre dépôt local.  Le script doit créer le nouveau répertoire  dans votre `$HOME`.
  Le nouveau projet sera créé dans GitHub.
  
## 3 - La calculatrice bash

Vous devez créer un script `bash` traite deux nombres et un opérateur (+-*/). Ils devront être donnés en paramètres.
Le script doit réaliser l'opération souhaitée et fournir la bonne réponse.  Créer une fonction pour faire l'opération.
Le programme `script` doit aussi retourner la réponse sous la forme d'un code de retour.  Finalement, `Le résultat est : 11` 
doit être envoyé sur le canal d'erreur. Ah oui, s'il y a une erreur d’afficher `Erreur!`.

```
$ ./calc.sh 7 + 4 
Le résultat est : 11
```
 + Q1. Comment obtenir le code de retour ?
 + Q2. Quelle est la limitation de ce programme ?
 + Q3. Comment faire pour éliminer l'affichage sorti dans le terminal ? 
    - Donnez un exemple fonctionnel de commande qui n'affiche pas de sortie à l'écran.
 + Q4. Donnez un exemple qui implique la multiplication.

## 4 - La boucle sur la chaine

Vous devez faire une fonction qui boucle sur pour les caractères de la chaine reçu en paramèttre.
Idéalement vous devez faire un programme qui n'a pas de dépendance sur des commandes du système d'exploitation.

#### Compléter
```bash
#!/bin

# sortir du programme si nous n'onvons pas 1 argument


# faire un fonction ma_fonction qui traite affiche la chaine en diagonale


# faire l'appel de la fonction
call function

# afficher le nombre de caratères de la chaine
echo 18

# sortir avec le nombre de caractere de la chaine
exit 18
```

#### Sortie

+ `bash ./chaine.sh "ceci est la chaine"


```
c
 e
  c
   i
    
     e
      s
       t
... vous avez compris
18
````

### FIN.
---
##### Auteur Guy Francoeur :copyright: version A2020 
###### Basé sur le matériel d'Alexandre Blondin Massé, Professeur
