//几何求凸包模板
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
const double PI = acos(-1);
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
		scanf("%d%d", &x, &y);
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

int n, L;
int main()
{
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		if (kase++)printf("\n");
		scanf("%d%d", &n, &L);
		Polygon a(n);
		double ans = 2 * PI*L;
		vector<double>angle;
		for (int i = 0; i < a.size(); i++) {
			ans += a.sqr_len(i);//第i段的长度
			angle.push_back(a.get_angle(i));//表示获得凸包a的第i个角a的cos值
		}
		printf("%.0lf\n", ans);
	}
}