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

int n, a[int(2e5 + 5)];
ll ans = 0;
map<int, ll> cnt;

void solve(int i) {
  for (int j = 1; j * j <= i; j++) {
    if (i % j != 0) {
      continue;
    }

    int k = i / j;

    if (j == k) {
      ans += cnt[i] * cnt[j] * cnt[k];
    } else {
      ans += cnt[i] * cnt[j] * cnt[k] * 2;
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a, a + n + 1);

  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      solve(a[i]);
    }
  }

  cout << ans << endl;

  return 0;
}