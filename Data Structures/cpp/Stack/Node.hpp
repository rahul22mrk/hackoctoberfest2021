#pragma once
template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T data);
    Node(T data, Node<T> *next);
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T> *next)
{
    this->data = data;
    this->next = next;
}
