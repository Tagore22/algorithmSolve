#include <iostream>

using namespace std;

int main()
{
    int N, answer = 0, num;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        answer += num;
    }
    if (answer > 0)
        cout << "Right" << '\n';
    else if (answer < 0)
        cout << "Left" << '\n';
    else
        cout << "Stay" << '\n';
    return 0;
}