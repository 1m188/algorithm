template <typename T>
void Insert_sort(T *a, int N)
{
    if (N < 2)
    {
        return;
    }
    else
    {
        T change = reinterpret_cast<T>(0);
        for (int i = N - 2; i > -1; i--)
        {
            for (int j = i; j < N - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    change = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = change;
                }
            }
        }
    }
}

template <typename T>
void InsertSort(T A[], int N) //书上的例程
{
    int j = 0, P = 0;
    T Tmp = reinterpret_cast<T>(0);
    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = Tmp;
    }
}