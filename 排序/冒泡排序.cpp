template <typename T>
void Bubble_sort(T *a, int N)
{
    T change;
    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                change = a[j];
                a[j] = a[j + 1];
                a[j + 1] = change;
            }
        }
    }
}