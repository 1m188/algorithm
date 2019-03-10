template <typename T>
struct list
{
    T data = reinterpret_cast<T>(0);
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
        head->next = head;
        list<T> *cursor = head;
        for (int i = 1; i < N; i++)
        {
            cursor->next = new list<T>;
            cursor->next->next = head;
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
            if (N == 0)
            {
                while (cursor->next != head)
                {
                    cursor = cursor->next;
                }
                cursor->next = cursor->next->next;
                delete head;
                return cursor->next;
            }
            else if (i == N - 1)
            {
                if (cursor->next != head)
                {
                    list<T> *cursor_next_next = cursor->next->next;
                    delete cursor->next;
                    cursor->next = cursor_next_next;
                    return head;
                }
                else
                {
                    list<T> *cursor_next_next = cursor->next->next;
                    delete cursor->next;
                    cursor->next = cursor_next_next;
                    return cursor_next_next;
                }
            }
            else
            {
                cursor = cursor->next;
                if (cursor == head)
                {
                    N -= i;
                    i = 0;
                }
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
            if (N == 0)
            {
                list<T> *newlist = new list<T>;
                while (cursor->next != head)
                {
                    cursor = cursor->next;
                }
                cursor->next = newlist;
                newlist->next = head;
                return newlist;
            }
            else if (i == N - 1)
            {
                list<T> *newlist = new list<T>;
                list<T> *cursor_next = cursor->next;
                cursor->next = newlist;
                newlist->next = cursor_next;
                return head;
            }
            else
            {
                cursor = cursor->next;
                if (cursor == head)
                {
                    N -= i;
                    i = 0;
                }
            }
        }
    }
}

template <typename T>
list<T> *SetValue(list<T> *head, int N, T Data)
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
            if (i == N)
            {
                cursor->data = Data;
                return head;
            }
            else
            {
                cursor = cursor->next;
                if (cursor == head)
                {
                    N -= i;
                    i = 0;
                }
            }
        }
    }
}