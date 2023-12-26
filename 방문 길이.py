# 입력에 따라 좌표를 움직이는데 가능한 입력만 처리한다
# 움직일 때 x,y 좌표에서 어떤 방향으로 움직였는지 기록해서 리턴한다
# 방향으로만 처리하면 반대편에서 오는 것을 중복 처리 못하네

dxy = {'U': (0, 1), 'D': (0, -1), 'R': (1, 0), 'L': (-1, 0)}
d_reverse = {'U': 'D', 'D': 'U', 'R': 'L', 'L': 'R'}


def solution(dirs):
    pos = (0, 0)
    visited = {}
    for d in dirs:
        if -5 <= pos[0] + dxy[d][0] <= 5 and -5 <= pos[1] + dxy[d][1] <= 5:
            visited[pos] = visited.get(pos, set([]))
            visited[pos].add(d)
            pos = (pos[0] + dxy[d][0], pos[1] + dxy[d][1])
            visited[pos] = visited.get(pos, set([]))
            visited[pos].add(d_reverse[d])
    result = 0
    for value in visited.values():
        result += len(value)
    return result / 2