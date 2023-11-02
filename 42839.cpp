#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    solution("123");
}

int solution(string numbers) {

    int countTarget = 0;
    int numLength = numbers.length();
    int tmpArray[numLength];
    int tmp = std::stoi(numbers);

    for (int i = 0; i < numLength; i++) {
        if (10 < tmp)
            tmpArray[i] = (tmp % 10);
        else
            tmpArray[i] = tmp;
        tmp /= 10;
    }

    do{}
    while ()

    //1.    숫자 배열 char로 받기.
    //2.    char 배열 랜덤한 모든 경우의 수를 String으로 넘기기
    //3.    String을 int로 변환해 isPrime
    //4.    if(isPrime) countTarget++;
}

bool isPrime(int num) {
    if ( num <= 1)
        return false;
    for (int i = 2; i <= num/2; i++) {
        if (i * i == num)
            return true;
    }
}
