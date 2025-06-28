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

int n;
char s[int(2e5 + 5)];

int cnt0[int(2e5 + 5)], cnt1[int(2e5 + 5)], a[int(2e5 + 5)];

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == '0') {
      cnt0[i]++;
    } else {
      cnt1[i]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cnt0[i] += cnt0[i - 1];
    cnt1[i] += cnt1[i - 1];
    a[i] = cnt1[i] - cnt0[i];
  }

  int ans = 1e9, m = 0;
  for (int i = 1; i <= n; i++) {
    m = min(m, a[i]);
    ans = min(ans, cnt1[n] - (a[i] - m));
  }

  return ans;
}

void reset() {
  fill(cnt0, cnt0 + n + 1, 0);
  fill(cnt1, cnt1 + n + 1, 0);
  fill(a, a + n + 1, 0);

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
    reset();
  }

  return 0;
}
