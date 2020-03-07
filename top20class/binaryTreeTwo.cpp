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
};
        
int main() {

    LeftMostNode *obj = new LeftMostNode();

    cout << "Enter Size of Tree " << endl;
    cin >> bTreeUtil::size; 

    createOneChildTree();

    cout << "Left Mode Node is " << obj->leftMostNode1(bTreeUtil::root) << endl;

    return 0;
}
