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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define APP_VERSION "0.2.1"

#include <QtGui>

class QAction;
class QMenu;
class QTextEdit;
class QToolBar;
class QMainWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void setArgument(char *);

private slots:
    void newFile();
    void open();
    bool saveFile();
    void saveAs();
    void about();
    void textEditModified();

    void closeEvent(QCloseEvent *);

 private:
    void createActions();
    void createMenus();
    void createContextMenus();
    void createToolBars();
    void createStatusBar();

    void readSettings();
    void writeSettings();

    bool loadFile(QString &fileName);

    void setCurrentFile(const QString &fileName);

    bool maybeSave();

    bool readFile(QString &fileName);
    bool writeFile(QString &fileName);

    QTextEdit *textEdit;
    QAction *newAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *openAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *clearAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *selectAllAction;
    QAction *aboutAction;
    QAction *exitAction;

    QToolBar *baseToolBar;
    QToolBar *editToolBar;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *aboutMenu;

    QString m_savedFileName;
    bool m_isFileNameKnown;

};

#endif // MAINWINDOW_H
