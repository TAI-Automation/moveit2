/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2012, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Ioan Sucan */

#pragma once

#include <moveit/warehouse/moveit_message_storage.hpp>
#include <moveit_msgs/msg/planning_scene_world.hpp>
#include <rclcpp/logger.hpp>

namespace moveit_warehouse
{
typedef warehouse_ros::MessageWithMetadata<moveit_msgs::msg::PlanningSceneWorld>::ConstPtr PlanningSceneWorldWithMetadata;
typedef warehouse_ros::MessageCollection<moveit_msgs::msg::PlanningSceneWorld>::Ptr PlanningSceneWorldCollection;

class PlanningSceneWorldStorage : public MoveItMessageStorage
{
public:
  static const std::string DATABASE_NAME;
  static const std::string PLANNING_SCENE_WORLD_ID_NAME;

  PlanningSceneWorldStorage(warehouse_ros::DatabaseConnection::Ptr conn);

  void addPlanningSceneWorld(const moveit_msgs::msg::PlanningSceneWorld& msg, const std::string& name);
  bool hasPlanningSceneWorld(const std::string& name) const;
  void getKnownPlanningSceneWorlds(std::vector<std::string>& names) const;
  void getKnownPlanningSceneWorlds(const std::string& regex, std::vector<std::string>& names) const;

  /** \brief Get the constraints named \e name. Return false on failure. */
  bool getPlanningSceneWorld(PlanningSceneWorldWithMetadata& msg_m, const std::string& name) const;

  void renamePlanningSceneWorld(const std::string& old_name, const std::string& new_name);

  void removePlanningSceneWorld(const std::string& name);

  void reset();

private:
  void createCollections();

  PlanningSceneWorldCollection planning_scene_world_collection_;
  rclcpp::Logger logger_;
};
}  // namespace moveit_warehouse
