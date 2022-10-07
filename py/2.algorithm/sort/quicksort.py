from typing import List


def _quick_sort(nums: List[float]) -> List[float]:
    n = len(nums)
    if n < 2:
        return nums
    left, right = 0, n - 1
    tem = nums[0]  # 中心轴
    moving_flag = 2  # 当前应该移动的下标：1-左下标；2-右下标
    while left < right:
        if moving_flag == 2:
            if nums[right] >= tem:
                right -= 1
            else:
                nums[left] = nums[right]  # right处小于中心轴，将其填入left
                left += 1
                moving_flag = 1
        elif moving_flag == 1:
            if nums[left] <= tem:
                left += 1
            else:
                nums[right] = nums[left]
                right -= 1
                moving_flag = 2
    nums[left] = tem  # 填入中心轴
    nums[:left] = _quick_sort(nums[:left])
    nums[left + 1:] = _quick_sort(nums[left + 1:])

    return nums


def quick_sort(nums: List[float]):
    """快速排序：O(n*logn), 最好：O(n*logn); 最坏：O(n^2)"""
    nums = _quick_sort(nums)
    """
        优化方法：1. 采用合理的中心轴，以减少递归深度，如从列表中取多个数的中间数；
                2. 结合插入排序，在n<10时使用插入排序效率更高
    """
    return


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    # [1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9]
    quick_sort(a)
    print(a)
