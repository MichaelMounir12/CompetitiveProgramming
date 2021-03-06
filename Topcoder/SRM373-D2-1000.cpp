/**
*
*   idea : Just Check the end point of Every segment within rectangle using ccw checking and check segments intersections
*          of all triangle side  with all segment line
*
*
*
**/

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
#include <string>
#include <string.h>
using namespace std;
struct point{
  int x,y;
  point(int x=0,int y=0):x(x),y(y){}
  point operator -(point &other){
      return point(x-other.x,y-other.y);
  }
  inline bool operator ==(point &other){
     return x==other.x&&y==other.y;
  }
};                       
struct rect{
  point a,b,c,d;
  int area;
  rect(point a,point b,point c,point d,int area=0):a(a),b(b),c(c),d(d),area(area){}
};
struct seg{
  point a,b;
  seg(point a,point b):a(a),b(b){}
};
const int N=105;
bool Cont[N];
const double EPS=1e-5;
class RectangleCrossings {
public:
       double norm(point &v1){
          return sqrt(((double)v1.x*v1.x)+((double)v1.y*v1.y));
       }

       long long cross(point &v1,point &v2){
           return 1ll*v1.x*v2.y-1ll*v1.y*v2.x;
       }

       int ccw(point &a,point &b,point &c){
          point v1=b-a;
          point v2=c-a;
          if(cross(v1,v2)>0)return 1;
          if(cross(v1,v2)<0)return -1;
          if(v1.x*v2.x < 0 || v1.y*v2.y < 0)return -1;
          if(norm(v1) < norm(v2) -EPS)return 1;
          return 0;
       }
       bool InterSeg(point &a,point &b,point &c,point &d){
           bool f1=(b==a),f2=(c==d);
           if(f1&&f2)return a==c;
           if(f1) return ccw(c,d,a)==0;
           if(f2)  return ccw(a,b,c)==0;
           return ccw(a,b,c)*ccw(a,b,d)<=0&&
                  ccw(c,d,a)*ccw(c,d,b)<=0;
       }
       bool contain(point &a,point &b,point &c,point &d,point &f1,point &f2){
                 return (((ccw(a,b,f1)>0&&ccw(b,c,f1)>0&&ccw(c,d,f1)>0&&ccw(d,a,f1)>0))||
                      ((ccw(a,b,f2)>0&&ccw(b,c,f2)>0&&ccw(c,d,f2)>0&&ccw(d,a,f2)>0)));
       }
	vector <int> countAreas(vector <string> rec, vector <string> segment) {
	       int n=rec.size();
	       point a,b,c,d;
	       vector<rect>r;
	       vector<seg>s;
	       memset(Cont,0,sizeof(Cont));
	       for(int i=0;i<n;i++){
	           istringstream in(rec[i]);
	           in>>a.x>>a.y>>c.x>>c.y;
	           b.x=c.x,b.y=a.y;
	           d.x=a.x,d.y=c.y;
	           r.push_back(rect(a,b,c,d,((d.y-a.y)*(b.x-a.x))));
	       }       
	       for(int i=0;i<segment.size();i++){
	           istringstream in(segment[i]);
	           in>>a.x>>a.y>>b.x>>b.y;
	           s.push_back(seg(a,b));
	           
	       }
	       n=r.size();
	       int  m=s.size();
	       int inter_area=0;
	       int contain_area=0;
	       // contain
                for(int i=0;i<n;i++){   
	          for(int j=0;j<m;j++){
	            if(contain(r[i].a,r[i].b,r[i].c,r[i].d,s[j].a,s[j].b)){
	                contain_area+=r[i].area;
	                Cont[i]=1;
	                break;
	            }
	          }
	       }
	       // inter
	       for(int i=0;i<n;i++){
	          if(Cont[i])continue;
	          for(int j=0;j<m;j++){
	              if(InterSeg(r[i].a,r[i].b,s[j].a,s[j].b)||InterSeg(r[i].b,r[i].c,s[j].a,s[j].b)||
	                 InterSeg(r[i].c,r[i].d,s[j].a,s[j].b)||InterSeg(r[i].d,r[i].a,s[j].a,s[j].b)){
	                 inter_area+=(r[i].area);
	                 break;
	              }
	          }
	       }                                                                                                           

	  	return vector<int>{contain_area,inter_area};	

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, vector <int> p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	RectangleCrossings *obj;
	vector <int> answer;
	obj = new RectangleCrossings();
	clock_t startTime = clock();
	answer = obj->countAreas(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p2[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
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
	vector <string> p1;
	vector <int> p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"-1000 -1000 1000 1000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"-525 245 222 243"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4000000,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"1 1 2 2","1 4 2 5","5 5 6 7","7 7 9 9"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"1 2 1 5"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"1 1 3 3","4 4 5 5","6 6 7 7","8 8 9 9","51 22 344 352","-124 -235 -12 -1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"-100 -2 300 300"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {122898,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"1 1 3 3","4 4 5 5","6 6 7 7","8 8 9 9","51 22 344 352","-124 -235 -12 -1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"-104 -103 202 201"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {122898,7};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"-891 -869 -853 -842","-857 -399 -744 -231","-910 -55 -856 36","-844 287 -749 548","-809 627 -782 954","-704 -803 -641 -663","-684 -330 -558 -268","-702 -40 -545 98","-660 386 -528 586","-697 855 -571 962","-414 -678 -168 -648","-401 -559 -383 -441","-387 5 -263 51","-389 220 -194 448","-361 673 -175 753","68 -912 95 -742","-24 -521 24 -227","30 -70 38 -2","-111 297 14 356","7 797 27 809","368 -709 418 -614","247 -453 344 -251","385 -111 417 -33","275 202 290 421","265 604 278 921","524 -861 655 -640","555 -336 576 -305","429 28 578 35","480 324 704 520","444 632 665 842","932 -954 981 -931","930 -537 939 -455","735 -81 787 192","830 316 869 589","808 629 971 666"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"-898 -383 126 12","283 -716 545 -918","-299 333 54 138","-901 129 706 488","-8 690 -290 955","-590 -771 476 257","-528 -518 651 -139","-984 -848 -380 459","-358 924 31 -617","817 -904 -208 -401","-657 -211 275 -407","-427 -699 -460 876","403 -612 -675 563","-782 -197 845 816","-492 -771 -342 -83","-650 -208 393 -614","-67 -290 135 -610","68 650 -366 560","-482 608 -525 516","548 460 -95 -436","461 -457 -491 -846","-672 728 -764 548","-301 633 -613 278","-496 126 940 576","-350 -378 -671 1000","148 82 275 211","815 872 -810 -362","160 -367 -754 569","-721 941 -405 -57","-792 582 804 563","-934 -115 -641 -737"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {126942,241757};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
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
