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

int n, t, p, l[105], sum[105];

int main() {
  cin >> n >> t >> p;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
    sum[max(0, t - l[i])]++;
  }
  for (int i = 1; i <= 100; i++) {
    sum[i] += sum[i - 1];
  }

  for (int i = 0; i <= 100; i++) {
    if (sum[i] >= p) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
