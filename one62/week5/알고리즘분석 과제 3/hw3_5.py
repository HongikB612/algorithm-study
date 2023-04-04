import sys
input = sys.stdin.readline
arr = list(map(float, input().split()))
n = len(arr)
def p(i, j):
	tmp = 0
	for k in range(i, j + 1):
		tmp += arr[k - 1]
	return tmp
opt = [[float('inf') for j in range(n + 2)] for i in range(n + 2)]
kk = [[float('inf') for j in range(n + 2)] for i in range(n + 2)]
def Opt(i, j):
	if opt[i][j] != float('inf'):
		return opt[i][j]
	if i > j:
		opt[i][j] = 0
		return opt[i][j]
	tmp = float('inf')
	for k in range(i, j + 1):
		tmp = 1 + Opt(i, k - 1)*p(i, k - 1)/p(i,j) + Opt(k + 1, j)*p(k + 1, j)/p(i,j)
		if tmp < opt[i][j]:
			opt[i][j] = tmp
			kk[i][j] = k
	return opt[i][j]
for i in range(1, n + 1):
	for j in range(1, n + 1):
		Opt(i,j)
def pr(p):
	for i in range(1, n + 1):
		for j in range(1, i):
			print(end='\t')
		for j in range(i, n + 1):
			print(round(p[i][j], 2), end='\t')
		print()
	return
print("table of opt[i,j]")
pr(opt)
print("table of k[i,j]")
pr(kk)
def tree(s,e):
	parent = kk[s][e]
	print("parent:", parent, end=' ')
	if parent != s:
		left = kk[s][parent - 1]
		print("left:", left, end=' ')
	if parent != e:
		right = kk[parent + 1][e]
		print("right:", right, end = ' ')
	print()
	if parent != s:
		tree(s, parent - 1)
	if parent != e:
		tree(parent + 1, e)
	return parent
print("root:", end=' ')
tree(1,n)