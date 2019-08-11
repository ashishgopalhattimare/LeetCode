#include <bits/stdc++.h>
using namespace std;

int binary_search(int start, int end, vector<int>& nums, int movie)
{
	if(start > end) return -1;

    if(start == end || end == start + 1) {
        if(movie >= nums[end]) return end;        
        return start;
    }
	
	int mid = start + (end-start)/2;

	if(nums[mid] == movie) return mid;

	if(movie > nums[mid])
		return binary_search(mid, end, nums, movie);
	return binary_search(start, mid, nums, movie);
}

pair<int,int> the_closest_sum(vector<int>& nums, int d)
{
	int GAP = 30;
	int DURATION = d - GAP;

	int index, nextmovie;
    int minGap = INT_MAX;

    pair<int,int> result = make_pair(-1,-1);

	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size(); i++) {
		
		nextmovie = d-GAP-nums[i];
		if(nextmovie >= 1) {
            index = binary_search(0, nums.size()-1, nums, nextmovie);

            if(index > 0) {
                index -= (index == i);
                
                if(minGap > DURATION-(nums[i]+nums[index])) {
                    minGap = DURATION-(nums[i]+nums[index]);
                    result = make_pair(nums[i], nums[index]);
                }
            }
        }
    }

    return result;
}

int main()
{
    vector<int>movie_duration = {60, 75, 85, 90, 120, 125, 150};
    int d = 250;

    pair<int,int> result = the_closest_sum(movie_duration, d);
    cout << result.first << " " << result.second << endl;

    return 0;
}