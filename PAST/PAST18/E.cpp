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

int n, c[10];
vector<int> a[10];
int ans = 0;

int cnt = 0, now[105];

void solve(int num) {
  cnt = 0;
  fill(now, now + 101, 0);
  for (int i = 0; i < n; i++) {
    if (num % 2 == 1) {
      cnt++;
      for (int j : a[i]) {
        now[j]++;
      }
    }
    num /= 2;
  }

  if (cnt <= 1) {
    return;
  }
  for (int i = 1; i <= 100; i++) {
    if (now[i] == cnt) {
      if (i % 2 == 0) {
        return;
      }
    }
  }

  ans++;
  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    a[i].resize(c[i]);
    for (int j = 0; j < c[i]; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}
