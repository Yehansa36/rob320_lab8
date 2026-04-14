#include "rrt.hpp"

RRT::RRT(Map &map, int max_iterations, int step_length)
    : PathPlanner(map),
      max_iterations(max_iterations),
      step_length(step_length) {
    assert(map.rows() > 0 && map.cols() > 0);
    assert(max_iterations > 0);
    assert(step_length > 0);
}

RRT::~RRT() {}

RRT::Path RRT::plan() {
    /**
     * TODO: Implement the RRT-Extend algorithm for motion planning in 2D. 
     * 
     * 1. Initialize a Tree with a Node with the start_x and start_y coordinates
     * 2. Generate q_rand using the create_random_q function from util.hpp
     * 3. Extend the tree towards q_rand
     * 4. If successful: 
     *    1. Mark the coordinates as visited on the map
     *    2. Calculate the distance between the extended Node and the goal
     *    3. If the distance is less than a step length:
     *       1. Return a Path object (std::vector<std::pair<int, int>>) that
     *          contains the coordinates from goal (path[-1]) to start (path[0])
     * 5. Otherwise, iterate until we reach the maximum number of iterations.
     */

    return {};
}

bool RRT::extend(Tree &tree, const Tree::Node &q_rand) const {
    /**
     * TODO: Extend the tree towards q_rand by a step_length from the nearest
     * neighbor of q_rand. If the new position is outside of the map bounds or
     * is occupied by an obstacle, return false. Otherwise, insert the new node
     * into the map and return true.
     * 
     * Hint: Use std::ceil to calculate the step size in the x and y directions.
     */

    return false;
}
