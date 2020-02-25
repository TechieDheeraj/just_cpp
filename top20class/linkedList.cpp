#include<iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

class LinkList {

    private:
        struct node *head; 
    public:
        int size;

        LinkList() { // constructor
            head = new node; // Creating Dummy node
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

            for(int i = 0; i < size; ++i) {
                cout << "Address: " << tmp << "->"; // Why It is coming 4 Bytes for 64-bit arch need to see 
                tmp = tmp->next;
            }
        }
};

class ReverseList {

    public:
        void testCase1(LinkList llobj) {

            for(int i = 0; i < llobj.size; ++i)
                llobj.addNode(i+1);
        }

        void reverseList(LinkList llobj) {
            
        }

};

int main() {

    LinkList llobj; // This will create on stack
    ReverseList obj; 

    cout << "Enter the number of LinkedList Nodes" << endl;

    cin >> llobj.size; 

    obj.testCase1(llobj);
    llobj.displayList();
    obj.reverseList(llobj);
   
    return 0;
}
