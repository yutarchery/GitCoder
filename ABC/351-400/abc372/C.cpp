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

int n, q, x, ans = 0;
char s[int(2e5 + 10)], c;

bool check(int idx) {
  for (int i = idx - 2; i <= idx; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n >> q;
  for (int i = 2; i <= n + 1; i++) {
    cin >> s[i];
  }
  for (int i = 2; i <= n + 1; i++) {
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
      ans++;
    }
  }

  for (int i = 1; i <= q; i++) {
    cin >> x >> c;
    x++;
    if (check(x)) {
      ans--;
    }
    s[x] = c;
    if (check(x)) {
      ans++;
    }

    cout << ans << endl;
  }

  return 0;
}