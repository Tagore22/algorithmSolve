#include <iostream>

using namespace std;

int N, M, answer[2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        answer[0] = answer[1] = 0;
        cin >> M;
        for (int i = 0; i < M; ++i)
        {
            int tessa, danny;
            cin >> tessa >> danny;
            if (tessa == 1 && danny == 2)
                answer[0] += 6;
            else if (tessa == 2 && danny == 1)
                answer[1] += 6;
            else if (tessa + 1 == danny)
                answer[0] += tessa + danny;
            else if (danny + 1 == tessa)
                answer[1] += tessa + danny;
            else if (tessa > danny)
                answer[0] += tessa;
            else if (tessa < danny)
                answer[1] += danny;
        }
        cout << "Game " << iter + 1 << ": Tessa " << answer[0] << " Danny " << answer[1] << '\n';
    }
    return 0;
}