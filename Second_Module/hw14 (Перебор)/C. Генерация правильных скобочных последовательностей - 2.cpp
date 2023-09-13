#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

void Scopes(int cnt1, int cnt2, int cnt3, int cnt4, string str, int n, vector<string>& stack) {
    if (str.size() == 2 * n) {
        cout << str << endl;
        return;
    }
    if (cnt1 + cnt3 < n) {
        str += "(";
        stack.push_back("(");
        Scopes(cnt1 + 1, cnt2, cnt3, cnt4, str, n, stack);
        str.pop_back();
        stack.pop_back();
        str += "[";
        stack.push_back("[");
        Scopes(cnt1, cnt2, cnt3 + 1, cnt4, str, n, stack);
        str.pop_back();
        stack.pop_back();
    }
    if (cnt1 > cnt2 && stack.back() == "(") {
        str += ")";
        stack.pop_back();
        Scopes(cnt1, cnt2 + 1, cnt3, cnt4, str, n, stack);
        str.pop_back();
        stack.push_back("(");
    }
    if (cnt3 > cnt4 && stack.back() == "[") {
        str += "]";
        stack.pop_back();
        Scopes(cnt1, cnt2, cnt3, cnt4 + 1, str, n, stack);
        str.pop_back();
        stack.push_back("[");
    }
}

int main() {
    int n;
    cin >> n;

    string str;
    vector<string> stack;
    if (n % 2 == 0) {
        Scopes(0, 0, 0, 0, str, n / 2, stack);
    }
}


