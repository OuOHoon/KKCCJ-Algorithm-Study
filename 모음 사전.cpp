#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 1. 모든 중복 순열 구하기 (재귀)
// 2. 사전순으로 정렬

char vowel[5] = {'A', 'E', 'O', 'U', 'I'};
char arr[5];
vector <string> dic;

void makeWords(int index) {
	string w;
	for (int j = 0; j < index; j++) {
		w += arr[j];
	}
	dic.push_back(w);

	if (index < 5) {
		for (int i = 0; i < 5; i++) {
			arr[index] = vowel[i];
			makeWords(index + 1);
		}
	}
}

int solution(string word) {
	int answer = 0;

	makeWords(0);
    sort(dic.begin(), dic.end());

	for (int i = 0; i < dic.size(); i++) {
		if (dic[i] == word) {
			answer = i;
			break;
		}
	}

	return answer;
}
