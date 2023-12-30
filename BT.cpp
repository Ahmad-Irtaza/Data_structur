//..........Irtaza Butt___22p-9316____Binary Sreach Tree.......... 
#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int val)
{
    data = val;
    left=NULL;
    right=NULL;

}

};
Node* insertBST(Node *root,int val)
{
    if(root==nullptr)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left=insertBST(root->left,val);
    }
    else
    {
        //val > root->data
        root->right=insertBST(root->right,val);
    }
    return root;
}

Node* searchBST(Node *root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    if(root->data>key)
    {
        return searchBST(root->left, key);
    }

    if(root->data<key)
    {
        return searchBST(root->right, key);
    }

   if(root->data<key)
{
        return searchBST(root->right,  key);
}
return root;
}




Node *inorderSucc(Node *root)

{

Node *curr = root;
while (curr && curr->left != NULL)
        {
        curr=curr->left;
}
return curr;
    }




    Node *deleteBST(Node *root, int key) {



// if (root->left && root->right == NULL) {
//         if (root->data == key) {
//           delete root;
//           }
          
//         }
if (key < root->data)
        {
        root->left=deleteBST(root->left, key);
        }
else if (key > root->data)
        {
        root->right=deleteBST(root->right, key);
        }
else
        {
if (root->left == NULL) {
          Node *temp = root->right;
          delete root;
          return temp;
        }
else if (root->right == NULL)
          {
          Node *temp = root->left;
          delete root;
          return temp;
          }
          Node *temp = inorderSucc(root->right);
          root->data = temp->data;
          root->right=deleteBST(root->right,key);
        }
        return root;
    }
class Tree
    {
    public:
      void preorder(Node *node)
          {
          if (node != NULL)
          {
            cout<<node->data<<" ";
            preorder(node->left);
            preorder(node->right);

        }
    }
    void inorder(Node *node)
        {
        if(node !=NULL){
            inorder(node->left);
            cout<<node->data<<" ";
            inorder(node->right);

        }
    }
    void postorder(Node *node)
        {
        if (node != NULL)
            {
            postorder(node->left);
            postorder(node->right);
            cout<<node->data<<" ";

        }
    }
    Node* root;
    Tree()
        {
        root= NULL;
    }
    void setLeft(Node *parent, Node *child)
        {
        parent->left=child;
    }

    void setRight(Node *parent, Node *child)
        {
        parent->right=child;
    }

};
int main()
{   Tree v1;
    Node *root = NULL;
    cout<<"___________INSERT___________"<<endl<<endl;

    root= insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root, 6);

    cout<<"......INORDER......."<<endl;
    v1.inorder(root);
    cout << endl;

    cout<<"......PREORDER......."<<endl;
    v1.preorder(root);
    cout << endl;

    cout<<"......POSTORDER......."<<endl;
    v1.postorder(root);
    cout << endl;

    cout<<"_________SERACH__________"<<endl;

    if (searchBST(root, 3) == NULL) {
        cout<<"key does'nt exist";
        cout << endl;

        }
    else {
        cout<<"key does exist";
        cout << endl;

    }
    //  v1.inorder(root);
    cout << endl;

    if (searchBST(root, 8) == NULL) {
        cout<<"key does'nt exist";
        cout << endl;
    }
    else
        {
        cout<<"key does exist";
        cout << endl;

    }
    //  v1.inorder(root);
    cout << endl;


    if (searchBST(root, 5) == NULL) {
        cout<<"key does'nt exist";
        cout << endl;

        }
    else {
        cout<<"key does exist";
        cout << endl;

    }
    //  v1.inorder(root);
    cout << endl;
    cout<<"________DELETE________"<<endl;
    root = deleteBST(root, 2);
    v1.inorder(root);
    cout << endl;
    
    root = deleteBST(root, 6);
    v1.inorder(root);
    cout << endl;

    root = deleteBST(root, 3);
    v1.inorder(root);
    cout << endl;

     root = deleteBST(root, 1);
    v1.inorder(root);
    cout << endl;


     root = deleteBST(root, 4);
    v1.inorder(root);
    cout << endl;


     root = deleteBST(root, 5);
    v1.inorder(root);
    cout << endl;
    return 0;
}
             