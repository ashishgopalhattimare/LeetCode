// https://leetcode.com/problems/push-dominoes/
// CareerCup, Amazon
// Medium

class Solution {
public:
    
    void allChange(vector<char>& arr, int C, int fac, int end, char X) {
        while(C != end && arr[C] == '.') {
            arr[C] = X;
            C += fac;
        }
        return;
    }
    
    string pushDominoes(string dominoes) {
        
        int n = dominoes.length();
        
        vector<char>domino(n);
        for(int i = 0; i < n; i++) {
            domino[i] = dominoes[i];
        }
        
        int start = 0, end = n-1;
        
        while(start < n) { // [.....L.L...R..rest...]
            if(domino[start] == 'R') break;
            else if(domino[start] == 'L') {
                allChange(domino, start-1, -1, -1, 'L');
            }
            start++;
        }
        
        while(start <= end) { // [rest .... L...R.....R..]
            if(domino[end] == 'L') break;
            else if(domino[end] == 'R') {
                allChange(domino, end+1, 1, n, 'R');
            }
            end--;
        }
        
        // if every this is good, then start element is R
        // and L element is L
        
        char prevChar = 'R';
        int prev = start++;
        
        int l, r;
        while(start <= end) {
            if(domino[start] == 'R') {
                if(prevChar == 'R') { // only right fall R....R condition
                    allChange(domino, prev+1, 1, start, 'R');
                }
		// if L =, then its L....R condition, do nothing

                prevChar = 'R';
                prev = start;
            }
            else if(domino[start] == 'L') {
                if(prevChar == 'L') { // only left fall L.....L condition
                    allChange(domino, start-1,-1, prev, 'L');
                }
                else { // fall from both sides R....L condition
                    l = prev+1; r = start-1;
                    while(l < r) {
                        domino[l++] = 'R';
                        domino[r--] = 'L';
                    }
                }
                
                prevChar = 'L';
                prev = start;
            }
            
            start++;
        }
        
        string result = "";
        for(char x : domino) result.push_back(x);
        
        return result;
    }
};
