#include<bits/stdc++.h>
using namespace std;

#define LL long long int

struct Person
{
    Person *parent;
    int rank;

    Person() : rank(0) {} 
};

Person *findSet(Person *person)
{
    if(person->parent == person) {
        return person;
    }
    
    person->parent = findSet(person->parent);
    return person->parent;
}

void merge(Person *p1, Person *p2)
{
    Person *s1 = findSet(p1);
    Person *s2 = findSet(p2);

    if(s1 == s2) return; // same set;

    if(s1->rank >= s2->rank) {
        s1->rank += (s2->rank + 1);
        s2->parent = s1;
    }
    else {
        s2->rank += (s1->rank + 1);
        s1->parent = s2;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    // Code Here
    int n, m;
    int u, v;

    cin >> n >> m;

    vector<Person*> arr(n+1);
    for(int i = 1; i <= n; i++) {
        arr[i] = new Person();
        arr[i]->parent = arr[i];
    }

    for(int i = 0; i <= m; i++) {
        cin >> u >> v;
        merge(arr[u], arr[v]);
    }

    for(int i = 1; i <= n; i++) {

        Person *temp = findSet(arr[i]);
        cout << temp->rank << " ";
    }

    return 0;
}