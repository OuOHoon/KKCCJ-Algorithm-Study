# h의 최댓값을 구해야함
# h 값의 범위는 0~1000
# 배열을 정렬하고 0부터 1000까지 조회하면서 가장 큰 h를 찾자
# 6 6 5 5 3 1 0 -> 4
def solution(citations):
    answer = 0
    citations.sort(reverse=True)
    for i, citation in enumerate(citations): # n^2
        for h in range(1001):
            if citation >= h and i+1 >= h:
                answer = max(answer, h)
    return answer

def solution2(citations):
    citations.sort(reverse=True)
    h = 0
    for citation in citations: # n
        if citation > h:
            h += 1
    return h

print(solution([3, 0, 6, 1, 5]))