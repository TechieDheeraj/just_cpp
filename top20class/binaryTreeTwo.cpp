#include<iostream>
#include<vector>
#include<iterator>
#include<unordered_map>


/* Problem Statement:
    Find the Left most Node from bottom of tree
*/

using namespace std;

#include"btreeUtil.h"

using namespace bTreeUtil;

class LeftMostNode {

    public:

/* Using Queue:
    Doing Right to Left Push because Output required is Left Most Node

    TC: O(n), SC: O(n)
*/
        int leftMostNode1(BTree *root) {
            BTree *tmp = NULL;
            vector<BTree *> queue;

            tmp = root;
            queue.push_back(tmp);

            while(!queue.empty()) {
                tmp = queue.front();
                queue.erase(queue.begin());

                if(tmp->left == NULL && tmp->right == NULL)
                    return tmp->data;

                if(tmp->right != NULL)
                    queue.push_back(tmp->right);
                if(tmp->left != NULL)
                    queue.push_back(tmp->left);
            }
            return -1;
        }
        
        // It is being Used just to Pick First Element when NULL Occurs ( To Pick First node from Bottom Level in Tree
        enum state { NULLSTATE, NON_NULLSTATE};

/* Using Queue:
    Doing Left to Right Push

    TC: O(n), SC: O(n)
*/
        int leftMostNode2(BTree *root) {
            int result= 0;
            BTree *tmp = NULL;
            vector<BTree *> queue;

            tmp = root;
            queue.push_back(tmp);
            queue.push_back(NULL);

            enum state laststate = NULLSTATE;

            while(!queue.empty()) {
                tmp = queue.front();
                queue.erase(queue.begin());

                if(tmp == NULL) {
                    laststate = NULLSTATE;
                    if(!queue.empty()) {
                        queue.push_back(NULL);
                        continue;
                    }
                    else
                        break;
                }
                else {
                    if(laststate == NULLSTATE) {
                        result = tmp->data;
                        laststate = NON_NULLSTATE;
                    }
                }

                if(tmp->left != NULL)
                    queue.push_back(tmp->left);
                if(tmp->right != NULL)
                    queue.push_back(tmp->right);
            }
            return result;
        }

/*
    Using Recursion:

    Storing each Level Nodes into Hash Map and at last returning last Level's Left Most Node
*/

        void storeTree(unordered_map<int, vector <int> > &hMap, BTree *root, int level) {

            if(root == NULL)
                return;

            storeTree(hMap, root->left, level+1);
            hMap[level].push_back(root->data);
            storeTree(hMap, root->right, level+1);
        }

        int leftMostNode3(BTree *root) {
            int level = 1;
            unordered_map<int, vector<int> > hMap;

            storeTree(hMap, root, level);
/*
    To Print:
            for(auto i = hMap.begin(); i != hMap.end(); ++i) {
                cout << "Same Group of " << i->first << " : {";
                for(auto j : i->second)
                    cout << " " << j;
                cout << "}" << endl;
            }
*/
            auto i = hMap.size();

            return hMap.at(i)[0];
        }
};
        
int main() {

    LeftMostNode *obj = new LeftMostNode();

    cout << "Enter Size of Tree " << endl;
    cin >> bTreeUtil::size; 

    createOneChildTree();

    //cout << "Left Most Node is " << obj->leftMostNode1(bTreeUtil::root) << endl;
    //cout << "Left Most Node is " << obj->leftMostNode2(bTreeUtil::root) << endl;
    cout << "Left Most Node is " << obj->leftMostNode3(bTreeUtil::root) << endl;

    return 0;
}
