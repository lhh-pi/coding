from bubblesort import bubble_sort
from bucketsort import bucket_sort
from countsort import count_sort
from heapsort import heap_sort
from insertsort import insert_sort
from mergesort import merge_sort, merge_sort2
from quicksort import quick_sort
from radixsort import radix_sort
from selectsort import select_sort, select_sort2
from shellsort import shell_sort

if __name__ == "__main__":
    import random
    import time

    times = 5
    sorts = [bubble_sort, bucket_sort, count_sort,
             heap_sort, insert_sort, merge_sort,
             merge_sort2, quick_sort, radix_sort,
             select_sort, select_sort2, shell_sort]


    def test(sort, nums):
        from collections import Counter
        cnt1 = Counter(nums)
        t1 = time.time()
        sort(nums)
        t2 = time.time()
        cnt2 = Counter(nums)
        if cnt1 - cnt2:
            print("Wrong data! sort:", sort.__name__)
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                print("Wrong sorting! sort:", sort.__name__)
                break
        print(sort.__name__, "time spent: ", t2 - t1)


    for i in range(times):
        print("**********test%d************" % (i + 1))
        for sort in sorts:
            data = [random.randint(0, 2500) for _ in range(10000)]
            test(sort, data)
