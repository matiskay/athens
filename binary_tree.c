#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

// TODO: USE enum
#define RIGHT_BALANCE_STATUS 1
#define IS_BALANCE_STATUS 0
#define LEFT_BALANCE_STATUS -1

// TODO: Rename aux to parent_balance_status
// TODO: Change aux to current_node_balance_status
BinaryTreeNode* binary_tree_insert(int value, BinaryTreeNode* parent, int* aux) {
    BinaryTreeNode* aux_binary_tree_node1;
    BinaryTreeNode* aux_binary_tree_node2;

    if (parent == NULL) {
        parent = binary_tree_create_node();
        parent->value = value;
        *aux = 1;
        return parent;
    }

    if (value < parent->value) {
        parent->left = binary_tree_insert(value, parent->left, aux);

        if (*aux == 1) {
            switch (parent->balance_status) {
                case RIGHT_BALANCE_STATUS:
                    parent->balance_status = IS_BALANCE_STATUS;
                    *aux = 0;
                    break;
                case IS_BALANCE_STATUS:
                    parent->balance_status = LEFT_BALANCE_STATUS;
                    break;
                case LEFT_BALANCE_STATUS:
                    aux_binary_tree_node1 = parent->left;

                    if (aux_binary_tree_node1->balance_status == LEFT_BALANCE_STATUS) {
                        // Left Left Rotation
                        parent->left = aux_binary_tree_node1->right;
                        aux_binary_tree_node1->right = parent;
                        parent->balance_status = IS_BALANCE_STATUS;
                        parent = aux_binary_tree_node1;
                    } else {
                        // Left Right Rotation
                        aux_binary_tree_node2 = aux_binary_tree_node1->right;
                        aux_binary_tree_node1->right = aux_binary_tree_node2->left;
                        aux_binary_tree_node2->left = aux_binary_tree_node1;
                        parent->left = aux_binary_tree_node2->right;
                        aux_binary_tree_node2->right = parent;

                        if (aux_binary_tree_node2->balance_status == LEFT_BALANCE_STATUS) {
                            parent->balance_status = RIGHT_BALANCE_STATUS;
                        } else  {
                            parent->balance_status = IS_BALANCE_STATUS;
                        }

                        if (aux_binary_tree_node2->balance_status == RIGHT_BALANCE_STATUS) {
                            aux_binary_tree_node1->balance_status = LEFT_BALANCE_STATUS;
                        } else {
                            aux_binary_tree_node1->balance_status = IS_BALANCE_STATUS;
                        }
                        parent = aux_binary_tree_node2;
                    }

                    parent->balance_status = IS_BALANCE_STATUS;
                    *aux = 0;
            }
        }
    }

    if (value > parent->value) {
        parent->right = binary_tree_insert(value, parent->right, aux);

        if (*aux == 1) {
            switch (parent->balance_status) {
                case LEFT_BALANCE_STATUS:
                    parent->balance_status = IS_BALANCE_STATUS;
                    *aux = 0;
                    break;
                case IS_BALANCE_STATUS:
                    parent->balance_status = RIGHT_BALANCE_STATUS;
                    break;
                case RIGHT_BALANCE_STATUS:
                    aux_binary_tree_node1 = parent->right;

                    if (aux_binary_tree_node1->balance_status == RIGHT_BALANCE_STATUS) {
                        // Rotation Right Right
                        parent->right = aux_binary_tree_node1->left;
                        aux_binary_tree_node1->left = parent;
                        parent->balance_status = IS_BALANCE_STATUS;
                        parent = aux_binary_tree_node1;
                    } else {
                        // Rotation Right Left
                        aux_binary_tree_node2 = aux_binary_tree_node1->left;
                        aux_binary_tree_node1->left = aux_binary_tree_node2->right;
                        aux_binary_tree_node2->right = aux_binary_tree_node1;
                        parent->right = aux_binary_tree_node2->left;
                        aux_binary_tree_node2->left = parent;

                        if (aux_binary_tree_node2->balance_status == RIGHT_BALANCE_STATUS) {
                            parent->balance_status = LEFT_BALANCE_STATUS;
                        } else {
                            parent->balance_status = IS_BALANCE_STATUS;
                        }

                        if (aux_binary_tree_node2->balance_status == LEFT_BALANCE_STATUS) {
                            aux_binary_tree_node1->balance_status = RIGHT_BALANCE_STATUS;
                        } else {
                            aux_binary_tree_node1->balance_status = IS_BALANCE_STATUS;
                        }

                        parent = aux_binary_tree_node2;
                    }

                    parent->balance_status = IS_BALANCE_STATUS;
                    *aux = 0;
            }
        }
    }

    return parent;
}

BinaryTreeNode* binary_tree_create_node() {
    BinaryTreeNode* node;
    node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->balance_status = IS_BALANCE_STATUS;
    return node;
}

void binary_tree_print(BinaryTreeNode* parent, int level) {
    int padding;

    if (parent != NULL) {
        binary_tree_print(parent->right, level + 1);
        printf(" \n ");

        for (padding = 1; padding < level; padding++) {
            printf("\t");
        }

        printf("%d (%d)", parent->value, parent->balance_status);
        binary_tree_print(parent->left, level + 1);
    }
}

BinaryTreeNode* binary_tree_balance_to_right(BinaryTreeNode *parent, int *aux) {
    BinaryTreeNode* aux_binary_tree_node1;
    BinaryTreeNode* aux_binary_tree_node2;

    switch (parent->balance_status) {
        case LEFT_BALANCE_STATUS:
            parent->balance_status = IS_BALANCE_STATUS;
            break;

        case IS_BALANCE_STATUS:
            parent->balance_status = RIGHT_BALANCE_STATUS;
            *aux = 0;
            break;

        case RIGHT_BALANCE_STATUS:
            aux_binary_tree_node1 = parent->right;

            if (aux_binary_tree_node1->balance_status >= 0) {
                // Right Right Rotation
                parent->right = aux_binary_tree_node1->left;
                aux_binary_tree_node1->left = parent;
                if (aux_binary_tree_node1->balance_status == IS_BALANCE_STATUS) {
                    parent->balance_status = RIGHT_BALANCE_STATUS;
                    aux_binary_tree_node1->balance_status = LEFT_BALANCE_STATUS;
                    *aux = 0;
                } else {
                    parent->balance_status = 0;
                    aux_binary_tree_node1->balance_status = IS_BALANCE_STATUS;
                }
                parent = aux_binary_tree_node1;
            } else {
                // Balance Right - Left
                aux_binary_tree_node2 = aux_binary_tree_node1->left;
                aux_binary_tree_node1->left = aux_binary_tree_node2->right;
                aux_binary_tree_node2->right = aux_binary_tree_node1;
                parent->right = aux_binary_tree_node2->left;
                aux_binary_tree_node2->left = parent;

                if (aux_binary_tree_node2->balance_status == RIGHT_BALANCE_STATUS) {
                    parent->balance_status = LEFT_BALANCE_STATUS;
                } else {
                    parent->balance_status = IS_BALANCE_STATUS;
                }

                if (aux_binary_tree_node2->balance_status == LEFT_BALANCE_STATUS) {
                    aux_binary_tree_node1->balance_status = RIGHT_BALANCE_STATUS;
                } else {
                    aux_binary_tree_node1->balance_status = IS_BALANCE_STATUS;
                }

                parent = aux_binary_tree_node2;
                aux_binary_tree_node2->balance_status = IS_BALANCE_STATUS;
            }
    }

    return parent;
}

BinaryTreeNode* binary_tree_free(BinaryTreeNode* parent) {
    if (! parent) {
        binary_tree_free(parent->left);
        binary_tree_free(parent->right);
        free(parent);
    }
    return NULL;
}

BinaryTreeNode* binary_tree_remove_node(BinaryTreeNode* parent, int value, int* aux) {
    BinaryTreeNode* temp_node;

    if (parent == NULL) {
        return parent;
    } else {
        if (value < parent->value) {
            parent->left = binary_tree_remove_node(parent->left, value, aux);

            if (*aux != 0) {
                parent = binary_tree_balance_to_right(parent, aux);
            }
        } else if (value > parent->value) {
            parent->right = binary_tree_remove_node(parent->right, value, aux);
            if (*aux != 0) {
                parent = binary_tree_balance_to_left(parent, aux);
            }
        } else {
            temp_node = parent;

            if (temp_node->right == NULL) {
                parent = temp_node->left;
                *aux = 1;
                free(temp_node);
            } else if (temp_node->left == NULL) {
                parent = temp_node->right;
                *aux = 1;
                free(temp_node);
            } else {
                //printf("[DEBUG] \n");

                temp_node->left = binary_tree_prepare_node_to_remove(temp_node->left, temp_node, aux);

                if (*aux != 0) {
                    parent = binary_tree_balance_to_right(parent, aux);
                }
            }
        }
    }

    return parent;
}

BinaryTreeNode* binary_tree_prepare_node_to_remove(BinaryTreeNode* node, BinaryTreeNode* temp_node, int* aux) {
    BinaryTreeNode* candidate_node;

//  candidate_node = node;

    if (node->right != NULL) {
        node->right = binary_tree_prepare_node_to_remove(node->right, temp_node, aux);
        if (*aux) {
            node = binary_tree_balance_to_left(node, aux);
        }
    } else {
        candidate_node = node;
        temp_node->value = node->value;
        node = node->left;
        free(candidate_node);
        *aux = 1;
    }

    return node;
}

BinaryTreeNode* binary_tree_balance_to_left(BinaryTreeNode *parent, int *aux) {
    BinaryTreeNode* aux_binary_tree_node1;
    BinaryTreeNode* aux_binary_tree_node2;

    switch (parent->balance_status) {
        case RIGHT_BALANCE_STATUS:
            parent->balance_status = IS_BALANCE_STATUS;
            break;

        case IS_BALANCE_STATUS:
            parent->balance_status = LEFT_BALANCE_STATUS;
            *aux = 0;
            break;

        case LEFT_BALANCE_STATUS:
            aux_binary_tree_node1 = parent->left;

            if (aux_binary_tree_node1->balance_status <= 0) {
                // Left - Left
                parent->left = aux_binary_tree_node1->right;
                aux_binary_tree_node1->right = parent;

                if (aux_binary_tree_node1->balance_status == IS_BALANCE_STATUS) {
                    parent->balance_status = LEFT_BALANCE_STATUS;
                    aux_binary_tree_node1->balance_status = RIGHT_BALANCE_STATUS;
                    *aux = 0;
                } else {
                    parent->balance_status = IS_BALANCE_STATUS;
                    aux_binary_tree_node1->balance_status = IS_BALANCE_STATUS;
                }

                parent = aux_binary_tree_node1;

            } else {
                // Left - Right
                aux_binary_tree_node2 = aux_binary_tree_node1->right;
                aux_binary_tree_node1->right = aux_binary_tree_node2->left;
                aux_binary_tree_node2->left = aux_binary_tree_node1;
                parent->left = aux_binary_tree_node2->right;
                aux_binary_tree_node2->right = parent;

                if (aux_binary_tree_node2->balance_status == LEFT_BALANCE_STATUS) {
                    parent->balance_status = RIGHT_BALANCE_STATUS;
                } else {
                    parent->balance_status = IS_BALANCE_STATUS;
                }

                if (aux_binary_tree_node2->balance_status == RIGHT_BALANCE_STATUS) {
                    aux_binary_tree_node1->balance_status = LEFT_BALANCE_STATUS;
                } else {
                    aux_binary_tree_node1->balance_status = IS_BALANCE_STATUS;
                }

                parent = aux_binary_tree_node2;
                aux_binary_tree_node2->balance_status = IS_BALANCE_STATUS;
            }
    }

    return parent;
}