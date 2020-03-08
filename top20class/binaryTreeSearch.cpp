#include<iostream>
#include<vector>

using namespace std;

#include"btreeUtil.h"

using namespace bTreeUtil;

class BTreeSearch {

    public:
        int val; 

        /* Using Recursion:

            TC: O(n) 
            SC: O(n) -> n * stack Size
         */
        bool bTreeSearch1(BTree *root) {

            bool isTrue = false;

            if(root == NULL)
                return false;

            isTrue = bTreeSearch1(root->left);
            if(root->data == val)
                return true;

            if(!isTrue)
                isTrue = bTreeSearch1(root->right);

            //ret = (ret == true) ? ret : bTreeSearch1(root->right);

            return isTrue;
        }

        /*
            Using Queue:
            After pop checking if Key element is matching node data or not 
                TC: O(n)
                SC: O(n)
         */
        bool bTreeSearch2(BTree *root) {

            bool isTrue = false;
            BTree *tmp = root;
            vector <BTree *> queue;

            queue.push_back(tmp);
            while(!queue.empty()) {
                tmp = queue.front();
                queue.erase(queue.begin());

                isTrue = (tmp->data == val) ? true : false;

                if(isTrue) 
                    return true;

                if(tmp->left == NULL && tmp->right == NULL && queue.empty())
                    return false;

                if(tmp->left != NULL)
                    queue.push_back(tmp->left);

                if(tmp->right != NULL)
                    queue.push_back(tmp->right);
            }

            return false;
        }

        /*  
            Find Successor
            Using Null Checks
                TC: O(n)
                SC: O(1)
         */
        struct BTree *findSuccessor(BTree *root) {

            BTree *tmp = root; 
            BTree *prev = NULL;
            tmp = tmp->right;

            while(tmp!=NULL) {

                if(tmp == root)
                    break;

                prev = tmp;
                tmp = tmp->left;

            }
            return prev;
        }

        bool bTreeSearch3(BTree *root) {

            bool isTrue = false;
            BTree *tmp = root;
            BTree *prev = NULL;

            while(tmp != NULL) {

                isTrue = (tmp->data == val) ? true : false;

                if(isTrue)
                    return true;

                if(tmp->right != NULL) {
                    prev = findSuccessor(tmp);

                    if(prev->left != NULL) {
                        cout << "For Check" << endl;
                        prev->left = NULL;
                        tmp = tmp->left;
                    }
                    else {
                        prev->left = tmp;
                        tmp = tmp->right;
                    }
                }
                else if(tmp->left != NULL)
                    tmp = tmp->left;

            }
            return false; 
        }
};

int main() {

    BTreeSearch *obj = new BTreeSearch();
    cout << "Enter Size of tree" << endl;
    cin >> bTreeUtil::size;

    cout << "Enter Key Element to Search" << endl;
    cin >> obj->val;

    createOneChildTree();

    //cout << "Element Existence : " << boolalpha << obj->bTreeSearch1(bTreeUtil::root) << endl;
    //cout << "Element Existence : " << boolalpha << obj->bTreeSearch2(bTreeUtil::root) << endl;
    cout << "Element Existence : " << boolalpha << obj->bTreeSearch3(bTreeUtil::root) << endl;


    return 0;
}
