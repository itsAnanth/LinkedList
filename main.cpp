#include <iostream>
#include <vector>

/**
 * Basic representation of a linked list
 * 
 * [1, pointer to 2] (head) -> [2, pointer to 3] -> [3, pointer to null] (tail)
 */

struct Node {
    int data;
    Node * next;
};

class LinkedList {
    private:
        Node * head;
    public:
        LinkedList() {
            head = NULL; // initialize with head pointing to null
        }

        void push(int x); // add element to the end (javascript function names lol)
        void unshift(int x); // add element to the beginning
        void print(); // prints all nodes in a list
        std::vector<int> toVector();
};

int main() {
    LinkedList list;
    list.print();

    list.push(1);
    list.push(5);
    list.print();
    std::vector<int> vectorForm = list.toVector();
    for (auto i : vectorForm)
        std::cout << i << " ";
};


void LinkedList::unshift(int x) {
    Node * newNode = new Node();
    newNode -> data = x;
    newNode -> next = head; // point to next node or NULL if first element
    head = newNode; // make this element the head because its on the top of the list 
};

void LinkedList::push(int x) {
    Node * newNode = new Node();
    Node * temp = new Node();
    temp = head; // new var because we don't want to change the value of head
    newNode -> data = x;
    if (temp == NULL) { // there are no elements in the list
        newNode -> next = NULL; // this being the last and only element in the list, point it to null
        head = newNode; // since this is the only element, this will be the first element as well and point head to this node
        return;
    }

    while(temp -> next != NULL) { // loop till last element is reached which will point to null
        temp = temp -> next; // updating temp to make the iteration possible
    }
    /**
     * representation
     * 1 -> 2 -> 3 -> null
     * after inserting
     * 1 -> 2 -> 3 -> newNode (4) -> null
     * temp -> next = newNode so that 3 will point to 4 which was initially null as it was the last element :O
     */
    newNode -> next = NULL;
    temp -> next = newNode;
};

void LinkedList::print() {
    Node * current = head;
    if (current == NULL) 
        std::cout << "this is an empty list aaa" << std::endl;
    while (current != NULL) {
        std::cout << current -> data << std::endl;
        current = current -> next;
    }

    std::cout << std::endl;
}

std::vector<int> LinkedList::toVector() {
    std::vector<int> arr;
    Node * current = head;
    if (current == NULL) 
        return arr;
    while (current != NULL) {
        arr.push_back(current -> data);
        current = current -> next;
    }

    return arr;
}