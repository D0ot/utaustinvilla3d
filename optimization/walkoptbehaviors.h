#ifndef _WALKOPTBEHAVIORS_H
#define _WALKOPTBEHAVIORS_H

#include "../behaviors/naobehavior.h"
#include <optimizer/optimizer.h>

// agent string in cmd line is "walkOptAgent"
class WalkOptBehaviors : public NaoBehavior
{
  private:
    // what to add
    double startTime;
    bool beamed;


    // true for set PLAY_ON
    // false for set BEFORE_KICK_OFF
    bool lastOp;
    VecPosition targetPos;
    Optimizer optimizer;

  public:
    WalkOptBehaviors(const std::string teamName, int uNum, const map<
                                  string, string>& namedParams_, const string& rsg_);
    
    virtual void beam( double& beamX, double& beamY, double& beamAngle);
    virtual SkillType selectSkill();
    virtual void updateFitness();
                    
};



#endif