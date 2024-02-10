import QtQuick 2.15
import QtQuick.Window 2.14
import QtQuick3D 1.15
import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Controls 2.15




    View3D {

        property double roll: 0
             property double yaw: 0
             property double pitch: 0
        id: view
        anchors.fill: parent
        camera: camera
        renderMode: View3D.Overlay

        PerspectiveCamera {
            id: camera
            position: Qt.vector3d(0, 200, 300)

            eulerRotation.x: -30
        }

        DirectionalLight {
            eulerRotation.x: 10
        }

        Model {

            id: cylinder
            visible: true
            position: Qt.vector3d(0, 30, 0)

            source: "#Cylinder"


          materials: DefaultMaterial {
          diffuseColor: cylinder.isPicked ? "yellow" : "green"
          specularAmount: 4
          specularRoughness: 4
          roughnessMap: Texture { source: "/skin1.jpg" }


                   }





                     scale.x: 0.8
                     scale.y: 1.6
                     scale.z: 0.8
                     pickable: true
                     property bool isPicked: false
                     PropertyAnimation on eulerRotation.x {
                                                          loops: Animation.Infinite
                                                          duration: 1000
                                                          to: roll
                                                          from: 0
                     }

                                          PropertyAnimation on eulerRotation.y {
                                                          loops: Animation.Infinite
                                                          duration: 1000
                                                          to: yaw
                                                          from: 0
                     }
                                          PropertyAnimation on eulerRotation.z {
                                                          loops: Animation.Infinite
                                                          duration: 1000
                                                          to: pitch
                                                          from: 0
                     }
}


Timer {
                                 id: updateTimer
                                 interval: 1000// Update every 1000 milliseconds (1 second)
                                 repeat: true
                                 running: true

                                 onTriggered: {


                    eulerFunction(roll, yaw, pitch)
                                       console.log(roll, yaw, pitch)
}




}

            function eulerFunction(roll, yaw, pitch){
cylinder.eulerRotationChanged(roll - rolll, yaw - yaww, pitch - pitchh)
                roll = rolll
                yaw = yaww
                pitch = pitchh





            }









        Rectangle {


            anchors.fill: parent
            color: "#FFFFFF"

            Image {
               anchors.fill: parent

                source: "space.jpg"
                anchors.left:parent.left
                anchors.top: parent.top
            }
            Image {
                width:170
                height:170
                source: "itutayf0.png"
                anchors.top: parent.top
                anchors.right: parent.right
            }
            Text {
                id: text
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: "#000000"
                font.pixelSize: 20
                text: qsTr(" 3D CANSAT MODEL")
                font.family: "Gill Sans"
                font.bold: true
                style: Text.Outline
            }
            Text {
                    id: textt

                    anchors.centerIn: parent.Center
                    color: "#000000"
                    font.pixelSize: 15
                    text: qsTr(" ROLL   YAW   PITCH")
                    font.family: "Gill Sans"
                    font.bold: true
                    style: Text.Outline
            }
}
        }




