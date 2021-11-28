#include "QtReportCompare.h"

#include <Windows.h>
#include <fstream>
#include <filesystem>

QtReportCompare::QtReportCompare(QWidget *parent)
    : QMainWindow(parent), m_chooseProjectsWnd(new QtChooseProjects(this))
{
    ui.setupUi(this);
}

void QtReportCompare::closeEvent(QCloseEvent* event) {

    this->m_chooseProjectsWnd->close();

}

void QtReportCompare::set_projects(std::map<QString, QString>&& project_map) {

    for (auto pair : project_map) {

        this->ui.treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList({ pair.first, pair.second })));

    }

    this->m_projects = std::move(project_map);

}

void QtReportCompare::analyze() {

    namespace fs = std::filesystem;

    const std::string new_reps_path = "reports_new";
    const std::string old_reps_path = "reports_old";

    if (!fs::exists(old_reps_path)) {
        fs::create_directory(old_reps_path);
    }
    if (!fs::exists(new_reps_path)) {
        fs::create_directory(new_reps_path);
    }

    for (size_t i = 0; i < 1; i++) { // this->ui.treeWidget->topLevelItemCount()

        QTreeWidgetItem* item = this->ui.treeWidget->topLevelItem(i);
        this->analyze_file(item->text(1), item->text(0), new_reps_path, old_reps_path); // 1 is column with path (не магическая константа)

    }

}

void QtReportCompare::chooseBtn_onclick() {

    this->m_chooseProjectsWnd->show();

}

void QtReportCompare::analyze_file(QString path, QString filename, std::string new_reps_path, std::string old_reps_path) {

    /*STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    WCHAR* wchars[]{ L"D:\\Programming\\CPP\\Utilities\\PVS-Studio\\PVS-Studio_Cmd.exe -t D:\\Programming\\TulaHack2021\\TulaHack2021Sol\\DLLTester\\DLLTester.vcxproj -o D:\\Programming\\TulaHack2021\\TulaHack2021Sol\\QtReportCompare\\reports_old" };

    if (!CreateProcess(NULL,
        wchars,        // Command line
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi)
        )
    {
        qDebug() << "Error";
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    qDebug() << "Finished";*/

}