#include<iostream>

using namespace std;

/* 
    Problem Statement:
        Reverse a Single Linklist
*/

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

        void addNode(int input) {
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

class ReverseList {

    public:
        void testCase1(LinkList& llobj) {

            for(int i = 0; i < llobj.size; ++i)
                llobj.addNode(i+1);
        }

/* 
    Using Three Pointers just reversing the linklist
    TC: O(n), SC: O(1)
*/
        void reverseList1(LinkList& llobj) {
            struct node *current, *tmp, *prev = NULL;;

            if(llobj.head->next == NULL)
                cout << "Empty Linklist" << endl; 

            current = llobj.head->next;
            while(current != NULL) {
                tmp = current->next;
                current->next = prev;
                prev = current;
                current = tmp;
            }
            llobj.head->next = prev;
        }

/*  With Two Pointers instead of Three
    TC: O(n), SC: O(1)
*/
        void reverseList2(LinkList& llobj) {
            struct node *current, *prev = nullptr;

            current = llobj.head->next;

            while(current != NULL) {
                current->next =(struct node *)((uintptr_t)current->next ^ (uintptr_t)prev);  // Bit-wise operations not allowed on pointer so converted into uintptr_t
                prev =(struct node *)((uintptr_t)current->next ^ (uintptr_t)prev); 
                current->next =(struct node *)((uintptr_t)current->next ^ (uintptr_t)prev); 
                // Till above steps prev and current->next is swapped
                // Now need to swap the current and prev 

                current =(struct node *)((uintptr_t)current ^ (uintptr_t)prev);  // Bit-wise operations not allowed on pointer so converted into uintptr_t
                prev =(struct node *)((uintptr_t)current ^ (uintptr_t)prev); 
                current =(struct node *)((uintptr_t)current ^ (uintptr_t)prev); 
            }
            llobj.head->next = prev;
        }
};

int main() {

    LinkList llobj; // This will create on stack
    ReverseList obj; 

    cout << "Enter the number of LinkedList Nodes" << endl;

    cin >> llobj.size; 

    obj.testCase1(llobj);
    llobj.displayList();
   // obj.reverseList1(llobj);
    obj.reverseList2(llobj);
    llobj.displayList();
   
    return 0;
}
