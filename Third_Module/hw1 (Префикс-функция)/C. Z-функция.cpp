#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> z(str.size());
    int left = 0;
    int right = 0;
	cout << 0 << ' ';
    for(int i = 1; i < str.size(); ++i) {
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
        
        cout << z[i] << ' ';
    }
}


