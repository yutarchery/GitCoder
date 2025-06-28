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

int n, m, l[int(1e6 + 5)], r[int(1e6 + 5)];
int cnt[int(1e6 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];
    cnt[l[i]]++;
    cnt[r[i] + 1]--;
  }

  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
    ans = min(ans, cnt[i]);
  }
  cout << ans << endl;

  return 0;
}
