import string


def oral(S: string) -> string:
    s1 = ""
    for ch in S:
        ord_ch = (ord(ch) - ord('a') + 26 - 3) % 26 + ord('a')
        s1 += chr(ord_ch)
    return s1


if __name__ == "__main__":
    n = int(input())
    s = input()[:n]
    print(oral(s))
