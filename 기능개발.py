# 작업 목록이 빌 때 까지 반복하는데
# 가장 앞에 있는 작업이 며칠 걸리는지 세고, 그만큼 진도율을 더해준다.
# 진도율이 100을 넘으면 카운트하고 다음 작업 목록으로 간다
# 안넘으면 그 앞까지 작업 목록을 뺀다. 이걸 반복한다.
import math
def solution(progresses, speeds):
    answer = []
    while len(progresses) > 0:
        day = math.ceil((100 - progresses[0]) / speeds[0])
        for i in range(len(progresses)):
            progresses[i] += speeds[i] * day
        cnt = 1
        for i in range(1, len(progresses)):
            if progresses[i] >= 100:
                cnt += 1
            else:
                break
        progresses = progresses[cnt:]
        speeds = speeds[cnt:]
        answer.append(cnt)

    return answer


print(solution([93, 30, 55], [1, 30, 5]))
print(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]))
