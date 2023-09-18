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

string s;
int ans;

bool check(int j, int k) {
  string t;
  for (int i = j; i <= k; i++) {
    t += s[i];
  }

  for (int i = 0; i < t.length(); i++) {
    if (t[i] != t[t.length() - i - 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    for (int j = i; j < s.length(); j++) {
      if (check(i, j)) {
        ans = max(ans, j - i + 1);
      }
    }
  }

  cout << ans << endl;

  return 0;
}