#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

#define RIGHT_BALANCE 1
#define BALANCE 0
#define LEFT_BALANCE -1

// TODO: Rename aux to parent_balance_status
BinaryTreeNode* binary_tree_insert(int value, BinaryTreeNode* parent, int* aux) {
  BinaryTreeNode * aux_binary_tree_node1;
  BinaryTreeNode * aux_binary_tree_node2;

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
        case RIGHT_BALANCE:
          parent->balance_status = 0;
          *aux = 0;
          break;
        case BALANCE:
          parent->balance_status = -1;
          break;
        case LEFT_BALANCE:
          aux_binary_tree_node1 = parent->left;

          if (aux_binary_tree_node1->balance_status == LEFT_BALANCE) {
            // Left Left Rotation
            parent->left = aux_binary_tree_node1->right;
            aux_binary_tree_node1->right = parent;
            parent->balance_status = BALANCE;
            parent = aux_binary_tree_node1;
          } else {
            // Left Right Rotation
            aux_binary_tree_node2 = aux_binary_tree_node1->right;
            aux_binary_tree_node1->right = aux_binary_tree_node2->left;
            aux_binary_tree_node2->left = aux_binary_tree_node1;
            parent->left = aux_binary_tree_node2->right;
            aux_binary_tree_node2->right = parent;

            if (aux_binary_tree_node2->balance_status == LEFT_BALANCE) {
              parent->balance_status = RIGHT_BALANCE; 
            } else  {
              parent->balance_status = BALANCE;
            }

            if (aux_binary_tree_node2->balance_status == RIGHT_BALANCE) {
              aux_binary_tree_node1->balance_status = LEFT_BALANCE;
            } else {
              aux_binary_tree_node1->balance_status = BALANCE;
            }

            parent = aux_binary_tree_node2;

            *aux = 0;
          }
      }
    }
  }
   
  if (value > parent->value) {
    parent->right = binary_tree_insert(value, parent->right, aux);

    if (*aux == 1) {
      switch (parent->balance_status) {
        case LEFT_BALANCE:
          parent->balance_status = BALANCE;
          *aux = 0;
          break;
        case BALANCE:
          parent->balance_status = 1;
          break;
        case RIGHT_BALANCE:
          aux_binary_tree_node1 = parent->right;

          if (aux_binary_tree_node1->balance_status == RIGHT_BALANCE) {
            // Rotation Right Right
            parent->right = aux_binary_tree_node1->left;
            aux_binary_tree_node1->left = parent;
            parent->balance_status = BALANCE;
            parent = aux_binary_tree_node1;
          } else {
            // Rotation Right Left
            aux_binary_tree_node2 = aux_binary_tree_node1->left;
            aux_binary_tree_node1->left = aux_binary_tree_node2->right;
            aux_binary_tree_node2->right = aux_binary_tree_node1;
            parent->right = aux_binary_tree_node2->left;
            aux_binary_tree_node2->left = parent;
            
            if (aux_binary_tree_node2->balance_status == RIGHT_BALANCE) {
              parent->balance_status = LEFT_BALANCE;
            } else {
              parent->balance_status = BALANCE;
            }

            if (aux_binary_tree_node2->balance_status == LEFT_BALANCE) {
              aux_binary_tree_node1->balance_status = RIGHT_BALANCE;
            } else {
              aux_binary_tree_node1->balance_status = BALANCE;
            }

            parent = aux_binary_tree_node2;
          }
          
          parent->balance_status = BALANCE;
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
  node->balance_status = 0;
  return node;
}

void binary_tree_print(BinaryTreeNode* parent, int level) {
  int i;

  if (parent != NULL) {
    binary_tree_print(parent->right, level + 1);
    printf(" \n ");

    for (i = 1; i < level; i++) {
      printf("\t");
    }

    printf("%d (%d)", parent->value, parent->balance_status);
    binary_tree_print(parent->left, level + 1);
  }
}

BinaryTreeNode* binary_tree_right_balance(BinaryTreeNode* parent, int* aux) {
  BinaryTreeNode* aux_binary_tree_node1;
  BinaryTreeNode* aux_binary_tree_node2;

  switch (parent->balance_status) {
    case LEFT_BALANCE: 
      parent->balance_status = BALANCE;
      break;

    case BALANCE:
      parent->balance_status = RIGHT_BALANCE;
      *aux = 0;
      break;

    case RIGHT_BALANCE:
      aux_binary_tree_node1 = parent->right;
      
      if (aux_binary_tree_node1->balance_status >= 0) {
        // Right Right Rotation
        parent->right = aux_binary_tree_node1->left;
        aux_binary_tree_node1->left = parent;
        if (aux_binary_tree_node1->balance_status == 0) {
          parent->balance_status = 1;
          aux_binary_tree_node1->balance_status = -1;
          *aux = 0;
        } else {
          parent->balance_status = 0;
          aux_binary_tree_node1->balance_status = 0;
        }
        parent = aux_binary_tree_node1;
      } else {
        // Balance Right - Left
        aux_binary_tree_node2 = aux_binary_tree_node1->left;
        aux_binary_tree_node1->left = aux_binary_tree_node2->right;
        aux_binary_tree_node2->right = aux_binary_tree_node1;
        parent->right = aux_binary_tree_node2->left;
        aux_binary_tree_node2->left = parent;

        if (aux_binary_tree_node2->balance_status == 1) {
          parent->balance_status = -1;
        } else {
          parent->balance_status = 0;
        }

        if (aux_binary_tree_node2->balance_status == -1) {
          aux_binary_tree_node1->balance_status = 1;
        } else {
          aux_binary_tree_node1->balance_status = 0;
        }

        parent = aux_binary_tree_node2;
        aux_binary_tree_node2 = 0;
      }
  }

  return NULL;
}

BinaryTreeNode* binary_tree_free(BinaryTreeNode* parent) {
  if (! parent) {
    binary_tree_free(parent->left);
    binary_tree_free(parent->right);
    free(parent);
  }
  return NULL;
}

// Check this function
BinaryTreeNode* binary_tree_remove_node(BinaryTreeNode* parent, int value, int* aux) {
  BinaryTreeNode* temp_node;
  
  if (parent == NULL) {
    return parent;
  } else {
    if (value < parent->value) {
      parent->left = binary_tree_remove_node(parent->left, value, aux);

      if (*aux != 0) {
        parent = binary_tree_right_balance(parent, aux);
      }
    } else if (value > parent->value) {
      parent->right = binary_tree_remove_node(parent->right, value, aux);
      if (*aux != 0) {
        parent = binary_tree_left_balance(parent, aux);
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
        temp_node->left = binary_tree_prepare_node_to_remove(temp_node->left, temp_node, aux);
        if (*aux != 0) {
          parent = binary_tree_right_balance(parent, aux);
        }
      }
    }
  }

  return parent;
}

BinaryTreeNode* binary_tree_prepare_node_to_remove(BinaryTreeNode* node, BinaryTreeNode* temp_node, int* aux) {
  BinaryTreeNode* candidate_node;

  candidate_node = node;

  if (node->right != NULL) {
    node->right = binary_tree_prepare_node_to_remove(node->right, temp_node, aux);
    if (*aux) {
      node = binary_tree_left_balance(node, aux);
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

BinaryTreeNode* binary_tree_left_balance(BinaryTreeNode* parent, int* aux) {
  BinaryTreeNode* aux_binary_tree_node1;
  BinaryTreeNode* aux_binary_tree_node2;

  switch (parent->balance_status) {
    case 1:
      parent->balance_status = 0;
      break;

    case 0:
      parent->balance_status = -1;
      *aux = 0;
      break;

    case -1:
      aux_binary_tree_node1 = parent->left;

      if (aux_binary_tree_node1 <= 0) {
        // Left - Left
        parent->left = aux_binary_tree_node1->right;
        aux_binary_tree_node1->right = parent;

        if (aux_binary_tree_node1->balance_status == 0) {
          parent->balance_status = -1;
          aux_binary_tree_node1->balance_status = 1;
          *aux = 0;
        } else {
          parent->balance_status = 0;
          aux_binary_tree_node1 = 0;
        }

        parent = aux_binary_tree_node1;

      } else {
        // Left - Right
        aux_binary_tree_node2 = aux_binary_tree_node1->right;
        aux_binary_tree_node1->right = aux_binary_tree_node2->left;
        aux_binary_tree_node2->left = aux_binary_tree_node1;
        parent->left = aux_binary_tree_node2->right;
        aux_binary_tree_node2->right = parent;

        if (aux_binary_tree_node2->balance_status == -1) {
          parent->balance_status = 1;
        } else {
          parent->balance_status = 0;
        }

        if (aux_binary_tree_node2->balance_status == 1) {
          aux_binary_tree_node1->balance_status = -1;
        } else {
          aux_binary_tree_node1->balance_status = 0;
        }

        parent = aux_binary_tree_node2;
        aux_binary_tree_node2->balance_status = 0;
      }
  }

  return parent;
}
