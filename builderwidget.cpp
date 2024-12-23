#include "builderwidget.h"
#include "builderscene.h"
#include "bonditem.h"
#include <QtWidgets>
#include "utils.h"
#include "ringitem.h"
#include "zoomableview.h"
#include <QtGlobal>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMetaType>

#include "graphmodel.h"
Q_DECLARE_METATYPE(QTableWidgetItem*)

BuilderWidget::BuilderWidget(QWidget *parent)
    : QWidget(parent)
{

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setMargin(0);
    scene = new BuilderScene(this);
    view = new ZoomableView(scene);
    layout->addWidget(view);
    this->setLayout(layout);
    view->setRenderHints(QPainter::Antialiasing);
    view->setContextMenuPolicy(Qt::CustomContextMenu);


//    view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));

    clear();
    readxyz("C20","Isomer_0001_Ih");
    readschlegel("C20","Isomer_0001_Ih");
    setgraphsize(5);
    draw_grid("C20","Isomer_0001_Ih");
    SelectAllGraph();
    connect(view, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));;

    treeWidget = new QTreeWidget(this);
    treeWidget->setColumnCount(1);
    treeWidget->header()->hide();
    treeWidget->setIndentation(8);
    treeWidget->setFixedWidth(350);
    QString readfilePath = QDir::currentPath();
    QDir curDir(readfilePath);

    //QString fontPath = curDir.absolutePath() + "/TimesNewRomanPSMT.ttf";
    //QString fontPath = curDir.absolutePath() + "/MicrosoftSansSerif.ttf";
    QString fontPath = curDir.absolutePath() + "/PorscheSansSerif2.ttf";
    //QString fontPath = curDir.absolutePath() + "/TimesNewRomanPS-BoldMT.ttf";
    int fontId = QFontDatabase::addApplicationFont(fontPath);
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font;
    font.setPointSize(20);
    font.setFamily(fontFamily);
    treeWidget->setFont(font);
    

    QString text;
    QString xyzPath;
    QString mainItems;
    QStringList subItems;
    QColor color1(74,143,200);
    QColor color2(68,186,236);
    QColor color3(198,224,180);
    QColor color4(226,239,218);
    int colorcount ;

    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C20 = new QTreeWidgetItem(treeWidget);
    text = "C20";
    C20->setText(0, ch2subscript(text));
    //C20->setText(0,"<sub>Low</sub>Normal<sup>High</sup>");
    C20->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C20";
    QDir xyz20(xyzPath);
    subItems = xyz20.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C20);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }

    }
    //m_result = new QTableWidgetItem();
    //QTreeWidgetItem *item = new QTreeWidgetItem(C20);
    //C20 -> setItemWidget(item,0,m_result);
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C24 = new QTreeWidgetItem(treeWidget);
    text = "C24";
    C24->setText(0, ch2subscript(text));
    C24->setBackground(0, QBrush(color2));
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C24";
    QDir xyz24(xyzPath);
    subItems = xyz24.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C24);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }

    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C26 = new QTreeWidgetItem(treeWidget);
    text = "C26";
    C26->setText(0, ch2subscript(text));
    C26->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C26";
    QDir xyz26(xyzPath);
    subItems = xyz26.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C26);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C28 = new QTreeWidgetItem(treeWidget);
    text = "C28";
    C28->setText(0, ch2subscript(text));
    C28->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C28";
    QDir xyz28(xyzPath);
    subItems = xyz28.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C28);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C30 = new QTreeWidgetItem(treeWidget);
    text = "C30";
    C30->setText(0, ch2subscript(text));
    C30->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C30";
    QDir xyz30(xyzPath);
    subItems = xyz30.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C30);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C32 = new QTreeWidgetItem(treeWidget);
    text = "C32";
    C32->setText(0, ch2subscript(text));
    C32->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C32";
    QDir xyz32(xyzPath);
    subItems = xyz32.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C32);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C34 = new QTreeWidgetItem(treeWidget);
    text = "C34";
    C34->setText(0, ch2subscript(text));
    C34->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C34";
    QDir xyz34(xyzPath);
    subItems = xyz34.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C34);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C36 = new QTreeWidgetItem(treeWidget);
    text = "C36";
    C36->setText(0, ch2subscript(text));
    C36->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C36";
    QDir xyz36(xyzPath);
    subItems = xyz36.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C36);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C38 = new QTreeWidgetItem(treeWidget);
    text = "C38";
    C38->setText(0, ch2subscript(text));
    C38->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C38";
    QDir xyz38(xyzPath);
    subItems = xyz38.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C38);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C40 = new QTreeWidgetItem(treeWidget);
    text = "C40";
    C40->setText(0, ch2subscript(text));
    C40->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C40";
    QDir xyz40(xyzPath);
    subItems = xyz40.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C40);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C42 = new QTreeWidgetItem(treeWidget);
    text = "C42";
    C42->setText(0, ch2subscript(text));
    C42->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C42";
    QDir xyz42(xyzPath);
    subItems = xyz42.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C42);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C44 = new QTreeWidgetItem(treeWidget);
    text = "C44";
    C44->setText(0, ch2subscript(text));
    C44->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C44";
    QDir xyz44(xyzPath);
    subItems = xyz44.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C44);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C46 = new QTreeWidgetItem(treeWidget);
    text = "C46";
    C46->setText(0, ch2subscript(text));
    C46->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C46";
    QDir xyz46(xyzPath);
    subItems = xyz46.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C46);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C48 = new QTreeWidgetItem(treeWidget);
    text = "C48";
    C48->setText(0, ch2subscript(text));
    C48->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C48";
    QDir xyz48(xyzPath);
    subItems = xyz48.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C48);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C50 = new QTreeWidgetItem(treeWidget);
    text = "C50";
    C50->setText(0, ch2subscript(text));
    C50->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C50";
    QDir xyz50(xyzPath);
    subItems = xyz50.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C50);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }

    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C52 = new QTreeWidgetItem(treeWidget);
    text = "C52";
    C52->setText(0, ch2subscript(text));
    C52->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C52";
    QDir xyz52(xyzPath);
    subItems = xyz52.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C52);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C54 = new QTreeWidgetItem(treeWidget);
    text = "C54";
    C54->setText(0, ch2subscript(text));
    C54->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C54";
    QDir xyz54(xyzPath);
    subItems = xyz54.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C54);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C56 = new QTreeWidgetItem(treeWidget);
    text = "C56";
    C56->setText(0, ch2subscript(text));
    C56->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C56";
    QDir xyz56(xyzPath);
    subItems = xyz56.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C56);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C58 = new QTreeWidgetItem(treeWidget);
    text = "C58";
    C58->setText(0, ch2subscript(text));
    C58->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C58";
    QDir xyz58(xyzPath);
    subItems = xyz58.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C58);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C60 = new QTreeWidgetItem(treeWidget);
    text = "C60";
    C60->setText(0, ch2subscript(text));
    C60->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C60";
    QDir xyz60(xyzPath);
    subItems = xyz60.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C60);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C62 = new QTreeWidgetItem(treeWidget);
    text = "C62";
    C62->setText(0, ch2subscript(text));
    C62->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C62";
    QDir xyz62(xyzPath);
    subItems = xyz62.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C62);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C64 = new QTreeWidgetItem(treeWidget);
    text = "C64";
    C64->setText(0, ch2subscript(text));
    C64->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C64";
    QDir xyz64(xyzPath);
    subItems = xyz64.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C64);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C66 = new QTreeWidgetItem(treeWidget);
    text = "C66";
    C66->setText(0, ch2subscript(text));
    C66->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C66";
    QDir xyz66(xyzPath);
    subItems = xyz66.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C66);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C68 = new QTreeWidgetItem(treeWidget);
    text = "C68";
    C68->setText(0, ch2subscript(text));
    C68->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C68";
    QDir xyz68(xyzPath);
    subItems = xyz68.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C68);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
	if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C70 = new QTreeWidgetItem(treeWidget);
    text = "C70";
    C70->setText(0, ch2subscript(text));
    C70->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C70";
    QDir xyz70(xyzPath);
    subItems = xyz70.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C70);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        symmetry = ch2subscript(symmetry);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
        if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
/*    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C72 = new QTreeWidgetItem(treeWidget);
    C72->setText(0, "C72");
    C72->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C72";
    QDir xyz72(xyzPath);
    subItems = xyz72.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C72);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
        if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C74 = new QTreeWidgetItem(treeWidget);
    C74->setText(0, "C74");
    C74->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C74";
    QDir xyz74(xyzPath);
    subItems = xyz74.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C74);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
        if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C76 = new QTreeWidgetItem(treeWidget);
    C76->setText(0, "C76");
    C76->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C76";
    QDir xyz76(xyzPath);
    subItems = xyz76.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C76);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
        if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C78 = new QTreeWidgetItem(treeWidget);
    C78->setText(0, "C78");
    C78->setBackground(0, QBrush(color1));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C78";
    QDir xyz78(xyzPath);
    subItems = xyz78.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C78);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
        if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }
    //===============================================================================================
    // mainTreeWidgetItem
    QTreeWidgetItem *C80 = new QTreeWidgetItem(treeWidget);
    C80->setText(0, "C80");
    C80->setBackground(0, QBrush(color2));
    // sbuTreeWidgetItem
    xyzPath = curDir.absolutePath() + "/readfile"+"/"+"C80";
    QDir xyz80(xyzPath);
    subItems = xyz80.entryList(QDir::Files);
    colorcount = 0;
    for (const QString &subItemsText : subItems)
    {
        QTreeWidgetItem *subItem = new QTreeWidgetItem(C80);

        QStringList namelist = subItemsText.split("_");
        QString symmetry = namelist.at(2);
        QString number = namelist.at(1);
        QString filename = "Isomer " + number + " (" + symmetry + ")";
        subItem->setText(0, filename);
        colorcount = colorcount + 1;
        if (colorcount%2 == 0)
        {
          subItem->setBackground(0, QBrush(color3));
        }
        else
        {
          subItem->setBackground(0, QBrush(color4));
        }
    }*/

    layout->addWidget(treeWidget);
    layout->setStretch(0, 1);
    layout->setStretch(1, 0);
    connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(onTreeItemClicked(QTreeWidgetItem*, int)));

}


BuilderWidget::~BuilderWidget()
{

}

void BuilderWidget::clear()
{
    QSetIterator<BondItem*> it(m_selected_edges);
    while(it.hasNext())
    {
        it.next()->toggleSelection();
    }
    m_selected_edges.clear();
    m_selected_rings.clear();
    emit ClearAllWindows();
}

void BuilderWidget::draw_grid(QString foldername, QString filename)
{
    n_foldername = foldername;
    n_filename = filename;
    // in fullerene bondlength not fixed
    double bondlength = 30.0;
    QString abspath = QDir::currentPath();
    QString sep = QDir::separator();
    foldername = subscript2ch(foldername);
    filename = subscript2ch(filename);

    QString m_filename = abspath+"/readfile"+"/"+foldername+"/bondlist"+"/"+filename+"_bondlist";
    QFile bondlfile(m_filename);
    if (!bondlfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // qDebug() << filename << "not exist";
        qDebug() << m_filename << "not exist";
        qCritical() << "Unable to open the bondlfile.";
    }
    int start, end;
    std::vector<std::pair<int, int>> bondlist;
    bondlist.clear();

    QTextStream in(&bondlfile);
    while (!in.atEnd())
    {
        in >> start >> end;
        if (!in.atEnd())
        {
            // qDebug() << start << end;
            bondlist.emplace_back(start, end);
        }

    }
    // for (const auto& aa : bondlist)
    // {
    //     std::cout << aa.first << " " << aa.second << std::endl;
    // }

    BondItem *item ;// = new BondItem();
    for (size_t i=0;i < bondlist.size();i++)
    {
        int be = bondlist[i].first;
        int en = bondlist[i].second;
        EdgeModel edge(QPoint(0,be),QPoint(0,en));
        item = new BondItem(0,0,bondlength, edge, BondItem::Grid);
        connect(item, SIGNAL(bondSelected(BondItem*)), this, SLOT(selectBond(BondItem*)));
        connect(item, SIGNAL(bondUnselected(BondItem*)), this, SLOT(unselectBond(BondItem*)));
        edges.insert(edge, item);
        // r->addBondItem(item);
        scene->addItem(item);
    }
    view->centerOn(scene->sceneRect().center());
}
void BuilderWidget::onTreeItemClicked(QTreeWidgetItem *item, int column)
{
    QString subText = item->text(column);
    //qDebug() <<"porsche2"<< subText;
    subText = subText.replace(" (", " ").left(subText.length() - 1);

    QTreeWidgetItem *MainItem = item->parent();
    if (MainItem)
    {
        QString MainText = MainItem->text(column);
        // qDebug() << "Parent item: " << MainText;
        if (subText.length() > 3)
        {
            Loadgraph(MainText,subText,5);
        }
    }

}
QList<EdgeModel> BuilderWidget::getGraph()
{
    QList<EdgeModel> res;
    QSetIterator<BondItem*> it(m_selected_edges);
    while(it.hasNext())
    {
        res.append(it.next()->getEdgeModel());
    }
    return res;
}


void BuilderWidget::selectBond(BondItem *bond)
{
    m_selected_edges.insert(bond);
    emit modified();
}

void BuilderWidget::unselectBond(BondItem *bond)
{
    m_selected_edges.remove(bond);
    emit modified();
}


void BuilderWidget::ringClicked(RingItem *ring)
{
    if (m_selected_rings.contains(ring))
    {
        ring->UnselectAllBonds();
        m_selected_rings.remove(ring);
        QSetIterator<RingItem*> it(m_selected_rings);
        while(it.hasNext())
        {
            it.next()->SelectAllBonds();
        }
    }
    else
    {
        ring->SelectAllBonds();
        m_selected_rings.insert(ring);
    }
    emit modified();
}

void BuilderWidget::contextMenu(QPoint point)
{
    QPoint globalPos = view->mapToGlobal(point);

    QMenu myMenu;
    myMenu.addAction("Compute polynomial...");

    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem)
    {
        GraphModel *model = getGraphModel();
        emit ZZPolynomialRequest(model);
        delete model;
    }
}

GraphModel* BuilderWidget::getGraphModel()
{
    GraphModel* graphModel = new GraphModel(this->getGraph(), QList<EdgeModel>(), NULL, GraphModel::None, 0);
    graphModel -> setFilename(subscript2ch(n_foldername),subscript2ch(n_filename));
    //qDebug() << "tatata"<< graphModel -> getfolderename() << graphModel -> getfilename();

    //return new GraphModel(this->getGraph(),QList<EdgeModel>(), NULL, GraphModel::None, 0);
    return graphModel;
}

void BuilderWidget::setGridRotate(bool )
{
    QTransform q = view->transform();
    if (q.isRotating())
    {
        q.rotate(-30);
    }
    else
    {
        q.rotate(30);
    }
    view->setTransform(q);
}

void BuilderWidget::SelectAllGraph()
{
    QHash<EdgeModel, BondItem*>::iterator it = edges.begin();
    while (it != edges.end())
    {
        BondItem *item = it.value();
        item -> setSelection(true);
        selectBond(item);
        ++it;
    }
}
void BuilderWidget::Loadgraph(const QString& foldername, QString& graphName, double graphSize)
{
    clear();
    QHash<EdgeModel, BondItem*>::iterator it = edges.begin();
    while (it != edges.end())
    {
        BondItem *item = it.value();
        if (item->scene() == scene)
        {
            scene->removeItem(item);
            delete item;
        }
        ++it;
    }
    edges.clear();
    graphName = graphName.replace(" ", "_");
    readxyz(foldername, graphName);
    readschlegel(foldername, graphName);
    setgraphsize(graphSize);
    draw_grid(foldername, graphName);
    SelectAllGraph();
    connect(view, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
    //qDebug() << graphName;
}


QString BuilderWidget::ch2subscript(const QString &input)
{
    QMap<QChar, QChar> chMap;
    chMap['0'] = QChar(0x2080);
    chMap['1'] = QChar(0x2081);
    chMap['2'] = QChar(0x2082);
    chMap['3'] = QChar(0x2083);
    chMap['4'] = QChar(0x2084);
    chMap['5'] = QChar(0x2085);
    chMap['6'] = QChar(0x2086);
    chMap['7'] = QChar(0x2087);
    chMap['8'] = QChar(0x2088);
    chMap['9'] = QChar(0x2089);
    chMap['s'] = QChar(0x209B);
    chMap['v'] = QChar(0x1D65); //1D65
    chMap['h'] = QChar(0x2095);
    chMap['d'] = QChar(0x0080);
    QString result;
    for (const QChar &ch : input) {
        if (chMap.contains(ch)) {
            result += chMap[ch];
        } else {
            result += ch;
        }
    }
    return result;
}

// void BuilderWidget::ReadFile(QString filename)
// {
//     QString filePath = "readfile/" + filename;
//     std::ifstream File(filePath.toStdString());
//     if (!File.is_open()) 
//     {
//         std::cerr << "Unable to open the File." << std::endl;
//         return;
//     }
//     std::vector<std::vector<double>> xyzMap;
//     QHash<QPoint, QPointF> schlegelMap;
//     int cnat;
//     std::string useless,atom;
//     File >> cnat;
//     qDebug() << cnat;
//     File >> useless;
//     double x, y, z;
//     for (int index = 0; index < cnat; index++)
//     {
//         File >> atom >> x >> y >> z;
//         qDebug() << x << y << z;
//         xyzMap.push_back({x, y, z});
//     }

//     File >> useless;
//     for (int index = 0; index < cnat; index++)
//     {
//         File >> useless >> x >> y;
//         qDebug() << QPointF(x, y);
//         schlegelMap[QPoint(0, index)] = QPointF(x, y);
//     }

//     File >> useless;
//     int be, en;
//     std::vector<std::pair<int, int>> bondlist;
//     qDebug() << "start";
//     while (File >> be >> en) 
//     {
//         qDebug() << be << en;
//         bondlist.emplace_back(be, en);
//     }
// }
