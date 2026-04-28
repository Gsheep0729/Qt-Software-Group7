#pragma once
#include <QTableWidget>

// 电子表格类，继承QTableWidget处理核心数据展示
class Spreadsheet : public QTableWidget {
    Q_OBJECT
public:
    explicit Spreadsheet(QWidget *parent = nullptr);
    Spreadsheet(const Spreadsheet&) = delete;
    Spreadsheet& operator=(const Spreadsheet&) = delete;
    virtual ~Spreadsheet() override;

    [[nodiscard]] QString currentLocation() const;
    [[nodiscard]] QString currentFormula() const;

public slots:
    void clear();
    void readFile(const QString &fileName);
    void writeFile(const QString &fileName);
    void cut();
    void copy();
    void paste();
    void del();
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private:
    static constexpr int RowCount = 999;
    static constexpr int ColumnCount = 26;
    void setupTable();
};