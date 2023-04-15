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

ll n, k, a[int(1e5 + 5)], b[int(1e5 + 5)], ans[int(1e5 + 5)];
ll sum = 0, cnt = 0;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n + 1);

  for (int i = 1; i <= n; i++) {
    if (sum + (b[i] - b[i - 1]) * (n - i + 1) > k) {
      cnt += (k - sum) / (n - i + 1);
      sum += ((k - sum) / (n - i + 1)) * (n - i + 1);

      break;
    }

    sum += (b[i] - b[i - 1]) * (n - i + 1);
    cnt += (b[i] - b[i - 1]);
  }

  ll rest = k - sum;
  for (int i = 1; i <= n; i++) {
    ans[i] = max(a[i] - cnt, ll(0));
    if (ans[i] > 0 && rest > 0) {
      ans[i]--;
      rest--;
    }

    cout << ans[i];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}