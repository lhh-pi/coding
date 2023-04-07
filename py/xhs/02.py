

if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()[:n]))
    m = int(input())
    left_list = list(map(int, input().split()[:m]))
    right_list = list(map(int, input().split()[:m]))
    # op_list = input().split()[:m]
    op_s = input()
    op_list = [ch for ch in op_s]
    X_list = list(map(int, input().split()[:m]))

    for i in range(m):
        left, right = left_list[i], right_list[i]
        op = op_list[i]
        x = X_list[i]
        for j in range(left - 1, right):
            if op == '|':
                nums[j] |= x
            elif op == '&':
                nums[j] &= x
            else:
                nums[j] = x
    res = ""
    for num in nums:
        res += str(num) + " "
    print(res)
