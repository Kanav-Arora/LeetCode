/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums, int l, int mid, int r)
    {
        int size1 = mid - l + 1;
        int size2 = r - mid;
        vector<int> a1(size1);
        vector<int> a2(size2);

        for (int i = 0; i < size1; i++)
        {
            a1[i] = nums[l + i];
        }
        for (int i = 0; i < size2; i++)
        {
            a2[i] = nums[mid + 1 + i];
        }

        int i = 0, j = 0, k = l;
        while (i < size1 && j < size2)
        {
            if (a1[i] <= a2[j])
            {
                nums[k] = a1[i];
                i++;
                k++;
            }
            else
            {
                nums[k] = a2[j];
                j++;
                k++;
            }
        }

        while (i < size1)
        {
            nums[k] = a1[i];
            i++;
            k++;
        }

        while (j < size2)
        {
            nums[k] = a2[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid + 1, r);
            merge(nums, l, mid, r);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};
// @lc code=end
