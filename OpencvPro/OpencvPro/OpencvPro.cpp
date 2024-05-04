#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() {
    // Adjustable frame rate (experiment for optimal value)
    double targetFrameRate = 20.0; // Frames per second

    // Calculate frame interval based on target frame rate
    double frameInterval = 1.0 / targetFrameRate;
    int desiredNumberOfFrames;
    cout << "Enter a Number of Frames you want" << endl;
    cin >> desiredNumberOfFrames;


    int frameCount = 0;
    while (1) {
        // Construct formatted command string with placeholders
        string command = "gst-launch-1.0 filesrc location=input.mp4 ! decodebin ! videoscale ! video/x-raw,width=640,height=640 ! jpegenc quality=90 ! filesink location=output_" + to_string(frameCount) + ".jpg";

        // Execute the command to capture a frame at the current interval
        int result = system(command.c_str());

        // Check for system call errors (optional)
        if (result != 0) {
            cerr << "Error: Gstreamer command failed." << endl;
            break;
        }

        // Use frameInterval for precise timing (replace sleep if needed)
        this_thread::sleep_for(chrono::milliseconds((int)(frameInterval * 1000)));

        frameCount++;

        // Optional: Stop after a certain number of frames
        if (frameCount >= desiredNumberOfFrames) {
            break;
        }
    }


    return 0;
}
