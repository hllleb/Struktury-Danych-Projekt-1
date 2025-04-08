#include "DynamicArray.h"
#include "LinkedList.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;
using namespace DataStructures;

void SaveResults(const string& filename, const vector<pair<string, chrono::duration<double>>>& results)
{
    ofstream file(filename);
    file << "Operation,Time(seconds)" << endl;
    for (const auto& result : results)
    {
        file << result.first << "," << result.second.count() << endl;
    }
    file.close();
}

template<typename T>
void TestDynamicArray(int numElements, vector<pair<string, chrono::duration<double>>>& results)
{
    DynamicArray<T> array;

    // Test adding elements to the end
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        array.Add(i);
    }
    auto end = chrono::high_resolution_clock::now();
    results.push_back({"Adding to the end (" + to_string(numElements) + " elements)", end - start});

    DynamicArray<T> array2 = array;
    DynamicArray<T> array3 = array;
    DynamicArray<T> array4 = array;
    DynamicArray<T> array5 = array;

    // Test adding elements to the beginning
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        array.Insert(0, i);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Adding to the beginning (" + to_string(numElements) + " elements)", end - start});

    // Test adding elements to a given index
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        array2.Insert(array2.GetLength() / 2, i);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Adding to a given index (" + to_string(numElements) + " elements)", end - start});

    // Test removing elements from the end
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        array3.RemoveAt(array3.GetLength() - 1);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Removing from the end (" + to_string(numElements) + " elements)", end - start});

    // Test removing elements from the beginning
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        array4.RemoveAt(0);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Removing from the beginning (" + to_string(numElements) + " elements)", end - start});

    // Test removing elements from a given index
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        array5.RemoveAt(array5.GetLength() / 2);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Removing from a given index (" + to_string(numElements) + " elements)", end - start});

    // Test finding elements
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        array2.IndexOf(i);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Finding elements (" + to_string(numElements) + " elements)", end - start});
}

template<typename T>
void TestLinkedList(int numElements, vector<pair<string, chrono::duration<double>>>& results)
{
    LinkedList<T> list;

    // Test adding elements to the end
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        list.AddLast(i);
    }
    auto end = chrono::high_resolution_clock::now();
    results.push_back({"Adding to the end (" + to_string(numElements) + " elements)", end - start});

    LinkedList<T> list2 = list;
    LinkedList<T> list3 = list;
    LinkedList<T> list4 = list;

    // Test adding elements to the beginning
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        list.AddFirst(i);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Adding to the beginning (" + to_string(numElements) + " elements)", end - start});

    // Test adding elements to a given index
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        list2.AddAt(list2.GetCount() / 2, i);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Adding to a given index (" + to_string(numElements) + " elements)", end - start});

    // Test removing elements from the end
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        list2.RemoveLast();
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Removing from the end (" + to_string(numElements) + " elements)", end - start});

    // Test removing elements from the beginning
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        list3.RemoveFirst();
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Removing from the beginning (" + to_string(numElements) + " elements)", end - start});

    // Test removing elements from a given index
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        list4.RemoveAt(list4.GetCount() / 2);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Removing from a given index (" + to_string(numElements) + " elements)", end - start});

    // Test finding elements
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i)
    {
        list2.Find(i);
    }
    end = chrono::high_resolution_clock::now();
    results.push_back({"Finding elements (" + to_string(numElements) + " elements)", end - start});
}

int main()
{
    vector<int> testSizes = { 1, 10, 20, 40, 80, 100, 200, 400, 800, 1000, 1600, 3200, 6400, 10000, 12800, 25600, 51200, 102400 };
    vector<pair<string, chrono::duration<double>>> dynamicArrayResults;
    vector<pair<string, chrono::duration<double>>> linkedListResults;

    // Test DynamicArray
    for (int size : testSizes)
    {
        TestDynamicArray<int>(size, dynamicArrayResults);
    }

    auto comp = [](const pair<string, chrono::duration<double>>& a, const pair<string, chrono::duration<double>>& b) {
        auto aLeftIndex = a.first.find('(');
        auto aRightIndex = a.first.find(')');
        auto bLeftIndex = b.first.find('(');
        auto bRightIndex = b.first.find(')');

        auto aCountStr = (a.first.substr(aLeftIndex + 1, aRightIndex - aLeftIndex - 10));
        auto bCountStr = (b.first.substr(bLeftIndex + 1, bRightIndex - bLeftIndex - 10));
        auto aCount = stoi(aCountStr);
        auto bCount = stoi(bCountStr);

        auto aOperation = a.first.substr(0, aLeftIndex - 1);
        auto bOperation = b.first.substr(0, bLeftIndex - 1);

        if(aOperation == bOperation)
        {
            return aCount < bCount;
        }

        return aOperation < bOperation;
    };

    sort(dynamicArrayResults.begin(), dynamicArrayResults.end(), comp);
    SaveResults("DynamicArrayResults6.csv", dynamicArrayResults);

    // Test LinkedList
    for (int size : testSizes)
    {
        TestLinkedList<int>(size, linkedListResults);
    }

    sort(linkedListResults.begin(), linkedListResults.end(), comp);
    SaveResults("LinkedListResults6.csv", linkedListResults);



    return 0;
}