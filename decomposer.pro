#-------------------------------------------------
#
# Project created by QtCreator 2012-02-22T13:48:17
#
#-------------------------------------------------

QT       += core gui svg xml widgets
TARGET = FullereneDecomposer
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    edgemodel.cpp \
    neightborlist.cpp \
    ringitem.cpp \
    bonditem.cpp \
    builderscene.cpp \
    builderwidget.cpp \
    graphmodel.cpp \
    zoomableview.cpp \
    graphmodelgraphicsitem.cpp \
    graphmodeltreenode.cpp \
    layoutabletree.cpp \
    layoutabletreenode.cpp \
    decomposer.cpp \
    decomposer2.cpp \
    graphitemconnectingline.cpp \
    graphdecomposecommand.cpp \
    graphdecomposecommand2.cpp \
    undoredomanager.cpp \
    identificationdecomposer.cpp \
    identificationdecomposer2.cpp \
    decomposerdialog.cpp \
    decomposerdialog2.cpp \
    identificationmodelmanager.cpp \
    dragdroplistview.cpp \
    uniquetaggenerator.cpp \
    graphmodeltag.cpp \
    tagmodificationdialog.cpp \
    graphmodellistview.cpp \
    widthidentifycommand.cpp \
    widthcombinecommand.cpp \
    widthdecomposecommand.cpp \
    widthdecomposecommand2.cpp \
    zzpolynomialcalculator.cpp \
    zzpolynomialcalculatorpanel.cpp \
    zzcalculatorjob.cpp \
    zzpolynomialresultdelegate.cpp \
    graphmodelgraphicsitem2.cpp \
    graphmodeldisplaywidget.cpp \
    graphicsitemdebugdialog.cpp \
    mygraphicsitemgroup.cpp \
    testnode.cpp \
    formats.cpp \
    GraphModelGraphicsItemMarkerToggleVistor.cpp \
    widthmodeexportdialog.cpp \
    CCRC32.cpp \
    gzip_helper.cpp \
    file_helpers.cpp \
    SetAtomLinkDialog.cpp \
    QGraphicsTextItemWithBackgroundColor.cpp \
    utils.cpp

HEADERS  += mainwindow.h \
    edgemodel.h \
    neightborlist.h \
    ringitem.h \
    bonditem.h \
    utils.h \
    builderscene.h \
    builderwidget.h \
    polynomial.h \
    graphmodel.h \
    zoomableview.h \
    graphmodelgraphicsitem.h \
    icommand.h \
    graphmodeltreenode.h \
    layoutabletree.h \
    layoutabletreenode.h \
    decomposer.h \
    decomposer2.h \
    graphitemconnectingline.h \
    layoutabletree.h \
    graphdecomposecommand.h \
    graphdecomposecommand2.h \
    undoredomanager.h \
    identificationdecomposer.h \
    identificationdecomposer2.h \
    graphdelegate.h \
    decomposerdialog.h \
    decomposerdialog2.h \
    identificationmodelmanager.h \
    dragdroplistview.h \
    uniquetaggenerator.h \
    graphmodeltag.h \
    tagmodificationdialog.h \
    graphmodellistview.h \
    widthidentifycommand.h \
    widthcombinecommand.h \
    widthdecomposecommand.h \
    widthdecomposecommand2.h \
    zzpolynomialcalculator.h \
    zzpolynomialcalculatorpanel.h \
    basegraphdelegate.h \
    zzcalculatorjob.h \
    zzpolynomialresultdelegate.h \
    graphmodelgraphicsitem2.h \
    graphmodeldisplaywidget.h \
    stringpolynomial.h \
    graphicsitemdebugdialog.h \
    mygraphicsitemgroup.h \
    testnode.h \
    formats.h \
    ITreeNodeVistor.h \
    GraphModelGraphicsItemMarkerToggleVistor.h \
    VERION_INFO.H \
    widthmodeexportdialog.h \
    CCRC32.h \
    gzip_helper.h \
    file_helpers.h \
    SetAtomLinkDialog.h \
    QGraphicsTextItemWithBackgroundColor.h

RESOURCES += \
    zzpoly.qrc

FORMS += \
    tagmodificationdialog.ui \
    graphicsitemdebugdialog.ui \
    widthmodeexportdialog.ui



















































































