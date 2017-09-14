#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <string>

using namespace std;
const int N=474800;
int dp[N][2];
bool composite[N];
int k;
bool win;
class PrimeCompositeGame {
public:


       int solve(int value,int turn){
             int &ret=dp[value][turn];
             if(ret!=-1)return ret;
             if(value==0){
                if(turn==1)win=1;
                return ret=0;
             }
//             cerr<<value<<" "<<turn<<endl;
             if(turn==0){
                for(int i=k;i>=1;i--){
                   int t=(value-i);
                   if(t>=2&&composite[t]==0){
                    ret=solve(t,1-turn)+1;
                     break;
                   }
                }
                if(ret==-1){
                  return ret=0;
                }

             }else{
               
               for(int i=1;i<=k;i++){
                 int t=(value-i);
                 if(t>1&&composite[t]==1){
                   ret=solve(t,1-turn)+1;
                   break;
                 }
               }
               if(ret==-1){win=1;return  ret=0;}
             }
            return ret;
       
       }
        void sieve(int n){
             composite[1]=1;
             composite[0]=1;
            for(int i=2;i<=n;i++){
               if(composite[i]==0){
                 for(int j=i+i;j<=n;j+=i){
                    composite[j]=1;
                 } 
               }
            }
        
        }
	int theOutcome(int n, int K) {
	    k=K;
	    win=0;
	    sieve(n);
	    memset(dp,-1,sizeof(dp));
	    int ans=solve(n,0);
	    if(win==0)ans*=-1;
	    return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	PrimeCompositeGame *obj;
	int answer;
	obj = new PrimeCompositeGame();
	clock_t startTime = clock();
	answer = obj->theOutcome(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 2;
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 58;
	p1 = 1;
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 30;
	p1 = 3;
	p2 = -2;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 6;
	p1 = 3;
	p2 = 1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 526;
	p1 = 58;
	p2 = 19;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!