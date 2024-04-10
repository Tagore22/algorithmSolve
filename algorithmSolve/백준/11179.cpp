#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string binary = "";
    while (N > 0)
    {
        binary += to_string(N % 2);
        N /= 2;
    }
    int answer = 0, multi = 0;
    for (int i = binary.size() - 1; i >= 0; --i)
    {
        answer += (binary[i] - '0') * pow(2, multi);
        ++multi;
    }
    cout << answer << '\n';
    return 0;
}