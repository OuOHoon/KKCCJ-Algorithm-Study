#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 문자를 아스키코드로 치환하여 계산
// 2. 이동 횟수 = A에서 이동과 Z에서 이동 + 1중에 작은 것 선택
// 3. 중간에 A로만 이루어진 문자열이 있는 경우 인덱스 번호와 길이를 구함
// 4. 왼쪽과 오른쪽의 남은 문자열을 비교하여 짧은쪽부터 탐색
// 5. 부분 문자열을 건너뛴 것과 그렇지 않은 것 중 작은 것 선택
// 6. 부분 A 문자열마다 반복

int solution(string name) {
    int answer = 0;

    // 위/아래 알파벳 찾기
    for (int i = 0; i < name.length(); i++) {
        int cnt = min(name[i] - 'A', 'Z' - name[i] + 1);
        answer += cnt;
    }

    // A 부분 문자열
    int len = 0;
    int st = -1;
    int end = -100;

    int move = name.length() - 1;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'A') {
            if (len == 0) st = i;
            len++;           

            if (i == name.length() - 1) {
                if (st != 0) st--;
                end = i;

                int right = name.length() - end - 1;
                int move_lr = min(st * 2 + right, st + right * 2);
                move = min(move, move_lr);
            }
        }
        else if (len > 0){
            if (st != 0) st--;
            end = i - 1;

            int right = name.length() - end - 1;
            int move_lr = min(st * 2 + right, st + right * 2);
            move = min(move, move_lr);
            len = 0;
        }
    }

    answer += move;

    return answer;
}
