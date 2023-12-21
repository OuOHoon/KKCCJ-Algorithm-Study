# k의 꺾은선 그래프를 만든다
# 시작점과 끝점이 유효한지 확인한다
# 시작점과 끝점 구간의 정적분을 구한다

def setIntegral(graph):
    result = []

    for i in range(len(graph) - 1):
        result.append((graph[i] + graph[i + 1]) / 2)

    return result


def solution(k, ranges):
    answer = []
    graph = []

    while k > 1:
        graph.append(k)
        k = k * 3 + 1 if k % 2 else k / 2
    graph.append(1.0)

    integral = setIntegral(graph)

    for r in ranges:
        a, b = r
        n = len(graph) - 1
        if a > n + b:
            answer.append(-1.0)
            continue
        else:
            b = n + b

        if a == b:
            answer.append(0.0)
        else:
            answer.append(sum(integral[a:b]))

    return answer