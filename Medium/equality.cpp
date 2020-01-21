// https://www.codechef.com/JAN20B/problems/ISBIAS
// Medium

#include <bits/stdc++.h>

using namespace std;

// Brute Force Approach
// Complexity : O(n^2)
pair<int,int> equality(vector<int>& nums, int L, int R)
{
    int incCount = 0, decCount = 0;
	int prev;
	bool subFound;

    prev = nums[L]; subFound = false;
    
	for(int i = L+1; i <= R; i++) {
		if(prev < nums[i]) {
			subFound = true;
		}
		else {
			if(subFound) incCount++;
			subFound = false;
		}
		prev = nums[i];
	}
	if(subFound) incCount++;
	
    prev = nums[R]; subFound = false;
	for(int i = R-1; i >= L; i--) {
		if(nums[i] > prev) {
			subFound = true;
		}
		else {
			if(subFound) decCount++;
			subFound = false;
		}
		prev = nums[i];
	    
	}
	if(subFound) decCount++;
    
    return {incCount, decCount};
}

// Complexity : O(n)
void preCompute(vector<int>& nums, vector<int>& index, vector<int>& incAr) 
{
    index[0] = incAr[0] = 0;
    bool subFound = false;
    int count = 0;
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i-1] < nums[i]) {
            if(subFound == false) {
                subFound = true;
                count++;
            }
            
            index[i] = index[i-1];
        }
        else {
            subFound = false;
            index[i] = i;
        }
        
        incAr[i] = count;
    }
    
    // for(int x : index) printf("%d ", x); printf("\n");
    // for(int x : incAr) printf("%d ", x); printf("\n\n");
}

// Complexity : O(1)
int optimal(vector<int>& index, vector<int>& incAr, int L, int R)
{
    if(L == R) return 0;
    
    if(incAr[L] == 0) return incAr[R];
    else { // L < R and L > 0
        
        if(index[L] != index[R])
        {
            if(incAr[L] != incAr[L+1]) {
                return incAr[R] - incAr[L];    
            }
            return incAr[R] - incAr[L] + (index[L] == index[L+1]);
        }
        if(incAr[L] == incAr[L+1]) {
            
            return incAr[R] - incAr[L] + 1;
        }
        return incAr[R] - incAr[L];
    }
}

int main()
{
	int N, Q;
	int L, R;

	cin >> N >> Q;

	vector<int>numsOriginal(N), numsNegate(N);

	vector<int>indexInc(N), arrInc(N);
	vector<int>indexDec(N), arrDec(N);
	
	for(int i = 0; i < N; i++) {
		cin >> numsOriginal[i];
		numsNegate[i] = -numsOriginal[i];
	}
	
	preCompute(numsOriginal, indexInc, arrInc);	// Maximum Increasing Subsequence
	preCompute(numsNegate, indexDec, arrDec);	// Maximum Decreasing Subsequence
	
	while(Q--) {
		cin >> L >> R;
		
		// pair<int,int> brute = equality(nums, L-1, R-1);
		pair<int,int> opti = {optimal(indexInc, arrInc, L-1, R-1), optimal(indexDec, arrDec, L-1, R-1)};
	    	
	    if (opti.first == opti.second) cout << "YES" << endl;
	    else 
	    	cout << "NO" << endl;
	}
	return 0;
}