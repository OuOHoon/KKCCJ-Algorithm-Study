# 숫자가 몇번 등장했는지 세서 가장 많이 등장하는 순으로 정렬하면 그게 튜플

from collections import defaultdict

def solution(s):
    d = defaultdict(int)
    temp = ''
    for c in s:
        if c in [',', '}']:
            if temp == '':
                continue
            d[temp] += 1
            temp = ''
        elif c == '{':
            pass
        else:
            temp += c
    answer = [int(key) for key, value in sorted(d.items(), key=lambda x: -x[1])]
    return answer