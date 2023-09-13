#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> z_function(const string &text, const string &key) {
    auto str = key + '#' + text;
    vector<int> z(str.size());
    int left = 0;
    int right = 0;

    for (int i = 1; i < str.size(); ++i) {
        if (i <= right) {
            z[i] = min(right - i + 1, z[i - left]);
        }
        while (i + z[i] < str.size() && str[z[i]] == str[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }

    vector<int> new_z;
    for (int i = key.size() + 1; i < str.size(); ++i) {
        new_z.push_back(z[i]);
    }
    return new_z;
}

int main() {
    string key, text;
    cin >> key >> text;

    auto z = z_function(text, key);
    reverse(text.begin(), text.end());
    reverse(key.begin(), key.end());
    auto reverse_z = z_function(text, key);
    reverse(reverse_z.begin(), reverse_z.end());

    vector<int> ans;
    for (int i = 0; i < text.size(); ++i) {
        if (z[i] == key.size()) {
            ans.push_back(i + 1);
        } else if (i + key.size() - 1 < reverse_z.size() && z[i] + reverse_z[i + key.size() - 1] == key.size() - 1) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for (const auto &num: ans) {
        cout << num << ' ';
    }
}



