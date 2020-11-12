# Atelier 07: Type abstrait de données

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

 > > Pourquoi versionner vos exercices avec Git: afin de vous entraîner à utiliser le logiciel (les commandes) naturellement.
----

## 0a - Makefile

Pour tous les exercices qui suivent, vous devez ajouter au fichier `Makefile` ce qui est nécessaire pour automatiser
la production de vos exécutables (et/ou objets).  De plus, il est souhaitable de produire une cible de test pour chacun.

Si vous cherchez des noms pour vos `exécutables` et `cibles` atelier_07_1, atelier_07_2, ... etc. Il s'agit, 
de mot `atelier` ou `labo` suivi du numéro de l'atelier, et, terminant par le numéro de l'exercice.

Il est fort possible que je visite votre dépôt pour vérifier vos avancements.

À ceci, vous allez ajouter deux cibles :
+ all_atelier_test :
+ all_atelier_build :

Vous avez aussi compris que `all_atelier_test` est dépendant de `all_atelier_build`.

## 0b - valgrind

Il souhaitable d'utiliser `valgrind` pour compléter les exercices de cette séance.

+ Q1. Pourquoi utiliser valgrind ?

## 1 - Implémentation d'une pile (*stack*)

- Une pile contient des objets insérés et retirés selon le principe dernier inséré, premier sorti (last-in-first-out LIFO);
- Les objets peuvent être insérés à tout moment, mais seulement le dernier (le plus récemment inséré) peut être retiré;

```c
// stack.h

//libre à vous, faites votre implémentation
//je vais vérifier les solutions
```

+ Q1. Quelle est la différence entre les mots anglais suivants : stack vs pile vs heap ?
+ Q2. Produire un fichier d'entête (.h).
+ Q3. Produire un fichier source (.c).
+ Q4. Produire un fichier test_stack.c qui référence et utilise les fichiers `.h` et `.c`.
+ Q5. Produire un fichier Makefile pour automatiser certaines tâches.

## 2 (a et b) - Implémentation d'un Ensemble (*set*)

Vous allez créer un seul fichier par cas et y mettre tout le code nécessaire. Pas de `.h` ici.

- Un `set` contient des éléments uniques ou pas;
  + Faire la version que vous voulez, mais la version avec des éléments unique est surement plus intéressant;
- a) Des entiers numériques positifs seulement, _N*_ = nombre naturel = { 0, 1, ,2, ... };
  + votre fichier sera nommé `set_number.c`;
- b) Dans cet exercice vous allez gérer des éléments `chaine de caractères`.
  + votre fichier sera nommé `set_string.c`;

Dans cet exercice vous allez gérer des éléments en fonction du cas.
Les fonctionnalités suivantes devraient être présentées :

- ajouter
- supprimer
- recercher
- vider

## 3 - Implémentation d'une file (*queue*)

Complétez l'implémentation d'une structure de données de type "file" (en anglais *queue*) à partir des déclarations suivantes:

```c
typedef struct Queue_s {
  int capacity;  //total space used
  int size;      //number of elements
  int front;     //index of first
  int rear;      //index of last 
  int *elements; //data is here
} Queue_t;

extern Queue_t * initQ(int maxQueueSize);
extern void dequeueQ(Queue_t *Q);
extern int frontQ(Queue_t *Q);
extern void enqueueQ(Queue_t *Q,int element);
extern void deleteQ(Queue_t *Q);
```

+ Dans cet exercice, nous voulons prendre de bonnes habitudes, et tenter de réaliser un `type abstrait de données` de façon autonome.
+ Le but est de le rendre le `type abstrait`, le plus complet possible sans optimisation de code.
+ Il n'y a pas de mauvaise réponse à priori.
+ Assurez-vous de gérer correctement la mémoire (sans fuite de mémoire)!

Questions:
+ Q1.  Quelle est la difficulté que vous avez rencontrée ?
+ Q2.  Avez-vous des fuites de mémoire ou des accès illicites à des zones mémoires (*out of bounds*) ?

## 4 - Implémenter un Array Dynamique (*Vector*)

Dans cet exercice vous devez construire une structure de données capable d'accepter un nombre `limite de int` d'éléments.
Lors de la création, vous devez déterminer la capacité, exemple 2.  Lorsque cette capacité sera insuffisante, vous devrez
étendre le Vecteur.

Voici la définition et les prototypes

```c
typedef struct {
  int size;      // slots used so far
  int capacity;  // total available slots
  int *data;     // array of integers we're storing
} Vector_t;

extern void initV(Vector_t *vector, int capacity);
extern void appendV(Vector_t *vector, int value);
extern int getV(Vector_t *vector, int index);
extern void setV(Vector_t *vector, int index, int value);
static void extendV(Vector_t *vector);
extern void freeV(Vector_t *vector);
```

Questions :
+ Q1. Quelle est la difficulté que vous avez rencontrée ?
+ Q2. Avez-vous des fuites de mémoire ou des accès illicites à des zones mémoires (*out of bounds*) ?
+ Q3. Avez-vous eu recours à internet ou des exemples pour compléter l'exercice ?

### FIN.
---
##### Auteur Guy Francoeur :copyright: version A2020 
