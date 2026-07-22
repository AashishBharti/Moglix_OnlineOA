#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int longestValidParentheses(const string &s)
{
    stack<int> indices;
    indices.push(-1);

    int longest = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            indices.push(i);
        }
        else
        {
            indices.pop();

            if (indices.empty())
            {
                // Start a new possible valid substring
                indices.push(i);
            }
            else
            {
                longest = max(longest, i - indices.top());
            }
        }
    }

    return longest;
}

int main()
{
    string input;

    cout << "Enter the string: ";
    cin >> input;

    cout << "Longest valid parentheses length: "
         << longestValidParentheses(input) << endl;

    return 0;
}
