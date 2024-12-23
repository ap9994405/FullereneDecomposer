#include "mainwindow.h"
#include "graphmodel.h"
#include "graphmodelgraphicsitem.h"

#include "zoomableview.h"

#include "VERION_INFO.H"

#include "builderwidget.h"
#include "decomposer.h"
#include "decomposer2.h"
#include "identificationdecomposer.h"
#include "identificationdecomposer2.h"

#include "zzpolynomialcalculatorpanel.h"

#include "graphmodeldisplaywidget.h"

#include "SetAtomLinkDialog.h"

#include "formats.h"
#include "file_helpers.h"
#include "utils.h"

//#include "graphmodelgraphicsitem.h"
//#include "graphmodelgraphicsitem2.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setAttribute(Qt::WA_DeleteOnClose);

    m_workingGraphModel = NULL;

    this->setWindowTitle(tr("FullereneDecomposer"));

    m_builder = new BuilderWidget();
    connect(m_builder, SIGNAL(ClearAllWindows()), this, SLOT(clearDecomposer()));
    m_tabWidget = new QTabWidget(this);
    this->setCentralWidget(m_tabWidget);
    m_tabWidget->addTab(m_builder, tr("Builder"));

    m_decomposer = new Decomposer(0,this);
    m_tabWidget->addTab(m_decomposer, tr("Depth-mode StarDecomposer"));

    m_decomposer2 = new Decomposer2(0,this);
    m_tabWidget->addTab(m_decomposer2, tr("Depth-mode ZZDecomposer"));

    m_identDecomposer = new IdentificationDecomposer(this);
    m_tabWidget->addTab(m_identDecomposer, tr("Width-mode StarDecomposer"));

    m_identDecomposer2 = new IdentificationDecomposer2(this);
    m_tabWidget->addTab(m_identDecomposer2, tr("Width-mode ZZDecomposer"));

    m_zzCalculatorPanel = new ZZPolynomialCalculatorPanel(this);
    m_tabWidget->addTab(m_zzCalculatorPanel, tr("Polynomial Calculator"));

    connect(m_builder,SIGNAL(ZZPolynomialRequest(GraphModel*)),this, SLOT(builderProcessZZPolynomialRequest(GraphModel*)));
    connect(m_decomposer,SIGNAL(ZZPolynomialRequest(GraphModel*)),this,SLOT(processZZPolynomialRequest(GraphModel*)));
    connect(m_decomposer2,SIGNAL(ZZPolynomialRequest(GraphModel*)),this,SLOT(processZZPolynomialRequest(GraphModel*)));
    connect(m_identDecomposer,SIGNAL(ZZPolynomialRequest(GraphModel*)),this,SLOT(processZZPolynomialRequest(GraphModel*)));
    connect(m_identDecomposer2,SIGNAL(ZZPolynomialRequest(GraphModel*)),this,SLOT(processZZPolynomialRequest(GraphModel*)));
    connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabPageChanged(int)));

    createActions();
    createMenus();
    createToolbars();

    createDocks();
}

void MainWindow::tabPageChanged(int index)
{
    if (index == 3) // for Width-mode StarDecomposer
    {
        m_undo->setEnabled(true);
        m_redo->setEnabled(true);
    }
    else if (index == 4) // for Width-mode ZZDecomposer
    {
        m_undo->setEnabled(true);
        m_redo->setEnabled(true);
    }
    else
    {
        m_undo->setEnabled(false);
        m_redo->setEnabled(false);
    }
    int tmpindex;
    if (index > 0)
    {
        readschlegel(m_builder->getGraphModel()->getfolderename(), m_builder->getGraphModel()->getfilename());
        if (m_workingGraphModel == NULL)
        {
            m_workingGraphModel = m_builder->getGraphModel();
            if ( m_workingGraphModel->isEmpty())
            {
                delete m_workingGraphModel;
                m_workingGraphModel = NULL;
            }
            else
            {
                m_decomposer->setRootGraph(m_builder->getGraphModel());
                m_decomposer2->setRootGraph(m_builder->getGraphModel());
                m_identDecomposer->setRootGraph(m_builder->getGraphModel());
                m_identDecomposer2->setRootGraph(m_builder->getGraphModel());
                m_zzCalculatorPanel->addRow(m_builder->getGraphModel());

                m_zzCalculatorPanel->setFilename(m_builder->getGraphModel()->getfolderename(), m_builder->getGraphModel()->getfilename());
                //readschlegel(m_model -> getfolderename(),m_model -> getfilename());
		tmpindex = index;
            }

        }
        else
        {
            GraphModel* model = m_builder->getGraphModel(); //problem here
            QSet<EdgeModel> s1, s2;
            QListIterator<EdgeModel> it(m_workingGraphModel->getAllEdges());
            while(it.hasNext())
            {
                s1.insert(it.next());
            }
            QListIterator<EdgeModel> it2(model->getAllEdges());
            while(it2.hasNext())
            {
                s2.insert(it2.next());
            }
            if (s1!=s2)
            {
                delete m_workingGraphModel;
                m_workingGraphModel = NULL;
                m_workingGraphModel = model;
                m_decomposer->clear();
                m_decomposer->setRootGraph(m_builder->getGraphModel());
                m_decomposer2->clear();
                m_decomposer2->setRootGraph(m_builder->getGraphModel());

                m_identDecomposer->clear();
                m_identDecomposer->setRootGraph(m_builder->getGraphModel());

                m_identDecomposer2->clear();
                m_identDecomposer2->setRootGraph(m_builder->getGraphModel());
                m_zzCalculatorPanel->addRow(m_builder->getGraphModel());

                m_zzCalculatorPanel->setFilename(m_builder->getGraphModel()->getfolderename(), m_builder->getGraphModel()->getfilename());
                //readschlegel(m_model -> getfolderename(),m_model -> getfilename());
            }
            else
            {
                delete model;
            }
        }
    }
    if (index == 0)
    {
        m_savefile->setEnabled(true);
        m_zzinfo->setEnabled(false);
    }
    else if (index == 1)
    {
        m_savefile->setEnabled(true);
        m_zzinfo->setEnabled(false);
    }
    else if ( index == 2 )
    {
        m_zzinfo->setEnabled(false);
        m_savefile->setEnabled(true);
    }
    else if ( index == 3 )
    {
        m_zzinfo->setEnabled(true);
        m_savefile->setEnabled(true);
    }
    else if ( index == 4 )
    {
        m_zzinfo->setEnabled(true);
        m_savefile->setEnabled(true);
    }
    else
    {
        m_savefile->setEnabled(false);
        m_zzinfo->setEnabled(false);
    }

    // if (index == 1)
    // {
    //     m_toogleSeparateFragments->setEnabled(true);
    // }
    // else
    // {
    //     m_toogleSeparateFragments->setEnabled(false);
    // }

}

void MainWindow::clearAll()
{
    m_builder->clear();
    m_decomposer->clear();
    m_decomposer2->clear();
    m_tabWidget->setCurrentIndex(0);
    m_identDecomposer->clear();
    m_identDecomposer2->clear();
    m_workingGraphModel = NULL;
}
void MainWindow::clearDecomposer()
{
    m_decomposer->clear();
    m_decomposer2->clear();
    m_tabWidget->setCurrentIndex(0);
    m_identDecomposer->clear();
    m_identDecomposer2->clear();
    m_workingGraphModel = NULL;
}
void MainWindow::selectall()
{
    m_builder->SelectAllGraph();
    m_tabWidget->setCurrentIndex(0);
    m_workingGraphModel = NULL;
}

void MainWindow::createActions()
{
    m_newfile = new QAction(tr("Clean All"),this);
    connect(m_newfile, SIGNAL(triggered()), this, SLOT(clearAll()));
    m_selectall = new QAction(tr("Select All"),this);
    connect(m_selectall, SIGNAL(triggered()), this, SLOT(selectall()));
    m_savefile = new QAction(QIcon(":/images/savefile.png"),tr("&Save"),this);
    m_openfile = new QAction(QIcon(":/images/openfile.png"),tr("&Open"),this);
//    m_savefile->setEnabled(false);

//    connect(m_savefile, SIGNAL(triggered()), this, SLOT(exportSVG()));
    connect(m_savefile, SIGNAL(triggered()), this, SLOT(saveClicked()));

    m_zzinfo = new QAction(tr("Show &ZZ Formula"), this);
    connect(m_zzinfo, SIGNAL(triggered()), this, SLOT(showZZInfo()));
    m_zzinfo->setEnabled(false);

//    m_hidezeros = new QAction(tr("Hide &Zeros"), this);
//    m_hidezeros->setCheckable(true);
//    connect(m_hidezeros, SIGNAL(toggled(bool)), m_decomposer, SLOT(setHideZeros(bool)));

    m_undo = new QAction(tr("Undo"), this);
    m_redo = new QAction(tr("Redo"), this);
    connect(m_undo, SIGNAL(triggered()), this, SLOT(undo()));
    connect(m_redo, SIGNAL(triggered()), this, SLOT(redo()));
    m_undo->setEnabled(false);
    m_redo->setEnabled(false);
}

void MainWindow::createToolbars()
{
    m_toolbar = addToolBar(tr("General"));
    m_toolbar->addAction(m_newfile);
    m_toolbar->addAction(m_selectall);
    m_toolbar->addAction(m_savefile);
    m_toolbar->addSeparator();
    m_toolbar->addAction(m_undo);
    m_toolbar->addAction(m_redo);
    m_toolbar->addSeparator();
    m_toolbar->addAction(m_zzinfo);

/*    QAction *test = new QAction(tr("Rotate Grid"),this);
    test->setCheckable(true);
    connect(test, SIGNAL(toggled(bool)),this, SLOT(setGridRotate(bool)));
    m_toolbar->addAction(test);


    // m_toolbar->addSeparator();
    // m_toogleSeparateFragments = new QAction(tr("Separate fragments"),this);
    // m_toogleSeparateFragments->setCheckable(true);
    // m_toogleSeparateFragments->setChecked(true);
    // m_toogleSeparateFragments->setEnabled(false);
    // connect(m_toogleSeparateFragments, SIGNAL(triggered(bool)),this, SLOT(toggleSeparateFragments(bool)));
    // m_toolbar->addAction(m_toogleSeparateFragments);

    test = new QAction(tr("Set atom links"),this);
    connect(test, SIGNAL(triggered()),this, SLOT(test()));
    m_toolbar->addAction(test);
*/
//    m_toolbar->addAction(m_hidezeros);

}

void MainWindow::createMenus()
{
    QMenu* menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(tr("&Exit"), this, SLOT(close()));

    menu = menuBar()->addMenu(tr("&Advance"));
    menu->addAction(tr("&Take screenshot"), this, SLOT(screenshot()));

    menu = menuBar()->addMenu(tr("&Help"));
    menu->addAction(tr("&About Qt..."), this, SLOT(showAboutQt()) );
    menu->addAction(tr("&About..."), this, SLOT(showAbout()));
}

void MainWindow::createDocks()
{
}

void MainWindow::saveClicked()
{
    if ( m_tabWidget->currentIndex() == 0)
    {
        GraphModel* mo = m_builder->getGraphModel();
        if (!mo->isEmpty())
            export_structure(mo);
        delete mo;
    }
    else if (m_tabWidget->currentIndex() == 1)
    {
        bool comp;
        QString filename = getSVGExportFilename(this,&comp);
        if (!filename.isNull())
        {
            m_decomposer->exportSVG(filename, comp);
        }
    }
    else if (m_tabWidget->currentIndex() == 2)
    {
        bool comp;
        QString filename = getSVGExportFilename(this,&comp);
        if (!filename.isNull())
        {
            m_decomposer2->exportSVG(filename, comp);
        }
    }
    else if (m_tabWidget->currentIndex() == 3)
    {
        m_identDecomposer->exportSVG();
    }

    else if (m_tabWidget->currentIndex() == 4)
    {
        m_identDecomposer2->exportSVG();
    }

    // else if (m_tabWidget->currentIndex() == 4)
    // {
    //     bool comp;
    //     QString filename = getSVGExportFilename(this,&comp);
    //     m_zzAromaticityCalculatorPanel->exportSVG(filename, comp);

    // }
    // else if (m_tabWidget->currentIndex() == 5)
    // {
    //     bool comp;
    //     QString filename = getSVGExportFilename(this,&comp);
    //     m_zzSpinpopulaitonCalculatorPanel->exportSVG(filename, comp);

    // }

    // else if (m_tabWidget->currentIndex() == 6)
    // {
    //     bool comp;
    //     QString filename = getSVGExportFilename(this,&comp);
    //     m_zzSpinpopulaitonCalculatorPanel2->exportSVG(filename, comp);

    // }
    // else if (m_tabWidget->currentIndex() == 7)
    // {
    //     bool comp;
    //     QString filename = getSVGExportFilename(this,&comp);
    //     m_zzSpinpopulaitonCalculatorPanel3->exportSVG(filename, comp);

    // }

    // else if (m_tabWidget->currentIndex() == 8)
    // {
    //     bool comp;
    //     QString filename = getSVGExportFilename(this,&comp);
    //     m_johanna->exportSVG(filename, comp);

    // }
//9
}

void MainWindow::showZZInfo()
{
    if (m_tabWidget->currentIndex() == 3)
    {
        QString ZZ = m_identDecomposer->getZZPolynomial();
        QMessageBox msgBox;

        msgBox.setText(ZZ);
        msgBox.setDetailedText(ZZ);
        msgBox.exec();
    }
    else if (m_tabWidget->currentIndex() == 4)
    {
        QString ZZ = m_identDecomposer2->getZZPolynomial();
        QMessageBox msgBox;

        msgBox.setText(ZZ);
        msgBox.setDetailedText(ZZ);
        msgBox.exec();
    }
    else if (m_tabWidget->currentIndex() == 1)
    {
        QString ZZ = m_decomposer->getZZPolynomial();
        QMessageBox msgBox;

        msgBox.setText(ZZ);
        msgBox.setDetailedText(ZZ);
        msgBox.exec();
    }
    else if (m_tabWidget->currentIndex() == 2)
    {
        QString ZZ = m_decomposer2->getZZPolynomial();
        QMessageBox msgBox;

        msgBox.setText(ZZ);
        msgBox.setDetailedText(ZZ);
        msgBox.exec();
    }
}

void MainWindow::showAbout()
{
    QMessageBox msgBox;
    QString version("Version: %1.%2.%3 <br>Website:<a href='http://qcl.ac.nctu.edu.tw/zzdecomposer'>http://qcl.ac.nctu.edu.tw/zzdecomposer</a><br>Email: sol.chou@gmail.com<br>Powered by Chien-Pin Chou");
    msgBox.setTextFormat(Qt::RichText);
    msgBox.setText(version.arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_REVISION));
    msgBox.setWindowTitle("ZZDecomposer");
    msgBox.exec();
}

void MainWindow::showAboutQt()
{
    QMessageBox::aboutQt(this,tr("ZZDecomposer"));
}

void MainWindow::undo()
{
    if (m_tabWidget->currentIndex()==3)
    {
        m_identDecomposer->undo();
    }
    else if (m_tabWidget->currentIndex()==4)
    {
        m_identDecomposer2->undo();
    }
}

void MainWindow::redo()
{
    if (m_tabWidget->currentIndex()==3)
    {
        m_identDecomposer->redo();
    }
    else if (m_tabWidget->currentIndex()==4)
    {
        m_identDecomposer2->redo();
    }
}

void MainWindow::processZZPolynomialRequest(GraphModel *model)
{

    m_zzCalculatorPanel->addRowAndRun(model);
    // m_tabWidget->setCurrentWidget(m_zzCalculatorPanel);
}

void MainWindow::builderProcessZZPolynomialRequest(GraphModel *model)
{
    if (m_workingGraphModel == NULL)
    {
        m_workingGraphModel = m_builder->getGraphModel();
        if ( m_workingGraphModel->isEmpty())
        {
            delete m_workingGraphModel;
            m_workingGraphModel = NULL;
        }
        else
        {
            m_zzCalculatorPanel->addRowAndRun(model);
        }

    }
}

/*void MainWindow::setGridRotate(bool rotate)
{
    m_builder->setGridRotate(rotate);
    m_decomposer->setGridRotate(rotate);
}*/

// void MainWindow::toggleSeparateFragments(bool isSeparated)
// {
//     QMessageBox qbox(this);
//     qbox.setWindowTitle(tr("ZZDecomposer"));
//     qbox.setText(tr("Changing the fragment separation mode will reset the decomposer. Continue?"));
//     qbox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
//     qbox.setIcon(QMessageBox::Question);
//     int ret = qbox.exec();
//     if (ret == QMessageBox::Yes)
//     {
//         m_decomposer->clear();
//         m_decomposer->setAllowFragments(isSeparated);
//         m_decomposer->setRootGraph(this->m_builder->getGraphModel());
//     }
//     else
//     {
//         m_toogleSeparateFragments->toggle();
//         return;
//     }
// }

void MainWindow::test()
{
    GraphModel* model = m_builder->getGraphModel();
    if ( model->isEmpty())
    {
        return;
    }
    SetAtomLinkDialog dia(model);
    dia.resize(1024,767);
    int ret = dia.exec();
    if (ret == QDialog::Accepted)
    {
        m_decomposer->setRootGraph(model);
        m_workingGraphModel = model;
        m_tabWidget->setCurrentIndex(1);
    }
}

void MainWindow::screenshot()
{
    QString filename = QFileDialog::getSaveFileName(
           this,
           tr("Save screenshot to image"),
           QDir::homePath(),
           tr("png files (*.png)") );

    if( !filename.isNull() )
    {
        QPixmap image(this->width()*5.0, this->height()*5.0);
        QPainter painter;
        painter.begin(&image);
        double scale = 5.0;
        painter.scale(scale, scale);
        this->render(&painter);
        image.save(filename, "png",0);
    }

}

