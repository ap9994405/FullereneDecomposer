#ifndef GRAPHDECOMPOSECOMMAND2_H
#define GRAPHDECOMPOSECOMMAND2_H

#include "icommand.h"

class Decomposer2;
class GraphModel;

class GraphDecomposeCommand2 : public ICommand
{
public:
    GraphDecomposeCommand2(Decomposer2* decomposer, GraphModel* model);
    virtual void Execute();
    virtual void UnExecute();
private:
    Decomposer2 *m_decomposer;
    GraphModel *m_model;

};

#endif // GRAPHDECOMPOSECOMMAND2_H
