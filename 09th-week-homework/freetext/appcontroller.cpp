#include "appcontroller.h"

AppController::AppController(QObject *parent) : QObject(parent) {}
AppController::~AppController()
{
    delete storage;
}
void AppController::setTextEdit(TextEdit *te) { textEdit = te; }
void AppController::setStorage(DocumentStorage *ds) { storage = ds; }

void AppController::saveDocument()
{

}