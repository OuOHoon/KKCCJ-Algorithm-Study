#define _GLIBCXX_HOSTED 1
#include <bits/stdc++.h>

using namespace std;

/**
 1. 문자열을 문자로 나눈다.
 2. 문자들로 1부터 numbers의 길이 자릿수의 수를 전부 만든다.
 3. 만든 수가 소수인지 판단하고 결과에 추가한다.
 */

vector<int> splitNumbers(string& numbers) {
    vector<int> result;
    for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
        result.push_back(*iter);
    }
    return result;
}

vector<bool> primeNumbers(10000000, true);
void setPrimeNumbers(int size) {
    primeNumbers[0] = primeNumbers[1] = false;
    for(auto i = 2; i*i <= size; i++){
        if (primeNumbers[i]) {
            for (auto j = i * i; j <= size; j += i) {
                primeNumbers[j] = false;
            }
        }
    }
}

bool isPrimeNumber(int number) {
    return primeNumbers[number];
}


// 흠..
vector<int> makeNumbers(vector<int> numbers, int size) {
    vector<int> result;
    
    return result;
}


int solution(string numbers) {
    int answer = 0;
    vector<int> intNumbers = splitNumbers(numbers);
    for(int i = 1; i <= numbers.size(); i++) {
        auto numbers = makeNumbers(intNumbers, i);
        for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
            if (isPrimeNumber(*iter))
                answer++;
        }
    }
    return answer;
}



int main() {
    setPrimeNumbers(10000000);
    cout << solution("17") << endl;
    cout << solution("011") << endl;
}
