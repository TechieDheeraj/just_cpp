#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<algorithm>

using namespace std;

#include"btreeUtil.h"

/*
   Problem Statement:
       Serialize and De-Serialize the Tree into String Format and and back to Tree 
*/

using namespace bTreeUtil;

#define NULLCHAR '#'
#define COMMA ','

class BTreeSerDe {

    private:
        string findInOrder(BTree *root) {
            string result = "";

            if(root == NULL) return "";

            result += findInOrder(root->left);
            result += to_string(root->data) + COMMA;
            result += findInOrder(root->right);

            return result;
        }

        string findPreOrder(BTree *root) {
            string result = "";

            if(root == NULL) return "";

            result += to_string(root->data) + COMMA;

            result += findPreOrder(root->left);
            result += findPreOrder(root->right);

            return result;
        }

        vector<string> tokenizeString(string data) {
            vector<string> sstring; // = new vector<string>();
            string substr;

            if(data.back() == ',')
                data.pop_back();

            if(data.front() == ',')
                data.erase(data.begin());

            istringstream s_stream(data);

            while(s_stream.good()) {

                getline(s_stream, substr, COMMA);
                sstring.push_back(substr);
            }

            return sstring;
        }

    public:
        //vector<char> serString;
        string serString;
        int nodeCounter = 0;

/*
Adhoc ->
    Preorder With Null Links

Using Stack ( recursive ) approach to traverse the tree and then using extra variable on Data Segment to Store result.
*/

        void BTreeSerialise1(BTree *root) {

            if (root == NULL) return;

            //serString.push_back((char) '`' + (root->data)); // Just to Map with characters
            //serString.push_back(COMMA);
            serString += to_string(root->data) + COMMA; // Just to Map with characters
            if(root->left == NULL) {
            /*
                serString.push_back(NULLCHAR); // Taking Extra Memory to Solve the Problem
                serString.push_back(COMMA);
            */
                serString += NULLCHAR;
                serString += COMMA;
            }

            BTreeSerialise1(root->left);

            if(root->right == NULL) {
            /*
                serString.push_back(NULLCHAR);
                serString.push_back(COMMA);
            */
                serString += NULLCHAR;
                serString += COMMA;
            }

            BTreeSerialise1(root->right);
        }

        BTree *buildTree(vector <string> data) {

            BTree *node;

            if(data[nodeCounter] == "#")
                return NULL;

            node = createNode(stoi(data[nodeCounter]));

            nodeCounter++;

            node->left = buildTree(data);

            nodeCounter++;

            node->right = buildTree(data);

            return node;
        }
/*
    De-Serialise Pre Order Serialised String
*/

        BTree *BTreeDeSerialise1(string data)  {
            vector <string> pString;
            string substr;
            BTree *root = NULL;

            pString = tokenizeString(data);

            root = buildTree(pString);

            return root;
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

    /* 
       Level Order with Null Links
     */

        string BTreeSerialise3(BTree *root) {
            string result = "";

            vector<BTree *> queue;
            BTree *tmp = root;

            queue.push_back(tmp);

            while(!queue.empty()) {
                tmp = queue.front();
                queue.erase(queue.begin());

                if(tmp == NULL) {
                    result += "#,"; 
                    continue;
                }

                result += to_string(tmp->data) + COMMA; 

                if(tmp->left != NULL) {
                    queue.push_back(tmp->left);
                }
                else if(tmp->left == NULL)
                    queue.push_back(NULL);

                if(tmp->right != NULL) {
                    queue.push_back(tmp->right);
                }
                else if(tmp->right == NULL)
                    queue.push_back(NULL);
            }
            return result;
        }

/*
    De-Serialise Level Order Serialised string
*/
        BTree *BTreeDeSerialise3(string data) {
           
            BTree *node = NULL;
            queue <BTree *> lqueue;
            vector <string> pString;
            nodeCounter = 0;

            pString = tokenizeString(data);

            lqueue.push(node);
        
            while(!lqueue.empty()) {
                node = lqueue.front();
                lqueue.pop();
                
                if(nodeCounter == 0) {
                    root = createNode(stoi(pString[nodeCounter]));
                    nodeCounter++;
                    node = root;
                }
                
                if(pString[nodeCounter] != "#"){

                    node->left = createNode(stoi(pString[nodeCounter]));
                    nodeCounter++;
                    lqueue.push(node->left);
                }
                else {
                    node->left = NULL;
                    nodeCounter++;
                }
                
                if(pString[nodeCounter] != "#"){
                    node->right = createNode(stoi(pString[nodeCounter]));
                    nodeCounter++;
                    lqueue.push(node->right);
                }
                else {
                    node->right = NULL;
                    nodeCounter++;
                }
            }

            return root; 
        }
/*
    Using PreOrder + InOrder Strings to Serialise
*/
        string BTreeSerialise4(BTree *root) {
            string inOrder = "";
            string preOrder = "";

            inOrder = findInOrder(root);
            cout << "Inorder string is " << inOrder << endl;
            preOrder = findPreOrder(root);
            cout << "Pre order string is " << preOrder << endl;

            return preOrder + NULLCHAR + COMMA + inOrder;
        }

/*
    De-Serialise in+pre Order Serialised string
*/
        int findElementByIndex(vector<string> array, string elem, int l, int r) {

            for(int i = l; l<=r; ++i) {
                if(array[i] == elem) return i;
            }
            return -1;
        }

        BTree *auxDeSer4(vector<string> &preString, vector<string> &inString, int l, int r) {

            string current;
            int cIndex;
            bool isRoot = false;
            BTree *node;

            if(l>r) return NULL;

            if(preString.size() == inString.size())
                isRoot = true;
                
            current = preString.front();
            preString.erase(preString.begin());

            node = createNode(stoi(current));
            if(isRoot) root = node; // Just Setting First node to Root defined in bTreeUtil

            cIndex = findElementByIndex(inString, current, l, r);

            node->left = auxDeSer4(preString, inString, l, cIndex-1);
            node->right = auxDeSer4(preString, inString, cIndex+1, r);

            return node;
        }

        BTree * BTreeDeSerialise4(string data) {
            vector<string> preString;
            vector<string> inString;
            
            string tmp;
            vector<string> tokenStr;// = new vector<string>;
            string inOrder, preOrder;

            istringstream sstream(data);

            while(getline(sstream, tmp, '#'))
                tokenStr.push_back(tmp);

            preOrder = tokenStr.at(0);
            inOrder = tokenStr.at(1);

            //copy((*preOrder).begin(), (*preOrder).end(), preOrder);
            //copy(tmp[1].begin(), tmp[1].end(), inOrder);

            preString = tokenizeString(preOrder);
            inString = tokenizeString(inOrder);

            return auxDeSer4(preString, inString, 0, inString.size()-1);
        }
};

int main() {

    BTreeSerDe *obj = new BTreeSerDe();
    string fString;

    cout << "Enter Size of Tree " << endl;
    cin >> bTreeUtil::size;

//    createOneChildTree();
    createRandomTree();
    displayTree(bTreeUtil::root);

/*
    Serialize Strings
*/

//    obj->BTreeSerialise1(bTreeUtil::root); // Storing in serString Global Object
//    cout << "PreOrder Serialise " << obj->serString << endl;

//    cout << "PreOrder Serialise is " << obj->BTreeSerialise2(bTreeUtil::root) << endl;
//    fString = obj->BTreeSerialise3(bTreeUtil::root);
//    cout << "Level Order Serialise " << fString << endl;
    fString = obj->BTreeSerialise4(bTreeUtil::root);
    cout << "Serialise String with In+Pre " << fString << endl;

/* 
    De-Serialise Strings
*/
//    BTree *node = obj->BTreeDeSerialise1(obj->serString);

//    BTree *node = obj->BTreeDeSerialise3(fString); // Level Order DeSer
    BTree *node = obj->BTreeDeSerialise4(fString); // Level Order DeSer
    displayTree(node);


    return 0;
}
