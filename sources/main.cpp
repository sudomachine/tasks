// https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <utility>

#include "two_sum.h"
#include "valid_parentheses.h"
#include "merge_two_sorted_lists.h"
#include "valid_palindrom.h"

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

void test_merge_two_sorted_lists()
{
    std::cout << "\nMerge two sorted lists\n";

    auto n = create({1,2,4});
    auto m = create({1,3,4});

    auto node = mergeTwoLists(n, m);
    print(node);

    print(mergeTwoLists(
        create({}),
        create({})
    ));

    print(mergeTwoLists(
        create({}),
        create({0})
    ));

    print(mergeTwoLists(
        create({1,2,5}),
        create({})
    ));

    print(mergeTwoLists(
        create({}),
        create({1,2,10})
    ));

    print(mergeTwoLists(
        create({3}),
        create({1,2,10})
    ));
}

void test_valid_palindrom()
{
    std::cout << "\nValid Palindrome\n";

    // test set
    std::vector<std::pair<std::string, bool>> set {
        {"A man, a plan, a canal: Panama", true},
        {"race a car", false},
        {" ", true},
        {"a", true},
        {"aa", true},
        {"aaa", true},
        {"aba", true},
        {"aab", false},
        {"baa", false},
        {"aaaa", true},
        {"abaa", false},
        {"abba", true},
        {"baaa", false},
        {"aaba", false},
        {"aaab", false},
        {"0A", false},
        {"0A0", true},
        {"A0A", true}
    };

    // testing
    for (int i = 0; i < set.size(); i++)
    {
        auto str = set[i].first;
        auto true_answer = set[i].second;
        auto infact_answer = isPalindrome(str);

        if (true_answer == infact_answer)
        {
            std::cout << "SUCCESS TEST: \"" << str << "\"\n";
        }
        else {
            std::cout << "FAILED TEST: \"" << str << "\" - ";
            std::cout << (infact_answer ? "valid" : "invalid");
            std::cout << ". Must be - " << (true_answer ? "valid" : "invalid") << std::endl;
        }
    }

}

int main(int argc, char** argv)
{
    test_two_sum();
    test_valid_parentheses();
    test_merge_two_sorted_lists();
    test_valid_palindrom();

    return 0;
}