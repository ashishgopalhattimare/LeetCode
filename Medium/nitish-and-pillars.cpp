#include <bits/stdc++.h>
using namespace std;

// 16 46 9 92 73 54 16 66 45 65 32 74 22 90 34 30 5 78 99 -1

int optimal(vector<int>& arr, vector<int>&height, vector<int>& rightTop, vector<int>& setInc, vector<int>& nextHeight, int L, int R, bool debug)
{
    int maxRight = rightTop[L]; // Get the max height index in RHS of element L
    
    // If L has maxHeight before the R, then L can only see height[L] integers
    if(maxRight <= R) {
        if(debug) printf("<here 1> ");
        return height[L];
    }

    /* L and R belong to same rightTop */
    
    // if the height of L is one
    if(height[L] == 1 || L == R) {
        if(debug) printf("<here 2> ");
        return 1;
    }
    // If the height of L ie greater than or equal to R
    if(arr[L] >= arr[R]) {
        
        if(setInc[L] < R) {
            if(debug) printf("<here 3> ");
            return abs(L-setInc[L])+1;
        }
        if(debug) printf("<here 4> ");
    }

    if(debug) printf("<here 5> ");

    return abs(height[L]-height[R])+1;
}

int bruteforce(vector<int>&arr, int L, int R)
{
    int count = 1;
    int maxHeight = arr[L];
    while(L < R) {
        if(maxHeight < arr[L+1]) {
            count++;
        }
        maxHeight = max(maxHeight, arr[++L]);
    }
 
    return count;
}

int main()
{
    ifstream infile;
    infile.open("input.txt");

    int n, data;
    // infile >> n;

    vector<int>arr;
    while(true) {
        infile >> data;
        if(data == -1) break;
        arr.push_back(data);
    }

    // sort(arr.begin(), arr.end());

    n = arr.size();
    vector<int>height(n, 0), rightTop(n, 0), setInc(n, 0), nextHeight(n, 0);

    stack<vector<int>>st;

    int setCount = n-1;
    int currTop;
    for(int i = n-1; i >= 0; i--) {

        if(i == n-1) setInc[n-1] = setCount;
        else {
            if(arr[i] >= arr[i+1]) setCount = i;
            setInc[i] = setCount;
        }

        vector<int>curr = {arr[i], i, 1, i};
        while(!st.empty()) {

            vector<int>temp = st.top();
            if(arr[i] >= temp[0]) {
                st.pop();
                height[temp[1]] = temp[2];
                nextHeight[temp[1]] = temp[3];
            }
            else {
                curr[2] = temp[2] + 1;
                curr[3] = temp[1];
                break;
            }
        }

        if(curr[2] == 1) currTop = i;

        rightTop[i] = currTop;
        st.push(curr);
    }

    while(!st.empty()) {
        vector<int>temp = st.top();
        st.pop();

        height[temp[1]] = temp[2];
        nextHeight[temp[1]] = temp[3];
    }

    printf("index  : "); for(int i = 0; i < n; i++) printf("%-2d ", i); printf("\n\n");
    printf("array  : "); for(int x : arr) printf("%-2d ", x); printf("\n");
    printf("height : "); for(int x : height) printf("%-2d ", x); printf("\n");
    printf("righTp : "); for(int x : rightTop) printf("%-2d ", x); printf("\n");
    printf("setInc : "); for(int x : setInc) printf("%-2d ", x); printf("\n");
    printf("nexHei : "); for(int x : nextHeight) printf("%-2d ", x); printf("\n");

    int q, L, R;

    // printf("\n"); L = 0; R = 2;
    // printf("[%2d-%2d] : %d == %d\n", L, R, optimal(arr, height, rightTop, setInc, nextHeight, L, R), bruteforce(arr, L, R));
    // printf("\n");

    bool allTrue = true;
    for(int i = 0; i < n ; i++) {
        for(int j = i; j < n ; j++) {
            L = i; R = j;

            if (optimal(arr, height, rightTop, setInc, nextHeight, L, R, false) != bruteforce(arr, L, R)) {
                // for(int k = L; k <= R; k++) printf("%d ", arr[k]); printf("\n");
                printf("[%2d-%2d] : %d == %d\n", L, R, optimal(arr, height, rightTop, setInc, nextHeight, L, R, true), bruteforce(arr, L, R));
            }
        }
    }

    cout << allTrue << endl;

    return 0;
}