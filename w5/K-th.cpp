#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<long long, vector<long long>, greater<long long>> q;
    long long sum = 0;

    while (n--) {
        string s;
        cin >> s;

        if (s == "insert") {
            long long x;
            cin >> x;
            q.push(x);
            sum += x;

            if (q.size() > k) {
                sum -= q.top();
                q.pop();
            }
        } else {
            cout << sum << '\n';
        }
    }
}