/*
*    Idea : First Make dp state [last][cnt]... the answer is if we found the l strings then we can make (N-L)! sequence from this valid sequence :)
*
*
*
*/
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
using namespace std;
vector<string>str;
const int N=55;
int dp[N][N];
int l;
int n;
const int MOD=(int)1e9+7;
int fact[N];

class SimilarNames2 {
public:
        int solve(int last,int cnt){
            int &ret=dp[last][cnt];
            if(ret!=-1)return ret;
            if(cnt>=l){
              return fact[n-l];
            }
            ret=0;
            for(int i=0;i<n;i++){
              if(last==52){
                 ret=(ret+solve(i,cnt+1))%MOD;
              }else if(str[last].size()>=str[i].size())continue;
              else if(str[last]==str[i].substr(0,str[last].size())){
//                 cerr<<str[last]<<" "<<str[i].substr(0,str[last].size())<<endl;
                 ret=(ret+solve(i,cnt+1))%MOD;
              }
            }
            return ret=ret%MOD;

        }

	int count(vector <string> names, int L) {
	    l=L;
	    str=names;
	    n=names.size();
	    fact[0]=1;
	    for(int i=1;i<N;i++){
	     fact[i]=(fact[i-1]*(long long )i)%MOD;
	    }
	    memset(dp,-1,sizeof(dp));
	    return solve(52,0);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	SimilarNames2 *obj;
	int answer;
	obj = new SimilarNames2();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
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
	
	vector <string> p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"kenta","kentaro","ken"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"hideo","hideto","hideki","hide"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"aya","saku","emi","ayane","sakura","emika","sakurako"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 24;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"taro","jiro","hanako"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	p2 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"alice","bob","charlie"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	p2 = 6;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"ryota","ryohei","ryotaro","ryo","ryoga","ryoma","ryoko","ryosuke","ciel","lun","ryuta","ryuji","ryuma","ryujiro","ryusuke","ryutaro","ryu","ryuhei","ryuichi","evima"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	p2 = 276818566;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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