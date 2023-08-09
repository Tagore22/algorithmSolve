#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

// 네트워크 유량쪽 확인하기.

#define MAX_NODE 52
#define INF 1e9

int capacity[MAX_NODE][MAX_NODE];

int flow[MAX_NODE][MAX_NODE];

vector<int> neighbor_node[MAX_NODE];

int visited[MAX_NODE];

int result_max_flow;

int ctoi(char c) {

    if (c <= 'Z') {
        return c - 'A';
    }
    return c - 'a' + 26;
}

int maximum_flow(int source_node, int sink_node) {

    while (1) {

        memset(visited, -1, sizeof(visited));
        queue<int> q;
        q.push(source_node);

        while (!q.empty()) {

            int current_node = q.front();
            q.pop();

            for (int i = 0; i < neighbor_node[current_node].size(); ++i) {

                int next_node = neighbor_node[current_node][i];

                if ((capacity[current_node][next_node] - flow[current_node][next_node] > 0) && (visited[next_node] == -1)) {

                    q.push(next_node);

                    visited[next_node] = current_node;

                    if (next_node == sink_node) break;
                }
            }
            if (visited[sink_node] != -1) break;
        }

        if (visited[sink_node] == -1) break;

        int temp_max_flow = INF;
        int residual_capacity;

        for (int i = sink_node; i != source_node; i = visited[i]) {
            residual_capacity = capacity[visited[i]][i] - flow[visited[i]][i];
            temp_max_flow = min(temp_max_flow, residual_capacity);
        }

        for (int i = sink_node; i != source_node; i = visited[i]) {

            flow[visited[i]][i] += temp_max_flow;

            flow[i][visited[i]] -= temp_max_flow;
        }

        result_max_flow += temp_max_flow;
    }
    return result_max_flow;
}

int main() {

    int edge_count;
    cin >> edge_count;

    char char_start_node, char_end_node;
    int input_capacity;

    for (int i = 0; i < edge_count; ++i) {

        cin >> char_start_node >> char_end_node >> input_capacity;
        int int_start_node = ctoi(char_start_node);
        int int_end_node = ctoi(char_end_node);

        neighbor_node[int_start_node].push_back(int_end_node);
        neighbor_node[int_end_node].push_back(int_start_node);

        capacity[int_start_node][int_end_node] += input_capacity;
        capacity[int_end_node][int_start_node] += input_capacity;
    }

    cout << maximum_flow(ctoi('A'), ctoi('Z')) << endl;

}