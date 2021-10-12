#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream&, std::vector<int>);

void swap(std::vector<int>&, int, int);
void quicksort(std::vector<int>&, int, int);
int  partition(std::vector<int>&, int, int);

int main(int argc, char **argv)
{
    int arr[] = {15, 10, 14, 17, 23, 2, 7};

    std::vector<int> list;
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        list.push_back(arr[i]);
    }

    std::cout << "Before sorting: " << list << std::endl << std::endl;
    quicksort(list, 0, list.size()-1);
    std::cout << "\nAfter sorting: " << list << std::endl;

    return 0;
}

std::ostream& operator<<(std::ostream &os, std::vector<int> list)
{
    for (std::vector<int>::iterator iter=list.begin(); iter != list.end(); iter++) {
        os << *iter << " ";
    }
    return os;
}

void swap(std::vector<int> &list, int i, int j)
{
    int tmp = list.at(i);
    list.at(i) = list.at(j);
    list.at(j) = tmp;
}

void quicksort(std::vector<int> &list, int left, int right)
{
    if (left < right) {
        int pivot_idx = partition(list, left, right);

        // All elements in the left subarray are all less or equal to list[pivot_idx] (unsorted)
        quicksort(list, left, pivot_idx-1);

        // All elements in the right subarray are all larger than list[pivot_idx] (unsorted)
        quicksort(list, pivot_idx+1, right);
    }
}

int partition(std::vector<int> &list, int left, int right)
{
    // choose the leftmost index as a pivot
    int pivot = list.at(left);
    int     i = left;
    for (int j=left+1; j <= right; j++) {
        if (list.at(j) <= pivot && (i=i+1) < j) {
            swap(list, i, j);
            std::cout << "swap(" << i << ", " << j << "): " << list << std::endl;
        }
    }
    swap(list, left, i);
    return i;
}