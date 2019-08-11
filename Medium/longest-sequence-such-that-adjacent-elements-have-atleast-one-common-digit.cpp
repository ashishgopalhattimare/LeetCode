#include <bits/stdc++.h>

using namespace std;

static int digits[10] = {0};

bool adjacent(int x, int y, int id) {
    while(x) {
        digits[x%10] = id;
        x/=10;
    }
    while(y) {
        if(digits[y%10] == id) {
            return true;
        }
        y/=10;
    }

    return false;
}

int algorithm(vector<int>& input)
{
    int id = 1, maxLong;

    vector<int>longest(input.size(), 1);
    for(int i = 0; i < input.size(); i++) {

        for(int j = i+1; j < input.size(); j++) {
            if(adjacent(input[i], input[j], id)) {
                longest[j] = max(longest[j], longest[i]+1);
                maxLong = max(maxLong, longest[j]);    
            }
            id++;
        }
    }

    return maxLong;
}

int main()
{
    vector<int> input = {12,23,45,43,36,97};

    cout << algorithm(input) << endl;

    return 0;
}