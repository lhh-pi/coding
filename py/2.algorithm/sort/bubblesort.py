from typing import List


def bubble_sort(nums: List[float]):
    """冒泡排序：O(n^2), 最好：O(n); 最坏：O(n^2)"""
    n = len(nums)
    is_swap = 1  # 优化，若无交换则说明已经排好，提前结束
    for i in range(n - 1, 0, -1):
        if is_swap == 0:
            break
        if_swap = 0
        for j in range(i):
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
                if_swap = 1
    return None


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    # a = bubble_sort(a)
    bubble_sort(a)
    print(a)
