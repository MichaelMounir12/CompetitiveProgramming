/***
*   idea : First Of all if the number of places is odd there is no answer because will not be any two point in same axis
*          So When Right Angle made in Circle Easily When 2 point in same axis and any other point ...
*          Because the number of places even the Striaght line become between point i and i+(n/2) 
*          ...Now Goo For Last then how when we eliminate the place that chosin and ... Easily Using Parent Path Feature  
*          in DSU :)
* 
*         Happy Solving :)
***/

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
const int N=1e6+7;
bool red[N];
int p[N];
class RightTriangle {
public:
        int Find(int i){
          return i==p[i]?i:p[i]=Find(p[i]);
        }
        void init(){
           for(int i=0;i<1e6+7;i++){
             p[i]=i;
           }
        }
	long long triangleCount(int n, int m, int a, int b, int c) {
	    init();
	    memset(red,0,sizeof(red));
	    if((n&1) || m <3)return 0;
	    for(int i=0;i<m;i++){
	       int cur=(int)((1ll*a*i*i+1ll*b*i+c)%n);
	       cur=Find(cur);
	       red[cur]=1;
	       p[cur]=(cur+1)%n;
	    }
	    long long cnt=0;
	    for(int i=0;i<n/2;i++){
	       if(red[i]&&red[i+n/2])cnt++;
	    } 
	    return cnt*(m-2);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, long long p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	RightTriangle *obj;
	long long answer;
	obj = new RightTriangle();
	clock_t startTime = clock();
	answer = obj->triangleCount(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	int p3;
	int p4;
	long long p5;
	
	{
	// ----- test 0 -----
	p0 = 9;
	p1 = 3;
	p2 = 0;
	p3 = 3;
	p4 = 0;
	p5 = 0ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 40;
	p1 = 3;
	p2 = 5;
	p3 = 0;
	p4 = 0;
	p5 = 1ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 4;
	p2 = 16;
	p3 = 24;
	p4 = 17;
	p5 = 4ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1000000;
	p1 = 47000;
	p2 = 0;
	p3 = 2;
	p4 = 5;
	p5 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 200000;
	p1 = 700;
	p2 = 123456;
	p3 = 789012;
	p4 = 345678;
	p5 = 6980ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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
