# 1. 악보 정보를 음악 재생 시간만큼 자르거나 늘린다
# 2. 멜로디와 악보 정보를 비교하는데, C# 같은 것 때문에 비교가 불편하니 다른 문자 1개 문자로 치환해서 비교한다
# 3. 조건이 일치하는 음악이 여러 개일 수 있으니 재생 시간이 가장 긴 음악 순서로 정렬한다. 먼저 입력된 음악이 앞에 와야하니 stable 정렬이 필요하다.
change = {'C':'A',
          'C#':'B',
          'D':'C',
          'D#':'D',
          'E':'E',
          'E#':'O',
          'F':'F',
          'F#':'G',
          'G':'H',
          'G#':'I',
          'A':'J',
          'A#':'K',
          'B':'L'}
def changer(s):
    new_s = ''
    i = 0
    while i < len(s):
        if s[i+1:i+2] == '#':
            new_s += change[s[i:i+2]]
            i += 2
        else:
            new_s += change[s[i]]
            i += 1
    return new_s

def solution(m, musicinfos):
    answer = ''
    new_musicinfos = []
    for info in musicinfos:
        start, end, title, music = info.split(',')
        music = changer(music)
        s_h, s_m = start.split(':')
        s_time = int(s_h) * 60 + int(s_m)
        e_h, e_m = end.split(':')
        e_time = int(e_h) * 60 + int(e_m)
        total_time = e_time - s_time
        if total_time <= len(music):
            music = music[:total_time]
        else:
            music = music * (total_time // len(music)) + music[:total_time % len(music)]
        new_musicinfos.append((total_time, title, music))
    m = changer(m)
    new_musicinfos.sort(key=lambda x: x[0], reverse=True)
    for info in new_musicinfos:
        total_time, title, music = info
        if m in music:
            return title
    return "(None)"

solution("ABCDEFG", ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"])
solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"])
solution("ABC", ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"])