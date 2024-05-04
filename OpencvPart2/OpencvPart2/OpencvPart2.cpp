#include <opencv2/opencv.hpp>
#include <iostream>
#include <sys/stat.h> // For Unix-like systems
#include <direct.h>   // For Windows systems

using namespace cv;

bool createDirectory(const char* path) {
#ifdef _WIN32
    if (_mkdir(path) != 0) {
#else
    if (mkdir(path, 0777) != 0) {
#endif
        std::cerr << "Error creating directory: " << path << std::endl;
        return false;
    }
    return true;
    }

int main() {
    // Load the image
    Mat image = imread("image.jpg");

    // Convert the image to grayscale
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // Create a face detector
    CascadeClassifier face_cascade;
    face_cascade.load("haarcascade_frontalface_default.xml");

    // Detect faces in the image
    std::vector<Rect> faces;
    face_cascade.detectMultiScale(gray, faces);

    // Get the directory path of the input image
    std::string imagePath = "image";
    size_t lastSlash = imagePath.find_last_of('/');
    std::string folderName = imagePath.substr(0, lastSlash);

    // Create a folder with the same name as the image folder
    if (!createDirectory(folderName.c_str())) {
        return 1;
    }

    // Save the faces to the created folder
    for (size_t i = 0; i < faces.size(); i++) {
        Mat face = gray(faces[i]);
        std::string filename = folderName + "/face_" + std::to_string(i) + ".jpg";
        imwrite(filename, face);
    }

    return 0;
}
