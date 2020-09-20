# Séance 2: Programmer en C, Makefile, Git
----
**Note** : (_facultatif_) S'il y a des questions dans ce labo, répondez y dans un fichier nommé
`./labo/reponse-labo-XX.md`. `XX` étant le numéro de séance. Le fichier doit être dans un format `Markdown`. 
Utiliser un projet `privé` nommé `inf3135-a2020` pour déposer le fichier demandé.
Utiliser le même format de fichier pour tous les exercices.

##### Format du fichier Markdown
 + Séance 01 (Header 1)
 + Exercice {1..n} (H2)
 + Question {1..n} (H4)
 + S`2`.E`3`.Q`1` (strong) `est une valeur qui change bien sûr`
 + La réponse dans une section script (code block)

**Note**: Il est recommandé de versionner vos réponses aux exercices à l'aide
de Git (en ligne de commande). Un seul dépôt est amplement suffisant pour tous les laboratoires.

 > > Pourquoi versionner vos exercices avec Git: afin de
vous entraîner à utiliser le logiciel (les commandes) naturellement.
----

## 0 - Préparation avant de commencer

Il serait important de penser à une stratégie de répertoire afin de garder mes fichiers
dans une structure adéquate.  Des répertoires sont nécessaires pour ne pas mettre tout au même
endroit.  Les commandes : `cd`, `mkdir`, `ls` et `rm` sont utiles pour réaliser le travail.

~~~~
$ cd
$ mkdir inf3135 ; cd inf313*
$ mkdir seance-02
$ cd seance-02/
~~~~

## 1 - Gestion des arguments de la fonction main (partie 1)

- S'il n'est pas déjà créé, créez ou modifiez un programme de type *Hello, world!* nommé `hello.c`;
- Votre programme devra accepter le premier argument et l'afficher comme ceci : `Hello, Guy F.`;
- `Guy F.` est l'argument qui est fourni au programme;

+ Un autre exemple pour exécuter votre programme :
    ```shell
    $ ./hello Guy
    ```

+ Compilez votre programme en une seule étape :
  - la commande suivante produit un exécutable nommé `a.out`.
    ```shell
    $ gcc hello.c
    ```

+ Il est aussi possible que cet exécutable ait un nom que vous choisissez, par exemple :
    ```shell
    $ gcc hello.c -o hello
    ```

+ Ensuite, produire le programme en deux étapes :
  -  Le fichier `hello.o` sera produit avec :
    ```shell
    $ gcc -c hello.c
    ```
  - Notez que la commande suivante produit exactement le même résultat :
    ```shell
    $ gcc -c hello.c -o hello.o
    ```
 
- Complétez la deuxième étape en entrant la commande :
    ```shell
    $ gcc hello.o -o hello
    ```
+ Ouvrez-le `hello.o` avec `nano` ou affichez-le avec `cat` pour vérifier son contenu.

Questions :
 - Q1. Que retrouvez-vous dans le fichier `hello.o`?
 - Q2. A quoi correspondent les deux étapes de compilation vu ci-haut ?
 - Q3. Quel est l'option pour compiler avec les instructions de débogage ? (mode `debug`)
 - Q4. Est-ce que le contenu du fichier `.o` est lisible ?

## 2 - Makefile pour automatiser (la compilation...)

- Finalement, créez un fichier `Makefile` qui automatise les étapes de compilation. 
  + Ajoutez à ce fichier Makefile une cible `clean` qui supprime le fichier `.o` ainsi que l'exécutable.

- Versionnez l'état actuel de votre projet avec Git.

Questions :
 - Q1. Votre `Makefile` fonctionne-t-il, et quelle commande le prouve ?
 - Q2. Est-ce que le format (la structure) du fichier est important ?
 - Q3. Puis-je changer le nom du fichier Makefile ?
 - Q4. Quelle est la commande pour créer l'exécutable ?
 - Q5. Quelle est la commande pour supprimer les fichiers ?

## 3 - Gestion des arguments de la fonction main (partie 2)

- Vérifiez bien qu'un seul argument a été passé. S'il n'y en a aucun ou s'il y
  en a plus d'un, affichez un message d'erreur :
    ```shell
    Usage: argv[0] "Votre nom" 
    Erreur : Un seul argument permis.
    ```
  Versionnez l'état actuel de votre projet avec Git.

Questions:
 - Q1. Décrire, dans vos mots, à quoi correspond le premier argument (dans le programme `hello.c` ou tout autre programme) ?

## 4 - Fonctions

Vous devez d'abord faire les prototypes, puis ensuite implémentez en C chacune des fonctions suivantes :

- Une fonction `boucleAvant()` qui fait un `for(int i=0;i<x;++i)` avec un printf de `i`;
- Une fonction `boucleApres()` qui fait un `for(int j=0;j<x;j++)` avec un printf de `j`;
- Une fonction `racineCarreEntiere()` qui retourne la portion entière de la racine Carré d'un entier naturel;
- Une fonction `lignecommande()` capable de traiter des arguments en provenance de la ligne de commande;
- Une fonction `somme` qui calcule la somme des éléments présents dans un tableau d'entiers;
- Une fonction `estTrie` qui retourne vrai si et seulement si les éléments d'un
  tableau d'entiers sont en ordre croissant;
- Une fonction `elementPlusFrequent` qui calcule l'élément qui est répété le
  plus souvent dans un tableau d'entiers;
- Une fonction `nombreOccurrences` qui calcule le nombre de fois qu'un
  caractère donné apparaît dans une chaîne;

Un retour sur les entiers naturels:

N = { 0, 1, 2, ..., &infin; }

&infin; = 2 <sup>64</sup> - 1

Questions :
 - Q1. Quelle fonction est plus rapide entre `boucleAvant()` et `boucleApres()`? 
 - Q2. Est-ce que les résultats sont identiques?
 - Q3. Quelle est la racine de 4294967296? temps requis?
 - Q4. Quelle est la racine de 17179869184? temps requis?

N'oubliez pas d'inclure dans votre fonction main quelques tests qui démontrent
que votre fonction est correctement implémentée. Chaque fois que vous avez
terminé d'implémenter une fonction, n'oubliez pas de versionner votre projet à
l'aide de Git.

## 5 - Ignorer des fichiers avec Git

Il est crucial
d'[ignorer](https://git-scm.com/book/fr/v2/Les-bases-de-Git-Enregistrer-des-modifications-dans-le-d%C3%A9p%C3%B4t#_ignoring)
les fichiers inutiles lorsqu'on suit l'évolution d'un projet avec Git,
notamment les fichiers binaires (pas tous, mais beaucoup d'entre eux), les
fichiers temporaires, les fichiers de configuration individuelle, etc.

Dans le cours, vous devrez en particulier ignorer les fichiers avec les
extensions `.o` et `.out` qui sont générés par le compilateur *gcc*. Les
fichiers et répertoires à ignorer sont spécifiés dans le fichier ".gitignore" à
l'aide d'une expression régulière.

Par exemple, créez un fichier nommé ".gitignore" à la racine de votre projet.

```shell
$ nano .gitignore
```

Modifier le fichier pour y ajouter les choses que vous ne voulez pas gérer dans
le gestionnaire de version (une expression par ligne). Par exemple, vous pourriez
inclure les lignes suivantes:

```shell
# Fichiers C
*.o
*.out

# Fichiers Vim
*.swo
*.swp

# Fichiers temporaires
*.old
*.tmp
*.bak

# Exemple de répertoire à ignorer
bin/
build/
```

**Note:** Il n'est pas nécessaire de compléter les exercices suivants dans
cette séance, mais il est encouragé de venir les consulter chaque fois que vous
souhaitez apporter des modifications à vos *commits*

---

## 6 - Annuler des modifications avec Git

Il y a plusieurs façons d'annuler des modifications dans Git:

* En modifiant le dernier *commit* grâce à la commande `git commit --amend`
* En retirant des fichiers du *commit* en cours de construction (*unstaging*)
  grâce à la commande `git reset HEAD nomFichier`
* En annulant toutes les modifications dans un fichier depuis le dernier
  *commit*.

D'autres exemples sont [fournis dans la documentation](https://git-scm.com/book/fr/v2/Les-bases-de-Git-Annuler-des-actions).

## 7 - Modifier le dernier commit

La modification de *commit* se fait en deux étapes:

1. Ajouter des modifications avec `git add`;
2. Lancer la commande `git commit --amend`.

Par exemple, supposons qu'on crée un nouveau fichier `LICENCE.md` puis qu'on
souhaite l'enregistrer:
```shell
$ vim LICENCE.md
$ git add LICENCE.md
$ git commit -m "Ajout de LICENCE.md"
```

Ô malheur! Nous avons fait une erreur, puisqu'en anglais, le fichier devrait
plutôt s'appeler `LICENSE.md` (avec un `S`).

Pas de problème! Il suffit de renommer le fichier comme il se doit puis de
modifier le dernier *commit* pour y ajouter les modifications:

```shell
$ mv LICENCE.md LICENSE.md
$ git rm LICENCE.md # on confirme la suppression du fichier erroné
$ git add LICENSE.md # on versionne le nouveau fichier
$ git commit --amend
```

Et voilà, si on regarde le contenu du dernier *commit*, on peut voir que le
fichier créé s'apelle `LICENSE.md` comme si l'erreur ne s'était jamais
produite.

**Mise en garde:**: Si vous travaillez à plusieurs personnes, il ne faut jamais
modifier un *commit* qui a déjà été poussé sur le dépôt distant. Des
collaborateurs pourraient déjà l'avoir récupéré (via la commande `git pull`) et
s'en servir, ce qui aura pour effet de rendre vos historiques incompatibles (et
donc impossibles à fusionner).

### Annuler une modification ajoutée par erreur au prochain commit

Il est possible de retirer une modification ajoutée à un *commit* par
accident.  Par exemple, supposons que nous incluions par erreur le ficher
`a.out` au prochain *commit*.

```shell
$ git add a.out
$ git status
```

Clairement, ce n'est pas une bonne idée puisqu'il s'agit d'un fichier généré et
donc il ne devrait pas être partagé (il sera probablement inutilisable par les
autres collaborateurs et polluera inutilement le contenu du dépôt).

Vous pouvez annuler cet ajout erroné à l'aide de la commande

```shell
$ git reset HEAD a.out
```

(`HEAD` est une "constante" spéciale qui pointe vers l'état actuel de votre
projet avant modifications non enregistrées.)

### Annuler des modifications apportées à un fichier

Commencez par faire quelques modifications dans votre `README.md`.

```shell
$ nano README.md # modifiez ou supprimez quelques lignes
```

Nous souhaitons maintenant annuler les modifications apportées au fichier en le
remettant dans l'état où il était au dernier *commit*. Il est possible de récupérer le fichier
qui est dans le dépôt distant avec la commande suivante :

```shell
$ git checkout -- README.md
```

## 8 - Commandes de base de Git

- Familiarisez avec d'autres commandes de base de Git :
    - `git status` pour voir l'état de votre projet;
    - `git diff` avant de faire `git add` pour visualiser les modifications apportées;
    - `git commit -m` est un raccourci permettant de faire un *commit* tout en écrivant directement le message;
    - `git commit -a` permet de faire un *commit* en incluant tous les fichiers modifiés;
    - `git reset --hard` permet d'annuler les modifications qui n'ont pas encore été incluses dans un *commit*. **Attention**, cette opération est irréversible;
    - `git log` pour voir l'historique du projet;
    - `git checkout` pour naviguer dans l'historique du projet;
    - `git show` pour visualiser le "contenu" d'un *commit*;
    - `git remote` pour lister tous les dépôts distants. Si vous êtes synchronisés avec GitLab, vous devriez voir apparaître seulement`origin`;
    - `git remote -v` donne la liste des dépôts distants avec plus d'informations (notamment l'URL où il se trouve).

Questions :
 + Q1. Quel avantage permet la commande `git commit -a` ?
 + Q2. Que fait la commande `git mv` ?
 + Q3. Que fait la commande `git branch` ?
 + Q4. Que fait la commande `git checkout` concrètement ?
 + Q5. Quelle commande permet de m'aider lorsque je pers la mémoire et m'aide à la retrouver ?

### FIN.
---
##### Auteur Guy Francoeur :copyright: version A2020 
###### Basé sur le matériel d'Alexandre Blondin Massé, Professeur
