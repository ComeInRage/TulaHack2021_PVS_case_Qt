#pragma once

#include <QWidget>
#include "ui_QtChooseProjects.h"

class QtReportCompare;

class QtChooseProjects : public QWidget
{

	Q_OBJECT

public:

	QtChooseProjects(QWidget *parent = Q_NULLPTR);
	QtChooseProjects(QtReportCompare* parent);
	~QtChooseProjects();

private:

	Ui::QtChooseProjects ui;

	QtReportCompare* m_parent;

	std::map<QString, QString> m_projects;

public:

	void closeEvent(QCloseEvent* event) override;

public slots:

	void acceptBtn_onclick();
	void removeBtn_onclick();
	void chooseBtn_onclick();

};
