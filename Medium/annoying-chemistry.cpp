// https://www.hackerearth.com/challenges/competitive/march-circuits-20/algorithm/annoying-chemistry-f5fb9556/
// Set 1
// March Circuit '20

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, p, q;

    cin >> x >> y >> p >> q;

    int gcd;

    int b1 = 1, b2, b3;
    int C_LEFT, H_LEFT, C_RIGHT, H_RIGHT;
    while(true) {

        C_LEFT = b1*x;
        b3 = C_LEFT/p; C_RIGHT = b3*p;

        H_RIGHT = b3*q;
        b2 = H_RIGHT/y; H_LEFT = b2*y;

        if(b1*x == b3*p && b2*y == b3*q) {
            break;
        }
        b1++;
    }
    
    gcd = __gcd(__gcd(b1,b2), b3);
    printf("%d %d %d\n", b1/gcd, b2/gcd, b3/gcd);
    
    return 0;
}
