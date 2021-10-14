#include "binary_search.cpp"
#include "interpolation_search.cpp"

int main(int argc, char **argv)
{
    std::vector<int> list;
    for (int idx = 0; idx <= 10; idx++) {
        list.push_back(idx*2+1);
    }

    int target = 19, result = -1;
    std::cout << "binary search result..." << std::endl;
    print(binary_search(list, target) );

    std::cout << "************************" << std::endl;
    std::cout << "interpolation result..." << std::endl;
    print(interpolation_search(list, target) );

    return 0;
}

std::ostream& operator<<(std::ostream &os, std::vector<int> list) {
    for (std::vector<int>::iterator iter=list.begin(); iter != list.end(); iter++) {
        os << *iter << " ";
    }
    return os;
}

void print(int result) {
    if (result != -1)
        std::cout << "target index: " << result << std::endl;
    else
        std::cout << "Not found" << std::endl;
}