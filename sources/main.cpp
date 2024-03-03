// https://leetcode.com/problems/two-sum/description/

#include <iostream>

#include "two_sum.h"
#include "valid_parentheses.h"

void test_two_sum()
{
    std::cout << "\nTwo sum\n";
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

void test_valid_parentheses()
{
    std::cout << "\nValid parentheses\n";
    auto test = [](const std::string& s)
    {
        auto answer = valid_parentheses(s);

        std::cout << "Input: s = \"" << s << "\"\n";
        std::cout << "Output: " << (answer ? "true" : "false") << std::endl;
    };

    test("()");
    test("()[]{}");
    test("(]");
    test("]");
}

int main(int argc, char** argv)
{
    test_two_sum();
    test_valid_parentheses();

    return 0;
}