#ifndef PROJEKT1_DYNAMICARRAY_H
#define PROJEKT1_DYNAMICARRAY_H

#include <stdexcept>

namespace DataStructures
{
    const int DefaultCapacity = 4;
    const int CapacityMultiplier = 2;

    template<typename T>
    class DynamicArray
    {
    public:
        DynamicArray() : DynamicArray<T>(DefaultCapacity)
        {
        }

        explicit DynamicArray(int capacity) : capacity(capacity), length(0)
        {
            this->items = new T[this->capacity];
        }

        DynamicArray(const std::initializer_list<T> &initializerList) : DynamicArray(initializerList.size())
        {
            for (const auto &item: initializerList)
            {
                this->Add(item);
            }
        }

        DynamicArray(const DynamicArray<T> &list) : capacity(list.capacity), length(list.length)
        {
            this->items = new T[this->capacity];
            Copy(list.items, 0, this->items, 0, list.length);
        }

        ~DynamicArray()
        {
            delete[] this->items;
        }

        int GetLength() const
        {
            return this->length;
        }

        T operator[](int index) const
        {
            CheckIndex(index);
            return this->items[index];
        }

        T &operator[](int index)
        {
            CheckIndex(index);
            return this->items[index];
        }

        DynamicArray<T> &operator=(const DynamicArray<T> &array)
        {
            if (&array == this)
            {
                return *this;
            }

            if (array.capacity != this->capacity)
            {
                delete[] this->items;
                this->capacity = array.capacity;
                this->items = new T[this->capacity];
            }

            Copy(array.items, 0, this->items, 0, array.length);
            this->length = array.length;
            return *this;
        }

        DynamicArray<T> &operator=(const std::initializer_list<T> &initializerList)
        {
            if (this->capacity < initializerList.size())
            {
                delete[] this->items;
                if (initializerList.size() % 4 == 0)
                {
                    this->capacity = initializerList.size();
                }
                else
                {
                    this->capacity = DefaultCapacity;
                    while (this->capacity < initializerList.size())
                    {
                        this->capacity *= CapacityMultiplier;
                    }
                }

                this->items = new T[this->capacity];
            }

            int i = 0;
            for (const auto &item: initializerList)
            {
                this->items[i++] = item;
            }

            this->length = initializerList.size();
            return *this;
        }

        void Add(T item)
        {
            if (this->length == this->capacity)
            {
                IncreaseCapacity();
            }

            this->items[this->length++] = item;
        }

        void Insert(int index, T item)
        {
            CheckIndex(index);
            if (this->length == this->capacity)
            {
                this->capacity *= CapacityMultiplier;
                T *newItems = new T[this->capacity];
                if (index != 0)
                {
                    Copy(this->items, 0, newItems, 0, index);
                }

                newItems[index] = item;
                Copy(this->items, index, newItems, index + 1, this->length - index);
                delete[] this->items;
                this->items = newItems;
            }
            else
            {
                Copy(this->items, index, index + 1, this->length - index);
                this->items[index] = item;
            }

            this->length++;
        }

        bool Contains(T item) const
        {
            for (int i = 0; i < this->length; i++)
            {
                if (this->items[i] == item)
                {
                    return true;
                }
            }

            return false;
        }

        int IndexOf(T item) const
        {
            for (int i = 0; i < this->length; i++)
            {
                if (this->items[i] == item)
                {
                    return i;
                }
            }

            return -1;
        }

        int LastIndexOf(T item) const
        {
            for (int i = this->length - 1; i >= 0; i--)
            {
                if (this->items[i] == item)
                {
                    return i;
                }
            }

            return -1;
        }

        void Clear()
        {
            this->length = 0;
        }

        void RemoveAt(int index)
        {
            CheckIndex(index);
            if (index == this->length - 1)
            {
                return RemoveLast();
            }

            Copy(this->items, index + 1, index, this->length - index - 1);
            --this->length;
        }

        void RemoveFirst()
        {
            return RemoveAt(0);
        }

        void RemoveLast()
        {
            this->length--;
        }

    private:
        T *items;
        int length;
        int capacity;

        void IncreaseCapacity()
        {
            this->capacity *= CapacityMultiplier;
            T *newItems = new T[this->capacity];
            Copy(this->items, 0, newItems, 0, this->length);
            delete[] this->items;
            this->items = newItems;
        }

        void CheckIndex(int index) const
        {
            if (index < 0 || index >= this->length)
            {
                throw std::invalid_argument("Index is outside of the array");
            }
        }

        static void Copy(T *array, int sourceIndex, int destinationIndex, int count)
        {
            if (sourceIndex == destinationIndex)
            {
                return;
            }

            if (sourceIndex < destinationIndex)
            {
                for (int i = count - 1; i >= 0; i--)
                {
                    array[destinationIndex + i] = array[sourceIndex + i];
                }
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    array[destinationIndex + i] = array[sourceIndex + i];
                }
            }
        }

        static void Copy(T *sourceArray, int sourceIndex, T *destinationArray, int destinationIndex, int count)
        {
            if (sourceArray == destinationArray)
            {
                return Copy(sourceArray, sourceIndex, destinationIndex, count);
            }

            for (int i = 0; i < count; i++)
            {
                destinationArray[destinationIndex + i] = sourceArray[sourceIndex + i];
            }
        }
    };
}

#endif //PROJEKT1_DYNAMICARRAY_H
