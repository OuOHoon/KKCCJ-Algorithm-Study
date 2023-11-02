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

// �Ҽ����� �Ǻ�
bool isPrime(int n) {
	if (n <= 1) return false;

	for (int i = 2; i * i <= n; i++) {	// 2���� ��Ʈ n���� ��ȸ
		if (n % i == 0) return false;	// ������ �������� �Ҽ��� �ƴ�
	}

	return true;
}

int main() {
	FIO;
	int answer = 0;
	int len = numbers.length();

	cin >> numbers;

	for (int i = 0; i < len; i++) 
		num[i] = numbers[i] - '0';		// ���ڿ��� ��ȸ�ϸ� ���� �ϳ��� �迭�� ����


	// ��� ���� ���ϱ� 
	// next_permutation....


	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());	// �ߺ� ����

	for (int i = 0; i < v.size(); i++)
		if (isPrime(v[i])) answer++;	// �Ҽ����� Ȯ��		

	cout << answer;
	
	return 0;
}