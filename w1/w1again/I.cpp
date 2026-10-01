#include <iostream>
#include <deque>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        deque<int> deck;

        deck.push_front(N);

        for (int i = N - 1; i >= 1; i--) {
            deck.push_front(i);

            for (int j = 0; j < i; j++) {
                deck    .push_front(deck.back());
                deck.pop_back();
            }
        }

        for (int i = 0; i < N; i++) {
            cout << deck[i];
            if (i + 1 < N) cout << " ";
        }

        cout << '\n';
    }

    return 0;
}