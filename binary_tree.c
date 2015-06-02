#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

#define RIGHT_BALANCE 1
#define BALANCE 0
#define LEFT_BALANCE -1

// TODO: Rename aux
BinaryTreeNode* binary_tree_insert(int value, BinaryTreeNode* parent, int* aux) {
  BinaryTreeNode * aux_binary_tree_node1;
  BinaryTreeNode * aux_binary_tree_node2;

  if (parent == NULL) {
    parent = binary_tree_create_node();
    *aux = 1;
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
