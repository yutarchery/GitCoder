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

ll n, l[int(5e5 + 5)], r[int(5e5 + 5)];
ll cnt = 0;

int main() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  sort(l + 1, l + n + 1);
  sort(r + 1, r + n + 1);

  int i = 1, j = 1;
  while (i <= n && j <= n) {
    if (r[j] < l[i]) {
      cnt += n - (i - 1);
      j++;
    } else {
      i++;
    }
  }

  cout << n * (n - 1) / 2 - cnt << endl;

  return 0;
}
