# 최솟값이니까 bfs로 풀자 시작점, 도착점 고정..

def solution(maps):
    answer = 1
    n, m = len(maps), len(maps[0])
    visited = [[False for i in range(m)] for i in range(n)]
    q = [(0, 0)]
    d = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    c = 1
    while q:
        nc = 0
        for i in range(c):
            y, x = q.pop(0)
            if y == n - 1 and x == m - 1:
                return answer
            for direction in d:
                ty, tx = direction
                ny, nx = y + ty, x + tx
                if 0 <= ny < n and 0 <= nx < m and not visited[ny][nx] and maps[ny][nx] == 1:
                    q.append((ny, nx))
                    visited[ny][nx] = True
                    nc += 1
        c = nc
        answer += 1

    return -1