#include <optimizer/optimizer.h>
#include <utwalk/motion/UTWalkEngine.h>
#include <utwalk/motion/MotionModule.h>



void Optimizer::setWalkParameters(WalkRequestBlock::ParamSet paramset, const WalkEngineParameters& params)
{
    UTWalkEngine& ut_walk_engine = m_behavior->core->motion_->ut_walk_engine_;

    // load the paramSets
    ut_walk_engine.paramSets[paramset] = params;
    
    // This 'if' is at performance considration
    if(paramset == ut_walk_engine.last_param_set_)
    {
        // force it to reload the params
        ut_walk_engine.last_param_set_ = WalkRequestBlock::ParamSet::PARAMS_NONE;
        ut_walk_engine.setWalkParameters(paramset);
    } else
    {
        ut_walk_engine.setWalkParameters(paramset);
    }
}

void Optimizer::getWalkParameters(WalkRequestBlock::ParamSet paramset, WalkEngineParameters& params)
{
    params = m_behavior->core->motion_->ut_walk_engine_.paramSets[paramset];
}
