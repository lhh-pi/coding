from typing import List


def shell_sort(nums: List[float]) -> List[float]:
    """希尔排序：O(n(logn)^2), 最好：O(n(logn)^2); 最坏：O(n(logn)^2)"""
    n = len(nums)
    gap = n // 2
    while gap > 0:
        for i in range(n):
            t = nums[i]  # 待插入数据
            j = i - gap
            while j >= 0 and t < nums[j]:
                nums[j + gap] = nums[j]
                j -= gap
            nums[j + gap] = t
        gap = gap // 2
    return nums


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    a = shell_sort(a)
    print(a)
