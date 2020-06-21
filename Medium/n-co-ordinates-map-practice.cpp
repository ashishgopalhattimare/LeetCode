// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/n-co-ordinates-map-practice/
// Easy, Map

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    // Code Here
    int N;
    int x, y;

    cin >> N;

    map<int, map<int,int>> mapi;
    while(N--) {
        cin >> x >> y;

        mapi[x][y]++;
    }

    for(auto itr1 = mapi.begin(); itr1 != mapi.end(); itr1++) {
        for(auto itr2 = (itr1->second).begin(); itr2 != (itr1->second).end(); itr2++) {
            printf("%d %d %d\n", itr1->first, itr2->first, itr2->second);
        }
    }

    return 0;
}