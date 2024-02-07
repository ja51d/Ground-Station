import QtQuick 2.15
import QtQuick.Window 2.14
import QtQuick3D 1.15
import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Controls 2.15




    View3D {
        property double roll:0
        property double yaw:20
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
            Rotation { angle: 20; axis: "50,50,20" }
            source: "#Cylinder"


          materials: DefaultMaterial {
          diffuseColor: cylinder.isPicked ? "yellow" : "green"
          specularAmount: 4
          specularRoughness: 4
          roughnessMap: Texture { source: "/skin1.jpg" }


                   }



                     eulerRotation.y: 90

                     scale.x: 0.8
                     scale.y: 1.6
                     scale.z: 0.8
                     pickable: true
                     property bool isPicked: false

                     SequentialAnimation on eulerRotation {
                         loops: Animation.Infinite
                         PropertyAnimation {
                             duration: 2500
                             from: Qt.vector3d(0, 0, 0)
                             to: Qt.vector3d(roll, yaw, pitch)
                         }







                     }
                     Timer {
                                 id: updateTimer
                                 interval: 1000 // Update every 1000 milliseconds (1 second)
                                 repeat: true
                                 running: true

                                 onTriggered: {
                                     // Simulate changing latitude and longitude

                    // eulerFunction(roll, yaw, pitch)
                                       console.log(roll, yaw, pitch)
}




}

            function eulerFunction(rolll, yaww, pitchh) {
cylinder.pan(roll - rolll, yaw - yaww, pitch - pitchh)
  console.log(roll, yaw, pitch)
                roll = rolll
                yaw = yaww
                pitch = pitchh





            }






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
                color: "#f30505"
                font.pixelSize: 20
                text: qsTr(" 3D CANSAT MODEL")
                font.family: "Gill Sans"
                font.bold: true
                style: Text.Outline
            }
            Text {
                    id: textt

                    anchors.centerIn: parent.Center
                    color: "#f30505"
                    font.pixelSize: 15
                    text: qsTr(" Rotation Coordinates: (360°, 50°, 360°)")
                    font.family: "Gill Sans"
                    font.bold: true
                    style: Text.Outline
            }
}
        }




