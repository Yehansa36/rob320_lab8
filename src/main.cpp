#include "rrt.hpp"

// Helper function to update the map with the path value 
void update_map_with_path(Map& map, const RRT::Path& path) {
    for (const auto& node : path) {
        map.mark_path(node.first, node.second);
    }
}

// Helper function to print the map to stdout
void print_map(const Map& map) {
    std::cout << map.rows() << " " << map.cols() << std::endl;
    for (size_t i = 0; i < map.rows(); ++i) {
        for (size_t j = 0; j < map.cols(); ++j) {
            std::cout << static_cast<int>(map.at(i, j)) << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <map_file> <max_iterations> <step_length>" << std::endl;
        return 1;
    }

    std::string map_file = argv[1];
    int max_iterations = std::stoi(argv[2]);
    int step_length = std::stoi(argv[3]);

    Map map(argv[1]);
    RRT rrt(map, max_iterations, step_length);
    rrt.set_start(0, 0);
    rrt.set_goal(map.rows() - 1, map.cols() - 1);

    RRT::Path path = rrt.plan();

    if (!path.empty()) {
        update_map_with_path(map, path);
        print_map(map);
    } else {
        std::cerr << "No path found!" << std::endl;
        print_map(map);
        return 1;
    }

    return 0;
}