#ifndef QTCV_H
#define QTCV_H

//#include <QQuickImageProvider>
#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>
//#include <QOpenCVProcessing.hpp>

using namespace cv;
using namespace std;

class QtCV : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString inputFilePath READ getInputFilePath WRITE setInputFilePath NOTIFY onInputFilePathChange)
public:
    explicit QtCV(QObject *parent = nullptr);

    QString getInputFilePath();
    void setInputFilePath(QString &getInputFilePath);

signals:
    void onInputFilePathChange();

private:
    QImage _outputImage;
    void findLines(Mat sourceImage, Mat destinationImage);

};

#endif // QTCV_H
