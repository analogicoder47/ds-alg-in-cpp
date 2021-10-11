#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream&, std::vector<int>);
void          selection_sort(std::vector<int>&);

int main()
{
    std::vector<int> list;
    int arr[] = {5, 12, 3, 18, 9, 10, 39, 21, 99};
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        list.push_back(arr[i]);
    }

    std::cout << "Before sorting..." << std::endl;
    std::cout << list << std::endl;

    selection_sort(list);
    std::cout << "After sorting..." << std::endl;
    std::cout << list << std::endl;

    return 0;
}

std::ostream& operator<<(std::ostream &os, std::vector<int> list) {
    for (std::vector<int>::iterator iter=list.begin(); iter != list.end(); iter++)
        os << *iter << " ";

    return os;
}

void selection_sort(std::vector<int> &list) {
    int tmp;    
    int list_len = list.size();

    for (int i = 0, j = 0; i < list_len-1; i++) {
        j = i+1;
        while (j <= list_len-1) {
            if (list.at(i) > list.at(j) ) {
                tmp = list.at(i);
                list.at(i) = list.at(j);
                list.at(j) = tmp;
            }
            j++;
        }
    }
}