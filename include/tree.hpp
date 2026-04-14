#pragma once

#include <cstddef>
#include <cmath>
#include <limits>
#include <vector>

class Tree {
   public:
    struct Node {
        Node *parent;
        std::vector<Node *> children;
        int x, y;

        Node();
        Node(const Node &node);
        Node(int x, int y);
        Node &operator=(const Node &node);
    };

    Tree(const Node &start);

    Tree(const Tree &tree) = delete;
    Tree &operator=(const Tree &tree) = delete;

    ~Tree();

    size_t size();
    Node *get_root();
    Node *get_latest();
    Node *get_nearest(const Node &q_new);
    void insert(Node *q, const Node &q_new);

   private:
    size_t size_;
    Node *root;
    Node *latest;
};