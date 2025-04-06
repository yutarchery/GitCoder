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

int n, a[int(5e5 + 5)];
int now[int(5e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    now[i] += now[i - 1];
    a[i] += now[i];

    if (a[i] <= n - i) {
      now[i + 1]++;
      now[i + (a[i] + 1)]--;
      a[i] = 0;
    } else {
      a[i] -= (n - i);
      now[i + 1]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << (i != n ? ' ' : '\n');
  }

  return 0;
}
