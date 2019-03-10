template <typename T>
struct list
{
    T data = reinterpret_cast<T>(0);
    list<T> *last = nullptr;
    list<T> *next = nullptr;
};

template <typename T>
list<T> *CreateNode(int N)
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
            cursor->next->last = cursor;
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
        for (int i = 0;; i++)
        {
            if (!cursor)
            {
                return head;
            }
            else if (i == N)
            {
                if (!(cursor->next))
                {
                    cursor->last->next = nullptr;
                    delete cursor;
                    return head;
                }
                else if (!(cursor->last))
                {
                    cursor = cursor->next;
                    delete cursor->last;
                    return cursor;
                }
                else
                {
                    list<T> *cursor_next = cursor->next;
                    list<T> *cursor_last = cursor->last;
                    cursor_last->next = cursor_next;
                    cursor_next->last = cursor_last;
                    delete cursor;
                    return head;
                }
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
        for (int i = 0;; i++)
        {
            if (!(cursor->next) && (i != N))
            {
                cursor->next = new list<T>;
                cursor->next->last = cursor;
                return head;
            }
            else if (i == N)
            {
                if (!(cursor->last))
                {
                    cursor->last = new list<T>;
                    cursor->last->next = cursor;
                    cursor = cursor->last;
                    return cursor;
                }
                else
                {
                    list<T> *newNode = new list<T>;
                    cursor->last->next = newNode;
                    newNode->last = cursor->last;
                    cursor->last = newNode;
                    newNode->next = cursor;
                    return head;
                }
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
}

template <typename T>
list<T> *SetValue(list<T> *head, int N, T newdata)
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
                cursor->data = newdata;
                return head;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
}