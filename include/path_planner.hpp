#pragma once

#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "map.hpp"

class PathPlanner {
   public:
    typedef std::vector<std::pair<int, int>> Path;

    PathPlanner(Map& map)
        : map(map), start_x(-1), start_y(-1), goal_x(-1), goal_y(-1) {}

    void set_start(int x, int y) {
        if (!map.is_in_bounds(x, y) || map.is_obstacle(x, y)) {
            std::cerr << "Invalid start position!" << std::endl;
            return;
        }
        start_x = x;
        start_y = y;
    }

    void set_goal(int x, int y) {
        if (!map.is_in_bounds(x, y) || map.is_obstacle(x, y)) {
            std::cerr << "Invalid goal position!" << std::endl;
            return;
        }
        goal_x = x;
        goal_y = y;
    }

    virtual Path plan() = 0;

   protected:
    Map& map;
    int start_x, start_y, goal_x, goal_y;
};