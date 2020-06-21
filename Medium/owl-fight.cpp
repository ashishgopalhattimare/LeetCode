// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/
// Easy

#include<bits/stdc++.h>
using namespace std;

#define LL long long int

struct Person
{
    Person *parent;
    int rank;
    int power;

    Person(int power) : rank(0), power(power) {} 
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
        s1->power = max(s1->power, s2->power);
        s1->rank += (s2->rank + 1);
        s2->parent = s1;
    }
    else {
        s2->power = max(s2->power, s1->power);
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
    int n, m, q;
    int u, v;

    cin >> n >> m;

    vector<Person*>arr(n+1);
    for(int i = 1; i <= n; i++) {
        arr[i] = new Person(i);
        arr[i]->parent =arr[i];
    }

    while(m--) {
        cin >> u >> v;
        merge(arr[u], arr[v]);
    }

    Person *u1, *v1;

    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        u1 = findSet(arr[u]);
        v1 = findSet(arr[v]);
    
        if(u1 == v1) { // same group, friends
            printf("TIE\n");
        }
        else if(u1->power > v1->power) {
            printf("%d\n", u);
        }
        else {
            printf("%d\n", v);
        }
    }
    
    // [1 2 7] [3 4] 5 6

    return 0;
}