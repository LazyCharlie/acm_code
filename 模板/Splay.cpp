struct Node *null, *pit;
struct Node {
  Node *ch[2];
  int s;           // number of nodes in the subtree
  int flip;        // if flip=1, children and hashes are ALREADY swapped, so ch[0] and h1 are always corresponding to left child
  int v;           // value
  unsigned h1, h2; // hash

  Node() {}
  Node(int v) : flip(0), s(1), v(v), h1(v), h2(v) { ch[0] = ch[1] = null; }

  void *operator new(size_t) { return pit++; }

  // k = 1 means the smallest node
  int cmp(int k) const {
    int d = k - ch[0]->s;
    if(d == 1) return -1;
    return d <= 0 ? 0 : 1;
  }
  void maintain() {
    s = ch[0]->s + ch[1]->s + 1;
    h1 = ch[0]->h1*powers[ch[1]->s+1] + v*powers[ch[1]->s] + ch[1]->h1;
    h2 = ch[1]->h2*powers[ch[0]->s+1] + v*powers[ch[0]->s] + ch[0]->h2;
  }
  void reverse() {
    flip ^= 1;
    swap(ch[0], ch[1]);
    swap(h1, h2);
  }
  void pushdown() {
    if(flip) {
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
  Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
  o->maintain(); k->maintain(); o = k; 
}


// k >= 1
void splay(Node* &o, int k) {
  o->pushdown();
  int d = o->cmp(k);
  if(d == 1) k -= o->ch[0]->s + 1;
  if(d != -1) {
    Node* p = o->ch[d];
    p->pushdown();
    int d2 = p->cmp(k);
    int k2 = (d2 == 0 ? k : k - p->ch[0]->s - 1);
    if(d2 != -1) {
      splay(p->ch[d2], k2);
      if(d == d2) rotate(o, d^1); else rotate(o->ch[d], d);
    }
    rotate(o, d^1);
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


#include<cstring>
struct SplaySequence {
  char* s;
  Node *root;

  // build s[L,R)
  Node* build(int L, int R) {
    int M = L + (R - L) / 2;
    Node* o = new Node(s[M]);
    if(L < M) o->ch[0] = build(L, M);
    if(M+1 < R) o->ch[1] = build(M+1, R);
    o->maintain();
    return o;
  }

  // update dummy nodes
  // root: dummy min node
  // root->ch[1]: dummy max node
  // root->ch[1]->ch[0]: actual sequence
  void update_dummy() {
    root->ch[1]->maintain();
    root->maintain();
  }

  Node* last() const {
    return root->ch[1]->ch[0];
  }

  Node* build(char* s) {
    this->s = s;
    root = new Node('[');
    root->ch[1] = new Node(']');
    root->ch[1]->ch[0] = build(0, strlen(s));
    update_dummy();
    return root;
  }

  // splay and returns the range [L,R)
  // L >= 1
  Node*& range(int L, int R) {
    splay(root, L);
    splay(root->ch[1], R-L+1);
    return root->ch[1]->ch[0];
  }

  void print(Node* o, int flip) {
    if(o == null) return;
    if(!flip) { print(o->ch[0], o->flip); printf("%c", o->v); print(o->ch[1], o->flip); }
    else { print(o->ch[1], o->flip); printf("%c", o->v); print(o->ch[0], o->flip); }
  }

  void print() {
    print(root, 0);
    printf("\n");
  }

};
