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

    void displayTree(struct BTree *node) {
        if(root == NULL)
            return;

        displayTree(node->left);
        cout << node->data << endl;
        displayTree(node->right);
    }
}
