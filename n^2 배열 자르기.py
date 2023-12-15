# n 범위가 크니까 완탐x
# i행은 i개의 i가 있고 나머지 자리(n-i)를 i+1~n으로 채운다


def solution(n, left, right):
    answer = []
    for i in range(left, right + 1):
        row = (i // n) + 1  # 행 번호
        col = i % n + 1  # 열 번호
        if col < row:
            answer.append(row)
        else:
            answer.append(col)

    return answer