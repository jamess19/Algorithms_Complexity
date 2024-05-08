#include"func.h"

// Ước lượng độ phức tạp thuật toán
// ý (i)
int sumHalf(int n)
{
    int a = 0; 
    int i = n; 
    while ( i > 0)
    {
        a = a + i;
        i = i / 2;
    }
    return a;
}
// Sau khi thêm biến đếm
int sumHalf(int n, int& count_comparisons, int& count_assignments)
{
    count_comparisons = 0;
    count_assignments = 0;

    int a = 0; count_assignments++;
    int i = n; count_assignments++;
    while (++count_comparisons && i > 0)
    {
        a = a + i;
        count_assignments++;
        i = i / 2;
        count_assignments++;
    }
    return a;
}

// ý (ii)
int recursiveSquareSum(int n) {
    if (n < 1) return 0;
    return n * n + recursiveSquareSum(n - 1);
}
// sau khi thêm biến đếm
int recursiveSquareSum(int n, int& cmp, int& asgm) {
    if (++cmp && n < 1) return 0;
    ++asgm;
    return n * n + recursiveSquareSum(n - 1, cmp, asgm);
}

// Thiết kế giải thuật

// Thuật toán 1: Không tối ưu
int gcd(int u, int v) {
    int gcd = 1;
    int limit = min(u, v);
    for (int i = 2; i <= limit; i++) {
        if (u % i == 0 && v % i == 0) {
            gcd = i;;
        }
    }
    return gcd;
}

// Sau khi chèn biến đếm
int gcd(int u, int v, int& assignments, int& comparisons) {
    assignments = 0;
    comparisons = 0;
    int gcd = 1; assignments++;
    int limit = min(u, v); assignments++;
    int i = 2; assignments++;
    for (; ++comparisons && i <= limit; i++) {
        assignments++;
        if ((++comparisons && u % i == 0) && (++comparisons && v % i == 0)) {
            gcd = i;
            assignments++;
        }
    }
    return gcd;
}

//Thuật toán 2: Tối ưu hơn
int gcdEuclid(int u, int v) {
    while (v != 0) {
        int temp = u % v;
        u = v;
        v = temp;
    }
    return u;
}
// Sau khi chèn biến đếm
int gcdEuclid(int u, int v, int& assignments, int& comparisons) {
    assignments = 0;
    comparisons = 0;

    while ((++comparisons) && v != 0) {
        int temp = u % v;
        u = v;
        v = temp;
        assignments += 3;
    }
    return u;
}

// ý (ii)

// Thuật toán 1: Kém tối ưu
int longestNonDecreasingSubsequenceLength1(int* a, int n) {
    int* dp = new int[n];
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}
// Sau khi thêm biến đếm
int longestNonDecreasingSubsequenceLength1(int a[], int n, int& count_assignments, int& count_comparisons) {
    count_assignments = 0;
    count_comparisons = 0;
    int* dp = new int[n]; count_assignments++;
    int i = 0; count_assignments++;
    for (;++count_comparisons && i < n; ++i) {
        count_assignments++;
        dp[i] = 1; count_assignments++;
    }
    i = 1; count_assignments++;
    for (; ++count_comparisons && i < n; ++i) {
        count_assignments++;
        if ((count_comparisons++) && a[i] >= a[i - 1]) {
            dp[i] = dp[i - 1] + 1; count_assignments++;
        }
    }
    int maxLength = 0; count_assignments++;
    i = 0; count_assignments++;
    for (; ++count_comparisons && i < n; ++i) {
        count_assignments++;
        maxLength = max(maxLength, dp[i]); count_assignments++;
    }
    return maxLength;
}



// Thuật toán 2: Tối ưu hơn
int longestNonDecreasingSubsequenceLength2(int* a, int n) {
    if (n == 0) return 0;
    int maxLength = 1;
    int currentLength = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            currentLength++;
        }
        else {
            maxLength = max(maxLength, currentLength);
            currentLength = 1;
        }
    }
    maxLength = max(maxLength, currentLength);
    return maxLength;
}


// Sau khi thêm biến đếm
int longestNonDecreasingSubsequenceLength2(int a[], int n, int& count_assignments, int& count_comparisons) {
    count_assignments = 0;
    count_comparisons = 0;
    if ((count_comparisons++) && n == 0) return 0;

    int maxLength = 1; count_assignments++;
    int currentLength = 1; count_assignments++;
    int i = 1; count_assignments++;
    for (;++count_comparisons && i < n; ++i) {
        count_assignments++;
        if ((count_comparisons++) && (a[i] >= a[i - 1])) {
            currentLength++;
            count_assignments++;
        }
        else {
            maxLength = max(maxLength, currentLength); count_assignments++;
            currentLength = 1; count_assignments++;
        }
    }

    maxLength = max(maxLength, currentLength); count_assignments++;
    return maxLength;
}

// ý (iii)
// Thuật toán 1: kém tối ưu O(n^2*logn)
void heapify(vector<int>& arr, int n, int i, int& cmp, int& asgm) {
    int largest = i; ++asgm;
    int left = 2 * i + 1; ++asgm;
    int right = 2 * i + 2; ++asgm;
    if (++cmp && ++cmp && left < n && arr[left] > arr[largest]) {
        largest = left; ++asgm;
    }
    if (++cmp && ++cmp && right < n && arr[right] > arr[largest]) {
        largest = right; ++asgm;
    }
    if (++cmp && largest != i) {
        int tmp = arr[i]; ++asgm;
        arr[i] = arr[largest]; ++asgm;
        arr[largest] = tmp; ++asgm;
        heapify(arr, n, largest, cmp, asgm);
    }
}

void heapSort(vector<int>& arr, int n, int& cmp, int& asgm) { // O(nlogn)
    int i = n / 2 - 1; ++asgm;
    while (++cmp && i >= 0) {
        heapify(arr, n, i, cmp, asgm);
        --i; ++asgm;
    }
    int j = n - 1; ++asgm;
    while (++cmp && j >= 0) {
        int tmp = arr[0]; ++asgm;
        arr[0] = arr[j]; ++asgm;
        arr[j] = tmp; ++asgm;
        heapify(arr, j, 0, cmp, asgm);
        --j; ++asgm;
    }
}

vector<int> findMedian(vector<int> a, int n, int& cmp, int& asgm) {
    vector<int> b;
    int i = 0; ++asgm;
    while (++cmp && i < n) {
        int x = generateRandomNumber(-pow(10, 5), pow(10, 5)); ++asgm;
        a.push_back(x);
        heapSort(a, i + 1, cmp, asgm);
        if (cmp++ && a.size() % 2 == 0) {
            b.push_back((a[a.size() / 2] + a[a.size() / 2 - 1]) / 2);
        }
        else {
            b.push_back(a[a.size() / 2]);
        }
        ++i; ++asgm;
    }
    return b;
}
// Thuật toán 2: Tối ưu hơn
vector<int> findMedian_optimize(vector<int> a, int n, int& cmp, int& asgm) {
    int i = 1; ++asgm;
    vector<int> b;
    int x;
    if (++cmp && a.empty()) {
        x = generateRandomNumber(-pow(10, 5), pow(10, 5)); ++asgm;
        a.push_back(x);
    }
    while (++cmp && i < n) {
        x = generateRandomNumber(-pow(10, 5), pow(10, 5)); ++asgm;
        int j = 0; ++asgm;
        while (++cmp && j < a.size()) {
            if (++cmp && x < a[j]) {
                a.insert(a.begin() + j, x);
                break;
            }
            ++j; ++asgm;
        }
        a.push_back(x);
        if (cmp++ && a.size() % 2 == 0) {
            b.push_back((a[a.size() / 2] + a[a.size() / 2 - 1]) / 2);
        }
        else {
            b.push_back(a[a.size() / 2]);
        }
        ++i; ++asgm;
    }
    return b;
}

// ý (iv)

// Thuật toán 1
int paradoxicalNum1(int arr[], int n) {

    int count = 0;
    int i = 0;
    while (i < n - 1) {
        int j = i + 1; 
        while ( j < n) {
            if ( arr[i] > arr[j])
            {
                count++;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return count;
}
// Sau khi thêm biến đếm
int paradoxicalNum1(int arr[], int n, int& count_assignments, int& count_comparisons) {
    count_comparisons = 0;
    count_assignments = 0;
    int count = 0;count_assignments++;
    int i = 0; count_assignments++;
    while (++count_comparisons && i < n - 1) {
        int j = i + 1; count_assignments++;
        while (++count_comparisons && j < n) {
            if (++count_comparisons && arr[i] > arr[j])
            {
                count++;
                count_assignments++;
            }
            j = j + 1; count_assignments++;
        }
        i = i + 1; count_assignments++;
    }
    return count;
}


// Thuật toán 2
long long merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1; 
    int n2 = right - mid;

    int* left_arr = new int[n1]; 
    int* right_arr = new int[n2];
    for (int i = 0; i < n1;i++) {
        left_arr[i] = arr[left + i]; 
    }
    for (int j = 0; j < n2;j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    long long inv_count = 0;

    int i = 0, j = 0, k = left;

    while (i < n1 &&  j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            k++;
            i++;
        }
        else {
            arr[k] = right_arr[j];
            k++;
            j++;
            inv_count += n1 - i;
        }
    }

    while (i < n1) {
        arr[k] = left_arr[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        k++;
        j++;
    }

    delete[] left_arr;
    delete[] right_arr;

    return inv_count;
}
long long mergesort(int arr[], int left, int right) {

    long long inv_count = 0; 

    if ( left < right) {
        int mid = left + (right - left) / 2; 
        inv_count += mergesort(arr, left, mid); 
        inv_count += mergesort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right); 
    }
    return inv_count;
}

long long paradoxicalnum2(int arr[], int n) {
    return mergesort(arr, 0, n - 1);
}

// Sau khi thêm biến đếm
long long merge(int arr[], int left, int mid, int right, int& count_assignments, int& count_comparisons) {

    int n1 = mid - left + 1; count_assignments++;
    int n2 = right - mid; count_assignments++;

    int* left_arr = new int[n1]; count_assignments++;
    int* right_arr = new int[n2];count_assignments++;
    for (int i = 0;++count_comparisons && i < n1;i++) {
        count_assignments++;
        left_arr[i] = arr[left + i]; count_assignments++;
    }
    for (int j = 0;++count_comparisons && j < n2;j++) {
        count_assignments++;
        right_arr[j] = arr[mid + 1 + j];
        count_assignments++;
    }

    long long inv_count = 0; count_assignments++;

    int i = 0, j = 0, k = left;
    count_assignments++;
    count_assignments++;
    count_assignments++;

    while ((++count_comparisons && i < n1) && (++count_comparisons && j < n2)) {
        if (++count_comparisons && left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            count_assignments++;
            k++;count_assignments++;
            i++;count_assignments++;
        }
        else {
            arr[k] = right_arr[j];count_assignments++;
            k++;count_assignments++;
            j++;count_assignments++;
            inv_count += n1 - i;count_assignments++;
        }
    }

    while (++count_comparisons && i < n1) {
        arr[k] = left_arr[i];count_assignments++;
        k++;count_assignments++;
        i++;count_assignments++;
    }

    while (++count_comparisons && j < n2) {
        arr[k] = right_arr[j];count_assignments++;
        k++;count_assignments++;
        j++;count_assignments++;
    }

    delete[] left_arr;
    delete[] right_arr;

    return inv_count;
}
long long mergesort(int arr[], int left, int right, int& count_assignments, int& count_comparisons) {

    long long inv_count = 0; count_assignments++;

    if (++count_comparisons && left < right) {
        int mid = left + (right - left) / 2; count_assignments++;
        inv_count += mergesort(arr, left, mid, count_assignments, count_comparisons); count_assignments++;
        inv_count += mergesort(arr, mid + 1, right, count_assignments, count_comparisons); count_assignments++;
        inv_count += merge(arr, left, mid, right, count_assignments, count_comparisons); count_assignments++;
    }
    return inv_count;
}

long long paradoxicalnum2(int arr[], int n, int& count_assignments, int& count_comparisons) {
    return mergesort(arr, 0, n - 1, count_assignments, count_comparisons);
}


//Khác
void nhapMang(int arr[], int n)
{
    // khởi tạo số ngẫu nhiên
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 500);

    for (int i = 0;i < n;i++) {
        arr[i] = dis(gen);
    }
}

int generateRandomNumber(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(min, max);

  return dis(gen);
}