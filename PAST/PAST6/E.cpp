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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
string s;
deque<int> que, tmp;

void frontPop(int idx) {
  if (que.size() < idx) {
    cout << "ERROR" << endl;
    return;
  }
  for (int i = 0; i < idx - 1; i++) {
    tmp.push_front(que.front());
    que.pop_front();
  }
  cout << que.front() << endl;
  que.pop_front();

  while (!tmp.empty()) {
    que.push_front(tmp.front());
    tmp.pop_front();
  }
  return;
}

void backPop(int idx) {
  if (que.size() < idx) {
    cout << "ERROR" << endl;
    return;
  }

  for (int i = 0; i < idx - 1; i++) {
    tmp.push_front(que.back());
    que.pop_back();
  }
  cout << que.back() << endl;
  que.pop_back();

  while (!tmp.empty()) {
    que.push_back(tmp.front());
    tmp.pop_front();
  }
  return;
}

int main() {
  cin >> n >> s;

  for (int i = 1; i <= n; i++) {
    char c = s[i - 1];
    if (c == 'L') {
      que.push_front(i);
    } else if (c == 'R') {
      que.push_back(i);
    } else if ('A' <= c && c <= 'C') {
      frontPop(c - 'A' + 1);
    } else {
      backPop(c - 'D' + 1);
    }
  }

  return 0;
}