#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int x;
    cin >> x;

    vector<string> s1(x);
    vector<string> s2;

    for (int i = 0; i < x; i++) {
        cin >> s1[i];

        if (i == 0 || s1[i] != s1[i - 1]) {
            s2.push_back(s1[i]);
        }
    }

    cout << s2.size() << "\n";

    for (int i = 0; i < s2.size(); i++) {
        cout << s2[i] << "\n";
    }

    return 0;
}