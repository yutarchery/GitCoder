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

int h, w, a[20][20], ans;
map<int, int> cnt;

int solve(int i, int j) {
  if (i == h && j == w) {
    ans++;
    return 0;
  }

  if (i + 1 <= h && cnt[a[i + 1][j]] == 0) {
    cnt[a[i + 1][j]]++;
    solve(i + 1, j);
    cnt[a[i + 1][j]]--;
  }
  if (j + 1 <= w && cnt[a[i][j + 1]] == 0) {
    cnt[a[i][j + 1]]++;
    solve(i, j + 1);
    cnt[a[i][j + 1]]--;
  }
  return 0;
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }
  cnt[a[1][1]]++;
  solve(1, 1);
  cout << ans << endl;

  return 0;
}