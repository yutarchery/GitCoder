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

string S[3];
int usedCharCount = 0;
bool usedChar[26];
int usedCharIndex[26];

int main(){
  for (int i = 0; i < 3; i++){
    cin >> S[i];
    for (int j = 0; j < S[i].length(); j++){
      if (!usedChar[S[i][j] - 'a']) {
        usedCharIndex[S[i][j] - 'a'] = usedCharCount;
        usedCharCount++;  
      }
      usedChar[S[i][j] - 'a'] = true;
    }
  }

  if (usedCharCount > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }

  int numberOrder[10];
  for (int i = 0; i < 10; i++){
    numberOrder[i] = i;
  }

  do{
    ll nowNumber[3] = {};
    bool ansFlag = true;
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < S[i].length(); j++){
        nowNumber[i] *= 10;
        int charIndex = usedCharIndex[S[i][j] - 'a'];
        nowNumber[i] += numberOrder[charIndex];
      }
      int startIndex = usedCharIndex[S[i][0] - 'a'];
      if (numberOrder[startIndex] == 0){
        ansFlag = false;
      }
    }

    if (ansFlag){
      if (nowNumber[0] + nowNumber[1] == nowNumber[2]){
        for (int i = 0; i < 3; i++){
          cout << nowNumber[i] << endl;
        }
        return 0;
      }
    }

  } while (next_permutation(numberOrder, numberOrder + 10));
  
  cout << "UNSOLVABLE" << endl;

  return 0;
}