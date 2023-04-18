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

string s, t;
vector<pair<char, int>> a, b;

int main() {
  cin >> s >> t;

  int cnt = 1;
  char now = s[0];
  for (int i = 1; i < s.length(); i++) {
    if (s[i] != now) {
      a.push_back({now, cnt});
      now = s[i];
      cnt = 1;
    } else {
      cnt++;
    }

    if (i == s.length() - 1) {
      a.push_back({now, cnt});
    }
  }
  cnt = 1, now = t[0];
  for (int i = 1; i < t.length(); i++) {
    if (t[i] != now) {
      b.push_back({now, cnt});
      now = t[i], cnt = 1;
    } else {
      cnt++;
    }

    if (i == t.length() - 1) {
      b.push_back({now, cnt});
    }
  }

  if (a.size() != b.size()) {
    No();
    return 0;
  }

  for (int i = 0; i < a.size(); i++) {
    if (a[i].first != b[i].first) {
      No();
      return 0;
    }

    if (a[i].second > b[i].second) {
      No();
      return 0;
    }

    if (a[i].second == 1 && b[i].second > 1) {
      No();
      return 0;
    }
  }

  Yes();
  return 0;
}