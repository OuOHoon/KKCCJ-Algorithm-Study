# 노란 카펫이 갈색 카펫의 모양을 결정한다.
# 24를 기준으로 24x1, 12x2, 8x3, 6x4가 나온다
# 이중에서 brown 24개가 가능한 목록을 찾아보면 (width+height)*2+4(모서리)에 충족하는 width, height를 찾으면 된다.

def find_divisors(num):
    for i in range(1, int(num ** 0.5) + 1):
        if num % i == 0:
            yield num // i, i
def solution(brown, yellow):
    for width, height in find_divisors(yellow):
        if (width + height) * 2 + 4 == brown:
            return [width + 2, height + 2]

    return []


if __name__ == '__main__':
    print(solution(10, 2))
    print(solution(8, 1))
    print(solution(24, 24))
