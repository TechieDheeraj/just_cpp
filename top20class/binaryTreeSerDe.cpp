#include<iostream>

using namespace std;

#include"btreeUtil.h"

/*
    Problem Statement:
        Serialize the Tree into String Format and also De-Serialize
*/

using namespace bTreeUtil;

#define NULLCHAR '#'
#define COMMA ','

class BTreeSerDe {
    
    public:
        //vector<char> serString;
        string serString;

/*
    Adhoc ->
        Preorder With Null Links
*/

        void BTreeSerialise1(BTree *root) {

            if (root == NULL) return;

            serString.push_back((char) '`' + (root->data)); // Just to Map with characters
            serString.push_back(COMMA);

            if(root->left == NULL) {
                serString.push_back(NULLCHAR);
                serString.push_back(COMMA);
            }
            
            BTreeSerialise1(root->left);

            if(root->right == NULL) {
                serString.push_back(NULLCHAR);
                serString.push_back(COMMA);
            }

            BTreeSerialise1(root->right);
        }
};

int main() {

    BTreeSerDe *obj = new BTreeSerDe();

    cout << "Enter Size of Tree " << endl;
    cin >> bTreeUtil::size;

    createOneChildTree();

    obj->BTreeSerialise1(bTreeUtil::root);

    cout << "Serialised String is " << obj->serString << endl;

    return 0;
}
