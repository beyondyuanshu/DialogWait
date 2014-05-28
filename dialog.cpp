#include "dialog.h"
#include "ui_dialog.h"
#include "dialogwait.h"
#include "dialogthread.h"
#include "QTimer"
#include "QDebug"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    DialogWait *wait = new DialogWait(this);
    wait->setText("Please Waitting...");
    QTimer::singleShot(2000, wait, SLOT(accept()));
    wait->exec();
}

void Dialog::on_pushButton_2_clicked()
{
    DialogThread<Dialog> *dlg = new DialogThread<Dialog>(this);
    dlg->setHidden("Dialog Thread...");
    dlg->exec(&Dialog::func, NULL, NULL);
    delete dlg;
}

int Dialog::func(void *p, void *q)
{
    return 1;
}

