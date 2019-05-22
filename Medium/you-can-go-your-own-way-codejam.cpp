// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da
// your path should not be a subpath of the computer's way
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for(int k = 1; k <= t; k++) {
        int n;
        string str;
        
        cin >> n;
        cin >> str;
        
        string result = "";
        
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == 'S') result.push_back('E');
            else result.push_back('S');
        }
        
        printf("Case #%d: ", k);
        cout << result << endl;
    }
}
