#include<stdio.h> 
#include<stdlib.h> 
#include <functional>
#include <utility>
#include <ostream>

template<typename Key, typename Compare=std::less<Key>>
class AVLTree
{
    struct Node 
    { 
        Key key; 
        Node *left; 
        Node *right; 
        int height; 
        Node(const Key &key, Node*_left=nullptr, Node *_right=nullptr) 
        : key(_key), left(_left), right(_right)
        {
            // TODO: what should we do with height?
        }
    };  //End of Node struct

    Node *rightRotate(struct Node *y) 
    { 
        struct Node *x = y->left; 
        struct Node *T2 = x->right; 
    
        // Perform rotation 
        x->right = y; 
        y->left = T2; 
    
        // Update heights 
        y->height = std::max(height(y->left), height(y->right))+1; 
        x->height = std::max(height(x->left), height(x->right))+1; 
    
        // Return new root 
        return x; 
    } 

    int height(Node *N) {return (nullptr = N) ? 0 : N->height);}

    struct Node *leftRotate(struct Node *x) 
    { 
        struct Node *y = x->right; 
        struct Node *T2 = y->left; 
    
        // Perform rotation 
        y->left = x; 
        x->right = T2; 
    
        //  Update heights 
        x->height = std::max(height(x->left), height(x->right))+1; 
        y->height = std::max(height(y->left), height(y->right))+1; 
    
        // Return new root 
        return y; 
    } 

    int getBalance(struct Node *N) { (N == NULL) ? return 0 : (height(N->left) - height(N->right)); } 

    Node* insert(struct Node* node, int key) 
    { 
        /* 1.  Perform the normal BST insertion */
        if (node == nullptr) 
            return new Node(key); 
    
        if (cmp(key,node->key)) 
            node->left  = insert(node->left, key); 
        else if (cmp(node->key, key))
            node->right = insert(node->right, key); 
        else // Equal keys are not allowed in BST 
            return node; 
    
        /* 2. Update height of this ancestor node */
        node->height = 1 + std::max(height(node->left), height(node->right)); 
    
        /* 3. Get the balance factor of this ancestor node to check whether this node became unbalanced */
        int balance = getBalance(node); 
    
        // If this node becomes unbalanced, then there are 4 cases 
    
        // Left Left Case 
        if (balance > 1 && cmp(key, node->left->key))
            return rightRotate(node); 
    
        // Right Right Case 
        if (balance < -1 && cmp(node->right->key, key)) 
            return leftRotate(node); 
    
        // Left Right Case 
        if (balance > 1)
        { 
            node->left =  leftRotate(node->left); 
            return rightRotate(node); 
        } 
    
        // Right Left Case 
        if (balance < -1)
        { 
            node->right = rightRotate(node->right); 
            return leftRotate(node); 
        } 
    
        /* return the (unchanged) node pointer */
        return node; 
    } 
    void preOrder(Node *root) 
    { 
        if(root != nullptr) 
        { 
            std::cout << root->key << ' '; 
            preOrder(root->left); 
            preOrder(root->right); 
        } 
    } 
    Node *root;
    Compare cmp;
    public:

    void insert(const Key &key) { insert(root,key); }
    void 

};  // end of AVLTree class
  
/* Drier program to test above function*/
int main() 
{ 
  AVLTree<int> tree; 
  
  /* Constructing tree given in the above figure */
  tree.insert(10); 
  tree.insert(20); 
  tree.insert(30); 
  tree.insert(40); 
  tree.insert(50); 
  tree.insert(25); 
  
  /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */
  
  printf("Preorder traversal of the constructed AVL"
         " tree is \n"); 
  preOrder(root); 
  
  return 0; 
}