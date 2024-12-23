#ifndef WIDTHDECOMPOSECOMMAND2_H
#define WIDTHDECOMPOSECOMMAND2_H

#include "icommand.h"

#include <QList>
#include <QModelIndex>

class IdentificationModelManager;
class IdentificationDecomposer2;
class GraphModel;
class UniqueTagGenerator;
class QStandardItem;
class WidthDecomposeCommand2 : public ICommand
{
public:
    WidthDecomposeCommand2(IdentificationDecomposer2* decomposer, IdentificationModelManager* manager, const UniqueTagGenerator *tagGenerator, QModelIndex index, const QList<GraphModel*>& list);
    void Execute();
    void UnExecute();
    ~WidthDecomposeCommand2();

private:
    IdentificationDecomposer2* m_decomposer;
    IdentificationModelManager* m_manager;
    QStandardItem* m_parent;
    QList<QStandardItem*> m_children;
    UniqueTagGenerator* m_tagGenerator;
    QModelIndex m_index;
    QList<GraphModel*> m_list;
};

#endif // WIDTHDECOMPOSECOMMAND2_H
