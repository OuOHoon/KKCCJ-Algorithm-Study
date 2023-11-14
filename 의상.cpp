#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 1. 벡터를 해시에 저장
// 2. 옷 종류와 개수 저장
// 3. 조합의 수 return

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> hash;

    for (int i = 0; i < clothes.size(); i++) {
        auto it = hash.find(clothes[i][1]);

        if (it != hash.end()) it->second++;
        else hash[clothes[i][1]] = 1;
    }

    for (auto& pair : hash) 
        answer *= pair.second + 1;
    
    return --answer;
}
