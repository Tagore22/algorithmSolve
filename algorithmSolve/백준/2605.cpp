#include <iostream>
#include <list>

using namespace std;

// 풀이.
// 브론즈인데 2번이나 틀린 문제다. 나의 생각이 잘못되었을 뿐이지만.
// 처음에는 list를 생각했었다. 하지만 반복자를 사용해야하기에 브론즈 문제인데 굳이? 라는 생각이 들었고
// string으로 풀려고 했다. 하지만 치명적인 실수였다. 주어지는 학생의 수가 10을 넘어가기 때문에
// string으로는 정답을 제대로 출력할수 없었다. 역시 처음 생각했던것처럼 list를 사용해야했다.
// 두번째로는 순서의 문제였다. 보통 일상에서 순서는 왼쪽부터 시작되나 이 문제는 오른쪽부터 시작되었다.
// 그래서 방법은 2가지였는데 오른쪽부터 시작하게끔 추가하는 것과, 왼쪽부터 추가하되 출력 순서를 뒤집는 것이다.
// 둘다 해보았는데 출력 순서를 뒤집는 것은 코드가 깨끗하지 않았다. 일단 list이기 때문에 for문에 반복자를 써야했으며
// 뒤집어야 하기에 end()의 이전부터 begin()이전까지 출력해야 한다. 따라서 for문으로 begin()이전까지 출력후 한번 더 출력
// 해야 한다. 따라서 오른쪽부터 시작하게끔 추가하기로 하였다. 이것은 advance()에 반영되었다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    int N;
    cin >> N;
    list<int> board;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        // 뽑은 것이 0이라면 제자리에 남는다. 즉 현재 위치(맨 오른쪽)에 남는다.
        if (num == 0)
        {
            board.push_back(i);
        }
        // 0이 아니라면 뽑은 순서로 줄에 낀다. 다만 그 순서는 왼쪽부터가 아닌 오른쪽부터 이기에
        // size() - 순서로 바뀐다.
        else
        {
            auto iter = board.begin();
            advance(iter, board.size() - num);
            board.insert(iter, i);
        }
    }
    for (auto n : board)
        cout << n << ' ';
    cout << '\n';
    return 0;
}