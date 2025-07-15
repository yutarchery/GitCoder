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

ll n, m;
int a[int(1e5 + 5)], b[int(1e5 + 5)];

int group[int(1e5 + 5)];
ll cnt[int(1e5 + 5)], ans[int(1e5 + 5)];

int find_group(int u) {
  if (group[u] == u) {
    return u;
  }

  int gu = find_group(group[u]);
  return group[u] = gu;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    group[i] = i;
    cnt[i] = 1;
  }

  for (int i = m; i >= 1; i--) {
    ans[i] = ans[i + 1];

    int ga = find_group(a[i]), gb = find_group(b[i]);
    if (ga == gb) {
      continue;
    } else if (ga > gb) {
      swap(ga, gb);
    }

    ans[i] += cnt[ga] * cnt[gb];
    cnt[ga] += cnt[gb];
    group[a[i]] = ga;
    group[b[i]] = ga;
    group[gb] = ga;
  }

  for (int i = 1; i <= m; i++) {
    cout << n * (n - 1) / 2 - ans[i + 1] << endl;
  }

  return 0;
}
