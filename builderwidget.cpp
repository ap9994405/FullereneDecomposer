#include "builderwidget.h"
#include "builderscene.h"
#include "bonditem.h"
#include <QtWidgets>
#include "utils.h"
#include "ringitem.h"
#include "zoomableview.h"
#include <QtGlobal>

#include "graphmodel.h"

#include <iostream>
#include <fstream>


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
    readxyz("c20ih");
    readschlegel("c20ih");
    draw_grid("c20ih");
    connect(view, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));;
    QListWidget *listWidget = new QListWidget(this);
    listWidget->addItem("C20Ih");
    listWidget->addItem("C24D6d");
    listWidget->addItem("C26D3h");
    listWidget->addItem("C28D2");
    listWidget->addItem("C28Td");
    listWidget->addItem("C60Ih");
    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onListItemClicked(QListWidgetItem*)));
    layout->addWidget(listWidget);
    layout->setStretch(0, 1);
    layout->setStretch(1, 0); 
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

void BuilderWidget::draw_grid(QString filename)
{
    // in fullerene bondlength not fixed
    double bondlength = 30.0;
    QString abspath = QDir::currentPath();
    QString sep = QDir::separator();
    QString m_filename = abspath+sep+"readfile" + sep + filename + +"_bondlist";
    QFile bondlfile(m_filename);
    if (!bondlfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << "Unable to open the schlegel file.";
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
    // QPolygonF ring;
    // RingItem *r = new RingItem(QPoint(1,1));
    // connect(r, SIGNAL(clicked(RingItem*)), this, SLOT(ringClicked(RingItem*)));
    // ring << vertexXY2XY(QPoint(0,0)) << vertexXY2XY(QPoint(0,1)) << vertexXY2XY(QPoint(0,8)) << vertexXY2XY(QPoint(0,9)) << vertexXY2XY(QPoint(0,10)) << vertexXY2XY(QPoint(0,0));
    
    // r->setPolygon(ring);
    // r->setOpacity(0.3);
    // r->setZValue(-10);
    // scene->addItem(r);
    
    // start here
    // int len_x = 2;
    // int len_y = 2;

    // QPoint vertex_xys[7] = {QPoint(1,0), QPoint(0,-1), QPoint(-1,-1), QPoint(-1,0), QPoint(0,1), QPoint(1,1), QPoint(1,0)};

    // for(int i=0; i<len_x; ++i)
    // {
    //     for(int j=0; j<len_y;++j)
    //     {
    //         QPoint ring_center = ringXY2vertexXY(QPoint(i,j));
    //         QPolygonF ring;
    //         RingItem *r = new RingItem(QPoint(i,j));
    //         connect(r, SIGNAL(clicked(RingItem*)), this, SLOT(ringClicked(RingItem*)));
    //         for(int k=0; k<6; ++k)
    //         {
    //             // creat a bond of ring from ring center
    //             QPoint ver_1 = ring_center + vertex_xys[k];
    //             QPoint ver_2 = ring_center + vertex_xys[k+1];
    //             // save real position of v1 to ring
    //             QPointF v1 = vertexXY2XY(ver_1,bondlength); // real position

    //             EdgeModel edge(ver_1, ver_2);   // fake position but still transfer to real position in EdgeModel
                
    //             //edge using fake position
    //             if (!edges.contains(edge))  
    //             {   
    //                 // 0,0 is distance of bottom of ring and bond, 0,0 mean overlap  
    //                 item = new BondItem(0,0,bondlength, edge, BondItem::Grid);
    //                 connect(item, SIGNAL(bondSelected(BondItem*)), this, SLOT(selectBond(BondItem*)));
    //                 connect(item, SIGNAL(bondUnselected(BondItem*)), this, SLOT(unselectBond(BondItem*)));
    //                 edges.insert(edge, item);
    //                 r->addBondItem(item);
    //                 scene->addItem(item);
    //             }
    //             else
    //             {
    //                 QHash<EdgeModel, BondItem*>::iterator eit=edges.find(edge);

    //                 BondItem *item = eit.value();
    //                 if (eit != edges.end())
    //                 {
    //                     r->addBondItem(item);
    //                 }
    //             }
    //             ring << v1 ;
    //         }
    //         r->setPolygon(ring);
    //         r->setOpacity(0.3);
    //         r->setZValue(-10);
    //         scene->addItem(r);
    //     }
    // }
    // end here
    view->centerOn(scene->sceneRect().center());

}
void BuilderWidget::onListItemClicked(QListWidgetItem *item)
{
    QString selectedItemText = item->text();
    if (selectedItemText == "C20Ih")
    {   
        Loadgraph("c20ih",2.0);
    }
    else if (selectedItemText == "C24D6d")
    {
        Loadgraph("c24d6d",2.0);
    }
    else if (selectedItemText == "C26D3h")
    {
        Loadgraph("c26d3h",2.0);
    }
    else if (selectedItemText == "C28D2")
    {
        Loadgraph("c28d2",2.0);
    }
    else if (selectedItemText == "C28Td")
    {
        Loadgraph("c28td",2.0);
    }
    else if (selectedItemText == "C60Ih")
    {
        Loadgraph("c60ih",3.0);
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
    myMenu.addAction("Compute ZZ polynomial...");

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
    return new GraphModel(this->getGraph(),QList<EdgeModel>(), NULL, GraphModel::None, 0);
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
void BuilderWidget::Loadgraph(const QString& graphName, double graphSize)
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
    readxyz(graphName);
    readschlegel(graphName);
    setgraphsize(graphSize);
    draw_grid(graphName);
    connect(view, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
    qDebug() << graphName;
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