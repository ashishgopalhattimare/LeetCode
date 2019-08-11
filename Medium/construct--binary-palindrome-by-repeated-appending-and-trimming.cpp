// https://www.geeksforgeeks.org/construct-binary-palindrome-by-repeated-appending-and-trimming/
// Medium
// Complexity : O(n) time and space

#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////
// SOLUTION FROM GEEKSFORGEEKS
////////////////////////////////////////////////////////////////
void dfs(int p, int ans[], vector<int> c[]) 
{
	ans[p] = 1;
    for (int i = 0; i < c[p].size(); i++) {
		if (!ans[c[p][i]]) {
            dfs(c[p][i], ans, c); 
        }
	}
}

string GeeksForGeeks(int n, int k) 
{ 
	int arr[n], ans[n] = { 0 }; 
	vector<int> c[k]; 
	for (int i = 0; i < n; i++) arr[i] = i % k; 
	for (int i = 0; i < n / 2; i++) { 
		c[arr[i]].push_back(arr[n-i-1]);
		c[arr[n-i-1]].push_back(arr[i]);
	}
	dfs(0, ans, c);

    string result = "";
	for (int i = 0; i < n; i++) result.push_back('0' + ans[arr[i]]);

    return result;
}
////////////////////////////////////////////////////////////////

string binaryPalindrome(int n, int k)
{
    vector<char>binary(n, '0');
    if(n <= k) {
        binary[0] = binary[n-1] = '1';
    }
    else {
        vector<int>indices(n);
        for(int i = 0; i < n; i++) {
            indices[i] = i % k;
            if(indices[i] == 0) {
                binary[i] = '1';
            }
        }

        unordered_set<int>set; // changed bits in the binary
        int l = 0, r = n-1;
        while(l < r) {
            // Both bits are not same
            if(binary[l] != binary[r]) {
                // bit that is zero and not in set is to be updated
                if(binary[l] == '0' && set.find(indices[l]) == set.end()) {
                    set.insert(indices[l]);
                }
                else if(binary[r] == '0' && set.find(indices[r]) == set.end()) {
                    set.insert(indices[r]);
                }
            }
            l++; r--;
        }

        // Update the binary
        for(int i = 0; i < n; i++) {
            if(set.find(indices[i]) != set.end()) {
                binary[i] = '1';
            }
        }
    }
    
    string result = "";
    for(char x : binary) result.push_back(x);

    return result;
}

int main()
{
    int n = 11, k = 1;

    if(binaryPalindrome(n,k) == GeeksForGeeks(n,k)) {
        cout << "Same Generated:\n" << binaryPalindrome(n,k) << endl;
    }
    else {
        cout << "Different" << endl;
    }

    return 0;
}