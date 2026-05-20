import QtQuick

ListView {
    id:root

    property string message: "in ListView object"
    width: 200;    height: 200;   spacing: 2
    model:5
    // @disable-check M300
    delegate: CC.MyType{}

    // CC { id:myDelegate }
}
