# Vision-Vanguard-Advanced-Face-Detection-with-OpenCV in C++

## Description
This C++ program demonstrates how to use OpenCV to process a video file, resize each frame to 640x640 pixels, and save the resized frame as "image.jpg". 
## Requirements
- C++ compiler
- OpenCV library (version 3.x or above)

## Usage
1. Compile the C++ code using a C++ compiler, ensuring that OpenCV is properly linked.
    ```
    g++ -o opencvPro opencvPro.cpp `pkg-config --cflags --libs opencv`
    ```
2. Place the input video file (e.g., "input_video.mp4") in the same directory as the compiled executable.
3. Run the compiled executable.
    ```
    ./opencvPro
    ```
4. The program will process the video file, resize each frame to 640x640 pixels, save the resized frame as "image.jpg".
5. Once the program finishes execution, you will find the processed frames saved as "image.jpg" and the output video file "output_video.avi" in the same directory as the executable.

## File Structure
- `opencvPro.cpp`: C++ source code implementing the frame processing and resizing functionality.
- `input_video.mp4`: Sample input video file (replace with your own video file).
- `README.md`: This README file providing instructions and information about the program.

## License
This project is licensed under the [MIT License](LICENSE).
