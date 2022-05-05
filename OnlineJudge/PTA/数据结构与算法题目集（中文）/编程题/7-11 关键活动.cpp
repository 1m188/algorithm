/*
假定一个工程项目由一组子任务构成，子任务之间有的可以并行执行，有的必须在完成了其它一些子任务后才能执行。
“任务调度”包括一组子任务、以及每个子任务可以执行所依赖的子任务集。

比如完成一个专业的所有课程学习和毕业设计可以看成一个本科生要完成的一项工程，各门课程可以看成是子任务。
有些课程可以同时开设，比如英语和C程序设计，它们没有必须先修哪门的约束；
有些课程则不可以同时开设，因为它们有先后的依赖关系，比如C程序设计和数据结构两门课，必须先学习前者。

但是需要注意的是，对一组子任务，并不是任意的任务调度都是一个可行的方案。
比如方案中存在“子任务A依赖于子任务B，子任务B依赖于子任务C，子任务C又依赖于子任务A”，那么这三个任务哪个都不能先执行，
这就是一个不可行的方案。

任务调度问题中，如果还给出了完成每个子任务需要的时间，则我们可以算出完成整个工程需要的最短时间。
在这些子任务中，有些任务即使推迟几天完成，也不会影响全局的工期；
但是有些任务必须准时完成，否则整个项目的工期就要因此延误，这种任务就叫“关键活动”。

请编写程序判定一个给定的工程项目的任务调度是否可行；
如果该调度方案可行，则计算完成整个工程项目需要的最短时间，并输出所有的关键活动。

输入格式:
输入第1行给出两个正整数N(≤100)和M，其中N是任务交接点
（即衔接相互依赖的两个子任务的节点，例如：若任务2要在任务1完成后才开始，则两任务之间必有一个交接点）的数量。
交接点按1~N编号，M是子任务的数量，依次编号为1~M。随后M行，每行给出了3个正整数，
分别是该任务开始和完成涉及的交接点编号以及该任务所需的时间，整数间用空格分隔。

输出格式:
如果任务调度不可行，则输出0；
否则第1行输出完成整个工程项目需要的时间，第2行开始输出所有关键活动，每个关键活动占一行，按格式“V->W”输出，
其中V和W为该任务开始和完成涉及的交接点编号。关键活动输出的顺序规则是：
任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反。

输入样例:
7 8
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
4 6 6
5 7 5
6 7 2

输出样例:
17
1->2
2->4
4->6
6->7

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 参考的人家大佬的代码，用拓扑序列求最早开始时间，用逆拓扑序列求最迟开始时间，所有最早开始时间=最迟开始时间
的任务都是关键任务，之后按照要求输出关键路径即可。但关键在于如何对这个问题建模，如何存储和处理他的输入才能够
更好的对这个问题进行计算和输出 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int N = 0, M = 0;                  // 输入的任务数和任务之间的依赖关系数目
vector<int> in, ve, vl;            // 从1-N任务的入度，最早开始时间，最迟开始时间
vector<vector<pair<int, int>>> pe; // 对于pe[i]而言，指i号任务其后继的节点和从i到其后继的时间
stack<int> re_top_sorted;          // 用来压入拓扑序列，这样出栈的时候就是逆拓扑序列了

// 初始化输入
void init() {
    cin >> N >> M;
    in.resize(N + 1, 0); // 这里做到N+1是为了后面索引能够从1-N进行访问
    ve.resize(N + 1, 0);
    vl.resize(N + 1, 0);
    pe.resize(N + 1, {});

    for (int i = 0; i < M; i++) { // 输入两个任务间时间以及先后依赖关系
        int v1 = 0, v2 = 0, c = 0;
        cin >> v1 >> v2 >> c;
        in[v2]++; // 记录每个节点的入度，后面拓扑排序要用
        pe[v1].push_back(
            {v2, c}); // 对于每个节点，记录其后继节点和从该节点到后继节点的时间
    }
}

// 拓扑排序
// 返回布尔值表示任务能否被调度，有环则调度不了
bool topsort() {
    queue<int>
        que; // 先找个队列，压入所有没有入度的节点（考虑到多入口多出口等情况）
    for (int i = 1; i <= N; i++) {
        if (!in[i])
            que.push(i);
    }

    while (!que.empty()) { // 队列非空则不停的寻找入度为0的节点
        int v = que.front();
        que.pop();
        re_top_sorted.push(v); // 维护逆拓扑序列

        for (const auto &e : pe[v]) { // 对于每个当前无入度节点的后继节点

            // 将每个后继节点的入度--，对应将无入度节点从图中拿掉的动作，这个时候如果有节点的入度减少到0，则必然是这些节点
            if (!--in[e.first])
                que.push(e.first);

            // 这里更新最早开始时间（在拓扑序列里顺便更新了）
            // 对于当前节点v，其后继节点e.first(u)，和v->e.first的时间e.second(c)
            // 如果从v出发到u的最早开始时间，比u固有的最早开始时间要更晚
            // 那么更新
            // 因为对于u而言，必须其前置所有任务完成他才能够开始，所以前置所有任务的
            // 最晚完成时间才是他的最早开始时间
            if (ve[v] + e.second > ve[e.first])
                ve[e.first] = ve[v] + e.second;
        }
    }

    // 判定是否所有的点都被遍历到了，如果没有，那么必然存在环，无法调度
    return re_top_sorted.size() < N ? false : true;
}

// 寻找关键路径
void criticalpath() {

    // 先拓扑排序判定一下
    // 这里判定之前由于拓扑排序里会用到最早开始时间数组，所以应该初始化ve
    // 而由于是“开始”，则假设所有任务最开始都从0开始发生
    // 这里在上面init里已经初始化过了
    if (!topsort()) {
        cout << 0;
        return;
    }

    // 这里很巧妙
    // 关键路径上所有的任务其最早开始时间都等于其最晚开始时间
    // 而关键路径又是项目中时间最长的活动顺序，决定着可能的项目最短工期
    // 所以关键路径长度就等于其最大的最早开始时间
    int mpl = *max_element(ve.begin(), ve.end()); // 关键路径长
    cout << mpl << '\n';

    // 这里对最晚开始时间初始化
    // 由于最晚开始时间都是从后往前算，寻找一个更小的值
    // 这里将其初始化为最大值
    fill(vl.begin(), vl.end(), mpl);

    while (!re_top_sorted.empty()) { // 逆拓扑排序求最晚开始时间
        int v = re_top_sorted.top();
        re_top_sorted.pop();

        // 这里从后往前更新最晚开始时间数组，原理和上面最早开始时间一样
        for (const auto &e : pe[v]) {
            if (vl[e.first] - e.second < vl[v])
                vl[v] = vl[e.first] - e.second;
        }
    }

    // 最后的输出，也非常的巧妙
    // 一开始i从1-N，满足了起始点小编号在先
    for (int i = 1; i <= N; i++) {

        // 当起始点编号一样的时候，按照输入顺序的反序进行输出
        // 由于pe[i]数组在初始化的时候就是按照输入顺序一个个push进去的，
        // 所以这里从后往前刚好是按照输入顺序反着来的
        for (int j = pe[i].size() - 1; j >= 0; j--) {

            // 这里并没有直接比较同一个节点的最早开始时间和最晚开始时间是否相同
            // 而是对于i的每个后继节点和i进行比较和计算，也可以得到同样的结果，但是能够
            // 指明下一个该输出的节点是什么
            if (vl[pe[i][j].first] - pe[i][j].second == ve[i])
                cout << i << "->" << pe[i][j].first << '\n';
        }
    }
}

int main() {
    init();
    criticalpath();
    return 0;
}

/*

这里附上人家大佬的博客和代码

https://blog.csdn.net/qq_45921756/article/details/123724915




题目链接：7-11 关键活动
考查知识：拓扑排序+逆拓扑排序

题意描述：
关键路径：从源点到汇点的所有路径中，具有最大路径长度的路径称为关键路径，其上的活动称为关键活动
n个点，m条有向边，求有向图中的关键路径长度，并按以下要求打印关键路径
关键活动输出的顺序规则是：任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反。

思路简析：

从原点出发，按拓扑排序求事件最早发生时间ve

从汇点出发，按逆拓扑排序求事件最迟发生时间vl

根据各个顶点的ve,vl数组求弧的最早e，最迟l开始时间

求AOE网中所有活动的差额d(),找到所有d()=l()-e()=0的活动构成关键活动




具体代码


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e2;
int in[N],ve[N],vl[N];//in为点的入度，ve为事件最早开始时间，vl为事件最迟开始时间
vector<pair<int,int> >e[N];//pair为后继结点，与后继结点的边权  
stack<int>toporder;//按拓扑序列入栈，出栈即逆拓扑序列 
bool topologicalsort(int n){//拓扑排序，同时求Ve数组
	queue<int>q;
	for(int i=1;i<=n;i++){//遍历所有结点，令入度为零的结点入队 
		if(!in[i])q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();toporder.push(u);
		for(int i=0;i<e[u].size();i++){//遍历u所有后继结点
			int v=e[u][i].first,w=e[u][i].second;//u的i号后继节点编号为v，边权为w 
			if(--in[v]==0)q.push(v);
			if(ve[u]+w>ve[v])ve[v]=ve[u]+w;//用ve[u]来跟新u的所有后继结点v
		}
	}
	if(toporder.size()==n)return true;
	else return false;
} 
int criticalpath(int n){
	memset(ve,0,sizeof(ve));//ve数组初始化
	if(!topologicalsort(n)){
		cout<<0;return 0;//不是有向无环图，打印0
	} 
	int mx=-1;//关键路径长度 
	for(int i=1;i<=n;i++){
		if(ve[i]>mx)mx=ve[i];
	}cout<<mx<<endl;
	fill(vl+1,vl+n+1,mx);//vl数组初始化 
	while(!toporder.empty()){
		int u=toporder.top();//按拓扑序列入栈，出栈即逆拓扑序列
		toporder.pop();
		for(int i=0;i<e[u].size();i++){ 
			int v=e[u][i].first,w=e[u][i].second;//u的i号后继节点编号为v，边权为w
			if(vl[v]-w<vl[u])vl[u]=vl[v]-w;//同时向前更新vl数组 
		}
	} 
	for(int i=1;i<=n;i++){//任务开始的交接点编号小者优先
		for(int j=e[i].size()-1;j>=0;j--){//起点编号相同时，与输入时任务的顺序相反。
			int v=e[i][j].first,w=e[i][j].second;//i的j号后继节点编号为v，边权为w
			int e=ve[i],l=vl[v]-w;//遍历领接表的所有边，计算活动最早开始时间e与最晚开始时间l
			if(e==l)cout<<i<<"->"<<v<<endl; 
		} 
	}
}
int main(){
	int n,m,x,y,z;
	cin>>n>>m;//n个点，m条有向边 
	while(m--){
		cin>>x>>y>>z;//x到y的边权为z的有向边 
		in[y]++;
		e[x].push_back({y,z});
	}
	criticalpath(n);
	return 0;
}

*/