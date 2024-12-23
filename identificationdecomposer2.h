#ifndef IDENTIFICATIONDECOMPOSER2_H
#define IDENTIFICATIONDECOMPOSER2_H

#include <QtWidgets>



class UndoRedoManager;
class GraphModel;
class IdentificationModelManager;
class IdentificationDecomposer2 : public QWidget
{
    Q_OBJECT
    friend class WidthDecomposeCommand2;
public:
    explicit IdentificationDecomposer2(QWidget *parent = 0);
    virtual ~IdentificationDecomposer2();
    void setRootGraph(GraphModel* graphmodel);
signals:
    void ZZPolynomialRequest(GraphModel* model);
public slots:
    void clear();
    QString getZZPolynomial();
    void undo();
    void redo();
    void exportSVG();
private slots:
    void unidentItemSelected(QModelIndex index);
    void identItemDoubleClicked(QModelIndex index);
    void IdentifyButtonClicked();
    void UnidentifyButtonClicked();
    void identRightClick(QPoint point);
    void unidentRightClick(QPoint point);
    void confirmCombination(QListView* target,QPoint point);
    void childZZPolynomialRequest(GraphModel* model);
private:
    void createUI();
    bool isomorphismCheck(QModelIndexList list);
private:
    QListView* m_unidentified;
    QListView* m_identified;
    QTextDocument *m_freeterm_text;
    IdentificationModelManager* m_manager;
    UndoRedoManager* m_undoRedoManager;

};

#endif // IDENTIFICATIONDECOMPOSER_H2
