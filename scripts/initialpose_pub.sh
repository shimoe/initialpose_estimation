#!bin/bash
rostopic pub -r 10 /initialpose geometry_msgs/PoseWithCovarianceStamped '{header: {seq: 1.0, stamp: [1,1], frame_id: map}, pose: {pose: {position: {x: 1.0,y: 0.0,z: 0.0}, orientation: {x: 1.0,y: 0.0, z: 0.0, w: 1.0}}, covariance: [1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0]}}'
