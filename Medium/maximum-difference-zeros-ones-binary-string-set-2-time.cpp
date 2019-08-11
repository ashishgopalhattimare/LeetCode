// https://www.geeksforgeeks.org/maximum-difference-zeros-ones-binary-string-set-2-time/

#include <bits/stdc++.h>

using namespace std;

void kadaneAlgo(string& input, unordered_map<char,int>& map, int &maxCount)
{
    int sum = 0;
    for(int i = 0; i < input.length(); i++) {
        sum += map[input[i]];

        if(sum < 0) sum = 0;
        
        maxCount = max(maxCount, sum);
    }
}

bool allSame(string& input, char x) {
    for(auto c : input) {
        if(c != x) return false;
    }

    return true;
}

int algorithm(string& input)
{
    // Use Kadane algorithm where once you
    // change 0 to 1 and 1 to -1
    // and next time, you
    // change 0 to -1 and 1 to 1

    if(allSame(input, '0') || allSame(input, '1'))
        return 0;

    unordered_map<char,int>map;
    int maxDiffCount = 0;
    
    map['0'] = 1; map['1'] = -1;
    kadaneAlgo(input, map, maxDiffCount);

    map['0'] = -1; map['1'] = 1;
    kadaneAlgo(input, map, maxDiffCount);

    return maxDiffCount;
}

int main()
{
    string input = "11110";

    cout << algorithm(input) << endl;

    return 0;
}