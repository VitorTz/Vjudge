#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>


constexpr double INF = 1e-9;
constexpr int MAX_NODES{201};
constexpr int MAX_EDGES{20000};


typedef std::pair<int, int> point_t;

typedef struct edge {
    point_t point{};
    double weigth{};
} edge_t;


point_t node_arr[MAX_NODES];
edge_t edge_arr[MAX_EDGES];
int proc_arr[MAX_NODES];
int nnodes, nedges;


double distance_points(const point_t& a, const point_t& b) {
    return sqrt(std::pow(a.first - b.first, 2) + std::pow(a.second - b.second, 2));
}


int pree_proc(const int u){
    if (proc_arr[u] == u) {
        return u;
    }
    proc_arr[u] = pree_proc(proc_arr[u]);
    return proc_arr[u];    
}


int main() {    
    int i, j, tc = 1;
    
    while(std::cin >> nnodes && nnodes) {
        for(i = 0; i < nnodes; i++) {
            std::cin >> node_arr[i].first >> node_arr[i].second;            
        }
        nedges = 0;
        for(i = 0; i < nnodes;i++) {
            for(j = i + 1; j < nnodes; j++) {
                edge_arr[nedges].point.first = i;
                edge_arr[nedges].point.second = j;
                edge_arr[nedges].weigth = distance_points(node_arr[i], node_arr[j]);                
                nedges++;
            }
        }

        for (int i = 0; i < nnodes; i++){
            proc_arr[i] = i;
        }

        double min_max = 0;
        
        std::sort(
            edge_arr, 
            edge_arr + nedges, 
            [](const edge_t& l, const edge_t& r) { return l.weigth - r.weigth < INF; }
        );

        for(i = 0; i < nedges; i++){
            const int start = pree_proc(edge_arr[i].point.first);
            const int end = pree_proc(edge_arr[i].point.second);
            if(pree_proc(0) == pree_proc(1)) {
                break;
            }
            if(start != end) {
                min_max = edge_arr[i].weigth;
                proc_arr[start] = end;
            }

        }
        std::cout << "Scenario #" << tc++ << '\n';
        std::printf("Frog Distance = %.3lf\n\n", min_max);        

    }

	return 0;
}