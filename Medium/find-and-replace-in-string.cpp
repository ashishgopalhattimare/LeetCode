// https://leetcode.com/problems/find-and-replace-in-string/
// Medium, Mock Test

class Solution {
public:
    // Since it is not in sorted, find in entire indexes vector
    int contains(int x, vector<int>& indexes) {
        for(int i = 0; i < indexes.size(); i++) {
            if(indexes[i] == x) return i;
        }
        return -1; // not available
    }
    
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        // string resultant
        string result = "";
        int k = 0; // number of indexes conditions matches
        for(int i = 0; i < S.length(); ) {
            
            // if the i is contained in the indexes, return its index in vector
            int index = contains(i, indexes);
            
            if(k < indexes.size() && index != -1) { // if not all are matches
                int x = 0;
                for(int j = i; x < sources[index].length(); j++, x++) {
                    if(S[j] != sources[index][x]) {
                        break;
                    }
                }
                // if all the source char were matched
                if(x == sources[index].length()) {
                    // Append all the target chars in the resultant
                    for(char x : targets[index]) {
                        result.push_back(x);
                    }
                    // skip the next n indexes in the string 
                    i += (sources[index].length());
                }
                
                // append this char in the string
                else {
                    result.push_back(S[i++]);
                }
                k++;
            }
            else result.push_back(S[i++]);
        }
        return result;
    }
};
