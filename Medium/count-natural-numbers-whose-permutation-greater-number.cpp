#include <bits/stdc++.h>

using namespace std;

int countNumber(int n)
{
    int totalCount = 0, top, next;
    stack<int>st;

    for(int i = 1; i <= 9; i++) {
        if(i <= n) {
            totalCount += 1;
            st.push(i);
        }
        
        // 1  -> 11 12 13 14
        // 11 -> 111 112 113

        while(!st.empty()) {
            top = st.top();
            st.pop();

            for(int j = top%10; j <= 9; j++) {
                next = top*10 + j;
                if(next <= n) {
                    totalCount += 1;
                    st.push(next);
                }
                else break;
            }
        }
    }

    return totalCount;
}

int main()
{
    int n;
    cin >> n;
    cout << countNumber(n) << endl;
    return 0;
}