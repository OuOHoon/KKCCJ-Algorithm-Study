# 모든 가능한 접두어를 해시테이블에 저장하고 비교하면 n*m. 범위가 작아서 가능

def solution(phone_book):
    d = {phone[:i]: True for phone in phone_book for i in range(1, len(phone))}
    for phone in phone_book:
        if d.get(phone, False):
            return False
    return True
