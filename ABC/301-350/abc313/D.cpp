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

int n, k, t[1005], a[1005];

int main() {
  cin >> n >> k;
  int sum = 0;
  for (int i = 1; i <= k + 1; i++) {
    cout << "?";
    for (int j = 1; j <= k + 1; j++) {
      if (i == j) {
        continue;
      }
      cout << " " << j;
    }
    cout << endl;

    cin >> t[i];
    sum += t[i];
  }

  for (int i = 1; i <= k + 1; i++) {
    if (t[i] % 2 == sum % 2) {
      a[i] = 0;
    } else {
      a[i] = 1;
    }
  }

  sum = 0;
  for (int i = 1; i <= k - 1; i++) {
    sum += a[i];
  }

  for (int i = k + 2; i <= n; i++) {
    cout << "?";
    for (int j = 1; j < k; j++) {
      cout << " " << j;
    }
    cout << " " << i << endl;

    cin >> t[i];
    if (sum % 2 == t[i]) {
      a[i] = 0;
    } else {
      a[i] = 1;
    }
  }

  cout << "!";
  for (int i = 1; i <= n; i++) {
    cout << " " << a[i];
  }
  cout << endl;

  return 0;
}
