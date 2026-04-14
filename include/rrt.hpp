#pragma once

#include <cassert>
#include <cstddef>
#include <cmath>
#include <random>
#include <algorithm>

#include "path_planner.hpp"
#include "tree.hpp"
#include "util.hpp"

class RRT : public PathPlanner {
   public:
    RRT(Map &map, int max_iterations, int step_length);
    ~RRT();

    Path plan() override;

   private:
    int max_iterations;
    int step_length;

    bool extend(Tree &tree, const Tree::Node &q_rand) const;
};