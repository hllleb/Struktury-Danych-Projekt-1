#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include <string>

using namespace DataStructures;

template <typename T>
void Display(const DynamicArray<T>& array)
{
    for(int i = 0; i < array.GetLength(); i++)
    {
        std::cout << array[i] << ' ';
    }

    std::cout << std::endl;
}

template <typename T>
void Display(const LinkedList<T>& list)
{
    auto node = list.GetFirst();
    while(node != nullptr)
    {
        std::cout << node->GetValue() << ' ';
        node = node->GetNext();
        if(node == list.GetFirst())
        {
            node = nullptr;
        }
    }

    std::cout << std::endl;
}

int main()
{
    DynamicArray<int> array;



    array.Add(5);
    array.Add(-212);
    array.Add(51);
    array.Add(0);
    array.Add(10);
    std::cout << "Array: \t";
    Display(array);
    array.Insert(3, -100);
    std::cout << "Insert(3, -100): \t";
    Display(array);
    array.Insert(5, 500);
    std::cout << "Insert(5, 500): \t";
    Display(array);
    array.Insert(0, -999);
    std::cout << "Insert(0, -999): \t";
    Display(array);


    array.RemoveAt(3);
    Display(array);
    array.RemoveAt(0);
    Display(array);
    array.RemoveLast();
    Display(array);
    array.Add(10000);
    Display(array);


    DynamicArray array2 = { 1, 2, 3, 4, 5 };
    Display(array2);
    array2 = array;
    array[0] = 4238952;
    Display(array);
    array2 = array2;
    Display(array2);

    array = { 5, -4, 0, 2, 1 };
    Display(array);

    DynamicArray stringArray = { "Hello", "my", "World", "!", "!", "and", "you" };
    Display(stringArray);
    stringArray.RemoveAt(4);
    stringArray.RemoveAt(1);
    stringArray.Add("!");
    stringArray.RemoveAt(2);
    Display(stringArray);







    LinkedList<int> list;
    list.AddFirst(1);
    list.AddFirst(2);
    list.AddFirst(3);
    list.AddFirst(4);
    list.AddFirst(5);
    list.AddFirst(6);

    Display(list);

    list.AddLast(7);
    list.AddLast(8);
    list.AddLast(9);
    list.AddLast(10);
    list.AddLast(11);

    auto node = list.GetFirst();
    node = node->GetNext()->GetNext()->GetNext();
    list.AddBefore(node, 100);
    std::cout << "Item: " << node->GetValue() << std::endl;
    list.AddAfter(node, -999);
    Display(list);


    DynamicArray<int> newarr = array;
    Display(newarr);


    auto listArray = list.ToArray();
    listArray.Insert(3, 555);
    listArray.RemoveAt(5);
    Display(listArray);
    std::cout << "===================================" << std::endl;
    Display(list);
    std::cout << "Count = " << list.GetCount() << std::endl;
    list.AddAt(3, 4732);
    Display(list);
    std::cout << "Count = " << list.GetCount() << std::endl;
    list.RemoveAt(1);
    Display(list);
    std::cout << "Count = " << list.GetCount() << std::endl;

    LinkedList<const char*> stringList;
    stringList.AddLast("time");
    Display(stringList);
    stringList.AddLast("the");
    Display(stringList);
    stringList.AddLast("apple");
    Display(stringList);
    stringList.AddFirst("new");
    Display(stringList);
    stringList.AddAt(1, "hope");
    Display(stringList);
    stringList.AddAt(0, "name");
    Display(stringList);
    stringList.RemoveAt(3);
    Display(stringList);
    stringList.RemoveLast();
    Display(stringList);
    stringList.RemoveFirst();
    Display(stringList);

    return 0;
}