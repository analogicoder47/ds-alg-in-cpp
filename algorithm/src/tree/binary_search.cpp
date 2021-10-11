#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream&, std::vector<int>);
int binary_search(std::vector<int>, int);

int main(int argc, char **argv)
{
    std::vector<int> list;

    for (int idx = 0; idx < 10; idx++) {
        list.push_back(idx);
    }
    std::cout << "list:[" << list << "]" << std::endl;
    
    int result = binary_search(list, 3);
    if (result != -1) {
        std::cout << "target index: " << result << std::endl;
    } else {
        std::cout << "target not found in the list " << std::endl;
    }

    return 0;
}

std::ostream& operator<<(std::ostream &os, std::vector<int> list) {
    for (std::vector<int>::iterator iter=list.begin(); iter != list.end(); iter++) {
        os << *iter << " ";
    }
    return os;
}

int binary_search(std::vector<int> list, int target) {
    int left  = list.front();
    int right = list.back();

    int mid;
    while (left <= right) {
        mid = (left+right) / 2;
        if (list.at(mid) < target) {
            left = mid+1;
        } else if (list.at(mid) > target) {
            right = mid-1;
        } else {
            return mid;
        }
    }
    return -1;
}