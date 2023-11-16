# (는 스택에 넣고, )를 만나면 스택을 빼는데, 스택을 뺄때 (이 아니라면 에러다.

def solution(s):
    stack = []

    for c in s:
        if c == "(":
            stack.append(c)
        else:
            if len(stack) < 1:
                return False
            if stack.pop() != "(":
                return False
    return len(stack) == 0