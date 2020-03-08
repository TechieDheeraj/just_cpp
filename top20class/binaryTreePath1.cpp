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
                prev = tqueue.front();
                tqueue.erase(tqueue.begin());

                lpath = tmp->level;
                LChild = prev->root->left;
                RChild = prev->root->right;

                if(prev->root->left == NULL && prev->root->right == NULL && tqueue.empty())
                    break;

                if(LChild != NULL) {
                    tmp->level = lpath+1;
                    tmp->root = LChild;
                    tqueue.push_back(tmp);
                }
                    
                if(RChild != NULL) {
                    tmp->level = lpath+1;
                    tmp->root = RChild;
                    tqueue.push_back(tmp);
                }
            }
          
            return lpath; 
        }


/*
    Using Stack (Recusrive approach to traverse the tree) 
        TC: O(n)
        SC: O(n) -> n * stack_size
*/

        int traverseTree(BTree *root, int level) {

            int lpath = 0;

            if(root == NULL) return 0;
                
            lpath = traverseTree(root->left, level+1);
            //level = (level > lpath) ? level : lpath; 
            cout << "Level " << level  << " and lpath " << lpath << endl; 
            lpath = traverseTree(root->right, level+1);

            return level;
        }

        int bTreeLongPath2(BTree *root) {

            int level = 1;

            return traverseTree(root, level);
            
        }
};

int main() {

    BTreeLongPath *obj = new BTreeLongPath();

    cout << "Enter size of Tree " << endl;
    cin >> bTreeUtil::size;

    createOneChildTree();

    cout << "Longest Root to Leaf Path is " << obj->bTreeLongPath1(bTreeUtil::root) << endl;
    cout << "Longest Root to Leaf Path is " << obj->bTreeLongPath2(bTreeUtil::root) << endl;

    return 0;
}
