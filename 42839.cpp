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


}

bool isPrime(int num) {
    if ( num <= 1)
        return false;
    for (int i = 2; i <= num/2; i++) {
        if (i * i == num)
            return true;
    }
}
