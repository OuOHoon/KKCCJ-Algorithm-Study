# priorities가 작으니까 완탐 가능
# 큐에서 하나씩 꺼내고, 지금게 제일 큰 값이면 answer + 1, 아니면 큐 뒤로 보낸다.
# location은 -1 하고 로케이션이 0일 때 제일 큰 값일때 해결

def solution(priorities, location):
    answer = 0

    while priorities:
        if len(priorities) == 1:
            return answer + 1

        t = priorities.pop(0)
        if t >= max(priorities):
            answer += 1
            if location == 0:
                break
        else:
            priorities.append(t)
            if location == 0:
                location = len(priorities)
        location -= 1

    return answer