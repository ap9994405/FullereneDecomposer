#include "zzpolynomialcalculator.h"

#include "graphmodel.h"
#include "utils.h"
#include <QtWidgets>
#include <QtXml>
#include <QDebug>
#include <QThread>
#include <iostream>
#include <QSysInfo>

#include <fstream>

using namespace std;



ZZPolynomialCalculator::ZZPolynomialCalculator(GraphModel* model, QObject *parent) :
    QThread(parent), m_model(model), m_hasError(false)
{
    this->setTerminationEnabled(true);
//    m_process = NULL ;
//    connect(m_process,SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(jobFinished(int,QProcess::ExitStatus)));
//    connect(m_process,SIGNAL(error(QProcess::ProcessError)), this, SLOT(jobFinishedError(QProcess::ProcessError)));
}

void ZZPolynomialCalculator::run()
{
    m_process = new QProcess();
    QString osType = QSysInfo::productType();
    QString zzcalcname;
    if (osType == "windows")
    {
        zzcalcname = "StarCalculator.exe";
    }
    else
    {
        zzcalcname = "StarCalculator";
    }

    m_poly.clear();
    QFileInfo cmdInfo = QFileInfo(QFileInfo(QCoreApplication::arguments().at(0)).absolutePath(),zzcalcname);

    if (!cmdInfo.exists() || !cmdInfo.isExecutable())
    {
        m_hasError = true;
        m_errorMsg = zzcalcname + " not found in the same path as FullereneDecomposer";
        return;
    }
    QString cmd = cmdInfo.absoluteFilePath() ;

    QStringList arguments;
//    arguments << "-Q";
    arguments << "-X" << "-Q" ;
    readxyz(m_model -> getfolderename(),m_model -> getfilename());
    QTemporaryFile file;    //temporaryfile
    if (file.open())
    {
        arguments << file.fileName();
        {
            QTextStream inOut(&file);
            inOut << m_model->getZZInput(true);  // GraphModel::getZZInput(bool connections, bool hydrogens)
            std::string ZZInput = m_model->getZZInput(true).toStdString();
            std::ofstream InputData;
        }

        m_process->start(cmd, arguments);
        m_process->waitForFinished(-1);

        if (m_process->exitCode()!=0)
        {
            m_hasError = true;
            m_errorMsg = zzcalcname + " crashed.";
            return;
        }

        QByteArray result = m_process->readAll();
        QString t(result);
        QDomDocument resultXML;
        bool failed = !resultXML.setContent(t);
        if (failed)
        {
            m_hasError = true;
            m_errorMsg = "The output from " + zzcalcname + " has wrong format1.";
            return;
        }
        QDomElement zzpoly = resultXML.documentElement();
        if (zzpoly.isNull() || zzpoly.tagName() != "zzpolynomial")
        {
            m_hasError = true;
            m_errorMsg = "The output from " + zzcalcname + " has wrong format2.";
            qDebug() << t;
            return;
        }

        QDomNodeList terms = zzpoly.elementsByTagName("term");
        QDomNodeList total = zzpoly.elementsByTagName("total");

        if (total.count() == 1)
        {
            QDomElement total_elem = total.at(0).toElement();
            QString total_str = total_elem.text();
            m_total = total_str;
        }
        for (int i = 0; i < terms.count(); ++i)
        {
            QDomNode termNode = terms.item(i);
            QDomElement termElem = termNode.toElement();
            QDomNodeList orders = termElem.elementsByTagName("order");
            QDomNodeList coeffs = termElem.elementsByTagName("coefficient");
            if (orders.count() != 1 || coeffs.count() != 1)
            {
                m_hasError = true;
                m_errorMsg = "The output from " + zzcalcname + " has wrong format3.";
                qDebug() << t;
                return;
            }
            QDomElement orderElem = orders.at(0).toElement();
            QDomElement coeffElem = coeffs.at(0).toElement();

            int order = orderElem.text().toInt();
            QString coeff = coeffElem.text();
            m_poly.addTerm(coeff,order);
        }
    }
    delete m_process;
    run2();
}
void ZZPolynomialCalculator::run2()
{
    m_process = new QProcess();
    QString osType = QSysInfo::productType();
    QString zzcalcname;
    if (osType == "windows")
    {
        zzcalcname = "GZZCalculator.exe";
    }
    else
    {
        zzcalcname = "GZZCalculator";
    }

    m_poly2.clear();

    // .at(0) is path of zzcalcname
    // cmd is the program we want to call
    QFileInfo cmdInfo = QFileInfo(QFileInfo(QCoreApplication::arguments().at(0)).absolutePath(),zzcalcname);

    if (!cmdInfo.exists() || !cmdInfo.isExecutable())
    {
        m_hasError = true;
        m_errorMsg = zzcalcname + " not found in the same path as GZZDecomposer";
        return;
    }
    QString cmd = cmdInfo.absoluteFilePath() ;

    // int nthreads = QThread::idealThreadCount() - 1;
    // if (nthreads < 1 )
    //     nthreads = 1;

    QStringList arguments;

    // arguments << "-x" << QString("%1").arg(nthreads);
    arguments << "-x" << "-B";
    QTemporaryFile file;
    if (file.open())
    {
        arguments << file.fileName();
        {
            QTextStream inOut(&file);
            inOut << m_model->getZZInput(true);  // GraphModel::getZZInput(bool connections, bool hydrogens)
        }

        m_process->start(cmd, arguments);
        m_process->waitForFinished(-1); // waiting for finish

        if (m_process->exitCode()!=0)   // if finish exitCode() == 0
        {
            m_hasError = true;
            m_errorMsg = zzcalcname + " crashed.";
            return;
        }

        QByteArray result = m_process->readAll();   // read output save in result
        QString t(result);  // convert QbyteArray into QString

        QDomDocument resultXML; // QDomDocument save XML
        bool failed = !resultXML.setContent(t); // check t is XML format
        if (failed)
        {
            m_hasError = true;
            m_errorMsg = "The output from " + zzcalcname + " has wrong format1.";
            qDebug() << t << m_errorMsg;
            return;
        }


        QDomElement gzzpoly = resultXML.documentElement();   // get root node(most top node) in resultXML
        if (gzzpoly.isNull() || gzzpoly.tagName() != "gzzpolynomial")
        {
            m_hasError = true;
            m_errorMsg = "The output from " + zzcalcname + " has wrong format2.";
            qDebug() << t << m_errorMsg;
            return;
        }
        // finding all node name
        QDomNodeList terms = gzzpoly.elementsByTagName("term");
        QDomNodeList total_zz = gzzpoly.elementsByTagName("total_zz");
        QDomNodeList total_gzz = gzzpoly.elementsByTagName("total_gzz");

        if (total_zz.count() == 1)
        {
            QDomElement total_elem = total_zz.at(0).toElement();
            QString total_str = total_elem.text();
            m_total_zz = total_str;
        }
        if (total_gzz.count() == 1)
        {
            QDomElement total_elem = total_gzz.at(0).toElement();
            QString total_str = total_elem.text();
            m_total_gzz = total_str;
        }
        for (int i = 0; i < terms.count(); ++i) //loop every term
        {
            QDomNode termNode = terms.item(i);
            QDomElement termElem = termNode.toElement();    //termElem = terms(i) node
            QDomNodeList orders_x = termElem.elementsByTagName("order_x");  //get order node
            QDomNodeList orders_y = termElem.elementsByTagName("order_y");  //get order node
            QDomNodeList coeffs = termElem.elementsByTagName("coefficient");    //get coefficient node
            if (orders_x.count() != 1 || orders_y.count() != 1 || coeffs.count() != 1)
            {
                m_hasError = true;
                m_errorMsg = "The output from " + zzcalcname + " has wrong format3.";
                qDebug() << t << m_errorMsg;
                return;
            }
            QDomElement orderElem_x = orders_x.at(0).toElement();   //turn QDomNode to QDomElement
            QDomElement orderElem_y = orders_y.at(0).toElement();   //turn QDomNode to QDomElement
            QDomElement coeffElem = coeffs.at(0).toElement();   //turn QDomNode to QDomElement

            int order_x = orderElem_x.text().toInt();
            int order_y = orderElem_y.text().toInt();
            QString coeff = coeffElem.text();

            m_poly2.addTerm2(coeff,order_x,order_y);
        }
    }
    delete m_process;
}

Polynomial<QString> ZZPolynomialCalculator::getPoly()
{
    return m_poly;
}

Polynomial<QString> ZZPolynomialCalculator::getPoly2()
{
    return m_poly2;
}

QString ZZPolynomialCalculator::getTotal() const
{
    return m_total;
}

QString ZZPolynomialCalculator::getTotal2() const
{
    return m_total_gzz;
}

QString ZZPolynomialCalculator::getTotal3() const
{
    return m_total_zz;
}

bool ZZPolynomialCalculator::hasError()
{
    return m_hasError;
}

const QString & ZZPolynomialCalculator::getErrorMsg()
{
    return m_errorMsg;
}

void ZZPolynomialCalculator::stop()
{
    m_process->kill();
}

void ZZPolynomialCalculator::serialRun()
{
    run();
}

