#include<iostream>

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
                cout << tmp << "->";
                tmp = tmp->next;
            }
            cout << "\n";
        }
};

class ReverseList {

    public:
        void testCase1(LinkList llobj) {

            for(int i = 0; i < llobj.size; ++i)
                llobj.addNode(i+1);
        }

        int reverseList1(LinkList llobj) {
            struct node *current, *tmp, *prev = NULL;;

            if(llobj.head->next == NULL)
                return -1;

            current = llobj.head->next;
            while(current->next != NULL) {
                tmp = current->next;
                current->next = prev;
                prev = current;
                current = tmp;
            }

            return 0;
        }
};

int main() {

    LinkList llobj; // This will create on stack
    ReverseList obj; 

    cout << "Enter the number of LinkedList Nodes" << endl;

    cin >> llobj.size; 

    obj.testCase1(llobj);
    llobj.displayList();
    obj.reverseList1(llobj);
    llobj.displayList();
   
    return 0;
}
