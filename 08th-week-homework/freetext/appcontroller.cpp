#include "appcontroller.h"

#include "window.h"
#include "textedit.h"
#include "documentstorage.h"

AppController::AppController()
    : _window(new Window(this))
    , _textEdit(nullptr)
    , _ds(nullptr)
{
    _textEdit = qobject_cast<TextEdit *>(_window->centralWidget());
    _ds = new DocumentStorage(_window);
    _window->show();

    _window->setWindowTitle(_textEdit->title());
    QObject::connect(_textEdit->document(), &QTextDocument::modificationChanged, [this](bool changed) {
        _window->setWindowTitle(_textEdit->title());
        _window->setWindowModified(changed);
    });
}

AppController::~AppController() noexcept
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
    bool modified;
    bool titled;
    currentState(titled, modified);

    if (titled && !modified) {
        return true; //r1
    } else if (titled && modified) {
        auto text = _textEdit->toPlainText();
        auto fp = _textEdit->filePath();
        auto wf = _ds->writeFile(fp, text);
        // qDebug() << _text->document()->isModified() << "in FreeText::save() titled && modified";
        if (!wf) {
            return false;  //r2
        } else {
            _textEdit->setModified(false);
            return true;//r3
        }
    }

    // untitled
    QString filePath = _window->getSaveFilepath();
    if (filePath.isEmpty()) return false; //r4

    //filepath is not empty
    auto text = _textEdit->toPlainText();
    _textEdit->setFilePath(filePath);
    auto wf = _ds->writeFile(filePath, text);

    if (!wf) {
        return false;  //r5
    } else {
        _textEdit->setModified(false);
        return true; //r6
    }
}