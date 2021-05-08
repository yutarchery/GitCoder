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

string X;
vector <int> numX;
ll M;

bool compare(int digit){

  vector <int> nowDigit;
  ll nowM = M;
  while (nowM > 0){
    nowDigit.push_back(nowM % digit);
    nowM /= digit;
  }
  
  if (numX.size() < nowDigit.size()) return true;
  else if (numX.size() > nowDigit.size()) return false;

  for (int i = 0; i < numX.size(); i++){
    if (numX[i] == nowDigit[numX.size() - 1 - i]) continue;
    else if (numX[i] < nowDigit[numX.size() - 1 - i]) return true;
    else return false;
  }

  return true;
}

int main(){
  cin >> X >> M;
  int digit = 0;
  for (int i = 0 ; i < X.length(); i++){
    numX.push_back(X[i] - '0');
    digit = max(digit, X[i] - '0');
  }

  int ans = 0;
  digit++;
  while (compare(digit)){
    ans++; digit++;
  }
  cout << ans << endl;
  
  return 0;
}