#include <iostream>
#include <list>

using namespace std;

// 풀이.
// 연결리스트를 이용하여 원소를 삭제후 순회하는 문제다.
// 예전에 종만북에서 풀었던 것은 오른쪽으로만 순회했기에 깔끔하게 풀었는데
// 이건 왼쪽으로도 순회해야했기에 복잡하고 가독성도 구리다.

// 자세한 설명은 주석으로 남긴다.

list<pair<int, int>> board;
int N;

void MakeAnswer()
{
    // 이동후값과 현재값.
    list<pair<int, int>>::iterator there = board.begin();
    list<pair<int, int>>::iterator here;
    int cost;
    while (!board.empty())
    {
        here = there;
        cost = here->second;
        // 이동이 오른쪽이라면 현재값을 지우기 위해 이동후값을 미리 오른쪽으로 이동시킨다.
        if (cost > 0)
        {
            ++there;
            // 이동후값이 끝값이라면 처음으로 옮긴다.
            if (there == board.end())
                there = board.begin();
        }
        // 왼쪽이라면 왼쪽으로 미리 옮긴다.
        else
        {
            // 시작값에서 더이상 왼쪽으로 옮길수 없으니 끝값으로 옮겨 왼쪽으로 이동시킨다.
            if (there == board.begin())
                there = board.end();
            --there;
        }
        // 현재 번호를 출력하고 삭제한다.
        cout << here->first << ' ';
        board.erase(here);

        // 리스트가 텅비었다면 탈출한다.
        if (board.empty())
            break;

        // 한번 이동시킨 이후이기에 cost - 1만큼 이동시킨다.
        for (int i = 0; i < abs(cost) - 1; ++i)
        {
            if (cost > 0)
            {
                ++there;
                if (there == board.end())
                    there = board.begin();
            }
            else
            {
                if (there == board.begin())
                    there = board.end();
                --there;
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        board.push_back(make_pair(i, num));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}