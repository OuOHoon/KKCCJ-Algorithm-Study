#include <algorithm>
#include <vector>

using namespace std;

vector <pair <int, int>> v = { {2, 3}, {2, 4}, {3, 4} };

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end(), greater<>());

    int len = weights.size();
    for (int i = 0; i < len; i++) {
        int st = weights[i];

        for (int j = i + 1; j < len; j++) {
            int end = weights[j];

            for (int k = 0; k < 3; k++) {
                int f = v[k].first;
                int s = v[k].second;

                if (st == end || st * f == end * s) {
                    answer++;
                    break;
                }
            }
        }
    }

    return answer;
}
