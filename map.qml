import QtQuick 2.15
import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.15

Rectangle {
    property double oldlat: 200.6585
    property double oldlng: 100.1158
    Plugin {
        id: mapPlugin
        name: "osm"
    }


    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
      center: QtPositioning.coordinate(oldlat, oldlng);
       zoomLevel: 15

    }
    Timer {
                id: updateTimer
                interval: 1000 // Update every 1000 milliseconds (1 second)
                repeat: true
                running: true

                onTriggered:
                {

                setCenter(oldlat, oldlng)

                }


    }
    function setCenter(lat, lng){
        mapView.pan(oldlat - lat, oldlng - lng)
        oldlat = lat
        oldlng = lng
    }

}
