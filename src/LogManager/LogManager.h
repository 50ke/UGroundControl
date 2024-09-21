#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QObject>
#include <QtCore/QStringListModel>
#include <QtCore/QFile>
#include <QDateTime>
#include <QtConcurrent/QtConcurrent>
#include <QtCore/QTextStream>

namespace UGC {

class LogModel : public QStringListModel{

    Q_OBJECT
public:
    LogModel();
    Q_INVOKABLE void writeMessages(const QString destFile);
    static void log(const QString message);

signals:
    void emitLog(const QString message);
    void writeStarted();
    void writeFinished(bool success);

private slots:
    void threadsafeLog(const QString message);

private:
    QFile mLogFile;
};

class LogManager
{
public:
    static void installHandler();
    static LogModel* getModel();
};

}

#endif // LOGMANAGER_H
