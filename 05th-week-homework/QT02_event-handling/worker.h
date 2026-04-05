/**
* @file    worker.h
* @date    2026-04-05
* @author  GY
* @brief   Worker业务逻辑类的头文件
*
* 本文件定义了Worker类，该类继承自QObject，专门用于执行
* 耗时的业务逻辑任务。Worker对象将被移动到子线程中执行，
* 以避免阻塞主线程（UI线程）。主要功能包括：
* 1. 执行耗时任务（doWork槽函数）
* 2. 任务完成后发送完成信号（workDone信号）
* 3. 禁用拷贝构造和赋值操作，防止意外复制
*
* Change Log:
* [v1.0] GY   2026-04-05
* * Initial creation
*/
#pragma once

#include <QObject>

/**
 * Worker业务逻辑类
 * 该类用于执行耗时任务，将被移动到子线程中运行。
* 通过信号槽机制与主线程通信，保证UI的响应性。
*/
class Worker : public QObject {
    Q_OBJECT

public:
    explicit Worker(QObject *parent = nullptr);

    // 禁用拷贝构造函数，防止对象被意外复制
    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;

    virtual ~Worker() override = default;

public slots:
    /**
     * 执行耗时任务
     * 该槽函数在子线程中被调用，用于执行耗时操作。
     * 示例中模拟了2秒的耗时操作。
     */
    void doWork();

signals:
    /**
     * 任务完成信号
     * 当doWork()任务执行完成后发出此信号，通知主线程
     * 任务已完成，可以执行后续操作（如清理资源）。
     */
    void workDone();
};