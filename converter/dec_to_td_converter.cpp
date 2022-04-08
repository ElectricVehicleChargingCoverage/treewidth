#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	// read dec file
	int width, num_bags;
	cin >> width >> num_bags;
	int num_graph_nodes = 0;
	vector<int> parents(num_bags);
	vector<vector<int>> bags(num_bags);
	for (int i = 0; i < num_bags; ++i) {
		int bag_id, bag_size;
		cin >> bag_id >> bag_size;
		for (int j = 0; j < bag_size; ++j) {
			int node_id; cin >> node_id;
			bags[i].push_back(node_id);
			num_graph_nodes = max(num_graph_nodes, node_id);
		}
		int parent_bag_id; cin >> parent_bag_id;
		parents[bag_id] = parent_bag_id;
		int num_children; cin >> num_children;
		for (int j = 0; j < num_children; ++j) {
			int ignore; cin >> ignore;
		}
	}

	// write gr file
	ofstream out("graph.td");
	out << "s td " << num_bags << " " << width + 1 << " " << num_graph_nodes << endl;
	for (int i = 0; i < num_bags; ++i) {
		out << "b " << i + 1 << " ";
		for (int id : bags[i]) {
			out << id << " ";
		}
		out << endl;
	}
	for (int i = 0; i < num_bags; ++i) {
		if (parents[i] != i) {
			out << i + 1 << " " << parents[i] + 1 << endl;
		}
	}
	out.close();
	return 0;
}