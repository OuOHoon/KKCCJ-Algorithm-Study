# 입력값의 범위가 작으므로 완탐 가능하다
import itertools


def solution(orders, course):
    answer = []
    d = {}
    for order in orders:
        for c in course:
            if c > len(order):
                break

            for tp in itertools.combinations(order, c):
                tp = ''.join(sorted(tp))
                d[tp] = d.get(tp, 0)
                d[tp] += 1

    maxs = [0] * 11
    for key, value in d.items():
        maxs[len(key)] = max(maxs[len(key)], value)

    for key, value in d.items():
        if maxs[len(key)] == value and value >= 2:
            answer.append(''.join(key))
    answer.sort()

    return answer