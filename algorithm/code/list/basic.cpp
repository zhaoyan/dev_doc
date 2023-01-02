#include <iostream>
#include <iomanip>
#include <concepts>
using namespace std;

struct Node {
    //* put next to nullptr, that is good style
    Node(int i) : data{ i }, next{ nullptr }{}
    int data;
    Node* next;
};

//* function need return void
void Display(Node* head) {
    Node* p = head;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
}

void Display_reverse(Node* head) {
    if (!head) {
        return;
    }
    Display_reverse(head->next);
    cout << head->data << endl;
}

Node* new_head{ nullptr };


//The basic idea is atomic action, When we only deal with one node, 
//we need to pass pre-code as parameter. that is why this recursive function 
//must have two parameter. 
void reverse_list(Node* cur, Node* pre) {
    if (!cur->next) {
        cur->next = pre;
        new_head = cur;
        return; //* recursive function must has return. 
    }
    Node* temp = cur->next;
    cur->next = pre;
    reverse_list(temp, cur);
}

//Node* merge_list(Node* phead1, Node* phead2) {
//    Node* head;
//    Node* p;
//    //deal with special case
//    //1) init 2) boundary 3) special 
//    if (phead1 == nullptr) {
//        head = phead2;
//    }
//    if (phead2 == nullptr) {
//        head = phead1;
//    }
//    Node* i = phead1;
//    Node* j = phead2;
//    if (i->data > j->data) {
//        head = i;
//        i = i->next;
//    }
//    else {
//        head = j;
//        j = j->next;
//    }
//    p = head;
//    while (i != nullptr && j != nullptr) {
//        if (i->data < j->data) {
//            i = i->next;
//            p->next = i;
//        }
//        else  {
//            j = j->next;
//            p->next = j;
//        }
//        p = p->next;
//    }
//    if (i != nullptr)
//        p->next = i;
//    if (j != nullptr)
//        p->next = j;
//
//    return head;
//}


Node* reverse_list_dummy(Node* head) {
    //Node dummy1{ 0 };
    //Node dummy2{ 0 };
    //dummy1.next = head;
    Node* pre, *current, *next;
    pre = nullptr;
    current = head;
    next = current;
    while (next) {
        next = current->next;
        current->next = pre;
        current = next;
        pre = current;
    }
    return current;
}




int main() {
    

    //build a list, usually for any list operation, 
    //*we need head node and p node, p node used to move.
    Node* head = new Node{ 0 };
    Node* p = head;
    p->next = new Node{ 1 };
    p = p->next;
    p->next = new Node{ 2 };
    Display(head);
    cout << "delete current node." << endl;
    p = head->next;
    cout << p->data << endl;
    Node* i = new Node{ 3 };
    while (p) { //* Basice style is use while(p), if you need special operation, 
                //* deal with it inside of while.
        std::swap(p->data, i->data);
        if (p->next)
            p = p->next;
        else { //* The last node should be deal spcially
            p->next = i;
            break;
        }
    }
    Display(head);
    cout << " delete current node" << endl;
    p = head->next;
    cout <<"current node"<< p->data << endl;
    Node* temp = p->next;
    p->data = temp->data;
    p->next = temp->next;
    delete temp;
    Display(head);

    cout << "reverse display" << endl;
    Display_reverse(head);

    cout << "reverse list" << endl;
    reverse_list(head, nullptr);
    Display(new_head);
}

