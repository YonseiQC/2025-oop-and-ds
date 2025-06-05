#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <iostream>
#include <format>

enum class Color {WHITE, GRAY, BLACK};

template<typename V>
class UndirectedGraph {
private:
	std::vector<V> vertices_;
	std::unordered_map<V, int> v_to_idx_;
	std::vector<std::list<int>> adjacent_list_;
	int num_edges_;

public:
	using VertexT = V;

	UndirectedGraph() : num_edges_{0} {
	}

	void add_vertex(const V& v) {
		int idx = vertices_.size();
		vertices_.push_back(v);
		v_to_idx_[v] = idx;
		adjacent_list_.push_back(std::list<int>());
	}

	const std::vector<V>& all_vertices() const {
		return vertices_;
	}

	int num_verticies() const {
		return vertices_.size();
	}

	int num_edges() const {
		return num_edges_;
	}

	int v_to_idx(const V& v) const {
		return v_to_idx_.at(v);
	}

	void add_edge(const V& u, const V& v) {
		adjacent_list_[v_to_idx(u)].push_back(v_to_idx(v));
		adjacent_list_[v_to_idx(v)].push_back(v_to_idx(u));
		++num_edges_;
	}

	const std::list<int>& neighbors(int u_idx) const {
		return adjacent_list_[u_idx];
	}
};

struct BFSResult {
	std::vector<int> distances;
	std::vector<int> predecessor;
};

template<typename Graph>
BFSResult bfs(const Graph& G, const typename Graph::VertexT& s) {
	const int n = G.num_verticies();
	std::vector<Color> colors(n, Color::WHITE);
	std::vector<int> distances(n, -1);
	std::vector<int> predecessor(n, -1);

	const int idx = G.v_to_idx(s);
	colors[idx] = Color::GRAY;
	distances[idx] = 0;

	std::queue<int> q;
	q.push(idx);
	while(!q.empty()) {
		const int u = q.front();
		q.pop();

		for(const int v: G.neighbors(u)) {
			if(colors[v] == Color::WHITE) {
				colors[v] = Color::GRAY;
				distances[v] = distances[u] + 1;
				predecessor[v] = u;
				q.push(v);
			}
		}
		colors[u] = Color::BLACK;
	}
	return {distances, predecessor};
}

int main() {
	UndirectedGraph<char> G;
	for(const char v: {'r','s','t','u','v','w','x','y'}) {
		G.add_vertex(v);
	}

	G.add_edge('r','v');
	G.add_edge('r','s');
	G.add_edge('s','w');
	G.add_edge('w','t');
	G.add_edge('w','x');
	G.add_edge('t','x');
	G.add_edge('t','u');
	G.add_edge('x','u');
	G.add_edge('x','y');
	G.add_edge('u','y');

	const auto [distances, predecessor] = bfs(G, 's');

	for(const char v: G.all_vertices()) {
		std::cout << std::format("Distance of {} is {}\n", v, distances[G.v_to_idx(v)]);
	}

	return 0;
}
