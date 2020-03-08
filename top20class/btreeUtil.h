#include<sys/time.h>

namespace bTreeUtil {
    
    struct BTree {
        int data;
        struct BTree *left;
        struct BTree *right;
    };

    int size;
    BTree *root = NULL; 

    struct BTree *createNode(int data) {
        struct BTree *node = new BTree;

        node->data = data;
        node->left = NULL;
        node->right = NULL;

        return node;
    }
    
    void createOneChildTree() {

        struct BTree *tmp = NULL;

        for(int i=0; i<size; ++i) {
            if(i == 0) {
                root = createNode(i+1);
                tmp = root;
                cout << tmp->data << "(Root) - " << tmp << endl;
                continue;
            }
            else if( i % 2 == 0) {
                tmp->left = createNode(i+1);
                cout << tmp->left->data << "(L) - " << tmp->left << endl;
                tmp = tmp->left;
            }
            else {
                tmp->right = createNode(i+1);
                cout << tmp->right->data << "(R) - " << tmp->right << endl;
                tmp = tmp->right;
            }
        }    
    }

    struct BTree *insertNode(BTree *node, int data) {
       
        struct BTree *current = NULL;
        struct timeval cur_time;

        gettimeofday(&cur_time, NULL);
        srand(cur_time.tv_sec);

        if(node == NULL) {
            node = createNode(data);
            //cout << "Node : " << node << endl;
            return node;
        }
        
        current = node;
        while(current != NULL) {
            if((rand() % 2 + (data * 3 * data)) % 2 == 0) {
                if(current->left == NULL) {
                    current->left = createNode(data);
                    //cout << " Inserting in Left of Node :" << current << " New Node: " << current->left << endl;
                    break;
                }
                current = current->left;
            }
            else {
                if(current->right == NULL) {
                    current->right = createNode(data);
                    //cout << " Inserting in Right of Node :" << current << " New Node: " << current->right << endl;
                    break;
                }
                current = current->right;
            }
        }
        return node;
    }

    void createRandomTree() {
        for(int i = 0; i < size; ++i) {
            root = insertNode(root, i+1);
        }
    }

    void inOrderTreeDisplay(struct BTree *node) {
        if(node == NULL)
            return;

        inOrderTreeDisplay(node->left);
        cout << node->data << endl;
        inOrderTreeDisplay(node->right);
    }

    void preOrderTreeDisplay(BTree *node, int nspaces, const char *type) {

        if(node == NULL) return;

        for(int i = 0; i < nspaces; ++i)
            cout << " ";
        cout << node->data << "(" << type << ")" << endl;

        preOrderTreeDisplay(node->left, nspaces + 4, "L");
        preOrderTreeDisplay(node->right, nspaces + 4, "R");
    }

    void displayTree(BTree *node) {
        preOrderTreeDisplay(node, 0, "Root");
    }

}
