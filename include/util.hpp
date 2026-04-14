#pragma once

#include <random>
#include "tree.hpp"
#include "map.hpp"

inline Tree::Node random_config(const Map &map, const Tree::Node &goal) {
    static std::mt19937 gen(48104); // Use a fixed seed for deterministic behavior
    static std::bernoulli_distribution dis_goal(0.2);

    // Predefined map dimensions
    static std::uniform_int_distribution<int> dis_x(0, map.rows() - 1);
    static std::uniform_int_distribution<int> dis_y(0, map.cols() - 1);

    // 20% of the time, return the goal node
    if (dis_goal(gen)) {
        return goal;
    }

    // Otherwise, return a random node within the map bounds that is open
    while (true) {
        int x = dis_x(gen);
        int y = dis_y(gen);
        if (map.is_open(x, y)) {
            return Tree::Node(x, y);
        }
    }
}