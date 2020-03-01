#include<iostream>
#include<unordered_set>

using namespace std;

struct node {
    int data;
    struct node *next;
};

class LinkList {

   // private:
   //     struct node *head; 
    public:
        int size;
        struct node *head; 

        LinkList() { // constructor
            head = new node; // Creating Dummy node
            head->data = 22;
            head->next = NULL; 
        }

        struct node * addNode(int input) {
            void *ptr = NULL;

            struct node *tmp = new node; // Also Can do Malloc for whole Struct node and return pointer.

            if(tmp != NULL) {
                tmp->data = input;
                tmp->next = NULL;
            }

            if( head->next == NULL)
                head->next = tmp;
            else {                      // Adding Node at the Beginning
                ptr = head->next;
                head->next = tmp;
                tmp->next = (struct node *)ptr;
            }
         return tmp;
        }

        void displayList() {
            struct node *tmp = head;

            cout << tmp << "->";
            tmp = tmp->next;

            while(tmp != NULL) {
                cout << tmp << "->";
                tmp = tmp->next;
            }
            cout << "\n";
        }
};

class LoopInLinkList {
    
    public:
        int size;

        void testCase1(LinkList& llobj) {
            struct node *ptr = NULL;

            for( int i =0; i < llobj.size-1; ++i)
                ptr = llobj.addNode(i+2);

            ptr->next = new node; // node is Struct node
            ptr->next->data = 10;
            ptr->next->next = ptr;
            
        }

/*
    Traversing through each Node of Link List then first checking and Pushing Each node's Address into HashSet, If there is loop the same address could be inserted into hashset
    TC: n * 2 * O(1) -> O(n), SC: O(n)
*/
        bool loopInLinkList1(LinkList& llobj) {
            struct node *tmp;
            unordered_set<struct node *> hashSet;            

            tmp = llobj.head->next;

            for(int i =0; i < size; i++) {
                if(hashSet.find(tmp) == hashSet.end()) 
                    hashSet.insert(tmp);
                else
                    return true;
                tmp = tmp->next;
            }
            return false;
        }
};

int main() {
    
    LinkList llobj;
    LoopInLinkList obj;

    cout << "Enter the number of LinkedList Nodes" << endl;

    cin >> llobj.size; 

    obj.testCase1(llobj);
    //llobj.displayList(); // Commenting because Loop is there

    cout << "Loop Existence is " << boolalpha << obj.loopInLinkList1(llobj) << endl;

    return 0;
}
