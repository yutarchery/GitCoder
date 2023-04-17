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

int n, k, c[int(3e5 + 5)];
map<int, int> cnt;
int ans = 0, now = 0;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> c[i];

    if (i < k) {
      if (cnt[c[i]] == 0) {
        ans++;
        now++;
      }
      cnt[c[i]]++;
    }
  }

  for (int i = k; i < n; i++) {
    cnt[c[i - k]]--;
    if (cnt[c[i - k]] == 0) {
      now--;
    }
    if (cnt[c[i]] == 0) {
      now++;
    }
    cnt[c[i]]++;
    ans = max(ans, now);
  }

  cout << ans << endl;

  return 0;
}