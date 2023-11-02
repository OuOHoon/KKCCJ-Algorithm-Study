import itertools
import math

def is_prime(number):
    if number < 2:
        return False
    for i in range(2, int(math.sqrt(number)) + 1):
        if number % i == 0:
            return False
    return True
def solution(numbers):
    unique_numbers = set([])
    for i in range(1, len(numbers) + 1):
        for comb in itertools.permutations(numbers, i):
            unique_numbers.add(int(''.join(comb)))

    result = 0
    for number in unique_numbers:
        if is_prime(number):
            result += 1
    return result


if __name__ == '__main__':
    print(solution("17"))
    print(solution("011"))
