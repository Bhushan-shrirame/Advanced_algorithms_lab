#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int stepArea(pair<int, int>& step1, pair<int, int>& step2) {
        return step1.first * step2.second;
    }

    int minConcrete(vector<pair<int, int>>& steps, int K, int M) {
        int minConcrete = INT_MAX;
        for (int mask = 0; mask < (1 << (K - 1)); ++mask) {
            int removedSteps = 0;
            int totalConcrete = 0;
            for (int i = 0; i < K - 1; ++i) {
                if (!(mask & (1 << i))) totalConcrete += stepArea(steps[i], steps[i + 1]);
                else removedSteps++;
            }
            totalConcrete += stepArea(steps[K - 2], steps[K - 1]);
            if (removedSteps == M) minConcrete = min(minConcrete, totalConcrete);
        }
        return minConcrete;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    Solution st;
    int K, M;
    cin >> K >> M;
    vector<pair<int, int>> steps(K);
    for (int i = 0; i < K; ++i) cin >> steps[i].first >> steps[i].second;
    cout << st.minConcrete(steps, K, M) << endl;
    return 0;
}
