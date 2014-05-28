#ifndef DIALOGTHREAD_H
#define DIALOGTHREAD_H

#include <QThread>
#include <QDialog>
#include <QLabel>
#include <QKeyEvent>

template <class T>
class DialogThread_thread : public QThread {
    //Q_OBJECT
    typedef int (T::*Func)(void *p, void *q);
    T* parent;
    Func func;
public :
    int *ret;
    void *p;
    void *q;
    DialogThread_thread(T* parent, Func func) {
        this->parent = parent;
        this->func = func;
        ret = NULL;
        connect(this, SIGNAL(finished()), SLOT(deleteLater()));
    }
    void run() {
        *ret = (parent->*func)(p, q);
    }
};

template <class T>
class DialogThread : public QDialog {
    //Q_OBJECT
    typedef int (T::*Func)(void *p, void *q);
    T* parent;
    QLabel *label;
    int ret;
public:
    DialogThread(T* parent) : QDialog(parent, Qt::SplashScreen) {
        this->parent = parent;
        ret = -1;
        label = new QLabel(this);
        label->setStyleSheet("background-color: #DFDFDF; padding: 5px;");
        label->show();
    }

    void setHint(const QString& hint) {
        label->setText(hint);
        label->resize(hint.length()*10, 35);
    }

    void keyPressEvent(QKeyEvent *e) {
        e->ignore();
    }

public slots:
    void thread_done() {
        done(ret);
    }

    int exec(Func func, void *p = NULL, void *q = NULL) {
        DialogThread_thread<T> *t = new DialogThread_thread<T>(parent, func);
        connect(t, SIGNAL(finished()), SLOT(accept()));
        t->p = p;
        t->q = q;
        t->ret = &ret;
        t->start();
        QDialog::exec();
        return ret;
    }
};


#endif // DIALOGTHREAD_H
