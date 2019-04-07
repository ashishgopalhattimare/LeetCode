// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char* argv[])
{
    int t;
    int n;
    char c;
    
    cin >> t;
    while(t--) {
        
        cin >> n;
        
        deque<char> dq;
        vector<int>freq(26,0);
        
        for(int i = 0 ; i < n; i++) {
            cin >> c;
            
            if(freq[c-'a'] == 0){
                dq.push_back(c);
            }
            freq[c-'a']++;
            
            while(!dq.empty() && freq[dq.front()-'a'] > 1) {
                dq.pop_front();
            }
            
            if(dq.empty()) {
                printf("-1 ");
            }
            else printf("%c ", dq.front());
        }
        printf("\n");
    }

    return 0;
}
