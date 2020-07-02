template <typename T>
void QuickSort(T *a, int N)
{
    if (N <= 1)
    {
        return;
    }

    int i = 0, j = N - 1, index = 0;

    while (i < j)
    {
        for (;;)
        {
            if (a[j] < a[index])
            {
                T temp = a[j];
                a[j] = a[index];
                a[index] = temp;
                index = j;
                break;
            }
            else
            {
                j--;
                if (j <= i)
                {
                    break;
                }
            }
        }
        for (;;)
        {
            if (a[i] > a[index])
            {
                T temp = a[i];
                a[i] = a[index];
                a[index] = temp;
                index = i;
                break;
            }
            else
            {
                i++;
                if (i >= j)
                {
                    break;
                }
            }
        }
    }

    QuickSort(a, index + 1);
    QuickSort(&a[index + 1], N - index - 1);
}