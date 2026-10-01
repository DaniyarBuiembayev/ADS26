#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> leftChild(n + 1, 0);
    vector<int> rightChild(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0) {
            leftChild[a] = b;
        }
        else {
            rightChild[a] = b;
        }
    }

    queue<int> q;
    q.push(1);
    int answer = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        if (levelSize > answer) {
            answer = levelSize;
        }

        for (int i = 0; i < levelSize; i++) {
            int v = q.front();
            q.pop();

            if (leftChild[v] != 0) {
                q.push(leftChild[v]);
            }
            if (rightChild[v] != 0) {
                q.push(rightChild[v]);
            }
        }
    }

    cout << answer << "\n";
    return 0;
}