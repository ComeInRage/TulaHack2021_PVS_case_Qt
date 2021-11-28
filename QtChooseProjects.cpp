#include "QtChooseProjects.h"
#include <qfiledialog.h>
#include "QtReportCompare.h"

QtChooseProjects::QtChooseProjects(QWidget *parent)
	: QWidget(parent), m_parent(nullptr)
{
	ui.setupUi(this);
}

QtChooseProjects::QtChooseProjects(QtReportCompare* parent) 
	: QWidget(), m_parent(parent) {
	ui.setupUi(this);
}

QtChooseProjects::~QtChooseProjects()
{
}

void QtChooseProjects::closeEvent(QCloseEvent* event) {

	this->ui.treeWidget->clear();
	this->m_projects.clear();

}

void QtChooseProjects::acceptBtn_onclick() {

	this->m_parent->set_projects(std::move(this->m_projects));
	this->close();

}

void QtChooseProjects::removeBtn_onclick() {

	for (auto item : this->ui.treeWidget->selectedItems()) {

		this->m_projects.erase(item->text(0));

		int index = this->ui.treeWidget->indexOfTopLevelItem(item);
		this->ui.treeWidget->takeTopLevelItem(index);

	}

}

void QtChooseProjects::chooseBtn_onclick() {

	QStringList paths = QFileDialog::getOpenFileNames(this, "Select .json report", "/home", "*.vcxproj");

	if (paths.isEmpty()) {
		return;
	}

	for (const auto& path : paths) {

		QString filename = QFileInfo(path).fileName();

		this->ui.treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList({ filename, path })));
		this->m_projects[filename] = path;

	}

}