#include <iostream>
#include "../../header/list.h"

int main(int argc, char* argv[])
{
    int arr[]{1, 3, 4, 7, 9, 11, 18, 23, 29};

    LnkList list;
    list.initList(arr, sizeof(arr)/sizeof(arr[0]) );
    list.printList();

    list.reverseList();
    list.printList();

    return 0;
}