#include <utility>
#include <vector>
#include <cmath>
#include <limits>

struct Node {
	std::pair<int, int> point;
	int id;

	Node(std::vector<int> origin, int n) {
		point = std::make_pair(origin[0], origin[1]);
		id = n;
	}

	~Node() {
		// Empty for now
	}

	// Distance from node to node
	int distanceToNode(Node* a) {
		int dist;

		// Distance to self is max
		if (this->id == a->id) {
			return dist = std::numeric_limits<int>::max();
		}

		// Distance to node a
		return dist = std::abs(this->point.first - a->point.first) + std::abs(this->point.second - a->point.second);
	}
};

struct Tree {
	Node* root;
	std::vector<Node*> tree;
	int weight;

	Tree(std::vector<int> origin, int n) {
		root = new Node(origin, n);
		tree.push_back(root);
	}

	~Tree() {
		Node* toDelete;
		while (!tree.empty()) {
			toDelete = tree.back();
			tree.pop_back();
			delete toDelete;
		}
		if (root != nullptr) {
			delete root;
			root = nullptr;
		}
	}

	// Shortest distance between trees
	int distanceToTree(Tree* a) {
		int dist;
		// Distance to self if max
		if (this->root->id == a->root->id) {
			return std::numeric_limits<int>::max();
		}
	}
};

struct Forest {
	std::vector<Tree*> forest;

	Forest(std::vector<std::vector<int>> points) {
		for (int i = 0; i < points.size(); i++) {
			Tree* tree = new Tree(points[i], i);
			forest.push_back(tree);
		}
	}

	~Forest() {
		Tree* toDelete;
		while (!forest.empty()) {
			toDelete = forest.back();
			forest.pop_back();
			delete toDelete;
		}
	}
};