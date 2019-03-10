template <typename T>
struct list
{
    T data = reinterpret_cast<T>(0);
    list<T> *next = nullptr;
};

template <typename T>
list<T> *CreateList(int N)
{
    if (N <= 0)
    {
        return nullptr;
    }
    else
    {
        list<T> *head = new list<T>;
        list<T> *cursor = head;
        for (int i = 1; i < N; i++)
        {
            cursor->next = new list<T>;
            cursor = cursor->next;
        }
        return head;
    }
}

template <typename T>
list<T> *DelNode(list<T> *head, int N)
{
    if (N < 0)
    {
        return head;
    }
    else
    {
        list<T> *cursor = head;
        if (N == 0)
        {
            cursor = cursor->next;
            delete head;
            return cursor;
        }
        for (int i = 0;; i++)
        {
            if (!cursor)
            {
                return head;
            }
            else if ((i == N - 1) && cursor->next)
            {
                list<T> *cursor_next_next = cursor->next->next;
                delete cursor->next;
                cursor->next = cursor_next_next;
                return head;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
}

template <typename T>
list<T> *AddNode(list<T> *head, int N)
{
    if (N < 0)
    {
        return head;
    }
    else
    {
        list<T> *cursor = head;
        if (N == 0)
        {
            list<T> *NewNode = new list<T>;
            NewNode->next = head;
            return NewNode;
        }
        for (int i = 0;; i++)
        {
            if (!cursor)
            {
                return head;
            }
            else if (i == N - 1)
            {
                list<T> *NewNode = new list<T>;
                list<T> *cursor_next = cursor->next;
                cursor->next = NewNode;
                NewNode->next = cursor_next;
                return head;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
}

template <typename T>
list<T> *SetValue(list<T> *head, int N, T value)
{
    if (N < 0)
    {
        return head;
    }
    else
    {
        list<T> *cursor = head;
        for (int i = 0;; i++)
        {
            if (!cursor)
            {
                return head;
            }
            else if (i == N)
            {
                cursor->data = value;
                return head;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
}