template <typename T>
struct Queue
{
    T *head = nullptr;
    T *end = nullptr;
    int num = 0;

    const T operator[](int index) const;
};

template <typename T>
Queue<T> *CreateQueue(int N)
{
    if (N < 0)
    {
        return nullptr;
    }
    else
    {
        Queue<T> *head = new Queue<T>;
        head->head = new T[N]{reinterpret_cast<T>(0)};
        head->end = head->head;
        head->num = N;
        return head;
    }
}

template <typename T>
Queue<T> *InQueue(Queue<T> *head, T Data)
{
    if (head->end - head->head == head->num)
    {
        return head;
    }
    else
    {
        *(head->end) = Data;
        head->end++;
        return head;
    }
}

template <typename T>
Queue<T> *OutQueue(Queue<T> *head)
{
    if (head->head == head->end)
    {
        return head;
    }
    else
    {
        for (int i = 0; i < head->end - head->head - 1; i++)
        {
            (head->head)[i] = (head->head)[i + 1];
        }
        head->end--;
        return head;
    }
}

template <typename T>
Queue<T> *Clear(Queue<T> *head)
{
    head->end = head->head;
    return head;
}

template <typename T>
int GetNumOfMember(Queue<T> *head)
{
    return head->end - head->head;
}

template <typename T>
bool IsEmpty(Queue<T> *head)
{
    if (head->head == head->end)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool IsFull(Queue<T> *head)
{
    if (head->end - head->head == head->num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
const T Queue<T>::operator[](int index) const
{
    if ((index < 0 && index != -1) || this->head == this->end)
    {
        return reinterpret_cast<T>(0);
    }
    else if (index == -1)
    {
        return *(this->end - 1);
    }
    else
    {
        return *(this->head + index);
    }
}