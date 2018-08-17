// https://leetcode.com/problems/queue-reconstruction-by-height/description/

struct Node
{
    int h, k;
    Node *prev, *next;
    
    Node(int height, int kth) : h(height) , k(kth) {
        prev = next = NULL;
    }
}*front = NULL, *rear = NULL;

bool compare(pair<int, int> & A, pair<int, int> & B)
{
    if(A.first == B.first) {
        return A.second < B.second;
    }
    return A.first > B.first;
}

void insertFront(int height, int k)
{
    Node *temp = new Node(height, k);

    if(front == NULL) {
        front = temp;
        rear = temp;
    }
    else {
        temp->next = front;
        front->prev = temp;

        front = temp;
    }
    return;
}

void insertNode(Node *ptr, int height, int k)
{
    Node *temp = new Node(height, k);

    if(ptr->next == NULL) {
        ptr->next = temp;
        temp->prev = ptr;

        rear = temp;
    }
    else {
        temp->next = ptr->next;
        temp->next->prev = temp;

        temp->prev = ptr;
        ptr->next = temp;
    }
    return;
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        sort(people.begin(), people.end(), compare);
        
        front = rear = NULL;
        
        Node *ptr, *prev;
        for(int i = 0; i < people.size(); i++) {
            if(front == NULL || people[i].second == 0) {
                insertFront(people[i].first, people[i].second);
            }
            else {
                ptr = front;
                int count = people[i].second;

                prev = NULL;
                while(count) {
                    if(ptr->h >= people[i].first) {
                        count--;
                    }
                    prev = ptr;
                    ptr = ptr->next;
                }

                insertNode(prev, people[i].first, people[i].second);
            }
        }

        vector<pair<int, int> > V;

        ptr = front;
        while(ptr) {
            V.push_back(make_pair(ptr->h, ptr->k));
            ptr = ptr->next;
        }

        return V;
    }
};