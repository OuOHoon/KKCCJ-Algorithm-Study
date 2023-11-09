# 숫자의 앞 자리수가 큰 순서대로 정렬한다
# 문자를 여러번 반복해서 최소 4자릿수로 만들어서 비교한다
# 정렬한 배열의 원소들을 문자열로 만든다

def solution(numbers):
    l = sorted(map(str, numbers), key=lambda x: x*4, reverse=True)
    return str(int(''.join(l)))

solution([6, 10, 2])
solution([31, 312, 313, 318, 319])
