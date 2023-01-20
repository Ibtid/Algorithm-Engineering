#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool insertStatus = true;

class BST{
    int data;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int);

    // Insert function.
    BST* Insert(BST*, int);

    //Inorder traversal.
    void Inorder(BST*);

    void printLevelOrder(BST*);

};

//Default Constructor definition.
BST::BST():data(0),left(NULL),right(NULL){}

// Parameterized Constructor definition.
BST::BST(int value){
    data = value;
    left = right = NULL;
}

// Insert function definition.
BST* BST::Insert(BST* root, int value)
{
    if (!root) {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    //Bottom neck cases
    if (root && value == root->data) {
            insertStatus=false;
            return root;
    }

    if (root && value > root->data && value <= root->data + 3) {
            insertStatus=false;
            return root;
    }
    if (root && value < root->data && value >= root->data - 3) {
            insertStatus=false;
            return root;
    }

    // Insert data.
    if (value > root->data+3) {
        root->right = Insert(root->right, value);
    }


    else if (value < root->data-3 ){
        root->left = Insert(root->left,value);
    }

    // Return root node after insertion.
    return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
    if(!root){
        return;
    }
    Inorder(root->left);
    cout << root->data <<" ";
    Inorder(root->right);
}

void BST ::printLevelOrder(BST* root)
{
    // Base Case
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    queue<BST*> q;

    // Enqueue Root and initialize height
    q.push(root);

    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        BST* node = q.front();
        cout << node->data << " ";
        q.pop();

        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);

        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}

// Driver code
int main()
{
    BST b, *root = NULL;
    int reservation;

    while(1){
        insertStatus = true;
        cout << "\nAdd a Reservation" << endl;
        cin >> reservation;
        if(reservation == -1){
            break;
        }
        if(root == NULL){
            root = b.Insert(root, reservation);

        }else{
            b.Insert(root, reservation);
        }
        /*b.Inorder(root);
        if(!insertStatus){
            cout << "(Reservation Failed)" << endl;
        }*/
    }

    b.printLevelOrder(root);

    return 0;
}

