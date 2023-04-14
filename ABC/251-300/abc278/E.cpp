#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int H, W, N, h, w;
int a[305][305];
int cnt[305][305][305];
int ans[305][305];

int main() {
  cin >> H >> W >> N >> h >> w;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> a[i][j];
      for (int k = 1; k <= N; k++) {
        cnt[i][j][k] =
            cnt[i - 1][j][k] + cnt[i][j - 1][k] - cnt[i - 1][j - 1][k];
      }
      cnt[i][j][a[i][j]]++;
    }
  }

  for (int i = 1; i <= H - h + 1; i++) {
    for (int j = 1; j <= W - w + 1; j++) {
      for (int k = 1; k <= N; k++) {
        if (cnt[H][W][k] >
            cnt[i + h - 1][j + w - 1][k] - cnt[i - 1][j + w - 1][k] -
                cnt[i + h - 1][j - 1][k] + cnt[i - 1][j - 1][k]) {
          ans[i][j]++;
        }
      }
    }
  }

  for (int i = 1; i <= H - h + 1; i++) {
    for (int j = 1; j <= W - w + 1; j++) {
      cout << ans[i][j];
      if (j == W - w + 1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  return 0;
}