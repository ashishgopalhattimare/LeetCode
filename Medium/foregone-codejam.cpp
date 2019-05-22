// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231
// decompose number into two numbers such that no number has digit '4' in it

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int tt = 1; tt <= t; tt++) {
        string str;
        cin >> str;
        
        vector<char>num2(str.length(), '0');
        vector<char>num1(str.length());
        
        for(int i = 0; i < str.length(); i++) {
            if(str[i] != '4') {
                num1[i] = str[i];
            }
            else {
                num1[i] = str[i]-1;
                num2[i] = '1';
            }
        }
        
        string strnum1 = "";
        string strnum2 = "";
        
        for(int i = 0; i < str.length(); i++) {
            strnum1.push_back(num1[i]);
        }
        
        int k = 0;
        bool secondFound = false;
        while(num2[k] == '0') k++;
        
        for( ; k < str.length(); k++) {
            secondFound = true;
            strnum2.push_back(num2[k]);
        }
        
        if(secondFound == false) strnum2 = "0";
        cout << "Case #" << tt << ": " << strnum1 << " " << strnum2 << endl;
    }
    
    return 0;
}
