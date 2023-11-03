#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 10
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	vector<int> prime;

	int x, y;
	int xy = brown + yellow;
	int x_y = brown / 2 + 2;

	for (int i = 1; i <= sqrt(xy); i++) {
		if (xy % i == 0) {
			prime.push_back(i);
			prime.push_back(xy / i);
		}
	}
	sort(prime.begin(), prime.end());

	for (int i = 0; i < prime.size(); i++) {
		if (prime[i] + prime[prime.size() - i - 1] == x_y) {
			if (prime[i] >= prime[prime.size() - i]) {
				x = prime[i];
				y = prime[prime.size() - i - 1];
			}
			else {
				x = prime[prime.size() - i - 1];
				y = prime[i];
			}
		}
	}

	answer.push_back(x);
	answer.push_back(y);

	return answer;
}

void main() {
	FIO;

	// 1. brown + yellow = 가로 * 세로
	// 2. brown / 2 + 2 = 가로 + 세로
	// 3. 약수를 모두 찾음
	// 4. 완전탐색으로 더하여 값 찾기
	
	
	vector<int> answer = solution(10, 2);

	for (int i : answer)
		cout << i << '\n';

}