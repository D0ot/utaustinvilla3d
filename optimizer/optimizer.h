#ifndef _OPTIMIZER_H
#define _OPTIMIZER_H

#include <behaviors/naobehavior.h>
#include <utwalk/motion/WalkEngineParameters.h>

// wrapper for useful process in optimization
class Optimizer
{
private:
    NaoBehavior *m_behavior;

public:
    void setWalkParameters(WalkRequestBlock::ParamSet paramset, const WalkEngineParameters& params);
    void getWalkParameters(WalkRequestBlock::ParamSet paramset, WalkEngineParameters& params);
};

#endif