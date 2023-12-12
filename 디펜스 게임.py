# k가 enemy 길이 이상이라면 무조건 다 막음
# enemy 길이가 100만.. k를 enemy의 어디에 놓을지가 중요하다
# enemy를 하나씩 처리하는데, 막히는 순간 지금 위치를 포함해서 가장 컸던 곳을 k로 처리하고 병사를 복구하면 ..? 방문했던 곳들의 크기는 maxheap으로 저장..?

from heapq import heappush, heappop

def solution(n, k, enemy):
    answer = 0
    heap = []
    for value in enemy:
        heappush(heap, (-value, value))
        n -= value
        if n < 0 and k > 0: # 지금까지 막았던 것들 중에서 가장 컸던 곳을 k로 처리
            n += heappop(heap)[1]
            k -= 1

        if n >= 0: # 그랬을 때 n이 0 이상이면 다음으로
            answer += 1
        else:
            break

    return answer