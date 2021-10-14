#ifndef _INCLUDE_SEARCHING_H_
#define _INCLUDE_SEARCHING_H_

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream&, std::vector<int>);
void          print(int);

int binary_search(std::vector<int>&, int);
int interpolation_search(std::vector<int>&, int);

#endif