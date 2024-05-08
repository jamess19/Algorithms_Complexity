#pragma once
#define MAX 1000
#include <iostream>
#include <iomanip> 
#include <stdlib.h>
#include<random>
using namespace std;


// Ước lượng độ phức tạp thuật toán
// (i)
int sumHalf(int n);
int sumHalf(int n, int& count_comparisons, int& count_assignments);

// (ii)
int recursiveSquareSum(int n);
int recursiveSquareSum(int n, int& cmp, int& asgm);

//Thiết kế giải thuật
// (i)
int gcd(int u, int v);
int gcd(int u, int v, int& assignments, int& comparisons);
int gcdEuclid(int u, int v);
int gcdEuclid(int u, int v, int& assignments, int& comparisons);

// (ii)
int longestNonDecreasingSubsequenceLength1(int* a, int n);
int longestNonDecreasingSubsequenceLength1(int a[], int n, int& count_assignments, int& count_comparisons);
int longestNonDecreasingSubsequenceLength2(int* a, int n);
int longestNonDecreasingSubsequenceLength2(int a[], int n, int& count_assignments, int& count_comparisons);

// (iii)
int generateRandomNumber(int min, int max);
void heapify(vector<int>& arr, int n, int i, int& cmp, int& asgm);
void heapSort(vector<int>& arr, int n, int& cmp, int& asgm);
vector<int> findMedian(vector<int> a, int n, int& cmp, int& asgm);
vector<int> findMedian_optimize(vector<int> a, int n, int& cmp, int& asgm);

// (iv)
void nhapMang(int arr[], int n);
void xuatMang(int arr[], int n);

int paradoxicalNum1(int arr[], int n);
long long merge(int arr[], int left, int mid, int right);
long long mergesort(int arr[], int left, int right);
long long paradoxicalnum2(int arr[], int n);

int paradoxicalNum1(int arr[], int n, int& count_assignments, int& count_comparisons);
long long merge(int arr[], int left, int mid, int right, int& count_assignments, int& count_comparisons);
long long mergesort(int arr[], int left, int right, int& count_assignments, int& count_comparisons);
long long paradoxicalnum2(int arr[], int n, int& count_assignments, int& count_comparisons);

