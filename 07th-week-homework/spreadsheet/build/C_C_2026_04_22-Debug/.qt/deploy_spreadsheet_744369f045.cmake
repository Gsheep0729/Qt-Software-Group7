include("/root/homework/Qt-Software-Group7/07th-week-homework/spreadsheet/build/C_C_2026_04_22-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/spreadsheet-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "/root/homework/Qt-Software-Group7/07th-week-homework/spreadsheet/build/C_C_2026_04_22-Debug/spreadsheet"
    GENERATE_QT_CONF
)
