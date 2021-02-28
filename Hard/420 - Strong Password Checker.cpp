/*
 

Strong Password Checker


A password is considered strong if the below conditions are all met:

It has at least 6 characters and at most 20 characters.
It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
It does not contain three repeating characters in a row (i.e., "...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.

In one step, you can:

Insert one character to password,
Delete one character from password, or
Replace one character of password with another character.


Example 1:
Input: password = "a"
Output: 5

Example 2:
Input: password = "aA1"
Output: 3

Example 3:
Input: password = "1337C0d3"
Output: 0


Constraints:

1 <= password.length <= 50
password consists of letters, digits, dot '.' or exclamation mark '!'.

@Author Zixuan
@Date 2021-02-28
*/

#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

enum class PasswordStatus
{
    Success = 0,
    TooShort = 1,
    TooLong = 2,
    LowerCaseMissing = 4,
    UpperCaseMissing = 8,
    DigitMissing = 16,
    ContinuousThree = 32
};

inline PasswordStatus operator| (PasswordStatus a, PasswordStatus b)
{
    return static_cast<PasswordStatus>(static_cast<int>(a) | static_cast<int>(b));
}

inline PasswordStatus operator& (PasswordStatus a, PasswordStatus b)
{
    return static_cast<PasswordStatus>(static_cast<int>(a) & static_cast<int>(b));
}

// Reference: https://leetcode-cn.com/problems/strong-password-checker/solution/li-yong-zi-dian-lai-chu-li-by-tooooo_the_moon/leetcode
class Solution 
{
public:
    int strongPasswordChecker(string password) 
    {
        int length = password.length();

        passwordIssueChecker(password, length);

        if (status == PasswordStatus::Success)
            return 0;

        // Do we have SomethingMissing issue?
        int missingIssueCount = 0;
        missingIssueCount += isThisIssue(PasswordStatus::LowerCaseMissing) ? 1 : 0;
        missingIssueCount += isThisIssue(PasswordStatus::UpperCaseMissing) ? 1 : 0;
        missingIssueCount += isThisIssue(PasswordStatus::DigitMissing) ? 1 : 0;

        if (isThisIssue(PasswordStatus::TooShort))
            return max(6 - length, missingIssueCount);

        // If there is no ContinuousThree issue
        if (!isThisIssue(PasswordStatus::ContinuousThree))
        {
            if (isThisIssue(PasswordStatus::TooLong))
                return length - 20 + missingIssueCount;
            else // SomethingMissing issue
                return missingIssueCount;
        }
        else
        {
            if (isThisIssue(PasswordStatus::TooLong))
            {
                // Cacluate continous length of each repetition
                multiset<int> lengthsOfRepetition3N;
                multiset<int> lengthsOfRepetition3N1;
                multiset<int> lengthsOfRepetition3N2;

                for (int i = 0; i < length - 2; ++i)
                {
                    if (i < length - 2)
                        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2])
                        {
                            int j = i + 3;
                            while (j < length && password[i] == password[j])
                                ++j;

                            int continousLength = j - i;
                            int mod = continousLength % 3;
                            if (mod == 0)
                                lengthsOfRepetition3N.insert(continousLength);
                            else if (mod == 1)
                                lengthsOfRepetition3N1.insert(continousLength);
                            else
                                lengthsOfRepetition3N2.insert(continousLength);

                            i = j - 1;
                        }
                }

                int steps = 0;
            
                // Use replace to fix missing issue
                while (missingIssueCount > 0)
                {
                    // Replace, starting from 3N2
                    if (lengthsOfRepetition3N2.size() > 0)
                    {
                        int value = *lengthsOfRepetition3N2.rbegin() - 3;
                        lengthsOfRepetition3N2.erase(prev(lengthsOfRepetition3N2.end()));
                        
                        if (value >=3)
                            lengthsOfRepetition3N2.insert(value);

                        --missingIssueCount;
                        ++steps;
                    }
                    // 3N1
                    else if (lengthsOfRepetition3N1.size() > 0)
                    {
                        int value = *lengthsOfRepetition3N1.rbegin() - 3;
                        lengthsOfRepetition3N1.erase(prev(lengthsOfRepetition3N1.end()));

                        if (value >= 3)
                            lengthsOfRepetition3N1.insert(value);

                        --missingIssueCount;
                        ++steps;
                    }
                    // 3N
                    else if (lengthsOfRepetition3N.size() > 0)
                    {
                        int value = *lengthsOfRepetition3N.rbegin() - 3;
                        lengthsOfRepetition3N.erase(prev(lengthsOfRepetition3N.end()));

                        if (value >= 3)
                            lengthsOfRepetition3N.insert(value);

                        --missingIssueCount;
                        ++steps;
                    }

                    if (lengthsOfRepetition3N.size() + lengthsOfRepetition3N1.size() + lengthsOfRepetition3N2.size() == 0)
                        break;
                }

                if (missingIssueCount > 0) // No repitition now
                    return steps + missingIssueCount + length - 20;
                else
                {
                    // Do we still have TooLong issue? Use deletion on ContinousThree
                    while (length > 20)
                    {
                        // Delete, starting from 3N
                        if (lengthsOfRepetition3N.size() > 0)
                        {
                            int value = *lengthsOfRepetition3N.rbegin() - 1;
                            lengthsOfRepetition3N.erase(prev(lengthsOfRepetition3N.end()));

                            if (value >= 3)
                                lengthsOfRepetition3N2.insert(value);

                            --length;
                            ++steps;
                        }
                        // 3N1
                        else if (lengthsOfRepetition3N1.size() > 0)
                        {
                            int value = *lengthsOfRepetition3N1.rbegin() - 1;
                            lengthsOfRepetition3N1.erase(prev(lengthsOfRepetition3N1.end()));

                            if (value >= 3)
                                lengthsOfRepetition3N.insert(value);

                            --length;
                            ++steps;
                        }
                        // 3N2
                        else if (lengthsOfRepetition3N2.size() > 0)
                        {
                            int value = *lengthsOfRepetition3N2.rbegin() - 1;
                            lengthsOfRepetition3N2.erase(prev(lengthsOfRepetition3N2.end()));

                            if (value >= 3)
                                lengthsOfRepetition3N1.insert(value);

                            --length;
                            ++steps;
                        }

                        if (lengthsOfRepetition3N.size() + lengthsOfRepetition3N1.size() + lengthsOfRepetition3N2.size() == 0)
                            break;
                    }

                    // If still too long, delete any to get length 20
                    if (length > 20)
                        return steps + length - 20;
                    else // There are continous three
                    {
                        for (auto i : lengthsOfRepetition3N) steps += i / 3;
                        for (auto i : lengthsOfRepetition3N1) steps += i / 3;
                        for (auto i : lengthsOfRepetition3N2) steps += i / 3;
                        return steps;
                    }
                }

                return steps;
            }
            else // Length is ok
            {
                int steps = 0;
                for (auto i = 0; i < length - 2; ++i)
                {
                    if (password[i] == password[i + 1] && password[i + 1] == password[i + 2])
                        ++steps;
                    i += 2;
                }
                return max(steps, missingIssueCount);
            }
        }
    }

private:
    PasswordStatus status = PasswordStatus::Success;

    void passwordIssueChecker(const string& password, const int length)
    {
        if (length < 6)
            status = status | PasswordStatus::TooShort;

        if (length > 20)
            status = status | PasswordStatus::TooLong;

        bool hasLowerCase = false, hasUpperCase = false, hasDigit = false;

        for (auto i = 0; i < length; ++i)
        {
            if (islower(password[i]))
                hasLowerCase = true;
            else if (isupper(password[i]))
                hasUpperCase = true;
            else if (isdigit(password[i]))
                hasDigit = true;

            // Continuous three checker
            if (i < length - 2)
                if (password[i] == password[i + 1] && password[i + 1] == password[i + 2])
                    status = status | PasswordStatus::ContinuousThree;
        }

        if (!hasLowerCase)
            status = status | PasswordStatus::LowerCaseMissing;

        if (!hasUpperCase)
            status = status | PasswordStatus::UpperCaseMissing;
        
        if (!hasDigit)
            status = status | PasswordStatus::DigitMissing;
    }

    inline bool isThisIssue(PasswordStatus statusToCheck)
    {
        return static_cast<int>(status & statusToCheck) != 0;
    }
};
