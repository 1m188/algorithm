template <typename T>
class Queue
{
  private:
    T data;
    Queue<T> *last;
    Queue<T> *next;

  public:
    Queue() : data(reinterpret_cast<T>(0)), last(nullptr), next(nullptr) {}
    Queue(T d, Queue<T> *l, Queue<T> *n) : data(d), last(l), next(n) {}
    Queue(const Queue<T> &rhs);
    ~Queue();
    Queue<T> &operator=(const Queue<T> &rhs);

    static Queue<T> *CreateQueue();
    void InQueue(T Data);
    void OutQueue();
    void Clear();
    const int GetNumOfMember() const;
    const bool isEmpty() const;
    const T operator[](int index) const;
};

template <typename T>
Queue<T>::Queue(const Queue<T> &rhs)
{
    if (!rhs.next.next)
    {
        this->next = new Queue<T>;
        this->next->last = this;
    }
    else
    {
        Queue<T> *cursor = &rhs->next;
        for (;;)
        {
            if (!cursor->next)
            {
                break;
            }
            else
            {
                this->InQueue(cursor->data);
                cursor = cursor->next;
            }
        }
    }
}

template <typename T>
Queue<T>::~Queue()
{
    Queue<T> *cursor = const_cast<Queue<T> *>(this);
    for (;;)
    {
        if (cursor->last)
        {
            cursor = cursor->last;
        }
        else
        {
            break;
        }
    }
    for (;;)
    {
        if (cursor->next)
        {
            cursor = cursor->next;
            delete cursor->last;
        }
        else
        {
            delete cursor;
            break;
        }
    }
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &rhs)
{
    if (!rhs.next.next)
    {
        this->next = new Queue<T>;
        this->next->last = const_cast<Queue<T> *>(this);
    }
    else
    {
        Queue<T> *cursor = &rhs->next;
        for (;;)
        {
            if (!cursor->next)
            {
                break;
            }
            else
            {
                this->InQueue(cursor->data);
                cursor = cursor->next;
            }
        }
    }
    return *this;
}

template <typename T>
Queue<T> *Queue<T>::CreateQueue()
{
    Queue<T> *head = new Queue<T>();
    head->next = new Queue<T>();
    head->next->last = head;
    return head;
}

template <typename T>
void Queue<T>::InQueue(T Data)
{
    Queue<T> *cursor = const_cast<Queue<T> *>(this);
    for (;;)
    {
        if (!cursor->next)
        {
            cursor->data = Data;
            cursor->next = new Queue<T>();
            cursor->next->last = cursor;
            return;
        }
        else
        {
            cursor = cursor->next;
        }
    }
}

template <typename T>
void Queue<T>::OutQueue()
{
    if (!this->next->next)
    {
        return;
    }
    else
    {
        this->next = this->next->next;
        //delete this->next->last;
        this->next->last = this;
    }
}

template <typename T>
void Queue<T>::Clear()
{
    for (;;)
    {
        if (!this->next->next)
        {
            return;
        }
        else
        {
            this->OutQueue();
        }
    }
}

template <typename T>
const int Queue<T>::GetNumOfMember() const
{
    int num = 0;
    Queue<T> *cursor = const_cast<Queue<T> *>(this);
    for (;;)
    {
        if (!cursor->next->next)
        {
            return num;
        }
        else
        {
            num++;
            cursor = cursor->next;
        }
    }
}

template <typename T>
const bool Queue<T>::isEmpty() const
{
    if (!this->next->next)
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
    if ((index < 0 && index != -1) || (!this->next->next))
    {
        return reinterpret_cast<T>(0);
    }
    else if (index == -1)
    {
        Queue<T> *cursor = this->next;
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
        Queue<T> *cursor = this->next;
        for (int i = 0;; i++)
        {
            if (!cursor->next)
            {
                return T(0);
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