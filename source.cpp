#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 10
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string numbers;
int num[MAX];
vector <int> v;

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
	int len = numbers.length();

	cin >> numbers;

	for (int i = 0; i < len; i++) 
		num[i] = numbers[i] - '0';		// 문자열을 순회하며 숫자 하나씩 배열에 넣음


	// 모든 순열 구하기 
	// next_permutation....


	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());	// 중복 제거

	for (int i = 0; i < v.size(); i++)
		if (isPrime(v[i])) answer++;	// 소수인지 확인		

	cout << answer;
	
	return 0;
}