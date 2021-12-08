#include <iostream>
#include <iomanip>
#include "../../header/list.h"

Node::Node():
    data(-1), next(nullptr)
{}

LnkList::LnkList(): head(new Node())
{}

void LnkList::printList()
{
    std::cout << "list: ";

    Node *node = head;
    while (node != nullptr) {
        std::cout << std::setw(2) << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

void LnkList::initList(int *arr, int sz)
{
    head->data = arr[0];
    Node *current = head;
    for (int i = 1; i < sz; i++) {
        Node *node = new Node();
        node->data = arr[i];
        current->next = node;
        current = current->next;
    }
}

void LnkList::reverseList()
{
    Node *front   = nullptr;
    Node *current = head;
    Node *tail    = head->next;

    while (tail != nullptr) {
        current->next = front;
        front = current;
        current = tail;
        tail = tail->next;
    }
    current->next = front;

    head = current;
}