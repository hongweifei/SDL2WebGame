


#ifndef QUEUE_HEAD
#define QUEUE_HEAD


template<typename T>
class Queue
{
private:
    Queue *prev;
    Queue *next;

    T data;
public:
    Queue();
    ~Queue();

    void Add(T data);
    T Get();
};

template<typename T>
Queue<T>::Queue()
{
    this->prev = this;
    this->next = this;
    this->data = NULL;
}

template<typename T>
Queue<T>::~Queue()
{
    delete this->prev;
    delete this->next;
}

template<typename T>
void Queue<T>::Add(T data)
{
    Queue<T> *q = new Queue<T>();
    q->data = data;
    q->next = this;
    q->prev = this->prev;

    this->prev->next = q;
    this->prev = q;
}

template<typename T>
T Queue<T>::Get()
{
    T data = this->next->data;

    this->next = this->next->next;
    this->next->prev = this;

    return data;
}



#endif

