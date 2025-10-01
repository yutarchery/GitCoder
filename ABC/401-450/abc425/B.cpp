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

int n, a[15];
int cnt[15], p[15];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] != -1) {
      cnt[a[i]]++;
      p[i] = a[i];
    }
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[i] >= 2) {
      No();
      return 0;
    }
  }

  Yes();
  int now = 1;
  for (int i = 1; i <= n; i++) {
    while (cnt[now] > 0) {
      now++;
    }

    if (p[i] == 0) {
      p[i] = now;
      now++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << p[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
