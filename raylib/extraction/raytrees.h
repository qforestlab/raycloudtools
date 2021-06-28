// Copyright (c) 2021
// Commonwealth Scientific and Industrial Research Organisation (CSIRO)
// ABN 41 687 119 230
//
// Author: Thomas Lowe
#ifndef RAYLIB_RAYEXTRACT_TREES_H
#define RAYLIB_RAYEXTRACT_TREES_H

#include "raylib/raylibconfig.h"
#include "../rayutils.h"
#include "../raycloud.h"


namespace ray
{
struct TreesNode
{
  TreesNode() : centroid(0,0,0), radius(0), num_points(0), parent(-1), id(-1), min_dist_from_ground(0.0) {}
  Eigen::Vector3d centroid;
  double radius;
  int num_points;
  int parent;
  int id; // 0 based per tree
  double min_dist_from_ground;
  std::vector<int> roots; // root points
  std::vector<int> children;
};    

struct Trees
{
  Trees(const Cloud &cloud, bool verbose);
  bool save(const std::string &filename);
  std::vector<TreesNode> tree_nodes;
  std::vector<int> root_nodes;
};

} // namespace ray
#endif // RAYLIB_RAYEXTRACT_TREES_H