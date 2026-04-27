#pragma once
#include <QObject>

class TextEdit;
class DocumentStorage;

class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(QObject *parent = nullptr);
    ~AppController();

    void setTextEdit(TextEdit *te);
    void setStorage(DocumentStorage *ds);
    void saveDocument();

private:
    TextEdit *textEdit = nullptr;
    DocumentStorage *storage = nullptr;
};