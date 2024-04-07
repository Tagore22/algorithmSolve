#include <iostream>
#include <map>

using namespace std;

// 소수점 첫째짜리까지 출력해야하는데 문제에는 그런 말이 전혀 없고
// 다만 4.0이라고 표기되서 그런가보다.

int main()
{
    map<string, float> board;
    board["A+"] = 4.3;
    board["A0"] = 4.0;
    board["A-"] = 3.7;
    board["B+"] = 3.3;
    board["B0"] = 3.0;
    board["B-"] = 2.7;
    board["C+"] = 2.3;
    board["C0"] = 2.0;
    board["C-"] = 1.7;
    board["D+"] = 1.3;
    board["D0"] = 1.0;
    board["D-"] = 0.7;
    board["F"] = 0.0;

    string grade;
    cin >> grade;
    cout.precision(1);
    cout << fixed;
    cout << board[grade] << '\n';
    return 0;
}