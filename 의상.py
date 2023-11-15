# 해시로 옷 종류별로 저장한다
# 각 종류별로 입기+안입기로 곱하고, 아무것도 안입는 경우 1을 뺀다


def solution(clothes):
    answer = 1
    d = {}
    for _, category in clothes:
        d[category] = d.get(category, 0) + 1

    for category in d:
        answer *= (d[category] + 1)

    return answer - 1

