#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Comparator function for sorting factories based on their positions
bool cmpfunc(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

// Function to calculate absolute distance between two points
int absoluteDistance(int a, int b) {
    return abs(a - b);
}

// Function to find minimum total distance traveled
int minTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
    // Sort robots and factories based on their positions
    sort(robots.begin(), robots.end());
    sort(factories.begin(), factories.end(), cmpfunc);

    int totalDistance = 0;
    vector<bool> usedRobots(robots.size(), false);

    for (auto& factory : factories) {
        int factoryPosition = factory[0];
        int factoryCapacity = factory[1];

        for (int i = 0; i < factoryCapacity; ++i) {
            int closestRobotIdx = -1;
            int minDistance = INT_MAX;

            // Find the closest available robot
            for (int j = 0; j < robots.size(); ++j) {
                if (!usedRobots[j]) {
                    int distance = absoluteDistance(robots[j], factoryPosition);
                    if (distance < minDistance) {
                        minDistance = distance;
                        closestRobotIdx = j;
                    }
                }
            }

            if (closestRobotIdx != -1) {
                totalDistance += minDistance;
                usedRobots[closestRobotIdx] = true;
                // Optionally update robot's position (if robots need to stay at the factory)
                robots[closestRobotIdx] = factoryPosition;
            }
        }
    }
    return totalDistance;
}

int main() {
    // Example usage
    vector<int> robots = {4, 7, 12, 2, 9};
    vector<vector<int>> factories = {{3, 2}, {8, 3}, {10, 1}, {5, 1}};

    int minDistance = minTotalDistance(robots, factories);
    cout << "Minimum total distance traveled: " << minDistance << endl;

    return 0;
}

