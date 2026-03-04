#include <cstdio>
#include <cmath>

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define inc( i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec( i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

typedef long long   signed int LL;
typedef long long unsigned int LU;

template<typename T> void swap(T &x, T &y) { T t = x; x = y; y = t; return; }
template<typename T> T abs(T x) { return (0 <= x ? x : -x); }
template<typename T> T max(T a, T b) { return (b <= a ? a : b); }
template<typename T> T min(T a, T b) { return (a <= b ? a : b); }
template<typename T> bool setmin(T &a, T b) { if(a <= b) { return false; } else { a = b; return true; } }
template<typename T> bool setmax(T &a, T b) { if(b <= a) { return false; } else { a = b; return true; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

int h, w, a[200][600];
int dp[400][200][200];

int main() {
	scanf("%d%d", &h, &w);
	inc(i, h) { 
	inc(j, w) {
		scanf("%d", &a[i][j + 200]);
	}
	}
	
	dp[0][0][0] = a[0][0 + 200];
	inc(i, h + w - 1 - 1) {
		inc(j, h) {
		inc(k, h) {
			int jj[4] = { 0, 0, 1, 1 };
			int kk[4] = { 0, 1, 0, 1 };
			inc(l, 4) {
				int jjj = j + jj[l];
				int kkk = k + kk[l];
				if(0 <= jjj && jjj < h && 0 <= kkk && kkk < h) {
					setmax(dp[i + 1][jjj][kkk], dp[i][j][k] + a[jjj][i+1 - jjj + 200] + (jjj == kkk ? 0 : a[kkk][i+1 - kkk + 200]));
				}
			}
		}
		}
	}
	
	printf("%d\n", dp[h + w - 2][h - 1][h - 1]);
	
	return 0;
}
