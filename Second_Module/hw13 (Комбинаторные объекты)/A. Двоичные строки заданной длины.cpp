#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void print_binary(size_t bits_count) {
    for(int i = 0; i < (1<<bits_count); ++i) {
        for(size_t bit = bits_count; bit > 0; --bit) {
           if ((i & (1<<(bit - 1)))) {
               cout << 1;
           } else {
               cout << 0;
           }
        }
        cout << endl;
    }
}

int main() {
    size_t n;
    cin >> n;
    print_binary(n);
}


