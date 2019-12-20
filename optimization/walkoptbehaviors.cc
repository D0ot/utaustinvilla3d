#include "walkoptbehaviors.h"

WalkOptBehaviors::WalkOptBehaviors(const std::string teamName, int uNum, const map<string, string> &namedParams_, const string &rsg_)
    : NaoBehavior(teamName, uNum, namedParams_, rsg_),
      targetPos(0, 0, 0)
{
    startTime = worldModel->getTime();
    //worldModel->useGroundTruthDataForLocalization();
}

void WalkOptBehaviors::beam(double &beamX, double &beamY, double &beamAngle)
{
    beamX = -HALF_FIELD_X + 3;
    beamY = 0;
    beamAngle = 0;
}

SkillType WalkOptBehaviors::selectSkill()
{
    if(worldModel->getPlayMode() == PM_PLAY_ON)
    {
        return goToTarget(targetPos);
    }
    return SKILL_STAND;
}
void WalkOptBehaviors::updateFitness()
{
    auto timeElapsed = worldModel->getTime() - startTime;

    if (timeElapsed < 10)
    {
        return;
    }

    if (lastOp)
    {
        auto dis = worldModel->getMyPositionGroundTruth() - targetPos;
        if (dis.dotProduct(dis) <= 10)
        {
            setMonMessage("(playMode BeforeKickOff)");
            startTime = worldModel->getTime();
        }
        lastOp = false;
    }
    else
    {
        setMonMessage("(playMode PlayOn)");
        startTime = worldModel->getTime();
        lastOp = true;
    }
}