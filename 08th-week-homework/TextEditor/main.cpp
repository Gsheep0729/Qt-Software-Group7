/**
* @file    main.cpp
* @date    2026-04-27
* @author  GY
* @brief   应用程序入口
*
* Change Log:
* [v1.0] GY   2026-04-27
* * Initial creation
* [v2.0] GY   2026-04-27
* * 完成信号连接，使用 AppController 完成初始化
* [v3.0] GY   2026-04-27
* * 启用全局单例模式，引入底层存储模块完成整体架构
*/

#include <QApplication>
#include "AppController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 第三次提交：使用单例模式获取 Controller
    AppController::instance().launch();

    return QCoreApplication::exec();
}
