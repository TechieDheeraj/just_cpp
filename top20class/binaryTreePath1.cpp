#include<iostream>
#include<vector>

/*
    Problem Statement:
        Find Longest root to leaf path in binary Tree
*/

using namespace std;

#include"btreeUtil.h"

using namespace bTreeUtil;

struct TQueue {
    int level;
    struct BTree *root;
};

class BTreeLongPath {

    public:
/* 

    Using Queue:
        TC:O(n)
        SC:O(n)
*/
// TODO: Tested on One Child Tree, Need to see if multiple nodes at same level. It will fail because tmp->root is getting modified again for right child
        int bTreeLongPath1(BTree *root) {

            int lpath = 0;
            vector <TQueue *> tqueue;
            struct TQueue *tmp = new TQueue;
            struct TQueue *prev = NULL;
            struct BTree *LChild = NULL, *RChild = NULL;

            tmp->level = 1;
            tmp->root = root;

            tqueue.push_back(tmp);

            while(!tqueue.empty()) {
                cout << " size of queue "<< tqueue.size() << endl;
                prev = tqueue.front();
                tqueue.erase(tqueue.begin());
                cout << " root " << prev->root << " left " << prev->root->left << " right" << prev->root->right << endl;

                lpath = prev->level;
                cout << " lpath "<< lpath << endl;
                LChild = prev->root->left;
                RChild = prev->root->right;

                if(prev->root->left == NULL && prev->root->right == NULL && tqueue.empty())
                    break;

                if(LChild != NULL) {
                    cout  << " pushed left of "<< prev->root << endl; 
                    tmp->level = lpath+1;
                    tmp->root = LChild;
                    tqueue.push_back(tmp);
                }
                    
                if(RChild != NULL) {
                    cout  << " pushed right of "<< prev->root << endl; 
                    tmp->level = lpath+1;
                    tmp->root = RChild;
                    tqueue.push_back(tmp);
                }
            }
          
            return lpath; 
        }


/*
    Using Stack (Recusrive approach to traverse the tree not USING Direct Recusrion to Solve Problem Just taking help of recursion and updating result in global variable instead of passing on stack) 
        TC: O(n)
        SC: O(n) -> n * stack_size
*/

        void traverseTree1(BTree *root, int level, int *maxHeight) {

            if(root == NULL) return;
                
            traverseTree1(root->left, level+1, maxHeight);
            *maxHeight = (*maxHeight > level) ? *maxHeight : level;
            traverseTree1(root->right, level+1, maxHeight);
        }

        int bTreeLongPath2(BTree *root) {

            int level = 1;
            int maxHeight = 0;;

            traverseTree1(root, level, &maxHeight);
            return maxHeight;
        }
/*
    Using Recusrion to Solve Problem
        TC: O(n)
        SC: O(n) -> n * stack_size
*/
        int traverseTree2(BTree *root, int level) {
            int lpath = 0;
            int rpath = 0;
                
            if(root == NULL) return 0;

            lpath = traverseTree2(root->left, level+1);

            lpath = ( lpath > level ) ? lpath : level;
            rpath = traverseTree2(root->right, level+1);

            return (lpath > rpath) ? lpath : rpath;
        }

        int bTreeLongPath3(BTree *root) {
            int level = 1;
            return traverseTree2(root, level);
        }
};

int main() {

    BTreeLongPath *obj = new BTreeLongPath();

    cout << "Enter size of Tree " << endl;
    cin >> bTreeUtil::size;

//    createOneChildTree();

    createRandomTree();
    displayTree(bTreeUtil::root);

//    cout << "Longest Root to Leaf Path is " << obj->bTreeLongPath1(bTreeUtil::root) << endl;
    cout << "Longest Root to Leaf Path is " << obj->bTreeLongPath2(bTreeUtil::root) << endl;
    cout << "Longest Root to Leaf Path is " << obj->bTreeLongPath3(bTreeUtil::root) << endl;

    return 0;
}
