# Atelier 06: Matrices, structures, unions, types énumératifs

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

## 0 - Makefile

Pour tous les exercices qui suivent, vous devez ajouter au fichier `Makefile` ce qui est nécessaire pour automatiser
la production de vos exécutables (et/ou objets).  De plus, il est souhaitable de produire une cible de test pour chacun.

Si vous cherchez des noms pour vos `exécutables` et `cibles` atelier_05_1, atelier_05_2, ... etc. Il s'agit, 
de mot `atelier` ou `labo` suivi du numéro de l'atelier, et, terminant par le numéro de l'exercice.

Il est fort possible que je visite votre dépôt pour vérifier vos avancements.

À ceci, vous allez ajouter deux cibles :
+ all_atelier_test :
+ all_atelier_build :

Vous avez aussi compris que `all_atelier_test` est dépendant de `all_atelier_build`.

## 1 - Afficher une matrice

Écrivez une fonction C permettant d'afficher le contenu d'une matrice d'entiers
de dimensions 3 par 3.

Rappelons qu'on peut initialiser une matrice de la façon suivante
```c
int matrice[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
```
Bien sûr, vous trouverez un moyen d'éliminer les valeurs magiques spécifiant la
taille de la matrice. L'en-tête de votre fonction devrait ressembler à
```c
void afficherMatrice(int matrice[3][3]);
```

Grâce à votre fonction, la matrice sera affichée comme suit:
```
1 2 3
4 5 6
7 8 9
```

## 2a - Addition de matrices (entières)

Écrivez une fonction C permettant d'additionner deux matrices.  N'hésitez pas à
réutiliser la fonction de l'exercice précédent pour afficher le résultat.
L'en-tête de votre fonction devrait ressembler à
```c
void additionnerMatrices(int matrice1[3][3],
                         int matrice2[3][3],
                         int resultat[3][3]);
```

Voici un exemple de sortie attendue:

```
1 2 3
3 2 1
1 2 3
+
4 3 2
2 3 4
4 3 2
=
5 5 5
5 5 5
5 5 5
```

## 2b - Opération sur les matrices (ascii)

Écrire un programme qui va prendre les chaînes de caractères contenus dans la section `données` 
et qui fera une opération à l'aide de fonctions différentes :
  + la moyenne `void avg( ... );`
  + l'addition `void add( ... );`
  
Veuillez prendre note que les caratères ASCII en bas de 32 ne sont pas des caratères visibles ils
sont dit binaires.  Vous ne pouvez donc pas les afficher. Veuillez les convertir en un espace ASCII = 32.
Ne tentez pas d'afficher le caratères 0 (ou NULL) non plus. A quoi sert-il déjà ?

#### Données

Les matrices (ou tables de caractères) sont les suivantes :

`mat1`
~~~~
Les Canadiens sont une equipe de hockey
Les Nordiques sont de Quebec
Ils ne FONT pas de politique
Super moi non plus
Hourra!
~~~~

`mat2`
~~~~
Je dors ZZZ zzz
Le cours de C est le meilleur
J'aime apprendre
Nous avons tous le temps pour un bon repas
UQAM est mon univers
~~~~

Vous devez définir un nouveau type pour `typer` (définir le domaine) vos matrices `mat1`, `mat2` et `matresultat` 

```c
//déclaration et réservation de l'espace mémoire
... mat1[5,50];
... mat2[5,50];
... matresultat[5,50];
```

Vous devez afficher dans la sortie standard le caractère en plus de la valeur ascii. ex `9: 57`.
Vous devez afficher le caractère de la matrice résultat dans `stderr`.
Ecrire votre programme en petit module.

Exécuter votre programme en ligne de commande et rediriger `stdout` dans `out.txt` et `stderr` dans `err.txt`;

#### Questions

+ Q1. Quel est votre prototype de fonction pour add() ?
+ Q2. Ave-vous le même pour avg ?
+ Q3. Quels problèmes avez-vous rencontrés ?
+ Q4. Quelles notions académiques du langage C étaient nécessaires ?
+ Q5. Avez-vous utilisé `stdin` ou des fichiers pour charger `mat1` et `mat2` ?
+ Q6. Combien de fonctions avez-vous ?
+ Q7. Quel est le temps requis pour accomplir le travail ?

## 3 - Structures

Considérez les déclarations suivantes :

```c
struct Point_s { // Un point en 2D
    double x;  // Sa coordonnée x
    double y;  // Sa coordonnée y
};

struct Segment_s {
    struct Point p1;
    struct Point p2;
};

struct Triangle_s {
    struct Point points[3];
};
```

1. Écrivez une fonction
    ```c
    void initialiserSegment(struct Segment_s *segment, double x1, double y1, double x2, double y2);
    ```
   qui crée un segment dont les extrémités sont les points `(x1,y1)` et `(x2,y2)`.

2. Écrivez une fonction
    ```c
    double longueurSegment(const struct Segment_s *segment);
    ```
   qui retourne la longueur de `segment`.

3. Écrivez une fonction
    ```c
    void initialiserTriangle(struct Triangle_s *triangle,
                             double x1, double y1,
                             double x2, double y2,
                             double x3, double y3);
    ```
   qui crée un triangle dont les points sont `(x1,y1)`, `(x2,y2)` et `(x3,y3)`.

4. Écrivez une fonction
    ```c
    double perimetreTriangle(const struct Triangle_s *triangle);
    ```
   qui retourne le périmètre de `triangle`, c'est-à-dire la somme des longueurs
   de ses côtés. Bien qu'il soit possible de faire le calcul directement,
   faites appel à la fonction `longueurSegment` que vous avez implémentée plus tôt.

## 4 - Unions et types énumératifs

Considérons la structure de données suivante :

```c
enum Nombre_e {
    INT, FLOAT, DOUBLE
};

typedef struct {           // Un nombre
    enum Nombre_e type;  // Le type de nombre
    union {
        int i;
        float f;
        double d;
    } valeur;              // La valeur
} Nombre_t;
```

Donnez l'implémentation d'une fonction dont la signature est
```c
Nombre_t max(Nombre_t a, Nombre_t b);
```
et qui retourne le maximum entre les nombres `a` et `b`, peu importe leur type.

---

## 5 - Unions (en action)

Vous devez implémenter le code suivant dans un .h et faire un programme qui l'inclura en plus de répondre aux questions qui suivent: 

~~~~
union L64 {
  unsigned long n;
  struct {
    unsigned int lo;
    unsigned int hi;
  };
};
~~~~

Une fois le .h fini vous aller écrire un .c qui fera les actions suivantes :
  + mettre une valeur (ex 12345) dans `n`
  + afficher lo et hi
  + mettre une plus grande valeur (ex ULONG_MAX - 10) dans n  ou `n = ~n; n -= 10;`
  + afficher lo et hi

#### Questions
+ Q1. Que se passe-t-il à la compilation ?
+ Q2. Quelles sont les valeurs de lo et hi (première fois) ?
+ Q3. Quelles sont les valeurs de lo et hi (deuxième fois) ?
+ Q4. Expliquer dans vos mots little endian. Une recherche est nécessaire.
+ Q5. Expliquer dans vos mots big endian (vous pouvez le comparer).

### FIN.
---
##### Auteur Guy Francoeur :copyright: version A2020 
###### Basé sur le matériel d'Alexandre Blondin Massé, Professeur
