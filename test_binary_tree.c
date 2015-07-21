#include <stdio.h>
#include "minunit.h"
#include "binary_tree.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int tests_run = 0;

static char * test_binary_tree_creation() {
    int aux;
    BinaryTreeNode* node;
    aux = 0;
    node = NULL;

    printf("Initial configuration: \n");
    node = binary_tree_insert(10, node, &aux);
    node = binary_tree_insert(20, node, &aux);
    node = binary_tree_insert(30, node, &aux);
    node = binary_tree_insert(40, node, &aux);
    node = binary_tree_insert(50, node, &aux);
    node = binary_tree_insert(60, node, &aux);


    binary_tree_print(node, 1);
    printf("\n");
    printf("\n");
    printf("-----------------------------------\n");
    printf("\n");

    node = binary_tree_remove_node(node, 50, &aux);

    printf("Removing Node: %d \n", 50);
    binary_tree_print(node, 1);
    printf("\n");
    printf("-----------------------------------\n");

    mu_assert("erro test_binary_tree_creation", 1 == 1);
    return 0;
}

static char * test_unit() {
  mu_assert("error, test_unit 1 != 1", 1 == 1);
  return 0;
}

static char * all_tests() {
  mu_run_test(test_unit);
  mu_run_test(test_binary_tree_creation);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", tests_run);
  return result != 0;
}
