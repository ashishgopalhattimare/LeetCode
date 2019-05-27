#include <bits/stdc++.h>

using namespace std;

class SubarrayXor
{
private:
	vector<int>segmentTree, nums;
	int len, maxLevel;

public:
	SubarrayXor(vector<int> temp) {
		vector<int>arr(2.5*temp.size(), 0);
		segmentTree = arr;
		nums = temp;

		len = temp.size()-1;

		maxLevel = 0;
		construct(0, len, 0, temp, 1);
	}

	int construct(int start, int end, int index, vector<int>& temp, int level) {
		if(start > end) return 0;

		maxLevel = max(maxLevel, level);
		if(start == end) return (segmentTree[index] = temp[start]);
		
		int mid = start+(end-start)/2;
		int l = construct(start, mid, 2*index+1, temp, level+1);
		int r = construct(mid+1, end, 2*index+2, temp, level+1);

		return (segmentTree[index] = l ^ r);
	}

	void updateSegmentTree(int start, int end, int index, int pos, int value) {
		if(pos < start || pos > end) return;

		if(start == end) {
			if(start == pos) {
				segmentTree[index] = value;
				nums[start] = value;
			}
			return;
		}
		int mid = start + (end-start)/2;

		updateSegmentTree(start, mid, 2*index+1, pos, value);
		updateSegmentTree(mid+1, end, 2*index+2, pos, value);

		segmentTree[index] = segmentTree[2*index+1] ^ segmentTree[2*index+2];
		return;
	}

	int xorSegmentTree(int start, int end, int index, int left, int right) {
		if(right < start || end < left) { 	// out of range query
			return 0;
		}
		if(start == end) segmentTree[index];// leaf node
		if(left <= start && end <= right) 	// complete overlap
			return segmentTree[index];

		int mid = start + (end-start)/2;	// partial overlap

		return 	xorSegmentTree(start, mid, 2*index+1, left, right)^
				xorSegmentTree(mid+1, end, 2*index+2, left, right);
	}

	void update(int pos, int value) {
		updateSegmentTree(0, len, 0, pos, value);
	}

	int xorRange(int l, int r) {
		return xorSegmentTree(0, len, 0, l, r); 
	}

	int brute(int l, int r) {
		r = (r > len)? len : r;
		int sum = 0;
		for(int i = l; i <= r; i++) {
			sum ^= nums[i];
		}
		return sum;
	}

	void display() {
		for(int x : nums) printf("%d ", x);
		printf("\n");

		for(int i = 0; i <= pow(2, maxLevel); i++) {
			printf("%d ", segmentTree[i]);
		}
		printf("\n");
	}
};

int main(int argc, char const *argv[])
{
	SubarrayXor *sol1 = new SubarrayXor({1,3,5,7,9,11});

	sol1->display();	// display
	sol1->update(3, 6);	// update
	sol1->display();	// display

	// Range Query
	cout << sol1->brute(2,5) << " " << sol1->xorRange(2,5) << endl;
	return 0;
}