#pragma once

#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

namespace pamsi {
template <typename T>
struct GraphNode {
    std::shared_ptr<GraphNode> parent_ = nullptr;
    std::vector<std::shared_ptr<GraphNode>> children_ = nullptr;
    double cost_;
    std::size_t depth_;

    GraphNode(std::shared_ptr<GraphNode> parent):

        void add_child(GraphNode child) {
        children.push_back(child);
    }
};

template <typename T>
class Graph {
   public:
    Graph() {}

   private:
};
}  // namespace pamsi