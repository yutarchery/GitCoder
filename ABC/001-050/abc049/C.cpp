#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

string S;
string T[4] = {"dream", "dreamer", "erase", "eraser"};

bool visited[int(1e5 + 5)];
bool ans[int(1e5 + 5)];

bool solve(int start){
  if (start == S.length()) return true;
  if (visited[start]) return ans[start];

  visited[start] = true;
  bool res = false;
  for (int i = 0; i < 4; i++){
    if (start + T[i].length() > S.length()){
      continue;
    }
    bool flag = true;
    for (int j = 0; j < T[i].length(); j++){
      if (S[start + j] != T[i][j]) flag = false;
    }
    if (flag){
      res |= solve(start + T[i].length());
    }
  }
  return ans[start] = res;
}

int main(){
  cin >> S;
  if (solve(0)) YES();
  else NO();
  return 0;
}