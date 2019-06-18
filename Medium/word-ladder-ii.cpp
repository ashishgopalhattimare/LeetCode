// https://leetcode.com/problems/word-ladder-ii/
// Hard, Amazon SDE II
// TLE, look for part 1 of it

struct Node {
    string word;
    bool visited;
    vector<int>neighbours;

    Node(string word) : word(word), visited(false) {}
};

class Solution {
public:

    int minLength, len;

    bool difference(string x, string y) {
        int diff = 0;
        for(int i = 0; i < x.length() && diff < 2; i++) {
            if(x[i] != y[i]) diff++;
        }

        return (diff == 1);
    }

    void calculateBFS(int source, vector<Node*>nodes, int l, string endWord, vector<vector<string>>& result, vector<string>& path) {

    	if(nodes[source]->visited || l > minLength) return;

        path.push_back(nodes[source]->word);

    	if(nodes[source]->word == endWord) {
            if(minLength > l) {
                minLength = l;
                len = 0;
            }
            if(result.size() == len) result.push_back(path);
            else result[len] = path;
            len++;
    	}

    	nodes[source]->visited = 1;
    	for(int i = 0; i < nodes[source]->neighbours.size(); i++) {
    		calculateBFS(nodes[source]->neighbours[i], nodes, l+1, endWord, result, path);
    	}
    	nodes[source]->visited = 0;
        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string,int>indexmap;

        vector<Node*>nodes(wordList.size());
        for(int i = 0; i < nodes.size(); i++) {
            nodes[i] = new Node(wordList[i]);
            indexmap[wordList[i]] = i;
        }

        for(int i = 0; i < wordList.size(); i++) {
            string curr = wordList[i];
            for(int j = i+1; j < wordList.size(); j++) {
                string next = wordList[j];

                if(difference(curr, next)) {
                    nodes[i]->neighbours.push_back(j);
                    nodes[j]->neighbours.push_back(i);
                }
            }
        }

        if(indexmap.find(endWord) == indexmap.end()) return {};

        vector<vector<string>>result;
        vector<string>path;

        minLength = INT_MAX;
        if(indexmap.find(beginWord) != indexmap.end()) { // start is already in the wordList
            calculateBFS(indexmap[beginWord], nodes, 1, endWord, result, path);
        }
        else { // not in the wordList
            path.push_back(beginWord);
            for(int i = 0; i < wordList.size(); i++) {
            	if(difference(wordList[i], beginWord)) {
                    calculateBFS(indexmap[wordList[i]], nodes, 2, endWord, result, path);
            	}
            }
        }
        
        while(result.size() > len) {
            result.pop_back();
        }

        return result;
    }
};
