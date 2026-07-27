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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

string s;
int ans = 0;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    int cnt = 0;
    for (int j = 0; i - j >= 0 && i + j < s.length(); j++) {
      if (s[i - j] != s[i + j]) {
        cnt++;
      }

      if (cnt <= 1) {
        ans++;
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < s.length(); i++) {
    int cnt = 0;
    for (int j = 0; i - j >= 0 && i + 1 + j < s.length(); j++) {
      if (s[i - j] != s[i + 1 + j]) {
        cnt++;
      }

      if (cnt <= 1) {
        ans++;
      } else {
        break;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
