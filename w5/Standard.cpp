#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<long long> q;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        q.push(x);
    }

    long long answer = 0;

    for (int i = 0; i < m; i++) {
        long long x = q.top();
        q.pop();

        answer += x;

        if (x > 1)
            q.push(x - 1);
    }

    cout << answer;

    return 0;
}