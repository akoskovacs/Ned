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

#ifndef FINDDIALOG_H
#define FINDDIALOG_H

namespace Ned {
    enum FindFlag {
        FindBackward = 0x00001,
        FindCaseSensitively = 0x00002,
        FindWholeWords = 0x00004
    }
}

#include <QDialog>

class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QLineEdit;
class QCheckBox;
class QLabel;

class FindDialog : public QDialog
{

    Q_OBJECT

public:
    FindDialog(QWidget *parent=0);

signals:
    void find(QString &exp, Ned::FindFlag ff);

private slots:
    void findButtonClicked();
    void enableFindButton(QString &string);

private:
    void createWidgets();
    void setupLayouts();

    QPushButton *findButton;
    QPushButton *closeButton;
    QLineEdit *findEdit;
    QLabel *whatLabel;
    QCheckBox *sensitivityBox;
    QHBoxLayout *topLeftLayout;
    QHBoxLayout *mainLayout;
    QVBoxLayout *rightLayout;
    QVBoxLayout *leftLayout;

};

#endif // FINDDIALOG_H
