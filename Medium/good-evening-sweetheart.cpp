// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/good-evening-sweetheart/
// Medium

// Segmented Tree (Optimal)
// Sorted binarySearch + O(n) (Less Optimal)
// Priority Queue (Bruteforce)

#include <bits/stdc++.h>

using namespace std;

int firstOccurrence(vector<int>& arr, int start, int end, int x)
{
    if(start == end) { // Only one element
        return start;
    }
    else if(end == start+1) { // There are only two elements
        while(start <= end) {
            if(arr[start] == x)
            return start;
            start++;
        }
    }

    int mid = start + (end-start)/2;

    if(x >= arr[mid]) return firstOccurrence(arr, start, mid, x);
    return firstOccurrence(arr, mid, end, x);
}

int lastOccurrence(vector<int>& arr, int start, int end, int x)
{
    if(start == end) { // Only one element
        return start;
    }
    else if(end == start+1) { // There are only two elements
        while(start <= end) {
            if(arr[end] == x)
            return end;
            end--;
        }
    }

    int mid = start + (end-start)/2;

    if(x > arr[mid]) return lastOccurrence(arr, start, mid, x);
    return lastOccurrence(arr, mid, end, x);
}

int main()
{
    int N, M, C;
    int data, last, first;

    cin >> N >> M;

    vector<int>arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    bool possible = true;
    int count = 0;
    for(int i = 0; i < M; i++) {
        cin >> C;
        data  = arr[C-1];

        if(data == 0) possible = false;

        if(possible) {
            
            first = firstOccurrence(arr, 0, arr.size()-1, data);
            last  = lastOccurrence(arr, 0, arr.size()-1, data);

            for(int i = 0; possible && i < first; i++) {
                if(arr[i] == 0) possible = false;
                arr[i]--;
            }
            for(int i = 0; possible && i < C-first; i++) {

                if(arr[last] == 0) possible = false;
                arr[last--]--;
            }
            
            if(possible) count++;
        }
    }

    cout << count << endl;
    return 0;
}