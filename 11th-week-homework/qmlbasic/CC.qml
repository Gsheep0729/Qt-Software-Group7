import QtQuick

Item{
    id: cc

    property string message: "in CompositeComponent object"

    component MyType: Rectangle {
        width: 50;  height: 20;
        color:ListView.isCurrentItem ? "red" : "blue"
        TapHandler{
            onTapped: {
                //currentIndex是ListView对象的property, index是当前视图item的property
                currentIndex = index
                console.log("currentIndex = ", currentIndex)
                console.log("index = ", index)
            }
        }
        Component.onCompleted:{
            console.log(root.message)
            console.log(cc.message)
            console.log(index)
        }
    }
}
