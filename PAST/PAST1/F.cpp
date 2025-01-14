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
vector<string> ans;

int main() {
  cin >> s;
  string now = "";
  for (int i = 0; i < s.length(); i++) {
    if (now == "") {
      now += char(s[i] - 'A' + 'a');
    } else if ('A' <= s[i] && s[i] <= 'Z') {
      now += char(s[i] - 'A' + 'a');
      ans.push_back(now);
      now = "";
    } else {
      now += s[i];
    }
  }
  sort(ans.begin(), ans.end());

  for (string a : ans) {
    for (int j = 0; j < a.length(); j++) {
      if (j == 0 || j == a.length() - 1) {
        cout << char(a[j] - 'a' + 'A');
      } else {
        cout << a[j];
      }
    }
  }
  cout << endl;

  return 0;
}
