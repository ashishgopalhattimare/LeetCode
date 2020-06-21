// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/seating-arrangement-6b8562ad/
// Easy, HashTable, Priority Queue, Map

#include <bits/stdc++.h>
using namespace std;

#define LL long long int

struct Range
{
    LL l, h;
    Range(LL low, LL high) {
        l = low; h = high;
    }

    bool operator<(const Range& oth) const {

        // If number of seats are same, give priority to the row close the left
        if(abs(h-l) == abs(oth.h-oth.l))
            return l > oth.l;
        
        // Priority to the maximum number of seats range
        return abs(h-l) < abs(oth.h-oth.l);
    }
};

int main()
{
    LL N, K, Q;
    string plan;

    cin >> N >> K;
    cin >> plan;

    LL mid, totalSeats, mid1, mid2;
    unordered_map<LL,LL>mapi;
    
    /**
     If there are 5 seats --->
                                < . .  . . . >   initial row
                                < . . > < . . >  divide from the center into 2 row
    **/

    priority_queue<Range>pq;
    pq.push({0, N + 1});
    
    for(int i = 0; i < plan.length(); i++) {

        // Get the row with maximum seats, or closest to the left
        Range temp = pq.top(); pq.pop();

        totalSeats = abs(temp.h-temp.l)-1;
        if(totalSeats % 2 == 1) { // Odd seats (center)
            mid = temp.l + (temp.h-temp.l)/2;
        }
        else { // plan decide on 2 center seats
            mid1 = temp.l + (temp.h-temp.l)/2;
            mid2 = mid1 + 1;

            if(plan[i] == 'R') mid = mid2;
            else mid = mid1;
        }
        
        mapi[mid] = i + 1; // Assign the seat to Kth or ith person

        if(abs(temp.l-mid) != 1) pq.push({temp.l, mid}); // If any seat remaining between L to R
        if(abs(temp.h-mid) != 1) pq.push({mid, temp.h}); // If any seat remaining between L to R
    }

    cin >> Q;
    while(Q--)
    {
        cin >> mid;
        if(mapi.find(mid) == mapi.end()) {
            printf("-1\n");
        }
        else printf("%lld\n", mapi[mid]);
    }
    
    return 0;
}