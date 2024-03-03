// https://leetcode.com/problems/two-sum/description/

#include <vector>

std::pair<int, int>
two_sum(const std::vector<int>& nums, int target)
{
    if (nums.size() == 2)
        return std::make_pair<int, int>(0, 1);

    int sum = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (i == j)
                continue;

            sum = nums[i] + nums[j];
            if (sum == target)
                return std::make_pair(i, j);
        }
    }

    return std::make_pair<int, int>(0, 1);
}