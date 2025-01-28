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

int k;
string s, t;

bool solve() {
  if (abs(int(s.length()) - int(t.length())) >= 2) {
    return false;
  }

  if (s.length() == t.length()) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != t[i]) {
        cnt++;
      }
    }
    return cnt <= 1;
  }

  int j = 0, cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (j - i >= 2) {
      return false;
    }

    if (s[i] == t[j]) {
      j++;
      continue;
    } else {
      i--;
      j++;
      continue;
    }
  }

  return true;
}

int main() {
  cin >> k;
  cin >> s;
  cin >> t;

  if (s.length() > t.length()) {
    swap(s, t);
  }

  solve() ? Yes() : No();

  return 0;
}
