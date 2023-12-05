# a에서 가장 작은 수 순서대로, b에서 가장 큰 수 순서대로 곱하면 그게 과연 최소일까?

def solution(A,B):
    answer = 0
    A.sort()
    B.sort(reverse=True)
    for i in range(len(A)):
        answer += A[i]*B[i]
    return answer