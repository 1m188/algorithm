template <typename T>
void Choose_sort(T *a, int N)
{
    T temp;
    int temp_index;
    for (int i = 0; i < N; i++)
    {
        temp = a[i];
        temp_index = i;
        for (int j = i; j < N; j++)
        {
            if (a[j] < temp)
            {
                temp = a[j];
                temp_index = j;
            }
        }
        temp = a[i];
        a[i] = a[temp_index];
        a[temp_index] = temp;
    }
}