#include <string>
#include <algorithm>
#include <list>

using namespace std;

// 1. 연산자를 기준으로 숫자와 연산자를 분리하여 연결리스트에 저장
// 2. 3개의 연산자 순열(6가지 경우) 탐색
// 3. 리스트에서 연산자를 찾은 뒤 연산자 앞, 뒤의 숫자와 연산자를 모두 제거 -> 계산 -> 다시 리스트에 삽입
// 4. 리스트에 최종 결과값 1개만 남을 때까지 반복
// 5. 리스트 사이즈가 1이 되면 해당 결과값이 max값인지 비교

vector <string> op = { "*", "+", "-"};
list <string> ex;

bool isOp(char c) {
    if (c == '*' || c == '+' || c == '-') return true;
    else return false;
}

long long solution(string exp) {
    long long answer = 0;
    string num = "";

    for (int i = 0; i < exp.size(); i++) {
        if (isOp(exp[i])) {
            ex.push_back(num);
            ex.push_back(string(1, exp[i]));
            num = "";
        } 
        else num += exp[i];       
    }
    ex.push_back(num);

    do {
        int i = 0;
        list <string> now = ex;

        while(now.size() > 1) {
            if (i == 4) break;

            auto it = find(now.begin(), now.end(), op[i]);

            if (it != now.end()) {
                auto next = it;
                long long st = stoll(*--it);
                long long end = stoll(*++next);

                auto itEnd = ++next;
                now.erase(it, itEnd);

                long long n = 0;
                if (op[i] == "*") n = st * end;
                else if (op[i] == "+") n = st + end;
                else n = st - end;

                now.insert(next, to_string(n));
            }
            else i++;
        }
        answer = max(answer, abs(stoll(now.front())));

    } while (next_permutation(op.begin(), op.end()));

    return answer;
}
