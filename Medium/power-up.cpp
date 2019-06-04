// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/power-up-2/
// Medium, Kadane Algorithm (Modified with HashMap)

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<bool>reset(n, false);

    int start = 0;
    long long int sum = 0;
    long long int maxim = INT_MIN;

    unordered_map<int,int>set;

    for(int i = 0; i < n; i++) {

    	/** MODIFICATION **/
        if(set.find(arr[i]) != set.end()) { // duplicate found
            int prevIndex = set[arr[i]];
            bool found = false;
            for(int j = prevIndex; j < i; j++) {
                // it was reset in between first occurence and second occurence
                if(reset[j] == true) {
                    found = true;
                    break;
                }
            }
            // Remove all the elements from start to second occurence
            while(start <= set[arr[i]]) {
                set.erase(arr[start]);

                // if reset was not done, decrement from the sum
                if(!found) sum -= arr[start];
                start++;
            }
        }

        /** KADANE ALGORIHTM **/
        sum += arr[i];

        set[arr[i]] = i;
        maxim = max(maxim, sum);
        if(sum < 0) {
            reset[i] = true;
            sum = 0;
        }
    }

    cout << maxim << endl;

    return 0;
}

