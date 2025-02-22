#include <iostream>

using namespace std;

int main()
{
    int N, cur = 0, answer = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        if (num == cur)
        {
            ++answer;
            cur = (cur + 1) % 3;
        }
    }
    cout << answer << '\n';
    return 0;
}