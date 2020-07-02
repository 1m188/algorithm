//当有散列值相同的元素时，会产生一个冲突，为了解决冲突，一种简单的方法时是分离链接法，即将散列到一个值的所有元素保存到一个表中

#include "cstdlib"

const int MinTableSize = 0;
template <typename T>
struct ListNode;
template <typename T>
struct HashTbl;
template <typename T>
struct ListNode;
template <typename T>
struct HashTbl;
template <typename T>
HashTbl<T> *InitializeTable(int TableSize);
template <typename T>
void DestroyTable(HashTbl<T> *H);
template <typename T>
ListNode<T> *Find(T Key, HashTbl<T> *H);
template <typename T>
void Insert(T Key, HashTbl<T> *H);
template <typename T>
T Retrieve(ListNode<T> *P);

template <typename T>
struct ListNode
{
    T Element;
    ListNode<T> *Next;
};

template <typename T>
struct HashTbl
{
    int TableSize;
    ListNode<T> *TheLists;
};

template <typename T>
HashTbl<T> *InitializeTable(int TableSize)
{
    HashTbl<T> *H = nullptr;

    if (TableSize < MinTableSize)
    {
        return nullptr;
    }

    H = new HashTbl<T>();
    if (H == nullptr)
    {
        return nullptr;
    }

    //H->TableSize = NextPrime(TableSize);//设定表的大小为一素数

    H->TheLists = malloc(sizeof(ListNode<T> *) * H->TableSize);
    if (H->TheLists == nullptr)
    {
        return nullptr;
    }

    for (int i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(ListNode<T>));
        if (H->TheLists[i] == nullptr)
        {
            return nullptr;
        }
        else
        {
            H->TheLists[i]->Next = nullptr;
        }
    }
}

template <typename T>
ListNode<T> *Find(T Key, HashTbl<T> *H)
{
    ListNode<T> *P = nullptr;
    ListNode<T> *L = nullptr;

    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != nullptr && P->Element != Key) //如果Key是个字符串记得要用相应的方法
    {
        P = P->Next;
    }
    return P;
}

template <typename T>
void Insert(T Key, HashTbl<T> *H) //计算了两次散列函数，多余的计算不太好
{
    ListNode<T> *Pos = nullptr, *NewCell = nullptr;
    ListNode<T> *L = nullptr;

    Pos = Find(Key, H);
    if (Pos == nullptr) //Key没找到
    {
        return;
    }
    else
    {
        L = H->TheLists[Hash(Key, H->TableSize)];
        NewCell->Next = L->Next;
        NewCell->Element = Key;
        L->Next = NewCell;
    }
}