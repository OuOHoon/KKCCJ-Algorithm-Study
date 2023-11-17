# n-1개의 원판들을 임시 기둥으로 옮기고
# 가장 큰 원판을 목표 기둥으로 옮긴 후에
# 임시 기둥의 원판들을 목표 기둥으로 옮기자

answer = []

def hanoi(n, from_, to):
    global answer
    if n == 1:
        answer.append([from_, to])
        return None
    for i in range(1, 4):
        if i not in [from_, to]:
            temp = i
    hanoi(n-1, from_, temp)
    answer.append([from_, to])
    hanoi(n-1, temp, to)

def solution(n):
    hanoi(n, 1, 3)
    return answer