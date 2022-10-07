from typing import List


def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1  # left = 2*i + 1
    r = 2 * i + 2  # right = 2*i + 2

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # 交换
        heapify(arr, n, largest)


def heap_sort(nums: List[float]):
    """堆排序：O(nlogn), 最好：O(nlogn); 最坏：O(nlogn)"""
    n = len(nums)

    # 建立大顶堆
    for i in range((n - 1) // 2, -1, -1):
        heapify(nums, n, i)

    # 逐个交换元素
    for i in range(n - 1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        heapify(nums, i, 0)

    return


if __name__ == "__main__":
    # a = [5, 7, 6, 8]
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    # [1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9]
    heap_sort(a)
    print(a)
