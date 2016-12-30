/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int j=1;
        if(nums.size()==0){
            return 0;
        }
        else{
            for(i=0;i<nums.size();++i){
                if(nums[i]!=nums[j-1]){
                    nums[j] = nums[i];
                    j+=1;
                }
            }
        return j;
        }
    }
};