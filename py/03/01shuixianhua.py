import sys


def is_shuixianhua(n: int) -> bool:
    n1, n2 = 0, n
    while n2:
        n1 += (n2 % 10) ** 3
        n2 = n2 // 10
    return n1 == n


if __name__ == "__main__":
    ans = []
    for line in sys.stdin:
        line = line[:-1]
        if not line:
            break
        row = []
        m, n = map(int, line.split())
        for i in range(m, n):
            if is_shuixianhua(i):
                row.append(i)
        if not row:
            row.append(-1)
        ans.append(row)

    for row in ans:
        s = ""
        for num in row:
            if num == -1:
                print("no")
            else:
                s += str(num) + " "
        if s:
            print(s)
