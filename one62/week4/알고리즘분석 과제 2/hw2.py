def hw2(n):
	if n==0: return 1
	t = 0
	for i in range(0, n):
		t = t + hw2(i)*hw2(n-i-1)
	return t

def memoize(f):
	memo = {}
	def helper(x):
		if x not in memo:
			memo[x] = f(x)
		return memo[x]
	return helper
def hw2td(n):
	if n==0: return 1
	t = 0
	for i in range(0, n):
		t = t + hw2td(i)*hw2td(n-i-1)
	return t
hw2td=memoize(hw2td)

def hw2bu(n):
	memo = {}
	memo[0] = 1
	for i in range(1, n + 1):
		t = 0
		for j in range(0, i):
			t = t + memo[j]*memo[i - j - 1]
		memo[i] = t
	return memo[n]

n = 23
print(hw2td(n))
print(hw2bu(n))
print(hw2(n))
