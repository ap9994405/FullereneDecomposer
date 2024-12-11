/********************************************************************************
** Form generated from reading UI file 'tagmodificationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAGMODIFICATIONDIALOG_H
#define UI_TAGMODIFICATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_TagModificationDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_preview;
    QLabel *label_2;

    void setupUi(QDialog *TagModificationDialog)
    {
        if (TagModificationDialog->objectName().isEmpty())
            TagModificationDialog->setObjectName(QString::fromUtf8("TagModificationDialog"));
        TagModificationDialog->resize(586, 286);
        buttonBox = new QDialogButtonBox(TagModificationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(150, 250, 431, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(TagModificationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 391, 41));
        lineEdit = new QLineEdit(TagModificationDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 190, 551, 31));
        label_preview = new QLabel(TagModificationDialog);
        label_preview->setObjectName(QString::fromUtf8("label_preview"));
        label_preview->setGeometry(QRect(20, 130, 531, 31));
        label_preview->setAutoFillBackground(false);
        label_preview->setStyleSheet(QString::fromUtf8(" QLabel { background-color: white }"));
        label_2 = new QLabel(TagModificationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 67, 17));

        retranslateUi(TagModificationDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), TagModificationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TagModificationDialog);
    } // setupUi

    void retranslateUi(QDialog *TagModificationDialog)
    {
        TagModificationDialog->setWindowTitle(QCoreApplication::translate("TagModificationDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TagModificationDialog", "Please enter a new tag:\n"
" (starting with a capital letter A is NOT allowed)", nullptr));
        label_preview->setText(QString());
        label_2->setText(QCoreApplication::translate("TagModificationDialog", "Preview:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TagModificationDialog: public Ui_TagModificationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAGMODIFICATIONDIALOG_H
