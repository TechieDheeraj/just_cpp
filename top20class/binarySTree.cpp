#include<iostream>

using namespace std;

#include"bstUtil.h"

using namespace bSTUtil;

class BSTSearch {
/*
    public:

       int bstSearch1(BSTree *root) {


       }
*/



};

int main() {

    BSTSearch obj;
    BSTree *root = NULL;

    cout << "Enter the Size of BST " << endl;

    cin >> bSTUtil::size;

    root = createRandomBST();

    cout << "root " << root << endl;

    displayBST(root);

}

