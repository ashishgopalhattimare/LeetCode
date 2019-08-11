#include <bits/stdc++.h>

using namespace std;

bool pathExist(vector<vector<int>>& matrix)
{
	vector<vector<int>>visited = matrix;
	for(int i = 0l i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = 0;
		}
	}

	list<vector<int>>ll;
	
	if(matrix[0][0] == 1) ll.push_back({0,0,1});
	else ll.push_back({0,0,-1});

	visited[0][0] = true;
	vector<int>curr;

	while(!ll.empty())
	{
		curr = ll.front();
		ll.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> matrix = 
	{
		{1, 0, 0, 0, 0, 0, 0},
	    {1, 1, 0, 1, 0, 0, 0},
	    {0, 1, 0, 0, 0, 0, 0},
	    {1, 1, 1, 1, 0, 1, 0}
	}

	cout << pathExist(matrix) << endl;

	return 0;
}