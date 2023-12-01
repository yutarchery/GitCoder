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

int n, m, a[int(2e5 + 5)], cnt[int(2e5 + 5)];
Pii ans = {0, 0};

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++) {
    cnt[a[i]]++;

    if (ans.first < cnt[a[i]]) {
      ans = {cnt[a[i]], a[i]};
    } else if (ans.first == cnt[a[i]]) {
      ans = {ans.first, min(ans.second, a[i])};
    }

    cout << ans.second << endl;
  }

  return 0;
}