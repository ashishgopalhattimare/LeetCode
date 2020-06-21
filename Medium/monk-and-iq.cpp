// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-iq/description/
// Easy-Medium, Priority Queue

#include <bits/stdc++.h>
using namespace std;

#define LL long long int

struct Course
{
    LL x; // sum of IQ of the last two students
    LL c; // number of students already enrolled in the course
    LL z; // x*c

    int id;

    vector<LL>lastTwo;
    Course(int identity) : c(0), x(0), z(0) {
        id = identity;

        lastTwo = vector<LL>(3, 0);
    }

    void addStudent(int IQ) {
        c++;
        switch(c) {
            case 1: lastTwo[1] = IQ;
                    break;
            case 2: lastTwo[2] = IQ;
                    break;
            default:
                    lastTwo[1] = lastTwo[2];
                    lastTwo[2] = IQ;
        }

        x = lastTwo[1] + lastTwo[2];
        z = x * c;
    }

    bool operator<(const Course& other) const {
        if(z == other.z) return id > other.id;
        return z > other.z;
    }
};

int main()
{
    int C, P, N;
    int IQ;

    priority_queue<Course>pq;

    cin >> C >> P >> N;

    // Courses assigned to each student
    vector<int>assignCourse(P+1, 0);

    // Add C courses to pq
    for(int i = 1; i <= C; i++) {
        pq.push({i});
    }

    // IQ of the student
    for(int i = 1; i <= N; i++) {
        cin >> IQ;

        Course temp = pq.top(); pq.pop();
        temp.addStudent(IQ);

        pq.push(temp);
    }
    
    // IQ of Monk and his friends
    for(int i = 1; i <= P; i++) {
        cin >> IQ;

        Course temp = pq.top(); pq.pop();

        assignCourse[i] = temp.id;
        temp.addStudent(IQ);

        pq.push(temp);
    }

    for(int i = 1; i <= P; i++) {
        printf("%d ", assignCourse[i]);
    }
    printf("\n");

    return 0;
}