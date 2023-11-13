#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 벡터 정렬 (문자열이므로 1부터 9까지의 순서로 사전순 정렬)
// 2. i번째 문자열의 길이 저장(len)
// 3. 바로 다음 문자열의 substring과 비교
// 4. 같으면 false return

bool solution(vector<string> v) {
    bool answer = true;

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; i++) {
        int len = v[i].length();
        string str = v[i + 1].substr(0, len);
        if (v[i] == str) return false;
    }

    return answer;
}
