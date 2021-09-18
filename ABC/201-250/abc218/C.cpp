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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int n, cntS, cntT;
int si, sj, ui, uj;
char s[205][205], t[205][205], u[205][205];

void setStart(){
  si = n, sj = n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (s[i][j] == '#'){
        si = min(si, i);
        sj = min(sj, j);
      }
    }
  }

  ui = n, uj = n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (u[i][j] == '#'){
        ui = min(ui, i);
        uj = min(uj, j);
      }
    }
  }
}

void setU(){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      u[i][j] = t[n - 1 - j][i];      
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      t[i][j] = u[i][j];
    }
  }
  setStart();
}

bool solve(){
  setU();

  int cnt = 0;
  for (int i = 0; i + si < n && i + ui < n; i++){
    for (int j = 0; j + sj < n && j + uj < n; j++){
      if (s[i + si][j + sj] != u[i + ui][j + uj]){
        return false;
      }
      if (s[i + si][j + sj] == '#'){
        cnt++;
      }
    }
  }
  return cnt == cntS && cnt == cntT;
}


int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> s[i][j];
      if (s[i][j] == '#'){
        cntS++;
      }
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> t[i][j];
      if (t[i][j] == '#'){
        cntT++;
      }
    }
  }

  bool ans = false;
  for (int i = 0; i < 4; i++){
    ans |= solve();
  }
  if (ans) Yes();
  else No();

  return 0;
}