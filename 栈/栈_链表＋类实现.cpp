template <typename T>
class Stack
{
  private:
    T data;
    Stack<T> *last;
    Stack<T> *next;

  public:
    Stack() : data(reinterpret_cast<T>(0)), last(nullptr), next(nullptr) {}
    Stack(T d, Stack<T> *l, Stack<T> *n) : data(d), last(l), next(n) {}
    Stack(const Stack<T> &rhs);
    ~Stack();
    Stack<T> &operator=(const Stack<T> &rhs);

    static Stack<T> *CreateStack();
    void Push(T Data);
    void Pop();
    void Clear();
    const int GetNumofMember() const;
    const bool isEmpty() const;
    const T operator[](int index) const;
};

template <typename T>
Stack<T>::Stack(const Stack<T> &rhs)
{
    Stack<T> *cursor_this = const_cast<Stack<T> *>(this);
    Stack<T> *cursor = &rhs;
    for (;;)
    {
        if (!cursor)
        {
            cursor_this->data = cursor->data;
            cursor = cursor->next;
            cursor_this->next = new Stack<T>;
            cursor_this->next->last = cursor_this;
            cursor_this = cursor_this->next;
        }
        else
        {
            cursor_this = cursor_this->last;
            delete cursor_this->next;
            cursor_this->next = nullptr;
            return;
        }
    }
}

template <typename T>
Stack<T>::~Stack()
{
    delete last;
    delete next;
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs)
{
    Stack<T> *cursor_this = const_cast<Stack<T> *>(this);
    Stack<T> *cursor = &rhs;
    for (;;)
    {
        if (!cursor)
        {
            cursor_this->data = cursor->data;
            cursor = cursor->next;
            cursor_this->next = new Stack<T>;
            cursor_this->next->last = cursor_this;
            cursor_this = cursor_this->next;
        }
        else
        {
            cursor_this = cursor_this->last;
            delete cursor_this->next;
            cursor_this->next = nullptr;
            return *this;
        }
    }
}

template <typename T>
Stack<T> *Stack<T>::CreateStack()
{
    Stack<T> *head = new Stack<T>;
    return head;
}

template <typename T>
void Stack<T>::Push(T Data)
{
    Stack<T> *cursor = const_cast<Stack<T> *>(this);
    for (;;)
    {
        if (!cursor->next)
        {
            cursor->next = new Stack<T>();
            cursor->next->last = cursor;
            cursor->data = Data;
            return;
        }
        else
        {
            cursor = cursor->next;
        }
    }
}

template <typename T>
void Stack<T>::Pop()
{
    Stack<T> *cursor = const_cast<Stack<T> *>(this);
    if (!this->next)
    {
        return;
    }
    else
    {
        cursor = cursor->next;
        for (;;)
        {
            if (!cursor->next->next)
            {
                cursor = cursor->last;
                delete cursor->next->next;
                delete cursor->next;
                cursor->next = new Stack<T>;
                cursor->next->last = cursor;
                return;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
}

template <typename T>
void Stack<T>::Clear()
{
    Stack<T> *cursor = const_cast<Stack<T> *>(this);
    for (;;)
    {
        if (!cursor->next)
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
            delete cursor;
            cursor = new Stack<T>;
            return;
        }
    }
}

template <typename T>
const int Stack<T>::GetNumofMember() const
{
    Stack<T> *cursor = const_cast<Stack<T> *>(this);
    int num = 0;
    for (;;)
    {
        if (cursor->next)
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
const bool Stack<T>::isEmpty() const
{
    if (this->next == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
const T Stack<T>::operator[](int index) const
{
    if ((index < 0 && index != -1) || (!this->next))
    {
        return T(0);
    }
    else if (index == -1)
    {
        Stack<T> *cursor = const_cast<Stack<T> *>(this);
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
        Stack<T> *cursor = const_cast<Stack<T> *>(this);
        for (int i = 0;; i++)
        {
            if (!cursor->next)
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