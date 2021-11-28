#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_QtReportCompare.h"
#include "QtChooseProjects.h"

class QtReportCompare : public QMainWindow
{

    Q_OBJECT

public:

    QtReportCompare(QWidget *parent = Q_NULLPTR);

private:

    Ui::QtReportCompare ui;

    QtChooseProjects* m_chooseProjectsWnd;

    std::map<QString, QString> m_projects;

public:

    void closeEvent(QCloseEvent* event) override;
    void set_projects(std::map<QString, QString>&& project_map);

public slots:

    void analyze();
    void chooseBtn_onclick();

private:

    void analyze_file(QString path, QString filename, std::string new_reps_path, std::string old_reps_path);

};
