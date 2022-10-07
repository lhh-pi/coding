from typing import List


def count_sort(nums: List[int]):
    """基数排序：O(n+k), 最好：O(n+k); 最坏：O(n+k)"""
    max_num, min_num = max(nums), min(nums)
    n, k = len(nums), max_num - min_num + 1
    cnt = [0] * k
    for i in range(n):
        cnt[nums[i] - min_num] += 1
    j = 0
    for i in range(k):
        while cnt[i]:
            nums[j] = i + min_num
            j += 1
            cnt[i] -= 1

    return


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    # [1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9]
    count_sort(a)
    print(a)
