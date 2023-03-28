def dfs(picks, minerals, fatigue, m_idx, p_count, total):
    global count
    if m_idx >= len(minerals) or p_count == total:  # 광물을 다 캤다면 곡괭이 다씀
        count = min(count, fatigue)
        return
    for i in range(len(picks)):  # 곡괭이 종류만큼 반복을 한다.
        if picks[i] > 0:
            temp = 0
            a_sum = 0
            picks[i] -= 1
            for j in range(m_idx, m_idx+5):
                temp = j
                if j == len(minerals):
                    break
                if i == 0:
                    a_sum += 1
                elif i == 1:
                    if minerals[j] == "diamond":
                        a_sum += 5
                        continue
                    a_sum += 1
                else:
                    if minerals[j] == "diamond":
                        a_sum += 25
                    elif minerals[j] == "iron":
                        a_sum += 5
                    else:
                        a_sum += 1
            dfs(picks, minerals, fatigue+a_sum, temp+1, p_count+1, total)
            picks[i] += 1


def solution(picks, minerals):
    global count
    count = 100000
    total = sum(picks)
    dfs(picks, minerals, 0, 0, 0, total)
    return count
