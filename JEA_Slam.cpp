#include <iostream>
#include <vector>

// Structure to represent a point in 2D space
struct Point {
    double x;
    double y;
};

// Dummy function to simulate wall detection
bool feelForWall(Point position) {
    // For the sake of demonstration, let's assume the robot detects a wall if it's close to the origin
    double distance_to_origin = std::sqrt(position.x * position.x + position.y * position.y);
    return distance_to_origin < 1.0; // If distance is less than 1 unit, consider it as a wall
}

// SLAM algorithm implementation
class HexapodSLAM {
private:
    std::vector<Point> map;
    Point currentPosition;

public:
    HexapodSLAM() {
        // Initialize the robot's position
        currentPosition.x = 0.0;
        currentPosition.y = 0.0;
    }

    // Move the robot to a new position and update the map
    void move(double deltaX, double deltaY) {
        currentPosition.x += deltaX;
        currentPosition.y += deltaY;

        // Check if the robot is close to a wall and update the map accordingly
        if (feelForWall(currentPosition)) {
            // If the current position is close to a wall, add it to the map
            map.push_back(currentPosition);
            std::cout << "Detected a wall at position (" << currentPosition.x << ", " << currentPosition.y << ")" << std::endl;
        }
    }

    // Print the map
    void printMap() {
        std::cout << "Map:" << std::endl;
        for (const auto& point : map) {
            std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
        }
    }
};

int main() {
    HexapodSLAM hexapod;

    // Move the hexapod around (simulate motion)
    hexapod.move(1.0, 0.0);
    hexapod.move(0.0, 1.0);
    hexapod.move(-1.0, 0.0);
    hexapod.move(0.0, -1.0);

    // Print the final map
    hexapod.printMap();

    return 0;
}
