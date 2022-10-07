from typing import List
from heapsort import heap_sort


def bucket_sort(nums: List[float], k: int = 5):
    """桶排序排序：O(n+k), 最好：O(n+k); 最坏：O(n^2)"""
    n, k = len(nums), k
    min_num, max_num = 0, 0
    for i in range(n):
        if nums[i] > max_num:
            max_num = nums[i]
        if nums[i] < min_num:
            min_num = nums[i]
    gap = (int(max_num + 1) - int(min_num - 1)) / k  # 桶区间
    buckets = [[] for _ in range(k)]  # 初始化桶
    for i in range(n):  # 数据放入桶中
        m = int((nums[i] - min_num) // gap)
        buckets[m].append(nums[i])
    for i in range(k):
        heap_sort(buckets[i])
    i = 0
    for bucket in buckets:
        for x in bucket:
            nums[i] = x
            i += 1
    return


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    # [1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9]
    bucket_sort(a)
    print(a)
