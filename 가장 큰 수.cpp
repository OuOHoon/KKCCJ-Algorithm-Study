#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 1. 숫자를 문자열로 변환
// 2. 두 문자열을 이어붙였을 때 큰 수를 기준으로 벡터 정렬
// 3. 정렬된 벡터를 문자열로 이어붙임

bool compare (string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector <string> num_s;

	for (int i = 0; i < numbers.size(); i++)
		num_s.push_back(to_string(numbers[i]));

	sort(num_s.begin(), num_s.end(), compare);

	for (int i = 0; i < numbers.size(); i++)
		answer += num_s[i];

  if (answer[0] == '0') return "0";
	return answer;
}
