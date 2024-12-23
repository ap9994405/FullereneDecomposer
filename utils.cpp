#include "utils.h"
#include <cmath>
#include <QDebug>
#include <algorithm>
#include <QtGlobal>
#include <QVector3D>
#include <QDir>
#include <QFile>
#include <QTextStream>

const double PI = std::acos(-1.0);
static QHash<QPoint, QPointF> xyMap;
static QHash<QPoint, float> xMap, yMap, zMap;
static QString m_filename;
static double size = 4.0;
static QString abspath = QDir::currentPath();
static QString sep =QDir::separator();
void readschlegel(QString foldername, QString filename)
{
    foldername = subscript2ch(foldername);
    filename = subscript2ch(filename);

    m_filename = abspath+"/readfile"+"/"+foldername+"/schlegel"+"/"+filename+"_schlegel";
    QFile schlegelfile(m_filename);
    if (!schlegelfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << "Unable to open the schlegelfile.";
    }
    qreal x, y;
    int index=1;
    QTextStream in(&schlegelfile);
    while (!in.atEnd())
    {
        in >> x >> y;
        if (!in.atEnd())
        {
            xyMap[QPoint(0, index)] = QPointF(x, y);
            index += 1;
        }
    }
}
void readxyz(QString foldername, QString filename)
{
    foldername = subscript2ch(foldername);
    filename = subscript2ch(filename);
    m_filename = abspath+"/readfile"+"/"+foldername+"/"+filename;
    QString filePath = m_filename;
    QFile xyzfile(filePath);
    if (!xyzfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << "Unable to open the xyzfile.";
    }

    int cnat;
    QString atom;
    qreal x, y, z;
    int index=1;

    QTextStream in(&xyzfile);
    in >> cnat;
    while (index <= cnat && !in.atEnd())
    {
        in >> atom >> x >> y >> z;
        xMap[QPoint(0, index)] = x;
        yMap[QPoint(0, index)] = y;
        zMap[QPoint(0, index)] = z;
        index += 1;
    }
}
void setgraphsize(double m_size)
{
    size = m_size;
}
QPoint XY2VertexXY(QPointF old_p, double r)
{
    QPoint new_p;
    double sqr = sqrt(3.0);
    new_p.setX((2.0/(r*sqr))*old_p.x());
    double alay = (old_p.x()/(r*sqr))+old_p.y()/r;
    new_p.setY(alay);
    return new_p;
}
QPointF vertexXY2XY(QPoint old_p, double r)
{
    QPointF new_p;
    new_p = xyMap[old_p]*30*size; //bondlength is 30

    return new_p;
}
QVector3D vertexXY2XYZ(QPoint old_p)
{   
    float px, py, pz;
    px = xMap[old_p];
    py = yMap[old_p];
    pz = zMap[old_p];

    return QVector3D(px, py, pz);
}
QPoint ringXY2vertexXY(QPoint old_p)
{
    QPoint n10(2,1);
    QPoint n01(1,2);
    QPoint n02(0,3);
    QPoint new_p;
    if (old_p.y() % 2 == 1)
    {
        new_p = old_p.x()*n10+((old_p.y()-1)/2)*n02+n01;
    }
    else
    {
        new_p = old_p.x()*n10+(old_p.y()/2)*n02;
    }
    //new_p.setX(2*old_p.x()+old_p.y());
    //new_p.setY(1*old_p.x()+2*old_p.y());
    return new_p;
}


inline uint qHash(const QPoint &key)
{
    QString str = QString("(%1,%2)").arg(key.x()).arg(key.y());
    QString hkey = QString(QCryptographicHash::hash(str.toStdString().c_str(),QCryptographicHash::Md5).toHex());
    return qHash(hkey);
}
void getCenter(const QList<EdgeModel> &all_edges, QList<QPointF> &all_points, QPointF &graph_center)
{
    graph_center.setX(0);
    graph_center.setY(0);
    all_points.clear();

    QSet<QPoint> points;
    for(int i=0; i<all_edges.size();++i)
    {
        points.insert(all_edges[i].startPoint());
        points.insert(all_edges[i].endPoint());
    }
    QPointF mp;
    QSetIterator<QPoint> it(points);
    while(it.hasNext())
    {
        QPointF ala = vertexXY2XY(it.next(), 2.0);
        mp += ala;
        all_points.append(ala);
    }
    mp /= static_cast<double>(points.size());

    graph_center = mp;
}


void getRingCenters(const QList<QList<EdgeModel> > &rings, QList<QPointF> &ring_centers)
{
    for(int i=0; i<rings.size();++i)
    {
        QPointF cm;
        QList<QPointF> points;
        getCenter(rings[i], points, cm);
        ring_centers.append(cm);
    }
}


class PointFSorter
{
public:
    bool operator()(const QPointF& p1, const QPointF& p2)
    {
        if (qFuzzyCompare(p1.x(), p2.x()))
        {
            return (p1.y() < p2.y());
        }
        else if (p1.x() < p2.x())
        {
            return true;
        }
        else if (p1.x() > p2.x())
        {
            return false;
        }
        else
        {
            return false;
        }
    }
};

bool compareQPointF(const QPointF& p1, const QPointF& p2)
{
    return (qFuzzyCompare(p1.x(), p2.x()) && qFuzzyCompare(p1.y(), p2.y()));
}

bool isIsomorphic(const QList<QPointF> &graph1, const QList<QPointF> &graph2)
{
    if (graph1.size() != graph2.size())
    {
        return false;
    }
    QList<QPointF> sorted_graph1 = graph1;
    QList<QPointF> sorted_graph2 = graph2;
    std::sort(sorted_graph1.begin(), sorted_graph1.end(), PointFSorter());
    std::sort(sorted_graph2.begin(), sorted_graph2.end(), PointFSorter());

    for(int i=0; i<sorted_graph1.size();++i)
    {
        if (!compareQPointF(sorted_graph1[i], sorted_graph2[i]))
        {
            return false;
        }
    }
    return true;
}

QString subscript2ch(const QString &input)
{
    QMap<QChar, QChar> subscriptMap;
    subscriptMap[QChar(0x2080)] = '0';
    subscriptMap[QChar(0x2081)] = '1';
    subscriptMap[QChar(0x2082)] = '2';
    subscriptMap[QChar(0x2083)] = '3';
    subscriptMap[QChar(0x2084)] = '4';
    subscriptMap[QChar(0x2085)] = '5';
    subscriptMap[QChar(0x2086)] = '6';
    subscriptMap[QChar(0x2087)] = '7';
    subscriptMap[QChar(0x2088)] = '8';
    subscriptMap[QChar(0x2089)] = '9';
    subscriptMap[QChar(0x209B)] = 's';
    subscriptMap[QChar(0x1D65)] = 'v';
    subscriptMap[QChar(0x2095)] = 'h';
    subscriptMap[QChar(0x0080)] = 'd';

    QString result;

    for (const QChar &ch : input) {
        if (ch != 'C' && subscriptMap.contains(ch)) {
            result += subscriptMap[ch];
        } else {
            result += ch;
        }
    }
    return result;
}


