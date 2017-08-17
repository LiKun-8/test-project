import QtQuick 2.0
import QtQuick.Layouts 1.1

Item {
    id:imgBoxer
    width:940
    height:320
    Rectangle {
        id: window
        anchors.fill: parent

//        gradient: Gradient {
//            GradientStop { position: 0; color: "lightsteelblue" }
//            GradientStop { position: 1; color: "black" }
//        }



        ListView{
            model:imgModel
            delegate: delegate
        }

        ListModel{
            id:imgModel

        }

        Component{
            id:delegate
            RowLayout{

            }

        }

//        ShaderEffect {
//            anchors.top: img.bottom
//            width: img.width
//            height: img.height
//            anchors.left: img.left

//            property variant source: img
//            property size sourceSize: Qt.size(0.5 / img.width, 0.5 / img.height)

//            fragmentShader: "777
//                varying highp vec2 qt_TexCoord0;
//                uniform lowp sampler2D source;
//                uniform lowp vec2 sourceSize;
//                uniform lowp float qt_Opacity;
//                void main() {

//                    lowp vec2 tc = qt_TexCoord0 * vec2(1, -1) + vec2(0, 1);
//                    lowp vec4 col = 0.25 * (texture2D(source, tc + sourceSize)
//                                            + texture2D(source, tc- sourceSize)
//                                            + texture2D(source, tc + sourceSize * vec2(1, -1))
//                                            + texture2D(source, tc + sourceSize * vec2(-1, 1))
//                                           );
//                    gl_FragColor = col * qt_Opacity * (1.0 - qt_TexCoord0.y) * 0.2;
//                }"
//        }
    }
}
