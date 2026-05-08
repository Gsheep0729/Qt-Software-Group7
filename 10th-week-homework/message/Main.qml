import QtQuick
import se.qt.message

Window{
    visible: true;
    width: 400; height: 50;
    title: qsTr("Register an instantibal object type")
    Message{
        id:m
        author:"Amelie"
        creationDate: new Date()
    }
    Column{
        Text {
            text: m.author;color: "red"
        }
        Text {
            text: m.creationDate; color: "blue"
        }
    }

}
