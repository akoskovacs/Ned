/*************************************************************************
 *
 *   Ned - Simple, graphical, cross-platform editor
 *   Copyright (C) 2011 Ákos Kovács <akoskovacs@gmx.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 **************************************************************************/

#include "QuickDialog.h"
#include <QSysInfo>

QuickDialog::QuickDialog(QWidget *parent, const QString &currentPath)
        : QWidget(parent), m_path(currentPath)
{
    setupWidgets();
    setupLayouts();
    setupConnections();
}

void QuickDialog::setupWidgets()
{
    pathEdit = new QLineEdit(this);
    m_fsModel = new QFileSystemModel(this);
    if (m_path.isEmpty())
        m_path = QDir::rootPath();

    okButton = new QToolButton(this);
    okButton->setIcon(QIcon::fromTheme("go-next"));

    upButton = new QToolButton(this);
    upButton->setIcon(QIcon::fromTheme("go-up"));

    dirView = new QListView(this);

    dirView->setRootIndex(m_fsModel->index(m_path));
    dirView->setModel(m_fsModel);
    pathEdit->setText(m_path);
    m_fsModel->setReadOnly(true);
}

void QuickDialog::setupLayouts()
{
    topLayout = new QHBoxLayout;
    mainLayout = new QVBoxLayout;

    topLayout->addWidget(upButton);
    topLayout->addWidget(pathEdit);
    topLayout->addWidget(okButton);

    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(dirView);
    setLayout(mainLayout);
}

void QuickDialog::goUpperDirectory()
{
    dirView->setRootIndex(dirView->rootIndex());
    refreshPath(m_fsModel->rootPath());
}

void QuickDialog::goToDirectory()
{
    refreshPath(m_path);
}

void QuickDialog::setupConnections()
{
   connect(upButton, SIGNAL(clicked())
           , this, SLOT(goUpperDirectory()));

   connect(okButton, SIGNAL(clicked())
           , this, SLOT(goToDirectory()));

   connect(dirView, SIGNAL(clicked(QModelIndex))
           , dirView, SLOT(setRootIndex(QModelIndex)));

   connect(pathEdit, SIGNAL(textChanged(QString))
           , this, SLOT(refreshPath(QString)));
}

void QuickDialog::refreshPath(const QString &path)
{
    if (!path.isEmpty())
        m_fsModel->setRootPath(path);
}
