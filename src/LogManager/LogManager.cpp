#include "LogManager.h"

Q_GLOBAL_STATIC(UGC::LogModel, debug_model)
static QtMessageHandler old_handler;

static void msgHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    const char symbols[] = { 'D', 'E', '!', 'X', 'I' };
    QString time = QDateTime::currentDateTime().toString("yyyy-mm-dd hh:mm:ss");
    QString output = QString("[%1][%2 at %3:%4] -> %5").arg(time).arg(symbols[type]).arg(context.file).arg(context.line).arg(msg);

    // Avoid recursion
    if (!QString(context.category).startsWith("qt.quick")) {
        debug_model->log(output);
    }

    if (old_handler != nullptr) {
        old_handler(type, context, msg);
    }
    if( type == QtFatalMsg ) abort();
}

void UGC::LogManager::installHandler()
{
    old_handler = qInstallMessageHandler(msgHandler);
    Q_UNUSED(*debug_model);
}

UGC::LogModel *UGC::LogManager::getModel()
{
    return debug_model;
}

UGC::LogModel::LogModel() : QStringListModel()
{
    Qt::ConnectionType contype = Qt::AutoConnection;
    connect(this, &LogModel::emitLog, this, &LogModel::threadsafeLog, contype);
}

void UGC::LogModel::writeMessages(const QString dest_file)
{
    const QString writebuffer(stringList().join('\n').append('\n'));

    QFuture<void> future = QtConcurrent::run([dest_file, writebuffer] {
        emit debug_model->writeStarted();
        bool success = false;
        QFile file(dest_file);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << writebuffer;
            success = out.status() == QTextStream::Ok;
        } else {
            qWarning() << "AppLogModel::writeMessages write failed:" << file.errorString();
        }
        emit debug_model->writeFinished(success);
    });
}

void UGC::LogModel::log(const QString message)
{
    emit debug_model->emitLog(message);
}

void UGC::LogModel::threadsafeLog(const QString message)
{
    const int line = rowCount();
    insertRows(line, 1);
    setData(index(line), message, Qt::DisplayRole);

    if (mLogFile.fileName().isEmpty()) {
        qDebug() << mLogFile.fileName().isEmpty();
        QString saveDirPath = "";
        QDir saveDir(saveDirPath);
        QString saveFilePath = saveDir.absoluteFilePath(QStringLiteral("UGroundControl.log"));

        mLogFile.setFileName(saveFilePath);
        if (!mLogFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << tr("Open console log output file failed %1 : %2").arg(mLogFile.fileName()).arg(mLogFile.errorString());
        }
    }

    if (mLogFile.isOpen()) {
        QTextStream out(&mLogFile);
        out << message << "\n";
        mLogFile.flush();
    }
}
