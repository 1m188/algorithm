//当有散列值相同的元素时，会产生一个冲突，为了解决冲突，一种简单的方法时是开放定址法，即在冲突发生的时候尝试另外的单元，直到找出空位为止

#include "cstdlib"

enum KindOfEntry
{
    Legitimate,
    Empty,
    Deleted
};
struct HashTbl;
template <typename T>
struct HashEntry;
HashTbl *InitializeTable(int TableSize);
void DestroyTable(HashTbl *H);
template <typename T>
unsigned int Find(T Key, HashTbl *H);
template <typename T>
void Insert(T Key, HashTbl *H);
template <typename T>
T Retrieve(unsigned int P, HashTbl *H);
HashTbl *Rehash(HashTbl *H);

template <typename T>
struct HashEntry
{
    T Element;
    KindOfEntry Info;
};

struct HashTbl
{
    int TableSize;
    //Cell *TheCells; //一个HashEntry的数组指针
};