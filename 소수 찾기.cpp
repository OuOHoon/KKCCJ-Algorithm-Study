#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string numbers;
vector <int> num;
vector <int> v;

// 모든 조합 구하기
void makeNums(int len) {
	for (int j = 1; j <= len; j++) {
		do {
			int n = 0;
			for (int i = 0; i < j; i++)
				n += pow(10, j - i - 1) * num[i];		
			v.push_back(n);

		} while (next_permutation(num.begin(), num.end()));
	}
}

// 소수인지 판별
bool isPrime(int n) {
	if (n <= 1) return false;

	for (int i = 2; i * i <= n; i++) {	// 2부터 루트 n까지 순회
		if (n % i == 0) return false;	// 나누어 떨어지면 소수가 아님
	}

	return true;
}

int main() {
	FIO;
	int answer = 0;

	cin >> numbers;
	int len = numbers.length();

	for (int i = 0; i < len; i++) 
		num.push_back(numbers[i] - '0');	// 문자열을 순회하며 숫자 하나씩 벡터에 넣음

	sort(num.begin(), num.end());
	makeNums(len);						

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());	// 중복 제거

	for (int i = 0; i < v.size(); i++)
		if (isPrime(v[i])) answer++;	// 소수인지 확인	

	cout << answer;
	
	return 0;
}
