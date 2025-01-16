#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int answer = N / 2;
    answer = N % 2 == 0 ? answer : answer + 3;
    cout << answer << '\n';
}