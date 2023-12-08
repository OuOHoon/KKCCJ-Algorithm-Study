# 문제에 설명된 대로 하자

def hs(i, tp):
    return sum([value % i for value in tp])


def solution(data, col, row_begin, row_end):
    if len(data) == 1:
        return hs(1, data[0])
    data.sort(key=lambda x: [x[col - 1], -x[0]])
    answer = [hs(i, data[i - 1]) for i in range(row_begin, row_end + 1)]
    result = answer[0] ^ answer[1]
    for i in range(2, len(answer)):
        result = result ^ answer[i]
    return result


solution([[2, 2, 6], [1, 5, 10], [4, 2, 9], [3, 8, 3]], 2, 2, 3)
