#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> q;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        q.push(x);
    }

    long long ans = 0;

    while (q.size() > 1) {
        long long a = q.top();
        q.pop();

        long long b = q.top();
        q.pop();

        long long sum = a + b;

        ans += sum;
        q.push(sum);
    }

    cout << ans;

    return 0;
}