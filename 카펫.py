# 노란 카펫이 갈색 카펫의 모양을 결정한다.
# 24를 기준으로 24x1, 12x2, 8x3, 6x4가 나온다
# 이중에서 brown 24개가 가능한 목록을 찾아보면 (width+height)*2+4(모서리)에 충족하는 width, height를 찾으면 된다.

def find_tuples(num):
    if num < 4:
        return [(num, 1)]
    s = {(num, 1)}
    for i in range(2, int(num / 2) + 1):
        if num % i == 0:
            s.add((num // i, i))
    return s


def solution(brown, yellow):
    answer = []
    tuples = find_tuples(yellow)
    for tp in tuples:
        width, height = tp
        if (width+height)*2+4 == brown:
            if width < height:
                return [height+2, width+2]
            else:
                return [width+2, height+2]

    return answer


if __name__ == '__main__':
    print(solution(10, 2))
    print(solution(8, 1))
    print(solution(24, 24))
