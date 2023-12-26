# 과제 시작 시간 순으로 정렬한다
# 과제 목록을 순회하는데, 과제의 시작 시간 + 소요 시간이 다음 과제의 시작 시간보다 크다면 현재 과제의 이름과 소요 시간을 스택에 넣고 다음 과제로 넘어간다
# 다음 과제의 시작 시간보다 작다면 배열에 이름을 담고 스택에 과제가 있다면 과제를 꺼내고 다음 과제 시작 시간까지 진행한다.

def to_end_time(start, playtime):
    hour, minute = map(int, start.split(':'))
    return hour * 60 + minute + int(playtime)


def to_time(start):
    hour, minute = map(int, start.split(':'))
    return hour * 60 + minute


def solution(plans):
    answer = []
    plans.sort(key=lambda x: x[1])
    stack = []
    current_hour, current_min = map(int, plans[0][1].split(':'))
    current_time = current_hour * 60 + current_min
    for i, plan in enumerate(plans[:-1]):
        name, start, playtime = plan
        end_time = to_end_time(start, playtime)
        next_name, next_start, next_playtime = plans[i + 1]
        next_time = to_time(next_start)
        if end_time > next_time:
            stack.append((name, int(playtime) - (next_time - to_time(start))))
            current_time = next_time
        elif end_time == next_time:
            answer.append(name)
            current_time = end_time
        elif end_time < next_time:
            answer.append(name)
            current_time = end_time
            while current_time < next_time:
                if len(stack) == 0:
                    current_time = next_time
                    break
                last_name, last_time = stack.pop()
                if current_time + last_time <= next_time:
                    current_time = current_time + last_time
                    answer.append(last_name)
                elif current_time + last_time > next_time:
                    current_time = next_time
                    stack.append((last_name, last_time - (next_time - current_time)))
    answer.append(plans[-1][0])
    while len(stack) > 0:
        answer.append(stack.pop()[0])

    return answer

solution([["science", "12:40", "50"], ["music", "12:20", "40"], ["history", "14:00", "30"], ["computer", "12:30", "100"]])