#pragma once
class Window;
class TextEdit;
class DocumentStorage;

class AppController
{
public:
    static AppController &singleton();
    bool save(); // ✅ 必须加上！

private:
    AppController();
    ~AppController();
    void currentState(bool &titled, bool &modified);

    Window *_window;
    TextEdit *_textEdit;        // ✅ 统一大小写
    DocumentStorage *_ds;
};
