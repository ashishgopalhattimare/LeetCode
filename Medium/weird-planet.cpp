// Queue (UNDONE)

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

vector<string> weirdPlanet(vector<vector<int>>& crew, vector<vector<int>>& member)
{   
    // Descendig Sort the queries according to incoming time
    sort(member.begin(), member.end(), [](vector<int>& a, vector<int>& b) {
        if(a[2] == b[2]) {
            return a[1] > b[1];
        }
        return a[2] > b[2];
    });

    sort(crew.begin(), crew.end(), [](vector<int>& a, vector<int>& b) {
        if(a[2] == b[2]) {
            return a[1] > b[1];
        }
        return a[2] > b[2];
    });
    
    vector<string> result(member.size(), "YES");

    int m = 0, c = 0;
    while(m < member.size() && c < crew.size())
    {
        vector<int> mem = member[m];
        vector<int> cre = crew[c];

        int ch = cre[0], cs = cre[1], ce = cre[2];
        int mh = mem[1], mt = mem[2];

        // printf("crew : [%d,%d,%d], member : [%d,%d]\n", ch, cs, ce, mh, mt);

        if(ce < mt) m++;
        else if(mt < cs) c++;
        else if(cs <= mt && mt <= ce) { // member is in the range of crew time
            if(mh <= ch) {
                result[mem[0]] = "NO";
            }
            m++;
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    int H, C, Q;
    int h, S, E;
    int t;

    // Hours, Crew count, Queries
    infile >> H >> C >> Q;

    vector<vector<int>> arr(C);
    for(int i = 0; i < C; i++) {

        // hours, start time, end time
        infile >> h >> S >> E;
        arr[i] = {h,S,E};
    }

    vector<vector<int>> queries(Q);
    for(int i = 0; i < Q; i++)
    {
        infile >> h >> t;
        queries[i] = {i,h,t};
    }

    vector<string> result = weirdPlanet(arr, queries);
    for(string x : result) {
        cout << x << '\n';
    }

    return 0;
}