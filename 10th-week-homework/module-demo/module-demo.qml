import QtQuick 2.15
import se.qt.MyModule 2

Column {
    spacing: 2

    MyTextConstants{id:constants}
    MyClock{color:"red"}
    MyTextBox{id:textBox}
    MyButton{
        text:qsTr("OK")
        onClicked:{
            textBox.textColor = "red"
            textBox.text = constants.welcomeText.arg("Ver 2.1")
            textBox.width = 150
        }
    }
}
