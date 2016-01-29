class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        else if(nums.size()==1){
            return nums[0];
        }
        else if(nums.size()==2){
            return min(nums[0],nums[1]);
        }
        
        int start = 0;
        int end = nums.size()-1;
        int mid;
        
        while(start<end-1){
            if(nums[start]<nums[end]){
                return nums[start];
            }
            
            mid = (start+end)/2;
            if(nums[mid]>nums[start]){
                start = mid;
            }
            else if(nums[mid]<nums[start]){
                end = mid;
            }
            else{
                ++start;
            }
        }

        return min(nums[start],nums[end]);
    }
};