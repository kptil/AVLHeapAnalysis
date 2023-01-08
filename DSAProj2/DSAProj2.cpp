#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <chrono>
#include "AVLTree.h"
#include "MinHeap.h"

using namespace std;
using namespace std::chrono;

/*
* Citation: The method for randomly shuffling a vector of integers is taken from an answer to this
* Stack Overflow question: https://stackoverflow.com/questions/41491141/c-random-number-duplicate-prevent
* Citation: I relied on this Geeks for Geeks article to learn how to use the chrono library: 
* https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
*/

vector<int> TestTree(AVLTree& tree, vector<int>& data);
vector<int> TestHeap(MinHeap& heap, vector<int>& data);
int main()
{
    /*==== Creates 9 Test Files ====*/
    ofstream fileOut1;
    fileOut1.open("small_ascending.txt");
    if (fileOut1.is_open()) {
        for (int i = 1; i <= 500; i++) {
            fileOut1 << i << endl;
        }
        fileOut1.close();
    }
    else { cout << "file 1 not open" << endl; }

    ofstream fileOut2;
    fileOut2.open("small_descending.txt");
    if (fileOut2.is_open()) {
        for (int i = 500; i > 0; i--) {
            fileOut2 << i << endl;
        }
        fileOut2.close();
    }
    else { cout << "file 2 not open" << endl; }

    ofstream fileOut3;
    fileOut3.open("small_random.txt");
    if (fileOut3.is_open()) {
        vector<int> vec;
        for (int i = 1; i <= 500; i++) {
            vec.push_back(i);
        }
        random_device rd;
        mt19937 rng(rd());
        shuffle(vec.begin(), vec.end(), rng);
        for (int i = 0; i < vec.size(); i++) {
            fileOut3 << vec[i] << endl;
        }
        fileOut3.close();
    }
    else { cout << "file 3 not open" << endl; }

    ofstream fileOut4;
    fileOut4.open("medium_ascending.txt");
    if (fileOut4.is_open()) {
        for (int i = 1; i <= 5000; i++) {
            fileOut4 << i << endl;
        }
        fileOut4.close();
    }
    else { cout << "file 4 not open" << endl; }

    ofstream fileOut5;
    fileOut5.open("medium_descending.txt");
    if (fileOut5.is_open()) {
        for (int i = 5000; i > 0; i--) {
            fileOut5 << i << endl;
        }
        fileOut5.close();
    }
    else { cout << "file 5 not open" << endl; }

    ofstream fileOut6;
    fileOut6.open("medium_random.txt");
    if (fileOut6.is_open()) {
        vector<int> vec;
        for (int i = 1; i <= 5000; i++) {
            vec.push_back(i);
        }
        random_device rd;
        mt19937 rng(rd());
        shuffle(vec.begin(), vec.end(), rng);
        for (int i = 0; i < vec.size(); i++) {
            fileOut6 << vec[i] << endl;
        }
        fileOut6.close();
    }
    else { cout << "file 6 not open" << endl; }

    ofstream fileOut7;
    fileOut7.open("large_ascending.txt");
    if (fileOut7.is_open()) {
        for (int i = 1; i <= 50000; i++) {
            fileOut7 << i << endl;
        }
        fileOut7.close();
    }
    else { cout << "file 7 not open" << endl; }

    ofstream fileOut8;
    fileOut8.open("large_descending.txt");
    if (fileOut8.is_open()) {
        for (int i = 50000; i > 0; i--) {
            fileOut8 << i << endl;
        }
        fileOut8.close();
    }
    else { cout << "file 8 not open" << endl; }

    ofstream fileOut9;
    fileOut9.open("large_random.txt");
    if (fileOut9.is_open()) {
        vector<int> vec;
        for (int i = 1; i <= 50000; i++) {
            vec.push_back(i);
        }
        random_device rd;
        mt19937 rng(rd());
        shuffle(vec.begin(), vec.end(), rng);
        for (int i = 0; i < vec.size(); i++) {
            fileOut9 << vec[i] << endl;
        }
        fileOut9.close();
    }
    else { cout << "file 9 not open" << endl; }

    AVLTree tree;
    MinHeap heap;
    vector<int> data;
    string i;

    /*==== Small Ascending Tests ====*/
    
    ifstream myFile1("small_ascending.txt");
    if (myFile1.is_open()) {
        while (getline(myFile1, i)) {
            data.push_back(stoi(i));
        }
        myFile1.close();
    }

    // vector order is always insert, traverse, delete
    cout << "Testing Tree Small Ascending" << endl;
    vector<int> timesTreeSA = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Small Ascending" << endl;
    vector<int> timesHeapSA = TestHeap(heap, data);
    cout << endl;

    data.clear();

    /*==== Medium Ascending Tests ====*/
    ifstream myFile2("medium_ascending.txt");
    if (myFile2.is_open()) {
        while (getline(myFile2, i)) {
            data.push_back(stoi(i));
        }
        myFile2.close();
    }

    cout << "Testing Tree Medium Ascending" << endl;
    vector<int> timesTreeMA = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Medium Ascending" << endl;
    vector<int> timesHeapMA = TestHeap(heap, data);
    cout << endl;

    data.clear();

    /*==== Large Ascending Tests ====*/
    ifstream myFile3("large_ascending.txt");
    if (myFile3.is_open()) {
        while (getline(myFile3, i)) {
            data.push_back(stoi(i));
        }
        myFile3.close();
    }

    cout << "Testing Tree Large Ascending" << endl;
    vector<int> timesTreeLA = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Large Ascending" << endl;
    vector<int> timesHeapLA = TestHeap(heap, data);
    cout << endl;

    data.clear();

    /*==== Small Descending Tests ====*/
    ifstream myFile4("small_descending.txt");
    if (myFile4.is_open()) {
        while (getline(myFile4, i)) {
            data.push_back(stoi(i));
        }
        myFile4.close();
    }

    cout << "Testing Tree Small Descending" << endl;
    vector<int> timesTreeSD = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Small Descending" << endl;
    vector<int> timesHeapSD = TestHeap(heap, data);
    cout << endl;

    data.clear();

    /*==== Medium Descending Tests ====*/
    ifstream myFile5("medium_descending.txt");
    if (myFile5.is_open()) {
        while (getline(myFile5, i)) {
            data.push_back(stoi(i));
        }
        myFile5.close();
    }

    cout << "Testing Tree Medium Descending" << endl;
    vector<int> timesTreeMD = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Medium Descending" << endl;
    vector<int> timesHeapMD = TestHeap(heap, data);
    cout << endl;

    data.clear();

    /*==== Large Descending Tests ====*/
    ifstream myFile6("large_descending.txt");
    if (myFile6.is_open()) {
        while (getline(myFile6, i)) {
            data.push_back(stoi(i));
        }
        myFile6.close();
    }

    cout << "Testing Tree Large Descending" << endl;
    vector<int> timesTreeLD = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Large Descending" << endl;
    vector<int> timesHeapLD = TestHeap(heap, data);
    cout << endl;

    data.clear();

    /*==== Small Random Tests ====*/
    ifstream myFile7("small_random.txt");
    if (myFile7.is_open()) {
        while (getline(myFile7, i)) {
            data.push_back(stoi(i));
        }
        myFile7.close();
    }

    cout << "Testing Tree Small Random" << endl;
    vector<int> timesTreeSR = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Small Random" << endl;
    vector<int> timesHeapSR = TestHeap(heap, data);
    cout << endl;

    data.clear();

    /*==== Medium Random Tests ====*/
    ifstream myFile8("medium_random.txt");
    if (myFile8.is_open()) {
        while (getline(myFile8, i)) {
            data.push_back(stoi(i));
        }
        myFile8.close();
    }

    cout << "Testing Tree Medium Random" << endl;
    vector<int> timesTreeMR = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Medium Random" << endl;
    vector<int> timesHeapMR = TestHeap(heap, data);
    cout << endl;

    data.clear();

    /*==== Large Random Tests ====*/
    ifstream myFile9("large_random.txt");
    if (myFile9.is_open()) {
        while (getline(myFile9, i)) {
            data.push_back(stoi(i));
        }
        myFile9.close();
    }

    cout << "Testing Tree Large Random" << endl;
    vector<int> timesTreeLR = TestTree(tree, data);
    cout << endl;

    cout << "Testing Heap Large Random" << endl;
    vector<int> timesHeapLR = TestHeap(heap, data);
    cout << endl;

    data.clear();

     //Final Stats Print
    cout << "Data Structure 1: AVL Tree" << endl;
    cout << "Small Ascending: " << endl;
    cout << "Insert: " << timesTreeSA[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeSA[1] << " ms" << endl;
    cout << "Delete: " << timesTreeSA[2] << " ms" << endl;
    cout << "Medium Ascending: " << endl;
    cout << "Insert: " << timesTreeMA[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeMA[1] << " ms" << endl;
    cout << "Delete: " << timesTreeMA[2] << " ms" << endl;
    cout << "Large Ascending: " << endl;
    cout << "Insert: " << timesTreeLA[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeLA[1] << " ms" << endl;
    cout << "Delete: " << timesTreeLA[2] << " ms" << endl;
    cout << "Small Descending: " << endl;
    cout << "Insert: " << timesTreeSD[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeSD[1] << " ms" << endl;
    cout << "Delete: " << timesTreeSD[2] << " ms" << endl;
    cout << "Medium Descending: " << endl;
    cout << "Insert: " << timesTreeMD[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeMD[1] << " ms" << endl;
    cout << "Delete: " << timesTreeMD[2] << " ms" << endl;
    cout << "Large Descending: " << endl;
    cout << "Insert: " << timesTreeLD[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeLD[1] << " ms" << endl;
    cout << "Delete: " << timesTreeLD[2] << " ms" << endl;
    cout << "Small Random: " << endl;
    cout << "Insert: " << timesTreeSR[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeSR[1] << " ms" << endl;
    cout << "Delete: " << timesTreeSR[2] << " ms" << endl;
    cout << "Medium Random: " << endl;
    cout << "Insert: " << timesTreeMR[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeMR[1] << " ms" << endl;
    cout << "Delete: " << timesTreeMR[2] << " ms" << endl;
    cout << "Large Random: " << endl;
    cout << "Insert: " << timesTreeLR[0] << " ms" << endl;
    cout << "Traverse: " << timesTreeLR[1] << " ms" << endl;
    cout << "Delete: " << timesTreeLR[2] << " ms" << endl;
    cout << endl;

    cout << "Data Structure 2: Min Heap" << endl;
    cout << "Small Ascending: " << endl;
    cout << "Insert: " << timesHeapSA[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapSA[1] << " ms" << endl;
    cout << "Delete: " << timesHeapSA[2] << " ms" << endl;
    cout << "Medium Ascending: " << endl;
    cout << "Insert: " << timesHeapMA[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapMA[1] << " ms" << endl;
    cout << "Delete: " << timesHeapMA[2] << " ms" << endl;
    cout << "Large Ascending: " << endl;
    cout << "Insert: " << timesHeapLA[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapLA[1] << " ms" << endl;
    cout << "Delete: " << timesHeapLA[2] << " ms" << endl;
    cout << "Small Descending: " << endl;
    cout << "Insert: " << timesHeapSD[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapSD[1] << " ms" << endl;
    cout << "Delete: " << timesHeapSD[2] << " ms" << endl;
    cout << "Medium Descending: " << endl;
    cout << "Insert: " << timesHeapMD[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapMD[1] << " ms" << endl;
    cout << "Delete: " << timesHeapMD[2] << " ms" << endl;
    cout << "Large Descending: " << endl;
    cout << "Insert: " << timesHeapLD[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapLD[1] << " ms" << endl;
    cout << "Delete: " << timesHeapLD[2] << " ms" << endl;
    cout << "Small Random: " << endl;
    cout << "Insert: " << timesHeapSR[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapSR[1] << " ms" << endl;
    cout << "Delete: " << timesHeapSR[2] << " ms" << endl;
    cout << "Medium Random: " << endl;
    cout << "Insert: " << timesHeapMR[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapMR[1] << " ms" << endl;
    cout << "Delete: " << timesHeapMR[2] << " ms" << endl;
    cout << "Large Random: " << endl;
    cout << "Insert: " << timesHeapLR[0] << " ms" << endl;
    cout << "Traverse: " << timesHeapLR[1] << " ms" << endl;
    cout << "Delete: " << timesHeapLR[2] << " ms" << endl;

    return 0;
}

vector<int> TestTree(AVLTree& tree, vector<int>& data) {
    vector<int> timesTree;
    auto start = high_resolution_clock::now();
    for (int i : data) {
        tree.insert(i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    timesTree.push_back(duration.count());
    cout << "Insert: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    tree.traverseLevelOrder();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    timesTree.push_back(duration.count());
    cout << "Traverse: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < data.size(); i++) {
        tree.remove();
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    timesTree.push_back(duration.count());
    cout << "Delete: " << duration.count() << " ms" << endl;

    return timesTree;
}

vector<int> TestHeap(MinHeap& heap, vector<int>& data) {
    vector<int> timesHeap;
    auto start = high_resolution_clock::now();
    for (int i : data) {
        heap.insert(i);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    timesHeap.push_back(duration.count());
    cout << "Insert: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    heap.traverse();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    timesHeap.push_back(duration.count());
    cout << "Traverse: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    for (int i = 0; i < data.size(); i++) {
        heap.remove();
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    timesHeap.push_back(duration.count());
    cout << "Delete: " << duration.count() << " ms" << endl;

    return timesHeap;
}

