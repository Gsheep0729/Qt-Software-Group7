/**
* @file    worker.cpp
* @date    2026-04-05
* @author  GY
* @brief   Worker业务逻辑类的实现文件
*
* 本文件实现了Worker类，该类在子线程中执行耗时任务。
* 主要内容包括：
* 1. Worker构造函数的实现
* 2. doWork()槽函数的实现，模拟耗时操作
* 3. 输出当前线程信息，用于调试验证
*
* Change Log:
* [v1.0] GY   2026-04-05
* * Initial creation
*/
#include "worker.h"
#include <QDebug>
#include <QThread>

Worker::Worker(QObject *parent) : QObject{parent} {}

void Worker::doWork() {
    // 输出当前线程ID，验证是否在子线程中执行
    qDebug() << "Worker: doing work in thread:" << QThread::currentThread();

    // 模拟耗时操作：休眠2秒
    // 在实际应用中，这里可以是文件IO、网络请求、数据处理等耗时任务
    QThread::msleep(2000);

    // 发送任务完成信号，通知主线程
    emit workDone();
}