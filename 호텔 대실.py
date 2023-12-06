# 하루를 1440분으로 나누고 누적합으로 시간 표시하고 가장 합이 높은 부분을 찾으면 그게 정답

def to_min(time):
    hour, minute = map(int, time.split(':'))
    return hour * 60 + minute

def solution(book_time):
    answer = 1
    timeline = [0 for i in range(1450)]
    for t in book_time:
        start_time, end_time = t
        timeline[to_min(start_time)] += 1
        timeline[to_min(end_time) + 10] -= 1
    for i in range(1, len(timeline)):
        timeline[i] = timeline[i-1] + timeline[i]
    answer = max(timeline)
    return answer