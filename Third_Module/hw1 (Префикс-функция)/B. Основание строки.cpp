#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> prefix(str.size());
    for (int i = 1; i < str.size(); ++i) {
        int k = prefix[i - 1];
        while (k && str[i] != str[k]) {
            k = prefix[k - 1];
        }
        if (str[i] == str[k]) {
            ++k;
        }
        prefix[i] = k;
    }
    cout << str.size() - prefix.back();
}


