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

        Using Stack ( recursive ) approach to traverse the tree and then using extra variable on Data Segment to Store result.
*/

        void BTreeSerialise1(BTree *root) {

            if (root == NULL) return;

            serString.push_back((char) '`' + (root->data)); // Just to Map with characters
            serString.push_back(COMMA);

            if(root->left == NULL) {
                serString.push_back(NULLCHAR); // Taking Extra Memory to Solve the Problem
                serString.push_back(COMMA);
            }
            
            BTreeSerialise1(root->left);

            if(root->right == NULL) {
                serString.push_back(NULLCHAR);
                serString.push_back(COMMA);
            }

            BTreeSerialise1(root->right);
        }
/*
    Adhoc ->
        Preorder With Null Links

        Using direct recursive approach to solve the problem.
*/
        string BTreeSerialise2(BTree *root) {
            string left = "";
            string right = "";
            if(root == NULL) return "#,";

            left = BTreeSerialise2(root->left);
            right = BTreeSerialise2(root->right);

            return to_string(root->data) + "," + left + right; 
        }
};

int main() {

    BTreeSerDe *obj = new BTreeSerDe();

    cout << "Enter Size of Tree " << endl;
    cin >> bTreeUtil::size;

    createOneChildTree();

    obj->BTreeSerialise1(bTreeUtil::root);

    cout << "Serialised String is " << obj->serString << endl;

    cout << "Serialises String 2 is " << obj->BTreeSerialise2(bTreeUtil::root) << endl;

    return 0;
}
