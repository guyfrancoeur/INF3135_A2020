# Démonstration atelier 03

### Mise en garde
 + Le code ou les exemples sont purement académiques, ils peuvent contenir des erreurs.
 + Ils ne sont pas destinés pour un usage commercial. La prudence est de mise.

#### Vous devez toujours tenter vos propres expériences afin d'en avoir le coeur net.

### Compilation

+ `gcc -std=c11 -Werror=vla -Wall atelier-03.c`

### Jeu d'essai

+ `$ ./a.out -d`
+ `$ ./a.out -d DEC`
+ `$ ./a.out -d DEC -c`
+ `$ ./a.out -d DEC -c DEIF`
+ `$ ./a.out -d DEC -c DEIF -v`
+ `$ ./a.out -d DEC -c DEIF -v 1`


### Programme C
```c
//atelier 03 (demo)
#include <string.h> //strcmp
#include <stdlib.h> //atol
#include <stdio.h>  //printf
#include <stdbool.h> //bool

//int strcmp ( const char * str1, const char * str2 ); //return 0 veut dire egal
//long int strtol (const char* str, char** endptr, int base);

int check_d(int _nbr_arguments, char** _arguments,  int _position) {
  if (strcmp(_arguments[_position], "-d") == 0) {
    // verifier que i+1 existe
    if ((_position + 1) < _nbr_arguments) {
      // recuperer la valeur de l'argument
      char* valeur = _arguments[_position + 1];
      // comparer avec les valeurs de reference
      if (strcmp(valeur, "INC") == 0 || strcmp(valeur, "DEC") == 0) {
        return 0;
      }
    }
    return 3;
  }
  return 0;
}

int cmdline(int _nbr_arguments, char** _arguments) {
  bool has_arg_c = false;

  for (int i = 1; i != _nbr_arguments; i+=2) {

    int dOk=check_d(_nbr_arguments, _arguments, i);

    if (dOk != 0) return dOk;

    if (!strcmp(_arguments[i], "-c")) {
      if ((i + 1) < _nbr_arguments) {
        has_arg_c = true;
      } else { return 1; }
    }
    else if (!strcmp(_arguments[i], "-v")) {
      if ((i + 1) < _nbr_arguments) {
        // devrait aussi fonctionner pour le cas avec 0
        long entier = atol(_arguments[i + 1]);
        if (!entier) {
          return 2;
        }
      } else { return 2; }
    }
  }
  if (!has_arg_c) return 1;
  return 0;
}

unsigned int trouverElement(const double* tableau, unsigned int taille, double element) {
  for (int i = 0; i != taille; ++i) {
    if (tableau[i] == element) {
      return i+1;
    }
  }
  return -1;
}

int main(int argc, char** argv)
{
  int retour = cmdline(argc, argv);
  printf("%d\n\n", retour);
  double tableau[] = { 3000, 21, 5, 4, 34, 8 };
  int resultat = trouverElement(tableau, 6, 21);
  printf("%d\n\n", resultat);
}
```

#### FIN.
---
révision A2020
