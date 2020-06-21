// https://codeforces.com/problemset/problem/1326/D1

#include <bits/stdc++.h>
using namespace std;

#define lli long long int

// https://leetcode.com/problems/shortest-palindrome/discuss/60204/using-kmps-lps-longest-prefix-suffix-computation-to-solve-in-linear-on-time
int longest_palindrome_prefix(const string s)
{
    string kmprev = s;
    std::reverse(kmprev.begin(), kmprev.end());
    
    string kmp = s + "#" + kmprev;

    vector<int> lps(kmp.size(), 0);   // lps[i] = longest suffix length for substring kmp[0..i] where the suffix == prefix
    for (int i = 1; i < (int)lps.size(); ++i)
    {
        int prev_idx = lps[i - 1];
        
        while (prev_idx > 0 && kmp[i] != kmp[prev_idx]) {
            prev_idx = lps[prev_idx - 1];
        }

        lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
    }

    // after KMP's LPS preprocessing, the last index of the LPS array will contain the longest palindrome prefix' length!
    return lps[lps.size() - 1];
}

int main()
{
	int t;
	string input;

	cin >> t;
	while(t--)
	{
		cin >> input;

		int n = input.length();
		int low = 0, high =n-1;
        
        bool prefixSufix = (input[low] == input[high]);
		while(low < high && input[low] == input[high]) {
			if(low+1 >= high-1) break;
			low++; high--;
		}
        
        string prf = input.substr(0, low);
        string suf = input.substr(high+1,n);
        
        string btw = input.substr(low, high-low+1);
        
        int maxLen = 0, len = longest_palindrome_prefix(btw);
        string res;
        if(maxLen < len) {
            res = btw.substr(0, len);
            maxLen = len;
        }
        
        std::reverse(btw.begin(), btw.end());
        len = longest_palindrome_prefix(btw);
        if(maxLen < len) {
            res = btw.substr(0, len);
            maxLen = len;
        }
        
        cout << prf + res + suf << endl;
	}

    return 0;
}