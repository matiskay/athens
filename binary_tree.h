struct binary_tree_node {
  int value;
  int balance_status;
  struct binary_tree_node* left;
  struct binary_tree_node* right;
};

typedef struct binary_tree_node BinaryTreeNode;

BinaryTreeNode* binary_tree_insert(int, BinaryTreeNode*, int*);

// Right Rotation
BinaryTreeNode* binary_tree_create_node(void);
void binary_tree_print(BinaryTreeNode*, int); 

BinaryTreeNode* binary_tree_balance_to_right(BinaryTreeNode *, int *);
BinaryTreeNode* binary_tree_balance_to_left(BinaryTreeNode *, int *);

BinaryTreeNode* binary_tree_free(BinaryTreeNode*);
BinaryTreeNode* binary_tree_remove_node(BinaryTreeNode*, int, int*);

BinaryTreeNode* binary_tree_prepare_node_to_remove(BinaryTreeNode*, BinaryTreeNode*, int*);
