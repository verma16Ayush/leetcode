class KF:
    def __init__(self):
        self.dp = [[-1 for i in range(1001)] for j in range(1001)]

    def knap(self, wt, val, w, n):
        if n == 0 or w == 0:
            return 0
        if self.dp[w][n] != -1:
            return self.dp[w][n]
        if w < wt[n-1]:
            self.dp[w][n] = self.knap(self, wt, val, w, n-1)
        else:
            self.dp[w][n] = max(val[n-1] + self.knap(wt, val, w-wt[n-1], n-1), self.knap(wt, val, w, n-1))


I = int(input())

wt = [int(i) for i in input().split(" ")]
val = [int(i) for i in input().split(" ")]
w = int(input())
n = len(wt)
print(KF().knap(wt, val, w, n))
