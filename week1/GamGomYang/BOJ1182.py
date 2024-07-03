def Solution(arr, n, s):
    def dfs(idx, current_sum):
        nonlocal count
        if idx == n:  
            return
        current_sum += arr[idx] 
        if current_sum == s:
            count += 1
        dfs(idx + 1, current_sum) 
        dfs(idx + 1, current_sum - arr[idx])  

    count = 0
    dfs(0, 0)
    return count


n, s = map(int, input().split())
arr = list(map(int, input().split()))


print(Solution(arr, n, s))
