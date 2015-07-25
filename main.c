#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binary_tree.h"

#define MAXIMUN_LENGTH_OF_THE_INPUT_STRING 300
#define MAX_REPL_ARGUMENT_SIZE 100

#define PROMPT "athens:%.3i> "

char* get_line(void);
void display_help(void);

int main(int argc, char **argv) {
    char* line;
    int line_number;
    char command[MAX_REPL_ARGUMENT_SIZE];
    char variable1[MAX_REPL_ARGUMENT_SIZE];

    /* Binary Tree */
    int aux;
    BinaryTreeNode* node;

    aux = 0;
    node = NULL;

    line_number = 1;

    while (1) {
        printf(PROMPT, line_number);
        line = get_line();

        if (strcmp(line, "exit") == 0) {
            printf("Do you really want to exit ([y]/n)? ");
            line = get_line();
            if (strcmp(line, "y") == 0) {
                break;
            }
        } else if (strcmp(line, "help") == 0) {
            display_help();
        } else if (strcmp(line, "destroy") == 0) {
            node = binary_tree_free(node);
        } else if (strcmp(line, "print") == 0) {
            binary_tree_print(node, 1);
            printf("\n");
        } else {
            sscanf(line, "%s %s", command, variable1);

            if (strcmp(command, "insert") == 0) {
                printf("Insert variable1 %d", atoi(variable1));
                node = binary_tree_insert(atoi(variable1), node, &aux);
                binary_tree_print(node, 1);
                printf("\n");
            } else if (strcmp(command, "remove") == 0) {
                printf("Removing variable1 %d", atoi(variable1));
                node = binary_tree_remove_node(node, atoi(variable1), &aux);
                binary_tree_print(node, 1);
                printf("\n");
            } else {
                printf("%s is an undefined command \n", line);
            }
        }

        line_number++;
    }

    return 0;
}

char* get_line() {
    char* line;
    int index;

    line = malloc(MAXIMUN_LENGTH_OF_THE_INPUT_STRING);
    index = 0;

    line[index] = (char) getchar();

    // This command includes "\n" at the end
    while (line[index] != '\n') {
        index++;
        if (line[index] != '\n') {
            line[index] = (char) getchar();
        }
    }

    line[index] = '\0';

    return line;
}

void display_help() {
    printf("   exit                                     :      Exit the program.\n");
    printf("   help                                     :      Help for the program.\n");
    printf("   insert <integer-value>                   :      Insert <integer-value> node to the binary tree.\n");
    printf("   remove <integer-value>                   :      Remove <integer-value> node to the binary tree.\n");
    printf("   destroy                                  :      Destroy the current binary tree.\n");
}
