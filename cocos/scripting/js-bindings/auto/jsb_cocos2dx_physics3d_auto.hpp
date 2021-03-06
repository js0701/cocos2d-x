#include "base/ccConfig.h"
#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
#ifndef __cocos2dx_physics3d_h__
#define __cocos2dx_physics3d_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_cocos2d_Physics3DShape_class;
extern JSObject *jsb_cocos2d_Physics3DShape_prototype;

bool js_cocos2dx_physics3d_Physics3DShape_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DShape_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DShape(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DShape_getbtShape(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DShape_getShapeType(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DShape_createBox(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DShape_createCylinder(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DShape_createConvexHull(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DShape_createCapsule(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DShape_createSphere(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DObject_class;
extern JSObject *jsb_cocos2d_Physics3DObject_prototype;

bool js_cocos2dx_physics3d_Physics3DObject_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DObject_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DObject(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DObject_setUserData(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_getUserData(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_getObjType(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_setPhysicsWorld(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_getWorldTransform(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_getPhysicsWorld(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_setMask(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_getCollisionCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_getMask(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DObject_needCollisionCallback(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DRigidBody_class;
extern JSObject *jsb_cocos2d_Physics3DRigidBody_prototype;

bool js_cocos2dx_physics3d_Physics3DRigidBody_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DRigidBody_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DRigidBody(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setGravity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getFriction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setAngularFactor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_addConstraint(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getRigidBody(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getTotalForce(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getConstraintCount(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralForce(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setMassProps(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setFriction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setKinematic(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setDamping(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_applyImpulse(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_isKinematic(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_applyTorque(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setCcdMotionThreshold(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setRollingFriction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getCcdMotionThreshold(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getLinearFactor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_applyDamping(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getAngularVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_applyTorqueImpulse(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setActive(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setLinearFactor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setLinearVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getLinearVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setCcdSweptSphereRadius(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_applyForce(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setAngularVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralImpulse(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getGravity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getRollingFriction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setCenterOfMassTransform(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setInvInertiaDiagLocal(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_removeConstraint(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getTotalTorque(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getInvMass(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getConstraint(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getRestitution(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getCcdSweptSphereRadius(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getHitFraction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getAngularDamping(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getInvInertiaDiagLocal(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getCenterOfMassTransform(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getAngularFactor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setRestitution(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_setHitFraction(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_getLinearDamping(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DRigidBody_Physics3DRigidBody(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DComponent_class;
extern JSObject *jsb_cocos2d_Physics3DComponent_prototype;

bool js_cocos2dx_physics3d_Physics3DComponent_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DComponent_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DComponent(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DComponent_syncNodeToPhysics(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_addToPhysicsWorld(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_syncPhysicsToNode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DObject(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_setPhysics3DObject(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_setSyncFlag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_setTransformInPhysics(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DComponentName(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DComponent_Physics3DComponent(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_PhysicsSprite3D_class;
extern JSObject *jsb_cocos2d_PhysicsSprite3D_prototype;

bool js_cocos2dx_physics3d_PhysicsSprite3D_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_PhysicsSprite3D_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_PhysicsSprite3D(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_PhysicsSprite3D_syncNodeToPhysics(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_PhysicsSprite3D_syncPhysicsToNode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_PhysicsSprite3D_getPhysicsObj(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_PhysicsSprite3D_setSyncFlag(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_PhysicsSprite3D_PhysicsSprite3D(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DWorld_class;
extern JSObject *jsb_cocos2d_Physics3DWorld_prototype;

bool js_cocos2dx_physics3d_Physics3DWorld_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DWorld_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DWorld(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DWorld_setGravity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_stepSimulate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_needCollisionChecking(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_collisionChecking(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DObjects(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_isDebugDrawEnabled(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DConstraints(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_getGravity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DConstraint(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DObject(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_setDebugDrawEnable(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DObject(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_getPhysicsObject(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DConstraint(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_debugDraw(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_sweepShape(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DWorld_Physics3DWorld(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DConstraint_class;
extern JSObject *jsb_cocos2d_Physics3DConstraint_prototype;

bool js_cocos2dx_physics3d_Physics3DConstraint_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DConstraint_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DConstraint(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DConstraint_setEnabled(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_setBreakingImpulse(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_getUserData(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_getBreakingImpulse(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_getBodyA(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_isEnabled(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_getOverrideNumSolverIterations(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_getBodyB(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_setOverrideNumSolverIterations(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_getConstraintType(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_setUserData(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConstraint_getbtContraint(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DPointToPointConstraint_class;
extern JSObject *jsb_cocos2d_Physics3DPointToPointConstraint_prototype;

bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DPointToPointConstraint_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DPointToPointConstraint(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInA(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInB(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInA(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInB(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_Physics3DPointToPointConstraint(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DHingeConstraint_class;
extern JSObject *jsb_cocos2d_Physics3DHingeConstraint_prototype;

bool js_cocos2dx_physics3d_Physics3DHingeConstraint_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DHingeConstraint_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DHingeConstraint(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getHingeAngle(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getMotorTargetVelosity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetA(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetB(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setMaxMotorImpulse(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_enableAngularMotor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getUpperLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getMaxMotorImpulse(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getLowerLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setUseFrameOffset(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getEnableAngularMotor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_enableMotor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getBFrame(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setFrames(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getUseFrameOffset(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setAngularOnly(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setMotorTarget(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getAngularOnly(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setAxis(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getAFrame(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DHingeConstraint_Physics3DHingeConstraint(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DSliderConstraint_class;
extern JSObject *jsb_cocos2d_Physics3DSliderConstraint_prototype;

bool js_cocos2dx_physics3d_Physics3DSliderConstraint_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DSliderConstraint_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DSliderConstraint(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredAngMotor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getLinearPos(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetA(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetB(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredLinMotor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getAngularPos(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperLinLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperAngLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredAngMotor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerAngLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperAngLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetLinMotorVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseFrameOffset(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setUseFrameOffset(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerLinLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetLinMotorVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerLinLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredLinMotor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setFrames(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxAngMotorForce(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperLinLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxLinMotorForce(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetAngMotorVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerAngLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetAngMotorVelocity(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxLinMotorForce(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxAngMotorForce(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirLin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimAng(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseLinearReferenceFrameA(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DSliderConstraint_Physics3DSliderConstraint(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3DConeTwistConstraint_class;
extern JSObject *jsb_cocos2d_Physics3DConeTwistConstraint_prototype;

bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3DConeTwistConstraint_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3DConeTwistConstraint(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getBFrame(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFixThresh(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetB(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetA(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFixThresh(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan2(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan1(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulse(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFrames(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistAngle(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_GetPointForAngle(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulseNormalized(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistSpan(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setDamping(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getAFrame(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_enableMotor(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_Physics3DConeTwistConstraint(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_cocos2d_Physics3D6DofConstraint_class;
extern JSObject *jsb_cocos2d_Physics3D6DofConstraint_prototype;

bool js_cocos2dx_physics3d_Physics3D6DofConstraint_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_physics3d_Physics3D6DofConstraint_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_physics3d_Physics3D6DofConstraint(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_physics3d(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearLowerLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearLowerLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularUpperLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getUseFrameOffset(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearUpperLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularLowerLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_isLimited(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setUseFrameOffset(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearUpperLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularLowerLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularUpperLimit(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_physics3d_Physics3D6DofConstraint_Physics3D6DofConstraint(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __cocos2dx_physics3d_h__
#endif //#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
