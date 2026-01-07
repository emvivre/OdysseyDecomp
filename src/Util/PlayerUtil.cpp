#include "Util/PlayerUtil.h"

#include "Library/LiveActor/ActorPoseUtil.h"
#include "Library/Player/PlayerUtil.h"
#include "Library/Math/MathUtil.h"

void rs::calcPlayerSideDir(sead::Vector3f* dir, const al::LiveActor* actor) {
    const al::LiveActor* player = al::getPlayerActor(actor, 0);
    al::calcSideDir(dir, player);
}

bool rs::isNearPlayerH(const al::LiveActor* actor, f32 threshold) {
    const al::LiveActor* player = al::getPlayerActor(actor, 0);
    sead::Vector3f diff = al::getTrans(player) - al::getTrans(actor);
    const sead::Vector3f& gravity = al::getGravity(actor);
    al::verticalizeVec(&diff, gravity, diff);
    return diff.length() < threshold;
}

const sead::Vector3f& rs::getPlayerPos(const al::LiveActor* actor) {
    const al::LiveActor* player = al::getPlayerActor(actor, 0);
    return al::getTrans(player);
}
