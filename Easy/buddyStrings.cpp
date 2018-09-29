// https://leetcode.com/problems/buddy-strings/description/

class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        if(A.size() != B.size()) return false;
        
        vector<char>freqtable(26, 0);
        
        // swap of two char is successfully done or not
        bool singleSwap = false;
        
        bool sw = false, dataSwapped = false;
        
        char a = '*', b = '*';
        for(int i = 0; i < A.size(); i++) {
            if(A[i] != B[i]) {
                
                // if no swap of data is done, first swap -> save it
                if(!dataSwapped && a == '*') {
                    a = A[i];
                    b = B[i];
                    
                    dataSwapped = true;
                    sw = true;
                }
                
                // if previous data is swapped, and this swap is also possible, 
                // try to make it check whether the swap is possible
                else if(dataSwapped && a != '*') {
                    if(a != B[i] || b != A[i]) {
                        return false;
                    }
                    dataSwapped = false;
                    singleSwap = true;
                    sw = false;
                }
                
                // initial and second swap is done , this is the third swap if
                else {
                    return false;
                }
            }
            
            // get the frequency of char in A
            freqtable[A[i]-'a']++;
        }
        
        // if the frequency is any char is >= 2, then it is possible that the same,
        // char were swapped, to keep the strings same
        for(int x : freqtable) {
            if(x >= 2) return true;
        }
        
        // if only one swap was done, not the second swap
        if(sw) return false;
        
        // if the swapping was done or not
        return singleSwap;
    }
};
