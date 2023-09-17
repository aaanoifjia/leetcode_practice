// There are some spherical balloons taped onto a flat wall that represents the
//  XY-plane. The balloons are represented as a 2D integer array points where 
//  points[i] = [xstart, xend] denotes a balloon whose horizontal diameter 
//  stretches between xstart and xend. You do not know the exact y-coordinates 
//  of the balloons.

// Arrows can be shot up directly vertically (in the positive y-direction) from 
// different points along the x-axis. A balloon with xstart and xend is burst by 
// an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

// Given the array points, return the minimum number of arrows that must be shot 
// to burst all balloons.

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0; 
        sort(points.begin(), points.end(),  // O(nlogn)
            [&](const pair<int, int>& a, const pair<int, int>& b){
                return a[1] <= b[1];  // notice
            });
        int asw = 1;
        int right = points[0][1]; 
        for (int i = 1; i < points.size(); ++i){
            if (points[i][0] > right){
                ++asw;
                right = points[i][1];
            }
        }
        return asw; 
    }
};