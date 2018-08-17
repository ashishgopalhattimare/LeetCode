// https://practice.geeksforgeeks.org/problems/word-break-part-2/0/?track=SP-Recursion

#include <bits/stdc++.h> 

using namespace std;

void wordBreak(const string word, vector<string>& v, vector<string>& result, unordered_map<string, bool>& hash, int index)
{
    if(index == word.length()) {
        if(v.size()) {
            string sentence = "";
            
            sentence.push_back('(');
            sentence.append(v[0]);
            
            for(int i = 1; i < v.size(); i++) {
                sentence.push_back(' ');
                sentence.append(v[i]);
            }
            sentence.push_back(')');
            
            result.push_back(sentence);
        }
        
        return;
    }
    
    string current_word = "";
    for(int i = index; i < word.length(); i++) {
        current_word.push_back(word[i]);
        
        if(hash.find(current_word) != hash.end()) {
            v.push_back(current_word);
            
            wordBreak(word, v, result, hash, i + 1); 
            
            v.pop_back();
        }
    }
    
    return;
}

int main(int argc, char* argv[])
{
    int t;
    int n;
    string word;
    
    cin >> t;
    while(t--) {
        cin >> n;
        
        unordered_map<string, bool>hash;
        
        for(int i = 0; i < n; i++) {
            cin >> word;
            hash[word] = true;
        }
        
        cin >> word;
        
        vector<string> result;
        vector<string> v;
        wordBreak(word, v, result, hash, 0);
        
        sort(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
        }
        printf("\n");
    }

    return 0;
}