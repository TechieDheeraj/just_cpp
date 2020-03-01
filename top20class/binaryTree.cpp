#include<iostream>
#include<vector>
#include<stack>
#include<queue>
//#include<bits/stdc++.h>

/*
    Problem Statement:
    Find Size (No. of NOdes) of Binary Tree
*/

using namespace std;

struct BTree {
    int data;
    struct BTree *left;
    struct BTree *right;
};

/*
class Stack {

    public:
        int top;
        int array[MAX_SIZE];

        void push(int data) {
            
};
*/

class BinaryTree {

    public:
        int size;
        struct BTree *root = NULL;
      /* 
        BinaryTree() {
            root = new BTree;
        }
      */

        struct BTree *createNode(int data) {

            struct BTree *node = new BTree;
            node->data = data;
            node->left = NULL;
            node->right = NULL;

            return node;
        }

        void testCase1() { // Creating Tree
                
            struct BTree *tmp = NULL;

            for(int i = 0; i < size; ++i) {
                if( i == 0) {
                    root = createNode(i+1);
                    tmp = root;
                    cout << tmp->data << "(Root) - " << tmp << endl;
                    continue;
                }
                if(i % 2 == 0) {
                    tmp->left = createNode(i+1);
                    cout << tmp->left->data << "(L) - " << tmp->left << endl;
                    tmp = tmp->left;
                }
                else { 
                    tmp->right = createNode(i+1);
                    cout << tmp->right->data << "(R) - " << tmp->right << endl;
                    tmp = tmp->right;
                }
            }
        }

        void display(struct BTree *node) { // Inorder Display

            if(node == NULL)
                return;

            display(node->left);
            cout << node->data << "(L)" << endl;      
            display(node->right);
        }


/*
    Going Level By level in Binary Tree (Not BST), Pushed Each Nodes Child into Stack at every Iteration
    TC: n * 2 * O(1) (Adding at Last and Removing from Last) (O(n) if vector implementation is traversing through each node for both operations), SC: O(n)
*/
        int nodesBinaryT1() {

            struct BTree *tmp;
            int count = 0;
            vector<struct BTree *> array; // Used as Stack (LIFO)

            array.push_back(root); // Pushed Root Node into Stack

            while(!array.empty()) {

                tmp = array.back();
                array.pop_back();
                ++count;

                if(tmp->left != NULL) 
                    array.push_back(tmp->left); //Pushed Left Node into Stack
                                
                if(tmp->right != NULL)
                    array.push_back(tmp->right); //Pushed Right Node into Stack
            }
            return count;
         }

  // TC: O(n), SC: -> n/2 ->  O(n)

       int nodesBinaryT12() {

         int count = 0;
         struct BTree *tmp = NULL;
         stack<struct BTree *> array;

         tmp = root;
         array.push(tmp);

         while(!array.empty()) {

            tmp = array.top();
            ++count;
            array.pop();

            if(tmp->left != NULL)
                array.push(tmp->left);
            if(tmp->right != NULL)
                array.push(tmp->right);
         }
         return count;
      }
/*
    Going Level By level in Binary Tree (Not BST), Pushed Each Nodes Child into Queue at every Iteration
    TC: n * 2 * O(1) (Adding at Last and remove at first) (O(n) if vector implementation is traversing through each node for both operations)
    SC: O(n/2) -> Because At Last Level of Binary Tree it has maximum n/2 nodes 
*/
      int nodesBinaryT2() {

          int count = 0;
          struct BTree *tmp = NULL;
          vector<struct BTree *> array; // Used as Queue (FIFO)

          tmp = root;
          array.push_back(tmp);

          while(!array.empty()) {

              tmp = array.front();
              array.erase(array.begin());
              ++count;
            
              if(tmp->left !=NULL)
                  array.push_back(tmp->left);
  //                array.insert(array.begin(), tmp->left);
          
              if(tmp->right !=NULL)
                  array.push_back(tmp->right);
//                  array.insert(array.begin(), tmp->right);
          }
          return count;    
      }

  // TC: O(n), SC: -> n/2 ->  O(n)

      int nodesBinaryT22() {

         int count = 0;
         struct BTree *tmp = NULL;
         queue<struct BTree *> array;

         tmp = root;
         array.push(tmp); // FIFO

         while(!array.empty()) {

            tmp = array.front();
            ++count;
            array.pop();

            if(tmp->left != NULL)
                array.push(tmp->left);
            if(tmp->right != NULL)
                array.push(tmp->right);
         }
         return count;
      }

/* Using Recursive Approach

1. Recusrive Thinking
2. Divide and Conquer 

To Understand Recursive -> 

     (1)
     / \
   (3) (2)

Going to Each Node's Left then Right then returning from Node and Incrementing the counter.

It's Just Recursion magic

TC: 3 * n == O(n), SC: (n * Stack Size) == O(n)

*/

        int nodesBinaryT3(struct BTree *topmost) {

            int count = 0;
            BTree *tmp = NULL;

            tmp = topmost;

            if(tmp != NULL) {
                count += nodesBinaryT3(tmp->left);
                count += nodesBinaryT3(tmp->right);
            }
            else
                return 0;

            return ++count; // Including Root node
        }

        struct BTree *findPredecessor(struct BTree *topmost) {
            struct BTree *tmp = NULL, *prev = NULL;

            tmp = topmost;
            cout << "Predecessor is :" << tmp << endl;

            // Inorder Predecessor ( First Left then Right most Node )
            if(tmp != NULL) {
                tmp = tmp->left;
                cout << "tmp is :" << tmp << endl;
                while(tmp != NULL) { 
                    prev = tmp;
                    cout << "Predecessor in func is :" << prev << " Left " << prev->left << " Right " << prev->right << endl;
                    tmp = tmp->right;
                }
            }
            return prev;
        }
/* 
    Adhoc -> 
        1. Inorder Predecessor
        2. Null Links
*/

        int nodesBinaryT4(struct BTree *topmost) {

            BTree *tmp = NULL;
            BTree *ptr = NULL;
            int count = 0;

            tmp = topmost;

            while(tmp != NULL) {
                cout << "Predecessor at line is :" << tmp << " Left " << tmp->right->left << " Right " << tmp->right << endl;
                if(tmp->left != NULL) {
                    ptr = findPredecessor(tmp);   
                    //cout << "Predecessor is :" << ptr << endl;
                    ptr->right = tmp;
                    tmp = tmp->left;
                }

                if(tmp->left == NULL) { // Bottom Leaf Node 
                    ++count;
                    if(tmp->right != NULL) {
                        tmp = tmp->right;
                        if(tmp->right != NULL) {
                            ++count;
                            tmp = tmp->right;
                        }
                    }
                }
            }
            return count;
        }
};

int main() {

    BinaryTree obj;
    cout << "Enter No. of Nodes" << endl; 

    cin >> obj.size;

    obj.testCase1();
    // obj.display(obj.root);
    // cout << "No. of Nodes: " << obj.nodesBinaryT1() << endl;
    // cout << "No. of Nodes: " << obj.nodesBinaryT2() << endl;
    // cout << "No. of Nodes: " << obj.nodesBinaryT12() << endl;
    // cout << "No. of Nodes: " << obj.nodesBinaryT22() << endl;
    //cout << "No. of Nodes: " << obj.nodesBinaryT3(obj.root) << endl;
    cout << "No. of Nodes: " << obj.nodesBinaryT4(obj.root) << endl;

    return 0;
}
