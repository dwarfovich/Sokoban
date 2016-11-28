#ifndef NEWLEVELDIALOG_HPP
#define NEWLEVELDIALOG_HPP

#include <QDialog>

QT_BEGIN_NAMESPACE
class QSpinBox;
class QDialogButtonBox;
QT_END_NAMESPACE

class NewLevelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewLevelDialog(QWidget* parent = 0);

    int fieldWidth () const;
    int fieldHeight () const;

private:
    QSpinBox* width_sb_;
    QSpinBox* height_sb_;
    QDialogButtonBox* buttons_box_;

};

#endif // NEWLEVELDIALOG_HPP
