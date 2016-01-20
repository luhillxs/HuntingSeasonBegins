/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question

Show Tags
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool dup = false;
        int j=0;
        if(nums.size()==0){
            return 0;
        }
        for(int i=1;i<nums.size();++i){
            if(dup==true&&nums[j]!=nums[i]){
                dup = false; //true to false
            }
            if(dup==false){
                if(nums[i]==nums[j]){
                    dup = true; //false to true
                }
                nums[++j]=nums[i];
            }
        }
        
        return j+1;
    }
};