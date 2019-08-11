#include <bits/stdc++.h>

using namespace std;

string merge_Strings(string s1, string s2)
{
    int i1 = 0, i2 = 0;
    bool first = true;

    string result = "";
    while(i1 < s1.length() && i2 < s2.length()) {
        if(first) {
            result.push_back(s1[i1++]);
        }
        else {
            result.push_back(s2[i2++]);
        }
        first = !first;
    }

    while(i1 < s1.length())
        result.push_back(s1[i1++]);

    while(i2 < s2.length())
        result.push_back(s2[i2++]);
    
    return result;
}

int main()
{
    string s1 = "hello";
    string s2 = "geeks";

    cout << merge_Strings(s1, s2) << endl;

    // Minimum Insertions required to form a
    // palindrome ( LCS, O(n2) )

    return 0;
}