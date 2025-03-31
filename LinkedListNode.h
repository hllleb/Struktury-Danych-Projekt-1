#ifndef PROJEKT1_LINKEDLISTNODE_H
#define PROJEKT1_LINKEDLISTNODE_H

#include <iostream>

namespace DataStructures
{
    /// \brief Represents a circular doubly-linked list
    /// \tparam T Type parameter
    template<typename T>
    class LinkedList;

    /// \brief Represents a linked list node
    /// \tparam T Type parameter
    template<typename T>
    class LinkedListNode
    {
    public:
        static int NodesCount;

        friend class LinkedList<T>;

        /// \brief Constructs a linked list node containing the given \p value
        /// \param value A value for the new node
        LinkedListNode(T value) : LinkedListNode(nullptr, value)
        {
        }

        /// \brief Constructs a linked list node containing the given \p value with a reference to the \p list
        /// \param list A linked list to which the reference is added
        /// \param value A value for the new node
        LinkedListNode(LinkedList<T> *list, T value) : list(list), item(value), previous(nullptr), next(nullptr)
        {
            std::cout << "Created " << this << " (Total count = " << ++LinkedListNode::NodesCount << ")" << std::endl;
        }

        /// \brief Destructs the node
        ~LinkedListNode()
        {
            std::cout << "Deleted " << this << " (Total count = " << --LinkedListNode::NodesCount << ")" << std::endl;
        }

        /// \brief Returns the value of the node
        /// \return The value that the node contains
        T GetValue() const
        {
            return this->item;
        }

        /// \brief Sets the new \p value of the node
        /// \param value A value to replace the current one with
        void SetValue(T value)
        {
            this->item = value;
        }

        /// \brief Returns a pointer to the previous node
        /// \return A pointer to the previous node
        const LinkedListNode<T> *GetPrevious() const
        {
            return this->previous;
        }

        /// \brief Returns a pointer to the next node
        /// \return A pointer to the next node
        const LinkedListNode<T> *GetNext() const
        {
            return this->next;
        }

        /// \brief Returns a pointer to the list containing the node
        /// \return A pointer to the list containing the node
        const LinkedList<T> *GetList() const
        {
            return this->list;
        }

        /// \brief Returns a pointer to the previous node
        /// \return A pointer to the previous node
        LinkedListNode<T> *GetPrevious()
        {
            return this->previous;
        }

        /// \brief Returns a pointer to the next node
        /// \return A pointer to the next node
        LinkedListNode<T> *GetNext()
        {
            return this->next;
        }

        /// \brief Returns a pointer to the list containing the node
        /// \return A pointer to the list containing the node
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
