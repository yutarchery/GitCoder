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

int n;
char s[int(2e5 + 5)], t[int(2e5 + 5)];

set<int> to_a, to_b, now_a, now_b;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] == t[i]) {
      if (s[i] == 'A') {
        now_a.insert(i);
      } else {
        now_b.insert(i);
      }
    } else {
      if (t[i] == 'A') {
        to_a.insert(i);
      } else {
        to_b.insert(i);
      }
    }
  }
  now_a.insert(n + 1);
  now_b.insert(0);

  if (to_a.empty() && to_b.empty()) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 0;
  auto a_iter = to_a.begin(), b_iter = to_b.begin();
  while (a_iter != to_a.end()) {
    int a = *a_iter;

    b_iter = to_b.upper_bound(a);
    if (b_iter != to_b.end()) {
      a_iter++;
      to_a.erase(a);
      now_a.insert(a);
      int b = *b_iter;
      to_b.erase(b);
      now_b.insert(b);
      ans++;
      continue;
    }

    b_iter = now_b.upper_bound(a);
    if (b_iter != now_b.end()) {
      a_iter++;
      to_a.erase(a);
      now_a.insert(a);
      ans++;
      continue;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }

  int a = *(now_a.begin());
  for (int b : to_b) {
    if (b < a) {
      cout << -1 << endl;
      return 0;
    } else {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
