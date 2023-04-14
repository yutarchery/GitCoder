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
bool front[int(3e5 + 5)], back[int(3e5 + 5)];

bool compare(int s_index, int t_index) {
  if (s[s_index - 1] == '?' || t[t_index - 1] == '?') {
    return true;
  }
  return s[s_index - 1] == t[t_index - 1];
}

int main() {
  cin >> s >> t;

  front[0] = true;
  back[s.length() + 1] = true;
  for (int i = 1; i <= t.length(); i++) {
    front[i] = front[i - 1] & compare(i, i);
  }
  for (int i = t.length(); i >= 1; i--) {
    back[s.length() - t.length() + i] = back[s.length() - t.length() + i + 1] &
                                        compare(s.length() - t.length() + i, i);
  }

  for (int i = 0; i <= t.length(); i++) {
    if (front[i] && back[s.length() - t.length() + i + 1]) {
      Yes();
    } else {
      No();
    }
  }

  return 0;
}