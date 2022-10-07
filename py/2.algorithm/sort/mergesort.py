from typing import List


def _merge_sort(nums: List[float], nums_tmp: List[float], start: int, end: int) -> None:
    if start >= end:
        return

    mid = start + (end - start) // 2
    start1, end1 = start, mid
    start2, end2 = mid + 1, end
    # 分组排序
    _merge_sort(nums, nums_tmp, start1, end1)
    _merge_sort(nums, nums_tmp, start2, end2)

    # 合并排序
    ii = start  # 已排序数组(nums_tmp)当前位置

    # 把区间左右两边数组合并到已排序数组ans中
    while start1 <= end1 and start2 <= end2:
        if nums[start1] > nums[start2]:
            nums_tmp[ii] = nums[start2]
            start2 += 1
        else:
            nums_tmp[ii] = nums[start1]
            start1 += 1
        ii += 1

    # 把左边（或右边）剩余元素追加到nums_tmp：
    while start1 <= end1:
        nums_tmp[ii] = nums[start1]
        start1 += 1
        ii += 1
    while start2 <= end2:
        nums_tmp[ii] = nums[start2]
        start2 += 1
        ii += 1

    nums[start: end + 1] = nums_tmp[start: end + 1]  # 将排序数组复制到nums中
    return


# 递归方法实现
def merge_sort(nums: List[float]) -> None:
    """归并排序：O(n*logn), 最好：O(n*logn); 最坏：O(n*logn)"""
    n = len(nums)
    if n < 2:
        return
    nums_tmp = nums[:]
    _merge_sort(nums, nums_tmp, 0, n - 1)
    return


# 循环方法实现
def merge_sort2(nums: List[float]) -> None:
    n = len(nums)
    if n < 2:
        return

    nums_point = nums  # 指向nums的数组
    nums_tmp = nums[:]  # 存放已排序数据
    iseg = 1  # 区间分段长度计数器：1，2，4，8，16……

    # 排序趟数的循环
    while iseg < n:
        start = 0  # 区间起始位置计数器
        # 每趟排序选取区间的循环
        while start < n:
            ilow = start
            imid = min(n, start + iseg)  # 考虑分段不均情况，不能越界
            imax = min(n, start + 2 * iseg)

            ii = ilow
            start1, end1 = ilow, imid
            start2, end2 = imid, imax

            # 把待排序左右两边元素合并到已排序数组
            while start1 < end1 and start2 < end2:
                if nums_point[start1] > nums_point[start2]:
                    nums_tmp[ii] = nums_point[start2]
                    start2 += 1
                else:
                    nums_tmp[ii] = nums_point[start1]
                    start1 += 1
                ii += 1

            # 把左边（或右边）剩余元素追加到nums_tmp：
            while start1 < end1:
                nums_tmp[ii] = nums_point[start1]
                start1 += 1
                ii += 1
            while start2 < end2:
                nums_tmp[ii] = nums_point[start2]
                start2 += 1
                ii += 1
            start += 2 * iseg
        # 交换指针，以便下一次排序
        nums_point, nums_tmp = nums_tmp, nums_point
        iseg *= 2
    if nums_point != nums:
        nums[:] = nums_point[:]
    return


if __name__ == "__main__":
    a = [8, 5, 5, 6, 4, 2, 5, 4, 1, 3, 4, 6, 9, 8, 7, 1, 2]
    # [1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9]
    # merge_sort(a)
    merge_sort2(a)
    print(a)
