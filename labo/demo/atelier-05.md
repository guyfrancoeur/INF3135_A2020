# Démonstration atelier 05

### Mise en garde
 + Le code ou les exemples sont purement académiques, ils peuvent contenir des erreurs.
 + Ils ne sont pas destinés pour un usage commercial. La prudence est de mise.

#### Vous devez toujours tenter vos propres expériences afin d'en avoir le coeur net.

### Référence
 + notes de cours

### Execice 1 - Lecture, traitement et affichage formaté (bash)

```
#!/bin/bash

# formate une colonne selon
# - taille min/max
# - caractere de padding (gauche ou droite)
function formatage_colonne () {
  chaine="$1"
  taille_colonne=$2
  longueur_min=$3
  padding="$4"
  before_after=$5
  if [ ${#chaine} -gt $taille_colonne ]; then
    # tester si $col2 > 15, si oui couper, sinon,
    chaine=${chaine::taille_colonne}
  else
    while [ ${#chaine} -lt $taille_colonne ]
    do
      if [ $before_after -gt 0 ]; then
        chaine="$chaine""$padding"
        # padder avec des espaces pour atteindre 15 characteres
      else
        chaine="$padding""$chaine"
      fi
    done
  fi
  echo "$chaine"
}

# recuperer l'argument du script (ici un nom de fichier est attendu)
input="$1"
# verifie que le fichier existe bien (-f)
if [ -f "$input" ]; then
  # afficher le header
  echo " Rang  Nom           Pays  Population"
  echo " ----  ---           ----  ----------"
  cursor=1
  # lire les lignes du fichier (while...done)
  while IFS="" read -r line || [ -n "$line" ]
  do
    # lire chaque colonne de la ligne dans un tebleau (csv_line)
    IFS=',' read -ra csv_line <<< "$line"

    # completer le prefixe avec des 0 (taille 4)
    col0=$(formatage_colonne "$cursor" 4 4 "0" 0)
    # padder avec espaces a droite ou couper si > 15
    col1=$(formatage_colonne "${csv_line[0]}" 15 15 " " 1)
    # idem mais avec 4
    col2=$(formatage_colonne "${csv_line[1]}" 4 4 " " 1)
    # aligner a droite avec 10 caracteres (meme principe, mais padding a gauche)
    col3=$(formatage_colonne "${csv_line[2]}" 10 10 " " 0)
    echo " $col0  $col1           $col2  $col3"
    cursor=$((cursor+1))
  done < "$input"
fi
```

### Exercice 2
- Q.1 : `$` `man printf | head -n20 > man-printf.txt`
- Q.2 : `$` `curl https://raw.githubusercontent.com/guyfrancoeur/INF3135_A2020/master/labo/atelier-05.md | grep chaine`
- Q.3 : `$` `git log | grep 'Author' | uniq`
- Q.4 : `$` `git log | grep 'Author' | uniq | sed 's/Author: //g' | sed 's/<.*>//g'`


### Facultatif

- Traduction de l'execice 1 en C

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
* Modifie le string selon la taille demandée. 
* Coupe le string si trop grand, rajoute des espaces si trop petit.
*
* @param char* : le string à formatter
* @param taille : la taille à respecter
* @param inverse : true -> ajoute les espaces/coupe à la fin du mot 
* false -> ajoute les espaces/coupe au début du mot
*/
char* formatterMotTailleFixe(char* pointeur, int taille, bool inverse){

  char* mot = malloc(taille * sizeof(char));
  *(mot + taille -1) = '\0';
  bool fin = false;

  if(!inverse){
    for(int i = 0 ; i < taille -1 ; i++){
      if(*(pointeur + i) == '\0'){
        fin = true;
      } 

      if(!fin){
        *(mot + i) = *(pointeur + i);
      } else {
        *(mot + i) = ' ';
      }
    }
  } else {
    int decalage = taille - strlen(pointeur);
    int j = 0;

    for(int i = 0 ; i < taille -1; i++){
      if(decalage != 0){
        *(mot + i) = ' ';
        decalage --;
      } else {
        *(mot + i) = *(pointeur + j);
        j++;
      }
    }
  }
  return mot;
}

int main(int argc, char *argv[]){

  FILE* fichier = fopen(argv[1], "r");

  if(fichier){
    char* ligne = malloc(sizeof(char) * 100);
    const char* delimiteur = ",";
    int index = 1;
    printf("Rang  Nom           Pays  Population\n");
    printf("----  ---           ----  ----------\n");

    while(fgets(ligne, 100, fichier)){
      printf("%04d  ", index);

      //ville
      char* pointeur = strtok(ligne, delimiteur);
      char* ville = formatterMotTailleFixe(pointeur, 15, false);
      printf("%s", ville);
      free(ville);

      //pays
      pointeur = strtok(NULL, delimiteur);
      char* pays = formatterMotTailleFixe(pointeur,5, false);
      printf("%s   ",pays);
      free(pays);

      //population 
      pointeur = strtok(NULL, delimiteur);
      char* population = formatterMotTailleFixe(pointeur, 10, true);
      printf("%s\n", population);
      free(population);

      index ++;
    }
  } else {
    printf("Erreur à l'ouverture du fichier.\n");
  }
  return 0;
}
```


#### FIN.
---
révision A2020
