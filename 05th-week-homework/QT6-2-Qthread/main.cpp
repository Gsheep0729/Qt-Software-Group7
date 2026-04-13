#include <QThread>
#include <QCoreApplication>
#include <QDebug>
#include <QObject>

// Worker 类定义
class Worker : public QObject
{
    Q_OBJECT
public:

signals:
    void workDone();

public slots:
    void doWork()
    {
        qDebug() << "doing work...";
        emit workDone();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto thread = new QThread;
    auto worker = new Worker;

    // 信号槽连接
    QObject::connect(thread, &QThread::started, worker, &Worker::doWork);
    QObject::connect(worker, &Worker::workDone, thread, &QThread::quit);

    QObject::connect(thread, &QThread::finished, worker, &Worker::deleteLater);
    worker->moveToThread(thread);

    thread->start();

    return a.exec();
}

#include "main.moc"