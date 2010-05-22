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

void FindDialog::findButtonClicked()
{
    QString text = findEdit->text();

    Qt::CaseSensitivity cs =
            sensitivityBox->isChecked() ? Qt::CaseSensitive
                :Qt::CaseInsensitive;

    emit find(text, cs);
}

void FindDialog::enableFindButton(QString &string)
{
    findButton->setEnabled(!string.isEmpty());
}
