#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long K;
    cin >> n >> K;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    int answer = n + 1;

    for (int l = 0; l < n; l++) {
        int left = l;
        int right = n - 1;
        int ansR = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (prefix[mid + 1] - prefix[l] >= K) {
                ansR = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (ansR != -1) {
            int len = ansR - l + 1;
            answer = min(answer, len);
        }
    }

    cout << answer << '\n';

    return 0;
}