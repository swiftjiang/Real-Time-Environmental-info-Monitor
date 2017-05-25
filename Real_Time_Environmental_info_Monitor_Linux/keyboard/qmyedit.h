#ifndef QMYEDIT_H
#define QMYEDIT_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QLineEdit>

class QMyEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit QMyEdit(QWidget *parent = 0);

protected:
    virtual void mousePressEvent(QMouseEvent *event);

private slots:

signals:
    void LineEditClicked();
};

#endif // QMYEDIT_H
