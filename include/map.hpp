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

class Map {
   public:
    Map(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: could not open file " << filename << std::endl;
            exit(1);
        }

        file >> rows_ >> cols_;
        cells_.resize(rows_ * cols_);
        for (int i = 0; i < rows_ * cols_; i++) {
            int value;
            file >> value;
            cells_[i] = static_cast<uint8_t>(value);
        }
    }

    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
    size_t size() const { return cells_.size(); }
    uint8_t at(size_t i, size_t j) const { return cells_[i * cols_ + j]; }

    void mark_visited(size_t i, size_t j) {
        if (i < rows_ && j < cols_) {
            cells_[i * cols_ + j] = 2;
        }
    }
    void mark_path(size_t i, size_t j) {
        if (i < rows_ && j < cols_) {
            cells_[i * cols_ + j] = 3;
        }
    }

    bool is_in_bounds(size_t i, size_t j) const {
        return i < rows_ && j < cols_;
    }

    bool is_obstacle(size_t i, size_t j) const {
        return at(i, j) == 0;
    }

    bool is_open(size_t i, size_t j) const {
        return at(i, j) == 1;
    }

    bool is_visited(size_t i, size_t j) const {
        return at(i, j) == 2;
    }

    bool is_path(size_t i, size_t j) const {
        return at(i, j) == 3;
    }
    
   private:
    size_t rows_;
    size_t cols_;
    std::vector<uint8_t> cells_;
};