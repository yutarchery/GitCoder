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

int n, cnt;
char s[int(5e5 + 5)];
vector<int> v;

ll solve(int num) {
  ll sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += abs(v[i] - (num + i));
  }
  return sum;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == '1') {
      cnt++;
      v.push_back(i);
    }
  }

  int l = 1, r = n - (v.size() - 1);
  while (r - l > 2) {
    int mid_l = (l * 2 + r) / 3;
    int mid_r = (l + r * 2) / 3;

    ll cnt_l = solve(mid_l), cnt_r = solve(mid_r);

    if (cnt_l > cnt_r) {
      l = mid_l;
    } else if (cnt_l < cnt_r) {
      r = mid_r;
    } else {
      l = mid_l;
      r = mid_r;
    }
  }

  ll ans = 1e16;
  for (int i = l; i <= r; i++) {
    ans = min(ans, solve(i));
  }
  cout << ans << endl;

  return 0;
}
