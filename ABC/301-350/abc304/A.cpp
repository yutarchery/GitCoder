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

int n, a[105], m = 1e9 + 5, idx = 0;
string s[205];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> a[i];
    s[i + n] = s[i];
    if (a[i] < m) {
      m = a[i];
      idx = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << s[idx + i - 1] << endl;
  }

  return 0;
}
