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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];

vector<Pii> p;

int solve(int num) {
  int l = 0, r = p.size() - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (p[mid].first <= num) {
      r = mid;
    } else {
      l = mid;
    }
  }

  return p[r].second;
}

int main() {
  cin >> n >> m;
  int now = 1e9;
  p.push_back({now, 0});
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (now > a[i]) {
      p.push_back({a[i], i});
      now = a[i];
    }
  }
  p.push_back({0, -1});

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    cout << solve(b[i]) << endl;
  }

  return 0;
}
