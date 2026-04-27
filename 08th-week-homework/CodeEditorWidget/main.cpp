/**
* @file    main.cpp
* @date    2026-04-22
* @author  GY
* @brief   应用程序主入口
*
* 将启动流程委托给 EditorController。
* 实现主流程逻辑与特定 UI 的解耦。
*
* Change Log:
* [v1.0] GY   2026-04-22
* * Initial creation
*/

#include <QApplication>
#include "EditorController.h"

int main(int argc, char *argv[])
{
    // 初始化 Qt 应用程序对象，处理命令行参数
    QApplication app(argc, argv);

    // 调用单例控制器的启动方法，进入业务装配流程
    EditorController::instance().launch();

    // 进入事件循环，直到应用程序退出
    return app.exec();
}