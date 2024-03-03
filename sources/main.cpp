// https://leetcode.com/problems/two-sum/description/

#include <iostream>

#include "two_sum.h"

void test_two_sum()
{
    auto test = [](const std::vector<int> &n, int t){
        std::cout << "Input: nums = [" << n[0];
        for (int i = 1; i < n.size(); i++)
        {
            std::cout << "," << n[i];
        }
        std::cout << "], target = " << t << std::endl;

        auto answer = two_sum(n, t);

        std::cout << "Output: [" << answer.first << ",";
        std::cout << answer.second << "]\n";
    };

    test({2,7,11,15}, 9);
    test({3,2,4}, 6);
    test({3,3}, 6);
}

int main(int argc, char** argv)
{
    test_two_sum();

    return 0;
}