/*****************************************
 * the best-case  time complexity: O(1)
 * the average    time complexity: O(logn)
 * the worst-case time complexity: O(logn)
 *****************************************/
#include "../../include/searching.h"

inline int binary_search(std::vector<int> &list, int target) {
    int left  = 0;
    int right = list.size()-1;

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