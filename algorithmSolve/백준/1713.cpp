#include <iostream>
#include <list>

using namespace std;

// 풀이
// 이 문제를 푸는 메커니즘은 이러하다.

// 1. 현재 추천된 학생 번호 K를 받는다.
// 2. K가 이미 사진틀안에 존재한다면 추천횟수만 늘리고 빠진다.
// 3. K가 사진틀안에 존재하지 않는다면 현재 사진틀안에 인월수를 확인한다.
// 3-1. 사진틀이 아직 N명으로 꽉 차지 않았다면 추천횟수 1을 지닌채 사진틀안에 넣는다.
// 3-2. 사진틀이 이미 N명으로 꽉 차있다면 그 안에 학생들중 가장 추천횟수가 적은 학생을, 만약 추천횟수가 적은 횟수가 2명
// 이상이라면 그들중 가장 오래된 학생을 제외시키고 K를 추천횟수 1을 지닌채 사진틀안에 넣는다.

// 학생을 제외시킬때 앞 뒤 중간 어느곳에서도 빠질수 있기에 나같은 경우는 list를 사용하였다. 다만, 마지막에 학생 번호순으로 정렬을 해야하는데
// 일반 sort()로는 list가 랜덤 액세스를 지원하지 않기에 사용할수없고, list가 따로 지원하는 list::sort()를 사용했다.


int N, M;

bool CompareNum(pair<int, int> lhs, pair<int, int> rhs)
{
    return lhs.first < rhs.first;
}

void MakeAnswer()
{
    // 학생들이 들어가는 사진틀. 위 상술하였듯 앞 뒤 중간 어디서 제외될지 알수없기에 list로 구현하였다.
    list<pair<int, int>> board; // 번호, 추천수
    int cur;
    for (int i = 0; i < M; ++i)
    {
        cin >> cur;
        bool isfind = false;
        
        // 현재 추천받은 학생이 이미 사진틀안에 존재할 경우 추천횟수를 1 늘리고 빠진다.
        for (auto iter = board.begin(); iter != board.end(); ++iter)
            if (iter->first == cur)
            {
                ++iter->second;
                isfind = true;
                break;
            }

        // 사진틀안에 존재하지 않을 경우 2가지 경우로 나뉘어진다.
        if (!isfind)
        {

            // 1. 아직 사진틀에 N명의 학생이 존재하지 않는다면 그냥 추천횟수를 1 지닌채 집어넣고 빠진다.
            if (board.size() < N)
            {
                board.push_back(make_pair(cur, 1));
            }

            // 2. 이미 N명으로 꽉차있다면 그들중 추천횟수가 가장 적은 또한 그들중 가장 오래된 학생을 제외시키고 추천횟수를 1 지닌채 사진틀에
            // 집어넣는다.

            // 이 경우에 추천횟수가 가장 적은 학생들중 맨 앞에 학생을 가장 오래된 학생으로 취급하였는데, 이는 학생을 사진틀안에 집어넣을때
            // 무조건 뒤에서(push_back())부터 집어넣기 때문이다. 더 최근에 학생이 더 뒤에 있을수는 없다.
            else
            {
                int min_num = 1001;
                list<pair<int, int>>::iterator idx;
                for (auto iter = board.begin(); iter != board.end(); ++iter)
                    if (iter->second < min_num)
                    {
                        min_num = iter->second;
                        idx = iter;
                    }
                board.erase(idx);
                board.push_back(make_pair(cur, 1));
            }
        }
    }

    // 랜덤 액세스를 지원하지 않는 list로는 일반적인 sort()로 정렬할수 없기에 list에서 따로 지원하는 더 빠른 list::sort()로 정렬하여
    // 출력한다.
    board.sort(CompareNum);
    for (auto iter = board.begin(); iter != board.end(); ++iter)
        cout << iter->first << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}