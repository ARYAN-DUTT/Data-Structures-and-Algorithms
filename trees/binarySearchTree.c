#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int val) {
  struct node *nn = (struct node *)malloc(sizeof(struct node));
  nn->data = val;
  nn->left = NULL;
  nn->right = NULL;
  return nn;
}

struct node *insert(struct node *root, int value) {
  if (root == NULL) {
    return createNode(value);
  }
  if (value < root->data) {
    root->left = insert(root->left, value);
  } else if (value > root->data) {
    root->right = insert(root->right, value);
  }
  return root;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void preorder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

struct node *search(struct node *root, int key){
  if(root == NULL || root->data == key){
    return root;
  }
  if(key < root->data){
    return search(root->left, key);
  }
  return search(root->right, key);
}

struct node* minValueNode(struct node* node) {
  struct node* current = node;
  while (current && current->left != NULL) {
    current = current->left;
  }
  return current;
}


struct node * deleteNode(struct node *root, int key){
  if(root == NULL){
    return root;
  }
  if(key < root->data){
    root->left = deleteNode(root->left, key);
  } else if(key > root->data){
    root->right = deleteNode(root->right, key);
  } else {
    if(root->left == NULL){
      struct node *temp = root->right; 
      free(root); // wtf? like what is this
      // arent we supposed to get root->right
      // at the position of root here
      return temp;
    } else if(root->right == NULL){
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main() {
  struct node *root = NULL;
  root = insert(root, 30);
  root = insert(root, 7);
  root = insert(root, 15);
  root = insert(root, 4);
  root = insert(root, 19);
  root = insert(root, 50);
  root = insert(root, 76);
  root = insert(root, 100);
  root = insert(root, 21);
  root = deleteNode(root, 15);
  inorder(root);
  printf("\n");
  return 0;
}