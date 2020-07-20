#ifndef GLOCAL_EXPLORATION_ROS_VISUALIZATION_RH_RRT_STAR_VISUALIZER_H_
#define GLOCAL_EXPLORATION_ROS_VISUALIZATION_RH_RRT_STAR_VISUALIZER_H_

#include <memory>
#include <string>

#include "glocal_exploration/planning/local/rh_rrt_star.h"
#include "glocal_exploration_ros/visualization/local_planner_visualizer_base.h"

namespace glocal_exploration {

class RHRRTStarVisualizer : public LocalPlannerVisualizerBase {
 public:
  struct Config {
    std::string nh_namespace = "";
    bool visualize_gain = true;
    bool visualize_text = true;
    bool visualize_visible_voxels = true;
    bool visualize_value = true;

    Config isValid() const { return Config(*this); }
  };
  RHRRTStarVisualizer(const Config& config,
                      const std::shared_ptr<LocalPlannerBase>& planner);

  void visualize() override;

 protected:
  Config config_;
  std::shared_ptr<RHRRTStar> planner_;
  ros::NodeHandle nh_;
  ros::Publisher pub_;

  // visualization namespaces
  const std::string value_ns_ = "candidate_trajectories";
  const std::string gain_ns_ = "candidate_gains";
  const std::string text_ns_ = "candidate_text";
  const std::string voxel_ns_ = "next_expected_gain";
};

}  // namespace glocal_exploration

#endif  // GLOCAL_EXPLORATION_ROS_VISUALIZATION_RH_RRT_STAR_VISUALIZER_H_