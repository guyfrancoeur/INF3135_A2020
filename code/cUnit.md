# CUnit  _Exemple_

### les prérequis (qui sont déjà installés)
+ pour la machine Java (UQAM), version avec Ubuntu, nous avons la version 2.1-3;
+ les fichiers d'entête sont dans `/usr/include/CUnit`;
+ les fichiers librairies sont dans `/usr/lib/x86_64-linux-gnu`;
+ GCC version 9.3.0


### Rendu visuel
#### Lorsque vous executez vos tests voici un exemple sur la sortie standard
~~~
     CUnit - A unit testing framework for C - Version 2.1-3
     http://cunit.sourceforge.net/


Suite: max_test_suite
  Test: max_test_1 ...passed
  Test: max_test_2 ...passed
  Test: max_test_3 ...passed

Run Summary:    Type  Total    Ran Passed Failed Inactive
              suites      1      1    n/a      0        0
               tests      3      3      3      0        0
             asserts      6      6      6      0      n/a

Elapsed time =    0.000 seconds
~~~

### Commandes pour la compilation
#### La compilation avec `GCC` requiert plusieurs étapes pour notre exemple

+ `$ gcc -Wall -Werror=vla -c max.c`
+ `$ gcc -Wall -Werror=vla -I/usr/include/CUnit -L/usr/lib/x86_64-linux-gnu -o max_test max_test.c max.o -lcunit`
+ `$ ./max_test`


## max.h
#### Le fichier d'entête avec les prototypes

```c
//max.h
#ifndef MAX_H
#define MAX_H
  extern int max (int, int);
#endif
```

## max.c
#### L'implémentation, les codes sources, des fonctions

```c
//max.c
#include "max.h"

int max (int n1, int n2)
{
  if ( n2 > n1 ) return n2;
  return n1;
}
```


## max_test.c
#### Un programme exemple pour exécuter les tests

```c
//max_test.c
#include "Basic.h"       // mode de base
//#include "Automated.h"
//#include "Console.h"
#include "max.h"         // declaration de mes fonctions
#include <stdio.h>       // printf
#include <stdbool.h>     // bool true false

/*****  LES fonctions qui initialise et detruit la "Suite de test" ******/

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/********************* NOS fonctions de tests *********************/
/*
void test_case_exemple(void)
{
   // Les types d'assertions disponibles
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_TRUE(true);
   CU_ASSERT_FALSE(false);
   CU_ASSERT_NOT_EQUAL(2, -1);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(2, 3);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}
*/
void max_test_un(void) {
  CU_ASSERT_EQUAL( max(1,2), 2);
  CU_ASSERT_EQUAL( max(2,1), 2);
}

void max_test_deux(void) {
  CU_ASSERT_EQUAL( max(2,2), 2);
  CU_ASSERT_EQUAL( max(0,0), 0);
  CU_ASSERT_EQUAL( max(-1,-1), -1);
}

void max_test_trois(void) {
  CU_ASSERT_EQUAL( max(-1,-2), -1);
}

/************* Nous debutons l'execution des tests **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "max_test_suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ( (NULL == CU_add_test(pSuite, "max_test_1", max_test_un)) ||
        (NULL == CU_add_test(pSuite, "max_test_2", max_test_deux)) ||
        (NULL == CU_add_test(pSuite, "max_test_3", max_test_trois))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");
/* 
   // LES modes interactifs
   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   // Run all tests using the console interface
   CU_console_run_tests();
*/
   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
```
## Réferences

+ [CUnit Home](http://cunit.sourceforge.net/index.html)
+ [CUnit Framework](http://cunit.sourceforge.net/doxdocs/group__Framework.html)

 ----
 par GF version A2020
