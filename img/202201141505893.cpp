// C++ implementation
#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, char> a, pair<int, char> b) {
    // Sorting according to decreasing frequencies
    return a.first > b.first;
}

int main() {
    // Making vector of pairs and mapping them with their characters v[0] is for "a", v[1] is for "b", v[2] is for "c"
    vector<pair<int, char>> v(3);
    cin >> v[0].first >> v[1].first >> v[2].first;
    v[0].second = 'a';
    v[1].second = 'b';
    v[2].second = 'c';
    string s;
    int total = v[0].first + v[1].first + v[2].first;

    while (1) {
        string prev = s;
        // sorting to bring the highest frequency element to front
        sort(v.begin(), v.end(), compare);
        if (v[0].first == 0)
            break;
        // when length of the string < 2
        if (s.length() < 2) {
            s += v[0].second;
            v[0].first -= 1;
            continue;
        }
        // when length of the string > 2
        int len = s.length();
        for (int i = 0; i < 3; ++i) {
            if (v[i].first > 0 and (s[len - 1] != v[i].second or s[len - 2] != v[i].second)) {
                s += v[i].second;
                v[i].first -= 1;
                break;
            }
        }
        // check if the state has not changed from the previous state even after checking for "a", "b" and "c"
        if (s.length() == prev.length())
            break;
    }
    cout << s.size() << "\n";

    return 0;
}
