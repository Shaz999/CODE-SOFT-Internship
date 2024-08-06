#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Load Image
    string image_path;
    cout << "Enter image path: ";
    cin >> image_path;
    Mat image = imread(image_path);

    if (image.empty())
    {
        cerr << "Error loading image!" << endl;
        return -1;
    }

    // Display Original Image
    namedWindow("Original Image", WINDOW_NORMAL);
    imshow("Original Image", image);
    waitKey(0);

    // Convert to Grayscale
    Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);

    // Apply Gaussian Blur
    Mat blur_image;
    GaussianBlur(image, blur_image, Size(5, 5), 0);

    // Sharpen Image
    Mat sharpen_image;
    addWeighted(image, 1.5, blur_image, -0.5, 0, sharpen_image);

    // Adjust Color
    Mat adjusted_image;
    image.convertTo(adjusted_image, -1, 1.2, 20);

    // Crop Image
    Rect crop_region(100, 100, 300, 300);
    Mat cropped_image = image(crop_region);

    // Resize Image
    Mat resized_image;
    resize(image, resized_image, Size(), 0.5, 0.5);

    // Save Processed Image
    if (!imwrite("processed_image.jpg", resized_image))
    {
        cerr << "Error saving image!" << endl;
        return -1;
    }

    // Display Processed Image
    namedWindow("Processed Image", WINDOW_NORMAL);
    imshow("Processed Image", resized_image);
    waitKey(0);

    return 0;
}
