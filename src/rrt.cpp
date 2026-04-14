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
    Tree::Node start(start_x, start_y);
    Tree tree(start);
    Tree::Node goal(goal_x, goal_y);

    for (int i = 0; i < max_iterations; ++i) {
        Tree::Node q_rand = random_config(map, goal);

    if (extend(tree, q_rand)) {
        Tree::Node *latest = tree.get_latest();

        map.mark_visited(latest->x, latest->y);

        double dx = goal.x - latest->x;
        double dy = goal.y - latest->y;
        double distance = std::sqrt(dx * dx + dy * dy);

        if (distance , step_length) {
            Path path;
            Tree::Node *current = latest;

            while (current != nullptr) {
                path.push_back({current->x, current->y});
                current = current->parent;
            }
            return path;
        }
    }
    }

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
    Tree::Node *q_near = tree.get_nearest(q_rand);

    double dx = q_rand.x - q_near->x;
    double dy = q_rand.y - q_near->y;
    double distance = std::sqrt(dx * dx + dy * dy);

    if (distance > 0) {
        dx = dx / distance * step_length;
        dy = dy / distance * step_length;

    }

    int new_x = q_near->x + static_cast<int>(std::ceil(dx));
    int new_y = q_near->y + static_cast<int>(std::ceil(dy));

    if (!map.is_in_bounds(new_x, new_y) || map.is_obstacle(new_x, new_y)) {
        return false;
    }

    Tree::Node q_new(new_x, new_y);
    tree.insert(q_near, q_new);

    return true;
}
