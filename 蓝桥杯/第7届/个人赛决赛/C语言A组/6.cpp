/*

圆圈舞

春天温暖的阳光照耀着大地，正是草原上的小动物们最快乐的时候。小动物们在草原上开了一个舞会，欢度这美好的时光。

舞会上最重要的一个环节就是跳圆舞曲，n只小动物手拉手围成一大圈，随着音乐跳起来。在跳的过程中，小动物们可能会变换队形。它们的变换方式是动物A松开自己右手，动物B松开自己的左手，动物A和B手拉到一起，而它们对应的松开的手（如果有的话）也拉到一起。

例如，假设有10只小动物，按顺序围成一圈，动物1的右手拉着动物2的左手，动物2的右手拉着动物3的左手，依次类推，最后动物10的右手拉着动物1的左手。如果通过动物2和8变换队形，则动物2的右手拉着动物8的左手，而对应的动物3的左手拉着动物7的右手，这样形成了1-2-8-9-10和3-4-5-6-7两个圈。如果此时通过动物2和6变换队形，则将形成1-2-6-7-3-4-5-8-9-10一个大圈。注意，如果此时通过动物1和2变换队形，那么队形不会改变，因为动物1的右手和动物2的左手松开后又拉到一起了。

在跳舞的过程中，每个动物i都有一个欢乐值Hi和一个感动值Fi。
如果两个动物在一个圈中，欢乐值会彼此影响，产生欢乐能量。如果两个动物i, j（i≠j）在同一个大小为t的圈中，而动物i在动物j右手的第p个位置（动物j右手的第1个位置就是动物j右手所拉着的动物，而第2个位置就是右手第1个位置的动物右手拉着的动物，依次类推），则产生的欢乐能量为(t-p)*Hj*Fi。在跳舞的过程中，动物们的欢乐值和感动值有可能发生变化。

圆舞曲开始的时候，所有的动物按编号顺序围成一个圈，动物n右手的第i个位置正好是动物i。现在已知小动物们变换队形的过程和欢乐值、感动值变化的过程，求每次变换后所有动物所产生的欢迎能量之和。

【输入格式】
输入的第一行包含一个整数n，表示动物的数量。
接下来n行，每行两个用空格分隔的整数Hi, Fi，按编号顺序给出每只动物的欢乐值和感动值。
接下来一行包含一个整数m，表示队形、欢乐值、感动值的变化次数。
接下来m行，每行三个用空格分隔的整数k, p, q，当k=1时，表示小动物们通过动物p和动物q变换了队形，当k=2时，表示动物p的欢乐值变为q，当k=3时，表示动物p的感动值变为了q。

【输出格式】
输出m行，每行一个整数，表示每次变化后所有动物产生的能量之和。
答案可能很大，你需要计算答案除以1000000007的余数。

【样例输入】
10
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
9
1 2 8
1 2 6
2 8 10
3 5 10
1 1 2
1 2 1
2 5 5
1 4 8
1 4 5

【样例输出】
100
450
855
1341
1341
811
923
338
923

【数据规模与约定】
对于20%的数据，2<=n,m<=100。
对于30%的数据，2<=n,m<=1000。
另有20%的数据，只有k=1的操作且Hi,Fi均为1。
另有20%的数据，只有k=1或2的操作且Fi均为1。
对于100%的数据，2<=n,m<=100000，0<=Hi,Fi<=10^9，1<=k<=3，k=1时1<=p,q<=n且p≠q，k=2或3时1<=p<=n且0<=q<=10^9。

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 2500ms

请严格按要求输出，不要画蛇添足地打印类似："请您输入..." 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。


*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007LL;

mt19937 rng(time(0));

int rand_prio() { return uniform_int_distribution<int>(0, 2000000000)(rng); }

struct Node {
    int sz, prio;
    ll H, F;
    ll sumH, sumF, sumHF;
    ll wH, wF;
    ll cross;
    Node *l, *r, *p;

    void init(ll h, ll f) {
        sz = 1;
        prio = rand_prio();
        H = h;
        F = f;
        sumH = h % MOD;
        sumF = f % MOD;
        sumHF = h * f % MOD;
        wH = 0;
        wF = 0;
        cross = 0;
        l = r = p = nullptr;
    }
} nodes[100005];

ll total_energy = 0;

void update(Node *u) {
    if (!u) return;
    Node *l = u->l, *r = u->r;
    int lsz = l ? l->sz : 0;

    u->sz = lsz + 1 + (r ? r->sz : 0);

    ll l_sumH = l ? l->sumH : 0;
    ll l_sumF = l ? l->sumF : 0;
    ll l_sumHF = l ? l->sumHF : 0;
    ll l_wH = l ? l->wH : 0;
    ll l_wF = l ? l->wF : 0;
    ll l_cross = l ? l->cross : 0;

    ll r_sumH = r ? r->sumH : 0;
    ll r_sumF = r ? r->sumF : 0;
    ll r_sumHF = r ? r->sumHF : 0;
    ll r_wH = r ? r->wH : 0;
    ll r_wF = r ? r->wF : 0;
    ll r_cross = r ? r->cross : 0;

    u->sumH = (l_sumH + u->H + r_sumH) % MOD;
    u->sumF = (l_sumF + u->F + r_sumF) % MOD;
    u->sumHF = (l_sumHF + u->H * u->F % MOD + r_sumHF) % MOD;

    u->wH = (l_wH + (ll)lsz * u->H % MOD + r_wH + (ll)(lsz + 1) * r_sumH % MOD) % MOD;
    u->wF = (l_wF + (ll)lsz * u->F % MOD + r_wF + (ll)(lsz + 1) * r_sumF % MOD) % MOD;

    u->cross = (l_cross + r_cross + l_sumH * u->F % MOD + u->H * r_sumF % MOD +
                l_sumH * r_sumF % MOD) %
               MOD;
}

ll circle_energy(Node *root) {
    if (!root) return 0;
    ll t = root->sz;
    return (t * root->cross % MOD + root->wH * root->sumF % MOD -
            root->sumH * root->wF % MOD + MOD) %
           MOD;
}

pair<Node *, Node *> split(Node *root, int k) {
    if (!root) return {nullptr, nullptr};
    int lsz = root->l ? root->l->sz : 0;
    if (k <= lsz) {
        auto [l, r] = split(root->l, k);
        root->l = r;
        if (r) r->p = root;
        if (l) l->p = nullptr;
        update(root);
        return {l, root};
    } else {
        auto [l, r] = split(root->r, k - lsz - 1);
        root->r = l;
        if (l) l->p = root;
        if (r) r->p = nullptr;
        update(root);
        return {root, r};
    }
}

Node *merge(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;
    if (left->prio > right->prio) {
        left->r = merge(left->r, right);
        if (left->r) left->r->p = left;
        update(left);
        return left;
    } else {
        right->l = merge(left, right->l);
        if (right->l) right->l->p = right;
        update(right);
        return right;
    }
}

int get_pos(Node *u) {
    int pos = u->l ? u->l->sz : 0;
    while (u->p) {
        if (u == u->p->r) pos += 1 + (u->p->l ? u->p->l->sz : 0);
        u = u->p;
    }
    return pos;
}

Node *get_root(Node *u) {
    while (u->p)
        u = u->p;
    return u;
}

void update_path(Node *u) {
    while (u) {
        update(u);
        u = u->p;
    }
}

Node *rotate_to_first(Node *root, Node *target) {
    int pos = get_pos(target);
    auto [left, right] = split(root, pos);
    return merge(right, left);
}

void op_link(int p, int q) {
    Node *np = &nodes[p], *nq = &nodes[q];
    Node *root_p = get_root(np), *root_q = get_root(nq);

    if (root_p == root_q) {
        ll old_E = circle_energy(root_p);
        root_p = rotate_to_first(root_p, np);

        auto [node_p, rest] = split(root_p, 1);
        int q_pos = get_pos(nq);

        if (q_pos == 0) {
            merge(node_p, rest);
            return;
        }

        total_energy = (total_energy - old_E + MOD) % MOD;

        auto [middle, right_q] = split(rest, q_pos);
        Node *circle1 = merge(node_p, right_q);
        Node *circle2 = middle;

        total_energy = (total_energy + circle_energy(circle1)) % MOD;
        if (circle2) total_energy = (total_energy + circle_energy(circle2)) % MOD;
    } else {
        ll E1 = circle_energy(root_p), E2 = circle_energy(root_q);
        total_energy = (total_energy - E1 - E2 + 2 * MOD) % MOD;

        root_p = rotate_to_first(root_p, np);
        auto [node_p, rest_p] = split(root_p, 1);
        root_q = rotate_to_first(root_q, nq);

        Node *new_circle = merge(node_p, merge(root_q, rest_p));
        total_energy = (total_energy + circle_energy(new_circle)) % MOD;
    }
}

void op_update_H(int p, ll new_H) {
    Node *u = &nodes[p];
    Node *root = get_root(u);
    ll old_E = circle_energy(root);
    u->H = new_H % MOD;
    update_path(u);
    root = get_root(u);
    ll new_E = circle_energy(root);
    total_energy = (total_energy - old_E + new_E + MOD) % MOD;
}

void op_update_F(int p, ll new_F) {
    Node *u = &nodes[p];
    Node *root = get_root(u);
    ll old_E = circle_energy(root);
    u->F = new_F % MOD;
    update_path(u);
    root = get_root(u);
    ll new_E = circle_energy(root);
    total_energy = (total_energy - old_E + new_E + MOD) % MOD;
}

int main() {
    int n;
    scanf("%d", &n);

    Node *root = nullptr;
    for (int i = 1; i <= n; i++) {
        ll h, f;
        scanf("%lld %lld", &h, &f);
        nodes[i].init(h, f);
        root = merge(root, &nodes[i]);
    }

    total_energy = circle_energy(root);

    int m;
    scanf("%d", &m);
    while (m--) {
        int k, p;
        ll q;
        scanf("%d %d %lld", &k, &p, &q);
        if (k == 1)
            op_link(p, (int)q);
        else if (k == 2)
            op_update_H(p, q);
        else
            op_update_F(p, q);
        printf("%lld\n", total_energy);
    }

    return 0;
}
