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
        head->next = head;
        head->last = head;
        list<T> *cursor = head;
        for (int i = 1; i < N; i++)
        {
            list<T> *newlist = new list<T>;
            cursor->next = newlist;
            newlist->last = cursor;
            newlist->next = head;
            head->last = newlist;
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
                list<T> *cursor_next = cursor->next;
                list<T> *cursor_last = cursor->last;
                delete cursor;
                cursor_last->next = cursor_next;
                cursor_next->last = cursor_last;
                return cursor_next;
            }
            else if (i == N)
            {
                list<T> *cursor_next = cursor->next;
                list<T> *cursor_last = cursor->last;
                delete cursor;
                cursor_last->next = cursor_next;
                cursor_next->last = cursor_last;
                return head;
            }
            else
            {
                cursor = cursor->next;
                if (cursor == head)
                {
                    N -= i + 1;
                    i = -1;
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
                list<T> *cursor_last = cursor->last;
                cursor_last->next = newlist;
                newlist->last = cursor_last;
                newlist->next = cursor;
                cursor->last = newlist;
                return newlist;
            }
            else if (i == N)
            {
                list<T> *newlist = new list<T>;
                list<T> *cursor_last = cursor->last;
                cursor_last->next = newlist;
                newlist->last = cursor_last;
                newlist->next = cursor;
                cursor->last = newlist;
                return head;
            }
            else
            {
                cursor = cursor->next;
                if (cursor == head)
                {
                    N -= i + 1;
                    i = -1;
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
                    N -= i + 1;
                    i = -1;
                }
            }
        }
    }
}