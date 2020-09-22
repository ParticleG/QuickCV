import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import QtCV 1.0

ApplicationWindow {
    id: main_applicationWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("甜度测量测试")
    QtCV {
        id: qtcv
    }
    Rectangle {
        width: 400
        height: 300
        anchors.centerIn: parent
        Image {
            id: resultImage
            anchors.fill: parent
            cache: false
            Component.onCompleted:{
                source = "file:///storage/emulated/0/Pictures/test.jpg"
            }
        }
    }
    Button {
        id: cvTest_button
        anchors.centerIn: parent
        text: qsTr("/storage/emulated/0/Pictures")
        onClicked: {
            qtcv.inputFilePath = "/storage/emulated/0/Pictures/test.jpg"
            resultImage.source = "file:///storage/emulated/0/Pictures/output.jpg"
        }
    }
}
