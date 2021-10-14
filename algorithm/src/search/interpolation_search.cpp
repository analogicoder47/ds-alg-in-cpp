/**************************************
 * the best-case  time complexity: O(1)
 * the average    time complexity: O(n)
 * the worst-case time complexity: O(n)
 **************************************/
#include "../../include/searching.h"

inline int interpolation_search(std::vector<int> &list, int target)
{
    int low  = 0;
    int high = list.size()-1;

    int mid;
    while (low <= high) {
        mid = low + (high-low)*( (target-list.at(low))/(list.at(high)-list.at(low)) );

        if (list.at(mid) == target ) {
            return mid;
        } else if (target < list.at(mid) ) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}