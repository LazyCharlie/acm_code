
typedef long long LL;
LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a%b);
}
struct Frac {
	LL s;
	LL m;
	Frac(LL x = 0) :m(1), s(x) {}
	Frac(LL x, LL y) {  //x/y
		if (x == 0) {
			m = 1;
			s = 0;
			return;
		}
		LL g = gcd(std::abs(x), std::abs(y));
		x /= g;
		y /= g;
		if (y < 0)y = -y, x = -x;
		s = x;
		m = y;
	}
	Frac operator*(const Frac &rhs)const {
		if (s == 0 || rhs.s == 0)return Frac(0);
		Frac a(s, rhs.m), b(rhs.s, m);
		LL ns = a.s * b.s;
		LL nm = a.m * b.m;
		return Frac(ns, nm);
	}
	Frac operator/(const Frac &rhs)const {
		if (s == 0 || rhs.m == 0)return Frac(0);
		return (*this)*Frac(rhs.m, rhs.s);
	}
	Frac operator+(const Frac &rhs)const {
		LL g = gcd(std::abs(m), std::abs(rhs.m));
		LL ns = (rhs.m / g) * s + rhs.s * (m / g);
		if (ns == 0)return Frac(0);
		LL nm = (m / g) * rhs.m;
		return Frac(ns, nm);
	}
	Frac abs() { return Frac(std::abs(s), m); }
	Frac operator-(const Frac&rhs)const { return (*this) + Frac(-rhs.s, rhs.m); }
	Frac operator+=(const Frac&rhs) {return (*this) = (*this) + rhs; }
	Frac operator-=(const Frac&rhs){ return (*this) = (*this) - rhs; }
	bool operator<(const Frac&rhs)const { return ((*this) - rhs).s < 0; }
	bool operator>(const Frac&rhs)const { return rhs < (*this); }
	bool operator<=(const Frac&rhs)const { return (*this) < rhs || (*this) == rhs; }
	bool operator>=(const Frac&rhs)const { return (*this) > rhs || (*this) == rhs; }
	bool operator==(const Frac&rhs)const { return m == rhs.m&&s == rhs.s; }
	bool operator==(const LL&rhs)const { return (*this) == Frac(rhs); }
};
