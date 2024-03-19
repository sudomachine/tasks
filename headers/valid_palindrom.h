// https://leetcode.com/problems/valid-palindrome/description/

#include <string>

// A-Z (65-90)
// a-z (97-122)
// 0-9 (48-57)
// difference: 97-65=32

bool isPalindrome(std::string s) 
{
    int l = 0; // left
    int r = s.size()-1;// right

    auto isLetter = [](char ch) -> bool
    {
        if (65 <= ch && ch <= 90)
            return true;

        if (97 <= ch && ch <= 122)
            return true;

        if (48 <= ch && ch <= 57)
            return true;

        return false;
    };

    auto toUppercase = [](char ch) -> char
    {
        if (97 <= ch && ch <= 122)
            return (ch - 32);

        return ch;
    };

    while (l < r)
    {
        if (!isLetter(s[l]))
        {
            ++l;
            continue;
        }

        if (!isLetter(s[r]))
        {
            --r;
            continue;
        }

        if (toUppercase(s[l]) != toUppercase(s[r]))
        {
            return false;
        }

        ++l; --r;

    }

    return true;
}