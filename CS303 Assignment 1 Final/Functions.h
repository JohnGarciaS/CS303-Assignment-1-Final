#pragma once
#include <iostream>
using namespace std;

void menu();

int search(int arr[], int user_size, int x);

void modify(int arr[], int low, int high);

void insertElement(int arr[], int user_size);

void deleteInt(int arr[], int userindex, int user_size);

void replaceElement(int arr[], int userIndex, char userChoice, int size);

void printArray(int arr[], int user_size);
