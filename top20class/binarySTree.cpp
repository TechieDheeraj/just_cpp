#include<iostream>

using namespace std;

#include"bstUtil.h"

using namespace bSTUtil;

class BSTSearch {

    public:

        bool bstSearch1(BSTree *root, unsigned int key) {

            bool isFound = false;

            if(root == NULL) return false;

            if(key == root->data)
                return true;

            if(key < root->data)
                isFound = bstSearch1(root->left, key);

            if(!isFound)
                isFound = bstSearch1(root->right, key);

            return isFound;
        }
};

int main() {

    BSTSearch obj;
    BSTree *root = NULL;

    unsigned int key;

    cout << "Enter the Size of BST " << endl;
    cin >> bSTUtil::size;

    cout << "Enter the Key element" << endl;
    cin >> key;

    root = createRandomBST();
    displayBST(root);

    cout << "Element Existence : " << boolalpha << obj.bstSearch1(root, key) << endl;

    return 0;
}

