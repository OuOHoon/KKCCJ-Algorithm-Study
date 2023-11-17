#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void push(int n, int st, int end) {
    vector<int> v;
    v.push_back(st);
    v.push_back(end);
    answer.push_back(v);
}

void hanoi(int n, int st, int end, int sub) {
    if (n == 1) {
        push(n, st, end);
        return;
    }
    else {
        hanoi(n - 1, st, sub, end);     // n-1개 원판을 2번 막대로 옮김
        push(n, st, end);               // 가장 큰 원판 push
        hanoi(n - 1, sub, end, st);     // n-1개 원판을 다시 3번 막대로 옮김
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    return answer;
}
