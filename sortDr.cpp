// This program is a sorting algorithm tester.

// Input are sorting algorithm names plus Refresh for resetting the
//   values to be sorted to their previous values and Reinitialize for
//   creating a new set of values.
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <stdlib.h>
const int SIZE = 50;
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2.h"
#include "BubbleSort.h"
#include "ShortBubble.h"
#include "HeapSort.h"

using namespace std;
typedef int ItemType;

// SIZE should be a multiple of 10.

void Print(ofstream&, int[]);	// Prints array
void InitValues(int[]);			// Creates random array 
void CopyValues(int[], int[]);	// Makes a copy of random array


int main()
{
    chrono::time_point<chrono::system_clock> start;
    chrono::time_point<chrono::system_clock> end;

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  ItemType values[SIZE];
  int numCommands;
  ItemType copyValues[SIZE];

 
  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;
  InitValues(values);
  CopyValues(values, copyValues);
  outFile << "Initial values" << endl;
  Print(outFile, values);

  numCommands = 0;
  while (command != "Quit")
  { 
    if (command == "SelectionSort")
    {
        start = chrono::system_clock::now();           // Record start time
        SelectionSort(values, SIZE-1);
        end = chrono::system_clock::now();             // Record end time
        chrono::duration<float> elapsed = end-start;   // Calculate and report time
      outFile << "Results from SelectionSort: " << endl;
      outFile << "(Execution time in seconds = " << elapsed.count() << ")" << "\n";
      Print(outFile, values);
      outFile << endl;
    }
    else if (command == "BubbleSort")
    {
        start = chrono::system_clock::now();           // Record start time
      BubbleSort(values, SIZE-1);
        end = chrono::system_clock::now();             // Record end time
        chrono::duration<float> elapsed = end-start;   // Calculate and report time
      outFile << "Results from BubbleSort: " << endl;
        outFile << "(Execution time in seconds = " << elapsed.count() << ")" << "\n";
      Print(outFile, values);
      outFile << endl;
    }
    else if (command == "ShortBubble")
    {
        start = chrono::system_clock::now();           // Record start time
      ShortBubble(values, SIZE-1);
        end = chrono::system_clock::now();             // Record end time
        chrono::duration<float> elapsed = end-start;   // Calculate and report time
      outFile << "Results from ShortBubble: " << endl;
        outFile << "(Execution time in seconds = " << elapsed.count() << ")" << "\n";
      Print(outFile, values);
      outFile << endl;
    } 
    else if (command == "MergeSort")
    {
        start = chrono::system_clock::now();           // Record start time
      MergeSort(values, 0,  SIZE-1);
        end = chrono::system_clock::now();             // Record end time
        chrono::duration<float> elapsed = end-start;   // Calculate and report time
      outFile << "Results from MergeSort: " << endl;
        outFile << "(Execution time in seconds = " << elapsed.count() << ")" << "\n";
      Print(outFile, values);
      outFile << endl;
    }  
    else if (command == "QuickSort")
    {
        start = chrono::system_clock::now();           // Record start time
      QuickSort(values,  0, SIZE-1);
        end = chrono::system_clock::now();             // Record end time
        chrono::duration<float> elapsed = end-start;   // Calculate and report time
      outFile << "Results from QuickSort: " << endl;
        outFile << "(Execution time in seconds = " << elapsed.count() << ")" << "\n";
      Print(outFile, values);
      outFile << endl;
    }
    else if (command == "QuickSort2") 
    {
        start = chrono::system_clock::now();           // Record start time
      QuickSort2(values, 0,  SIZE-1);
        end = chrono::system_clock::now();             // Record end time
        chrono::duration<float> elapsed = end-start;   // Calculate and report time
      outFile << "Results from QuickSort2: " << endl;
        outFile << "(Execution time in seconds = " << elapsed.count() << ")" << "\n";
      Print(outFile, values);
      outFile << endl;
    }
     else if (command == "InsertionSort")
    {
        start = chrono::system_clock::now();           // Record start time
      InsertionSort(values,  SIZE-1);
        end = chrono::system_clock::now();             // Record end time
        chrono::duration<float> elapsed = end-start;   // Calculate and report time
      outFile << "Results from InsertionSort: " << endl;
        outFile << "(Execution time in seconds = " << elapsed.count() << ")" << "\n";
      Print(outFile, values);
      outFile << endl;
    }
    else if (command == "HeapSort")
    {
        start = chrono::system_clock::now();           // Record start time
      HeapSort(values, SIZE);
        end = chrono::system_clock::now();             // Record end time
        chrono::duration<float> elapsed = end-start;   // Calculate and report time
      outFile << "Results from HeapSort: " << endl;
        outFile << "(Execution time in seconds = " << elapsed.count() << ")" << "\n";
      Print(outFile, values);
      outFile << endl;
    }  
    else if (command ==  "Refresh")

      CopyValues(copyValues, values);
    else if (command == "ReInitialize")
    {
      InitValues(values);
      CopyValues(values, copyValues);
      outFile << endl << "Initial Values: " << endl;
      Print(outFile, values);
    }  
    else
      outFile << "Input not recognized." << endl;  
      
    numCommands++;
    cout <<  " Command " << command << " completed." 
         << endl;
    inFile >> command;

  }
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
}

void InitValues(int values[])
// initializes the values array with random integers from 0 to 99
{
  for (int index = 0; index < SIZE; index++)
    values[index] = (std::rand() % 1000);  
}

void Print(ofstream& outFile, int values[])
{
  using namespace std;
  for (int count = 0; count < SIZE; count= count+10)
    outFile << values[count]  << ", " << values[count+1] << ", " << values[count+2] << ", " 
    << values[count+3] << ", " << values[count+4] << ", " << values[count+5] << ", " 
    << values[count+6] << ", " << values[count + 7] << ", " << values[count + 8] 
    << ", " << values[count+9] << endl << endl;
    
}      


void CopyValues(int inData[], int outData[])
{
  for (int count = 0; count < SIZE; count++)
    outData[count] = inData[count];
}    
