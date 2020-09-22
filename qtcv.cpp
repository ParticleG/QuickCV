#include "qtcv.h"

QtCV::QtCV(QObject *parent) : QObject(parent){}

QString QtCV::getInputFilePath() {
    return QString::fromStdString("=");
}

void QtCV::setInputFilePath(QString &getInputFilePath) {
    Mat rawImage = imread(getInputFilePath.toStdString()), inputImage, gaussianBluredImage, cannyImage, dilateImage, outputImage;
    resize(rawImage, inputImage, Size(), 0.5, 0.5, 3);
    GaussianBlur(inputImage,gaussianBluredImage, Size(35, 35), 0);
    Canny(gaussianBluredImage, cannyImage,20,30);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(15, 15));
    dilate(cannyImage, dilateImage, kernel);
    outputImage = inputImage.clone();
    findLines(dilateImage, outputImage);
    imwrite(getInputFilePath.left(getInputFilePath.lastIndexOf("/")).toStdString() + "/output.jpg", outputImage);
}

void QtCV::findLines(Mat sourceImage, Mat destinationImage) {
    vector<Vec4i> houghLines;
    HoughLinesP(sourceImage, houghLines, 1, CV_PI / 360,10, 1000, 5);
    for(const auto &houghLine : houghLines) {
        line(destinationImage, Point(houghLine[0], houghLine[1]), Point(houghLine[2], houghLine[3]), Scalar(0, 255, 0), 2);
    }
}
