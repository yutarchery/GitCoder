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

int n, m, par[int(2e5 + 5)];
ll ans, cnt[int(2e5 + 5)];

int find_parent(int a) {
  if (par[a] == a) {
    return par[a] = a;
  }
  int p = par[a];
  return par[a] = find_parent(p);
}

void unite(int a, int b) {
  int pa = find_parent(a), pb = find_parent(b);

  par[max(pa, pb)] = min(pa, pb);
  par[a] = min(pa, pb);
  par[b] = min(pa, pb);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    unite(a, b);
  }
  for (int i = 1; i <= n; i++) {
    cnt[find_parent(i)]++;
  }

  for (int i = 1; i <= n; i++) {
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  ans -= m;
  cout << ans << endl;

  return 0;
}
