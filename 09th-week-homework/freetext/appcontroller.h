#pragma once
#include <QObject>

class Window;
class TextEdit;
class DocumentStorage;

class AppController : public QObject
{
    Q_OBJECT
public:
    static AppController &singleton();

    bool save();

private:
    AppController();
    ~AppController() noexcept;

    void currentState(bool &titled, bool &modified);

    Window *_window;
    TextEdit *_textEdit;
    DocumentStorage *_ds;
};