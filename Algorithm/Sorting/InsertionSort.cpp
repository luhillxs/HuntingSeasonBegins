void insert_sort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++) { // position
        for (int j = i; j > 0; j--) {
            if (nums[j] < nums[j - 1]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
    }
}