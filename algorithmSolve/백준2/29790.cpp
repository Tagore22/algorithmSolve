#include <iostream>

using namespace std;

int main()
{
    int N, U, L;
    cin >> N >> U >> L;
    if (N >= 1000)
        cout << (U >= 8000 || L >= 260 ? "Very Good" : "Good") << '\n';
    else
        cout << "Bad" << '\n';
    return 0;
}