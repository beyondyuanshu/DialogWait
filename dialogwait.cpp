#include "dialogwait.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QKeyEvent>

DialogWait::DialogWait(QWidget *parent) :
    QDialog(parent, Qt::SplashScreen)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    label = new QLabel(this);
    layout->addWidget(label);
    setLayout(layout);
}

void DialogWait::keyPressEvent(QKeyEvent *e) {
    e->ignore();
}

void DialogWait::setText(const QString &text) {
    label->setText(text);
}
