#ifndef BENZENOID_BUILDER_H
#define BENZENOID_BUILDER_H

#include <QtWidgets>
#include <QHash>
#include <QSet>
#include "edgemodel.h"
#include "bonditem.h"
#include "ringitem.h"


class BuilderScene;
class ZoomableView;
class GraphModel;

class BuilderWidget : public QWidget
{
    Q_OBJECT
public:
    BuilderWidget(QWidget *parent = 0);
    virtual ~BuilderWidget();
    QString ch2subscript(const QString &input);
private:
    ZoomableView *view;
    BuilderScene *scene;
    QHash<EdgeModel, BondItem* > edges;
    QSet<BondItem*> m_selected_edges;
    QSet<RingItem*> m_selected_rings;
    QTreeWidget *treeWidget;
    QString n_foldername;
    QString n_filename;
class CustomQLabel : public QLabel
{
//    Q_OBJECT
public:
    CustomQLabel(const QString &molecule, BuilderWidget *builderWidget = nullptr, QWidget *parent = nullptr) : QLabel(parent), m_molecule(molecule), m_builderWidget(builderWidget) {}
    QString getmolecule() const {return m_molecule;}

//signals:
    //void leftClicked(const QString &molecule, const QString &text);

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            m_Isomer = text();
            m_Isomer.replace("<sub>", "");
            m_Isomer.replace("</sub>", "");
            m_Isomer.replace("(", "");
            m_Isomer.replace(")", "");

            qDebug() << m_molecule << m_Isomer;
            m_builderWidget->Loadgraph(m_molecule,m_Isomer,8.5);
        }
        QLabel::mousePressEvent(event);
    }
    void wheelEvent(QWheelEvent *event) override {
        event->ignore();
    }
    //void setParentTreeWidgetItem(BuilderWidget::CustomTreeWidgetItem *parentItem) { m_parentItem = parentItem; }

private:
    QString m_molecule;
    QString m_Isomer;
    BuilderWidget *m_builderWidget;
};

class CustomTreeWidgetItem : public QTreeWidgetItem {
public:
    CustomTreeWidgetItem(QTreeWidgetItem *parentWidget) : QTreeWidgetItem(parentWidget) {

        BuilderWidget *builderWidget = dynamic_cast<BuilderWidget*>(parentWidget->treeWidget()->parent());
        if (!builderWidget) {
            qDebug() << "Parent widget is not a BuilderWidget.";
            return;
        }
        label = new CustomQLabel(parentWidget->text(0),builderWidget);
        treeWidget()->setItemWidget(this, 0, label);
    }

    CustomQLabel* getQLabel() {
        return label;
    }
private:
//    CustomQTextEdit *textEdit;
    CustomQLabel *label;
};


signals:
    void modified();
    void ZZPolynomialRequest(GraphModel*);
    void ClearAllWindows();
private slots:
    void selectBond(BondItem*);
    void unselectBond(BondItem*);
    void ringClicked(RingItem* ring);
    void contextMenu(QPoint point);
    void onTreeItemClicked(QTreeWidgetItem *item, int column);
public slots:
    void leftClicked3(const QString molecule, const QString text);
    // void ReadFile(QString filename);
    void clear();
    void draw_grid(QString foldername, QString filename);
    QList<EdgeModel> getGraph();
    GraphModel* getGraphModel();
    void setGridRotate(bool rotate);
    void SelectAllGraph();
    void Loadgraph(const QString& foldername, QString& graphName, double graphSize);
protected:

};

#endif // BENZENOID_BUILDER_H
