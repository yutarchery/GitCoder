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
int ans = 0;

bool judge(string now) {
  if (now.length() == 0 || now.length() >= 4) {
    return false;
  }

  for (int i = 0; i + now.length() - 1 < s.length(); i++) {
    bool flag = true;
    for (int j = 0; j < now.length(); j++) {
      if (s[i + j] == now[j] || now[j] == '.') {
        continue;
      } else {
        flag = false;
        break;
      }
    }

    if (flag) {
      return true;
    }
  }

  return false;
}

void solve(string now = "") {
  if (judge(now)) {
    ans++;
  }
  if (now.length() == 3) {
    return;
  }

  for (char c = 'a'; c <= 'z'; c++) {
    string next = now;
    next += c;
    solve(next);
  }

  now += '.';
  solve(now);
  return;
}

int main() {
  cin >> s;
  solve();
  cout << ans << endl;

  return 0;
}
