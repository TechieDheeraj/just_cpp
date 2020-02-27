#include<iostream>

using namespace std;

struct BTree {
    int data;
    struct BTree *left;
    struct BTree *right;
};

class BinaryTree {

    public:
        int size;
        struct BTree *root = NULL;
      /* 
        BinaryTree() {
            root = new BTree;
        }
      */

        struct BTree *createNode(int data, struct BTree *node) {

            node = new BTree;
            node->data = data;
            node->left = NULL;
            node->right = NULL;

            return node;
        }

        void testCase1() { // Creating Tree
                
            struct BTree *tmp = NULL;

            for(int i = 0; i < size; ++i) {
                if( i == 0) {
                    root = createNode(i+1, root);         
                    tmp = root;
                    continue;
                }
                if(i % 2 == 0) {
                    tmp->left = createNode(i+1, tmp->left);
                    tmp = tmp->left;
                }
                else { 
                    tmp->right = createNode(i+1, tmp->right);
                    tmp = tmp->right;
                }
            }
        }

        void display(struct BTree *node) { // Inorder Display

            if(node == NULL)
                return;

            display(node->left);
            cout << node->data << "(L)" << endl;      
            display(node->right);
        }
};

int main() {

    BinaryTree obj;
    cout << "Enter No. of Nodes" << endl; 

    cin >> obj.size;

    obj.testCase1();
    obj.display(obj.root);

    return 0;
}
