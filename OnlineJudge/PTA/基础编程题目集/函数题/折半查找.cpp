/*
6-13 折半查找 （15 分）
给一个严格递增数列，函数int Search_Bin(SSTable T, KeyType k)用来二分地查找k在数列中的位置。

函数接口定义：

int  Search_Bin(SSTable T, KeyType k)
其中T是有序表，k是查找的值。

裁判测试程序样例：


#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType  *R; 
  int  length;
} SSTable;                      

void  Create(SSTable &T)
{ int i;
  T.R=new ElemType[MAXSIZE+1];
  cin>>T.length;
  for(i=1;i<=T.length;i++)
     cin>>T.R[i].key;   
}

int  Search_Bin(SSTable T, KeyType k);

int main () 
{  SSTable T;  KeyType k;
   Create(T);
   cin>>k;
   int pos=Search_Bin(T,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

请在这里填写答案

输入格式：

第一行输入一个整数n，表示有序表的元素个数，接下来一行n个数字，依次为表内元素值。 然后输入一个要查找的值。

输出格式：

输出这个值在表内的位置，如果没有找到，输出"NOT FOUND"。

输入样例：

5
1 3 5 7 9
7
输出样例：

4
输入样例：

5
1 3 5 7 9
10
输出样例：

NOT FOUND
*/

#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef struct
{
    KeyType key;
} ElemType;

typedef struct
{
    ElemType *R;
    int length;
} SSTable;

void Create(SSTable &T)
{
    int i;
    T.R = new ElemType[MAXSIZE + 1];
    cin >> T.length;
    for (i = 1; i <= T.length; i++)
        cin >> T.R[i].key;
}

int Search_Bin(SSTable T, KeyType k);

int main()
{
    SSTable T;
    KeyType k;
    Create(T);
    cin >> k;
    int pos = Search_Bin(T, k);
    if (pos == 0)
        cout << "NOT FOUND" << endl;
    else
        cout << pos << endl;
    return 0;
}

int Search_Bin(SSTable T, KeyType k)
{
    int start = 0, end = T.length - 1;
    while (start <= end)
    {
        int mid = (end - start) / 2 + start;
        if (T.R[mid].key > k)
        {
            end = mid - 1;
        }
        else if (T.R[mid].key < k)
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return 0;
}