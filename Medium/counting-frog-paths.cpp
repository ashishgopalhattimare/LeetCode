// https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/counting-frog-paths-1abd84d5/
// Easy, Linear Search

#include <bits/stdc++.h>
using namespace std;

bool FindPoint(int x1, int y1, int x2, int y2, int x, int y) 
{ 
    if (x > x1 and x < x2 and y > y1 and y < y2) 
        return true;
    return false; 
}

int main() {
    
    int X, Y, s, T;
    int x1, x2, y1, y2;

    cin >> X >> Y >> s >> T;

    x1 = X-1; y1 = Y-1; x2 = X+s+1; y2 = Y+s+1;

    int count = 0;
    for(int y = T; y >= 0; y--) {
        for(int x = 0; x <= y; x++) {
            if(FindPoint(x1,y1,x2,y2,x,abs(y-x))) {
                count++;
            }
        }
    } 

    cout << count << endl;
    return 0;
}