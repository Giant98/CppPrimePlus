#include <iostream>
#include <queue>
using namespace std;

struct Student {
    string name;
    int num;
    int age;
};

bool cmp(const Student& s1, const Student& s2) {
    return s2.num > s1.num;
}

int main() {
    Student stu[5] = { {"Zhang san", 1, 18}, {"Li Si", 2, 19}, {"Wang Er", 3, 20},
                      {"Ma Zi", 4, 21}, {"Lucy", 5, 17} };
    priority_queue<Student, vector<Student>, decltype(&cmp)>q(cmp);
    for (int i = 0; i < 5; ++i) {
        q.push(stu[i]);
    }
    while (!q.empty()) {
        cout << q.top().name << " is " << q.top().num << endl;
        q.pop();
    }
    return 0;
}
