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
    auto test = [](const std::string& s, bool true_answer)
    {
        auto infact_answer = valid_parentheses(s);

        if (infact_answer == true_answer)
        {
            std::cout << "SUCCESS TEST: \"" << s << "\"\n";
        }
        else {
            std::cout << "FAILED TEST: \"" << s << "\" - ";
            std::cout << (infact_answer ? "valid" : "invalid");
            std::cout << ". Must be - " << (true_answer ? "valid" : "invalid") << std::endl;
        }
    };

    // Is valid string?
    test("()", true);
    test("([])", true);
    test("([]{})", true);
    test("([])({})", true);
    test("({])({})", false);
    test("[({])({})}", false);
    test("()[]{}", true);
    test("(]", false);
    test("]", false);
    test("(", false);
    test("((", false);
}

int main(int argc, char** argv)
{
    test_two_sum();
    test_valid_parentheses();

    return 0;
}