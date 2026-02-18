#include <iostream>

using namespace std;

int main()
{
    int from, to;
    cin >> from >> to;
    to = from >= to ? to + 24 : to;
    cout << to - from << '\n';
    return 0;
}