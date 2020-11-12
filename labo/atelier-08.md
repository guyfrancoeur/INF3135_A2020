# Atelier 08: modules et maintenance

**Note** : (_facultatif_) S'il y a des questions dans ce labo, répondez y dans un fichier nommé
`./labo/reponse-labo-XX.md`. `XX` étant le numéro de l'atelier. Le fichier doit être dans un format `Markdown`. 
Utiliser un projet `privé` nommé `inf3135-a2020` pour déposer le fichier demandé.
Une branche nommée `ateliers` est nécessaire afin de ne pas mélanger tout.
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

## 0 - Le tp1 (en 2h) <sup>ou 2 ateliers</sup>

Vous allez dans cet atelier corriger et compléter le tp1.  À la fin de la période, vous devez avoir un projet
fonctionnel avec toutes les composantes nécessaires. Vous êtes capable.  Ne faire que ce qui est demandé, simplement, une étape à la fois
sans prise de tête.

Il est souhaitable pour cet atelier de travailler dans un lieu sécuritaire (dépôt, branche, répertoire) afin de ne pas détruire
vos réalisations antérieures. Voir #5.

## 1 - Makefile

Compléter et modifier le `Makefile` afin d'avoir toutes les dépendances exigées dans le TP1. Vous avez sûrement
besoin d'une cible nommée `lib`. Avez-vous une cible `tp1` ? Quelles sont les dépendances de la cible `tp1` ?
Avez-vous des commandes comme `cd` dans votre Makefile ?  Si oui il est temps de faire le ménage. Enlevez ça!
Avez-vous fait des références absolues de répertoire ?  Oui, une correction s'impose.

Afin de vous aider un peu plus, avez-vous remarqué que des commandes génèrent des sorties (messages) ou des fichiers.  Nous 
ne voulons pas de log ou output en mode livraison (PRODUCTION).  De plus certaines commandes produisent des réactions interactives.
Ceci n'est pas toujours souhaitable, veillez à ce que rien ne soit laissé au hasard. Ici hasard ça veut dire tout le monde ne travaille
pas de la même façon, vous ne programmer pas UNIQUEMENT vous.  Il y a des cas d'utilisation de make et Makefile à gérer.

### Simple, Agile, Solide
Ne rien laisser rien au hasard ne veut pas dire de se casser la tête ou se compliquer la vie, c'est le contraire.  Ça veut dire
faites ce qui est nécessaire pour gagner en confiance et avoir du succès.  Quick wins first.  Le développement par petites victoires.
Ce n'est pas utile de tout prévoir, nous sommes Agile, nous y reviendrons! Faites ce que vous êtes capable.

## 2 - Le nouveau tp1a.c

Faire des tests qui ne soient pas redondants.  C'est le temps de faire le minimum, mais avec une couverture de test maximale.
Avez-vous créé une ou des fonctions génériques capables de lancer la vérification?  Est-ce que vos tests sont-ils déterministes?
Si vous utilisez des valeurs aléatoires sûrement pas.  Utilisez-vous des boucles dans votre code et est-ce que celles-ci en font trop?
Quel est le temps pour exécuter vos tests unitaires et `tp1`? Quand nous avons des nombres tels que `float` ou `double` il est important
de prendre des précautions? Qu'avez-vous fait pour garantir que les tests unitaires soient exactement ce que vous avez en tête?  Avez-vous
des énumérations `enum` dans votre tp1.c? Si vous avez répondu non, vous faites comment pour valider rapidement de nouvelles valeurs
acceptables ? Avez-vous codé en dure des valeurs dans `tp1.c`?

### Livrable
Vous allez produire un nouveau `tp1a.c` qui cette fois sera modulaire.  Vous allez créer deux fichiers `simple.h` et `simple.c` qui
seront utilisés par le `tp1a.c`.  Dans `tp1a.c` il y aura seulement la fonction `main()`. Dans le `simple.h` les prototypes de fonctions.
Dans `simple.c` les fonctions que vous avez déjà dans une première phase.  Dans la phase deux, vous allez réduire (éléminer) les valeurs codées en dure.
Dans la phase trois, vous allez réduire (optimiser) le nombre de lignes de code et de fonctions (si possible).

## 3 - valgrind

Il souhaitable d'utiliser `valgrind` pour compléter les exercices de cette séance. Vous allez donc créer une cible nommée `leak`
afin de vérifier s'il y a une fuite de mémoire dans votre programme.

+ Q1. Pourquoi utiliser valgrind ?
+ Q2. Est-ce facile d'utiliser valgrind ?
+ Q3. Est-ce que valgrind est utile ?

## 4 - liste.sh

Réviser le fichier `liste.sh` afin de produire ce qui est demandé. Le programme, un `script` **bash**, nommé `liste.sh` devrait être 
simple et court.  Assurez-vous que c'est le cas.  Il doit traiter des informations en provenance de `stdin` et produire un résultat sur
le canal de sortie standard `stdout`.

## 5 - Git

Assurez-vous que le labo est bien fait et envoyez vos fichiers dans le gestionnaire de version.

## 6 - Évaluation

Vous avez terminé.  Hourra.  Le temps est venu d'être critique pour vous ou pour quelqu'un d'autre. 
Vous pouvez : 
- demandez à un collègue de revoir votre projet.  
- demandez au démonstrateur (qui prendra un nombre limité en fonction du temps).

La critique doit constructive et vérifiable, on évite les opinions du style j'ai entendu dire que..., mentionner les bons coups et les moins bons.

Questions :
- Q1. Êtes-vous satisfait de votre livrable ? Pourquoi ?
- Q2. Comment se nomme cet exercice de révision de code d'une autre personne ?
- Q3. Qu'avez-vous appris de cet exercice ?
- Q4. Est-ce facile de lire le code des autres ?
- Q5. Est-ce que votre projet `tp1` fonctionne mieux ?
- Q6. Voulez-vous un (1) point bonus ? Est-ce que votre binôme vous donne un point ? Pourquoi ?

### FIN.
---

##### Auteur Guy Francoeur, édition A2020
