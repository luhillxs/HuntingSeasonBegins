void BubbleSort(vector<int> &nums) // O(n^2)
{
    for (int i = 0; i < nums.size() - 1; i++) { // times //i < nums.size() - 1
        for (int j = 0; j < nums.size() - i - 1; j++) { // position //j < nums.size() - i - 1
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

/*
优化1：某一趟遍历如果没有数据交换，则说明已经排好序了，因此不用再进行迭代了。用一个标记记录这个状态即可。
优化2：记录某次遍历时最后发生数据交换的位置，这个位置之后的数据显然已经有序，不用再排序了。
因此通过记录最后发生数据交换的位置就可以确定下次循环的范围了。
*/