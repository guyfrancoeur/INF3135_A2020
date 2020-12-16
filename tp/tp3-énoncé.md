# Travail pratique 3

#### Guy Francoeur :copyright: édition A2020

  L'objectif est de continuer notre initiation à la programmation avec le langage C. Cette fois nous allons
  un peu plus loin dans notre processus de création et de réflexion.  Vous devez dans ce travail livrer un
  programme de qualité irréprochable qui tient compte de critères déjà vus. Spécifiquement vous devez lire
  et produire des données sur l'entrée et la sortie standard respectivement.
  
  De plus, vos sources seront maintenues dans un gestionnaire de version/source de type git.
  
  La compréhension et la prise de décision sont aussi des objectifs à atteindre durant la mise en oeuvre,
  la réalisation, de vos travaux.
  
```  
  Le travail est à réaliser individuellement, qui veut dire seul, pas de travail d'équipe.
```

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

  Vous devez dans ce travail apporter des modifications au code existant. Vous ajouterez une fonction de gestion 
  des arguments (options) de la ligne de commande.  Vous devez créer un programme juste et robuste.  Des fichiers
  (modules) seront utilisés pour garder un code propre et lisible.  L'utilisation de toutes les notions vue cette
  année est souhaitable. Finalement, le langage dans les mains d'un programmeur tel que vous peut produire, doit
  produire, un exécutable performant.  Votre exécutable sera soumis à un stress incroyable. 😜
  
  Ce que vous devez faire : 
   - Compter, maintenir et afficher le nombre transactions selon les options demandées au lancement du logiciel.
  
  Ce travail est une modification du `tp2` vous devez donc modifier ce que vous avez déjà. Vous allez donc produire le `tp3.c`
  à partir des sources du `tp2.c`. Lorsque vous serez prêt, compilez les sources afin de produire un exécutable nommé `tp3`. (merci PO)
  
  Le programme exécutable peut être lancé en ligne de commande avec différentes syntaxes :

```bash
# sans option
$ ./tp3
$ cat file.dat | ./tp3
$ head -n 100 file.txt| tail -n 25 | ./tp3

# avec option(s) de la ligne de commande (-d détaillé, -s sommaire, -t tranquille -i invalide)
$ ./tp3 -s -d -i
$ ./tp3 -s
$ ./tp3 -t
...
```

#### Vous devez réaliser le travail selon les contraintes suivantes:

  Ce que nous devons retrouver dans le fichier `tp3.c` : 
   - uniquement le code de la fonction `int main(int argc, char *argv[])`.
   - ne doit pas contenir plus de 50 lignes, une instruction par ligne.
   
>  Ce que vous devez retrouver dans le fichier `outil3.h` et `outil3.c`:
>   - Ce module est indépendant;
>     + Aucune dépendance sur des librairies personnelles ou non standard au langage C;
>   - Le code source de la fonction `float distance(int _signal, int _power)`;
>     + La fonction gère le calcul de la distance en mètres;
>   - Le code source de la fonction `int cmd(...)`;
>     + La fonction gère les arguments de la ligne de commande;
>   - La MACRO `_OUTIL3_H_` doit exister pour la détection des inclusions multiple;
>   - Limiter le code source à 99 lignes ou moins, une instruction par ligne.
   
  Ce que nous devons retrouver dans le fichier `malib.h` et `malib.c` : 
> - Limiter le code source à 199 lignes et moins, une instruction par ligne.
- Profitez de la période de questions en classe pour vos questions;
- Votre travail sera réalisé et livré dans le dépôt distant toujours **privé**;
- Les fichiers d'entête :
  + standard sont tous permis;
  + `<unistd.h>`, `<windows.h>` ne sont pas autorisé;
- Vous devez utiliser les fichiers `tcv.h` et `tcv.o` qui sont fournis :
  + dans `tp3.zip` ou `tp2.zip` ou `tp1.zip`;
    + Votre Makefile est surement la bonne place pour gérer cela (simplement svp);
- Contributions Q&R
  + Seront faites dans le forum de discussion GitHub section *Issues*;
  + Aucun commentaire personnel ou politique ne sera toléré;
  + Vous devez contribuer de façon professionnelle;
  + Le nombre de contributions est limité à trois, questions et/ou réponses;
  + Une demande de solution, (validation ou réponse), 50% de la note sera amputée, exemple :
    + Comment devrais-je faire ... ?;
    + Je voudrais valider ... ?; `(je vais surement évaluer votre tp, soyez patient)` 😂
    + Est-ce que je devrais ... ?;
    + J'ai de la misère ...; contacter moi directement je vais prendre une décision en fonction du temps;
    + ... une demande de solution déguisée en demande d'aide ne sera surement pas une bonne idée;
    + ... une demande de compréhension déguisée en question n'est surement pas du travail individuel;
- Branche git :
  + Les fichiers seront maintenus dans la branche nommée `tp3`;
  + Aucun fichier dans la branche nommé `main` (branche par défaut);
  + La branche `main` est pour les rétroactions et commentaires de l'enseignant;
- Ne garder que les fichiers essentiels dans votre projet (dépôt distant);
- La gestion des répertoires :
  + doit se faire de façon explicite **à partir de votre répertoire de travail**;
  + votre répertoire de travail étant : `./`;
+ La note zéro est attribuée si :
  + vous utilisez `~` ou `~/`;
  + vous utilisez `..` avec la commande `cd`;
  + vous utilisez `..` ou `*` avec la commande `rm`;
  + vous descendez, dans la structure, en deçà de votre répertoire de travail;
> + Vous ne pouvez pas utilser les commandes suivantes dans le `Makefile` ou dans un script appelé par le `Makefile` :
>   - `cd`, `mv`
>   - `mkdir` dans la cible `lib`;
>   - `rm` dans les autres cibles que `clean`;
- Idéalement :
  + un code simple est facile à travailler, donc aucun code ésotérique;
  + vous devez produire du code juste, donc faites ce que vous connaissez;
  + vous devez produire du code robuste, donc débarrassez-vous du code instable;
  + vous devez produire un `Makefile` qui n'a pas d'effet de bord ou :
    + qui est sans effet secondaire;
    + qui n'a pas un comportement hasardeux;
>    + qui n'appel pas des scripts;
  + n'attendez pas à la dernière minute, cela risque de devenir stressant.

Définition :
 + ésotérique : Se dit d'un mode d'expression, d'une œuvre qui n'est compréhensible que des initiés;

Synonyme :
 + mystérieux : Qui est incompréhensible ou inexplicable;

Source : Larousse FR

 
### Rôle de votre programme

 Le rôle de votre programme est de lire des transactions (déjà fait durant le tp2).  Le `tp3` ajoute une fonctionnalité qui compte
 de nombre de lignes lues et selon le cas affichera les informations recueillies. Les options suivantes doivent être gérées :
 
 
Voici les cas et les traitements en fonction des options : 
 - option `-i` `information invalide`
   + Lorsqu'un code de transaction n'est reconnu;
   + Lorsque le timestamp est inférieur au temps précédent;
 - option `-d` `information détaillée`
   + Le nombre de transactions pour chacun des types de transactions;
 - option `-s` `information sommaire`
   + Le nombre total de transactions valides;
   + Le nombre total de transactions reçues;
 - option `-t` `mode tranquille`
   + Le mode tranquille n'affiche pas transaction en sortie;

### Ce qui doit être produit

#### exemple avec les options `-t -d -s -i`
```
version #: 0.0.1008
information invalide
  trx non reconnue : 10
  trx avec ts non sequentiel : 5
information detaillee
  trx 01 : 4
  trx 02 : 3
  trx 03 : 4
  trx 04 : 4
  trx 05 : 10
  le dernier ts lu : 1564
information sommaire
  nbr trx valides : 25
  nbr trx (total) : 40
```
NOTE : il n'y a pas de caractères accentués. Le format de sortie est important cette fois.

## Makefile

  Il est obligatoire d'inclure un fichier `Makefile` dans votre projet pour faciliter la compilation et
  les autres actions requises. Celui-ci doit minimalement offrir les services suivants :
  
- Le Makefile
  + La commande `make tp3` est commande pour construire l'exécutable `tp3`;
  + La commande `make` employée seule devra exécuter la cible `default` qui est dépendante de tp3;

- Lorsqu'on entre `make clean`, le projet revient dans son état d'origine, c'est-à-dire
  son état lors de la récupération initiale;

- Lorsqu'on entre `make lib`, le téléchargement du fichier 
  https://github.com/guyfrancoeur/INF3135_A2020/raw/master/tp/tp3.zip
  se fait de façon automatique dans un répertoire (./data). Par la suite, la décompression est nécessaire;

- Les programmes seront compilés et évalués avec les options suivant `-Wall -Werrorvla -pedantic -std=c11`;

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
+ Votre projet ne doit pas contenir de fichiers *.guy;

## README.md

  Votre projet doit contenir un fichier nommé `README.md` qui décrit le contenu et qui **respecte le
  format Markdown**. Il doit minimalement contenir les informations ci-bas :
  
  Les badges ajoutés à votre `README.md` seront en mis à jour par votre fichier `YAML`;

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

  La totalité de votre travail doit être remise au plus tard le 20 décembre 2020 23h59 ET (heure du Québec).
  Après cette date, une pénalité de **10 points par jour** de retard sera appliquée.

  La remise se fait **obligatoirement** par l'intermédiaire de la plateforme `Github https://github.com/` 
  
  **Aucune remise par courriel ne sera acceptée** (le travail sera considéré comme non remis).

  Le nom de votre dépôt doit être `inf3135-a2020` (en minuscules). Vous devez ajouter l'utilisateur
  `guyfrancoeur` comme collaborateur. Ceci permettra de récupérer et possiblement de déposer quelques commentaires
  (fichiers) dans votre projet.

  Votre projet devrait minimalement contenir, à la racine du dépôt, les fichiers de type `Unix/Linux` et `ascii` suivants :

- Un fichier `tp3.c` contenant votre fonction `main`;
- Les fichiers `malib.c` et `malib.h`; 
> > - Les fichiers `outil3.h` et `outil3.c` (ajout pour bien modulariser);
> > - Un fichier YAML de test de compilation test-c.yml;
> > - Un fichier YAML de test fonctionnel test-f.yml; 
- Un fichier `README.md` selon le format proposé;
- Un fichier nommé `Makefile` complet et optimal;
- Un fichier nommé `cp.txt` avec votre code permanent en majuscule;
- Un fichier `.gitignore`.

  L'usage de la commande `rm` dans votre travail est permise.  Avec de grands pouvoirs viennent de grandes responsabilités. 

  Les travaux seront corrigés sur le serveur Java. Vous devez donc vous assurer
  que votre programme fonctionne **tel que livré, sans modification** sur celui-ci.
  
# Barème de correction

| Critère | Sous-critère | Points |
| ------- |:------------ | ------:|
| Exigences         | outil3.c, malib.c, ...                                 | 4.0   |
| Compilation       |                                                        | 1.0   |
| Makefile          | plusieurs critères seront évalués                      | 1.0   |
| test-c.yml        | produire le résultat dans compilation.md               | 1.0   |
| test-f.yml        | résultat de tests dans fonctionnel.md                  | 1.0   |
| badges yaml       | mettre les deux badges dans README.md                  | 2.0   |
| Fonctionnabilité  | tests seront lancés (comparaison binaire)                 | 7.0   |
| Branche (git)     | nommée tp3 (pour votre dev), branche défaut (main) vide   | 1.0   |
| Optimal (git)     | on vise un dépôt parfait                                  | 1.0   |
| performance       | performance (bien)                                        | 1.0   |
| Bonus             | performance (optimal)                                     | 1.0   |
| **Total**         |                                                           | 21/20 |

FIN.
---
Guy Francoeur :copyright: édition A2020
