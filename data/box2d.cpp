#include <Box2D.h>
#include "box2d.h"


//
// Begin class 'b2ContactRegister'
//
void* b2ContactRegister__Create(){
	return new b2ContactRegister;
}
void* b2ContactRegister__CreateArray(int n){
	return new b2ContactRegister[n];
}
void b2ContactRegister__Destroy(void* cls){
	delete (b2ContactRegister*)cls;
}
void b2ContactRegister__DestroyArray(void* arr){
	delete[] (b2ContactRegister*)arr;
}
unsigned int b2ContactRegister__Size(){
	return sizeof(b2ContactRegister);
}
unsigned char b2ContactRegister__Get_Primary(void* cls){
	return ((b2ContactRegister*)cls)->primary;
}
void b2ContactRegister__Set_Primary(void* cls, unsigned char v){
	((b2ContactRegister*)cls)->primary = ((unsigned char)v);
}

//
// Begin class 'b2DistanceOutput'
//
void* b2DistanceOutput__Create(){
	return new b2DistanceOutput;
}
void* b2DistanceOutput__CreateArray(int n){
	return new b2DistanceOutput[n];
}
void b2DistanceOutput__Destroy(void* cls){
	delete (b2DistanceOutput*)cls;
}
void b2DistanceOutput__DestroyArray(void* arr){
	delete[] (b2DistanceOutput*)arr;
}
unsigned int b2DistanceOutput__Size(){
	return sizeof(b2DistanceOutput);
}
void* b2DistanceOutput__Get_PointA(void* cls){
	return &((b2DistanceOutput*)cls)->pointA;
}
void b2DistanceOutput__Set_PointA(void* cls, void* v){
	((b2DistanceOutput*)cls)->pointA = *((b2Vec2*)v);
}
void* b2DistanceOutput__Get_PointB(void* cls){
	return &((b2DistanceOutput*)cls)->pointB;
}
void b2DistanceOutput__Set_PointB(void* cls, void* v){
	((b2DistanceOutput*)cls)->pointB = *((b2Vec2*)v);
}
float b2DistanceOutput__Get_Distance(void* cls){
	return ((b2DistanceOutput*)cls)->distance;
}
void b2DistanceOutput__Set_Distance(void* cls, float v){
	((b2DistanceOutput*)cls)->distance = ((float)v);
}
int b2DistanceOutput__Get_Iterations(void* cls){
	return ((b2DistanceOutput*)cls)->iterations;
}
void b2DistanceOutput__Set_Iterations(void* cls, int v){
	((b2DistanceOutput*)cls)->iterations = ((int)v);
}

//
// Begin class 'b2RayCastCallback'
//
void b2RayCastCallback__Destroy(void* cls){
	delete (b2RayCastCallback*)cls;
}
void b2RayCastCallback__DestroyArray(void* arr){
	delete[] (b2RayCastCallback*)arr;
}
unsigned int b2RayCastCallback__Size(){
	return sizeof(b2RayCastCallback);
}

//
// Begin class 'b2ContactListener'
//
void* b2ContactListener__Create(){
	return new b2ContactListener;
}
void* b2ContactListener__CreateArray(int n){
	return new b2ContactListener[n];
}
void b2ContactListener__Destroy(void* cls){
	delete (b2ContactListener*)cls;
}
void b2ContactListener__DestroyArray(void* arr){
	delete[] (b2ContactListener*)arr;
}
unsigned int b2ContactListener__Size(){
	return sizeof(b2ContactListener);
}
void b2ContactListener_EndContact(void* cls, void* a){
	((b2ContactListener*)cls)->EndContact(((b2Contact*)a));
}
void b2ContactListener_PreSolve(void* cls, void* a, void* b){
	((b2ContactListener*)cls)->PreSolve(((b2Contact*)a), ((b2Manifold*)b));
}
void b2ContactListener_BeginContact(void* cls, void* a){
	((b2ContactListener*)cls)->BeginContact(((b2Contact*)a));
}
void b2ContactListener_PostSolve(void* cls, void* a, void* b){
	((b2ContactListener*)cls)->PostSolve(((b2Contact*)a), ((b2ContactImpulse*)b));
}

//
// Begin class 'b2Version'
//
void* b2Version__Create(){
	return new b2Version;
}
void* b2Version__CreateArray(int n){
	return new b2Version[n];
}
void b2Version__Destroy(void* cls){
	delete (b2Version*)cls;
}
void b2Version__DestroyArray(void* arr){
	delete[] (b2Version*)arr;
}
unsigned int b2Version__Size(){
	return sizeof(b2Version);
}
int b2Version__Get_Major(void* cls){
	return ((b2Version*)cls)->major;
}
void b2Version__Set_Major(void* cls, int v){
	((b2Version*)cls)->major = ((int)v);
}
int b2Version__Get_Minor(void* cls){
	return ((b2Version*)cls)->minor;
}
void b2Version__Set_Minor(void* cls, int v){
	((b2Version*)cls)->minor = ((int)v);
}
int b2Version__Get_Revision(void* cls){
	return ((b2Version*)cls)->revision;
}
void b2Version__Set_Revision(void* cls, int v){
	((b2Version*)cls)->revision = ((int)v);
}

//
// Begin class 'b2TOIOutput'
//
void* b2TOIOutput__Create(){
	return new b2TOIOutput;
}
void* b2TOIOutput__CreateArray(int n){
	return new b2TOIOutput[n];
}
void b2TOIOutput__Destroy(void* cls){
	delete (b2TOIOutput*)cls;
}
void b2TOIOutput__DestroyArray(void* arr){
	delete[] (b2TOIOutput*)arr;
}
unsigned int b2TOIOutput__Size(){
	return sizeof(b2TOIOutput);
}
unsigned int b2TOIOutput__Get_State(void* cls){
	return ((b2TOIOutput*)cls)->state;
}
void b2TOIOutput__Set_State(void* cls, unsigned int v){
	((b2TOIOutput*)cls)->state = ((b2TOIOutput::State)v);
}
float b2TOIOutput__Get_T(void* cls){
	return ((b2TOIOutput*)cls)->t;
}
void b2TOIOutput__Set_T(void* cls, float v){
	((b2TOIOutput*)cls)->t = ((float)v);
}

//
// Begin class 'b2TOIInput'
//
void* b2TOIInput__Create(){
	return new b2TOIInput;
}
void* b2TOIInput__CreateArray(int n){
	return new b2TOIInput[n];
}
void b2TOIInput__Destroy(void* cls){
	delete (b2TOIInput*)cls;
}
void b2TOIInput__DestroyArray(void* arr){
	delete[] (b2TOIInput*)arr;
}
unsigned int b2TOIInput__Size(){
	return sizeof(b2TOIInput);
}
void* b2TOIInput__Get_ProxyA(void* cls){
	return &((b2TOIInput*)cls)->proxyA;
}
void b2TOIInput__Set_ProxyA(void* cls, void* v){
	((b2TOIInput*)cls)->proxyA = *((b2DistanceProxy*)v);
}
void* b2TOIInput__Get_ProxyB(void* cls){
	return &((b2TOIInput*)cls)->proxyB;
}
void b2TOIInput__Set_ProxyB(void* cls, void* v){
	((b2TOIInput*)cls)->proxyB = *((b2DistanceProxy*)v);
}
void* b2TOIInput__Get_SweepA(void* cls){
	return &((b2TOIInput*)cls)->sweepA;
}
void b2TOIInput__Set_SweepA(void* cls, void* v){
	((b2TOIInput*)cls)->sweepA = *((b2Sweep*)v);
}
void* b2TOIInput__Get_SweepB(void* cls){
	return &((b2TOIInput*)cls)->sweepB;
}
void b2TOIInput__Set_SweepB(void* cls, void* v){
	((b2TOIInput*)cls)->sweepB = *((b2Sweep*)v);
}
float b2TOIInput__Get_TMax(void* cls){
	return ((b2TOIInput*)cls)->tMax;
}
void b2TOIInput__Set_TMax(void* cls, float v){
	((b2TOIInput*)cls)->tMax = ((float)v);
}

//
// Begin class 'b2PulleyJoint'
//
void b2PulleyJoint__Destroy(void* cls){
	delete (b2PulleyJoint*)cls;
}
void b2PulleyJoint__DestroyArray(void* arr){
	delete[] (b2PulleyJoint*)arr;
}
unsigned int b2PulleyJoint__Size(){
	return sizeof(b2PulleyJoint);
}
void* b2PulleyJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2PulleyJoint*)cls)->GetAnchorA());
}
void* b2PulleyJoint_GetGroundAnchorB(void* cls){
	return new b2Vec2(((b2PulleyJoint*)cls)->GetGroundAnchorB());
}
float b2PulleyJoint_GetReactionTorque(void* cls, float a){
	return ((b2PulleyJoint*)cls)->GetReactionTorque(((float)a));
}
void* b2PulleyJoint_GetGroundAnchorA(void* cls){
	return new b2Vec2(((b2PulleyJoint*)cls)->GetGroundAnchorA());
}
void* b2PulleyJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2PulleyJoint*)cls)->GetAnchorB());
}
void* b2PulleyJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2PulleyJoint*)cls)->GetReactionForce(((float)a)));
}
float b2PulleyJoint_GetLength2(void* cls){
	return ((b2PulleyJoint*)cls)->GetLength2();
}
float b2PulleyJoint_GetLength1(void* cls){
	return ((b2PulleyJoint*)cls)->GetLength1();
}
float b2PulleyJoint_GetRatio(void* cls){
	return ((b2PulleyJoint*)cls)->GetRatio();
}

//
// Begin class 'b2QueryCallback'
//
void b2QueryCallback__Destroy(void* cls){
	delete (b2QueryCallback*)cls;
}
void b2QueryCallback__DestroyArray(void* arr){
	delete[] (b2QueryCallback*)arr;
}
unsigned int b2QueryCallback__Size(){
	return sizeof(b2QueryCallback);
}

//
// Begin class 'b2DistanceJointDef'
//
void* b2DistanceJointDef__Create(){
	return new b2DistanceJointDef();
}
void* b2DistanceJointDef__CreateArray(int n){
	return new b2DistanceJointDef[n];
}
void b2DistanceJointDef__Destroy(void* cls){
	delete (b2DistanceJointDef*)cls;
}
void b2DistanceJointDef__DestroyArray(void* arr){
	delete[] (b2DistanceJointDef*)arr;
}
unsigned int b2DistanceJointDef__Size(){
	return sizeof(b2DistanceJointDef);
}
void b2DistanceJointDef_Initialize(void* cls, void* a, void* b, void* c, void* d){
	((b2DistanceJointDef*)cls)->Initialize(((b2Body*)a), ((b2Body*)b), *((b2Vec2*)c), *((b2Vec2*)d));
}
void* b2DistanceJointDef__Get_LocalAnchorA(void* cls){
	return &((b2DistanceJointDef*)cls)->localAnchorA;
}
void b2DistanceJointDef__Set_LocalAnchorA(void* cls, void* v){
	((b2DistanceJointDef*)cls)->localAnchorA = *((b2Vec2*)v);
}
void* b2DistanceJointDef__Get_LocalAnchorB(void* cls){
	return &((b2DistanceJointDef*)cls)->localAnchorB;
}
void b2DistanceJointDef__Set_LocalAnchorB(void* cls, void* v){
	((b2DistanceJointDef*)cls)->localAnchorB = *((b2Vec2*)v);
}
float b2DistanceJointDef__Get_Length(void* cls){
	return ((b2DistanceJointDef*)cls)->length;
}
void b2DistanceJointDef__Set_Length(void* cls, float v){
	((b2DistanceJointDef*)cls)->length = ((float)v);
}
float b2DistanceJointDef__Get_FrequencyHz(void* cls){
	return ((b2DistanceJointDef*)cls)->frequencyHz;
}
void b2DistanceJointDef__Set_FrequencyHz(void* cls, float v){
	((b2DistanceJointDef*)cls)->frequencyHz = ((float)v);
}
float b2DistanceJointDef__Get_DampingRatio(void* cls){
	return ((b2DistanceJointDef*)cls)->dampingRatio;
}
void b2DistanceJointDef__Set_DampingRatio(void* cls, float v){
	((b2DistanceJointDef*)cls)->dampingRatio = ((float)v);
}

//
// Begin class 'b2FrictionJointDef'
//
void* b2FrictionJointDef__Create(){
	return new b2FrictionJointDef();
}
void* b2FrictionJointDef__CreateArray(int n){
	return new b2FrictionJointDef[n];
}
void b2FrictionJointDef__Destroy(void* cls){
	delete (b2FrictionJointDef*)cls;
}
void b2FrictionJointDef__DestroyArray(void* arr){
	delete[] (b2FrictionJointDef*)arr;
}
unsigned int b2FrictionJointDef__Size(){
	return sizeof(b2FrictionJointDef);
}
void b2FrictionJointDef_Initialize(void* cls, void* a, void* b, void* c){
	((b2FrictionJointDef*)cls)->Initialize(((b2Body*)a), ((b2Body*)b), *((b2Vec2*)c));
}
void* b2FrictionJointDef__Get_LocalAnchorA(void* cls){
	return &((b2FrictionJointDef*)cls)->localAnchorA;
}
void b2FrictionJointDef__Set_LocalAnchorA(void* cls, void* v){
	((b2FrictionJointDef*)cls)->localAnchorA = *((b2Vec2*)v);
}
void* b2FrictionJointDef__Get_LocalAnchorB(void* cls){
	return &((b2FrictionJointDef*)cls)->localAnchorB;
}
void b2FrictionJointDef__Set_LocalAnchorB(void* cls, void* v){
	((b2FrictionJointDef*)cls)->localAnchorB = *((b2Vec2*)v);
}
float b2FrictionJointDef__Get_MaxForce(void* cls){
	return ((b2FrictionJointDef*)cls)->maxForce;
}
void b2FrictionJointDef__Set_MaxForce(void* cls, float v){
	((b2FrictionJointDef*)cls)->maxForce = ((float)v);
}
float b2FrictionJointDef__Get_MaxTorque(void* cls){
	return ((b2FrictionJointDef*)cls)->maxTorque;
}
void b2FrictionJointDef__Set_MaxTorque(void* cls, float v){
	((b2FrictionJointDef*)cls)->maxTorque = ((float)v);
}

//
// Begin class 'b2RopeDef'
//
void* b2RopeDef__Create(){
	return new b2RopeDef();
}
void* b2RopeDef__CreateArray(int n){
	return new b2RopeDef[n];
}
void b2RopeDef__Destroy(void* cls){
	delete (b2RopeDef*)cls;
}
void b2RopeDef__DestroyArray(void* arr){
	delete[] (b2RopeDef*)arr;
}
unsigned int b2RopeDef__Size(){
	return sizeof(b2RopeDef);
}
void* b2RopeDef__Get_Vertices(void* cls){
	return ((b2RopeDef*)cls)->vertices;
}
void b2RopeDef__Set_Vertices(void* cls, void* v){
	((b2RopeDef*)cls)->vertices = ((b2Vec2*)v);
}
int b2RopeDef__Get_Count(void* cls){
	return ((b2RopeDef*)cls)->count;
}
void b2RopeDef__Set_Count(void* cls, int v){
	((b2RopeDef*)cls)->count = ((int)v);
}
void* b2RopeDef__Get_Gravity(void* cls){
	return &((b2RopeDef*)cls)->gravity;
}
void b2RopeDef__Set_Gravity(void* cls, void* v){
	((b2RopeDef*)cls)->gravity = *((b2Vec2*)v);
}
float b2RopeDef__Get_Damping(void* cls){
	return ((b2RopeDef*)cls)->damping;
}
void b2RopeDef__Set_Damping(void* cls, float v){
	((b2RopeDef*)cls)->damping = ((float)v);
}
float b2RopeDef__Get_K2(void* cls){
	return ((b2RopeDef*)cls)->k2;
}
void b2RopeDef__Set_K2(void* cls, float v){
	((b2RopeDef*)cls)->k2 = ((float)v);
}
float b2RopeDef__Get_K3(void* cls){
	return ((b2RopeDef*)cls)->k3;
}
void b2RopeDef__Set_K3(void* cls, float v){
	((b2RopeDef*)cls)->k3 = ((float)v);
}

//
// Begin class 'b2MassData'
//
void* b2MassData__Create(){
	return new b2MassData;
}
void* b2MassData__CreateArray(int n){
	return new b2MassData[n];
}
void b2MassData__Destroy(void* cls){
	delete (b2MassData*)cls;
}
void b2MassData__DestroyArray(void* arr){
	delete[] (b2MassData*)arr;
}
unsigned int b2MassData__Size(){
	return sizeof(b2MassData);
}
float b2MassData__Get_Mass(void* cls){
	return ((b2MassData*)cls)->mass;
}
void b2MassData__Set_Mass(void* cls, float v){
	((b2MassData*)cls)->mass = ((float)v);
}
void* b2MassData__Get_Center(void* cls){
	return &((b2MassData*)cls)->center;
}
void b2MassData__Set_Center(void* cls, void* v){
	((b2MassData*)cls)->center = *((b2Vec2*)v);
}
float b2MassData__Get_I(void* cls){
	return ((b2MassData*)cls)->I;
}
void b2MassData__Set_I(void* cls, float v){
	((b2MassData*)cls)->I = ((float)v);
}

//
// Begin class 'b2WeldJoint'
//
void b2WeldJoint__Destroy(void* cls){
	delete (b2WeldJoint*)cls;
}
void b2WeldJoint__DestroyArray(void* arr){
	delete[] (b2WeldJoint*)arr;
}
unsigned int b2WeldJoint__Size(){
	return sizeof(b2WeldJoint);
}
void* b2WeldJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2WeldJoint*)cls)->GetAnchorA());
}
float b2WeldJoint_GetReactionTorque(void* cls, float a){
	return ((b2WeldJoint*)cls)->GetReactionTorque(((float)a));
}
void* b2WeldJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2WeldJoint*)cls)->GetAnchorB());
}
void* b2WeldJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2WeldJoint*)cls)->GetReactionForce(((float)a)));
}

//
// Begin class 'b2ContactFilter'
//
void* b2ContactFilter__Create(){
	return new b2ContactFilter;
}
void* b2ContactFilter__CreateArray(int n){
	return new b2ContactFilter[n];
}
void b2ContactFilter__Destroy(void* cls){
	delete (b2ContactFilter*)cls;
}
void b2ContactFilter__DestroyArray(void* arr){
	delete[] (b2ContactFilter*)arr;
}
unsigned int b2ContactFilter__Size(){
	return sizeof(b2ContactFilter);
}
unsigned char b2ContactFilter_ShouldCollide(void* cls, void* a, void* b){
	return ((b2ContactFilter*)cls)->ShouldCollide(((b2Fixture*)a), ((b2Fixture*)b));
}

//
// Begin class 'b2Body'
//
unsigned int b2Body__Size(){
	return sizeof(b2Body);
}
float b2Body_GetAngle(void* cls){
	return ((b2Body*)cls)->GetAngle();
}
void* b2Body_GetUserData(void* cls){
	return ((b2Body*)cls)->GetUserData();
}
unsigned char b2Body_IsSleepingAllowed(void* cls){
	return ((b2Body*)cls)->IsSleepingAllowed();
}
void b2Body_SetAngularDamping(void* cls, float a){
	((b2Body*)cls)->SetAngularDamping(((float)a));
}
void b2Body_SetActive(void* cls, unsigned char a){
	((b2Body*)cls)->SetActive(((unsigned char)a));
}
void b2Body_SetGravityScale(void* cls, float a){
	((b2Body*)cls)->SetGravityScale(((float)a));
}
void b2Body_SetUserData(void* cls, void* a){
	((b2Body*)cls)->SetUserData(((void*)a));
}
float b2Body_GetAngularVelocity(void* cls){
	return ((b2Body*)cls)->GetAngularVelocity();
}
void* b2Body_GetFixtureList0(void* cls){
	return ((b2Body*)cls)->GetFixtureList();
}
void* b2Body_GetFixtureList1(void* cls){
	return const_cast<b2Fixture*>(((b2Body*)cls)->GetFixtureList());
}
void b2Body_ApplyForce(void* cls, void* a, void* b){
	((b2Body*)cls)->ApplyForce(*((b2Vec2*)a), *((b2Vec2*)b));
}
void* b2Body_GetLocalPoint(void* cls, void* a){
	return new b2Vec2(((b2Body*)cls)->GetLocalPoint(*((b2Vec2*)a)));
}
void b2Body_SetLinearVelocity(void* cls, void* a){
	((b2Body*)cls)->SetLinearVelocity(*((b2Vec2*)a));
}
void* b2Body_GetJointList0(void* cls){
	return ((b2Body*)cls)->GetJointList();
}
void* b2Body_GetJointList1(void* cls){
	return const_cast<b2JointEdge*>(((b2Body*)cls)->GetJointList());
}
void* b2Body_GetLinearVelocity(void* cls){
	return new b2Vec2(((b2Body*)cls)->GetLinearVelocity());
}
void* b2Body_GetNext0(void* cls){
	return ((b2Body*)cls)->GetNext();
}
void* b2Body_GetNext1(void* cls){
	return const_cast<b2Body*>(((b2Body*)cls)->GetNext());
}
void b2Body_SetSleepingAllowed(void* cls, unsigned char a){
	((b2Body*)cls)->SetSleepingAllowed(((unsigned char)a));
}
void b2Body_SetTransform(void* cls, void* a, float b){
	((b2Body*)cls)->SetTransform(*((b2Vec2*)a), ((float)b));
}
float b2Body_GetMass(void* cls){
	return ((b2Body*)cls)->GetMass();
}
void b2Body_SetAngularVelocity(void* cls, float a){
	((b2Body*)cls)->SetAngularVelocity(((float)a));
}
void b2Body_GetMassData(void* cls, void* a){
	((b2Body*)cls)->GetMassData(((b2MassData*)a));
}
void* b2Body_GetLinearVelocityFromWorldPoint(void* cls, void* a){
	return new b2Vec2(((b2Body*)cls)->GetLinearVelocityFromWorldPoint(*((b2Vec2*)a)));
}
void b2Body_ResetMassData(void* cls){
	((b2Body*)cls)->ResetMassData();
}
void b2Body_ApplyForceToCenter(void* cls, void* a){
	((b2Body*)cls)->ApplyForceToCenter(*((b2Vec2*)a));
}
void b2Body_ApplyTorque(void* cls, float a){
	((b2Body*)cls)->ApplyTorque(((float)a));
}
unsigned char b2Body_IsAwake(void* cls){
	return ((b2Body*)cls)->IsAwake();
}
void b2Body_SetType(void* cls, unsigned int a){
	((b2Body*)cls)->SetType(((b2BodyType)a));
}
void* b2Body_CreateFixture0(void* cls, void* a){
	return ((b2Body*)cls)->CreateFixture(((b2FixtureDef*)a));
}
void* b2Body_CreateFixture1(void* cls, void* a, float b){
	return ((b2Body*)cls)->CreateFixture(((b2Shape*)a), ((float)b));
}
void b2Body_SetMassData(void* cls, void* a){
	((b2Body*)cls)->SetMassData(((b2MassData*)a));
}
void* b2Body_GetTransform(void* cls){
	return const_cast<b2Transform*>(&((b2Body*)cls)->GetTransform());
}
void* b2Body_GetWorldCenter(void* cls){
	return const_cast<b2Vec2*>(&((b2Body*)cls)->GetWorldCenter());
}
float b2Body_GetAngularDamping(void* cls){
	return ((b2Body*)cls)->GetAngularDamping();
}
void b2Body_ApplyLinearImpulse(void* cls, void* a, void* b){
	((b2Body*)cls)->ApplyLinearImpulse(*((b2Vec2*)a), *((b2Vec2*)b));
}
unsigned char b2Body_IsFixedRotation(void* cls){
	return ((b2Body*)cls)->IsFixedRotation();
}
void* b2Body_GetLocalCenter(void* cls){
	return const_cast<b2Vec2*>(&((b2Body*)cls)->GetLocalCenter());
}
void* b2Body_GetWorldVector(void* cls, void* a){
	return new b2Vec2(((b2Body*)cls)->GetWorldVector(*((b2Vec2*)a)));
}
void* b2Body_GetLinearVelocityFromLocalPoint(void* cls, void* a){
	return new b2Vec2(((b2Body*)cls)->GetLinearVelocityFromLocalPoint(*((b2Vec2*)a)));
}
void* b2Body_GetContactList0(void* cls){
	return ((b2Body*)cls)->GetContactList();
}
void* b2Body_GetContactList1(void* cls){
	return const_cast<b2ContactEdge*>(((b2Body*)cls)->GetContactList());
}
void* b2Body_GetWorldPoint(void* cls, void* a){
	return new b2Vec2(((b2Body*)cls)->GetWorldPoint(*((b2Vec2*)a)));
}
void b2Body_SetAwake(void* cls, unsigned char a){
	((b2Body*)cls)->SetAwake(((unsigned char)a));
}
float b2Body_GetLinearDamping(void* cls){
	return ((b2Body*)cls)->GetLinearDamping();
}
unsigned char b2Body_IsBullet(void* cls){
	return ((b2Body*)cls)->IsBullet();
}
void* b2Body_GetWorld0(void* cls){
	return ((b2Body*)cls)->GetWorld();
}
void* b2Body_GetWorld1(void* cls){
	return const_cast<b2World*>(((b2Body*)cls)->GetWorld());
}
void* b2Body_GetLocalVector(void* cls, void* a){
	return new b2Vec2(((b2Body*)cls)->GetLocalVector(*((b2Vec2*)a)));
}
void b2Body_SetLinearDamping(void* cls, float a){
	((b2Body*)cls)->SetLinearDamping(((float)a));
}
void b2Body_SetBullet(void* cls, unsigned char a){
	((b2Body*)cls)->SetBullet(((unsigned char)a));
}
unsigned int b2Body_GetType(void* cls){
	return ((b2Body*)cls)->GetType();
}
float b2Body_GetGravityScale(void* cls){
	return ((b2Body*)cls)->GetGravityScale();
}
void b2Body_DestroyFixture(void* cls, void* a){
	((b2Body*)cls)->DestroyFixture(((b2Fixture*)a));
}
float b2Body_GetInertia(void* cls){
	return ((b2Body*)cls)->GetInertia();
}
unsigned char b2Body_IsActive(void* cls){
	return ((b2Body*)cls)->IsActive();
}
void b2Body_SetFixedRotation(void* cls, unsigned char a){
	((b2Body*)cls)->SetFixedRotation(((unsigned char)a));
}
void b2Body_ApplyAngularImpulse(void* cls, float a){
	((b2Body*)cls)->ApplyAngularImpulse(((float)a));
}
void* b2Body_GetPosition(void* cls){
	return const_cast<b2Vec2*>(&((b2Body*)cls)->GetPosition());
}

//
// Begin class 'b2PrismaticJointDef'
//
void* b2PrismaticJointDef__Create(){
	return new b2PrismaticJointDef();
}
void* b2PrismaticJointDef__CreateArray(int n){
	return new b2PrismaticJointDef[n];
}
void b2PrismaticJointDef__Destroy(void* cls){
	delete (b2PrismaticJointDef*)cls;
}
void b2PrismaticJointDef__DestroyArray(void* arr){
	delete[] (b2PrismaticJointDef*)arr;
}
unsigned int b2PrismaticJointDef__Size(){
	return sizeof(b2PrismaticJointDef);
}
void b2PrismaticJointDef_Initialize(void* cls, void* a, void* b, void* c, void* d){
	((b2PrismaticJointDef*)cls)->Initialize(((b2Body*)a), ((b2Body*)b), *((b2Vec2*)c), *((b2Vec2*)d));
}
void* b2PrismaticJointDef__Get_LocalAnchorA(void* cls){
	return &((b2PrismaticJointDef*)cls)->localAnchorA;
}
void b2PrismaticJointDef__Set_LocalAnchorA(void* cls, void* v){
	((b2PrismaticJointDef*)cls)->localAnchorA = *((b2Vec2*)v);
}
void* b2PrismaticJointDef__Get_LocalAnchorB(void* cls){
	return &((b2PrismaticJointDef*)cls)->localAnchorB;
}
void b2PrismaticJointDef__Set_LocalAnchorB(void* cls, void* v){
	((b2PrismaticJointDef*)cls)->localAnchorB = *((b2Vec2*)v);
}
void* b2PrismaticJointDef__Get_LocalAxisA(void* cls){
	return &((b2PrismaticJointDef*)cls)->localAxisA;
}
void b2PrismaticJointDef__Set_LocalAxisA(void* cls, void* v){
	((b2PrismaticJointDef*)cls)->localAxisA = *((b2Vec2*)v);
}
float b2PrismaticJointDef__Get_ReferenceAngle(void* cls){
	return ((b2PrismaticJointDef*)cls)->referenceAngle;
}
void b2PrismaticJointDef__Set_ReferenceAngle(void* cls, float v){
	((b2PrismaticJointDef*)cls)->referenceAngle = ((float)v);
}
unsigned char b2PrismaticJointDef__Get_EnableLimit(void* cls){
	return ((b2PrismaticJointDef*)cls)->enableLimit;
}
void b2PrismaticJointDef__Set_EnableLimit(void* cls, unsigned char v){
	((b2PrismaticJointDef*)cls)->enableLimit = ((unsigned char)v);
}
float b2PrismaticJointDef__Get_LowerTranslation(void* cls){
	return ((b2PrismaticJointDef*)cls)->lowerTranslation;
}
void b2PrismaticJointDef__Set_LowerTranslation(void* cls, float v){
	((b2PrismaticJointDef*)cls)->lowerTranslation = ((float)v);
}
float b2PrismaticJointDef__Get_UpperTranslation(void* cls){
	return ((b2PrismaticJointDef*)cls)->upperTranslation;
}
void b2PrismaticJointDef__Set_UpperTranslation(void* cls, float v){
	((b2PrismaticJointDef*)cls)->upperTranslation = ((float)v);
}
unsigned char b2PrismaticJointDef__Get_EnableMotor(void* cls){
	return ((b2PrismaticJointDef*)cls)->enableMotor;
}
void b2PrismaticJointDef__Set_EnableMotor(void* cls, unsigned char v){
	((b2PrismaticJointDef*)cls)->enableMotor = ((unsigned char)v);
}
float b2PrismaticJointDef__Get_MaxMotorForce(void* cls){
	return ((b2PrismaticJointDef*)cls)->maxMotorForce;
}
void b2PrismaticJointDef__Set_MaxMotorForce(void* cls, float v){
	((b2PrismaticJointDef*)cls)->maxMotorForce = ((float)v);
}
float b2PrismaticJointDef__Get_MotorSpeed(void* cls){
	return ((b2PrismaticJointDef*)cls)->motorSpeed;
}
void b2PrismaticJointDef__Set_MotorSpeed(void* cls, float v){
	((b2PrismaticJointDef*)cls)->motorSpeed = ((float)v);
}

//
// Begin class 'b2RayCastOutput'
//
void* b2RayCastOutput__Create(){
	return new b2RayCastOutput;
}
void* b2RayCastOutput__CreateArray(int n){
	return new b2RayCastOutput[n];
}
void b2RayCastOutput__Destroy(void* cls){
	delete (b2RayCastOutput*)cls;
}
void b2RayCastOutput__DestroyArray(void* arr){
	delete[] (b2RayCastOutput*)arr;
}
unsigned int b2RayCastOutput__Size(){
	return sizeof(b2RayCastOutput);
}
void* b2RayCastOutput__Get_Normal(void* cls){
	return &((b2RayCastOutput*)cls)->normal;
}
void b2RayCastOutput__Set_Normal(void* cls, void* v){
	((b2RayCastOutput*)cls)->normal = *((b2Vec2*)v);
}
float b2RayCastOutput__Get_Fraction(void* cls){
	return ((b2RayCastOutput*)cls)->fraction;
}
void b2RayCastOutput__Set_Fraction(void* cls, float v){
	((b2RayCastOutput*)cls)->fraction = ((float)v);
}

//
// Begin class 'b2WheelJoint'
//
void b2WheelJoint__Destroy(void* cls){
	delete (b2WheelJoint*)cls;
}
void b2WheelJoint__DestroyArray(void* arr){
	delete[] (b2WheelJoint*)arr;
}
unsigned int b2WheelJoint__Size(){
	return sizeof(b2WheelJoint);
}
unsigned char b2WheelJoint_IsMotorEnabled(void* cls){
	return ((b2WheelJoint*)cls)->IsMotorEnabled();
}
float b2WheelJoint_GetMotorSpeed(void* cls){
	return ((b2WheelJoint*)cls)->GetMotorSpeed();
}
void* b2WheelJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2WheelJoint*)cls)->GetAnchorA());
}
float b2WheelJoint_GetReactionTorque(void* cls, float a){
	return ((b2WheelJoint*)cls)->GetReactionTorque(((float)a));
}
void b2WheelJoint_SetSpringDampingRatio(void* cls, float a){
	((b2WheelJoint*)cls)->SetSpringDampingRatio(((float)a));
}
float b2WheelJoint_GetSpringFrequencyHz(void* cls){
	return ((b2WheelJoint*)cls)->GetSpringFrequencyHz();
}
float b2WheelJoint_GetJointTranslation(void* cls){
	return ((b2WheelJoint*)cls)->GetJointTranslation();
}
float b2WheelJoint_GetSpringDampingRatio(void* cls){
	return ((b2WheelJoint*)cls)->GetSpringDampingRatio();
}
void b2WheelJoint_SetMaxMotorTorque(void* cls, float a){
	((b2WheelJoint*)cls)->SetMaxMotorTorque(((float)a));
}
void b2WheelJoint_SetSpringFrequencyHz(void* cls, float a){
	((b2WheelJoint*)cls)->SetSpringFrequencyHz(((float)a));
}
void b2WheelJoint_SetMotorSpeed(void* cls, float a){
	((b2WheelJoint*)cls)->SetMotorSpeed(((float)a));
}
void* b2WheelJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2WheelJoint*)cls)->GetAnchorB());
}
void* b2WheelJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2WheelJoint*)cls)->GetReactionForce(((float)a)));
}
float b2WheelJoint_GetMotorTorque(void* cls, float a){
	return ((b2WheelJoint*)cls)->GetMotorTorque(((float)a));
}
float b2WheelJoint_GetJointSpeed(void* cls){
	return ((b2WheelJoint*)cls)->GetJointSpeed();
}
float b2WheelJoint_GetMaxMotorTorque(void* cls){
	return ((b2WheelJoint*)cls)->GetMaxMotorTorque();
}
void b2WheelJoint_EnableMotor(void* cls, unsigned char a){
	((b2WheelJoint*)cls)->EnableMotor(((unsigned char)a));
}

//
// Begin class 'b2BlockAllocator'
//
void* b2BlockAllocator__Create(){
	return new b2BlockAllocator();
}
void* b2BlockAllocator__CreateArray(int n){
	return new b2BlockAllocator[n];
}
void b2BlockAllocator__Destroy(void* cls){
	delete (b2BlockAllocator*)cls;
}
void b2BlockAllocator__DestroyArray(void* arr){
	delete[] (b2BlockAllocator*)arr;
}
unsigned int b2BlockAllocator__Size(){
	return sizeof(b2BlockAllocator);
}
void b2BlockAllocator_Clear(void* cls){
	((b2BlockAllocator*)cls)->Clear();
}
void* b2BlockAllocator_Allocate(void* cls, int a){
	return ((b2BlockAllocator*)cls)->Allocate(((int)a));
}
void b2BlockAllocator_Free(void* cls, void* a, int b){
	((b2BlockAllocator*)cls)->Free(((void*)a), ((int)b));
}

//
// Begin class 'b2Vec3'
//
void* b2Vec3__Create0(){
	return new b2Vec3();
}
void* b2Vec3__Create1(float a, float b, float c){
	return new b2Vec3(((float)a), ((float)b), ((float)c));
}
void* b2Vec3__Create2(void* a){
	return new b2Vec3(*((b2Vec3*)a));
}
void* b2Vec3__CreateArray(int n){
	return new b2Vec3[n];
}
void b2Vec3__Destroy(void* cls){
	delete (b2Vec3*)cls;
}
void b2Vec3__DestroyArray(void* arr){
	delete[] (b2Vec3*)arr;
}
unsigned int b2Vec3__Size(){
	return sizeof(b2Vec3);
}
void b2Vec3_SetZero(void* cls){
	((b2Vec3*)cls)->SetZero();
}
void b2Vec3_Set(void* cls, float a, float b, float c){
	((b2Vec3*)cls)->Set(((float)a), ((float)b), ((float)c));
}
float b2Vec3__Get_X(void* cls){
	return ((b2Vec3*)cls)->x;
}
void b2Vec3__Set_X(void* cls, float v){
	((b2Vec3*)cls)->x = ((float)v);
}
float b2Vec3__Get_Y(void* cls){
	return ((b2Vec3*)cls)->y;
}
void b2Vec3__Set_Y(void* cls, float v){
	((b2Vec3*)cls)->y = ((float)v);
}
float b2Vec3__Get_Z(void* cls){
	return ((b2Vec3*)cls)->z;
}
void b2Vec3__Set_Z(void* cls, float v){
	((b2Vec3*)cls)->z = ((float)v);
}

//
// Begin class 'b2RevoluteJointDef'
//
void* b2RevoluteJointDef__Create(){
	return new b2RevoluteJointDef();
}
void* b2RevoluteJointDef__CreateArray(int n){
	return new b2RevoluteJointDef[n];
}
void b2RevoluteJointDef__Destroy(void* cls){
	delete (b2RevoluteJointDef*)cls;
}
void b2RevoluteJointDef__DestroyArray(void* arr){
	delete[] (b2RevoluteJointDef*)arr;
}
unsigned int b2RevoluteJointDef__Size(){
	return sizeof(b2RevoluteJointDef);
}
void b2RevoluteJointDef_Initialize(void* cls, void* a, void* b, void* c){
	((b2RevoluteJointDef*)cls)->Initialize(((b2Body*)a), ((b2Body*)b), *((b2Vec2*)c));
}
void* b2RevoluteJointDef__Get_LocalAnchorA(void* cls){
	return &((b2RevoluteJointDef*)cls)->localAnchorA;
}
void b2RevoluteJointDef__Set_LocalAnchorA(void* cls, void* v){
	((b2RevoluteJointDef*)cls)->localAnchorA = *((b2Vec2*)v);
}
void* b2RevoluteJointDef__Get_LocalAnchorB(void* cls){
	return &((b2RevoluteJointDef*)cls)->localAnchorB;
}
void b2RevoluteJointDef__Set_LocalAnchorB(void* cls, void* v){
	((b2RevoluteJointDef*)cls)->localAnchorB = *((b2Vec2*)v);
}
float b2RevoluteJointDef__Get_ReferenceAngle(void* cls){
	return ((b2RevoluteJointDef*)cls)->referenceAngle;
}
void b2RevoluteJointDef__Set_ReferenceAngle(void* cls, float v){
	((b2RevoluteJointDef*)cls)->referenceAngle = ((float)v);
}
unsigned char b2RevoluteJointDef__Get_EnableLimit(void* cls){
	return ((b2RevoluteJointDef*)cls)->enableLimit;
}
void b2RevoluteJointDef__Set_EnableLimit(void* cls, unsigned char v){
	((b2RevoluteJointDef*)cls)->enableLimit = ((unsigned char)v);
}
float b2RevoluteJointDef__Get_LowerAngle(void* cls){
	return ((b2RevoluteJointDef*)cls)->lowerAngle;
}
void b2RevoluteJointDef__Set_LowerAngle(void* cls, float v){
	((b2RevoluteJointDef*)cls)->lowerAngle = ((float)v);
}
float b2RevoluteJointDef__Get_UpperAngle(void* cls){
	return ((b2RevoluteJointDef*)cls)->upperAngle;
}
void b2RevoluteJointDef__Set_UpperAngle(void* cls, float v){
	((b2RevoluteJointDef*)cls)->upperAngle = ((float)v);
}
unsigned char b2RevoluteJointDef__Get_EnableMotor(void* cls){
	return ((b2RevoluteJointDef*)cls)->enableMotor;
}
void b2RevoluteJointDef__Set_EnableMotor(void* cls, unsigned char v){
	((b2RevoluteJointDef*)cls)->enableMotor = ((unsigned char)v);
}
float b2RevoluteJointDef__Get_MotorSpeed(void* cls){
	return ((b2RevoluteJointDef*)cls)->motorSpeed;
}
void b2RevoluteJointDef__Set_MotorSpeed(void* cls, float v){
	((b2RevoluteJointDef*)cls)->motorSpeed = ((float)v);
}
float b2RevoluteJointDef__Get_MaxMotorTorque(void* cls){
	return ((b2RevoluteJointDef*)cls)->maxMotorTorque;
}
void b2RevoluteJointDef__Set_MaxMotorTorque(void* cls, float v){
	((b2RevoluteJointDef*)cls)->maxMotorTorque = ((float)v);
}

//
// Begin class 'b2Fixture'
//
void b2Fixture__Destroy(void* cls){
	delete (b2Fixture*)cls;
}
void b2Fixture__DestroyArray(void* arr){
	delete[] (b2Fixture*)arr;
}
unsigned int b2Fixture__Size(){
	return sizeof(b2Fixture);
}
float b2Fixture_GetRestitution(void* cls){
	return ((b2Fixture*)cls)->GetRestitution();
}
void b2Fixture_SetFilterData(void* cls, void* a){
	((b2Fixture*)cls)->SetFilterData(*((b2Filter*)a));
}
void b2Fixture_SetFriction(void* cls, float a){
	((b2Fixture*)cls)->SetFriction(((float)a));
}
void* b2Fixture_GetShape0(void* cls){
	return ((b2Fixture*)cls)->GetShape();
}
void* b2Fixture_GetShape1(void* cls){
	return const_cast<b2Shape*>(((b2Fixture*)cls)->GetShape());
}
void b2Fixture_SetRestitution(void* cls, float a){
	((b2Fixture*)cls)->SetRestitution(((float)a));
}
void* b2Fixture_GetBody0(void* cls){
	return ((b2Fixture*)cls)->GetBody();
}
void* b2Fixture_GetBody1(void* cls){
	return const_cast<b2Body*>(((b2Fixture*)cls)->GetBody());
}
void* b2Fixture_GetNext0(void* cls){
	return ((b2Fixture*)cls)->GetNext();
}
void* b2Fixture_GetNext1(void* cls){
	return const_cast<b2Fixture*>(((b2Fixture*)cls)->GetNext());
}
float b2Fixture_GetFriction(void* cls){
	return ((b2Fixture*)cls)->GetFriction();
}
void* b2Fixture_GetUserData(void* cls){
	return ((b2Fixture*)cls)->GetUserData();
}
void b2Fixture_SetDensity(void* cls, float a){
	((b2Fixture*)cls)->SetDensity(((float)a));
}
void b2Fixture_GetMassData(void* cls, void* a){
	((b2Fixture*)cls)->GetMassData(((b2MassData*)a));
}
void b2Fixture_SetSensor(void* cls, unsigned char a){
	((b2Fixture*)cls)->SetSensor(((unsigned char)a));
}
void* b2Fixture_GetAABB(void* cls, int a){
	return const_cast<b2AABB*>(&((b2Fixture*)cls)->GetAABB(((int)a)));
}
unsigned char b2Fixture_TestPoint(void* cls, void* a){
	return ((b2Fixture*)cls)->TestPoint(*((b2Vec2*)a));
}
void b2Fixture_SetUserData(void* cls, void* a){
	((b2Fixture*)cls)->SetUserData(((void*)a));
}
unsigned char b2Fixture_RayCast(void* cls, void* a, void* b, int c){
	return ((b2Fixture*)cls)->RayCast(((b2RayCastOutput*)a), *((b2RayCastInput*)b), ((int)c));
}
void b2Fixture_Refilter(void* cls){
	((b2Fixture*)cls)->Refilter();
}
void* b2Fixture_GetFilterData(void* cls){
	return const_cast<b2Filter*>(&((b2Fixture*)cls)->GetFilterData());
}
unsigned char b2Fixture_IsSensor(void* cls){
	return ((b2Fixture*)cls)->IsSensor();
}
unsigned int b2Fixture_GetType(void* cls){
	return ((b2Fixture*)cls)->GetType();
}
float b2Fixture_GetDensity(void* cls){
	return ((b2Fixture*)cls)->GetDensity();
}

//
// Begin class 'b2PrismaticJoint'
//
void b2PrismaticJoint__Destroy(void* cls){
	delete (b2PrismaticJoint*)cls;
}
void b2PrismaticJoint__DestroyArray(void* arr){
	delete[] (b2PrismaticJoint*)arr;
}
unsigned int b2PrismaticJoint__Size(){
	return sizeof(b2PrismaticJoint);
}
unsigned char b2PrismaticJoint_IsMotorEnabled(void* cls){
	return ((b2PrismaticJoint*)cls)->IsMotorEnabled();
}
float b2PrismaticJoint_GetMotorSpeed(void* cls){
	return ((b2PrismaticJoint*)cls)->GetMotorSpeed();
}
void* b2PrismaticJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2PrismaticJoint*)cls)->GetAnchorA());
}
void b2PrismaticJoint_SetMaxMotorForce(void* cls, float a){
	((b2PrismaticJoint*)cls)->SetMaxMotorForce(((float)a));
}
float b2PrismaticJoint_GetReactionTorque(void* cls, float a){
	return ((b2PrismaticJoint*)cls)->GetReactionTorque(((float)a));
}
float b2PrismaticJoint_GetUpperLimit(void* cls){
	return ((b2PrismaticJoint*)cls)->GetUpperLimit();
}
float b2PrismaticJoint_GetJointTranslation(void* cls){
	return ((b2PrismaticJoint*)cls)->GetJointTranslation();
}
float b2PrismaticJoint_GetMotorForce(void* cls, float a){
	return ((b2PrismaticJoint*)cls)->GetMotorForce(((float)a));
}
float b2PrismaticJoint_GetLowerLimit(void* cls){
	return ((b2PrismaticJoint*)cls)->GetLowerLimit();
}
void b2PrismaticJoint_SetMotorSpeed(void* cls, float a){
	((b2PrismaticJoint*)cls)->SetMotorSpeed(((float)a));
}
void* b2PrismaticJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2PrismaticJoint*)cls)->GetAnchorB());
}
void* b2PrismaticJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2PrismaticJoint*)cls)->GetReactionForce(((float)a)));
}
void b2PrismaticJoint_SetLimits(void* cls, float a, float b){
	((b2PrismaticJoint*)cls)->SetLimits(((float)a), ((float)b));
}
void b2PrismaticJoint_EnableMotor(void* cls, unsigned char a){
	((b2PrismaticJoint*)cls)->EnableMotor(((unsigned char)a));
}
float b2PrismaticJoint_GetJointSpeed(void* cls){
	return ((b2PrismaticJoint*)cls)->GetJointSpeed();
}
unsigned char b2PrismaticJoint_IsLimitEnabled(void* cls){
	return ((b2PrismaticJoint*)cls)->IsLimitEnabled();
}
void b2PrismaticJoint_EnableLimit(void* cls, unsigned char a){
	((b2PrismaticJoint*)cls)->EnableLimit(((unsigned char)a));
}

//
// Begin class 'b2PolygonShape'
//
void* b2PolygonShape__Create(){
	return new b2PolygonShape();
}
void* b2PolygonShape__CreateArray(int n){
	return new b2PolygonShape[n];
}
void b2PolygonShape__Destroy(void* cls){
	delete (b2PolygonShape*)cls;
}
void b2PolygonShape__DestroyArray(void* arr){
	delete[] (b2PolygonShape*)arr;
}
unsigned int b2PolygonShape__Size(){
	return sizeof(b2PolygonShape);
}
void b2PolygonShape_Set(void* cls, void* a, int b){
	((b2PolygonShape*)cls)->Set(((b2Vec2*)a), ((int)b));
}
void b2PolygonShape_ComputeMass(void* cls, void* a, float b){
	((b2PolygonShape*)cls)->ComputeMass(((b2MassData*)a), ((float)b));
}
void* b2PolygonShape_Clone(void* cls, void* a){
	return ((b2PolygonShape*)cls)->Clone(((b2BlockAllocator*)a));
}
void* b2PolygonShape_GetVertex(void* cls, int a){
	return const_cast<b2Vec2*>(&((b2PolygonShape*)cls)->GetVertex(((int)a)));
}
unsigned char b2PolygonShape_RayCast(void* cls, void* a, void* b, void* c, int d){
	return ((b2PolygonShape*)cls)->RayCast(((b2RayCastOutput*)a), *((b2RayCastInput*)b), *((b2Transform*)c), ((int)d));
}
void b2PolygonShape_ComputeAABB(void* cls, void* a, void* b, int c){
	((b2PolygonShape*)cls)->ComputeAABB(((b2AABB*)a), *((b2Transform*)b), ((int)c));
}
int b2PolygonShape_GetVertexCount(void* cls){
	return ((b2PolygonShape*)cls)->GetVertexCount();
}
int b2PolygonShape_GetChildCount(void* cls){
	return ((b2PolygonShape*)cls)->GetChildCount();
}
unsigned char b2PolygonShape_TestPoint(void* cls, void* a, void* b){
	return ((b2PolygonShape*)cls)->TestPoint(*((b2Transform*)a), *((b2Vec2*)b));
}
void b2PolygonShape_SetAsBox0(void* cls, float a, float b){
	((b2PolygonShape*)cls)->SetAsBox(((float)a), ((float)b));
}
void b2PolygonShape_SetAsBox1(void* cls, float a, float b, void* c, float d){
	((b2PolygonShape*)cls)->SetAsBox(((float)a), ((float)b), *((b2Vec2*)c), ((float)d));
}
void* b2PolygonShape__Get_MCentroid(void* cls){
	return &((b2PolygonShape*)cls)->m_centroid;
}
void b2PolygonShape__Set_MCentroid(void* cls, void* v){
	((b2PolygonShape*)cls)->m_centroid = *((b2Vec2*)v);
}
int b2PolygonShape__Get_MVertexCount(void* cls){
	return ((b2PolygonShape*)cls)->m_vertexCount;
}
void b2PolygonShape__Set_MVertexCount(void* cls, int v){
	((b2PolygonShape*)cls)->m_vertexCount = ((int)v);
}

//
// Begin class 'b2Jacobian'
//
void* b2Jacobian__Create(){
	return new b2Jacobian;
}
void* b2Jacobian__CreateArray(int n){
	return new b2Jacobian[n];
}
void b2Jacobian__Destroy(void* cls){
	delete (b2Jacobian*)cls;
}
void b2Jacobian__DestroyArray(void* arr){
	delete[] (b2Jacobian*)arr;
}
unsigned int b2Jacobian__Size(){
	return sizeof(b2Jacobian);
}
void* b2Jacobian__Get_Linear(void* cls){
	return &((b2Jacobian*)cls)->linear;
}
void b2Jacobian__Set_Linear(void* cls, void* v){
	((b2Jacobian*)cls)->linear = *((b2Vec2*)v);
}
float b2Jacobian__Get_AngularA(void* cls){
	return ((b2Jacobian*)cls)->angularA;
}
void b2Jacobian__Set_AngularA(void* cls, float v){
	((b2Jacobian*)cls)->angularA = ((float)v);
}
float b2Jacobian__Get_AngularB(void* cls){
	return ((b2Jacobian*)cls)->angularB;
}
void b2Jacobian__Set_AngularB(void* cls, float v){
	((b2Jacobian*)cls)->angularB = ((float)v);
}

//
// Begin class 'b2ContactFeature'
//
void* b2ContactFeature__Create(){
	return new b2ContactFeature;
}
void* b2ContactFeature__CreateArray(int n){
	return new b2ContactFeature[n];
}
void b2ContactFeature__Destroy(void* cls){
	delete (b2ContactFeature*)cls;
}
void b2ContactFeature__DestroyArray(void* arr){
	delete[] (b2ContactFeature*)arr;
}
unsigned int b2ContactFeature__Size(){
	return sizeof(b2ContactFeature);
}
unsigned char b2ContactFeature__Get_IndexA(void* cls){
	return ((b2ContactFeature*)cls)->indexA;
}
void b2ContactFeature__Set_IndexA(void* cls, unsigned char v){
	((b2ContactFeature*)cls)->indexA = ((unsigned char)v);
}
unsigned char b2ContactFeature__Get_IndexB(void* cls){
	return ((b2ContactFeature*)cls)->indexB;
}
void b2ContactFeature__Set_IndexB(void* cls, unsigned char v){
	((b2ContactFeature*)cls)->indexB = ((unsigned char)v);
}
unsigned char b2ContactFeature__Get_TypeA(void* cls){
	return ((b2ContactFeature*)cls)->typeA;
}
void b2ContactFeature__Set_TypeA(void* cls, unsigned char v){
	((b2ContactFeature*)cls)->typeA = ((unsigned char)v);
}
unsigned char b2ContactFeature__Get_TypeB(void* cls){
	return ((b2ContactFeature*)cls)->typeB;
}
void b2ContactFeature__Set_TypeB(void* cls, unsigned char v){
	((b2ContactFeature*)cls)->typeB = ((unsigned char)v);
}

//
// Begin class 'b2SolverData'
//
void* b2SolverData__Create(){
	return new b2SolverData;
}
void* b2SolverData__CreateArray(int n){
	return new b2SolverData[n];
}
void b2SolverData__Destroy(void* cls){
	delete (b2SolverData*)cls;
}
void b2SolverData__DestroyArray(void* arr){
	delete[] (b2SolverData*)arr;
}
unsigned int b2SolverData__Size(){
	return sizeof(b2SolverData);
}
void* b2SolverData__Get_Step(void* cls){
	return &((b2SolverData*)cls)->step;
}
void b2SolverData__Set_Step(void* cls, void* v){
	((b2SolverData*)cls)->step = *((b2TimeStep*)v);
}
void* b2SolverData__Get_Positions(void* cls){
	return ((b2SolverData*)cls)->positions;
}
void b2SolverData__Set_Positions(void* cls, void* v){
	((b2SolverData*)cls)->positions = ((b2Position*)v);
}
void* b2SolverData__Get_Velocities(void* cls){
	return ((b2SolverData*)cls)->velocities;
}
void b2SolverData__Set_Velocities(void* cls, void* v){
	((b2SolverData*)cls)->velocities = ((b2Velocity*)v);
}

//
// Begin class 'b2Pair'
//
void* b2Pair__Create(){
	return new b2Pair;
}
void* b2Pair__CreateArray(int n){
	return new b2Pair[n];
}
void b2Pair__Destroy(void* cls){
	delete (b2Pair*)cls;
}
void b2Pair__DestroyArray(void* arr){
	delete[] (b2Pair*)arr;
}
unsigned int b2Pair__Size(){
	return sizeof(b2Pair);
}
int b2Pair__Get_ProxyIdA(void* cls){
	return ((b2Pair*)cls)->proxyIdA;
}
void b2Pair__Set_ProxyIdA(void* cls, int v){
	((b2Pair*)cls)->proxyIdA = ((int)v);
}
int b2Pair__Get_ProxyIdB(void* cls){
	return ((b2Pair*)cls)->proxyIdB;
}
void b2Pair__Set_ProxyIdB(void* cls, int v){
	((b2Pair*)cls)->proxyIdB = ((int)v);
}
int b2Pair__Get_Next(void* cls){
	return ((b2Pair*)cls)->next;
}
void b2Pair__Set_Next(void* cls, int v){
	((b2Pair*)cls)->next = ((int)v);
}

//
// Begin class 'b2World'
//
void* b2World__Create(void* a, unsigned char b){
	return new b2World(*((b2Vec2*)a), ((unsigned char)b));
}
void b2World__Destroy(void* cls){
	delete (b2World*)cls;
}
void b2World__DestroyArray(void* arr){
	delete[] (b2World*)arr;
}
unsigned int b2World__Size(){
	return sizeof(b2World);
}
void b2World_QueryAABB(void* cls, void* a, void* b){
	((b2World*)cls)->QueryAABB(((b2QueryCallback*)a), *((b2AABB*)b));
}
void* b2World_GetContactList0(void* cls){
	return ((b2World*)cls)->GetContactList();
}
void* b2World_GetContactList1(void* cls){
	return const_cast<b2Contact*>(((b2World*)cls)->GetContactList());
}
float b2World_GetTreeQuality(void* cls){
	return ((b2World*)cls)->GetTreeQuality();
}
int b2World_GetTreeHeight(void* cls){
	return ((b2World*)cls)->GetTreeHeight();
}
void* b2World_GetProfile(void* cls){
	return const_cast<b2Profile*>(&((b2World*)cls)->GetProfile());
}
int b2World_GetTreeBalance(void* cls){
	return ((b2World*)cls)->GetTreeBalance();
}
void* b2World_GetContactManager(void* cls){
	return const_cast<b2ContactManager*>(&((b2World*)cls)->GetContactManager());
}
void b2World_SetContactListener(void* cls, void* a){
	((b2World*)cls)->SetContactListener(((b2ContactListener*)a));
}
void b2World_DrawDebugData(void* cls){
	((b2World*)cls)->DrawDebugData();
}
void b2World_SetContinuousPhysics(void* cls, unsigned char a){
	((b2World*)cls)->SetContinuousPhysics(((unsigned char)a));
}
void b2World_SetGravity(void* cls, void* a){
	((b2World*)cls)->SetGravity(*((b2Vec2*)a));
}
int b2World_GetBodyCount(void* cls){
	return ((b2World*)cls)->GetBodyCount();
}
unsigned char b2World_GetAutoClearForces(void* cls){
	return ((b2World*)cls)->GetAutoClearForces();
}
void* b2World_GetJointList0(void* cls){
	return ((b2World*)cls)->GetJointList();
}
void* b2World_GetJointList1(void* cls){
	return const_cast<b2Joint*>(((b2World*)cls)->GetJointList());
}
void* b2World_CreateBody(void* cls, void* a){
	return ((b2World*)cls)->CreateBody(((b2BodyDef*)a));
}
void* b2World_GetBodyList0(void* cls){
	return ((b2World*)cls)->GetBodyList();
}
void* b2World_GetBodyList1(void* cls){
	return const_cast<b2Body*>(((b2World*)cls)->GetBodyList());
}
void b2World_SetDestructionListener(void* cls, void* a){
	((b2World*)cls)->SetDestructionListener(((b2DestructionListener*)a));
}
void b2World_DestroyJoint(void* cls, void* a){
	((b2World*)cls)->DestroyJoint(((b2Joint*)a));
}
int b2World_GetJointCount(void* cls){
	return ((b2World*)cls)->GetJointCount();
}
void b2World_Step(void* cls, float a, int b, int c){
	((b2World*)cls)->Step(((float)a), ((int)b), ((int)c));
}
void b2World_ClearForces(void* cls){
	((b2World*)cls)->ClearForces();
}
void b2World_DestroyBody(void* cls, void* a){
	((b2World*)cls)->DestroyBody(((b2Body*)a));
}
void* b2World_CreateJoint(void* cls, void* a){
	return ((b2World*)cls)->CreateJoint(((b2JointDef*)a));
}
int b2World_GetProxyCount(void* cls){
	return ((b2World*)cls)->GetProxyCount();
}
void b2World_RayCast(void* cls, void* a, void* b, void* c){
	((b2World*)cls)->RayCast(((b2RayCastCallback*)a), *((b2Vec2*)b), *((b2Vec2*)c));
}
unsigned char b2World_IsLocked(void* cls){
	return ((b2World*)cls)->IsLocked();
}
void b2World_SetSubStepping(void* cls, unsigned char a){
	((b2World*)cls)->SetSubStepping(((unsigned char)a));
}
void b2World_SetDebugDraw(void* cls, void* a){
	((b2World*)cls)->SetDebugDraw(((b2Draw*)a));
}
void b2World_SetAutoClearForces(void* cls, unsigned char a){
	((b2World*)cls)->SetAutoClearForces(((unsigned char)a));
}
void* b2World_GetGravity(void* cls){
	return new b2Vec2(((b2World*)cls)->GetGravity());
}
int b2World_GetContactCount(void* cls){
	return ((b2World*)cls)->GetContactCount();
}
void b2World_SetWarmStarting(void* cls, unsigned char a){
	((b2World*)cls)->SetWarmStarting(((unsigned char)a));
}
void b2World_SetContactFilter(void* cls, void* a){
	((b2World*)cls)->SetContactFilter(((b2ContactFilter*)a));
}

//
// Begin class 'b2Shape'
//
void b2Shape__Destroy(void* cls){
	delete (b2Shape*)cls;
}
void b2Shape__DestroyArray(void* arr){
	delete[] (b2Shape*)arr;
}
unsigned int b2Shape__Size(){
	return sizeof(b2Shape);
}
unsigned int b2Shape_GetType(void* cls){
	return ((b2Shape*)cls)->GetType();
}
unsigned int b2Shape__Get_MType(void* cls){
	return ((b2Shape*)cls)->m_type;
}
void b2Shape__Set_MType(void* cls, unsigned int v){
	((b2Shape*)cls)->m_type = ((b2Shape::Type)v);
}
float b2Shape__Get_MRadius(void* cls){
	return ((b2Shape*)cls)->m_radius;
}
void b2Shape__Set_MRadius(void* cls, float v){
	((b2Shape*)cls)->m_radius = ((float)v);
}

//
// Begin class 'b2DistanceJoint'
//
void b2DistanceJoint__Destroy(void* cls){
	delete (b2DistanceJoint*)cls;
}
void b2DistanceJoint__DestroyArray(void* arr){
	delete[] (b2DistanceJoint*)arr;
}
unsigned int b2DistanceJoint__Size(){
	return sizeof(b2DistanceJoint);
}
void* b2DistanceJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2DistanceJoint*)cls)->GetAnchorA());
}
float b2DistanceJoint_GetReactionTorque(void* cls, float a){
	return ((b2DistanceJoint*)cls)->GetReactionTorque(((float)a));
}
void b2DistanceJoint_SetFrequency(void* cls, float a){
	((b2DistanceJoint*)cls)->SetFrequency(((float)a));
}
float b2DistanceJoint_GetLength(void* cls){
	return ((b2DistanceJoint*)cls)->GetLength();
}
float b2DistanceJoint_GetDampingRatio(void* cls){
	return ((b2DistanceJoint*)cls)->GetDampingRatio();
}
float b2DistanceJoint_GetFrequency(void* cls){
	return ((b2DistanceJoint*)cls)->GetFrequency();
}
void b2DistanceJoint_SetDampingRatio(void* cls, float a){
	((b2DistanceJoint*)cls)->SetDampingRatio(((float)a));
}
void* b2DistanceJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2DistanceJoint*)cls)->GetAnchorB());
}
void* b2DistanceJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2DistanceJoint*)cls)->GetReactionForce(((float)a)));
}
void b2DistanceJoint_SetLength(void* cls, float a){
	((b2DistanceJoint*)cls)->SetLength(((float)a));
}

//
// Begin class 'b2TreeNode'
//
void* b2TreeNode__Create(){
	return new b2TreeNode;
}
void* b2TreeNode__CreateArray(int n){
	return new b2TreeNode[n];
}
void b2TreeNode__Destroy(void* cls){
	delete (b2TreeNode*)cls;
}
void b2TreeNode__DestroyArray(void* arr){
	delete[] (b2TreeNode*)arr;
}
unsigned int b2TreeNode__Size(){
	return sizeof(b2TreeNode);
}
unsigned char b2TreeNode_IsLeaf(void* cls){
	return ((b2TreeNode*)cls)->IsLeaf();
}
void* b2TreeNode__Get_Aabb(void* cls){
	return &((b2TreeNode*)cls)->aabb;
}
void b2TreeNode__Set_Aabb(void* cls, void* v){
	((b2TreeNode*)cls)->aabb = *((b2AABB*)v);
}
int b2TreeNode__Get_Child1(void* cls){
	return ((b2TreeNode*)cls)->child1;
}
void b2TreeNode__Set_Child1(void* cls, int v){
	((b2TreeNode*)cls)->child1 = ((int)v);
}
int b2TreeNode__Get_Child2(void* cls){
	return ((b2TreeNode*)cls)->child2;
}
void b2TreeNode__Set_Child2(void* cls, int v){
	((b2TreeNode*)cls)->child2 = ((int)v);
}
int b2TreeNode__Get_Height(void* cls){
	return ((b2TreeNode*)cls)->height;
}
void b2TreeNode__Set_Height(void* cls, int v){
	((b2TreeNode*)cls)->height = ((int)v);
}

//
// Begin class 'b2CircleShape'
//
void* b2CircleShape__Create(){
	return new b2CircleShape();
}
void* b2CircleShape__CreateArray(int n){
	return new b2CircleShape[n];
}
void b2CircleShape__Destroy(void* cls){
	delete (b2CircleShape*)cls;
}
void b2CircleShape__DestroyArray(void* arr){
	delete[] (b2CircleShape*)arr;
}
unsigned int b2CircleShape__Size(){
	return sizeof(b2CircleShape);
}
void b2CircleShape_ComputeMass(void* cls, void* a, float b){
	((b2CircleShape*)cls)->ComputeMass(((b2MassData*)a), ((float)b));
}
void* b2CircleShape_GetVertex(void* cls, int a){
	return const_cast<b2Vec2*>(&((b2CircleShape*)cls)->GetVertex(((int)a)));
}
void* b2CircleShape_Clone(void* cls, void* a){
	return ((b2CircleShape*)cls)->Clone(((b2BlockAllocator*)a));
}
void* b2CircleShape_GetSupportVertex(void* cls, void* a){
	return const_cast<b2Vec2*>(&((b2CircleShape*)cls)->GetSupportVertex(*((b2Vec2*)a)));
}
unsigned char b2CircleShape_RayCast(void* cls, void* a, void* b, void* c, int d){
	return ((b2CircleShape*)cls)->RayCast(((b2RayCastOutput*)a), *((b2RayCastInput*)b), *((b2Transform*)c), ((int)d));
}
void b2CircleShape_ComputeAABB(void* cls, void* a, void* b, int c){
	((b2CircleShape*)cls)->ComputeAABB(((b2AABB*)a), *((b2Transform*)b), ((int)c));
}
int b2CircleShape_GetVertexCount(void* cls){
	return ((b2CircleShape*)cls)->GetVertexCount();
}
int b2CircleShape_GetChildCount(void* cls){
	return ((b2CircleShape*)cls)->GetChildCount();
}
unsigned char b2CircleShape_TestPoint(void* cls, void* a, void* b){
	return ((b2CircleShape*)cls)->TestPoint(*((b2Transform*)a), *((b2Vec2*)b));
}
int b2CircleShape_GetSupport(void* cls, void* a){
	return ((b2CircleShape*)cls)->GetSupport(*((b2Vec2*)a));
}
void* b2CircleShape__Get_MP(void* cls){
	return &((b2CircleShape*)cls)->m_p;
}
void b2CircleShape__Set_MP(void* cls, void* v){
	((b2CircleShape*)cls)->m_p = *((b2Vec2*)v);
}

//
// Begin class 'b2JointEdge'
//
void* b2JointEdge__Create(){
	return new b2JointEdge;
}
void* b2JointEdge__CreateArray(int n){
	return new b2JointEdge[n];
}
void b2JointEdge__Destroy(void* cls){
	delete (b2JointEdge*)cls;
}
void b2JointEdge__DestroyArray(void* arr){
	delete[] (b2JointEdge*)arr;
}
unsigned int b2JointEdge__Size(){
	return sizeof(b2JointEdge);
}
void* b2JointEdge__Get_Other(void* cls){
	return ((b2JointEdge*)cls)->other;
}
void b2JointEdge__Set_Other(void* cls, void* v){
	((b2JointEdge*)cls)->other = ((b2Body*)v);
}
void* b2JointEdge__Get_Prev(void* cls){
	return ((b2JointEdge*)cls)->prev;
}
void b2JointEdge__Set_Prev(void* cls, void* v){
	((b2JointEdge*)cls)->prev = ((b2JointEdge*)v);
}
void* b2JointEdge__Get_Next(void* cls){
	return ((b2JointEdge*)cls)->next;
}
void b2JointEdge__Set_Next(void* cls, void* v){
	((b2JointEdge*)cls)->next = ((b2JointEdge*)v);
}

//
// Begin class 'b2RopeJointDef'
//
void* b2RopeJointDef__Create(){
	return new b2RopeJointDef();
}
void* b2RopeJointDef__CreateArray(int n){
	return new b2RopeJointDef[n];
}
void b2RopeJointDef__Destroy(void* cls){
	delete (b2RopeJointDef*)cls;
}
void b2RopeJointDef__DestroyArray(void* arr){
	delete[] (b2RopeJointDef*)arr;
}
unsigned int b2RopeJointDef__Size(){
	return sizeof(b2RopeJointDef);
}
void* b2RopeJointDef__Get_LocalAnchorA(void* cls){
	return &((b2RopeJointDef*)cls)->localAnchorA;
}
void b2RopeJointDef__Set_LocalAnchorA(void* cls, void* v){
	((b2RopeJointDef*)cls)->localAnchorA = *((b2Vec2*)v);
}
void* b2RopeJointDef__Get_LocalAnchorB(void* cls){
	return &((b2RopeJointDef*)cls)->localAnchorB;
}
void b2RopeJointDef__Set_LocalAnchorB(void* cls, void* v){
	((b2RopeJointDef*)cls)->localAnchorB = *((b2Vec2*)v);
}
float b2RopeJointDef__Get_MaxLength(void* cls){
	return ((b2RopeJointDef*)cls)->maxLength;
}
void b2RopeJointDef__Set_MaxLength(void* cls, float v){
	((b2RopeJointDef*)cls)->maxLength = ((float)v);
}

//
// Begin class 'b2Position'
//
void* b2Position__Create(){
	return new b2Position;
}
void* b2Position__CreateArray(int n){
	return new b2Position[n];
}
void b2Position__Destroy(void* cls){
	delete (b2Position*)cls;
}
void b2Position__DestroyArray(void* arr){
	delete[] (b2Position*)arr;
}
unsigned int b2Position__Size(){
	return sizeof(b2Position);
}
void* b2Position__Get_C(void* cls){
	return &((b2Position*)cls)->c;
}
void b2Position__Set_C(void* cls, void* v){
	((b2Position*)cls)->c = *((b2Vec2*)v);
}
float b2Position__Get_A(void* cls){
	return ((b2Position*)cls)->a;
}
void b2Position__Set_A(void* cls, float v){
	((b2Position*)cls)->a = ((float)v);
}

//
// Begin class 'b2Profile'
//
void* b2Profile__Create(){
	return new b2Profile;
}
void* b2Profile__CreateArray(int n){
	return new b2Profile[n];
}
void b2Profile__Destroy(void* cls){
	delete (b2Profile*)cls;
}
void b2Profile__DestroyArray(void* arr){
	delete[] (b2Profile*)arr;
}
unsigned int b2Profile__Size(){
	return sizeof(b2Profile);
}
float b2Profile__Get_Step(void* cls){
	return ((b2Profile*)cls)->step;
}
void b2Profile__Set_Step(void* cls, float v){
	((b2Profile*)cls)->step = ((float)v);
}
float b2Profile__Get_Collide(void* cls){
	return ((b2Profile*)cls)->collide;
}
void b2Profile__Set_Collide(void* cls, float v){
	((b2Profile*)cls)->collide = ((float)v);
}
float b2Profile__Get_Solve(void* cls){
	return ((b2Profile*)cls)->solve;
}
void b2Profile__Set_Solve(void* cls, float v){
	((b2Profile*)cls)->solve = ((float)v);
}
float b2Profile__Get_SolveInit(void* cls){
	return ((b2Profile*)cls)->solveInit;
}
void b2Profile__Set_SolveInit(void* cls, float v){
	((b2Profile*)cls)->solveInit = ((float)v);
}
float b2Profile__Get_SolveVelocity(void* cls){
	return ((b2Profile*)cls)->solveVelocity;
}
void b2Profile__Set_SolveVelocity(void* cls, float v){
	((b2Profile*)cls)->solveVelocity = ((float)v);
}
float b2Profile__Get_SolvePosition(void* cls){
	return ((b2Profile*)cls)->solvePosition;
}
void b2Profile__Set_SolvePosition(void* cls, float v){
	((b2Profile*)cls)->solvePosition = ((float)v);
}
float b2Profile__Get_Broadphase(void* cls){
	return ((b2Profile*)cls)->broadphase;
}
void b2Profile__Set_Broadphase(void* cls, float v){
	((b2Profile*)cls)->broadphase = ((float)v);
}
float b2Profile__Get_SolveTOI(void* cls){
	return ((b2Profile*)cls)->solveTOI;
}
void b2Profile__Set_SolveTOI(void* cls, float v){
	((b2Profile*)cls)->solveTOI = ((float)v);
}

//
// Begin class 'b2RevoluteJoint'
//
void b2RevoluteJoint__Destroy(void* cls){
	delete (b2RevoluteJoint*)cls;
}
void b2RevoluteJoint__DestroyArray(void* arr){
	delete[] (b2RevoluteJoint*)arr;
}
unsigned int b2RevoluteJoint__Size(){
	return sizeof(b2RevoluteJoint);
}
unsigned char b2RevoluteJoint_IsMotorEnabled(void* cls){
	return ((b2RevoluteJoint*)cls)->IsMotorEnabled();
}
float b2RevoluteJoint_GetMotorSpeed(void* cls){
	return ((b2RevoluteJoint*)cls)->GetMotorSpeed();
}
float b2RevoluteJoint_GetReactionTorque(void* cls, float a){
	return ((b2RevoluteJoint*)cls)->GetReactionTorque(((float)a));
}
void* b2RevoluteJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2RevoluteJoint*)cls)->GetReactionForce(((float)a)));
}
float b2RevoluteJoint_GetUpperLimit(void* cls){
	return ((b2RevoluteJoint*)cls)->GetUpperLimit();
}
float b2RevoluteJoint_GetMotorTorque(void* cls, float a){
	return ((b2RevoluteJoint*)cls)->GetMotorTorque(((float)a));
}
void b2RevoluteJoint_SetMaxMotorTorque(void* cls, float a){
	((b2RevoluteJoint*)cls)->SetMaxMotorTorque(((float)a));
}
float b2RevoluteJoint_GetLowerLimit(void* cls){
	return ((b2RevoluteJoint*)cls)->GetLowerLimit();
}
void b2RevoluteJoint_SetMotorSpeed(void* cls, float a){
	((b2RevoluteJoint*)cls)->SetMotorSpeed(((float)a));
}
float b2RevoluteJoint_GetJointAngle(void* cls){
	return ((b2RevoluteJoint*)cls)->GetJointAngle();
}
void b2RevoluteJoint_EnableLimit(void* cls, unsigned char a){
	((b2RevoluteJoint*)cls)->EnableLimit(((unsigned char)a));
}
void* b2RevoluteJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2RevoluteJoint*)cls)->GetAnchorA());
}
void b2RevoluteJoint_SetLimits(void* cls, float a, float b){
	((b2RevoluteJoint*)cls)->SetLimits(((float)a), ((float)b));
}
void b2RevoluteJoint_EnableMotor(void* cls, unsigned char a){
	((b2RevoluteJoint*)cls)->EnableMotor(((unsigned char)a));
}
float b2RevoluteJoint_GetJointSpeed(void* cls){
	return ((b2RevoluteJoint*)cls)->GetJointSpeed();
}
unsigned char b2RevoluteJoint_IsLimitEnabled(void* cls){
	return ((b2RevoluteJoint*)cls)->IsLimitEnabled();
}
void* b2RevoluteJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2RevoluteJoint*)cls)->GetAnchorB());
}

//
// Begin class 'b2Mat33'
//
void* b2Mat33__Create0(){
	return new b2Mat33();
}
void* b2Mat33__Create1(void* a, void* b, void* c){
	return new b2Mat33(*((b2Vec3*)a), *((b2Vec3*)b), *((b2Vec3*)c));
}
void* b2Mat33__CreateArray(int n){
	return new b2Mat33[n];
}
void b2Mat33__Destroy(void* cls){
	delete (b2Mat33*)cls;
}
void b2Mat33__DestroyArray(void* arr){
	delete[] (b2Mat33*)arr;
}
unsigned int b2Mat33__Size(){
	return sizeof(b2Mat33);
}
void b2Mat33_SetZero(void* cls){
	((b2Mat33*)cls)->SetZero();
}
void* b2Mat33_Solve33(void* cls, void* a){
	return new b2Vec3(((b2Mat33*)cls)->Solve33(*((b2Vec3*)a)));
}
void* b2Mat33_Solve22(void* cls, void* a){
	return new b2Vec2(((b2Mat33*)cls)->Solve22(*((b2Vec2*)a)));
}
void* b2Mat33__Get_Ex(void* cls){
	return &((b2Mat33*)cls)->ex;
}
void b2Mat33__Set_Ex(void* cls, void* v){
	((b2Mat33*)cls)->ex = *((b2Vec3*)v);
}
void* b2Mat33__Get_Ey(void* cls){
	return &((b2Mat33*)cls)->ey;
}
void b2Mat33__Set_Ey(void* cls, void* v){
	((b2Mat33*)cls)->ey = *((b2Vec3*)v);
}
void* b2Mat33__Get_Ez(void* cls){
	return &((b2Mat33*)cls)->ez;
}
void b2Mat33__Set_Ez(void* cls, void* v){
	((b2Mat33*)cls)->ez = *((b2Vec3*)v);
}

//
// Begin class 'b2TimeStep'
//
void* b2TimeStep__Create(){
	return new b2TimeStep;
}
void* b2TimeStep__CreateArray(int n){
	return new b2TimeStep[n];
}
void b2TimeStep__Destroy(void* cls){
	delete (b2TimeStep*)cls;
}
void b2TimeStep__DestroyArray(void* arr){
	delete[] (b2TimeStep*)arr;
}
unsigned int b2TimeStep__Size(){
	return sizeof(b2TimeStep);
}
float b2TimeStep__Get_Dt(void* cls){
	return ((b2TimeStep*)cls)->dt;
}
void b2TimeStep__Set_Dt(void* cls, float v){
	((b2TimeStep*)cls)->dt = ((float)v);
}
float b2TimeStep__Get_InvDt(void* cls){
	return ((b2TimeStep*)cls)->inv_dt;
}
void b2TimeStep__Set_InvDt(void* cls, float v){
	((b2TimeStep*)cls)->inv_dt = ((float)v);
}
float b2TimeStep__Get_DtRatio(void* cls){
	return ((b2TimeStep*)cls)->dtRatio;
}
void b2TimeStep__Set_DtRatio(void* cls, float v){
	((b2TimeStep*)cls)->dtRatio = ((float)v);
}
int b2TimeStep__Get_VelocityIterations(void* cls){
	return ((b2TimeStep*)cls)->velocityIterations;
}
void b2TimeStep__Set_VelocityIterations(void* cls, int v){
	((b2TimeStep*)cls)->velocityIterations = ((int)v);
}
int b2TimeStep__Get_PositionIterations(void* cls){
	return ((b2TimeStep*)cls)->positionIterations;
}
void b2TimeStep__Set_PositionIterations(void* cls, int v){
	((b2TimeStep*)cls)->positionIterations = ((int)v);
}
unsigned char b2TimeStep__Get_WarmStarting(void* cls){
	return ((b2TimeStep*)cls)->warmStarting;
}
void b2TimeStep__Set_WarmStarting(void* cls, unsigned char v){
	((b2TimeStep*)cls)->warmStarting = ((unsigned char)v);
}

//
// Begin class 'b2ContactImpulse'
//
void* b2ContactImpulse__Create(){
	return new b2ContactImpulse;
}
void* b2ContactImpulse__CreateArray(int n){
	return new b2ContactImpulse[n];
}
void b2ContactImpulse__Destroy(void* cls){
	delete (b2ContactImpulse*)cls;
}
void b2ContactImpulse__DestroyArray(void* arr){
	delete[] (b2ContactImpulse*)arr;
}
unsigned int b2ContactImpulse__Size(){
	return sizeof(b2ContactImpulse);
}

//
// Begin class 'b2Sweep'
//
void* b2Sweep__Create(){
	return new b2Sweep;
}
void* b2Sweep__CreateArray(int n){
	return new b2Sweep[n];
}
void b2Sweep__Destroy(void* cls){
	delete (b2Sweep*)cls;
}
void b2Sweep__DestroyArray(void* arr){
	delete[] (b2Sweep*)arr;
}
unsigned int b2Sweep__Size(){
	return sizeof(b2Sweep);
}
void b2Sweep_Normalize(void* cls){
	((b2Sweep*)cls)->Normalize();
}
void b2Sweep_Advance(void* cls, float a){
	((b2Sweep*)cls)->Advance(((float)a));
}
void b2Sweep_GetTransform(void* cls, void* a, float b){
	((b2Sweep*)cls)->GetTransform(((b2Transform*)a), ((float)b));
}
void* b2Sweep__Get_LocalCenter(void* cls){
	return &((b2Sweep*)cls)->localCenter;
}
void b2Sweep__Set_LocalCenter(void* cls, void* v){
	((b2Sweep*)cls)->localCenter = *((b2Vec2*)v);
}
void* b2Sweep__Get_C0(void* cls){
	return &((b2Sweep*)cls)->c0;
}
void b2Sweep__Set_C0(void* cls, void* v){
	((b2Sweep*)cls)->c0 = *((b2Vec2*)v);
}
void* b2Sweep__Get_C(void* cls){
	return &((b2Sweep*)cls)->c;
}
void b2Sweep__Set_C(void* cls, void* v){
	((b2Sweep*)cls)->c = *((b2Vec2*)v);
}
float b2Sweep__Get_A0(void* cls){
	return ((b2Sweep*)cls)->a0;
}
void b2Sweep__Set_A0(void* cls, float v){
	((b2Sweep*)cls)->a0 = ((float)v);
}
float b2Sweep__Get_A(void* cls){
	return ((b2Sweep*)cls)->a;
}
void b2Sweep__Set_A(void* cls, float v){
	((b2Sweep*)cls)->a = ((float)v);
}
float b2Sweep__Get_Alpha0(void* cls){
	return ((b2Sweep*)cls)->alpha0;
}
void b2Sweep__Set_Alpha0(void* cls, float v){
	((b2Sweep*)cls)->alpha0 = ((float)v);
}

//
// Begin class 'b2FrictionJoint'
//
void b2FrictionJoint__Destroy(void* cls){
	delete (b2FrictionJoint*)cls;
}
void b2FrictionJoint__DestroyArray(void* arr){
	delete[] (b2FrictionJoint*)arr;
}
unsigned int b2FrictionJoint__Size(){
	return sizeof(b2FrictionJoint);
}
void b2FrictionJoint_SetMaxTorque(void* cls, float a){
	((b2FrictionJoint*)cls)->SetMaxTorque(((float)a));
}
void* b2FrictionJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2FrictionJoint*)cls)->GetAnchorA());
}
float b2FrictionJoint_GetReactionTorque(void* cls, float a){
	return ((b2FrictionJoint*)cls)->GetReactionTorque(((float)a));
}
void b2FrictionJoint_SetMaxForce(void* cls, float a){
	((b2FrictionJoint*)cls)->SetMaxForce(((float)a));
}
float b2FrictionJoint_GetMaxForce(void* cls){
	return ((b2FrictionJoint*)cls)->GetMaxForce();
}
void* b2FrictionJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2FrictionJoint*)cls)->GetAnchorB());
}
void* b2FrictionJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2FrictionJoint*)cls)->GetReactionForce(((float)a)));
}
float b2FrictionJoint_GetMaxTorque(void* cls){
	return ((b2FrictionJoint*)cls)->GetMaxTorque();
}

//
// Begin class 'b2MouseJointDef'
//
void* b2MouseJointDef__Create(){
	return new b2MouseJointDef();
}
void* b2MouseJointDef__CreateArray(int n){
	return new b2MouseJointDef[n];
}
void b2MouseJointDef__Destroy(void* cls){
	delete (b2MouseJointDef*)cls;
}
void b2MouseJointDef__DestroyArray(void* arr){
	delete[] (b2MouseJointDef*)arr;
}
unsigned int b2MouseJointDef__Size(){
	return sizeof(b2MouseJointDef);
}
void* b2MouseJointDef__Get_Target(void* cls){
	return &((b2MouseJointDef*)cls)->target;
}
void b2MouseJointDef__Set_Target(void* cls, void* v){
	((b2MouseJointDef*)cls)->target = *((b2Vec2*)v);
}
float b2MouseJointDef__Get_MaxForce(void* cls){
	return ((b2MouseJointDef*)cls)->maxForce;
}
void b2MouseJointDef__Set_MaxForce(void* cls, float v){
	((b2MouseJointDef*)cls)->maxForce = ((float)v);
}
float b2MouseJointDef__Get_FrequencyHz(void* cls){
	return ((b2MouseJointDef*)cls)->frequencyHz;
}
void b2MouseJointDef__Set_FrequencyHz(void* cls, float v){
	((b2MouseJointDef*)cls)->frequencyHz = ((float)v);
}
float b2MouseJointDef__Get_DampingRatio(void* cls){
	return ((b2MouseJointDef*)cls)->dampingRatio;
}
void b2MouseJointDef__Set_DampingRatio(void* cls, float v){
	((b2MouseJointDef*)cls)->dampingRatio = ((float)v);
}

//
// Begin class 'b2Draw'
//
void b2Draw__Destroy(void* cls){
	delete (b2Draw*)cls;
}
void b2Draw__DestroyArray(void* arr){
	delete[] (b2Draw*)arr;
}
unsigned int b2Draw__Size(){
	return sizeof(b2Draw);
}
void b2Draw_AppendFlags(void* cls, unsigned int a){
	((b2Draw*)cls)->AppendFlags(((unsigned int)a));
}
void b2Draw_ClearFlags(void* cls, unsigned int a){
	((b2Draw*)cls)->ClearFlags(((unsigned int)a));
}
void b2Draw_SetFlags(void* cls, unsigned int a){
	((b2Draw*)cls)->SetFlags(((unsigned int)a));
}
unsigned int b2Draw_GetFlags(void* cls){
	return ((b2Draw*)cls)->GetFlags();
}

//
// Begin class 'b2Vec2'
//
void* b2Vec2__Create0(){
	return new b2Vec2();
}
void* b2Vec2__Create1(float a, float b){
	return new b2Vec2(((float)a), ((float)b));
}
void* b2Vec2__Create2(void* a){
	return new b2Vec2(*((b2Vec2*)a));
}
void* b2Vec2__CreateArray(int n){
	return new b2Vec2[n];
}
void b2Vec2__Destroy(void* cls){
	delete (b2Vec2*)cls;
}
void b2Vec2__DestroyArray(void* arr){
	delete[] (b2Vec2*)arr;
}
unsigned int b2Vec2__Size(){
	return sizeof(b2Vec2);
}
float b2Vec2_Normalize(void* cls){
	return ((b2Vec2*)cls)->Normalize();
}
float b2Vec2_LengthSquared(void* cls){
	return ((b2Vec2*)cls)->LengthSquared();
}
void b2Vec2_Set(void* cls, float a, float b){
	((b2Vec2*)cls)->Set(((float)a), ((float)b));
}
unsigned char b2Vec2_IsValid(void* cls){
	return ((b2Vec2*)cls)->IsValid();
}
void* b2Vec2_Skew(void* cls){
	return new b2Vec2(((b2Vec2*)cls)->Skew());
}
void b2Vec2_SetZero(void* cls){
	((b2Vec2*)cls)->SetZero();
}
float b2Vec2_Length(void* cls){
	return ((b2Vec2*)cls)->Length();
}
float b2Vec2__Get_X(void* cls){
	return ((b2Vec2*)cls)->x;
}
void b2Vec2__Set_X(void* cls, float v){
	((b2Vec2*)cls)->x = ((float)v);
}
float b2Vec2__Get_Y(void* cls){
	return ((b2Vec2*)cls)->y;
}
void b2Vec2__Set_Y(void* cls, float v){
	((b2Vec2*)cls)->y = ((float)v);
}

//
// Begin class 'b2PulleyJointDef'
//
void* b2PulleyJointDef__Create(){
	return new b2PulleyJointDef();
}
void* b2PulleyJointDef__CreateArray(int n){
	return new b2PulleyJointDef[n];
}
void b2PulleyJointDef__Destroy(void* cls){
	delete (b2PulleyJointDef*)cls;
}
void b2PulleyJointDef__DestroyArray(void* arr){
	delete[] (b2PulleyJointDef*)arr;
}
unsigned int b2PulleyJointDef__Size(){
	return sizeof(b2PulleyJointDef);
}
void b2PulleyJointDef_Initialize(void* cls, void* a, void* b, void* c, void* d, void* e, void* f, float g){
	((b2PulleyJointDef*)cls)->Initialize(((b2Body*)a), ((b2Body*)b), *((b2Vec2*)c), *((b2Vec2*)d), *((b2Vec2*)e), *((b2Vec2*)f), ((float)g));
}
void* b2PulleyJointDef__Get_GroundAnchorA(void* cls){
	return &((b2PulleyJointDef*)cls)->groundAnchorA;
}
void b2PulleyJointDef__Set_GroundAnchorA(void* cls, void* v){
	((b2PulleyJointDef*)cls)->groundAnchorA = *((b2Vec2*)v);
}
void* b2PulleyJointDef__Get_GroundAnchorB(void* cls){
	return &((b2PulleyJointDef*)cls)->groundAnchorB;
}
void b2PulleyJointDef__Set_GroundAnchorB(void* cls, void* v){
	((b2PulleyJointDef*)cls)->groundAnchorB = *((b2Vec2*)v);
}
void* b2PulleyJointDef__Get_LocalAnchorA(void* cls){
	return &((b2PulleyJointDef*)cls)->localAnchorA;
}
void b2PulleyJointDef__Set_LocalAnchorA(void* cls, void* v){
	((b2PulleyJointDef*)cls)->localAnchorA = *((b2Vec2*)v);
}
void* b2PulleyJointDef__Get_LocalAnchorB(void* cls){
	return &((b2PulleyJointDef*)cls)->localAnchorB;
}
void b2PulleyJointDef__Set_LocalAnchorB(void* cls, void* v){
	((b2PulleyJointDef*)cls)->localAnchorB = *((b2Vec2*)v);
}
float b2PulleyJointDef__Get_LengthA(void* cls){
	return ((b2PulleyJointDef*)cls)->lengthA;
}
void b2PulleyJointDef__Set_LengthA(void* cls, float v){
	((b2PulleyJointDef*)cls)->lengthA = ((float)v);
}
float b2PulleyJointDef__Get_LengthB(void* cls){
	return ((b2PulleyJointDef*)cls)->lengthB;
}
void b2PulleyJointDef__Set_LengthB(void* cls, float v){
	((b2PulleyJointDef*)cls)->lengthB = ((float)v);
}
float b2PulleyJointDef__Get_Ratio(void* cls){
	return ((b2PulleyJointDef*)cls)->ratio;
}
void b2PulleyJointDef__Set_Ratio(void* cls, float v){
	((b2PulleyJointDef*)cls)->ratio = ((float)v);
}

//
// Begin class 'b2FixtureProxy'
//
void* b2FixtureProxy__Create(){
	return new b2FixtureProxy;
}
void* b2FixtureProxy__CreateArray(int n){
	return new b2FixtureProxy[n];
}
void b2FixtureProxy__Destroy(void* cls){
	delete (b2FixtureProxy*)cls;
}
void b2FixtureProxy__DestroyArray(void* arr){
	delete[] (b2FixtureProxy*)arr;
}
unsigned int b2FixtureProxy__Size(){
	return sizeof(b2FixtureProxy);
}
void* b2FixtureProxy__Get_Aabb(void* cls){
	return &((b2FixtureProxy*)cls)->aabb;
}
void b2FixtureProxy__Set_Aabb(void* cls, void* v){
	((b2FixtureProxy*)cls)->aabb = *((b2AABB*)v);
}
int b2FixtureProxy__Get_ChildIndex(void* cls){
	return ((b2FixtureProxy*)cls)->childIndex;
}
void b2FixtureProxy__Set_ChildIndex(void* cls, int v){
	((b2FixtureProxy*)cls)->childIndex = ((int)v);
}
int b2FixtureProxy__Get_ProxyId(void* cls){
	return ((b2FixtureProxy*)cls)->proxyId;
}
void b2FixtureProxy__Set_ProxyId(void* cls, int v){
	((b2FixtureProxy*)cls)->proxyId = ((int)v);
}

//
// Begin class 'b2DistanceInput'
//
void* b2DistanceInput__Create(){
	return new b2DistanceInput;
}
void* b2DistanceInput__CreateArray(int n){
	return new b2DistanceInput[n];
}
void b2DistanceInput__Destroy(void* cls){
	delete (b2DistanceInput*)cls;
}
void b2DistanceInput__DestroyArray(void* arr){
	delete[] (b2DistanceInput*)arr;
}
unsigned int b2DistanceInput__Size(){
	return sizeof(b2DistanceInput);
}
void* b2DistanceInput__Get_ProxyA(void* cls){
	return &((b2DistanceInput*)cls)->proxyA;
}
void b2DistanceInput__Set_ProxyA(void* cls, void* v){
	((b2DistanceInput*)cls)->proxyA = *((b2DistanceProxy*)v);
}
void* b2DistanceInput__Get_ProxyB(void* cls){
	return &((b2DistanceInput*)cls)->proxyB;
}
void b2DistanceInput__Set_ProxyB(void* cls, void* v){
	((b2DistanceInput*)cls)->proxyB = *((b2DistanceProxy*)v);
}
void* b2DistanceInput__Get_TransformA(void* cls){
	return &((b2DistanceInput*)cls)->transformA;
}
void b2DistanceInput__Set_TransformA(void* cls, void* v){
	((b2DistanceInput*)cls)->transformA = *((b2Transform*)v);
}
void* b2DistanceInput__Get_TransformB(void* cls){
	return &((b2DistanceInput*)cls)->transformB;
}
void b2DistanceInput__Set_TransformB(void* cls, void* v){
	((b2DistanceInput*)cls)->transformB = *((b2Transform*)v);
}
unsigned char b2DistanceInput__Get_UseRadii(void* cls){
	return ((b2DistanceInput*)cls)->useRadii;
}
void b2DistanceInput__Set_UseRadii(void* cls, unsigned char v){
	((b2DistanceInput*)cls)->useRadii = ((unsigned char)v);
}

//
// Begin class 'b2GearJoint'
//
void b2GearJoint__Destroy(void* cls){
	delete (b2GearJoint*)cls;
}
void b2GearJoint__DestroyArray(void* arr){
	delete[] (b2GearJoint*)arr;
}
unsigned int b2GearJoint__Size(){
	return sizeof(b2GearJoint);
}
void* b2GearJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2GearJoint*)cls)->GetAnchorA());
}
float b2GearJoint_GetReactionTorque(void* cls, float a){
	return ((b2GearJoint*)cls)->GetReactionTorque(((float)a));
}
void b2GearJoint_SetRatio(void* cls, float a){
	((b2GearJoint*)cls)->SetRatio(((float)a));
}
float b2GearJoint_GetRatio(void* cls){
	return ((b2GearJoint*)cls)->GetRatio();
}
void* b2GearJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2GearJoint*)cls)->GetReactionForce(((float)a)));
}
void* b2GearJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2GearJoint*)cls)->GetAnchorB());
}

//
// Begin class 'b2SimplexCache'
//
void* b2SimplexCache__Create(){
	return new b2SimplexCache;
}
void* b2SimplexCache__CreateArray(int n){
	return new b2SimplexCache[n];
}
void b2SimplexCache__Destroy(void* cls){
	delete (b2SimplexCache*)cls;
}
void b2SimplexCache__DestroyArray(void* arr){
	delete[] (b2SimplexCache*)arr;
}
unsigned int b2SimplexCache__Size(){
	return sizeof(b2SimplexCache);
}
float b2SimplexCache__Get_Metric(void* cls){
	return ((b2SimplexCache*)cls)->metric;
}
void b2SimplexCache__Set_Metric(void* cls, float v){
	((b2SimplexCache*)cls)->metric = ((float)v);
}
unsigned short b2SimplexCache__Get_Count(void* cls){
	return ((b2SimplexCache*)cls)->count;
}
void b2SimplexCache__Set_Count(void* cls, unsigned short v){
	((b2SimplexCache*)cls)->count = ((unsigned short)v);
}

//
// Begin class 'b2Rot'
//
void* b2Rot__Create0(){
	return new b2Rot();
}
void* b2Rot__Create1(float a){
	return new b2Rot(((float)a));
}
void* b2Rot__CreateArray(int n){
	return new b2Rot[n];
}
void b2Rot__Destroy(void* cls){
	delete (b2Rot*)cls;
}
void b2Rot__DestroyArray(void* arr){
	delete[] (b2Rot*)arr;
}
unsigned int b2Rot__Size(){
	return sizeof(b2Rot);
}
void b2Rot_Set(void* cls, float a){
	((b2Rot*)cls)->Set(((float)a));
}
void* b2Rot_GetXAxis(void* cls){
	return new b2Vec2(((b2Rot*)cls)->GetXAxis());
}
void b2Rot_SetIdentity(void* cls){
	((b2Rot*)cls)->SetIdentity();
}
void* b2Rot_GetYAxis(void* cls){
	return new b2Vec2(((b2Rot*)cls)->GetYAxis());
}
float b2Rot_GetAngle(void* cls){
	return ((b2Rot*)cls)->GetAngle();
}
float b2Rot__Get_S(void* cls){
	return ((b2Rot*)cls)->s;
}
void b2Rot__Set_S(void* cls, float v){
	((b2Rot*)cls)->s = ((float)v);
}
float b2Rot__Get_C(void* cls){
	return ((b2Rot*)cls)->c;
}
void b2Rot__Set_C(void* cls, float v){
	((b2Rot*)cls)->c = ((float)v);
}

//
// Begin class 'b2DistanceProxy'
//
void* b2DistanceProxy__Create(){
	return new b2DistanceProxy();
}
void* b2DistanceProxy__CreateArray(int n){
	return new b2DistanceProxy[n];
}
void b2DistanceProxy__Destroy(void* cls){
	delete (b2DistanceProxy*)cls;
}
void b2DistanceProxy__DestroyArray(void* arr){
	delete[] (b2DistanceProxy*)arr;
}
unsigned int b2DistanceProxy__Size(){
	return sizeof(b2DistanceProxy);
}
void* b2DistanceProxy_GetVertex(void* cls, int a){
	return const_cast<b2Vec2*>(&((b2DistanceProxy*)cls)->GetVertex(((int)a)));
}
void* b2DistanceProxy_GetSupportVertex(void* cls, void* a){
	return const_cast<b2Vec2*>(&((b2DistanceProxy*)cls)->GetSupportVertex(*((b2Vec2*)a)));
}
void b2DistanceProxy_Set(void* cls, void* a, int b){
	((b2DistanceProxy*)cls)->Set(((b2Shape*)a), ((int)b));
}
int b2DistanceProxy_GetVertexCount(void* cls){
	return ((b2DistanceProxy*)cls)->GetVertexCount();
}
int b2DistanceProxy_GetSupport(void* cls, void* a){
	return ((b2DistanceProxy*)cls)->GetSupport(*((b2Vec2*)a));
}
void* b2DistanceProxy__Get_MVertices(void* cls){
	return const_cast<b2Vec2*>(((b2DistanceProxy*)cls)->m_vertices);
}
void b2DistanceProxy__Set_MVertices(void* cls, void* v){
	((b2DistanceProxy*)cls)->m_vertices = ((b2Vec2*)v);
}
int b2DistanceProxy__Get_MCount(void* cls){
	return ((b2DistanceProxy*)cls)->m_count;
}
void b2DistanceProxy__Set_MCount(void* cls, int v){
	((b2DistanceProxy*)cls)->m_count = ((int)v);
}
float b2DistanceProxy__Get_MRadius(void* cls){
	return ((b2DistanceProxy*)cls)->m_radius;
}
void b2DistanceProxy__Set_MRadius(void* cls, float v){
	((b2DistanceProxy*)cls)->m_radius = ((float)v);
}

//
// Begin class 'b2MouseJoint'
//
void b2MouseJoint__Destroy(void* cls){
	delete (b2MouseJoint*)cls;
}
void b2MouseJoint__DestroyArray(void* arr){
	delete[] (b2MouseJoint*)arr;
}
unsigned int b2MouseJoint__Size(){
	return sizeof(b2MouseJoint);
}
void b2MouseJoint_SetDampingRatio(void* cls, float a){
	((b2MouseJoint*)cls)->SetDampingRatio(((float)a));
}
void* b2MouseJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2MouseJoint*)cls)->GetAnchorA());
}
float b2MouseJoint_GetReactionTorque(void* cls, float a){
	return ((b2MouseJoint*)cls)->GetReactionTorque(((float)a));
}
void b2MouseJoint_SetFrequency(void* cls, float a){
	((b2MouseJoint*)cls)->SetFrequency(((float)a));
}
float b2MouseJoint_GetDampingRatio(void* cls){
	return ((b2MouseJoint*)cls)->GetDampingRatio();
}
void b2MouseJoint_SetTarget(void* cls, void* a){
	((b2MouseJoint*)cls)->SetTarget(*((b2Vec2*)a));
}
void b2MouseJoint_SetMaxForce(void* cls, float a){
	((b2MouseJoint*)cls)->SetMaxForce(((float)a));
}
float b2MouseJoint_GetFrequency(void* cls){
	return ((b2MouseJoint*)cls)->GetFrequency();
}
void* b2MouseJoint_GetTarget(void* cls){
	return const_cast<b2Vec2*>(&((b2MouseJoint*)cls)->GetTarget());
}
float b2MouseJoint_GetMaxForce(void* cls){
	return ((b2MouseJoint*)cls)->GetMaxForce();
}
void* b2MouseJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2MouseJoint*)cls)->GetAnchorB());
}
void* b2MouseJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2MouseJoint*)cls)->GetReactionForce(((float)a)));
}

//
// Begin class 'b2WheelJointDef'
//
void* b2WheelJointDef__Create(){
	return new b2WheelJointDef();
}
void* b2WheelJointDef__CreateArray(int n){
	return new b2WheelJointDef[n];
}
void b2WheelJointDef__Destroy(void* cls){
	delete (b2WheelJointDef*)cls;
}
void b2WheelJointDef__DestroyArray(void* arr){
	delete[] (b2WheelJointDef*)arr;
}
unsigned int b2WheelJointDef__Size(){
	return sizeof(b2WheelJointDef);
}
void b2WheelJointDef_Initialize(void* cls, void* a, void* b, void* c, void* d){
	((b2WheelJointDef*)cls)->Initialize(((b2Body*)a), ((b2Body*)b), *((b2Vec2*)c), *((b2Vec2*)d));
}
void* b2WheelJointDef__Get_LocalAnchorA(void* cls){
	return &((b2WheelJointDef*)cls)->localAnchorA;
}
void b2WheelJointDef__Set_LocalAnchorA(void* cls, void* v){
	((b2WheelJointDef*)cls)->localAnchorA = *((b2Vec2*)v);
}
void* b2WheelJointDef__Get_LocalAnchorB(void* cls){
	return &((b2WheelJointDef*)cls)->localAnchorB;
}
void b2WheelJointDef__Set_LocalAnchorB(void* cls, void* v){
	((b2WheelJointDef*)cls)->localAnchorB = *((b2Vec2*)v);
}
void* b2WheelJointDef__Get_LocalAxisA(void* cls){
	return &((b2WheelJointDef*)cls)->localAxisA;
}
void b2WheelJointDef__Set_LocalAxisA(void* cls, void* v){
	((b2WheelJointDef*)cls)->localAxisA = *((b2Vec2*)v);
}
unsigned char b2WheelJointDef__Get_EnableMotor(void* cls){
	return ((b2WheelJointDef*)cls)->enableMotor;
}
void b2WheelJointDef__Set_EnableMotor(void* cls, unsigned char v){
	((b2WheelJointDef*)cls)->enableMotor = ((unsigned char)v);
}
float b2WheelJointDef__Get_MaxMotorTorque(void* cls){
	return ((b2WheelJointDef*)cls)->maxMotorTorque;
}
void b2WheelJointDef__Set_MaxMotorTorque(void* cls, float v){
	((b2WheelJointDef*)cls)->maxMotorTorque = ((float)v);
}
float b2WheelJointDef__Get_MotorSpeed(void* cls){
	return ((b2WheelJointDef*)cls)->motorSpeed;
}
void b2WheelJointDef__Set_MotorSpeed(void* cls, float v){
	((b2WheelJointDef*)cls)->motorSpeed = ((float)v);
}
float b2WheelJointDef__Get_FrequencyHz(void* cls){
	return ((b2WheelJointDef*)cls)->frequencyHz;
}
void b2WheelJointDef__Set_FrequencyHz(void* cls, float v){
	((b2WheelJointDef*)cls)->frequencyHz = ((float)v);
}
float b2WheelJointDef__Get_DampingRatio(void* cls){
	return ((b2WheelJointDef*)cls)->dampingRatio;
}
void b2WheelJointDef__Set_DampingRatio(void* cls, float v){
	((b2WheelJointDef*)cls)->dampingRatio = ((float)v);
}

//
// Begin class 'b2Timer'
//
void* b2Timer__Create(){
	return new b2Timer();
}
void* b2Timer__CreateArray(int n){
	return new b2Timer[n];
}
void b2Timer__Destroy(void* cls){
	delete (b2Timer*)cls;
}
void b2Timer__DestroyArray(void* arr){
	delete[] (b2Timer*)arr;
}
unsigned int b2Timer__Size(){
	return sizeof(b2Timer);
}
void b2Timer_Reset(void* cls){
	((b2Timer*)cls)->Reset();
}
float b2Timer_GetMilliseconds(void* cls){
	return ((b2Timer*)cls)->GetMilliseconds();
}

//
// Begin class 'b2Transform'
//
void* b2Transform__Create0(){
	return new b2Transform();
}
void* b2Transform__Create1(void* a, void* b){
	return new b2Transform(*((b2Vec2*)a), *((b2Rot*)b));
}
void* b2Transform__CreateArray(int n){
	return new b2Transform[n];
}
void b2Transform__Destroy(void* cls){
	delete (b2Transform*)cls;
}
void b2Transform__DestroyArray(void* arr){
	delete[] (b2Transform*)arr;
}
unsigned int b2Transform__Size(){
	return sizeof(b2Transform);
}
void b2Transform_Set(void* cls, void* a, float b){
	((b2Transform*)cls)->Set(*((b2Vec2*)a), ((float)b));
}
void b2Transform_SetIdentity(void* cls){
	((b2Transform*)cls)->SetIdentity();
}
void* b2Transform__Get_P(void* cls){
	return &((b2Transform*)cls)->p;
}
void b2Transform__Set_P(void* cls, void* v){
	((b2Transform*)cls)->p = *((b2Vec2*)v);
}
void* b2Transform__Get_Q(void* cls){
	return &((b2Transform*)cls)->q;
}
void b2Transform__Set_Q(void* cls, void* v){
	((b2Transform*)cls)->q = *((b2Rot*)v);
}

//
// Begin class 'b2DynamicTree'
//
void* b2DynamicTree__Create(){
	return new b2DynamicTree();
}
void* b2DynamicTree__CreateArray(int n){
	return new b2DynamicTree[n];
}
void b2DynamicTree__Destroy(void* cls){
	delete (b2DynamicTree*)cls;
}
void b2DynamicTree__DestroyArray(void* arr){
	delete[] (b2DynamicTree*)arr;
}
unsigned int b2DynamicTree__Size(){
	return sizeof(b2DynamicTree);
}
void* b2DynamicTree_GetFatAABB(void* cls, int a){
	return const_cast<b2AABB*>(&((b2DynamicTree*)cls)->GetFatAABB(((int)a)));
}
void* b2DynamicTree_GetUserData(void* cls, int a){
	return ((b2DynamicTree*)cls)->GetUserData(((int)a));
}
int b2DynamicTree_GetMaxBalance(void* cls){
	return ((b2DynamicTree*)cls)->GetMaxBalance();
}
int b2DynamicTree_GetHeight(void* cls){
	return ((b2DynamicTree*)cls)->GetHeight();
}
float b2DynamicTree_GetAreaRatio(void* cls){
	return ((b2DynamicTree*)cls)->GetAreaRatio();
}
void b2DynamicTree_RebuildBottomUp(void* cls){
	((b2DynamicTree*)cls)->RebuildBottomUp();
}
int b2DynamicTree_CreateProxy(void* cls, void* a, void* b){
	return ((b2DynamicTree*)cls)->CreateProxy(*((b2AABB*)a), ((void*)b));
}
unsigned char b2DynamicTree_MoveProxy(void* cls, int a, void* b, void* c){
	return ((b2DynamicTree*)cls)->MoveProxy(((int)a), *((b2AABB*)b), *((b2Vec2*)c));
}
void b2DynamicTree_Validate(void* cls){
	((b2DynamicTree*)cls)->Validate();
}
void b2DynamicTree_DestroyProxy(void* cls, int a){
	((b2DynamicTree*)cls)->DestroyProxy(((int)a));
}

//
// Begin class 'b2Mat22'
//
void* b2Mat22__Create0(){
	return new b2Mat22();
}
void* b2Mat22__Create1(void* a, void* b){
	return new b2Mat22(*((b2Vec2*)a), *((b2Vec2*)b));
}
void* b2Mat22__Create2(float a, float b, float c, float d){
	return new b2Mat22(((float)a), ((float)b), ((float)c), ((float)d));
}
void* b2Mat22__Create3(void* a){
	return new b2Mat22(*((b2Mat22*)a));
}
void* b2Mat22__CreateArray(int n){
	return new b2Mat22[n];
}
void b2Mat22__Destroy(void* cls){
	delete (b2Mat22*)cls;
}
void b2Mat22__DestroyArray(void* arr){
	delete[] (b2Mat22*)arr;
}
unsigned int b2Mat22__Size(){
	return sizeof(b2Mat22);
}
void b2Mat22_SetZero(void* cls){
	((b2Mat22*)cls)->SetZero();
}
void* b2Mat22_GetInverse(void* cls){
	return new b2Mat22(((b2Mat22*)cls)->GetInverse());
}
void b2Mat22_Set(void* cls, void* a, void* b){
	((b2Mat22*)cls)->Set(*((b2Vec2*)a), *((b2Vec2*)b));
}
void* b2Mat22_Solve(void* cls, void* a){
	return new b2Vec2(((b2Mat22*)cls)->Solve(*((b2Vec2*)a)));
}
void b2Mat22_SetIdentity(void* cls){
	((b2Mat22*)cls)->SetIdentity();
}
void* b2Mat22__Get_Ex(void* cls){
	return &((b2Mat22*)cls)->ex;
}
void b2Mat22__Set_Ex(void* cls, void* v){
	((b2Mat22*)cls)->ex = *((b2Vec2*)v);
}
void* b2Mat22__Get_Ey(void* cls){
	return &((b2Mat22*)cls)->ey;
}
void b2Mat22__Set_Ey(void* cls, void* v){
	((b2Mat22*)cls)->ey = *((b2Vec2*)v);
}

//
// Begin class 'b2Velocity'
//
void* b2Velocity__Create(){
	return new b2Velocity;
}
void* b2Velocity__CreateArray(int n){
	return new b2Velocity[n];
}
void b2Velocity__Destroy(void* cls){
	delete (b2Velocity*)cls;
}
void b2Velocity__DestroyArray(void* arr){
	delete[] (b2Velocity*)arr;
}
unsigned int b2Velocity__Size(){
	return sizeof(b2Velocity);
}
void* b2Velocity__Get_V(void* cls){
	return &((b2Velocity*)cls)->v;
}
void b2Velocity__Set_V(void* cls, void* v){
	((b2Velocity*)cls)->v = *((b2Vec2*)v);
}
float b2Velocity__Get_W(void* cls){
	return ((b2Velocity*)cls)->w;
}
void b2Velocity__Set_W(void* cls, float v){
	((b2Velocity*)cls)->w = ((float)v);
}

//
// Begin class 'b2StackAllocator'
//
void* b2StackAllocator__Create(){
	return new b2StackAllocator();
}
void* b2StackAllocator__CreateArray(int n){
	return new b2StackAllocator[n];
}
void b2StackAllocator__Destroy(void* cls){
	delete (b2StackAllocator*)cls;
}
void b2StackAllocator__DestroyArray(void* arr){
	delete[] (b2StackAllocator*)arr;
}
unsigned int b2StackAllocator__Size(){
	return sizeof(b2StackAllocator);
}
int b2StackAllocator_GetMaxAllocation(void* cls){
	return ((b2StackAllocator*)cls)->GetMaxAllocation();
}
void* b2StackAllocator_Allocate(void* cls, int a){
	return ((b2StackAllocator*)cls)->Allocate(((int)a));
}
void b2StackAllocator_Free(void* cls, void* a){
	((b2StackAllocator*)cls)->Free(((void*)a));
}

//
// Begin class 'b2RopeJoint'
//
void b2RopeJoint__Destroy(void* cls){
	delete (b2RopeJoint*)cls;
}
void b2RopeJoint__DestroyArray(void* arr){
	delete[] (b2RopeJoint*)arr;
}
unsigned int b2RopeJoint__Size(){
	return sizeof(b2RopeJoint);
}
void* b2RopeJoint_GetAnchorA(void* cls){
	return new b2Vec2(((b2RopeJoint*)cls)->GetAnchorA());
}
float b2RopeJoint_GetReactionTorque(void* cls, float a){
	return ((b2RopeJoint*)cls)->GetReactionTorque(((float)a));
}
float b2RopeJoint_GetMaxLength(void* cls){
	return ((b2RopeJoint*)cls)->GetMaxLength();
}
void* b2RopeJoint_GetAnchorB(void* cls){
	return new b2Vec2(((b2RopeJoint*)cls)->GetAnchorB());
}
void* b2RopeJoint_GetReactionForce(void* cls, float a){
	return new b2Vec2(((b2RopeJoint*)cls)->GetReactionForce(((float)a)));
}
unsigned int b2RopeJoint_GetLimitState(void* cls){
	return ((b2RopeJoint*)cls)->GetLimitState();
}

//
// Begin class 'b2WorldManifold'
//
void* b2WorldManifold__Create(){
	return new b2WorldManifold;
}
void* b2WorldManifold__CreateArray(int n){
	return new b2WorldManifold[n];
}
void b2WorldManifold__Destroy(void* cls){
	delete (b2WorldManifold*)cls;
}
void b2WorldManifold__DestroyArray(void* arr){
	delete[] (b2WorldManifold*)arr;
}
unsigned int b2WorldManifold__Size(){
	return sizeof(b2WorldManifold);
}
void b2WorldManifold_Initialize(void* cls, void* a, void* b, float c, void* d, float e){
	((b2WorldManifold*)cls)->Initialize(((b2Manifold*)a), *((b2Transform*)b), ((float)c), *((b2Transform*)d), ((float)e));
}
void* b2WorldManifold__Get_Normal(void* cls){
	return &((b2WorldManifold*)cls)->normal;
}
void b2WorldManifold__Set_Normal(void* cls, void* v){
	((b2WorldManifold*)cls)->normal = *((b2Vec2*)v);
}

//
// Begin class 'b2Filter'
//
void* b2Filter__Create(){
	return new b2Filter;
}
void* b2Filter__CreateArray(int n){
	return new b2Filter[n];
}
void b2Filter__Destroy(void* cls){
	delete (b2Filter*)cls;
}
void b2Filter__DestroyArray(void* arr){
	delete[] (b2Filter*)arr;
}
unsigned int b2Filter__Size(){
	return sizeof(b2Filter);
}
unsigned short b2Filter__Get_CategoryBits(void* cls){
	return ((b2Filter*)cls)->categoryBits;
}
void b2Filter__Set_CategoryBits(void* cls, unsigned short v){
	((b2Filter*)cls)->categoryBits = ((unsigned short)v);
}
unsigned short b2Filter__Get_MaskBits(void* cls){
	return ((b2Filter*)cls)->maskBits;
}
void b2Filter__Set_MaskBits(void* cls, unsigned short v){
	((b2Filter*)cls)->maskBits = ((unsigned short)v);
}
short b2Filter__Get_GroupIndex(void* cls){
	return ((b2Filter*)cls)->groupIndex;
}
void b2Filter__Set_GroupIndex(void* cls, short v){
	((b2Filter*)cls)->groupIndex = ((short)v);
}

//
// Begin class 'b2ContactManager'
//
void* b2ContactManager__Create(){
	return new b2ContactManager();
}
void* b2ContactManager__CreateArray(int n){
	return new b2ContactManager[n];
}
void b2ContactManager__Destroy(void* cls){
	delete (b2ContactManager*)cls;
}
void b2ContactManager__DestroyArray(void* arr){
	delete[] (b2ContactManager*)arr;
}
unsigned int b2ContactManager__Size(){
	return sizeof(b2ContactManager);
}
void b2ContactManager_FindNewContacts(void* cls){
	((b2ContactManager*)cls)->FindNewContacts();
}
void b2ContactManager_Collide(void* cls){
	((b2ContactManager*)cls)->Collide();
}
void b2ContactManager_AddPair(void* cls, void* a, void* b){
	((b2ContactManager*)cls)->AddPair(((void*)a), ((void*)b));
}
void b2ContactManager_Destroy(void* cls, void* a){
	((b2ContactManager*)cls)->Destroy(((b2Contact*)a));
}
void* b2ContactManager__Get_MBroadPhase(void* cls){
	return &((b2ContactManager*)cls)->m_broadPhase;
}
void b2ContactManager__Set_MBroadPhase(void* cls, void* v){
	((b2ContactManager*)cls)->m_broadPhase = *((b2BroadPhase*)v);
}
int b2ContactManager__Get_MContactCount(void* cls){
	return ((b2ContactManager*)cls)->m_contactCount;
}
void b2ContactManager__Set_MContactCount(void* cls, int v){
	((b2ContactManager*)cls)->m_contactCount = ((int)v);
}
void* b2ContactManager__Get_MContactFilter(void* cls){
	return ((b2ContactManager*)cls)->m_contactFilter;
}
void b2ContactManager__Set_MContactFilter(void* cls, void* v){
	((b2ContactManager*)cls)->m_contactFilter = ((b2ContactFilter*)v);
}
void* b2ContactManager__Get_MContactListener(void* cls){
	return ((b2ContactManager*)cls)->m_contactListener;
}
void b2ContactManager__Set_MContactListener(void* cls, void* v){
	((b2ContactManager*)cls)->m_contactListener = ((b2ContactListener*)v);
}
void* b2ContactManager__Get_MAllocator(void* cls){
	return ((b2ContactManager*)cls)->m_allocator;
}
void b2ContactManager__Set_MAllocator(void* cls, void* v){
	((b2ContactManager*)cls)->m_allocator = ((b2BlockAllocator*)v);
}

//
// Begin class 'b2RayCastInput'
//
void* b2RayCastInput__Create(){
	return new b2RayCastInput;
}
void* b2RayCastInput__CreateArray(int n){
	return new b2RayCastInput[n];
}
void b2RayCastInput__Destroy(void* cls){
	delete (b2RayCastInput*)cls;
}
void b2RayCastInput__DestroyArray(void* arr){
	delete[] (b2RayCastInput*)arr;
}
unsigned int b2RayCastInput__Size(){
	return sizeof(b2RayCastInput);
}
void* b2RayCastInput__Get_P1(void* cls){
	return &((b2RayCastInput*)cls)->p1;
}
void b2RayCastInput__Set_P1(void* cls, void* v){
	((b2RayCastInput*)cls)->p1 = *((b2Vec2*)v);
}
void* b2RayCastInput__Get_P2(void* cls){
	return &((b2RayCastInput*)cls)->p2;
}
void b2RayCastInput__Set_P2(void* cls, void* v){
	((b2RayCastInput*)cls)->p2 = *((b2Vec2*)v);
}
float b2RayCastInput__Get_MaxFraction(void* cls){
	return ((b2RayCastInput*)cls)->maxFraction;
}
void b2RayCastInput__Set_MaxFraction(void* cls, float v){
	((b2RayCastInput*)cls)->maxFraction = ((float)v);
}

//
// Begin class 'b2Color'
//
void* b2Color__Create0(){
	return new b2Color();
}
void* b2Color__Create1(float a, float b, float c){
	return new b2Color(((float)a), ((float)b), ((float)c));
}
void* b2Color__CreateArray(int n){
	return new b2Color[n];
}
void b2Color__Destroy(void* cls){
	delete (b2Color*)cls;
}
void b2Color__DestroyArray(void* arr){
	delete[] (b2Color*)arr;
}
unsigned int b2Color__Size(){
	return sizeof(b2Color);
}
void b2Color_Set(void* cls, float a, float b, float c){
	((b2Color*)cls)->Set(((float)a), ((float)b), ((float)c));
}
float b2Color__Get_R(void* cls){
	return ((b2Color*)cls)->r;
}
void b2Color__Set_R(void* cls, float v){
	((b2Color*)cls)->r = ((float)v);
}
float b2Color__Get_G(void* cls){
	return ((b2Color*)cls)->g;
}
void b2Color__Set_G(void* cls, float v){
	((b2Color*)cls)->g = ((float)v);
}
float b2Color__Get_B(void* cls){
	return ((b2Color*)cls)->b;
}
void b2Color__Set_B(void* cls, float v){
	((b2Color*)cls)->b = ((float)v);
}

//
// Begin class 'b2EdgeShape'
//
void* b2EdgeShape__Create(){
	return new b2EdgeShape();
}
void* b2EdgeShape__CreateArray(int n){
	return new b2EdgeShape[n];
}
void b2EdgeShape__Destroy(void* cls){
	delete (b2EdgeShape*)cls;
}
void b2EdgeShape__DestroyArray(void* arr){
	delete[] (b2EdgeShape*)arr;
}
unsigned int b2EdgeShape__Size(){
	return sizeof(b2EdgeShape);
}
void b2EdgeShape_Set(void* cls, void* a, void* b){
	((b2EdgeShape*)cls)->Set(*((b2Vec2*)a), *((b2Vec2*)b));
}
void b2EdgeShape_ComputeMass(void* cls, void* a, float b){
	((b2EdgeShape*)cls)->ComputeMass(((b2MassData*)a), ((float)b));
}
void* b2EdgeShape_Clone(void* cls, void* a){
	return ((b2EdgeShape*)cls)->Clone(((b2BlockAllocator*)a));
}
unsigned char b2EdgeShape_RayCast(void* cls, void* a, void* b, void* c, int d){
	return ((b2EdgeShape*)cls)->RayCast(((b2RayCastOutput*)a), *((b2RayCastInput*)b), *((b2Transform*)c), ((int)d));
}
void b2EdgeShape_ComputeAABB(void* cls, void* a, void* b, int c){
	((b2EdgeShape*)cls)->ComputeAABB(((b2AABB*)a), *((b2Transform*)b), ((int)c));
}
int b2EdgeShape_GetChildCount(void* cls){
	return ((b2EdgeShape*)cls)->GetChildCount();
}
unsigned char b2EdgeShape_TestPoint(void* cls, void* a, void* b){
	return ((b2EdgeShape*)cls)->TestPoint(*((b2Transform*)a), *((b2Vec2*)b));
}
void* b2EdgeShape__Get_MVertex1(void* cls){
	return &((b2EdgeShape*)cls)->m_vertex1;
}
void b2EdgeShape__Set_MVertex1(void* cls, void* v){
	((b2EdgeShape*)cls)->m_vertex1 = *((b2Vec2*)v);
}
void* b2EdgeShape__Get_MVertex2(void* cls){
	return &((b2EdgeShape*)cls)->m_vertex2;
}
void b2EdgeShape__Set_MVertex2(void* cls, void* v){
	((b2EdgeShape*)cls)->m_vertex2 = *((b2Vec2*)v);
}
void* b2EdgeShape__Get_MVertex0(void* cls){
	return &((b2EdgeShape*)cls)->m_vertex0;
}
void b2EdgeShape__Set_MVertex0(void* cls, void* v){
	((b2EdgeShape*)cls)->m_vertex0 = *((b2Vec2*)v);
}
void* b2EdgeShape__Get_MVertex3(void* cls){
	return &((b2EdgeShape*)cls)->m_vertex3;
}
void b2EdgeShape__Set_MVertex3(void* cls, void* v){
	((b2EdgeShape*)cls)->m_vertex3 = *((b2Vec2*)v);
}
unsigned char b2EdgeShape__Get_MHasVertex0(void* cls){
	return ((b2EdgeShape*)cls)->m_hasVertex0;
}
void b2EdgeShape__Set_MHasVertex0(void* cls, unsigned char v){
	((b2EdgeShape*)cls)->m_hasVertex0 = ((unsigned char)v);
}
unsigned char b2EdgeShape__Get_MHasVertex3(void* cls){
	return ((b2EdgeShape*)cls)->m_hasVertex3;
}
void b2EdgeShape__Set_MHasVertex3(void* cls, unsigned char v){
	((b2EdgeShape*)cls)->m_hasVertex3 = ((unsigned char)v);
}

//
// Begin class 'b2Joint'
//
unsigned int b2Joint__Size(){
	return sizeof(b2Joint);
}
void* b2Joint_GetNext0(void* cls){
	return ((b2Joint*)cls)->GetNext();
}
void* b2Joint_GetNext1(void* cls){
	return const_cast<b2Joint*>(((b2Joint*)cls)->GetNext());
}
void* b2Joint_GetBodyA(void* cls){
	return ((b2Joint*)cls)->GetBodyA();
}
void* b2Joint_GetBodyB(void* cls){
	return ((b2Joint*)cls)->GetBodyB();
}
void* b2Joint_GetUserData(void* cls){
	return ((b2Joint*)cls)->GetUserData();
}
unsigned int b2Joint_GetType(void* cls){
	return ((b2Joint*)cls)->GetType();
}
void b2Joint_SetUserData(void* cls, void* a){
	((b2Joint*)cls)->SetUserData(((void*)a));
}
unsigned char b2Joint_GetCollideConnected(void* cls){
	return ((b2Joint*)cls)->GetCollideConnected();
}
unsigned char b2Joint_IsActive(void* cls){
	return ((b2Joint*)cls)->IsActive();
}

//
// Begin class 'b2JointDef'
//
void* b2JointDef__Create(){
	return new b2JointDef();
}
void* b2JointDef__CreateArray(int n){
	return new b2JointDef[n];
}
void b2JointDef__Destroy(void* cls){
	delete (b2JointDef*)cls;
}
void b2JointDef__DestroyArray(void* arr){
	delete[] (b2JointDef*)arr;
}
unsigned int b2JointDef__Size(){
	return sizeof(b2JointDef);
}
unsigned int b2JointDef__Get_Type(void* cls){
	return ((b2JointDef*)cls)->type;
}
void b2JointDef__Set_Type(void* cls, unsigned int v){
	((b2JointDef*)cls)->type = ((b2JointType)v);
}
void* b2JointDef__Get_BodyA(void* cls){
	return ((b2JointDef*)cls)->bodyA;
}
void b2JointDef__Set_BodyA(void* cls, void* v){
	((b2JointDef*)cls)->bodyA = ((b2Body*)v);
}
void* b2JointDef__Get_BodyB(void* cls){
	return ((b2JointDef*)cls)->bodyB;
}
void b2JointDef__Set_BodyB(void* cls, void* v){
	((b2JointDef*)cls)->bodyB = ((b2Body*)v);
}
unsigned char b2JointDef__Get_CollideConnected(void* cls){
	return ((b2JointDef*)cls)->collideConnected;
}
void b2JointDef__Set_CollideConnected(void* cls, unsigned char v){
	((b2JointDef*)cls)->collideConnected = ((unsigned char)v);
}

//
// Begin class 'b2StackEntry'
//
void* b2StackEntry__Create(){
	return new b2StackEntry;
}
void* b2StackEntry__CreateArray(int n){
	return new b2StackEntry[n];
}
void b2StackEntry__Destroy(void* cls){
	delete (b2StackEntry*)cls;
}
void b2StackEntry__DestroyArray(void* arr){
	delete[] (b2StackEntry*)arr;
}
unsigned int b2StackEntry__Size(){
	return sizeof(b2StackEntry);
}
int b2StackEntry__Get_Size(void* cls){
	return ((b2StackEntry*)cls)->size;
}
void b2StackEntry__Set_Size(void* cls, int v){
	((b2StackEntry*)cls)->size = ((int)v);
}
unsigned char b2StackEntry__Get_UsedMalloc(void* cls){
	return ((b2StackEntry*)cls)->usedMalloc;
}
void b2StackEntry__Set_UsedMalloc(void* cls, unsigned char v){
	((b2StackEntry*)cls)->usedMalloc = ((unsigned char)v);
}

//
// Begin class 'b2LoopShape'
//
void* b2LoopShape__Create(){
	return new b2LoopShape();
}
void* b2LoopShape__CreateArray(int n){
	return new b2LoopShape[n];
}
void b2LoopShape__Destroy(void* cls){
	delete (b2LoopShape*)cls;
}
void b2LoopShape__DestroyArray(void* arr){
	delete[] (b2LoopShape*)arr;
}
unsigned int b2LoopShape__Size(){
	return sizeof(b2LoopShape);
}
void* b2LoopShape_GetVertices(void* cls){
	return const_cast<b2Vec2*>(((b2LoopShape*)cls)->GetVertices());
}
void b2LoopShape_ComputeMass(void* cls, void* a, float b){
	((b2LoopShape*)cls)->ComputeMass(((b2MassData*)a), ((float)b));
}
void b2LoopShape_Create(void* cls, void* a, int b){
	((b2LoopShape*)cls)->Create(((b2Vec2*)a), ((int)b));
}
void* b2LoopShape_GetVertex(void* cls, int a){
	return const_cast<b2Vec2*>(&((b2LoopShape*)cls)->GetVertex(((int)a)));
}
void b2LoopShape_GetChildEdge(void* cls, void* a, int b){
	((b2LoopShape*)cls)->GetChildEdge(((b2EdgeShape*)a), ((int)b));
}
unsigned char b2LoopShape_RayCast(void* cls, void* a, void* b, void* c, int d){
	return ((b2LoopShape*)cls)->RayCast(((b2RayCastOutput*)a), *((b2RayCastInput*)b), *((b2Transform*)c), ((int)d));
}
void b2LoopShape_ComputeAABB(void* cls, void* a, void* b, int c){
	((b2LoopShape*)cls)->ComputeAABB(((b2AABB*)a), *((b2Transform*)b), ((int)c));
}
int b2LoopShape_GetChildCount(void* cls){
	return ((b2LoopShape*)cls)->GetChildCount();
}
unsigned char b2LoopShape_TestPoint(void* cls, void* a, void* b){
	return ((b2LoopShape*)cls)->TestPoint(*((b2Transform*)a), *((b2Vec2*)b));
}
int b2LoopShape_GetCount(void* cls){
	return ((b2LoopShape*)cls)->GetCount();
}
void* b2LoopShape_Clone(void* cls, void* a){
	return ((b2LoopShape*)cls)->Clone(((b2BlockAllocator*)a));
}

//
// Begin class 'b2DestructionListener'
//
void b2DestructionListener__Destroy(void* cls){
	delete (b2DestructionListener*)cls;
}
void b2DestructionListener__DestroyArray(void* arr){
	delete[] (b2DestructionListener*)arr;
}
unsigned int b2DestructionListener__Size(){
	return sizeof(b2DestructionListener);
}

//
// Begin class 'b2GearJointDef'
//
void* b2GearJointDef__Create(){
	return new b2GearJointDef();
}
void* b2GearJointDef__CreateArray(int n){
	return new b2GearJointDef[n];
}
void b2GearJointDef__Destroy(void* cls){
	delete (b2GearJointDef*)cls;
}
void b2GearJointDef__DestroyArray(void* arr){
	delete[] (b2GearJointDef*)arr;
}
unsigned int b2GearJointDef__Size(){
	return sizeof(b2GearJointDef);
}
void* b2GearJointDef__Get_Joint1(void* cls){
	return ((b2GearJointDef*)cls)->joint1;
}
void b2GearJointDef__Set_Joint1(void* cls, void* v){
	((b2GearJointDef*)cls)->joint1 = ((b2Joint*)v);
}
void* b2GearJointDef__Get_Joint2(void* cls){
	return ((b2GearJointDef*)cls)->joint2;
}
void b2GearJointDef__Set_Joint2(void* cls, void* v){
	((b2GearJointDef*)cls)->joint2 = ((b2Joint*)v);
}
float b2GearJointDef__Get_Ratio(void* cls){
	return ((b2GearJointDef*)cls)->ratio;
}
void b2GearJointDef__Set_Ratio(void* cls, float v){
	((b2GearJointDef*)cls)->ratio = ((float)v);
}

//
// Begin class 'b2ContactEdge'
//
void* b2ContactEdge__Create(){
	return new b2ContactEdge;
}
void* b2ContactEdge__CreateArray(int n){
	return new b2ContactEdge[n];
}
void b2ContactEdge__Destroy(void* cls){
	delete (b2ContactEdge*)cls;
}
void b2ContactEdge__DestroyArray(void* arr){
	delete[] (b2ContactEdge*)arr;
}
unsigned int b2ContactEdge__Size(){
	return sizeof(b2ContactEdge);
}
void* b2ContactEdge__Get_Other(void* cls){
	return ((b2ContactEdge*)cls)->other;
}
void b2ContactEdge__Set_Other(void* cls, void* v){
	((b2ContactEdge*)cls)->other = ((b2Body*)v);
}
void* b2ContactEdge__Get_Prev(void* cls){
	return ((b2ContactEdge*)cls)->prev;
}
void b2ContactEdge__Set_Prev(void* cls, void* v){
	((b2ContactEdge*)cls)->prev = ((b2ContactEdge*)v);
}
void* b2ContactEdge__Get_Next(void* cls){
	return ((b2ContactEdge*)cls)->next;
}
void b2ContactEdge__Set_Next(void* cls, void* v){
	((b2ContactEdge*)cls)->next = ((b2ContactEdge*)v);
}

//
// Begin class 'b2Manifold'
//
void* b2Manifold__Create(){
	return new b2Manifold;
}
void* b2Manifold__CreateArray(int n){
	return new b2Manifold[n];
}
void b2Manifold__Destroy(void* cls){
	delete (b2Manifold*)cls;
}
void b2Manifold__DestroyArray(void* arr){
	delete[] (b2Manifold*)arr;
}
unsigned int b2Manifold__Size(){
	return sizeof(b2Manifold);
}
void* b2Manifold__Get_LocalNormal(void* cls){
	return &((b2Manifold*)cls)->localNormal;
}
void b2Manifold__Set_LocalNormal(void* cls, void* v){
	((b2Manifold*)cls)->localNormal = *((b2Vec2*)v);
}
void* b2Manifold__Get_LocalPoint(void* cls){
	return &((b2Manifold*)cls)->localPoint;
}
void b2Manifold__Set_LocalPoint(void* cls, void* v){
	((b2Manifold*)cls)->localPoint = *((b2Vec2*)v);
}
unsigned int b2Manifold__Get_Type(void* cls){
	return ((b2Manifold*)cls)->type;
}
void b2Manifold__Set_Type(void* cls, unsigned int v){
	((b2Manifold*)cls)->type = ((b2Manifold::Type)v);
}
int b2Manifold__Get_PointCount(void* cls){
	return ((b2Manifold*)cls)->pointCount;
}
void b2Manifold__Set_PointCount(void* cls, int v){
	((b2Manifold*)cls)->pointCount = ((int)v);
}

//
// Begin class 'b2AABB'
//
void* b2AABB__Create(){
	return new b2AABB;
}
void* b2AABB__CreateArray(int n){
	return new b2AABB[n];
}
void b2AABB__Destroy(void* cls){
	delete (b2AABB*)cls;
}
void b2AABB__DestroyArray(void* arr){
	delete[] (b2AABB*)arr;
}
unsigned int b2AABB__Size(){
	return sizeof(b2AABB);
}
unsigned char b2AABB_IsValid(void* cls){
	return ((b2AABB*)cls)->IsValid();
}
unsigned char b2AABB_Contains(void* cls, void* a){
	return ((b2AABB*)cls)->Contains(*((b2AABB*)a));
}
void* b2AABB_GetExtents(void* cls){
	return new b2Vec2(((b2AABB*)cls)->GetExtents());
}
void* b2AABB_GetCenter(void* cls){
	return new b2Vec2(((b2AABB*)cls)->GetCenter());
}
float b2AABB_GetPerimeter(void* cls){
	return ((b2AABB*)cls)->GetPerimeter();
}
void b2AABB_Combine0(void* cls, void* a){
	((b2AABB*)cls)->Combine(*((b2AABB*)a));
}
void b2AABB_Combine1(void* cls, void* a, void* b){
	((b2AABB*)cls)->Combine(*((b2AABB*)a), *((b2AABB*)b));
}
unsigned char b2AABB_RayCast(void* cls, void* a, void* b){
	return ((b2AABB*)cls)->RayCast(((b2RayCastOutput*)a), *((b2RayCastInput*)b));
}
void* b2AABB__Get_LowerBound(void* cls){
	return &((b2AABB*)cls)->lowerBound;
}
void b2AABB__Set_LowerBound(void* cls, void* v){
	((b2AABB*)cls)->lowerBound = *((b2Vec2*)v);
}
void* b2AABB__Get_UpperBound(void* cls){
	return &((b2AABB*)cls)->upperBound;
}
void b2AABB__Set_UpperBound(void* cls, void* v){
	((b2AABB*)cls)->upperBound = *((b2Vec2*)v);
}

//
// Begin class 'b2FixtureDef'
//
void* b2FixtureDef__Create(){
	return new b2FixtureDef();
}
void* b2FixtureDef__CreateArray(int n){
	return new b2FixtureDef[n];
}
void b2FixtureDef__Destroy(void* cls){
	delete (b2FixtureDef*)cls;
}
void b2FixtureDef__DestroyArray(void* arr){
	delete[] (b2FixtureDef*)arr;
}
unsigned int b2FixtureDef__Size(){
	return sizeof(b2FixtureDef);
}
void* b2FixtureDef__Get_Shape(void* cls){
	return const_cast<b2Shape*>(((b2FixtureDef*)cls)->shape);
}
void b2FixtureDef__Set_Shape(void* cls, void* v){
	((b2FixtureDef*)cls)->shape = ((b2Shape*)v);
}
float b2FixtureDef__Get_Friction(void* cls){
	return ((b2FixtureDef*)cls)->friction;
}
void b2FixtureDef__Set_Friction(void* cls, float v){
	((b2FixtureDef*)cls)->friction = ((float)v);
}
float b2FixtureDef__Get_Restitution(void* cls){
	return ((b2FixtureDef*)cls)->restitution;
}
void b2FixtureDef__Set_Restitution(void* cls, float v){
	((b2FixtureDef*)cls)->restitution = ((float)v);
}
float b2FixtureDef__Get_Density(void* cls){
	return ((b2FixtureDef*)cls)->density;
}
void b2FixtureDef__Set_Density(void* cls, float v){
	((b2FixtureDef*)cls)->density = ((float)v);
}
unsigned char b2FixtureDef__Get_IsSensor(void* cls){
	return ((b2FixtureDef*)cls)->isSensor;
}
void b2FixtureDef__Set_IsSensor(void* cls, unsigned char v){
	((b2FixtureDef*)cls)->isSensor = ((unsigned char)v);
}
void* b2FixtureDef__Get_Filter(void* cls){
	return &((b2FixtureDef*)cls)->filter;
}
void b2FixtureDef__Set_Filter(void* cls, void* v){
	((b2FixtureDef*)cls)->filter = *((b2Filter*)v);
}

//
// Begin class 'b2ManifoldPoint'
//
void* b2ManifoldPoint__Create(){
	return new b2ManifoldPoint;
}
void* b2ManifoldPoint__CreateArray(int n){
	return new b2ManifoldPoint[n];
}
void b2ManifoldPoint__Destroy(void* cls){
	delete (b2ManifoldPoint*)cls;
}
void b2ManifoldPoint__DestroyArray(void* arr){
	delete[] (b2ManifoldPoint*)arr;
}
unsigned int b2ManifoldPoint__Size(){
	return sizeof(b2ManifoldPoint);
}
void* b2ManifoldPoint__Get_LocalPoint(void* cls){
	return &((b2ManifoldPoint*)cls)->localPoint;
}
void b2ManifoldPoint__Set_LocalPoint(void* cls, void* v){
	((b2ManifoldPoint*)cls)->localPoint = *((b2Vec2*)v);
}
float b2ManifoldPoint__Get_NormalImpulse(void* cls){
	return ((b2ManifoldPoint*)cls)->normalImpulse;
}
void b2ManifoldPoint__Set_NormalImpulse(void* cls, float v){
	((b2ManifoldPoint*)cls)->normalImpulse = ((float)v);
}
float b2ManifoldPoint__Get_TangentImpulse(void* cls){
	return ((b2ManifoldPoint*)cls)->tangentImpulse;
}
void b2ManifoldPoint__Set_TangentImpulse(void* cls, float v){
	((b2ManifoldPoint*)cls)->tangentImpulse = ((float)v);
}

//
// Begin class 'b2BodyDef'
//
void* b2BodyDef__Create(){
	return new b2BodyDef();
}
void* b2BodyDef__CreateArray(int n){
	return new b2BodyDef[n];
}
void b2BodyDef__Destroy(void* cls){
	delete (b2BodyDef*)cls;
}
void b2BodyDef__DestroyArray(void* arr){
	delete[] (b2BodyDef*)arr;
}
unsigned int b2BodyDef__Size(){
	return sizeof(b2BodyDef);
}
unsigned int b2BodyDef__Get_Type(void* cls){
	return ((b2BodyDef*)cls)->type;
}
void b2BodyDef__Set_Type(void* cls, unsigned int v){
	((b2BodyDef*)cls)->type = ((b2BodyType)v);
}
void* b2BodyDef__Get_Position(void* cls){
	return &((b2BodyDef*)cls)->position;
}
void b2BodyDef__Set_Position(void* cls, void* v){
	((b2BodyDef*)cls)->position = *((b2Vec2*)v);
}
float b2BodyDef__Get_Angle(void* cls){
	return ((b2BodyDef*)cls)->angle;
}
void b2BodyDef__Set_Angle(void* cls, float v){
	((b2BodyDef*)cls)->angle = ((float)v);
}
void* b2BodyDef__Get_LinearVelocity(void* cls){
	return &((b2BodyDef*)cls)->linearVelocity;
}
void b2BodyDef__Set_LinearVelocity(void* cls, void* v){
	((b2BodyDef*)cls)->linearVelocity = *((b2Vec2*)v);
}
float b2BodyDef__Get_AngularVelocity(void* cls){
	return ((b2BodyDef*)cls)->angularVelocity;
}
void b2BodyDef__Set_AngularVelocity(void* cls, float v){
	((b2BodyDef*)cls)->angularVelocity = ((float)v);
}
float b2BodyDef__Get_LinearDamping(void* cls){
	return ((b2BodyDef*)cls)->linearDamping;
}
void b2BodyDef__Set_LinearDamping(void* cls, float v){
	((b2BodyDef*)cls)->linearDamping = ((float)v);
}
float b2BodyDef__Get_AngularDamping(void* cls){
	return ((b2BodyDef*)cls)->angularDamping;
}
void b2BodyDef__Set_AngularDamping(void* cls, float v){
	((b2BodyDef*)cls)->angularDamping = ((float)v);
}
unsigned char b2BodyDef__Get_AllowSleep(void* cls){
	return ((b2BodyDef*)cls)->allowSleep;
}
void b2BodyDef__Set_AllowSleep(void* cls, unsigned char v){
	((b2BodyDef*)cls)->allowSleep = ((unsigned char)v);
}
unsigned char b2BodyDef__Get_Awake(void* cls){
	return ((b2BodyDef*)cls)->awake;
}
void b2BodyDef__Set_Awake(void* cls, unsigned char v){
	((b2BodyDef*)cls)->awake = ((unsigned char)v);
}
unsigned char b2BodyDef__Get_FixedRotation(void* cls){
	return ((b2BodyDef*)cls)->fixedRotation;
}
void b2BodyDef__Set_FixedRotation(void* cls, unsigned char v){
	((b2BodyDef*)cls)->fixedRotation = ((unsigned char)v);
}
unsigned char b2BodyDef__Get_Bullet(void* cls){
	return ((b2BodyDef*)cls)->bullet;
}
void b2BodyDef__Set_Bullet(void* cls, unsigned char v){
	((b2BodyDef*)cls)->bullet = ((unsigned char)v);
}
unsigned char b2BodyDef__Get_Active(void* cls){
	return ((b2BodyDef*)cls)->active;
}
void b2BodyDef__Set_Active(void* cls, unsigned char v){
	((b2BodyDef*)cls)->active = ((unsigned char)v);
}
float b2BodyDef__Get_GravityScale(void* cls){
	return ((b2BodyDef*)cls)->gravityScale;
}
void b2BodyDef__Set_GravityScale(void* cls, float v){
	((b2BodyDef*)cls)->gravityScale = ((float)v);
}

//
// Begin class 'b2WeldJointDef'
//
void* b2WeldJointDef__Create(){
	return new b2WeldJointDef();
}
void* b2WeldJointDef__CreateArray(int n){
	return new b2WeldJointDef[n];
}
void b2WeldJointDef__Destroy(void* cls){
	delete (b2WeldJointDef*)cls;
}
void b2WeldJointDef__DestroyArray(void* arr){
	delete[] (b2WeldJointDef*)arr;
}
unsigned int b2WeldJointDef__Size(){
	return sizeof(b2WeldJointDef);
}
void b2WeldJointDef_Initialize(void* cls, void* a, void* b, void* c){
	((b2WeldJointDef*)cls)->Initialize(((b2Body*)a), ((b2Body*)b), *((b2Vec2*)c));
}
void* b2WeldJointDef__Get_LocalAnchorA(void* cls){
	return &((b2WeldJointDef*)cls)->localAnchorA;
}
void b2WeldJointDef__Set_LocalAnchorA(void* cls, void* v){
	((b2WeldJointDef*)cls)->localAnchorA = *((b2Vec2*)v);
}
void* b2WeldJointDef__Get_LocalAnchorB(void* cls){
	return &((b2WeldJointDef*)cls)->localAnchorB;
}
void b2WeldJointDef__Set_LocalAnchorB(void* cls, void* v){
	((b2WeldJointDef*)cls)->localAnchorB = *((b2Vec2*)v);
}
float b2WeldJointDef__Get_ReferenceAngle(void* cls){
	return ((b2WeldJointDef*)cls)->referenceAngle;
}
void b2WeldJointDef__Set_ReferenceAngle(void* cls, float v){
	((b2WeldJointDef*)cls)->referenceAngle = ((float)v);
}

//
// Begin class 'b2ClipVertex'
//
void* b2ClipVertex__Create(){
	return new b2ClipVertex;
}
void* b2ClipVertex__CreateArray(int n){
	return new b2ClipVertex[n];
}
void b2ClipVertex__Destroy(void* cls){
	delete (b2ClipVertex*)cls;
}
void b2ClipVertex__DestroyArray(void* arr){
	delete[] (b2ClipVertex*)arr;
}
unsigned int b2ClipVertex__Size(){
	return sizeof(b2ClipVertex);
}
void* b2ClipVertex__Get_V(void* cls){
	return &((b2ClipVertex*)cls)->v;
}
void b2ClipVertex__Set_V(void* cls, void* v){
	((b2ClipVertex*)cls)->v = *((b2Vec2*)v);
}

//
// Begin class 'b2BroadPhase'
//
void* b2BroadPhase__Create(){
	return new b2BroadPhase();
}
void* b2BroadPhase__CreateArray(int n){
	return new b2BroadPhase[n];
}
void b2BroadPhase__Destroy(void* cls){
	delete (b2BroadPhase*)cls;
}
void b2BroadPhase__DestroyArray(void* arr){
	delete[] (b2BroadPhase*)arr;
}
unsigned int b2BroadPhase__Size(){
	return sizeof(b2BroadPhase);
}
float b2BroadPhase_GetTreeQuality(void* cls){
	return ((b2BroadPhase*)cls)->GetTreeQuality();
}
void* b2BroadPhase_GetFatAABB(void* cls, int a){
	return const_cast<b2AABB*>(&((b2BroadPhase*)cls)->GetFatAABB(((int)a)));
}
void* b2BroadPhase_GetUserData(void* cls, int a){
	return ((b2BroadPhase*)cls)->GetUserData(((int)a));
}
int b2BroadPhase_GetTreeHeight(void* cls){
	return ((b2BroadPhase*)cls)->GetTreeHeight();
}
int b2BroadPhase_GetProxyCount(void* cls){
	return ((b2BroadPhase*)cls)->GetProxyCount();
}
unsigned char b2BroadPhase_TestOverlap(void* cls, int a, int b){
	return ((b2BroadPhase*)cls)->TestOverlap(((int)a), ((int)b));
}
void b2BroadPhase_TouchProxy(void* cls, int a){
	((b2BroadPhase*)cls)->TouchProxy(((int)a));
}
int b2BroadPhase_GetTreeBalance(void* cls){
	return ((b2BroadPhase*)cls)->GetTreeBalance();
}
int b2BroadPhase_CreateProxy(void* cls, void* a, void* b){
	return ((b2BroadPhase*)cls)->CreateProxy(*((b2AABB*)a), ((void*)b));
}
void b2BroadPhase_MoveProxy(void* cls, int a, void* b, void* c){
	((b2BroadPhase*)cls)->MoveProxy(((int)a), *((b2AABB*)b), *((b2Vec2*)c));
}
void b2BroadPhase_DestroyProxy(void* cls, int a){
	((b2BroadPhase*)cls)->DestroyProxy(((int)a));
}

//
// Begin class 'b2Contact'
//
unsigned int b2Contact__Size(){
	return sizeof(b2Contact);
}
float b2Contact_GetRestitution(void* cls){
	return ((b2Contact*)cls)->GetRestitution();
}
void b2Contact_SetFriction(void* cls, float a){
	((b2Contact*)cls)->SetFriction(((float)a));
}
void b2Contact_SetRestitution(void* cls, float a){
	((b2Contact*)cls)->SetRestitution(((float)a));
}
void* b2Contact_GetNext0(void* cls){
	return ((b2Contact*)cls)->GetNext();
}
void* b2Contact_GetNext1(void* cls){
	return const_cast<b2Contact*>(((b2Contact*)cls)->GetNext());
}
float b2Contact_GetFriction(void* cls){
	return ((b2Contact*)cls)->GetFriction();
}
void b2Contact_ResetFriction(void* cls){
	((b2Contact*)cls)->ResetFriction();
}
unsigned char b2Contact_IsTouching(void* cls){
	return ((b2Contact*)cls)->IsTouching();
}
int b2Contact_GetChildIndexA(void* cls){
	return ((b2Contact*)cls)->GetChildIndexA();
}
int b2Contact_GetChildIndexB(void* cls){
	return ((b2Contact*)cls)->GetChildIndexB();
}
void b2Contact_GetWorldManifold(void* cls, void* a){
	((b2Contact*)cls)->GetWorldManifold(((b2WorldManifold*)a));
}
unsigned char b2Contact_IsEnabled(void* cls){
	return ((b2Contact*)cls)->IsEnabled();
}
void b2Contact_SetEnabled(void* cls, unsigned char a){
	((b2Contact*)cls)->SetEnabled(((unsigned char)a));
}
void* b2Contact_GetFixtureB0(void* cls){
	return ((b2Contact*)cls)->GetFixtureB();
}
void* b2Contact_GetFixtureB1(void* cls){
	return const_cast<b2Fixture*>(((b2Contact*)cls)->GetFixtureB());
}
void* b2Contact_GetFixtureA0(void* cls){
	return ((b2Contact*)cls)->GetFixtureA();
}
void* b2Contact_GetFixtureA1(void* cls){
	return const_cast<b2Fixture*>(((b2Contact*)cls)->GetFixtureA());
}
void* b2Contact_GetManifold0(void* cls){
	return ((b2Contact*)cls)->GetManifold();
}
void* b2Contact_GetManifold1(void* cls){
	return const_cast<b2Manifold*>(((b2Contact*)cls)->GetManifold());
}
void b2Contact_ResetRestitution(void* cls){
	((b2Contact*)cls)->ResetRestitution();
}