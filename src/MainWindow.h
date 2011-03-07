/*************************************************************************    
 *
 *   Ned - Simple, graphical, cross-platform editor
 *   Copyright (C) 2010 Ákos Kovács <akoskovacs@gmx.com> 
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

#define APP_VERSION "0.3-alpha3"

#include <QtGui>
#include "FindDialog.h"
#include "QuickDialog.h"

class QAction;
class QMenu;
class QPlainTextEdit;
class QToolBar;
class QMainWindow;
class QLabel;
// class FindDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QStringList files = QStringList(), QWidget *parent = 0);

private slots:
    void newFile();
    void open();
    bool saveFile();
    void saveAs();
    void about();
    void textEditModified();
    void createFindDialog();
    void findText(QString, QTextDocument::FindFlags);
    void pasteDateTime();
    void selectFont();
    void setDefaults();
    void showQuickDialog();
    void onFileSelected(QString, bool);

    void updateStatusBar();

protected:
    void closeEvent(QCloseEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);

 private:
    void createActions();
    void createMenus();
    void createContextMenus();
    void createToolBars();
    void createStatusBar();
    void createWindows(QStringList &files);

    void readSettings();
    void writeSettings();

    bool loadFile(QString &fileName);

    void setCurrentFile(const QString &fileName);

    bool maybeSave();

    bool readFile(QString &fileName);
    bool writeFile(QString &fileName);

    QPlainTextEdit *textEdit;
    QPointer<QDockWidget> quickDialogDock;
    QAction *newAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *openAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *findAction;
    QAction *clearAllAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *selectAllAction;
    QAction *aboutAction;
    QAction *exitAction;
    QAction *pasteDateTimeAction;
    QAction *fontDialogAction;
    QAction *defaultsAction;
    QAction *quickDialogAction;

    QToolBar *baseToolBar;
    QToolBar *editToolBar;

    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *editMenu;
    QMenu *pasteMenu;
    QMenu *settingsMenu;
    QMenu *aboutMenu;

    QPointer<FindDialog> findDialog;
    QPointer<QuickDialog> quickDialog;

    QLabel *characters;
    QLabel *lines;
    QLabel *mode;
    QLabel *fontLabel;

    QFont currentFont;

    // Arrghm, the ugliest ones. Please,
    // close your eyes!
    QString m_savedFileName;
    bool m_isFileNameKnown;
};

#endif // MAINWINDOW_H
