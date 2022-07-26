#include <iostream>
#include <algorithm>

using namespace std;

string A, B;

void MakeAnswer()
{
    int Asize = A.size();
    int Bsize = B.size();
    int answer = Asize;
    for (int i = 0; i <= Bsize - Asize; ++i)
    {
        int now = 0;
        for (int j = 0; j < Asize; ++j)
            if (A[j] != B[j + i])
                ++now;
        answer = min(answer, now);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}