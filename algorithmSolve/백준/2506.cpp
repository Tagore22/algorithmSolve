#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int point = 0, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        bool isRight;
        cin >> isRight;
        if (isRight)
        {
            ++point;
            answer += point;
        }
        else
        {
            point = 0;
        }
    }
    cout << answer << '\n';
    return 0;
}