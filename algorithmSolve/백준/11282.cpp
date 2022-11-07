#include <iostream>

using namespace std;

string str;
int N;

int main()
{
    cin >> N;
    N += 3071;
    str.push_back(N / 4096 + 234);
    str.push_back(N / 64 % 64 + 128);
    str.push_back(N % 64 + 128);

    cout << str << '\n';
    return 0;
}