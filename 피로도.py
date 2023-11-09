import itertools
def solution(k, dungeons):
    answer = -1

    for permutation in itertools.permutations(dungeons):
        temp_k = k
        temp_answer = 0
        for dungeon in permutation:
            if temp_k >= dungeon[0]:
                temp_k -= dungeon[1]
                temp_answer += 1
            else:
                break
        answer = max(temp_answer, answer)
    return answer

print(solution(80, [[80,20],[50,40],[30,10]]))