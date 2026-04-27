#include "appcontroller.h"

AppController::AppController(QObject *parent) : QObject(parent) {}
AppController::~AppController() {}   // 暂时不 delete

void AppController::setTextEdit(TextEdit *te) { textEdit = te; }
void AppController::setStorage(DocumentStorage *ds) { storage = ds; }

void AppController::saveDocument()
{

}