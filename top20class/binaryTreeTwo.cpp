#include<iostream>
#include<vector>

using namespace std;

#include"btreeUtil.h"

using namespace bTreeUtil;

class LeftMostNode {

    public:

/* Using Queue:
    Doing Right to Left Push because Output required is Left Most Node

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
};
        
int main() {

    LeftMostNode *obj = new LeftMostNode();

    cout << "Enter Size of Tree " << endl;
    cin >> bTreeUtil::size; 

    createOneChildTree();

    //cout << "Left Most Node is " << obj->leftMostNode1(bTreeUtil::root) << endl;
    cout << "Left Most Node is " << obj->leftMostNode2(bTreeUtil::root) << endl;

    return 0;
}
