// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*****************************************************************************************************************
 *
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/

#pragma once

#include <smacc2/smacc.hpp>
#include <nav2z_client/nav2z_client.hpp>
#include <nav2z_client/client_behaviors.hpp>
namespace sm_husky_barrel_search_1
{
    using namespace smacc2::default_events;
    using namespace cl_nav2z;
    using namespace smacc2;

    // STATE DECLARATION
    struct StNavigateToWaypointX : smacc2::SmaccState<StNavigateToWaypointX, SmHuskyBarrelSearch1>
    {
        using SmaccState::SmaccState;

        // TRANSITION TABLE
        typedef mpl::list<

            //Transition<EvWaypoint0<ClNav2Z, OrNavigation>, StDeactivateMine, SUCCESS>,
            Transition<EvWaypoint0<ClNav2Z, OrNavigation>, StLedBlinkingCommuncation, SUCCESS>, // entrance to station
            // Transition<EvWaypoint1<ClNav2Z, OrNavigation>, StMoveBackwardsBlinking, SUCCESS>,
            Transition<EvWaypoint1<ClNav2Z, OrNavigation>, StNavigateToWaypointX, SUCCESS>,
            Transition<EvWaypoint2<ClNav2Z, OrNavigation>, StNavigateToWaypointX, SUCCESS>,
            Transition<EvWaypoint3<ClNav2Z, OrNavigation>, StNavigateToWaypointX, SUCCESS>,
            Transition<EvWaypoint4<ClNav2Z, OrNavigation>, StNavigateToWaypointX, SUCCESS>,
            Transition<EvWaypoint5<ClNav2Z, OrNavigation>, StNavigateToWaypointX, SUCCESS>,
            Transition<EvWaypoint6<ClNav2Z, OrNavigation>, StNavigateToWaypointX, SUCCESS>,
            Transition<EvWaypoint7<ClNav2Z, OrNavigation>, StNavigateToWaypointX, SUCCESS>,

            // Transition<EvWaypoint2<ClNav2Z, OrNavigation>, SS5::SsSPattern1, SUCCESS>,
            // Transition<EvCbSuccess<cl_nav2z::CbNavigateNextWaypoint, OrNavigation>, StNavigateToWaypointX>
            Transition<EvCbFailure<cl_nav2z::CbNavigateNextWaypoint, OrNavigation>, StNavigateToWaypointX>
            >
            reactions;

        // STATE FUNCTIONS
        static void staticConfigure()
        {
            // configure_orthogonal<OrLED, CbLEDOn>();
            // configure_orthogonal<OrObstaclePerception, CbLidarSensor>();
            configure_orthogonal<OrNavigation, CbNavigateNextWaypoint>();
        }

        void runtimeConfigure()
        {
        }
    };
} // namespace sm_husky_barrel_search_1
