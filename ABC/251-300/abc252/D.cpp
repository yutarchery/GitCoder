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

ll n;
int a[int(2e5 + 5)];
map<int, ll> cnt;

ll conbi_sum = 0;
ll conbi[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a, a + n + 1);

  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      continue;
    }
    conbi_sum += cnt[a[i]] * (n - cnt[a[i]]);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) {
      continue;
    }

    ans += cnt[a[i]] * (conbi_sum - cnt[a[i]] * (n - cnt[a[i]]) * 2);
  }

  cout << ans / 6 << endl;

  return 0;
}