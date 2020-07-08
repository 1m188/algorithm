template <typename T>
struct Stack
{
    T *head = nullptr;
    T *cursor = nullptr;
    int num = 0;

    T operator[](int i);
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
        return *(this->cursor--);
    }
    else if (this->head + index >= this->cursor)
    {
        return reinterpret_cast<T>(0);
    }
    else
    {
        return *(this->head + index);
    }
}

template <typename T>
Stack<T> *CreateStack(int N)
{
    if (N < 0)
    {
        return nullptr;
    }
    else
    {
        Stack<T> *stack = new Stack<T>;
        stack->num = N;
        stack->head = new T[N]{T(0)};
        stack->cursor = stack->head;
        return stack;
    }
}

template <typename T>
Stack<T> *Push(Stack<T> *stack, T data)
{
    if (stack->cursor - stack->head == stack->num)
    {
        return stack;
    }
    else
    {
        *stack->cursor = data;
        stack->cursor++;
        return stack;
    }
}

template <typename T>
Stack<T> *Pop(Stack<T> *stack)
{
    if (stack->cursor == stack->head)
    {
        return stack;
    }
    else
    {
        stack->cursor--;
        *stack->cursor = T(0);
        return stack;
    }
}

template <typename T>
Stack<T> *Clear(Stack<T> *stack)
{
    if (stack->cursor == stack->head)
    {
        return stack;
    }
    else
    {
        for (; stack->cursor != stack->head;)
        {
            stack->cursor--;
            *stack->cursor = T(0);
        }
        return stack;
    }
}

template <typename T>
int GetNumofMember(Stack<T> *stack)
{
    return stack->cursor - stack->head;
}

template <typename T>
bool isEmpty(Stack<T> *stack)
{
    if (stack->cursor != stack->head)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
bool isFull(Stack<T> *stack)
{
    if (stack->cursor - stack->head == stack->num)
    {
        return true;
    }
    else
    {
        return false;
    }
}