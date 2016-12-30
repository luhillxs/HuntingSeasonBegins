/*
Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=0;
        if(nums.size()==0){
            return 0;
        }
        else{
            for(i=0;i<nums.size();++i){
                if(nums[i]!=val){
                    nums[j] = nums[i];
                    j+=1;
                }
            }
            return j;
        }
    }
};