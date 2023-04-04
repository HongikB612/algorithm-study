import sys
input = sys.stdin.readline
arr = list(map(int, input().split()))
n = len(arr) - 1
opt = [[0] * n for _ in range(n)]
kk = [[0] * n for _ in range(n)]
for l in range(2, n+1):
    for i in range(n-l+1):
        j = i + l - 1
        opt[i][j] = float('inf')
        for k in range(i, j):
            cost = opt[i][k] + opt[k+1][j] + arr[i]*arr[k+1]*arr[j+1]
            if opt[i][j] > cost:
                opt[i][j] = cost
                kk[i][j] = k + 1
def pr(p):
    n = len(p)
    for i in range(0, n):
        for j in range(0, i):
            print(end='\t')
        for j in range(i, n):
            print(p[i][j], end='\t')
        print()
    return
print("table of opt[i,j]")
pr(opt)
print("table of k[i,j]")
pr(kk)
def pr2(k, i, j):
    if i == j:
        print(f'A{i+1}', end='')
    else:
        print('(', end='')
        pr2(k, i, k[i][j]-1)
        pr2(k, k[i][j], j)
        print(')', end='')
print("optimal chained matrix multiplication")
pr2(kk, 0, n-1)