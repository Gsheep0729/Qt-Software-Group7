# Qt 第七组github作业项目结构

## 完整目录树状图

```
Qt-Software-Group7/
├── 03rd-week-homework/          # 第三周作业主目录（已完成）
│   ├── QT4-2_1-dialog/          # Qt 对话框项目1
│   │   ├── .gitignore
│   │   ├── CMakeLists.txt       # CMake 构建配置文件
│   │   ├── main.cpp             # 程序入口文件
│   │   ├── QT4-2_1-dialog_knowledge_base.md  # 知识库文档
│   │   ├── widget.cpp           # Widget 实现文件
│   │   └── widget.h             # Widget 头文件
│   │
│   ├── QT4-2_3-dialog/          # Qt 对话框项目2
│   │   ├── .gitignore
│   │   ├── CMakeLists.txt       # CMake 构建配置文件
│   │   ├── main.cpp             # 程序入口文件
│   │   └── ....
│   │
│   └── QT4-2_3-gotocell/        # GoToCell 对话框项目
│       ├── .gitignore
│       ├── CMakeLists.txt       # CMake 构建配置文件
│       ├── gotocelldialog.cpp   # GoToCell 对话框实现文件
│       ├── gotocelldialog.h     # GoToCell 对话框头文件
│       ├── gotocelldialog.ui    # GoToCell UI 界面文件
│       ├── main.cpp             # 程序入口文件
│       └── QT4-2_3-gotocell_knowledge_base.md  # 知识库文档
│
├── 04th-week-homework/          # 第四周作业主目录（今后实例）
│   ├── QT5-1_1-helloword/     # 作业1
│   │   ├── .gitignore
│   │   ├── CMakeLists.txt
│   │   ├── main.cpp
│   │   └── ....
│   │
│   └── QT5-1_2-helloword/     # 作业2
│       └── ....
│
├── 05th-week-homework/          # 第五周作业主目录（今后实例）
│   ├── QT6-1_1-helloword/   # 作业1
│   │   ├── .gitignore
│   │   ├── CMakeLists.txt
│   │   ├── main.cpp
│   │   └── ....
│   │
│   └── QT6-1_2-helloword/   # 作业2
│       └── ....
│
├── .gitignore                   # 根目录Git 忽略文件配置（备用）
├── for_md.py                    # 代码归档工具脚本
└── README.md                    # 命令和工具的查询文档
```

## 项目说明

### 1. QT4-2_1-dialog
基础对话框项目，实现基本的对话框功能。
- 使用 CMake 构建系统
- 包含 Widget 主窗口类
- 不包含 UI 界面文件（纯代码实现）

### 2. QT4-2_3-dialog

进阶对话框项目，在基础对话框功能上进行扩展。
- 使用 CMake 构建系统
- 包含 Widget 主窗口类
- 包含 UI 界面文件（Qt Designer 设计）

### 3. QT4-2_3-gotocell
GoToCell 对话框项目，实现单元格跳转功能。
- 使用 CMake 构建系统
- 包含 GoToCellDialog 对话框类
- 包含 UI 界面文件（Qt Designer 设计）

## 文件说明

### 通用文件
- `.gitignore`: Git 版本控制忽略配置
- `*_knowledge_base.md`: 使用`for_md.py`代码归档工具脚本，将各项目的知识库文档，记录相关知识点

### Git 忽略文件说明
项目中存在两个层级的 `.gitignore` 文件：
- **根目录 `.gitignore`**: 作为备用配置文件，用于防止子项目中缺少 `.gitignore` 文件的情况。Git 会按层级应用忽略规则，如果子项目没有自己的 `.gitignore`，则会继承根目录的配置
- **子项目 `.gitignore`**: 各个作业项目目录下的独立忽略文件，针对每个项目的特定需求配置忽略规则（如 build/、.qtcreator/ 等目录）

### 工具脚本
- `for_md.py`: 代码归档工具，用于整理和归档代码
