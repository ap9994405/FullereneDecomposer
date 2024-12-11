#ifndef UTILS_H
#define UTILS_H

#include <QPoint>
#include <cmath>
#include "edgemodel.h"

void readschlegel(QString foldername, QString filename);
void readxyz(QString foldername, QString filename);
void setgraphsize(double m_size = 1.0);
QPoint ringXY2vertexXY(QPoint old_p);

QPointF vertexXY2XY(QPoint old_p, double r = 1.0);
// QPoint reverse_vertexXY2XY(QPointF old_p, double r = 1.0);

QPoint XY2VertexXY(QPointF old_p, double r = 1.0);
QVector3D vertexXY2XYZ(QPoint old_p);

QPointF rotate(const QPointF& old_p, const QPointF &center, int fold);

void getCenter(const QList<EdgeModel>& all_edges, QList<QPointF> &all_points,
                QPointF& graph_center);

void getRingCenters(const QList<QList<EdgeModel> >& rings, QList<QPointF> &ring_centers);

bool compareQPointF(const QPointF& p1, const QPointF& p2);
bool isIsomorphic(const QList<QPointF> &graph1, const QList<QPointF> &graph2);
QString subscript2ch(const QString &input);
#endif // UTILS_H
