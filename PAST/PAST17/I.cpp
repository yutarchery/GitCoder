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
string s[int(1e5 + 5)];

map<string, ll> mp;
ll ans = 0;

void solve(string t) {
  int m = t.length();
  set<string> st;

  for (int i = 1; i < (1 << m); i++) {
    string now = "";
    int rest = i;
    for (int j = 0; j < m; j++) {
      if (rest % 2 == 1) {
        now += t[j];
      }
      rest /= 2;
    }
    st.insert(now);
  }

  for (string u : st) {
    mp[u]++;
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    solve(s[i]);
  }

  for (int i = 0; i < n; i++) {
    ans += mp[s[i]];
  }
  cout << ans << endl;

  return 0;
}
