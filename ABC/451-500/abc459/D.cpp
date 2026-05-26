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
int cnt[26];

void solve() {
  fill(cnt, cnt + 26, 0);
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    cnt[s[i] - 'a']++;
  }

  vector<pair<int, char>> now;
  vector<char> ans(s.length());

  for (int i = 0; i < 26; i++) {
    if (cnt[i] == 0) {
      continue;
    }
    now.push_back({cnt[i], char('a' + i)});
  }
  sort(now.begin(), now.end(), greater<pair<int, char>>());

  int idx = 0;
  for (pair<int, char> p : now) {
    while (p.first > 0) {
      ans[idx] = p.second;
      p.first--;

      idx += 2;
      if (idx >= s.length()) {
        idx = 1;
      }
    }
  }

  for (int i = 1; i < s.length(); i++) {
    if (ans[i] == ans[i - 1]) {
      No();
      return;
    }
  }

  Yes();
  for (char c : ans) {
    cout << c;
  }
  cout << '\n';
  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
