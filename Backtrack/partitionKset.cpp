#include <bits/stdc++.h>

using namespace std;

// what if the list has to be ordered in the random order for the resultant

void partition(int index, int sum, vector<int>& nums, int k, int count, vector<vector<int> >& result)
{
	if(index == nums.size() && k == count) {

		for(int i = 0; i < result.size(); i++) {
			printf("[");
			for (int j = 0; j < result[i].size(); ++j)
			{
				printf("%d ", result[i][j]);
			}
			printf("]");
		}
		printf("\n");
		return;
	}

	int tempSum = 0;
	vector<int> sumArray;
	for(int i = index; i < nums.size(); i++) {
		tempSum += nums[i];
		sumArray.push_back(nums[i]);

		if(tempSum == sum) {
			result.push_back(sumArray);
			partition(i+1, sum, nums, k, count+1, result);
			result.pop_back();
		}
		else if(tempSum > sum) {
			break;
		}
	}

	return;
}

void equalSum(int index, vector<int>& nums, int k, int count, vector<vector<int> >& result)
{
	int sum = 0;

	vector<int> sumArray;
	for(int i = index; i < nums.size(); i++) {
		sum += nums[i]; // total sum so far

		sumArray.push_back(nums[i]); // insert element into the sumArray

		result.push_back(sumArray);
		partition(i+1, sum, nums, k, count+1, result);
		result.pop_back();
	}
}

int main(int argc, char* argv[])
{
	int n, k, data;

	cin >> n >> k;
	vector<int> nums;

	for (int i = 0; i < n; ++i)
	{
		cin >> data;
		nums.push_back(data);
	}

	vector<vector<int> > result;
	equalSum(0, nums, k, 0, result);

	return 0;
}