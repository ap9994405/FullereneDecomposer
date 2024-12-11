#ifndef DECOMPOSERDIALOG2_H
#define DECOMPOSERDIALOG2_H

#include <QDialog>

class QAbstractButton;
class GraphModel;
class Decomposer2;
class UniqueTagGenerator;
class DecomposerDialog2 : public QDialog
{
    Q_OBJECT
public:
    explicit DecomposerDialog2(UniqueTagGenerator* tagGen, QWidget *parent = 0);
    void setRootGraphModel(GraphModel* model);
    QList<GraphModel*> getLeafs();

signals:
    void ZZPolynomialRequest(GraphModel* model);
public slots:

protected:
    void keyPressEvent(QKeyEvent *e);
private slots:
    void childZZPolynomialRequest(GraphModel* model);
private:
    Decomposer2* m_decomposer;
//    GraphModel* m_rootGraphModel;
};

#endif // DECOMPOSERDIALOG2_H
