#ifndef Stack_h
#define Stack_h

#include "Node.hpp"

template <class T>
class Stack
{
private:
    Node<T> *top;
    int size;

public:
    Stack();
    void push(T Data);
    T pop();
    T getTop();
    int getSize();
    void clear();
    void print();
    bool isEmpty();
};

template <class T>
Stack<T>::Stack()
{
    top = NULL;
    size = 0;
}

template <class T>
void Stack<T>::push(T data)
{
    top = new Node<T>(data, top);
    size++;
}

template <class T>
T Stack<T>::pop()
{
    if (!isEmpty())
    {
        Node<T> *aux = top;
        T data = aux->data;
        top = aux->next;
        delete aux;
        size--;
        return data;
    }
    throw runtime_error("The Stack is empty");
}

template <class T>
T Stack<T>::getTop()
{
    if (!isEmpty())
    {
        return top->data;
    }
    throw runtime_error("The Stack is empty");
}

template <class T>
int Stack<T>::getSize()
{
    return size;
}

template <class T>
void Stack<T>::clear()
{
    while (top != NULL)
    {
        Node<T> *aux = top;
        top = aux->next;
        delete aux;
    }
    size = 0;
}

template <class T>
void Stack<T>::print()
{
    Node<T> *aux = top;
    while (aux != NULL)
    {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return size == 0;
}
#endif