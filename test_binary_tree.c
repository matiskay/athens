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
    node = binary_tree_insert(80, node, &aux);
    node = binary_tree_insert(90, node, &aux);
    node = binary_tree_insert(100, node, &aux);
    node = binary_tree_insert(110, node, &aux);
    node = binary_tree_insert(120, node, &aux);


    binary_tree_print(node, 1);
    printf("\n");
    printf("\n");
    printf("-----------------------------------\n");
    printf("\n");

    node = binary_tree_remove_node(node, 90, &aux);

    printf("Removing Node: %d \n", 90);
    binary_tree_print(node, 1);
    printf("\n");
    printf("-----------------------------------\n");

    node = binary_tree_remove_node(node, 100, &aux);

    printf("Removing Node: %d \n", 100);
    binary_tree_print(node, 1);
    printf("\n");
    printf("-----------------------------------\n");

    node = binary_tree_remove_node(node, 110, &aux);

    printf("Removing Node: %d \n", 110);
    binary_tree_print(node, 1);
    printf("\n");
    printf("-----------------------------------\n");

    node = binary_tree_remove_node(node, 80, &aux);

    printf("Removing Node: %d \n", 80);
    binary_tree_print(node, 1);
    printf("\n");
    printf("-----------------------------------\n");

    node = binary_tree_remove_node(node, 120, &aux);

    printf("Removing Node: %d \n", 120);
    binary_tree_print(node, 1);
    printf("\n");
    printf("-----------------------------------\n");

    mu_assert("erro test_binary_tree_creation", 1 == 1);
    return 0;
}

static char * test_binary_tree_insertion() {
    /*
     * Test case based on http://www.csee.umbc.edu/courses/undergraduate/341/fall98/frey/ClassNotes/Class18/avl.html
     */
    int aux;
    BinaryTreeNode* node;
    aux = 0;
    node = NULL;

    printf("Initial configuration: \n");
    node = binary_tree_insert(10, node, &aux);

    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(20, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------ \n");

    node = binary_tree_insert(30, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------ \n");

    node = binary_tree_insert(40, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------ \n");

    node = binary_tree_insert(50, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------ \n");

    node = binary_tree_insert(0, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------ \n");

    node = binary_tree_insert(70, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------ \n");

    node = binary_tree_insert(60, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------ \n");

    mu_assert("test_binary_tree_insertion", 1 == 1);
    return 0;
}

static char * test_binary_tree_insertion_2() {
    /*
     * Test case based on http://www.csee.umbc.edu/courses/undergraduate/341/fall98/frey/ClassNotes/Class18/avl.html
     */
    int aux;
    BinaryTreeNode* node;
    aux = 0;
    node = NULL;

    printf("Initial configuration: \n");

    node = binary_tree_insert(30, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(5, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(35, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(32, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(40, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(45, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    mu_assert("test_binary_tree_insertion", 1 == 1);
    return 0;
}

static char * test_binary_tree_insertion_3() {
    int aux;
    BinaryTreeNode* node;
    aux = 0;
    node = NULL;

    printf("Initial configuration: \n");

    node = binary_tree_insert(14, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(17, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(11, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(7, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(53, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(4, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(13, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");


    node = binary_tree_insert(12, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(8, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_remove_node(node, 53, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_remove_node(node, 11, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_remove_node(node, 8, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    mu_assert("test_binary_tree_insertion", 1 == 1);
    return 0;
}

static char * test_binary_tree_insertion_4() {
    int aux;
    BinaryTreeNode* node;
    aux = 0;
    node = NULL;

    printf("Initial configuration: \n");

    node = binary_tree_insert(15, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(20, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(24, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(10, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(13, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(7, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(30, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");


    node = binary_tree_insert(36, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_insert(25, node, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_remove_node(node, 24, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

    node = binary_tree_remove_node(node, 20, &aux);
    binary_tree_print(node, 1);
    printf("\n ------------------- \n");

//    node = binary_tree_insert(8, node, &aux);
//    binary_tree_print(node, 1);
//    printf("\n ------------------- \n");
//
//    node = binary_tree_remove_node(node, 53, &aux);
//    binary_tree_print(node, 1);
//    printf("\n ------------------- \n");
//
//    node = binary_tree_remove_node(node, 11, &aux);
//    binary_tree_print(node, 1);
//    printf("\n ------------------- \n");
//
//    node = binary_tree_remove_node(node, 8, &aux);
//    binary_tree_print(node, 1);
//    printf("\n ------------------- \n");

    mu_assert("test_binary_tree_insertion", 1 == 1);
    return 0;
}

static char * test_unit() {
  mu_assert("error, test_unit 1 != 1", 1 == 1);
  return 0;
}

static char * all_tests() {
    mu_run_test(test_unit);
    mu_run_test(test_binary_tree_creation);
    mu_run_test(test_binary_tree_insertion);
    mu_run_test(test_binary_tree_insertion_2);
    mu_run_test(test_binary_tree_insertion_3);
    mu_run_test(test_binary_tree_insertion_4);
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
