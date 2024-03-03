// https://leetcode.com/problems/valid-parentheses/description/

#include <vector>
#include <string>

bool valid_parentheses(const std::string& s)
{
    auto isOpenBracket = [](char bracket)
    {
        if (bracket == '(' ||
            bracket == '[' ||
            bracket == '{')
            return true;

        return false;
    };

    auto isBracketsPair = [](char open_bracket, char close_bracket)
    {
        if (open_bracket == '(' && close_bracket == ')')
            return true;
        else if (open_bracket == '[' && close_bracket == ']')
            return true;
        else if (open_bracket == '{' && close_bracket == '}')
            return true;
        else
            return false;
    };

    std::vector<char> queue{};

    for (char bracket: s)
    {
        if (isOpenBracket(bracket))
            queue.push_back(bracket);
        else if (queue.size() != 0 && isBracketsPair(queue.back(), bracket))
            queue.pop_back();
        else
            return false;
    }

    if (queue.size() == 0)
        return true;
    else
        return false;
}