#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    string str;
    getline(cin, str);
    unordered_map<string, int> dict;
    int dict_size = 128;

    for (int i = 0; i < dict_size; ++i) {
        string key;
        key += i;
        dict[key] = i;
    }

    vector<int> ans;

    for (int i = 0; i < str.size();) {
        string cur_str;
        cur_str += str[i];
        auto j = i;
        int to_ans = dict[cur_str];

        while (dict.contains(cur_str) && j < str.size()) {
            ++j;
            cur_str += str[j];
            if (dict.contains(cur_str)) {
                to_ans = dict[cur_str];
            }
        }

        dict[cur_str] = dict_size++;
        ans.push_back(to_ans);

        i = j;
    }

    cout << ans.size() << endl;
    for (const auto& cur : ans) {
        cout << cur << ' ';
    }
}
