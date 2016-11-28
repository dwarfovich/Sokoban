#include "new_level_dialog.hpp"

#include <QFormLayout>
#include <QSpinBox>
#include <QDialogButtonBox>

NewLevelDialog::NewLevelDialog (QWidget* parent)
    : QDialog{parent}
    , width_sb_{new QSpinBox}
    , height_sb_{new QSpinBox}

{
    width_sb_->setRange(1, 100);
    width_sb_->setValue(15);
    height_sb_->setRange(1, 100);
    height_sb_->setValue(15);
    buttons_box_ = new QDialogButtonBox
    {QDialogButtonBox::Ok | QDialogButtonBox::Cancel};
    connect(buttons_box_, &QDialogButtonBox::accepted,
            this, &NewLevelDialog::accept);
    connect(buttons_box_, &QDialogButtonBox::rejected,
            this, &NewLevelDialog::reject);

    QFormLayout* layout = new QFormLayout;
    this->setLayout(layout);
    layout->addRow("Width", width_sb_);
    layout->addRow("Height", height_sb_);
    layout->addRow(buttons_box_);
}

int NewLevelDialog::fieldWidth() const
{
    return width_sb_->value();
}

int NewLevelDialog::fieldHeight() const
{
    return height_sb_->value();
}
