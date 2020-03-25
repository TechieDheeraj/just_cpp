#include<sys/time.h>

namespace bSTUtil {

    struct BSTree {
        unsigned int data;
        struct BSTree *left;
        struct BSTree *right;
    };

    unsigned int size;

    struct BSTree *createNode(int data) {
        struct BSTree *node = NULL;

        node = new BSTree;

        node->data = data;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    BSTree *insertNode(BSTree *root, unsigned int data) {
        BSTree *current = NULL;

        //data = (rand() % 100) +1; // / (((data+1) * 3 * (data+1)) % 100));
        data = ((rand() / ((data+1) * 3 * (data+1))) % size) + (size/3);

        if(root == NULL) {
            root = createNode(data);
            return root;
        }
        
        current = root;
        while(current != NULL) {
            if(data <= 0) exit(0);
            if(data < current->data) {
                if(current->left == NULL) {
                    current->left = createNode(data);
                    break;
                }
                current = current->left;
            }
            else if(data == current->data) { 
                if(current->right == NULL) {
                    current->right = createNode(data+current->data);
                    break;
                }
                else {
                    data-=2;  // TODO: To make less duplicates, Shall Reconsider
                    continue;
                }
            }
            else {
                if(current->right == NULL) {
                    current->right = createNode(data);
                    break;
                }
                current = current->right;
            }
        }
        return root;
    }

    struct BSTree *createRandomBST() {
        struct timeval cur_time;

        gettimeofday(&cur_time, NULL);
        srand(cur_time.tv_sec);

        BSTree *root = NULL;

        for(unsigned int i = 0; i < size; ++i) {
            root = insertNode(root, i+i);
        }

        return root;
    }

    void displayTree(struct BSTree *root, int nspaces, const char *type) {

        if(root == NULL) return;

        for(int i = 0; i < nspaces; ++i)
            cout << " ";

        cout << root->data << "(" << type << ")" << endl; 

        displayTree(root->left, nspaces+4, "L");
        displayTree(root->right, nspaces+4, "R");
    }

    void displayBST(struct BSTree *root) {
        displayTree(root, 0, "Root");
    }

}
