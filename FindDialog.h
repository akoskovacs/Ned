#ifndef FINDDIALOG_H
#define FINDDIALOG_H

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
    void find(QString &exp, Qt::CaseSensitivity cs);

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
