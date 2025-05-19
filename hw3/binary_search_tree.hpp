#include <utility>

template<typename T>
struct Node {
	T value;
	Node<T>* parent;
	Node<T>* left;
	Node<T>* right;
};

template <typename T>
Node<T>* create_leaf_node(Node<T>* parent) {
	auto node = new Node<T>;
	// node->value has a trash value
	node->parent = parent;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

template<typename Func>
class TreeTraversaler;

template<typename T>
bool is_leaf(Node<T>* node) {
	return (node->left == nullptr) && (node->right == nullptr);
}

template<typename T>
class BinarySearchTree {
private:
	Node<T>* root_;

public:
	class Iterator {
	private:
		Node<T>* curr_;

	public:
		Iterator(Node<T>* curr) : curr_(curr) {}

		Iterator& operator++() {
			// Implement here
			return *this;
		}

		Iterator& operator--() {
			// Implement here
			return *this;
		}

		T operator*() const {
			return curr_->value;
		}

		bool operator==(const Iterator& rhs) {
			return curr_ == rhs.curr_;
		}

		bool operator!=(const Iterator& rhs) {
			return curr_ != rhs.curr_;
		}
	};

	BinarySearchTree() {
		root_ = new Node<T>();
		root_->parent = nullptr;
		root_->left = nullptr;
		root_->right = nullptr;
	}

	Node<T>* root() {
		return root_;
	}

	void push(T value) {
		Node<T>* node = root_;

		while(!is_leaf(node)) {
			if(value < node->value) {
				node = node->left;
			} else {
				node = node->right;
			}
		}
		node->value = value;
		node->left = create_leaf_node<T>(node);
		node->right = create_leaf_node<T>(node);
	}

	Iterator find_elt(T value) {
		Node<T>* node = root_;
		while(!is_leaf(node)) {
			if(node->value == value) {
				return Iterator(node);
			}
			if(value < node->value) {
				node = node->left;
			} else {
				node = node->right;
			}
		}
		return Iterator(nullptr);
	}

	void remove_elt(Iterator it) {
		// Implement here
		// Be sure to free the memory of the node iterator points
	}

	Iterator begin() {
		Node<T>* node = root_;
		while(!is_leaf(node)) {
			node = node->left;
		}
		return Iterator(node->parent);
	}

	Iterator end() {
		return Iterator(nullptr);
	}

	~BinarySearchTree() {
		TreeTraversaler traversaler([](Node<T>* node) {
			delete node;
		});
		traversaler.postorder(root_);
	}
};


template<typename Func>
class TreeTraversaler {
private:
	Func visitor_;
public:
	TreeTraversaler(Func&& visitor)
		: visitor_(std::forward<Func>(visitor)){
	}

	template<typename T>
	void postorder(Node<T>* node) {
		if (node == nullptr) {
			return ;
		}
		postorder(node->left);
		postorder(node->right);
		visitor_(node);
	}

	template<typename T>
	void preorder(Node<T>* node) {
		if (node == nullptr) {
			return ;
		}
		visitor_(node);
		preorder(node->left);
		preorder(node->right);
	}

	template<typename T>
	void inorder(Node<T>* node) {
		if (node == nullptr) {
			return ;
		}
		inorder(node->left);
		visitor_(node);
		inorder(node->right);
	}
};

