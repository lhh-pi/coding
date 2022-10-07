from typing import List


def get_next(s: str) -> List[int]:
    nxt = [-1]
    j = -1
    for i in range(1, len(s)):
        while j >= 0 and s[i] != s[j + 1]:
            j = nxt[j]
        if s[i] == s[j + 1]:
            j += 1
        nxt.append(j)
    return nxt



if __name__ == '__main__':
    s = "abcacbabcabcabcabcabc"
    print(get_next(s))
