class Solution {
public:
    
    vector<int> KMP(string B)
    {
        int len = B.length();
        vector<int>lcp(len);
        
        lcp[0] = 0;
        for(int j = 0, i = 1; i < len; ) {
            if(B[j] == B[i]) {
                lcp[i] = j+1;
                i++;
                j++;
            }
            else {
                if(j == 0) {
                    lcp[i] = 0;
                    i++;
                }
                else {
                    j = lcp[j-1];
                }
            }
        }
        
        return lcp;
    }
    
    int repeatedStringMatch(string A, string B) {
        string temp = A;
        
        int count = 1;
        while(temp.length() < B.length()) {
            temp.append(A);
            count++;
        }
        
        vector<int> kmpArray = KMP(B);
        
        for(int i = 0, j = 0; i < temp.length(); ) {
            if(B[j] == temp[i]) {
                j++;
                i++;
                
                if(j == B.length()) return count;
            }
            else {
                if(j == 0) {
                    i = i + 1;
                }
                else {
                    j = kmpArray[j-1];
                }
            }
        }
        
        temp.append(A);
        
        cout << temp << endl;
        for(int i = 0, j = 0; i < temp.length(); ) {
            if(B[j] == temp[i]) {
                j++;
                i++;
                
                if(j == B.length()) return count + 1;
            }
            else {
                if(j == 0) {
                    i++;
                }
                else {
                    j = kmpArray[j-1];
                }
            }
        }
        
        return -1;
    }
};