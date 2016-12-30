void selection_sort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++) { // position
        int min = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }

        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
}