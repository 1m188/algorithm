template <typename T>
struct Stack
{
    T data = reinterpret_cast<T>(0);
    Stack<T> *last = nullptr;
    Stack<T> *next = nullptr;

    T operator[](int index);
};

template <typename T>
T Stack<T>::operator[](int index)
{
    if (index < 0 && index != -1)
    {
        return reinterpret_cast<T>(0);
    }
    else if (index == -1)
    {
        Stack<T> *cursor = this;
        for (;;)
        {
            if (!(cursor->next))
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
        Stack<T> *cursor = this;
        for (int i = 0;; i++)
        {
            if (!cursor)
            {
                return reinterpret_cast<T>(0);
            }
            else if (i == index)
            {
                return cursor->data;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
}

template <typename T>
Stack<T> *CreateStack()
{
    Stack<T> *head = nullptr;
    return head;
}

template <typename T>
Stack<T> *Push(Stack<T> *head, T Data)
{
    if (!head)
    {
        head = new Stack<T>;
        head->data = Data;
        return head;
    }
    else
    {
        Stack<T> *cursor = head;
        for (;;)
        {
            if (!(cursor->next))
            {
                cursor->next = new Stack<T>;
                cursor->next->data = Data;
                cursor->next->last = cursor;
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
Stack<T> *Pop(Stack<T> *head)
{
    if (!(head->next))
    {
        delete head;
        head = nullptr;
        return head;
    }
    else
    {
        Stack<T> *cursor = head;
        for (int i = 0;; i++)
        {
            if (!(cursor->next))
            {
                cursor = cursor->last;
                delete cursor->next;
                cursor->next = nullptr;
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
Stack<T> *Clear(Stack<T> *head)
{
    Stack<T> *cursor = head;
    for (;;)
    {
        if (!(cursor->next))
        {
            break;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    for (;;)
    {
        if (cursor->last)
        {
            cursor = cursor->last;
            delete cursor->next;
        }
        else
        {
            delete head;
            head = nullptr;
            return head;
        }
    }
}

template <typename T>
int GetNumofMember(Stack<T> *head)
{
    Stack<T> *cursor = head;
    int num = 0;
    for (;;)
    {
        if (cursor)
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
bool isEmpty(Stack<T> *head)
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}