import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4
import QtQuick.Extras.Private 1.0
import QtGraphicalEffects 1.0

CircularGauge {
    id: gauge

    style: CircularGaugeStyle {
        labelStepSize: 10
        labelInset: outerRadius / 2.2
        tickmarkInset: outerRadius / 4.2
        minorTickmarkInset: outerRadius / 4.2
        minimumValueAngle: -90
        maximumValueAngle: 90

        background: Canvas {
            onPaint: {
                var ctx = getContext("2d");
                ctx.reset();
                ctx.beginPath();
                ctx.strokeStyle = "#e34c22"
                ctx.lineWidth = outerRadius
                ctx.arc(outerRadius,
                      outerRadius,
                      outerRadius - ctx.lineWidth / 2,
                      degreesToRadians(valueToAngle(gauge.value) - 90),
                      degreesToRadians(valueToAngle(gauge.maximumValue + 1) - 90));
                ctx.stroke();
            }
        }

        needle: Rectangle {
            y: outerRadius * 0.15
            implicitWidth: outerRadius * 0.03
            implicitHeight: outerRadius * 0.6
            antialiasing: true
            color: '#869187'
        }

        tickmarkLabel:  Text {
            font.pixelSize: Math.max(6, outerRadius * 0.05)
            text: styleData.value
            color: styleData.value >= 66 ? "darkred" : "#777776" | styleData.value <= 33 ? "gold" : "#777776" | 33 <= styleData.value <= 66 ? "forestgreen" : "#777776"
            antialiasing: true
        }

        /*tickmark: Image {
            source: "qrc:/img/tickmark.svg"
            width: outerRadius * 0.018
            height: outerRadius * 0.15
            antialiasing: true
            asynchronous: true
        }*/

        tickmark: Rectangle {
            implicitWidth: outerRadius * 0.02
            implicitHeight: outerRadius * 0.15
            antialiasing: true
            color: styleData.value >= 66 ? "darkred" : "#777776" | styleData.value <= 33 ? "gold" : "#777776" | 33 <= styleData.value <= 66 ? "forestgreen" : "#777776"

        }

        minorTickmark: Rectangle {
            implicitWidth: outerRadius * 0.01
            implicitHeight: outerRadius * 0.03
            antialiasing: true
            smooth: true
            color: styleData.value >= 66 ? "darkred" : "#777776" | styleData.value <= 33 ? "gold" : "#777776" | 33 <= styleData.value <= 66 ? "forestgreen" : "#777776"

        }
    }
}
