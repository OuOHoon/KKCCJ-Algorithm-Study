#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// 1. 큐에 괄호 하나씩 넣음
// 2. 큐 순회
// 2-1. 여는 괄호일 경우 스택에 push
// 2-2. 닫는 괄호이며 스텍이 비어있거나 쌍이 맞지 않으면 return false
// 2-3. 닫는 괄호이며 쌍으로 이루어진 괄호가 스택 top인 경우 pop
// 2-4. 순회 완료 후 스택이 비어있는 경우 return true
// 3. true인 경우 count

string b = "[](){}";

bool check(queue <char> q) {
    stack <char> st;
    
    while(!q.empty()) {
        char f = q.front();
        q.pop();

        if (f == '[' || f == '{' || f == '(') st.push(f);
        else {
            if (st.empty()) return false;

            size_t loc = b.find(f);
            if (b[loc - 1] == st.top()) st.pop();
            else return false;
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    queue <char> q;

    for (char c : s) {
        q.push(c);
    }

    for (int i = 0; i < q.size() - 1; i++) {
        if (check(q)) answer++;

        char f = q.front();
        q.pop();
        q.push(f);
    }

    return answer;
}
