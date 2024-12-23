#include "graphmodel.h"
#include <QHash>
#include <QQueue>
#include <QPolygon>
#include <QBitArray>
#include <QSet>
#include <QVector3D>
#include <array>
#include "utils.h"
#include <iostream>
using namespace std;

inline uint qHash(const QPoint &key)
{
    QString str = QString("(%1,%2)").arg(key.x()).arg(key.y());
    QString hkey = QString(QCryptographicHash::hash(str.toStdString().c_str(),QCryptographicHash::Md5).toHex());
    return qHash(hkey);
}

bool GraphModel::isDisconnected()
{
    return m_isDisconnected;
}

GraphModel::DecompositionType GraphModel::getType()
{
    return m_type;
}

int GraphModel::getDepth()
{
    return m_poly.degree();
    //    return m_depth;
}

const Polynomial<long long> &GraphModel::getPoly() const
{
    return m_poly;
}

void GraphModel::setPoly(const Polynomial<long long> &poly)
{
    m_poly = poly;
    emit PolynomialChanged(this);
}

QList<GraphModel *> GraphModel::getDaughters(EdgeModel edge)
{
    QList<GraphModel *> res;
    QHash<QPoint, int> m_count;
    m_count.clear();
    // qDebug() << m_edges.size();
    for(int i=0; i<m_edges.size();++i)
    {
        // qDebug() << m_edges[i].startPoint() << m_edges[i].endPoint();
        m_count[m_edges[i].startPoint()] += 1;
        m_count[m_edges[i].endPoint()] += 1;
    }
    if (!(m_count.value(edge.startPoint()) == 1 || m_count.value(edge.endPoint())==1))
    {
        // qDebug() << m_count.value(edge.startPoint()) << m_count.value(edge.endPoint());
        res.append(getNoBondDaughter(edge));
    }
    QList<QPoint> startneighbor,endneighbor,startneighbor2,endneighbor2;
    bool NoAtomsDaughterExist = true;
    bool startstar = true;
    bool endstar = true;
    for (int i=0; i<m_edges.size();i++)
    {
        if (m_edges[i].startPoint() == edge.startPoint() && m_edges[i].endPoint() != edge.endPoint())
        {
            startneighbor.append(m_edges[i].endPoint());
            for (int j=0; j<m_edges.size();j++)
            {
                if (j == i)
                {
                    continue;
                }
                else if (m_edges[i].endPoint() == m_edges[j].startPoint())
                {
                    startneighbor2.append(m_edges[j].endPoint());
                }
                else if (m_edges[i].endPoint() == m_edges[j].endPoint())
                {
                    startneighbor2.append(m_edges[j].startPoint());
                }
            }
        }
        else if (m_edges[i].endPoint() == edge.startPoint() && m_edges[i].startPoint() != edge.endPoint())
        {
            startneighbor.append(m_edges[i].startPoint());
            for (int j=0; j<m_edges.size();j++)
            {
                if (j == i)
                {
                    continue;
                }
                else if (m_edges[i].startPoint() == m_edges[j].startPoint())
                {
                    startneighbor2.append(m_edges[j].endPoint());
                }
                else if (m_edges[i].startPoint() == m_edges[j].endPoint())
                {
                    startneighbor2.append(m_edges[j].startPoint());
                }
            }
        }
        else if (m_edges[i].startPoint() == edge.endPoint() && m_edges[i].endPoint() != edge.startPoint())
        {
            endneighbor.append(m_edges[i].endPoint());
            for (int j=0; j<m_edges.size();j++)
            {
                if (j == i)
                {
                    continue;
                }
                else if (m_edges[i].endPoint() == m_edges[j].startPoint())
                {
                    endneighbor2.append(m_edges[j].endPoint());
                }
                else if (m_edges[i].endPoint() == m_edges[j].endPoint())
                {
                    endneighbor2.append(m_edges[j].startPoint());
                }
            }
        }
        else if (m_edges[i].endPoint() == edge.endPoint() && m_edges[i].startPoint() != edge.startPoint())
        {
            endneighbor.append(m_edges[i].startPoint());
            for (int j=0; j<m_edges.size();j++)
            {
                if (j == i)
                {
                    continue;
                }
                else if (m_edges[i].startPoint() == m_edges[j].startPoint())
                {
                    endneighbor2.append(m_edges[j].endPoint());
                }
                else if (m_edges[i].startPoint() == m_edges[j].endPoint())
                {
                    endneighbor2.append(m_edges[j].startPoint());
                }
            }
        }
    }

    for (int i=1; i<=startneighbor.size(); i++)
    {
        if (m_count.value(startneighbor[i]) == 1)
        {
            NoAtomsDaughterExist = false;
            endstar = false;
            break;
        }
    }
    for (int i=1; i<=endneighbor.size(); i++)
    {
        if (m_count.value(endneighbor[i]) == 1)
        {
            NoAtomsDaughterExist = false;
            startstar = false;
            break;
        }
    }
    if (startstar)
    {
        for (int i=1; i<=startneighbor2.size(); i++)
        {
            if (m_count.value(startneighbor2[i]) == 1)
            {
                startstar = false;
                break;
            }
        }
    }
    if (endstar)
    {
        for (int i=1; i<=endneighbor2.size(); i++)
        {
            if (m_count.value(endneighbor2[i]) == 1)
            {
                endstar = false;
                break;
            }
        }
    }
    if (NoAtomsDaughterExist)
    {
        res.append(getNoAtomsDaughter(edge));
    }
    res.append(getNoStarDaughter(edge,startstar,endstar));
    return res;
}

QList<GraphModel *> GraphModel::getDaughters2(EdgeModel edge)
{
    QList<GraphModel *> res;
    res.append(getNoBondDaughter(edge));
    res.append(getNoAtomsDaughter(edge));
    res.append(getNoRingDaughter(edge));
    //res.append(getNoBisringDaughter(edge));
    return res;
}

void GraphModel::selectBond(EdgeModel edge)
{
    m_isBondSelected = true;
    m_selectedBond = edge;
    emit SelectionChanged(this);    //emit a signal
//    emit BondSelected(this, edge);
}

void GraphModel::unselectBond()
{
//    emit BondUnselected(this, edge);
    bool oldse = m_isBondSelected;
    m_isBondSelected = false;
    if (oldse)
        emit SelectionChanged(this);
}

bool GraphModel::isBondSelected()
{
    return m_isBondSelected;
}

EdgeModel GraphModel::getSelectedBond()
{
    return m_selectedBond;
}

bool GraphModel::isDead()
{
    return m_isDead;
}

bool GraphModel::isEmpty()
{
    return (m_edges.isEmpty() && m_hidden_edges.isEmpty());
}

bool GraphModel::isFinished()
{
    return m_isFinished;
}

QList<EdgeModel> GraphModel::getAllEdges() const
{
    return m_edges + m_hidden_edges;
}

const QList<EdgeModel>& GraphModel::getEdges() const
{
    return m_edges;
}

const QList<EdgeModel> &GraphModel::getHiddenEdges()
{
    return m_hidden_edges;
}


GraphModel::GraphModel(const QList<EdgeModel> &edges, const QList<EdgeModel> &hiddenEdges, const GraphModel *modelParent,
                       GraphModel::DecompositionType type, QObject *parent):QObject(parent), m_neighborlist(edges, hiddenEdges)
{
    m_modelParent = modelParent;
    m_tag = "";
    m_customTag = "";
    m_edges = edges;
    m_hidden_edges = hiddenEdges;
    m_isFinished = (edges.isEmpty() && !hiddenEdges.isEmpty());
    m_isDisconnected = false;
    m_isBondSelected = false;
    m_isDead = false;

    m_poly.addTerm(1,0);

    if ( modelParent != NULL)
    {
        m_doublebonds += modelParent->m_doublebonds;
        m_stars += modelParent->m_stars;
        m_rings += modelParent->m_rings;
        m_poly = modelParent->m_poly;
    }
    m_type = type;
    if (m_type == Star)
    {
        m_poly.multiplyTerm(1,1);
    }
    if (m_type == Ring)
    {
        m_poly.multiplyTerm(1,1);
    }

    if (m_neighborlist.numOfAtoms() % 2 == 1)
        m_isDead = true;


}

void GraphModel::cutDanglingBonds()
{
    bool cutAny = false;
    QHash<QPoint, int> count;
    for(int i=0; i<m_edges.size();++i)
    {
        count[m_edges[i].startPoint()] += 1;
        count[m_edges[i].endPoint()] += 1;
    }
    QHashIterator<QPoint, int> it(count);
    QList<QPoint> alone_atoms;
    QList<EdgeModel> alone_bonds;
    QSet<QPoint> alone_starcenters;
    QList<QList<EdgeModel> > alone_stars;
    QSet<QPoint> alone_starpoints;
    while(it.hasNext())
    {
        it.next();
        // qDebug() << it.value();
        if (it.value() == 1)
        {
            for(int i=0; i<m_edges.size();++i)
            {
                if (it.key() == m_edges[i].startPoint())
                {
                    if(count.value(m_edges[i].endPoint())==1 || count.value(m_edges[i].endPoint())==2)
                    {
                        alone_atoms.append(it.key());
                        break;
                    }
                    else if (count.value(m_edges[i].endPoint())==3)
                    {
                        alone_starcenters.insert(m_edges[i].endPoint());
                    }
                }
                if (it.key() == m_edges[i].endPoint())
                {
                    if(count.value(m_edges[i].startPoint())==1 || count.value(m_edges[i].startPoint())==2)
                    {
                        alone_atoms.append(it.key());
                        break;
                    }
                    else if (count.value(m_edges[i].startPoint())==3)
                    {
                        alone_starcenters.insert(m_edges[i].startPoint());
                    }
                }
            }
        }
    }
    if (alone_atoms.size() > 0 )
    {
        for(int i=0; i<m_edges.size();++i)
        {
            for(int j=0; j<alone_atoms.size();++j)
            {
                if (m_edges[i].startPoint() == alone_atoms[j] ||
                       m_edges[i].endPoint() == alone_atoms[j] )
                {
                    alone_bonds.append(m_edges[i]);
                }
            }
        }

        for(int i=0; i<alone_bonds.size();++i)
        {
            if (m_neighborlist.isAtomAlive(alone_bonds[i].startPoint()) &&
                m_neighborlist.isAtomAlive(alone_bonds[i].endPoint()))
            {
                removeAtoms(alone_bonds[i],this->m_edges, this->m_hidden_edges);
                addDoubleBond(alone_bonds[i]);
                m_neighborlist.removeAtom(alone_bonds[i].startPoint());
                m_neighborlist.removeAtom(alone_bonds[i].endPoint());
                cutAny = true;
            }
        }
    }
    QList<QPoint> alone_starcentersList = alone_starcenters.toList();
    if (alone_starcentersList.size() > 0)
    {
        for(int i=0; i<alone_starcentersList.size();++i)
        {
            QList<EdgeModel> Starpath = getTerminalStarEdges(alone_starcentersList[i]);

            if (Starpath.size()>0)
            {
                addStar(Starpath);
                for(int j=0; j<Starpath.size();++j)
                {
                    removeAtoms(Starpath[j],this->m_edges, this->m_hidden_edges);
                    m_neighborlist.removeAtom(Starpath[j].startPoint());
                    m_neighborlist.removeAtom(Starpath[j].endPoint());
                }
                cutAny = true;
                m_poly.multiplyTerm(1,1);
		// I believe problem is here
            }
        }
    }
    if (cutAny)
    {
        cutDanglingBonds();
    }
}

GraphModel::~GraphModel()
{
//    qDebug() << "GraphModel::~GraphModel";
}
void GraphModel::cutDanglingBonds2()
{
    bool cutAny = false;
    QHash<QPoint, int> count;
    for(int i=0; i<m_edges.size();++i)
    {
        count[m_edges[i].startPoint()] += 1;
        count[m_edges[i].endPoint()] += 1;
    }
    QHashIterator<QPoint, int> it(count);   //it.key() == QPoint, it.value() == int
    QList<QPoint> alone_atoms;
    QList<EdgeModel> alone_bonds;
    while(it.hasNext())
    {
        it.next();
        if (it.value() == 1)    //maybe it.value is # of neighbors
        {
            alone_atoms.append(it.key());
        }

    }
    if (alone_atoms.size() > 0 )
    {
        for(int i=0; i<m_edges.size();++i)
        {
            for(int j=0; j<alone_atoms.size();++j)
            {
                if (m_edges[i].startPoint() == alone_atoms[j] ||
                       m_edges[i].endPoint() == alone_atoms[j] )
                {
                    alone_bonds.append(m_edges[i]);
                }
            }
        }

        for(int i=0; i<alone_bonds.size();++i)
        {
            if (m_neighborlist.isAtomAlive(alone_bonds[i].startPoint()) &&
                m_neighborlist.isAtomAlive(alone_bonds[i].endPoint()))
            {
                removeAtoms(alone_bonds[i],this->m_edges, this->m_hidden_edges);
                addDoubleBond(alone_bonds[i]);
                m_neighborlist.removeAtom(alone_bonds[i].startPoint());
                m_neighborlist.removeAtom(alone_bonds[i].endPoint());
                cutAny = true;
            }
        }
    }
    if (cutAny)
    {
        cutDanglingBonds2();
    }
}


void GraphModel::removeAtoms(const EdgeModel& edge, QList<EdgeModel> &alive_edges, QList<EdgeModel> &dead_edges)
{
    QList<EdgeModel> new_model;
    for(int i=0; i<alive_edges.size(); ++i)
    {
        if ( alive_edges[i].startPoint() == edge.startPoint() || alive_edges[i].startPoint() == edge.endPoint())
        {
            if (!dead_edges.contains(alive_edges[i]))
                dead_edges.append(alive_edges[i]);
            continue;
        }
        else if ( alive_edges[i].endPoint() == edge.startPoint() || alive_edges[i].endPoint() == edge.endPoint())
        {
            if (!dead_edges.contains(alive_edges[i]))
                dead_edges.append(alive_edges[i]);
            continue;
        }
        else
        {
            new_model.append(alive_edges[i]);
        }
    }
    alive_edges = new_model;
}
QList<GraphModel*> GraphModel::split(const QVector<QList<EdgeModel> >& parts)
{
    QList<GraphModel*> res;
    if (parts.size() > 1)
    {
        m_isDisconnected = true;
        for(int i=0; i<parts.size();++i)
        {
            QList<EdgeModel> remained_edges = m_hidden_edges;
            for(int j=0; j<m_edges.size();++j)
            {
                if (!parts[i].contains(m_edges[j]))
                {
                    remained_edges.append(m_edges[j]);
                }
            }
            GraphModel* newModel = new GraphModel(parts[i], remained_edges, this, GraphModel::Fragment, 0);
            QSet<QPoint> atomPos;
            for(int j=0; j< newModel->getEdges().size();++j)
            {
                EdgeModel edge = newModel->getEdges().at(j);
                atomPos.insert(edge.startPoint());
                atomPos.insert(edge.endPoint());
            }
            if (atomPos.size() % 2 != 0)
            {
                newModel->setDead(true);
            }
            res.append(newModel);
        }
    }
    return res;
}
QVector<QList<EdgeModel> > GraphModel::checkIfDisconnected(QList<EdgeModel> edges)
{
    QVector<QList<EdgeModel> > res;
    if (edges.size() == 0)
    {
        res.append(edges);
        return res;
    }

    QList<EdgeModel> part1;
    QList<EdgeModel> part2;
    QVector<QList<int> > neighborlist(edges.size());

    for(int i=0; i<edges.size();++i)
    {
        for(int j=0; j<i; ++j)
        {
            if (edges[i].connected(edges[j]))
            {
                neighborlist[i].append(j);
                neighborlist[j].append(i);
            }
        }
    }
    QBitArray visited(edges.size());
    QQueue<int> queue;
    queue.append(0);
    while(!queue.isEmpty())
    {
        int cur = queue.first();
        queue.pop_front();
        if ( visited[cur] == true)
        {
            continue;
        }
        visited.setBit(cur,true);
        QListIterator<int> it(neighborlist[cur]);
        while(it.hasNext())
        {
            queue.append(it.next());
        }
    }
    if (visited.count(false) > 0)
    {
        for(int i=0; i<visited.size();++i)
        {
            if (visited[i])
            {
                part1.append(edges[i]);
            }
            else
            {
                part2.append(edges[i]);
            }
        }
        res.append(part1);
        res += checkIfDisconnected(part2);
    }
    else
    {
        res.append(edges);
    }
    return res;
}
void GraphModel::addDoubleBond(const EdgeModel &line)
{
    m_doublebonds.append(line);
}
GraphModel *GraphModel::getNoBondDaughter(EdgeModel edge)
{
    QList<EdgeModel> model = this->m_edges;
    QList<EdgeModel> hidden = this->m_hidden_edges;
    int index = model.indexOf(edge);
    if (index != -1)
    {
        hidden.append(model[index]);
        model.removeAt(index);
    }
    return new GraphModel(model, hidden, this, GraphModel::Single, 0);
}

GraphModel *GraphModel::getNoAtomsDaughter(EdgeModel edge)
{
    QList<EdgeModel> all_edges = this->m_edges;
    QList<EdgeModel> hidden_edges = this->m_hidden_edges;
    removeAtoms(edge, all_edges, hidden_edges);
    GraphModel* gm_child = new GraphModel(all_edges, hidden_edges, this, GraphModel::Double, 0);
    gm_child->addDoubleBond(edge);
    return gm_child;
}

QList<GraphModel *> GraphModel::getNoRingDaughter(EdgeModel edge)
{
    QList<GraphModel*> rings;
    QList<QList<EdgeModel> > pathes = getRingEdges(edge);

    for(int i=0; i<pathes.size();++i)
    {
        QList<EdgeModel> all_edges = this->m_edges;
        QList<EdgeModel> removed_edges = this->m_hidden_edges;
        for(int j=0; j<pathes[i].size();++j)
        {
            removeAtoms(pathes[i][j],all_edges,removed_edges);
        }
        GraphModel* gm_child = new GraphModel(all_edges,removed_edges,this,GraphModel::Ring, 0);
        gm_child->addRing(pathes[i]);
        rings.append(gm_child);
    }
    return rings;
}
QList<QList<EdgeModel> > GraphModel::getRingEdges(EdgeModel edge)
{
    QList<QList<EdgeModel> > res;
    QSet<EdgeModel> all_edges;
    bool findneighbor = false;
    bool findneighbor2 = false;
    QPoint atom1,atom2,atom3,atom4,atom5,atom6;
    atom1 = edge.startPoint();
    atom2 = edge.endPoint();
    for(int i=0; i<m_edges.size();++i)
    {
        all_edges.insert(m_edges[i]);
    }
    QList<EdgeModel> tmpPath;
    EdgeModel edge2,edge3,edge4,edge5,edge6;
    for(int i=0; i<m_edges.size();++i)  // find edge2
    {
        if (m_edges[i] == edge) {continue;}
        if(edge.startPoint() == m_edges[i].startPoint())
        {
            edge2 = m_edges[i];
            atom3 = edge2.endPoint();
            findneighbor = true;
        }
        else if (edge.startPoint() == m_edges[i].endPoint())
        {
            edge2 = m_edges[i];
            atom3 = edge2.startPoint();
            findneighbor = true;
        }
        if (findneighbor)
        {
            findneighbor = false;
            for(int j=0; j<m_edges.size();++j)  // find edge3
            {
                if(m_edges[j] == edge || m_edges[j] == edge2) {continue;}
                if(m_edges[j].connected(edge2))
                {
                    edge3 = m_edges[j];
                    if (edge3.connected(edge)){continue;}

                    if (edge3.startPoint() == atom3){atom4 =edge3.endPoint();}
                    else {atom4 =edge3.startPoint();}

                    for(int k=0; k<m_edges.size();++k)  // find edge4
                    {
                        if (m_edges[k] == edge) {continue;}
                        if(edge.endPoint() == m_edges[k].startPoint())
                        {
                            edge4 = m_edges[k];
                            atom5 = edge4.endPoint();
                            findneighbor2 = true;
                        }
                        else if (edge.endPoint() == m_edges[k].endPoint())
                        {
                            edge4 = m_edges[k];
                            atom5 = edge4.startPoint();
                            findneighbor2 = true;
                        }

                        if (findneighbor2)
                        {
                            findneighbor2 = false;
                            for(int m=0; m<m_edges.size();++m)  // find edge5
                            {
                                if(m_edges[m] == edge || m_edges[m] == edge4) {continue;}
                                if(m_edges[m].connected(edge4))
                                {
                                    edge5 = m_edges[m];
                                    if (edge5.connected(edge)){continue;}
                                    if (edge5.startPoint() == atom5){atom6 = edge5.endPoint();}
                                    else {atom6 =edge5.startPoint();}
                                    // if (edge5.connected(edge)){continue;}
                                    // if (edge5.connected(edge3)){break;}
                                    for(int l=0; l<m_edges.size();++l)
                                    {
                                        if (m_edges[l] == edge4 || m_edges[l] == edge5) {continue;}
                                        if (m_edges[l].connected(edge3) && m_edges[l].connected(edge4)) {continue;}

                                        if (m_edges[l].connected(edge3) && m_edges[l].connected(edge5))
                                        {
                                            edge6 = m_edges[l];
                                            if (!(edge6.startPoint() == atom4 && edge6.endPoint() == atom6) && !(edge6.startPoint() == atom6 && edge6.endPoint() == atom4)) {continue;}
                                            // if (edge.connected(edge2) && edge.connected(edge4) && edge2.connected(edge3) && edge4.connected(edge5))
                                            // {
                                                tmpPath.clear();
                                                tmpPath << edge << edge2 << edge3 << edge4 << edge5 << edge6;
                                                res.append(tmpPath);
                                            // }
                                        }
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    return res;
}

void GraphModel::addRing(const QList<EdgeModel>& bonds)
{
    if ( bonds.size() != 6 )
        return ;
    m_rings.append(bonds);
}

QList<GraphModel *> GraphModel::getNoStarDaughter(EdgeModel edge, bool startstar, bool endstar)
{
    QList<GraphModel*> stars;
    QList<QList<EdgeModel> > pathes = getStarEdges(edge, startstar, endstar);
    for(int i=0; i<pathes.size();++i)
    {
        QList<EdgeModel> all_edges = this->m_edges;
        QList<EdgeModel> removed_edges = this->m_hidden_edges;
        for(int j=0; j<pathes[i].size();++j)
        {   
            removeAtoms(pathes[i][j],all_edges,removed_edges);
        }
        GraphModel* gm_child = new GraphModel(all_edges,removed_edges,this,GraphModel::Star, 0);
        gm_child->addStar(pathes[i]);
        stars.append(gm_child);
    }
    return stars;
}

QList<QList<EdgeModel> > GraphModel::getStarEdges(EdgeModel edge, bool startstar, bool endstar)
{
    QList<QList<EdgeModel> > res;
    QList<EdgeModel> tmpPath;

    int find;
    if (startstar)
    {    
        tmpPath.clear();
        find = 0;
        for(int i=0; i<m_edges.size();++i)
        {   
            if (m_edges[i].startPoint() == edge.startPoint() || m_edges[i].endPoint() == edge.startPoint())
            {
                tmpPath.append(m_edges[i]);
                find += 1;
            }
        }
        if (find == 3)
        {
            if (tmpPath.contains(edge))
            {
                res.append(tmpPath);
            }
        }
    }
    if (endstar)
    {    
        tmpPath.clear();
        find = 0;
        for(int i=0; i<m_edges.size();++i)
        {   
            if (m_edges[i].startPoint() == edge.endPoint() || m_edges[i].endPoint() == edge.endPoint())
            {
                tmpPath.append(m_edges[i]);
                find += 1;
            }
        }
        if (find == 3)
        {
            if (tmpPath.contains(edge))
            {
                res.append(tmpPath);
            }
        }
    }
    if (res.size() > 2)
    {
        qDebug() << "Something is fucking wrong";
    }
    return res;
}
QList<EdgeModel> GraphModel::getTerminalStarEdges(QPoint TerminalStarCenter)
{
    QHash<QPoint, int> count;
    for(int i=0; i<m_edges.size();++i)
    {
        count[m_edges[i].startPoint()] += 1;
        count[m_edges[i].endPoint()] += 1;
    }

    QList<EdgeModel> res;
    QList<EdgeModel> tmpPath;
    int find = 0;
    tmpPath.clear();

    for(int i=0; i<m_edges.size();++i)
    {   
        if (m_edges[i].startPoint() == TerminalStarCenter)
        {
            tmpPath.append(m_edges[i]);
            // qDebug() << "m_count.value(m_edges[i].endPoint()) = " <<m_count.value(m_edges[i].endPoint());
            if (count.value(m_edges[i].endPoint()) == 1)
            {
                find += 1;
            }
        }
        else if (m_edges[i].endPoint() == TerminalStarCenter)
        {
            tmpPath.append(m_edges[i]);
            // qDebug() << "m_count.value(m_edges[i].startPoint()) = " <<m_count.value(m_edges[i].startPoint());
            if (count.value(m_edges[i].startPoint()) == 1)
            {
                find += 1;
            }
        }
    }
    // qDebug() << "find = " << find;
    if (find >= 2)
    {
        res = tmpPath;
    }

    return res;
}

void GraphModel::addStar(const QList<EdgeModel>& bonds)
{
    if ( bonds.size() != 3 )
        return ;
    m_stars.append(bonds);
}
const QList<EdgeModel> &GraphModel::getDoubleBonds() const
{
    return m_doublebonds;
}

const QList<QList<EdgeModel> > &GraphModel::getRings() const
{
    return m_rings;
}
const QList<QList<EdgeModel> > &GraphModel::getStars() const
{
    return m_stars;
}

QList<GraphModel *> GraphModel::getFragments()
{
    return split(m_parts);
}

bool GraphModel::hasCustomTag()
{
    return !m_customTag.isEmpty();
}

void GraphModel::setTag(const QString& tag)
{
    m_tag = tag;
}

void GraphModel::setCustomTag(const QString &tag)
{
    m_customTag = tag;
    emit TagChanged(this);
}

QString GraphModel::getTag()
{
    return m_tag;
}

QString GraphModel::getCustomTag()
{
    return m_customTag;
}

QString GraphModel::getFullTag()
{
    if (hasCustomTag())
    {
        return m_customTag;
    }
    else
    {
        return m_tag;
    }
}

const GraphModel * GraphModel::getModelParent()
{
    return m_modelParent;
}

const NeightborList &GraphModel::getNeighborList() const
{
    return m_neighborlist;
}

void GraphModel::clearLink()
{
    m_neighborlist.clearLink();
}

bool GraphModel::addLink(const QList<QPair<int, int> > &links)
{
    return m_neighborlist.addLink(links);
}

QString GraphModel::getZZInput2(bool connections, bool hydrogens) const
{
    QStringList input;

    QPointF cm(0.0,0.0);

    QVector<QPointF> final_points(this->m_neighborlist.numOfAtoms());
    QMap<int, int> final_mapping;
    QHashIterator<QPoint, int> it(this->m_neighborlist.mapping());  // QHash<QPoint, int> it
    QHash<QPoint, QPointF> l_hydrogens;

    int final_index = 0;

    const std::array<QPoint, 3> vectors_opbenz = {{{-1,0}, {0,-1}, {1,1}}};
    const std::array<QPoint, 3> vectors_benz = {{{0,1}, {1,0}, {-1,-1}}};
    while(it.hasNext())
    {
        it.next();
        if (!this->m_neighborlist.isAtomAlive(it.key()))    //.isAtomAlive() return bool
            continue;
        // qDebug() <<it.key() << it.value();
        int num_h = 0;
        for(int i=0; i<3; ++i)
        {
            bool benz = false;
            QPoint pot = it.key();
            QPoint vec;
            int to = pot.x() + pot.y();
            if (to % 3 == 1)
            {
                benz = true;
            }
            else if (to % 3 == 0)
            {
                return "";
            }

            if (benz)
                vec = vectors_benz[i];
            else
                vec= vectors_opbenz[i];
            pot += vec;
            if (!this->m_neighborlist.isAtomAlive(pot))
            {
                QPointF hydro_coord = vertexXY2XY(it.key(),1.4) + vertexXY2XY(vec, 1.0);
                l_hydrogens.insert(pot, hydro_coord);
                num_h ++;
            }
        }
        if (hydrogens && (num_h != (3- this->m_neighborlist.getNeighborCount(it.key()))))
        {
            return "";
        }


        QPointF p =  vertexXY2XY(it.key(),1.4);
        int index = it.value(); // QHash<QPoint, int>

        final_mapping[index] = final_index; // use in connection
        final_points[final_index] = p;  // use in hydrogens
        ++final_index;
        cm += p;

    }
    cm /= static_cast<double>(final_points.size());

    // creat xyzfile
    if (hydrogens)
    {
        input.append(QString("%1").arg(final_points.size() + l_hydrogens.size() ));
    }
    else
    {
        input.append(QString("%1").arg(final_points.size()));
        qDebug() << "test" << QString("%1").arg(final_points.size());
    }
    input.append("");

    QVectorIterator<QPointF> it3(final_points);
    while(it3.hasNext())
    {
        QPointF p = it3.next()-cm;
        input.append(QString("C %1 %2 0.000000").arg(p.x(),0,'f',6).arg(p.y(),0,'f',6));
    }
    if (hydrogens)
    {
        QHashIterator<QPoint, QPointF> hit(l_hydrogens);
        while(hit.hasNext())
        {
            hit.next();
            QPointF p = hit.value()-cm;
            input.append(QString("H %1 %2 0.000000").arg(p.x(),0,'f',6).arg(p.y(),0,'f',6));
        }
    }


    if (connections)    // creat bond list
    {
        QList<QPair<int, int> > conns = m_neighborlist.getAllConnections(); // get all bond(connection) QList<QPair<int, int>>
        input.append(QString::number(conns.size()));
        for(int i=0; i<conns.size();++i)
        {
            input.append(QString("%1 %2").arg(final_mapping[conns[i].first]+1)
                    .arg(final_mapping[conns[i].second]+1));
        }
    }
    return input.join("\n");
}

QString GraphModel::getZZInput(bool connections) const
{
    QStringList input;
    QHashIterator<QPoint, int> it(this->m_neighborlist.mapping());  // QHash<QPoint, int> it
    QMap<int, int> final_mapping;   // QMap<old, new>
    int index=1;
    QList<QVector3D> pos3d;

    while(it.hasNext())
    {
        it.next();
        // qDebug() <<it.key() << it.value();
        QVector3D new_p = vertexXY2XYZ(it.key());
        pos3d.append(new_p);

        final_mapping.insert(it.key().y(), index);
        index += 1;
        // qDebug() << new_p.x() <<new_p.y() << new_p.z();
    }
    input.append(QString::number(pos3d.size()));
    input.append(" ");

    for (int i=0;i<pos3d.size();i++)
    {
        QVector3D new_p = pos3d[i];
        input.append(QString("C %1 %2 %3").arg(new_p.x(),0,'f',6).arg(new_p.y(),0,'f',6).arg(new_p.z(),0,'f',6));
    }
    if (connections)
    {
        input.append(QString::number(m_edges.size()));
        int be,en;
        for(int i=0; i<m_edges.size();++i)
        {
            be = final_mapping.value(m_edges[i].startPoint().y());
            en = final_mapping.value(m_edges[i].endPoint().y());
            input.append(QString("%1 %2").arg(be).arg(en));
        }
    }
    // qDebug() <<input;
    return input.join("\n");
}

void GraphModel::setmode(int mode)
{
  m_mode = mode;
}


void GraphModel::setDead(bool isDead)
{
    if (m_isDead != isDead)
    {
        m_isDead = isDead;
        emit StateChanged(this);
    }
}

void GraphModel::prepare()
{
    cutDanglingBonds();
    if (m_neighborlist.numOfAtoms() == 0)
    {
        m_isFinished = true;
    }
    if (m_neighborlist.hasIsolatedAtom())
        m_isDead = true;

    if (!m_isDead || m_isFinished)
    {
        m_parts = checkIfDisconnected(m_edges);
        if (m_parts.size()> 1)
        {
            m_isDisconnected = true;
        }
    }
}

void GraphModel::prepare2()
{
    cutDanglingBonds2();
    if (m_neighborlist.numOfAtoms() == 0)
    {
        m_isFinished = true;
    }
    if (m_neighborlist.hasIsolatedAtom())
        m_isDead = true;

    if (!m_isDead || m_isFinished)
    {
        m_parts = checkIfDisconnected(m_edges);
        if (m_parts.size()> 1)
        {
            m_isDisconnected = true;
        }
    }
}

void GraphModel::setFilename(QString foldername, QString filename)
{
    m_foldername = foldername;
    m_filename = filename;
}

QString GraphModel::getfolderename()
{
    return m_foldername;
}

QString GraphModel::getfilename()
{
    return m_filename;
}




