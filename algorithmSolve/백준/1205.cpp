#include <iostream>
#include <vector>

using namespace std;

vector<int> ranks;
int N,point,P;

void MakeAnswer()
{
    if(N == 0)
    {
        cout << 1 << '\n';
        return;
    }
    int idx = 0;
    int answer = 1;
    for(int i = 0; i < ranks.size(); ++i)
    {
        if(ranks[i] > point)
            ++answer;
        else if(ranks[i] < point)
            break;
        ++idx;
    }
    cout << (idx < P ? answer : -1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> point >> P;
    for(int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        ranks.push_back(x);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}