// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-some-queries/
// Easy-Medium
// Heap

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    map<int,int>mapi;
 
    int Q, X, type;
    cin >> Q;
    while(Q--)
    {
        cin >> type;
        
        if(type == 1) {
            cin >> X; mapi[X]++;
        }
        else if(type == 2) {
            cin >> X;
            if(mapi.find(X) == mapi.end()) printf("-1\n");
            else {
                if(mapi[X] == 1) mapi.erase(X);
                else mapi[X]--;
            }
        }
        else if(type == 3) {

            if(mapi.size() == 0) printf("-1\n");
            else {
                auto itr1 = mapi.rbegin();
                printf("%d\n", itr1->first);
            }
        }
        else {
            
            if(mapi.size() == 0) printf("-1\n");
            else {
                auto itr2 = mapi.begin();
                printf("%d\n", itr2->first);
            }
        }
    }
    
    return 0;
}