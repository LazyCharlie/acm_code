//几何求凸包模板
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
const double PI = acos(-1);
#define int long long
#define all(a) a.begin(), a.end()
struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
	Point operator - (const Point& ot) const {
		return Point(x - ot.x, y - ot.y);
	}
	int operator * (const Point& ot) const {//求叉积
		return x * ot.y - y * ot.x;
	}
	void scan() {  //读入一个点对
		scanf("%lld%lld", &x, &y);
	}
	bool operator < (const Point& rhs) const {
		return make_pair(x, y) < make_pair(rhs.x, rhs.y);
	}
	int sqr_len() const {
		return x * x + y * y;
	}
	double get_len() const {  //求(x,y)点到(0,0)点的距离
		return sqrtl(sqr_len());
	}
	int operator % (const Point& rhs) const {//向量数量积,向量a在向量b上的投影
		return x * rhs.x + y * rhs.y;
	}
};

struct Polygon {
	vector<Point> hull;
	Polygon(int n) {
		vector<Point> points(n);
		for (int i = 0; i < n; ++i) {
			points[i].scan();
		}
		sort(all(points));
		vector<Point> up, down;
		for (auto& pt : points) {
			while (up.size() > 1 && (up[up.size() - 2] - up.back()) * (pt - up.back()) >= 0) {
				up.pop_back();
			}
			up.push_back(pt);
			while (down.size() > 1 && (down[down.size() - 2] - down.back()) * (pt - down.back()) <= 0) {
				down.pop_back();
			}
			down.push_back(pt);
		}
		hull = up;
		for (int i = (int)down.size() - 2; i > 0; --i) {
			hull.push_back(down[i]);
		}
	}
	double sqr_len(int pos) const {  //求的是距离
		return (hull[(pos + 1) % hull.size()] - hull[pos]).get_len();
	}
	int size() const {
		return (int)hull.size();
	}
	double get_angle(int pos) const {
		auto a = hull[(pos + 1) % hull.size()] - hull[pos], b = hull[(pos + hull.size() - 1) % hull.size()] - hull[pos];
		double co = (a % b) / a.get_len() / b.get_len();//返回的是cos(a)的值
		return co;
	}
};

const double eps = 1e-7;
int f[200050];//失配转移函数,f[i]表示如果第i个失配应该转移到哪里
void getFail(const vector<double>&T, int *f)//KMP失配函数
{
	f[0] = 0; f[1] = 0;
	int m = T.size() - 1;
	for (int i = 1; i < m; i++)
	{
		int j = f[i];
		while (j&&fabs(T[i] - T[j]) > eps)j = f[j];
		f[i + 1] = (fabs(T[i] - T[j])<=eps) ? j + 1 : 0;
	}
}
int KMP(const vector<double>&S, const vector<double>&T, int *f)
{
	getFail(T, f);
	int ans = 0, sn = S.size() - 1, tn = T.size() - 1 , j = 0;
	for (int i = 0, j = 0; i < sn; i++)
	{
		while (j&&fabs(S[i] - T[j]) > eps)j = f[j];
		if (fabs(S[i] - T[j])<=eps)j++;
		if (j == tn)ans++;//j=0 表示不考虑重叠串 printf("%d\n",i-m+1);
	}
	return ans;
}

int n, m;
signed main()
{
	scanf("%lld%lld", &n, &m);
	Polygon S0(n);
	Polygon S1(m);
	if (S0.size() != S1.size()) {
		printf("NO\n");
		return 0;
	}
	vector<double>ans1, ans2;
	for (int i = 0; i <  S0.size(); i++) {
		ans1.push_back(S0.get_angle(i));
		ans1.push_back(S0.sqr_len(i));
		ans2.push_back(S1.get_angle(i));
		ans2.push_back(S1.sqr_len(i));
	}
	ans1.push_back(-2);
	for (int i = 0; i < S0.size(); i++) {
		ans2.push_back(S1.get_angle(i));
		ans2.push_back(S1.sqr_len(i));
	}
	ans2.push_back(-2);
	getFail(ans1, f);
	printf(KMP(ans2, ans1, f) ? "YES\n" : "NO\n");
}
