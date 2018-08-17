#include <bits/stdc++.h>

// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0

using namespace std;

int hasht[26];
int frequ[26];

void reset() {
    for(int i = 0; i < 26; i++) {
        hasht[i] = frequ[i]= 0;
    }
    return;
}

int main(int argc, char* argv[])
{
    int t;
    int rangeMax;
    bool start;
    char c;
    
    int gl, gr;
    int ssValue, curValue;
    
    pair<char, int> P;
    deque<pair<char, int> >dq;
    string str, ss;
    
    cin >> t;
    while(t--) {
        
        ssValue = 0;
        curValue = 0;
        gl = gr = -1;
        start = false;
        rangeMax = INT_MAX;

        reset();

        cin >> str >> ss;
        
        while(!dq.empty()) {
            dq.pop_back();
        }
        for(int i = 0; i < ss.length(); i++) {
            hasht[ss[i]-'a']++;

            ssValue += ss[i];
        }
        
        for(int i = 0; i < str.length(); i++) {
            
            c = str[i];
            
            if(!start) {
                if(hasht[c-'a']) {
                    // printf("-------------------\n");
                    // printf("push : %c %d\n", c, i);

                    dq.push_back(make_pair(c, i));
                    frequ[c-'a']++;
                    start = true;
                    
                    curValue += (c);
                    // printf("-------------------\n");

                    if(frequ[c-'a'] == hasht[c-'a']) {
                        if(curValue == ssValue) {
                            if(rangeMax > abs(dq.back().second - dq.front().second)){
                                rangeMax = abs(dq.back().second - dq.front().second);

                                gl = dq.front().second;
                                gr = dq.back().second;
                            }
                        }
                    }
                }
            }
            
            else {
                if(hasht[c-'a']) {
                    // printf("-------------------\n");
                    // printf("push : %c %d\n", c, i);
                    dq.push_back(make_pair(c, i));
                    frequ[c-'a']++;
                    curValue += (c);

                    if(frequ[c-'a'] == hasht[c-'a'] && curValue == ssValue) {
                        if(rangeMax > abs(dq.back().second - dq.front().second)) {
                            rangeMax = abs(dq.back().second - dq.front().second);

                            gl = dq.front().second;
                            gr = dq.back().second;
                        }
                    }
                    
                    else if(frequ[c-'a'] > hasht[c-'a']) {
                        while(true) {
                            P = dq.front();
                            // printf("pop : %c %d\n", P.first, P.second);
                            dq.pop_front();
                            
                            frequ[P.first - 'a']--;
                            curValue -= P.first;
                            
                            if(P.first == c) {
                                break;
                            }
                        }
                    }

                    if(frequ[c-'a'] == hasht[c-'a'] && curValue == ssValue) {
                        if(rangeMax > abs(dq.back().second - dq.front().second)) {
                            rangeMax = abs(dq.back().second - dq.front().second);

                            gl = dq.front().second;
                            gr = dq.back().second;
                        }
                    }
                    // printf("-------------------\n");
                }
            }
        }

        if(gl == -1) {
            printf("-1\n");
        }
        else {
            for(int i = gl; i <= gr; i++) {
                printf("%c", str[i]);
            }
            printf("\n");
        }
    }

    return 0;
}