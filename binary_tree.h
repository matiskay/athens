struct binary_tree_node {
  int value;
  int balance_status;
  struct binary_tree_node* left;
  struct binary_tree_node* right;
};

typedef struct binary_tree_node BinaryTreeNode;

BinaryTreeNode* binary_tree_insert(int, BinaryTreeNode*, int*);

// Right Rotation
BinaryTreeNode* binary_tree_balance_to_right(BinaryTreeNode*, int*); 
BinaryTreeNode* binary_tree_create_node(); 
