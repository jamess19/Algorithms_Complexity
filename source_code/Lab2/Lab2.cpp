#include"func.h"

int main()
{
    int count_assignments = 0;
    int count_comparisons = 0;
    int count_assignments2 = 0;
    int count_comparisons2 = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 500);
    int phan;
    int bai;
    int n;
    int v;
    int* A;
    int longestLength1, longestLength2;
    int arr[MAX];
    int res1, res2;
    vector<int> a;

    do {
        system("cls");
        cout << "----------------- MENU -----------------" << endl;
        cout << "part 1 _ estimate algorithm complexity (press 1)" << endl;
        cout << "part 2 _ design algorithms (press 2)" << endl;
        cout << "press 0 to exit" << endl;
        cout << "--------------------------------------" << endl;
        cout << "choose part: ";
        cin >> phan;
        switch (phan)
        {
        case 1:
            do {
                system("cls");
                cout << "--------------- MENU 1 -------------------" << endl;
                cout << "1: sumhalf" << endl;
                cout << "2: recursiveSquareSum" << endl;
                cout << "press 0 to back" << endl;
                cout << "choose exercise:";
                cin >> bai;
                switch (bai)
                {
                case 1:
                    system("cls");
                    cout << setw(5) << "n" << setw(15) << "Assignments" << setw(15) << "Comparisons" << endl;
                    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
                    n = 0;
                    for (;n <= 500;n+=25) {
                        count_assignments = 0;
                        count_comparisons = 0;
                        sumHalf(n, count_comparisons, count_assignments);
                        cout << setw(5) << n << setw(10) << count_assignments << setw(15) << count_comparisons << endl;
                    }
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    system("cls");
                    cout << setw(5) << "n" << setw(15) << "Assignments" << setw(15) << "Comparisons" << endl;
                    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
                    n = 0;
                    for (;n<=500;n+=25) {
                        count_assignments = 0; 
                        count_comparisons = 0; 
                        recursiveSquareSum(n, count_comparisons, count_assignments);
                        cout << setw(5) << n << setw(10) << count_assignments << setw(15) << count_comparisons << endl;
                    }

                    cin.ignore();
                    cin.get();
                    break;
                }
            } while (bai != 0);
            break;
        case 2:
            do {
                system("cls");
                cout << "--------------- MENU 2 -------------------" << endl;
                cout << "1: greatest common divisor (gcd)" << endl;
                cout << "2: longest nondecreasing subsequence" << endl;
                cout << "3: Median of the array" << endl;
                cout << "4: Numbers of paradoxical pair" << endl;
                cout << "press 0 to back" << endl;
                cout << "choose exercise:";
                cin >> bai;
                switch (bai)
                {
                case 1:
                    system("cls");
                    cout << setw(10) << "U" << setw(10) << "V" << setw(20)
                        << "Assignments" << setw(20) << "Comparisons" << setw(20)
                        << "Assignments2" << setw(20) << "Comparisons2" << endl;
                    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;
                    for (int u = 0; u <= 500; u += 25) {
                        v = dis(gen);
                        count_assignments = 0;
                        count_comparisons = 0;
                        count_assignments2 = 0;
                        count_comparisons2 = 0;
                        gcd(u, v, count_assignments, count_comparisons);
                        gcdEuclid(u, v, count_assignments2, count_comparisons2);
                        cout << setw(10) << u << setw(10) << v << setw(15) 
                            << count_assignments << setw(20) << count_comparisons << setw(20) 
                            << count_assignments2 << setw(20) << count_comparisons2 << endl;
                    }
                    cin.ignore();
                    cin.get();
                    break;
                case 2:
                    system("cls");
                    cout << setw(10) << "n" << setw(20)
                        << "Assignments" << setw(20) << "Comparisons" << setw(20)
                        << "Assignments2" << setw(20) << "Comparisons2" << endl;
                    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
                    n = 0;
                    for (; n <= 500; n += 25) {
                        A = new int[n];
                        nhapMang(A, n);
                        count_assignments = 0;
                        count_comparisons = 0;
                        count_assignments2 = 0;
                        count_comparisons2 = 0;
                        longestLength1 = longestNonDecreasingSubsequenceLength1(A, n, count_assignments, count_comparisons);
                        longestLength2 = longestNonDecreasingSubsequenceLength2(A, n, count_assignments2, count_comparisons2);
                        cout << setw(10) << n << setw(20) 
                            << count_assignments << setw(20) << count_comparisons << setw(20)
                            << count_assignments2 << setw(20) << count_comparisons2 << endl;

                        delete[] A;
                    }
                    cin.ignore();
                    cin.get();
                    break;
                case 3:
                    system("cls");
                    cout << setw(10) << "n" << setw(20)
                        << "Assignments" << setw(20) << "Comparisons" << setw(20)
                        << "Assignments2" << setw(20) << "Comparisons2" << endl;
                    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
                    n = 0;
                    for (;n <= 500;n+=25) {
                        count_assignments = 0;
                        count_comparisons = 0;
                        count_assignments2 = 0;
                        count_comparisons2 = 0;
                        findMedian(a, n, count_comparisons, count_assignments);
                        findMedian_optimize(a, n, count_comparisons2, count_assignments2);
                        cout << setw(10) << n << setw(20)
                            << count_assignments << setw(20) << count_comparisons << setw(20)
                            << count_assignments2 << setw(20) << count_comparisons2 << endl;
                    }
                    cin.ignore();
                    cin.get();
                    break;
                case 4:
                    system("cls");
                    cout << setw(10) << "n" << setw(20)
                        << "Assignments" << setw(20) << "Comparisons" << setw(20)
                        << "Assignments2" << setw(20) << "Comparisons2" << endl;
                    cout << setfill('-') << setw(100) << "-" << setfill(' ') << endl;
                    n = 0;
                    for (;n <= 200;n+=25) {
                        count_assignments = 0;
                        count_comparisons = 0;
                        count_assignments2 = 0;
                        count_comparisons2 = 0;
                        nhapMang(arr, n);
                        paradoxicalNum1(arr, n, count_assignments, count_comparisons);
                        paradoxicalnum2(arr, n, count_assignments2, count_comparisons2);
                        cout << setw(10) << n << setw(20)
                            << count_assignments << setw(20) << count_comparisons << setw(20)
                            << count_assignments2 << setw(20) << count_comparisons2 << endl;
                    }
                    cin.ignore(); 
                    cin.get(); 
                    break;
                }
            } while (bai != 0);

            break;
        }
    } while (phan != 0);
}
