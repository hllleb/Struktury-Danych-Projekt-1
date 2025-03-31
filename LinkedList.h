#ifndef PROJEKT1_LINKEDLIST_H
#define PROJEKT1_LINKEDLIST_H

#include "LinkedListNode.h"

namespace DataStructures
{
    template <typename T>
    class LinkedList
    {
    public:
        LinkedList() : head(nullptr), count(0)
        {
        }

        ~LinkedList()
        {
            this->FreeMemory();
        }

        const LinkedListNode<T> *GetFirst() const
        {
            return this->head;
        }

        const LinkedListNode<T> *GetLast() const
        {
            return this->head == nullptr ? nullptr : this->head->previous;
        }

        LinkedListNode<T> *GetFirst()
        {
            return this->head;
        }

        LinkedListNode<T> *GetLast()
        {
            return this->head == nullptr ? nullptr : this->head->previous;
        }

        int GetCount() const
        {
            return this->count;
        }

        void AddAt(int index, T value)
        {
            if(index >= this->count)
            {
                throw std::invalid_argument("Index is outside the list");
            }

            if(index == 0)
            {
                this->AddFirst(value);
            }

            auto node = this->head;
            for(int i = 0; i < index; i++)
            {
                node = node->next;
            }

            AddBefore(node, value);
        }

        void RemoveAt(int index)
        {
            if(index >= this->count)
            {
                throw std::invalid_argument("Index is outside the list");
            }

            if(index == 0)
            {
                this->RemoveFirst();
            }

            auto node = this->head;
            for(int i = 0; i < index; i++)
            {
                node = node->next;
            }

            Remove(node);
            --this->count;
        }

        void AddFirst(T value)
        {
            auto node = new LinkedListNode(this, value);
            if (this->IsEmpty())
            {
                this->head = node;
                this->head->previous = this->head->next = this->head;
            }
            else
            {
                AddBefore(this->head, node);
                this->head = node;
            }

            this->count++;
        }

        void AddLast(T value)
        {
            auto node = new LinkedListNode(this, value);
            if (this->IsEmpty())
            {
                this->head = node;
                this->head->previous = this->head->next = this->head;
            }
            else
            {
                AddBefore(this->head, node);
            }

            this->count++;
        }

        void AddBefore(LinkedListNode<T> *node, T value)
        {
            if (node == nullptr || node->GetList() != this)
            {
                throw std::exception();
            }

            auto newNode = new LinkedListNode(this, value);
            AddBefore(node, newNode);
            this->count++;
        }

        void AddAfter(LinkedListNode<T> *node, T value)
        {
            if (node == nullptr || node->GetList() != this)
            {
                throw std::exception();
            }

            auto newNode = new LinkedListNode(this, value);
            AddAfter(node, newNode);
            this->count++;
        }

        void Clear()
        {
            this->FreeMemory();
            this->count = 0;
            this->head = nullptr;
        }

        void RemoveFirst()
        {
            if (this->IsEmpty())
            {
                throw std::exception();
            }

            auto secondNode = this->head->next;
            auto lastNode = this->head->previous;
            Remove(this->head);
            --this->count;

            if (this->count > 0)
            {
                lastNode->next = secondNode;
                secondNode->previous = lastNode;
                this->head = secondNode;
            }
            else
            {
                this->head = nullptr;
            }
        }

        void RemoveLast()
        {
            if (this->IsEmpty())
            {
                throw std::exception();
            }

            auto lastPreviousNode = this->GetLast()->previous;
            Remove(this->GetLast());
            --this->count;

            if (this->count > 0)
            {
                lastPreviousNode->next = this->head;
                this->head->previous = lastPreviousNode;
            }
            else
            {
                this->head = nullptr;
            }
        }

        bool Contains(T value) const
        {
            LinkedListNode<T> *node = this->head;
            for (int i = 0; i < this->count; i++)
            {
                if (node->item == value)
                {
                    return true;
                }

                node = node->next;
            }

            return false;
        }

        bool IsEmpty() const
        {
            return this->head == nullptr;
        }

        DynamicArray<T> ToArray() const
        {
            int capacity = 4;
            while (capacity < this->count)
            {
                capacity *= 2;
            }

            DynamicArray<T> array(capacity);
            auto node = this->head;
            for (int i = 0; i < this->count; i++)
            {
                array.Add(node->item);
                node = node->next;
            }

            return array;
        }

    private:
        LinkedListNode<T> *head;
        int count;

        void FreeMemory()
        {
            if (this->IsEmpty())
            {
                return;
            }

            auto node = this->head;
            auto nextNode = node->next;
            for (int i = 0; i < this->count; i++)
            {
                delete node;
                node = nextNode;
                nextNode = node->next;
            }
        }

        static void AddBefore(LinkedListNode<T> *node, LinkedListNode<T> *newNode)
        {
            newNode->next = node;
            newNode->previous = node->previous;
            node->previous->next = newNode;
            node->previous = newNode;
        }

        static void AddAfter(LinkedListNode<T> *node, LinkedListNode<T> *newNode)
        {
            newNode->previous = node;
            newNode->next = node->next;
            node->next->previous = newNode;
            node->next = newNode;
        }

        static void Remove(LinkedListNode<T> *node)
        {
            node->next->previous = node->previous;
            node->previous->next = node->next;
            delete node;
        }
    };
}

#endif //PROJEKT1_LINKEDLIST_H
