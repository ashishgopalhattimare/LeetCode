// https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings/0/?track=SP-Strings

// Manachar Algorithm Pivot Orbital O(n^2)

#include <bits/stdc++.h> 

using namespace std;

int distinctPalindrome(const string str)
{
    int count = 0;
    unordered_map<string, bool>hash;
    
    int l, r;
    for(int i = 0; i < str.length(); i++) {
        
        string word = "";
        l = i; r = i+1;
        while(l >= 0 && r < str.length()) {
            if(str[l] == str[r]) {
                word = str[l] + word + str[r];
                if(hash.find(word) == hash.end()) {
                    count++;
                }
                hash[word] = true;
                
                l--; r++;
            }
            else break;
        }
        
        word = "";
        l = i; r = i;
        while(l >= 0 && r < str.length()) {
            if(str[l] == str[r]) {
                if(l == r) {
                    word.push_back(str[l]);
                }
                else {
                    word = str[l] + word + str[r];
                }
                // cout << "-<" << word << endl;
                if(hash.find(word) == hash.end()) {
                    // cout << "-:" << word << endl;
                    count++;
                }
                hash[word] = true;
                
                l--; r++;
            }
            else break;
        }
    }
    
    return count;
}

int main(int argc, char* argv[])
{
    int t;
    string str;
    
    cin >> t;
    while(t--) {
        cin >> str;
        
        cout << distinctPalindrome(str) << endl;
    }

    return 0;
}