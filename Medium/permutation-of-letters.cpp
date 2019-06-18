class Solution {
public:
    
    void formString(int index, vector<vector<string>>& set, vector<string>& result, string word) {
        if(index == set.size()) {
            result.push_back(word);
            return;
        }
        for(int i = 0; i < set[index].size(); i++) {
            formString(index+1, set, result, word + set[index][i]);
        }
        return;
    }
    
    vector<string> permute(string S) {
        
        if(S.length() == 0) return {};
        
        vector<vector<string>>set;
        
        // {a,b}cd{d,e}{f,e}
        string common = "";
        vector<string>curr;

        for(int i = 0; i < S.length(); i++) {
            
            if(S[i] == ',') {
                if(common.length()) curr.push_back(common);
                common = "";
            }
            // Inside the {} words
            else if(S[i] == '{') {
                
                // append the word that was formed before starting this set
                // of words
                if(common.length()) {
                    curr.push_back(common);
                    set.push_back(curr);
                    common = "";
                }
                curr.clear(); // clear the current wordlist
                
                vector<string>row;
                string element = "";
                for(i = i+1; S[i] != '}'; i++) {
                    // append this char or word into the row vector
                    if(S[i] == ',') {// seperator found
                        if(element.length()) row.push_back(element);
                        element = "";
                    }
                    else element.push_back(S[i]);
                }
                // last element of the row vector
                if(element.length()) row.push_back(element);
                
                // appends this set into the main set;
                set.push_back(row);
            }
            else {
                common.push_back(S[i]);
            }
        }
        
        if(common.length()) {
            curr.push_back(common);
            set.push_back(curr);
        }
        
        vector<string>result;
        
        // combination of the words from each set
        for(int i = 0; i < set[0].size(); i++) {   
            formString(1, set, result, set[0][i]);
        }
        
        // sort the words in the lexicological order output
        sort(result.begin(), result.end());
        
        return result;
    }
};
