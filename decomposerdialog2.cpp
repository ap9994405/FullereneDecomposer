#include "decomposerdialog2.h"
#include "decomposer2.h"
#include "uniquetaggenerator.h"
#include "graphmodel.h"
#include <QtWidgets>

DecomposerDialog2::DecomposerDialog2(UniqueTagGenerator* tagGen, QWidget *parent) :
    QDialog(parent)
{
    this->resize(800,600);

    m_decomposer = new Decomposer2(tagGen,this);
    m_decomposer->setAllowFragments(false);

    connect(m_decomposer, SIGNAL(ZZPolynomialRequest(GraphModel*)), this, SLOT(childZZPolynomialRequest(GraphModel*)));

    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(m_decomposer);
    vbox->setMargin(0);

//    QHBoxLayout *hbox = new QHBoxLayout();
//    QPushButton *okbutton = new QPushButton(tr("OK"));
//    okbutton->setMaximumWidth(100);
//    QPushButton *cancelbutton = new QPushButton(tr("Cancel"));
//    cancelbutton->setMaximumWidth(100);

//    connect(cancelbutton, SIGNAL(pressed()), this, SLOT(reject()));
//    connect(okbutton, SIGNAL(pressed()), this, SLOT(accept()));
//    hbox->setMargin(5);
//    hbox->addWidget(okbutton);
//    hbox->addWidget(cancelbutton);
//    vbox->addLayout(hbox);

    QDialogButtonBox *buttons = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);

    connect(buttons, SIGNAL(accepted()),this, SLOT(accept()));
    connect(buttons, SIGNAL(rejected()),this, SLOT(reject()));

    vbox->addWidget(buttons);


    this->setLayout(vbox);


}

void DecomposerDialog2::setRootGraphModel(GraphModel *model)
{
    m_decomposer->setRootGraph(model);
}

QList<GraphModel *> DecomposerDialog2::getLeafs()
{
    return m_decomposer->getLeafs();
}



void DecomposerDialog2::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
    {
        reject();
    }
}

void DecomposerDialog2::childZZPolynomialRequest(GraphModel *model)
{
    emit ZZPolynomialRequest(model);
}


