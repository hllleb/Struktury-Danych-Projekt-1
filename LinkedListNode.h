#ifndef PROJEKT1_LINKEDLISTNODE_H
#define PROJEKT1_LINKEDLISTNODE_H

#include <iostream>

namespace DataStructures
{
    template<typename T>
    class LinkedList;

    template<typename T>
    class LinkedListNode
    {
    public:
        static int NodesCount;

        friend class LinkedList<T>;

        LinkedListNode(T value) : LinkedListNode(nullptr, value)
        {
        }

        LinkedListNode(LinkedList<T> *list, T value) : list(list), item(value), previous(nullptr), next(nullptr)
        {
            std::cout << "Created " << this << " (Total count = " << ++LinkedListNode::NodesCount << ")" << std::endl;
        }

        ~LinkedListNode()
        {
            std::cout << "Deleted " << this << " (Total count = " << --LinkedListNode::NodesCount << ")" << std::endl;
        }

        T GetValue() const
        {
            return this->item;
        }

        void SetValue(T value)
        {
            this->item = value;
        }

        const LinkedListNode<T> *GetPrevious() const
        {
            return this->previous;
        }

        const LinkedListNode<T> *GetNext() const
        {
            return this->next;
        }

        const LinkedList<T> *GetList() const
        {
            return this->list;
        }

        LinkedListNode<T> *GetPrevious()
        {
            return this->previous;
        }

        LinkedListNode<T> *GetNext()
        {
            return this->next;
        }

        LinkedList<T> *GetList()
        {
            return this->list;
        }

    private:
        T item;
        LinkedListNode<T> *previous;
        LinkedListNode<T> *next;
        LinkedList<T> *list;
    };

    template <typename T>
    int LinkedListNode<T>::NodesCount = 0;
}

#endif //PROJEKT1_LINKEDLISTNODE_H
