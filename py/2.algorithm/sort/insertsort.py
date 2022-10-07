from typing import List


def insert_sort(nums: List[float]):
    """插入排序：O(n^2), 最好：O(n); 最坏：O(n^2)"""
    n = len(nums)
    for i in range(1, n):
        t = nums[i]
        j = i - 1
        while j >= 0 and t < nums[j]:
            nums[j + 1] = nums[j]
            j -= 1
        nums[j + 1] = t
    """
    优化方法：1. 采用二分查找；
            2. 一次携带多个元素；
            3. 数据链表化；
            4. 希尔排序。         
    """
    return


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    insert_sort(a)
    print(a)
