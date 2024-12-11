/********************************************************************************
** Form generated from reading UI file 'widthmodeexportdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDTHMODEEXPORTDIALOG_H
#define UI_WIDTHMODEEXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <zoomableview.h>

QT_BEGIN_NAMESPACE

class Ui_WidthModeExportDialog
{
public:
    QHBoxLayout *horizontalLayout_2;
    ZoomableView *graphicsView;
    QVBoxLayout *verticalLayout;
    QPushButton *button_OK;
    QPushButton *button_cancel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_ncols;
    QSlider *slider_ncols;
    QCheckBox *checkBox;
    QCheckBox *checkBox_gridlines;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QLabel *label_2;
    QSlider *horizontalSlider_3;
    QLabel *label_4;
    QSlider *horizontalSlider_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *WidthModeExportDialog)
    {
        if (WidthModeExportDialog->objectName().isEmpty())
            WidthModeExportDialog->setObjectName(QString::fromUtf8("WidthModeExportDialog"));
        WidthModeExportDialog->resize(994, 808);
        horizontalLayout_2 = new QHBoxLayout(WidthModeExportDialog);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        graphicsView = new ZoomableView(WidthModeExportDialog);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(400, 0));
        graphicsView->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        button_OK = new QPushButton(WidthModeExportDialog);
        button_OK->setObjectName(QString::fromUtf8("button_OK"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_OK->sizePolicy().hasHeightForWidth());
        button_OK->setSizePolicy(sizePolicy1);
        button_OK->setMaximumSize(QSize(150, 16777215));
        button_OK->setCheckable(false);

        verticalLayout->addWidget(button_OK);

        button_cancel = new QPushButton(WidthModeExportDialog);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));
        sizePolicy1.setHeightForWidth(button_cancel->sizePolicy().hasHeightForWidth());
        button_cancel->setSizePolicy(sizePolicy1);
        button_cancel->setMaximumSize(QSize(150, 16777215));

        verticalLayout->addWidget(button_cancel);

        groupBox = new QGroupBox(WidthModeExportDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMaximumSize(QSize(150, 16777215));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        label_ncols = new QLabel(groupBox);
        label_ncols->setObjectName(QString::fromUtf8("label_ncols"));
        label_ncols->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_ncols);


        verticalLayout_2->addLayout(horizontalLayout_3);

        slider_ncols = new QSlider(groupBox);
        slider_ncols->setObjectName(QString::fromUtf8("slider_ncols"));
        slider_ncols->setMinimum(1);
        slider_ncols->setMaximum(5);
        slider_ncols->setValue(3);
        slider_ncols->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_ncols);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        verticalLayout_2->addWidget(checkBox);

        checkBox_gridlines = new QCheckBox(groupBox);
        checkBox_gridlines->setObjectName(QString::fromUtf8("checkBox_gridlines"));
        checkBox_gridlines->setChecked(true);

        verticalLayout_2->addWidget(checkBox_gridlines);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        horizontalSlider_2 = new QSlider(groupBox);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(10);
        horizontalSlider_2->setMaximum(500);
        horizontalSlider_2->setSingleStep(10);
        horizontalSlider_2->setPageStep(50);
        horizontalSlider_2->setValue(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalSlider_3 = new QSlider(groupBox);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setMinimum(10);
        horizontalSlider_3->setMaximum(500);
        horizontalSlider_3->setSingleStep(10);
        horizontalSlider_3->setPageStep(50);
        horizontalSlider_3->setValue(50);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        horizontalSlider_4 = new QSlider(groupBox);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setMaximum(100);
        horizontalSlider_4->setPageStep(20);
        horizontalSlider_4->setValue(10);
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_4);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(WidthModeExportDialog);

        button_OK->setDefault(false);


        QMetaObject::connectSlotsByName(WidthModeExportDialog);
    } // setupUi

    void retranslateUi(QDialog *WidthModeExportDialog)
    {
        WidthModeExportDialog->setWindowTitle(QCoreApplication::translate("WidthModeExportDialog", "Dialog", nullptr));
        button_OK->setText(QCoreApplication::translate("WidthModeExportDialog", "Save", nullptr));
        button_cancel->setText(QCoreApplication::translate("WidthModeExportDialog", "Cancel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("WidthModeExportDialog", "Options", nullptr));
        label_3->setText(QCoreApplication::translate("WidthModeExportDialog", "Columns", nullptr));
        label_ncols->setText(QCoreApplication::translate("WidthModeExportDialog", "3", nullptr));
        checkBox->setText(QCoreApplication::translate("WidthModeExportDialog", "Frame", nullptr));
        checkBox_gridlines->setText(QCoreApplication::translate("WidthModeExportDialog", "Grid Lines", nullptr));
        label->setText(QCoreApplication::translate("WidthModeExportDialog", "V. Spacing:", nullptr));
        label_2->setText(QCoreApplication::translate("WidthModeExportDialog", "H. Spacing:", nullptr));
        label_4->setText(QCoreApplication::translate("WidthModeExportDialog", "Margin:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidthModeExportDialog: public Ui_WidthModeExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDTHMODEEXPORTDIALOG_H
