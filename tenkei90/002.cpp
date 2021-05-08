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

int N;
bool now[20];

int Solve(int num){

  for (int i = 0; i < N; i++){
    now[i] = num % 2;
    num /= 2;
  }

  int point = 0;
  for (int i = 0; i < N; i++){
    if (now[i]) point++;
    else point--;
    if (point < 0) return 0;
  }

  if (point == 0){
    for (int i = N - 1; i >= 0; i--){
      if (now[i]) cout << ')';
      else cout << '(';
    }
    cout << endl;
  }
  return 0;
}

int main(){
  cin >> N;

  for (int i = 0; i < (1<<N); i++){
    Solve(i);
  }

  return 0;
}