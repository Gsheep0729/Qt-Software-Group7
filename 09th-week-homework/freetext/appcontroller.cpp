#include "appcontroller.h"
#include "window.h"
#include "textedit.h"
#include "documentstorage.h"
#include <QTextDocument>

AppController::AppController()
    : _window(new Window(this))
    , _textEdit(nullptr)
    , _ds(nullptr)
{
    _textEdit = qobject_cast<TextEdit *>(_window->centralWidget());
    _ds = new DocumentStorage(this);

    _window->setWindowTitle(_textEdit->title());

    connect(_textEdit->document(), &QTextDocument::modificationChanged, [this](bool changed) {
        _window->setWindowTitle(_textEdit->title());
        _window->setWindowModified(changed);
    });
}

AppController::~AppController()
{
    delete _window;
}

void AppController::currentState(bool &titled, bool &modified)
{
    titled = _textEdit->isTitled();
    modified = _textEdit->document()->isModified();
}

AppController &AppController::singleton()
{
    static AppController controller;
    return controller;
}

bool AppController::save()
{
    bool modified, titled;
    currentState(titled, modified);

    if (titled && !modified) {
        return true;
    } else if (titled && modified) {
        QString text = _textEdit->toPlainText();
        QString fp = _textEdit->filePath();
        bool ok = _ds->writeFile(fp, text);
        if (ok) {
            _textEdit->setModified(false);
        }
        return ok;
    }

    QString filePath = _window->getSaveFilepath();
    if (filePath.isEmpty()) return false;

    QString text = _textEdit->toPlainText();
    _textEdit->setFilePath(filePath);
    bool ok = _ds->writeFile(filePath, text);
    if (ok) {
        _textEdit->setModified(false);
    }
    return ok;
}
