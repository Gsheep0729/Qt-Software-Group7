#include "appcontroller.h"
#include "textedit.h"
#include "window.h"

AppController::AppController()
:_window(new Window(this))
,_textedit(new TextEdit(this))
{

}
