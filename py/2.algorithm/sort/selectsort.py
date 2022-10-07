from typing import List


def select_sort(nums: List[float]):
    """选择排序：找到最小值，放到左边。平均时间复杂度：O(n^2)；最好O(n^2)：最坏：O(n^2)"""
    n = len(nums)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if nums[min_index] > nums[j]:
                min_index = j
        if min_index != i:
            nums[i], nums[min_index] = nums[min_index], nums[i]
    return


def select_sort2(nums: List[float]):
    """优化：同时记录最小最大值"""
    n = len(nums)
    left, right = 0, n - 1
    while left < right:
        min_index, max_index = left, left
        for i in range(left, right + 1):
            if nums[i] < nums[min_index]:
                min_index = i
            if nums[i] > nums[max_index]:
                max_index = i
        if min_index != left:  # 将最小值交换到最左边
            nums[left], nums[min_index] = nums[min_index], nums[left]
        if max_index == left:  # 若最大值在left上，则其在上一步已交换到min_index位置上了
            max_index = min_index
        if max_index != right:
            nums[right], nums[max_index] = nums[max_index], nums[right]

        left += 1
        right -= 1
    return


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    # [1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9]
    select_sort(a)
    # select_sort2(a)
    print(a)
