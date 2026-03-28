#pragma once

#include <QtCore/qglobal.h>

#if defined(QT4_2_3_DIALOG_LIBRARY_LIBRARY)
#define QT4_2_3_DIALOG_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#define QT4_2_3_DIALOG_LIBRARY_EXPORT Q_DECL_IMPORT
#endif
