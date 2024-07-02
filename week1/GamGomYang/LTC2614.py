from typing import List

class Solution:
    def prime_machine(self, num: int) -> bool:
        if num <= 1:
            return False
        if num <= 3:
            return True
        if num % 2 == 0 or num % 3 == 0:
            return False
        i = 5
        while i * i <= num:
            if num % i == 0 or num % (i + 2) == 0:
                return False
            i += 6
        return True

    def diagonalPrime(self, nums: List[List[int]]) -> int:
        n = len(nums)
        diagonals = set()

        for i in range(n):
            diagonals.add(nums[i][i])           
            diagonals.add(nums[i][n - i - 1])   

        prime_numbers = [num for num in diagonals if self.prime_machine(num)]
        return max(prime_numbers) if prime_numbers else 0

solution = Solution()
print(solution.diagonalPrime([[1, 2, 3], [5, 6, 7], [9, 10, 11]]))  
print(solution.diagonalPrime([[1, 2, 3], [5, 17, 7], [9, 11, 10]]))  
