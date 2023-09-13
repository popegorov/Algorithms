#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct SnowMan {
    SnowMan* prev = nullptr;
    int last_ball = 0;
    int weight = 0;
} first;

int main() {
    int n;
    cin >> n;

    vector<SnowMan*> snowmans(n + 1);
    snowmans[0] = &first;
    for (int i = 1; i < n + 1; ++i) {
        int prev_sm, cur_weight;
        cin >> prev_sm >> cur_weight;

        snowmans[i] = new SnowMan;
        if (cur_weight) {
            snowmans[i]->prev = snowmans[prev_sm];
            snowmans[i]->last_ball = cur_weight;
            snowmans[i]->weight = snowmans[prev_sm]->weight + cur_weight;
        } else {
            snowmans[i]->prev = snowmans[prev_sm]->prev->prev;
            snowmans[i]->last_ball = snowmans[prev_sm]->prev->last_ball;
            snowmans[i]->weight = snowmans[prev_sm]->weight - snowmans[prev_sm]->last_ball;
        }
    }

    long long total_weight = 0;
    for (const auto& cur_sm : snowmans) {
        total_weight += cur_sm->weight;
    }
    cout << total_weight;
}


