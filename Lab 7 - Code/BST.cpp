#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// A recursive function to find the minimum valued node of a BST (When root is given traversing to the end of each sub tree)
struct node *findMin(struct node *node) {
    if (node->left == NULL) {
        return node;
    }
    return findMin(node->left);
}

// function for inorder traversal: left => root => right
void traverseInOrder(struct node *root) {
  if (root == NULL){
    return;
  }

  traverseInOrder(root->left);
  cout<<root->key<<" ";
  traverseInOrder(root->right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  
  if (node == NULL){ // If the root is NULL or we've traverse to the end of the tree
    struct node *newnode = new struct node; // Create a new node and assigned the key and set the left and right nodes to NULL
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
    
  } else{

    if (key <= node->key){
      node->left = insertNode(node->left, key); // Traverse to the left if the key is less than or equal to that of the node
    } else if(key > node->key){
      node->right = insertNode(node->right, key); // Traverse to the right if the key is greater than that of the node
    }

    return node;

  }

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL){ // If the tree is empty or the seraching key is not in the tree
    return NULL;
  }

  if (key < root->key){

    root->left = deleteNode(root->left,key);

  } else if(key > root->key){

    root->right = deleteNode(root->right,key);

  } else{ // The corresponding node is found

    // If no Children
    if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
      return root;
    }

    // 1 Child node on right
    else if(root->left == NULL){
      struct node *temp = root; // Assign the node to a temp variable
      root = root->right; // Assign the node on right asthe current node
      delete temp; // Delete the node
      return root;
    }

    // 1 Child node on left
    else if(root->right == NULL){
      struct node *temp = root;
      root = root->left;
      delete temp;
      return root;
    }

    // 2 Child nodes

    else{
      struct node *temp = findMin(root->right); // Find the minimum valued node in the right node, which gives the substitute to the current node 
      root->key = temp->key; // Assign the value of above found node to the current node
      root->right = deleteNode(root->right,temp->key); // Delete the minimum valued node
      return root;
    }

  }

}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}