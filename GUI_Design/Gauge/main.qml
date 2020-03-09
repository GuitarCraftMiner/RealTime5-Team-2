import QtQuick 2.7
import QtQuick.Controls 2.0

ApplicationWindow {
    id: window
    width: 500
    height: 500
    visible: true

    header: Label {
        text: "    Wind Turbine Pitch Blade Control"
        font.pixelSize: 30
        font.bold: True
        color: "midnightblue"
    }

    Gauge {
        property bool accelerating

        value: accelerating ? maximumValue : 0
        maximumValue: 100
        anchors {
            fill: parent
            margins: window.height * 0.005
        }

        Component.onCompleted: forceActiveFocus()

        Behavior on value { NumberAnimation { duration: 1000 }}

        Keys.onSpacePressed: accelerating = true
        Keys.onReleased: {
            if (event.key === Qt.Key_Space) {
                accelerating = false;
                event.accepted = true;
            }
        }
    }

    footer: Label {
        text: "  Real Time Embedded Programming Team 2"
        font.pixelSize: 15
        font.bold: True
        color: "black"
    }
}


