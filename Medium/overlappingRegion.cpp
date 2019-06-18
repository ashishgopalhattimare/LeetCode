// https://leetcode.com/problems/rectangle-overlap/
// Amazon : Area of Overlapping
// Easy

#include <bits/stdc++.h>
using namespace std;

pair<int,int> areaOverlap(vector<int>& rect1, vector<int>& rect2) {

    pair<int,int>l = make_pair(max(rect1[0], rect2[0]), max(rect1[1], rect2[1]));
    pair<int,int>r = make_pair(min(rect1[2], rect2[2]), min(rect1[3], rect2[3]));

    return make_pair(r.first-l.first, r.second-l.second);
}

int main() {

    vector<int>rect1 = {1,1,2,2};
    vector<int>rect2 = {2,1,4,4};

    pair<int,int> lw = areaOverlap(rect1, rect2);
    
    if(lw.first > 0 && lw.second > 0) {
        cout << "OverLapping area : " << lw.first * lw.second << endl;
    }
    else {
        cout << "non-overlapping rectangles" << endl;
    }

    return 0;
}