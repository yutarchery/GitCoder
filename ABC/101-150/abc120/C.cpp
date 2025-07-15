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
string s;

deque<char> que;

int main() {
  cin >> s;
  n = s.length();

  for (int i = 0; i < n; i++) {
    if (que.empty()) {
      que.push_front(s[i]);
      continue;
    }

    if (que.front() != s[i]) {
      que.pop_front();
    } else {
      que.push_front(s[i]);
    }
  }

  cout << n - int(que.size()) << endl;

  return 0;
}
