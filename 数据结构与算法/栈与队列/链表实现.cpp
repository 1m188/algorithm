template <typename T>
struct Queue
{
    T data = reinterpret_cast<T>(0);
    Queue<T> *last = nullptr;
    Queue<T> *next = nullptr;

    const T operator[](int index) const;
};

template <typename T>
Queue<T> *CreateQueue()
{
    Queue<T> *head = new Queue<T>;
    head->next = new Queue<T>;
    head->next->last = head;
    return head;
}

template <typename T>
Queue<T> *InQueue(Queue<T> *head, T Data)
{
    Queue<T> *cursor = head;
    for (;;)
    {
        if (!cursor->next->next)
        {
            cursor->next->data = Data;
            cursor->next->next = new Queue<T>;
            cursor->next->next->last = cursor->next;
            return head;
        }
        else
        {
            cursor = cursor->next;
        }
    }
}

template <typename T>
Queue<T> *OutQueue(Queue<T> *head)
{
    if (!head->next->next)
    {
        return head;
    }
    else
    {
        head = head->next;
        delete head->last;
        head->last = nullptr;
        head->data = reinterpret_cast<T>(0);
        return head;
    }
}

template <typename T>
Queue<T> *Clear(Queue<T> *head)
{
    if (!head->next->next)
    {
        return head;
    }
    else
    {
        for (;;)
        {
            if (head->next)
            {
                head = head->next;
                delete head->last;
            }
            else
            {
                delete head;
                head = CreateQueue<T>();
                return head;
            }
        }
    }
}

template <typename T>
int GetNumOfMember(Queue<T> *head)
{
    int num = 0;
    Queue<T> *cursor = head;
    for (;;)
    {
        if (cursor->next->next)
        {
            num++;
            cursor = cursor->next;
        }
        else
        {
            return num;
        }
    }
}

template <typename T>
bool IsEmpty(Queue<T> *head)
{
    if (!head->next->next)
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
    if ((index < 0 && index != -1) || !(this->next->next))
    {
        return reinterpret_cast<T>(0);
    }
    else if (index == -1)
    {
        Queue<T> *cursor = const_cast<Queue<T> *>(this);
        for (;;)
        {
            if (!cursor->next->next)
            {
                return cursor->data;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
    else
    {
        Queue<T> *cursor = const_cast<Queue<T> *>(this);
        for (int i = 0;; i++)
        {
            if (!cursor->next)
            {
                return reinterpret_cast<T>(0);
            }
            else if (i == index)
            {
                return cursor->next->data;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
}