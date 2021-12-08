#ifndef LIST_H_
#define LIST_H_

struct Node {
    Node();

    int  data;
    Node *next;
};

struct LnkList {
    LnkList();

    void printList();
    void initList(int*, int);
    void reverseList();

    Node *head;
};

#endif