#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    while (q.size() > 1) {
        int a = q.top();
        q.pop();

        int b = q.top();
        q.pop();

        if (a != b)
            q.push(a - b);
    }

    if (q.empty())
        cout << 0;
    else
        cout << q.top();

    return 0;
}