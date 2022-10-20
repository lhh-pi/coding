from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans, res = [], []

        def backtracking(nums, k):
            nonlocal ans, res
            if k == 0:
                ans.append(res)
                print(res, ans)
                return
            for i in range(len(nums) - k + 1):
                data = nums[i]
                res.append(data)
                nums.pop(i)
                backtracking(nums[i:], k - 1)
                # 回溯
                res.pop()
                nums.insert(i, data)

        nums = [x for x in range(1, n + 1)]
        backtracking(nums, k)
        return ans


if __name__ == "__main__":
    s = Solution()
    ans = s.combine(4, 2)
    print(ans)
