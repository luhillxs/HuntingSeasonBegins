#include "stdafx.h"

#include <iostream>
#include <vector>



using namespace std;

vector<int> bubbleSort(vector<int>& nums) {
	nums[0] += 1;
	return nums;
}

int main()
{
	int elem1[6] = {
		45,99,45,1,0,32 };
	vector<int> nums(elem1, elem1 + 6);
	nums = bubbleSort(nums);
	for (int i = 0; i < nums.size(); ++i) {
		std::cout << nums[i] << " ";
	}
	std::cout << endl;
    return 0;
}



