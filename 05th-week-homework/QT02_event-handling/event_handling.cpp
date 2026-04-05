/**
* @file    event_handling.cpp
* @date    2026-04-05
* @author  GY
* @brief   Qt事件处理示例项目的主窗口实现文件
*
* 本文件实现了event_handling类，演示了Qt中如何正确使用QThread
* 和moveToThread来执行耗时任务。主要内容包括：
* 1. 创建子线程和工作对象
* 2. 将工作对象移动到子线程
* 3. 通过信号槽机制建立线程间通信
* 4. 实现线程的安全启动和清理
*
* Change Log:
* [v1.0] GY   2026-04-05
* * Initial creation
*/
#include "event_handling.h"
#include "./ui_event_handling.h"
#include "worker.h"
#include <QThread>
#include <QDebug>

event_handling::event_handling(QWidget *parent)
    : QMainWindow{parent}
    , _ui{new Ui::event_handling}
{
    _ui->setupUi(this);

    // 输出主线程ID，用于调试和验证线程分离
    qDebug() << "Main UI Thread:" << QThread::currentThread();

    // 步骤1：创建线程对象和工作对象
    // 注意：线程对象挂载到主窗口，会随主窗口销毁而销毁
    // 注意：Worker对象不能设置父对象，否则无法moveToThread
    QThread *workerThread = new QThread(this);
    Worker *worker = new Worker();

    // 步骤2：将Worker对象移动到子线程
    // 从此以后，Worker的所有槽函数都在子线程中执行
    worker->moveToThread(workerThread);

    // 步骤3：建立信号槽连接，使用现代强类型语法

    // 线程启动时触发Worker的工作槽函数
    connect(workerThread, &QThread::started, worker, &Worker::doWork);

    // Worker工作完成后，线程退出事件循环
    connect(worker, &Worker::workDone, workerThread, &QThread::quit);

    // 线程结束后，自动删除Worker对象
    connect(workerThread, &QThread::finished, worker, &Worker::deleteLater);

    // 步骤4：启动线程
    qDebug() << "Main: starting worker thread from:" << QThread::currentThread();
    workerThread->start();
}

event_handling::~event_handling() {
    // 手动释放UI对象指针
    delete _ui;
}