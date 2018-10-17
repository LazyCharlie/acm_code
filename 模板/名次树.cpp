
//基于Treap实现的名次树，可以查第k大的数、某个数的rank
struct Node {
	Node *ch[2];
	int r, v, s;
	Node(int val = 0)
	{
		ch[0] = ch[1] = NULL;
		r = rand();
		v = val;
		s = 1;
	}
	int cmp(int x)const {
		if (x == v)return -1;
		return x < v ? 0 : 1;
	}
	void maintain()
	{
		s = 1;
		if (ch[0] != NULL)s += ch[0]->s;
		if (ch[1] != NULL)s += ch[1]->s;
	}
};
void rotate(Node* &o, int d) {
	Node * k = o->ch[1 ^ d]; //未来的顶点
	o->ch[1 ^ d] = k->ch[d]; //k的孩子变为顶点的孩子
	k->ch[d] = o;
	o->maintain();
	k->maintain();
	o = k;	 //k变为顶点
}
void insert(Node* &o, int x) {
	if (o == NULL) { o = new Node(x); }
	else {
		int d = x < o->v ? 0 : 1;//相同值当作右节点插入
		insert(o->ch[d], x); if (o->ch[d]->r > o->r)rotate(o, d ^ 1);
	}
	o->maintain();
}
void remove(Node* &o, int x)
{
	int d = o->cmp(x);
	if (d == -1) {
		if (o->ch[0] == NULL)o = o->ch[1];
		else if (o->ch[1] == NULL)o = o->ch[0];
		else {
			int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
			rotate(o, d2); remove(o->ch[d2], x);
		}
	}
	else remove(o->ch[d], x);
	if (o != NULL)o->maintain();
}
int find(Node *o, int x) {
	while (o != NULL) {
		int d = o->cmp(x);
		if (d == -1)return 1;
		else o = o->ch[d];
	}
	return 0;
}
Node* root[maxn];
void init()
{
	memset(vis, 0, sizeof(vis));
	C.clear();
	for (int i = 1; i < maxn; i++)p[i] = i;
}
int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
void mergeto(Node* &src, Node * &dest)
{
	if (src->ch[0])mergeto(src->ch[0], dest);
	if (src->ch[1])mergeto(src->ch[1], dest);
	insert(dest, src->v);
	delete src;
	src = NULL;
}
void removetree(Node* &o) 
{
	if (o->ch[0])removetree(o->ch[0]);
	if (o->ch[1])removetree(o->ch[1]);
	delete o;
	o = NULL;
}
int kth(Node* &o, int k)
{
	if (o == NULL || k <= 0 || k > o->s)return 0;
	if (o->ch[1] != NULL) {
		if (o->ch[1]->s >= k)return kth(o->ch[1], k);
		else k -= o->ch[1]->s;
	}
	if (k == 1)return o->v;
	k--;
	if (o->ch[0] != NULL) {
		return kth(o->ch[0], k); 
		if (o->ch[0]->s >= k)return kth(o->ch[0], k);
	}
}

int main()
{
	
}