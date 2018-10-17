#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int INF = 0x3f3f3f3f;
struct Node *null, *pit;
struct Node {
	Node *ch[2];
	int s;           // number of nodes in the subtree
	int flip;        // if flip=1, children and hashes are ALREADY swapped, so ch[0] and h1 are always corresponding to left child
	int v;           // value
	int mix;		 // min value

	Node() { mix = INF; ch[0] = ch[1] = null; }
	Node(int v) : flip(0), s(1), v(v), mix(v) { ch[0] = ch[1] = null; }

	void *operator new(size_t) { return pit++; }

	int cmp(int k) const {
		int d = k - ch[0]->s;
		if (d == 1) return -1;
		return d <= 0 ? 0 : 1;
	}
	void maintain() {
		s = ch[0]->s + ch[1]->s + 1;
		mix = min({ ch[0]->mix, ch[1]->mix,v });
	}
	void reverse() {
		flip ^= 1;
		swap(ch[0], ch[1]);
	}
	void pushdown() {
		if (flip) {
			flip = 0;
			ch[0]->reverse();
			ch[1]->reverse();
		}
	}
}pool[maxn];

void init_null() {
	null = new Node();
	null->s = 0;
}

void rotate(Node* &o, int d) {
	Node* k = o->ch[d ^ 1]; o->ch[d ^ 1] = k->ch[d]; k->ch[d] = o;
	o->maintain(); k->maintain(); o = k;
}


void splay(Node* &o, int k) {
	o->pushdown();
	int d = o->cmp(k);
	if (d == 1) k -= o->ch[0]->s + 1;
	if (d != -1) {
		Node* p = o->ch[d];
		p->pushdown();
		int d2 = p->cmp(k);
		int k2 = (d2 == 0 ? k : k - p->ch[0]->s - 1);
		if (d2 != -1) {
			splay(p->ch[d2], k2);
			if (d == d2) rotate(o, d ^ 1); else rotate(o->ch[d], d);
		}
		rotate(o, d ^ 1);
	}
}

// 把o的前k小结点放在left里，其他的放在right里。1<=k<=o->s。当k=o->s时，right=null
void split(Node* o, int k, Node* &left, Node* &right) {
	splay(o, k);
	left = o;
	right = o->ch[1];
	o->ch[1] = null;
	left->maintain();
}

// 合并left和right。假定left的所有元素比right小。注意right可以是null，但left不可以
Node* merge(Node* left, Node* right) {
	splay(left, left->s);
	left->ch[1] = right;
	left->maintain();
	return left;
}

struct SplaySequence {
	int* s;
	Node *root;

	// build s[L,R)
	Node* build(int L, int R) {
		int M = L + (R - L) / 2;
		Node* o = new Node(s[M]);
		if (L < M) o->ch[0] = build(L, M);
		if (M + 1 < R) o->ch[1] = build(M + 1, R);
		o->maintain();
		return o;
	}

	void update_dummy() {
		root->ch[1]->maintain();
		root->maintain();
	}

	Node* build(int* s, int n) {
		this->s = s;
		root = new Node(INF);
		root->ch[1] = new Node(INF);
		root->ch[1]->ch[0] = build(0, n);
		update_dummy();
		return root;
	}

	void print(Node* o, int flip) {
		if (o == null) return;
		if (!flip) { print(o->ch[0], o->flip); printf("%d ", o->v); print(o->ch[1], o->flip); }
		else { print(o->ch[1], o->flip); printf("%d ", o->v); print(o->ch[0], o->flip); }
	}

	int find(Node *o)
	{
		if (o->flip)o->pushdown();
		int k = o->mix;
		if (o->ch[0]->mix == k) return find(o->ch[0]);
		else if (o->v == k)return o->ch[0]->s + 1;
		else return o->ch[0]->s + 1 + find(o->ch[1]);
	}

	int find_min()
	{
		return find(root) - 1;
	}
}sp;

int n;
pair<int, int>p[maxn];
int ranks[maxn];

int main()
{
	while (scanf("%d", &n) == 1 && n) {
		pit = pool;
		init_null();
		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i].first);
			p[i].second = i;
		}
		sort(p, p + n);
		for (int i = 0; i < n; i++) {
			ranks[p[i].second] = i + 1;
		}
		sp.build(ranks, n);
		Node *L, *mid, *R, *tmp;
		for (int i = 1; i <= n; i++) {
			int k = sp.find_min();
			printf("%d%c", k + i - 1, i == n ? '\n' : ' ');
			split(sp.root, 1, L, R);
			split(R, k, mid, R);
			mid->reverse();
			R = merge(mid, R);
			split(R, 1, tmp, R);
			sp.root = merge(L, R);
		}
	}
}