from typing import List


def _radix_sort(nums: List[int], iexp: int, n: int):
    buckets = [0] * 10
    result = [0] * n
    for i in range(n):
        m = int(nums[i] // iexp % 10)  # iexp位处的值
        buckets[m] += 1
    for i in range(1, 10):
        buckets[i] += buckets[i - 1]  # 每个位置的索引上限
    for i in range(n-1, -1, -1):
        m = int(nums[i] // iexp % 10)
        buckets[m] -= 1
        result[buckets[m]] = nums[i]
    nums[:] = result[:]
    return


def radix_sort(nums: List[int]):
    """基数排序：O(n*k), 最好：O(n*k); 最坏：O(n*2)"""
    n = len(nums)
    if n < 2:
        return
    max_num = max(nums)
    iexp = 1
    while max_num // iexp > 0:
        _radix_sort(nums, iexp, n)
        iexp *= 10

    return


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    # [1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9]
    radix_sort(a)
    print(a)
