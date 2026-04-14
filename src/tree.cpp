#include "tree.hpp"

Tree::Node::Node() : x(0), y(0), parent(nullptr) {}

Tree::Node::Node(const Node &node)
    : x(node.x), y(node.y), parent(node.parent), children(node.children) {}

Tree::Node::Node(int x, int y) : x(x), y(y), parent(nullptr) {}

Tree::Node &Tree::Node::operator=(const Node &node) {
    if (this == &node) {
        return *this;
    }
    x = node.x;
    y = node.y;
    parent = node.parent;
    children = node.children;
    return *this;
}

Tree::Tree(const Node &start)
    : root(new Node(start)), latest(nullptr), size_(1) {}

Tree::~Tree() {
    std::vector<Node *> stack;
    stack.push_back(root);
    while (!stack.empty()) {
        Node *current = stack.back();
        stack.pop_back();
        for (Node *child : current->children) {
            stack.push_back(child);
        }
        delete current;
    }
}

size_t Tree::size() { return size_; }

Tree::Node *Tree::get_root() { return root; }

Tree::Node *Tree::get_latest() { return latest; }

Tree::Node *Tree::get_nearest(const Node &q_new) {
    /**
     * TODO: Implement the nearest neighbor search algorithm. This is an
     * O(n) algorithm that finds the nearest node in the tree to the given
     * node q_new. The nearest node is the one with the smallest Euclidean
     * distance to q_new. The function should return a pointer to the
     * nearest node.
     */
    std::vector<Node *> stack;
    stack.push_back(root);

    Node *nearest = root;
    double min_distance = std::sqrt(std::pow(root->x - q_new.x, 2) + std::pow(root->y - q_new.y, 2));

    while (!stack.empty()) {
        Node *current = stack.back();
        stack.pop_back();

        double distance = std::sqrt(std::pow(current->x - q_new.x, 2) + std::pow(current->y - q_new.y, 2));

        if (distance < min_distance) {
            min_distance = distance;
            nearest = current;

        }

        for (Node *child : current->children) {
            stack.push_back(child);
        }
    }

    return nearest;
}

void Tree::insert(Node *q, const Node &q_new) {
    /**
     * TODO: Add a new node to the tree structure. q_new should be copied onto
     * the heap and pushed into the children vector of q. q should be assigned
     * as the parent of q_new. Increment the size.
     */
    Node *new_node = new Node(q_new);
    new_node->parent = q;

    q->children.push_back(new_node);
    latest = new_node;
    size_++;
    
    return;
}