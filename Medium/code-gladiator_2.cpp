#include <bits/stdc++.h>
using namespace std;

int includeElement(std::vector<pair<int,int>>& nums, int maxim) 
{
    stack<pair<int,int>>st;
    pair<int,int> p;
    
    int tempMax, result, tempResult;
    
    result = INT_MIN;
    do {
        std::vector<int>notfoundindex;
        std::vector<int>resultindex;
        
        int prev = -1;
        
        tempMax = maxim;
        for (int i = 0; i < nums.size() && tempMax; i++) {
            if ((tempMax - nums[i].first) >= 0) {
                if(prev != -1 && abs(nums[i].second-prev) == 1) { // not possible
                    notfoundindex.push_back(i);
                    continue;
                }
                notfoundindex.push_back(i);
                resultindex.push_back(i);
                
                tempMax -= nums[i].first;
                st.push(make_pair(nums[i].first, i));
            
                prev = nums[i].second;
            }
        }
        
        if(tempMax == 0) {
            // printf("result index : "); for(int x : resultindex)   printf("%d ", x); printf("\n");
            // printf("removed index : ");for(int x : notfoundindex) printf("%d ", x); printf("\n\n");
            tempResult = 0;
            while(!st.empty()) {
                p = st.top();
                
                tempResult = tempResult*10 + p.first;
                nums.erase(nums.begin() + p.second);
                st.pop();
            }
            result = max(result, tempResult);
        }
        // else {
        //     printf("Removed index : ");
        //     for(int x : notfoundindex) printf("%d ", x);
        //     printf("\n");
        // }
    }while(tempMax == 0);
    
    return result;
}

int maximumSum(std::vector<pair<int,int>>& nums)
{
	if(nums.size() == 0) return 0;
    
    int inc = nums[0].first, exc = 0;
	int new_exc;
	for(int i = 1; i < nums.size(); i++) {
        new_exc = (inc > exc) ? inc : exc;
        
		inc = exc + nums[i].first;
		exc = new_exc;
	}
	return max(inc, exc);
}

bool compare(pair<int,int>& a, pair<int,int>& b) {
    if(a.first > b.first) {
        return true;
    }
    return a.second < b.second;
}

int main()
{
	int t, n, data;
    bool allNeg;

	cin >> t;
	while(t--) {
		cin >> n;
		std::vector<pair<int,int>> nums(n);
		
		allNeg = true;
		for(int i = 0; i < n; i++) {
			cin >> data;
			if(data >= 0) allNeg = false;
			nums[i] = make_pair(data, i);
		}
		
		if(allNeg) {
		    int maxim = INT_MIN;
		    for(pair<int,int> x : nums) maxim = max(maxim, x.first);
		    printf("%d\n", maxim);
		    break;
		}

        int maxim = maximumSum(nums);
        
        sort(nums.begin(), nums.end(), compare);
        // for(pair<int,int> x : nums) {
        //     printf("[%d,%d] ", x.first, x.second);
        // }
        // printf("\n");
		
		cout << includeElement(nums, maxim) << endl;
	}

	return 0;
}