// https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

#include <bits/stdc++.h>

using namespace std;

static unordered_map<int,int>mapi;

int algorithm(vector<int>& hval, int index) {

    // Out of bound
    if(index >= hval.size()) return 0;

    // If the max sum of this house has been found
    if(mapi.find(index) != mapi.end()) {
        return mapi[index];
    }

    // Consider this house and value of next to next house
    int val = hval[index];
    val += algorithm(hval, index+2);

    // Is this house value greater or house with next 
    mapi[index] = max(val, algorithm(hval, index+1));

    return mapi[index];
}

int main()
{
    vector<int>hval = {5,3,4,11,2};

    cout << algorithm(hval, 0) << endl;

    return 0;
}