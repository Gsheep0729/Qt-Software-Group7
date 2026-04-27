#include "appcontroller.h"
#include "window.h"
#include "textedit.h"
#include "documentstorage.h"
#include <QTimer>               // 新增

AppController::AppController()
    : _window(new Window(this))
    , _textEdit(nullptr)
    , _ds(nullptr)
{
    _textEdit = qobject_cast<TextEdit *>(_window->centralWidget());
    if (!_textEdit) {
        _textEdit = new TextEdit(_window);
        _window->setCentralWidget(_textEdit);
    }

    _ds = new DocumentStorage(_window);

    // 延迟显示窗口，确保事件循环已启动
    QTimer::singleShot(0, _window, &QWidget::show);

    _window->setWindowTitle(_textEdit->title());
    connect(_textEdit->document(), &QTextDocument::modificationChanged, [this](bool changed) {
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
    bool modified, titled;
    currentState(titled, modified);

    if (titled && !modified)
        return true;

    if (titled && modified) {
        QString text = _textEdit->toPlainText();
        QString fp = _textEdit->filePath();
        if (!_ds->writeFile(fp, text))
            return false;
        _textEdit->setModified(false);
        return true;
    }

    QString filePath = _window->getSaveFilepath();
    if (filePath.isEmpty())
        return false;

    QString text = _textEdit->toPlainText();
    _textEdit->setFilePath(filePath);
    if (!_ds->writeFile(filePath, text))
        return false;
    _textEdit->setModified(false);
    return true;
}