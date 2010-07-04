/*************************************************************************
 *
 *   Ned - Simple, graphical, cross-platform editor
 *   Copyright (C) 2010 Ákos Kovács
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

#include "FindDialog.h"

#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>

FindDialog::FindDialog(QWidget *parent)
    :QDialog(parent)
{
    setupLayouts();
    createWidgets();

    findButton->setEnabled(false);
    whatLabel->setBuddy(findEdit);

    connect(findEdit, SIGNAL(textChanged(QString)),
            this, SLOT(enableFindButton(QString)));

    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findButtonClicked()));

    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::createWidgets()
{
    findButton = new QPushButton(tr("&Find"));
    closeButton = new QPushButton(tr("&Close"));
    findEdit = new QLineEdit;
    whatLabel = new QLabel(tr("Find &what"));
    sensitivityBox = new QCheckBox(tr("Case &sesitive"));
    topLeftLayout = new QHBoxLayout;
    mainLayout = new QHBoxLayout;
    rightLayout = new QVBoxLayout;
    leftLayout = new QVBoxLayout;
}

void FindDialog::setupLayouts()
{
    topLeftLayout->addWidget(whatLabel);
    topLeftLayout->addWidget(findEdit);

    leftLayout->addLayout(topLeftLayout);
    leftLayout->addStretch();
    leftLayout->addWidget(sensitivityBox);

    rightLayout->addWidget(findButton);
    rightLayout->addStretch();
    rightLayout->addWidget(closeButton);

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
}
/*
void FindDialog::findButtonClicked()
{
    QString text = findEdit->text();

            FindFlag cf;
            if (sensitivityBox->isChecked())
                cf = FindFlag::FindCaseSensitively;

    emit find(text, cf);
}

void FindDialog::enableFindButton(QString &string)
{
    findButton->setEnabled(!string.isEmpty());
}
*/
