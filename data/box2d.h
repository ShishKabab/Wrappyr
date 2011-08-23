extern "C" {

//
// Begin class 'b2ContactRegister'
//
void* b2ContactRegister__Create();
void* b2ContactRegister__CreateArray(int);
void b2ContactRegister__Destroy(void*);
void b2ContactRegister__DestroyArray(void*);
unsigned int b2ContactRegister__Size();
unsigned char b2ContactRegister__Get_Primary(void*);
void b2ContactRegister__Set_Primary(void*, unsigned char);

//
// Begin class 'b2DistanceOutput'
//
void* b2DistanceOutput__Create();
void* b2DistanceOutput__CreateArray(int);
void b2DistanceOutput__Destroy(void*);
void b2DistanceOutput__DestroyArray(void*);
unsigned int b2DistanceOutput__Size();
void* b2DistanceOutput__Get_PointA(void*);
void b2DistanceOutput__Set_PointA(void*, void*);
void* b2DistanceOutput__Get_PointB(void*);
void b2DistanceOutput__Set_PointB(void*, void*);
float b2DistanceOutput__Get_Distance(void*);
void b2DistanceOutput__Set_Distance(void*, float);
int b2DistanceOutput__Get_Iterations(void*);
void b2DistanceOutput__Set_Iterations(void*, int);

//
// Begin class 'b2RayCastCallback'
//
void b2RayCastCallback__Destroy(void*);
void b2RayCastCallback__DestroyArray(void*);
unsigned int b2RayCastCallback__Size();

//
// Begin class 'b2ContactListener'
//
void* b2ContactListener__Create();
void* b2ContactListener__CreateArray(int);
void b2ContactListener__Destroy(void*);
void b2ContactListener__DestroyArray(void*);
unsigned int b2ContactListener__Size();
void b2ContactListener_EndContact(void*, void*);
void b2ContactListener_PreSolve(void*, void*, void*);
void b2ContactListener_BeginContact(void*, void*);
void b2ContactListener_PostSolve(void*, void*, void*);

//
// Begin class 'b2Version'
//
void* b2Version__Create();
void* b2Version__CreateArray(int);
void b2Version__Destroy(void*);
void b2Version__DestroyArray(void*);
unsigned int b2Version__Size();
int b2Version__Get_Major(void*);
void b2Version__Set_Major(void*, int);
int b2Version__Get_Minor(void*);
void b2Version__Set_Minor(void*, int);
int b2Version__Get_Revision(void*);
void b2Version__Set_Revision(void*, int);

//
// Begin class 'b2TOIOutput'
//
void* b2TOIOutput__Create();
void* b2TOIOutput__CreateArray(int);
void b2TOIOutput__Destroy(void*);
void b2TOIOutput__DestroyArray(void*);
unsigned int b2TOIOutput__Size();
unsigned int b2TOIOutput__Get_State(void*);
void b2TOIOutput__Set_State(void*, unsigned int);
float b2TOIOutput__Get_T(void*);
void b2TOIOutput__Set_T(void*, float);

//
// Begin class 'b2TOIInput'
//
void* b2TOIInput__Create();
void* b2TOIInput__CreateArray(int);
void b2TOIInput__Destroy(void*);
void b2TOIInput__DestroyArray(void*);
unsigned int b2TOIInput__Size();
void* b2TOIInput__Get_ProxyA(void*);
void b2TOIInput__Set_ProxyA(void*, void*);
void* b2TOIInput__Get_ProxyB(void*);
void b2TOIInput__Set_ProxyB(void*, void*);
void* b2TOIInput__Get_SweepA(void*);
void b2TOIInput__Set_SweepA(void*, void*);
void* b2TOIInput__Get_SweepB(void*);
void b2TOIInput__Set_SweepB(void*, void*);
float b2TOIInput__Get_TMax(void*);
void b2TOIInput__Set_TMax(void*, float);

//
// Begin class 'b2PulleyJoint'
//
void b2PulleyJoint__Destroy(void*);
void b2PulleyJoint__DestroyArray(void*);
unsigned int b2PulleyJoint__Size();
void* b2PulleyJoint_GetAnchorA(void*);
void* b2PulleyJoint_GetGroundAnchorB(void*);
float b2PulleyJoint_GetReactionTorque(void*, float);
void* b2PulleyJoint_GetGroundAnchorA(void*);
void* b2PulleyJoint_GetAnchorB(void*);
void* b2PulleyJoint_GetReactionForce(void*, float);
float b2PulleyJoint_GetLength2(void*);
float b2PulleyJoint_GetLength1(void*);
float b2PulleyJoint_GetRatio(void*);

//
// Begin class 'b2QueryCallback'
//
void b2QueryCallback__Destroy(void*);
void b2QueryCallback__DestroyArray(void*);
unsigned int b2QueryCallback__Size();

//
// Begin class 'b2DistanceJointDef'
//
void* b2DistanceJointDef__Create();
void* b2DistanceJointDef__CreateArray(int);
void b2DistanceJointDef__Destroy(void*);
void b2DistanceJointDef__DestroyArray(void*);
unsigned int b2DistanceJointDef__Size();
void b2DistanceJointDef_Initialize(void*, void*, void*, void*, void*);
void* b2DistanceJointDef__Get_LocalAnchorA(void*);
void b2DistanceJointDef__Set_LocalAnchorA(void*, void*);
void* b2DistanceJointDef__Get_LocalAnchorB(void*);
void b2DistanceJointDef__Set_LocalAnchorB(void*, void*);
float b2DistanceJointDef__Get_Length(void*);
void b2DistanceJointDef__Set_Length(void*, float);
float b2DistanceJointDef__Get_FrequencyHz(void*);
void b2DistanceJointDef__Set_FrequencyHz(void*, float);
float b2DistanceJointDef__Get_DampingRatio(void*);
void b2DistanceJointDef__Set_DampingRatio(void*, float);

//
// Begin class 'b2FrictionJointDef'
//
void* b2FrictionJointDef__Create();
void* b2FrictionJointDef__CreateArray(int);
void b2FrictionJointDef__Destroy(void*);
void b2FrictionJointDef__DestroyArray(void*);
unsigned int b2FrictionJointDef__Size();
void b2FrictionJointDef_Initialize(void*, void*, void*, void*);
void* b2FrictionJointDef__Get_LocalAnchorA(void*);
void b2FrictionJointDef__Set_LocalAnchorA(void*, void*);
void* b2FrictionJointDef__Get_LocalAnchorB(void*);
void b2FrictionJointDef__Set_LocalAnchorB(void*, void*);
float b2FrictionJointDef__Get_MaxForce(void*);
void b2FrictionJointDef__Set_MaxForce(void*, float);
float b2FrictionJointDef__Get_MaxTorque(void*);
void b2FrictionJointDef__Set_MaxTorque(void*, float);

//
// Begin class 'b2RopeDef'
//
void* b2RopeDef__Create();
void* b2RopeDef__CreateArray(int);
void b2RopeDef__Destroy(void*);
void b2RopeDef__DestroyArray(void*);
unsigned int b2RopeDef__Size();
void* b2RopeDef__Get_Vertices(void*);
void b2RopeDef__Set_Vertices(void*, void*);
int b2RopeDef__Get_Count(void*);
void b2RopeDef__Set_Count(void*, int);
void* b2RopeDef__Get_Gravity(void*);
void b2RopeDef__Set_Gravity(void*, void*);
float b2RopeDef__Get_Damping(void*);
void b2RopeDef__Set_Damping(void*, float);
float b2RopeDef__Get_K2(void*);
void b2RopeDef__Set_K2(void*, float);
float b2RopeDef__Get_K3(void*);
void b2RopeDef__Set_K3(void*, float);

//
// Begin class 'b2MassData'
//
void* b2MassData__Create();
void* b2MassData__CreateArray(int);
void b2MassData__Destroy(void*);
void b2MassData__DestroyArray(void*);
unsigned int b2MassData__Size();
float b2MassData__Get_Mass(void*);
void b2MassData__Set_Mass(void*, float);
void* b2MassData__Get_Center(void*);
void b2MassData__Set_Center(void*, void*);
float b2MassData__Get_I(void*);
void b2MassData__Set_I(void*, float);

//
// Begin class 'b2WeldJoint'
//
void b2WeldJoint__Destroy(void*);
void b2WeldJoint__DestroyArray(void*);
unsigned int b2WeldJoint__Size();
void* b2WeldJoint_GetAnchorA(void*);
float b2WeldJoint_GetReactionTorque(void*, float);
void* b2WeldJoint_GetAnchorB(void*);
void* b2WeldJoint_GetReactionForce(void*, float);

//
// Begin class 'b2ContactFilter'
//
void* b2ContactFilter__Create();
void* b2ContactFilter__CreateArray(int);
void b2ContactFilter__Destroy(void*);
void b2ContactFilter__DestroyArray(void*);
unsigned int b2ContactFilter__Size();
unsigned char b2ContactFilter_ShouldCollide(void*, void*, void*);

//
// Begin class 'b2Body'
//
unsigned int b2Body__Size();
float b2Body_GetAngle(void*);
void* b2Body_GetUserData(void*);
unsigned char b2Body_IsSleepingAllowed(void*);
void b2Body_SetAngularDamping(void*, float);
void b2Body_SetActive(void*, unsigned char);
void b2Body_SetGravityScale(void*, float);
void b2Body_SetUserData(void*, void*);
float b2Body_GetAngularVelocity(void*);
void* b2Body_GetFixtureList0(void*);
void* b2Body_GetFixtureList1(void*);
void b2Body_ApplyForce(void*, void*, void*);
void* b2Body_GetLocalPoint(void*, void*);
void b2Body_SetLinearVelocity(void*, void*);
void* b2Body_GetJointList0(void*);
void* b2Body_GetJointList1(void*);
void* b2Body_GetLinearVelocity(void*);
void* b2Body_GetNext0(void*);
void* b2Body_GetNext1(void*);
void b2Body_SetSleepingAllowed(void*, unsigned char);
void b2Body_SetTransform(void*, void*, float);
float b2Body_GetMass(void*);
void b2Body_SetAngularVelocity(void*, float);
void b2Body_GetMassData(void*, void*);
void* b2Body_GetLinearVelocityFromWorldPoint(void*, void*);
void b2Body_ResetMassData(void*);
void b2Body_ApplyForceToCenter(void*, void*);
void b2Body_ApplyTorque(void*, float);
unsigned char b2Body_IsAwake(void*);
void b2Body_SetType(void*, unsigned int);
void* b2Body_CreateFixture0(void*, void*);
void* b2Body_CreateFixture1(void*, void*, float);
void b2Body_SetMassData(void*, void*);
void* b2Body_GetTransform(void*);
void* b2Body_GetWorldCenter(void*);
float b2Body_GetAngularDamping(void*);
void b2Body_ApplyLinearImpulse(void*, void*, void*);
unsigned char b2Body_IsFixedRotation(void*);
void* b2Body_GetLocalCenter(void*);
void* b2Body_GetWorldVector(void*, void*);
void* b2Body_GetLinearVelocityFromLocalPoint(void*, void*);
void* b2Body_GetContactList0(void*);
void* b2Body_GetContactList1(void*);
void* b2Body_GetWorldPoint(void*, void*);
void b2Body_SetAwake(void*, unsigned char);
float b2Body_GetLinearDamping(void*);
unsigned char b2Body_IsBullet(void*);
void* b2Body_GetWorld0(void*);
void* b2Body_GetWorld1(void*);
void* b2Body_GetLocalVector(void*, void*);
void b2Body_SetLinearDamping(void*, float);
void b2Body_SetBullet(void*, unsigned char);
unsigned int b2Body_GetType(void*);
float b2Body_GetGravityScale(void*);
void b2Body_DestroyFixture(void*, void*);
float b2Body_GetInertia(void*);
unsigned char b2Body_IsActive(void*);
void b2Body_SetFixedRotation(void*, unsigned char);
void b2Body_ApplyAngularImpulse(void*, float);
void* b2Body_GetPosition(void*);

//
// Begin class 'b2PrismaticJointDef'
//
void* b2PrismaticJointDef__Create();
void* b2PrismaticJointDef__CreateArray(int);
void b2PrismaticJointDef__Destroy(void*);
void b2PrismaticJointDef__DestroyArray(void*);
unsigned int b2PrismaticJointDef__Size();
void b2PrismaticJointDef_Initialize(void*, void*, void*, void*, void*);
void* b2PrismaticJointDef__Get_LocalAnchorA(void*);
void b2PrismaticJointDef__Set_LocalAnchorA(void*, void*);
void* b2PrismaticJointDef__Get_LocalAnchorB(void*);
void b2PrismaticJointDef__Set_LocalAnchorB(void*, void*);
void* b2PrismaticJointDef__Get_LocalAxisA(void*);
void b2PrismaticJointDef__Set_LocalAxisA(void*, void*);
float b2PrismaticJointDef__Get_ReferenceAngle(void*);
void b2PrismaticJointDef__Set_ReferenceAngle(void*, float);
unsigned char b2PrismaticJointDef__Get_EnableLimit(void*);
void b2PrismaticJointDef__Set_EnableLimit(void*, unsigned char);
float b2PrismaticJointDef__Get_LowerTranslation(void*);
void b2PrismaticJointDef__Set_LowerTranslation(void*, float);
float b2PrismaticJointDef__Get_UpperTranslation(void*);
void b2PrismaticJointDef__Set_UpperTranslation(void*, float);
unsigned char b2PrismaticJointDef__Get_EnableMotor(void*);
void b2PrismaticJointDef__Set_EnableMotor(void*, unsigned char);
float b2PrismaticJointDef__Get_MaxMotorForce(void*);
void b2PrismaticJointDef__Set_MaxMotorForce(void*, float);
float b2PrismaticJointDef__Get_MotorSpeed(void*);
void b2PrismaticJointDef__Set_MotorSpeed(void*, float);

//
// Begin class 'b2RayCastOutput'
//
void* b2RayCastOutput__Create();
void* b2RayCastOutput__CreateArray(int);
void b2RayCastOutput__Destroy(void*);
void b2RayCastOutput__DestroyArray(void*);
unsigned int b2RayCastOutput__Size();
void* b2RayCastOutput__Get_Normal(void*);
void b2RayCastOutput__Set_Normal(void*, void*);
float b2RayCastOutput__Get_Fraction(void*);
void b2RayCastOutput__Set_Fraction(void*, float);

//
// Begin class 'b2WheelJoint'
//
void b2WheelJoint__Destroy(void*);
void b2WheelJoint__DestroyArray(void*);
unsigned int b2WheelJoint__Size();
unsigned char b2WheelJoint_IsMotorEnabled(void*);
float b2WheelJoint_GetMotorSpeed(void*);
void* b2WheelJoint_GetAnchorA(void*);
float b2WheelJoint_GetReactionTorque(void*, float);
void b2WheelJoint_SetSpringDampingRatio(void*, float);
float b2WheelJoint_GetSpringFrequencyHz(void*);
float b2WheelJoint_GetJointTranslation(void*);
float b2WheelJoint_GetSpringDampingRatio(void*);
void b2WheelJoint_SetMaxMotorTorque(void*, float);
void b2WheelJoint_SetSpringFrequencyHz(void*, float);
void b2WheelJoint_SetMotorSpeed(void*, float);
void* b2WheelJoint_GetAnchorB(void*);
void* b2WheelJoint_GetReactionForce(void*, float);
float b2WheelJoint_GetMotorTorque(void*, float);
float b2WheelJoint_GetJointSpeed(void*);
float b2WheelJoint_GetMaxMotorTorque(void*);
void b2WheelJoint_EnableMotor(void*, unsigned char);

//
// Begin class 'b2BlockAllocator'
//
void* b2BlockAllocator__Create();
void* b2BlockAllocator__CreateArray(int);
void b2BlockAllocator__Destroy(void*);
void b2BlockAllocator__DestroyArray(void*);
unsigned int b2BlockAllocator__Size();
void b2BlockAllocator_Clear(void*);
void* b2BlockAllocator_Allocate(void*, int);
void b2BlockAllocator_Free(void*, void*, int);

//
// Begin class 'b2Vec3'
//
void* b2Vec3__Create0();
void* b2Vec3__Create1(float, float, float);
void* b2Vec3__Create2(void*);
void* b2Vec3__CreateArray(int);
void b2Vec3__Destroy(void*);
void b2Vec3__DestroyArray(void*);
unsigned int b2Vec3__Size();
void b2Vec3_SetZero(void*);
void b2Vec3_Set(void*, float, float, float);
float b2Vec3__Get_X(void*);
void b2Vec3__Set_X(void*, float);
float b2Vec3__Get_Y(void*);
void b2Vec3__Set_Y(void*, float);
float b2Vec3__Get_Z(void*);
void b2Vec3__Set_Z(void*, float);

//
// Begin class 'b2RevoluteJointDef'
//
void* b2RevoluteJointDef__Create();
void* b2RevoluteJointDef__CreateArray(int);
void b2RevoluteJointDef__Destroy(void*);
void b2RevoluteJointDef__DestroyArray(void*);
unsigned int b2RevoluteJointDef__Size();
void b2RevoluteJointDef_Initialize(void*, void*, void*, void*);
void* b2RevoluteJointDef__Get_LocalAnchorA(void*);
void b2RevoluteJointDef__Set_LocalAnchorA(void*, void*);
void* b2RevoluteJointDef__Get_LocalAnchorB(void*);
void b2RevoluteJointDef__Set_LocalAnchorB(void*, void*);
float b2RevoluteJointDef__Get_ReferenceAngle(void*);
void b2RevoluteJointDef__Set_ReferenceAngle(void*, float);
unsigned char b2RevoluteJointDef__Get_EnableLimit(void*);
void b2RevoluteJointDef__Set_EnableLimit(void*, unsigned char);
float b2RevoluteJointDef__Get_LowerAngle(void*);
void b2RevoluteJointDef__Set_LowerAngle(void*, float);
float b2RevoluteJointDef__Get_UpperAngle(void*);
void b2RevoluteJointDef__Set_UpperAngle(void*, float);
unsigned char b2RevoluteJointDef__Get_EnableMotor(void*);
void b2RevoluteJointDef__Set_EnableMotor(void*, unsigned char);
float b2RevoluteJointDef__Get_MotorSpeed(void*);
void b2RevoluteJointDef__Set_MotorSpeed(void*, float);
float b2RevoluteJointDef__Get_MaxMotorTorque(void*);
void b2RevoluteJointDef__Set_MaxMotorTorque(void*, float);

//
// Begin class 'b2Fixture'
//
void b2Fixture__Destroy(void*);
void b2Fixture__DestroyArray(void*);
unsigned int b2Fixture__Size();
float b2Fixture_GetRestitution(void*);
void b2Fixture_SetFilterData(void*, void*);
void b2Fixture_SetFriction(void*, float);
void* b2Fixture_GetShape0(void*);
void* b2Fixture_GetShape1(void*);
void b2Fixture_SetRestitution(void*, float);
void* b2Fixture_GetBody0(void*);
void* b2Fixture_GetBody1(void*);
void* b2Fixture_GetNext0(void*);
void* b2Fixture_GetNext1(void*);
float b2Fixture_GetFriction(void*);
void* b2Fixture_GetUserData(void*);
void b2Fixture_SetDensity(void*, float);
void b2Fixture_GetMassData(void*, void*);
void b2Fixture_SetSensor(void*, unsigned char);
void* b2Fixture_GetAABB(void*, int);
unsigned char b2Fixture_TestPoint(void*, void*);
void b2Fixture_SetUserData(void*, void*);
unsigned char b2Fixture_RayCast(void*, void*, void*, int);
void b2Fixture_Refilter(void*);
void* b2Fixture_GetFilterData(void*);
unsigned char b2Fixture_IsSensor(void*);
unsigned int b2Fixture_GetType(void*);
float b2Fixture_GetDensity(void*);

//
// Begin class 'b2PrismaticJoint'
//
void b2PrismaticJoint__Destroy(void*);
void b2PrismaticJoint__DestroyArray(void*);
unsigned int b2PrismaticJoint__Size();
unsigned char b2PrismaticJoint_IsMotorEnabled(void*);
float b2PrismaticJoint_GetMotorSpeed(void*);
void* b2PrismaticJoint_GetAnchorA(void*);
void b2PrismaticJoint_SetMaxMotorForce(void*, float);
float b2PrismaticJoint_GetReactionTorque(void*, float);
float b2PrismaticJoint_GetUpperLimit(void*);
float b2PrismaticJoint_GetJointTranslation(void*);
float b2PrismaticJoint_GetMotorForce(void*, float);
float b2PrismaticJoint_GetLowerLimit(void*);
void b2PrismaticJoint_SetMotorSpeed(void*, float);
void* b2PrismaticJoint_GetAnchorB(void*);
void* b2PrismaticJoint_GetReactionForce(void*, float);
void b2PrismaticJoint_SetLimits(void*, float, float);
void b2PrismaticJoint_EnableMotor(void*, unsigned char);
float b2PrismaticJoint_GetJointSpeed(void*);
unsigned char b2PrismaticJoint_IsLimitEnabled(void*);
void b2PrismaticJoint_EnableLimit(void*, unsigned char);

//
// Begin class 'b2PolygonShape'
//
void* b2PolygonShape__Create();
void* b2PolygonShape__CreateArray(int);
void b2PolygonShape__Destroy(void*);
void b2PolygonShape__DestroyArray(void*);
unsigned int b2PolygonShape__Size();
void b2PolygonShape_Set(void*, void*, int);
void b2PolygonShape_ComputeMass(void*, void*, float);
void* b2PolygonShape_Clone(void*, void*);
void* b2PolygonShape_GetVertex(void*, int);
unsigned char b2PolygonShape_RayCast(void*, void*, void*, void*, int);
void b2PolygonShape_ComputeAABB(void*, void*, void*, int);
int b2PolygonShape_GetVertexCount(void*);
int b2PolygonShape_GetChildCount(void*);
unsigned char b2PolygonShape_TestPoint(void*, void*, void*);
void b2PolygonShape_SetAsBox0(void*, float, float);
void b2PolygonShape_SetAsBox1(void*, float, float, void*, float);
void* b2PolygonShape__Get_MCentroid(void*);
void b2PolygonShape__Set_MCentroid(void*, void*);
int b2PolygonShape__Get_MVertexCount(void*);
void b2PolygonShape__Set_MVertexCount(void*, int);

//
// Begin class 'b2Jacobian'
//
void* b2Jacobian__Create();
void* b2Jacobian__CreateArray(int);
void b2Jacobian__Destroy(void*);
void b2Jacobian__DestroyArray(void*);
unsigned int b2Jacobian__Size();
void* b2Jacobian__Get_Linear(void*);
void b2Jacobian__Set_Linear(void*, void*);
float b2Jacobian__Get_AngularA(void*);
void b2Jacobian__Set_AngularA(void*, float);
float b2Jacobian__Get_AngularB(void*);
void b2Jacobian__Set_AngularB(void*, float);

//
// Begin class 'b2ContactFeature'
//
void* b2ContactFeature__Create();
void* b2ContactFeature__CreateArray(int);
void b2ContactFeature__Destroy(void*);
void b2ContactFeature__DestroyArray(void*);
unsigned int b2ContactFeature__Size();
unsigned char b2ContactFeature__Get_IndexA(void*);
void b2ContactFeature__Set_IndexA(void*, unsigned char);
unsigned char b2ContactFeature__Get_IndexB(void*);
void b2ContactFeature__Set_IndexB(void*, unsigned char);
unsigned char b2ContactFeature__Get_TypeA(void*);
void b2ContactFeature__Set_TypeA(void*, unsigned char);
unsigned char b2ContactFeature__Get_TypeB(void*);
void b2ContactFeature__Set_TypeB(void*, unsigned char);

//
// Begin class 'b2SolverData'
//
void* b2SolverData__Create();
void* b2SolverData__CreateArray(int);
void b2SolverData__Destroy(void*);
void b2SolverData__DestroyArray(void*);
unsigned int b2SolverData__Size();
void* b2SolverData__Get_Step(void*);
void b2SolverData__Set_Step(void*, void*);
void* b2SolverData__Get_Positions(void*);
void b2SolverData__Set_Positions(void*, void*);
void* b2SolverData__Get_Velocities(void*);
void b2SolverData__Set_Velocities(void*, void*);

//
// Begin class 'b2Pair'
//
void* b2Pair__Create();
void* b2Pair__CreateArray(int);
void b2Pair__Destroy(void*);
void b2Pair__DestroyArray(void*);
unsigned int b2Pair__Size();
int b2Pair__Get_ProxyIdA(void*);
void b2Pair__Set_ProxyIdA(void*, int);
int b2Pair__Get_ProxyIdB(void*);
void b2Pair__Set_ProxyIdB(void*, int);
int b2Pair__Get_Next(void*);
void b2Pair__Set_Next(void*, int);

//
// Begin class 'b2World'
//
void* b2World__Create(void*, unsigned char);
void b2World__Destroy(void*);
void b2World__DestroyArray(void*);
unsigned int b2World__Size();
void b2World_QueryAABB(void*, void*, void*);
void* b2World_GetContactList0(void*);
void* b2World_GetContactList1(void*);
float b2World_GetTreeQuality(void*);
int b2World_GetTreeHeight(void*);
void* b2World_GetProfile(void*);
int b2World_GetTreeBalance(void*);
void* b2World_GetContactManager(void*);
void b2World_SetContactListener(void*, void*);
void b2World_DrawDebugData(void*);
void b2World_SetContinuousPhysics(void*, unsigned char);
void b2World_SetGravity(void*, void*);
int b2World_GetBodyCount(void*);
unsigned char b2World_GetAutoClearForces(void*);
void* b2World_GetJointList0(void*);
void* b2World_GetJointList1(void*);
void* b2World_CreateBody(void*, void*);
void* b2World_GetBodyList0(void*);
void* b2World_GetBodyList1(void*);
void b2World_SetDestructionListener(void*, void*);
void b2World_DestroyJoint(void*, void*);
int b2World_GetJointCount(void*);
void b2World_Step(void*, float, int, int);
void b2World_ClearForces(void*);
void b2World_DestroyBody(void*, void*);
void* b2World_CreateJoint(void*, void*);
int b2World_GetProxyCount(void*);
void b2World_RayCast(void*, void*, void*, void*);
unsigned char b2World_IsLocked(void*);
void b2World_SetSubStepping(void*, unsigned char);
void b2World_SetDebugDraw(void*, void*);
void b2World_SetAutoClearForces(void*, unsigned char);
void* b2World_GetGravity(void*);
int b2World_GetContactCount(void*);
void b2World_SetWarmStarting(void*, unsigned char);
void b2World_SetContactFilter(void*, void*);

//
// Begin class 'b2Shape'
//
void b2Shape__Destroy(void*);
void b2Shape__DestroyArray(void*);
unsigned int b2Shape__Size();
unsigned int b2Shape_GetType(void*);
unsigned int b2Shape__Get_MType(void*);
void b2Shape__Set_MType(void*, unsigned int);
float b2Shape__Get_MRadius(void*);
void b2Shape__Set_MRadius(void*, float);

//
// Begin class 'b2DistanceJoint'
//
void b2DistanceJoint__Destroy(void*);
void b2DistanceJoint__DestroyArray(void*);
unsigned int b2DistanceJoint__Size();
void* b2DistanceJoint_GetAnchorA(void*);
float b2DistanceJoint_GetReactionTorque(void*, float);
void b2DistanceJoint_SetFrequency(void*, float);
float b2DistanceJoint_GetLength(void*);
float b2DistanceJoint_GetDampingRatio(void*);
float b2DistanceJoint_GetFrequency(void*);
void b2DistanceJoint_SetDampingRatio(void*, float);
void* b2DistanceJoint_GetAnchorB(void*);
void* b2DistanceJoint_GetReactionForce(void*, float);
void b2DistanceJoint_SetLength(void*, float);

//
// Begin class 'b2TreeNode'
//
void* b2TreeNode__Create();
void* b2TreeNode__CreateArray(int);
void b2TreeNode__Destroy(void*);
void b2TreeNode__DestroyArray(void*);
unsigned int b2TreeNode__Size();
unsigned char b2TreeNode_IsLeaf(void*);
void* b2TreeNode__Get_Aabb(void*);
void b2TreeNode__Set_Aabb(void*, void*);
int b2TreeNode__Get_Child1(void*);
void b2TreeNode__Set_Child1(void*, int);
int b2TreeNode__Get_Child2(void*);
void b2TreeNode__Set_Child2(void*, int);
int b2TreeNode__Get_Height(void*);
void b2TreeNode__Set_Height(void*, int);

//
// Begin class 'b2CircleShape'
//
void* b2CircleShape__Create();
void* b2CircleShape__CreateArray(int);
void b2CircleShape__Destroy(void*);
void b2CircleShape__DestroyArray(void*);
unsigned int b2CircleShape__Size();
void b2CircleShape_ComputeMass(void*, void*, float);
void* b2CircleShape_GetVertex(void*, int);
void* b2CircleShape_Clone(void*, void*);
void* b2CircleShape_GetSupportVertex(void*, void*);
unsigned char b2CircleShape_RayCast(void*, void*, void*, void*, int);
void b2CircleShape_ComputeAABB(void*, void*, void*, int);
int b2CircleShape_GetVertexCount(void*);
int b2CircleShape_GetChildCount(void*);
unsigned char b2CircleShape_TestPoint(void*, void*, void*);
int b2CircleShape_GetSupport(void*, void*);
void* b2CircleShape__Get_MP(void*);
void b2CircleShape__Set_MP(void*, void*);

//
// Begin class 'b2JointEdge'
//
void* b2JointEdge__Create();
void* b2JointEdge__CreateArray(int);
void b2JointEdge__Destroy(void*);
void b2JointEdge__DestroyArray(void*);
unsigned int b2JointEdge__Size();
void* b2JointEdge__Get_Other(void*);
void b2JointEdge__Set_Other(void*, void*);
void* b2JointEdge__Get_Prev(void*);
void b2JointEdge__Set_Prev(void*, void*);
void* b2JointEdge__Get_Next(void*);
void b2JointEdge__Set_Next(void*, void*);

//
// Begin class 'b2RopeJointDef'
//
void* b2RopeJointDef__Create();
void* b2RopeJointDef__CreateArray(int);
void b2RopeJointDef__Destroy(void*);
void b2RopeJointDef__DestroyArray(void*);
unsigned int b2RopeJointDef__Size();
void* b2RopeJointDef__Get_LocalAnchorA(void*);
void b2RopeJointDef__Set_LocalAnchorA(void*, void*);
void* b2RopeJointDef__Get_LocalAnchorB(void*);
void b2RopeJointDef__Set_LocalAnchorB(void*, void*);
float b2RopeJointDef__Get_MaxLength(void*);
void b2RopeJointDef__Set_MaxLength(void*, float);

//
// Begin class 'b2Position'
//
void* b2Position__Create();
void* b2Position__CreateArray(int);
void b2Position__Destroy(void*);
void b2Position__DestroyArray(void*);
unsigned int b2Position__Size();
void* b2Position__Get_C(void*);
void b2Position__Set_C(void*, void*);
float b2Position__Get_A(void*);
void b2Position__Set_A(void*, float);

//
// Begin class 'b2Profile'
//
void* b2Profile__Create();
void* b2Profile__CreateArray(int);
void b2Profile__Destroy(void*);
void b2Profile__DestroyArray(void*);
unsigned int b2Profile__Size();
float b2Profile__Get_Step(void*);
void b2Profile__Set_Step(void*, float);
float b2Profile__Get_Collide(void*);
void b2Profile__Set_Collide(void*, float);
float b2Profile__Get_Solve(void*);
void b2Profile__Set_Solve(void*, float);
float b2Profile__Get_SolveInit(void*);
void b2Profile__Set_SolveInit(void*, float);
float b2Profile__Get_SolveVelocity(void*);
void b2Profile__Set_SolveVelocity(void*, float);
float b2Profile__Get_SolvePosition(void*);
void b2Profile__Set_SolvePosition(void*, float);
float b2Profile__Get_Broadphase(void*);
void b2Profile__Set_Broadphase(void*, float);
float b2Profile__Get_SolveTOI(void*);
void b2Profile__Set_SolveTOI(void*, float);

//
// Begin class 'b2RevoluteJoint'
//
void b2RevoluteJoint__Destroy(void*);
void b2RevoluteJoint__DestroyArray(void*);
unsigned int b2RevoluteJoint__Size();
unsigned char b2RevoluteJoint_IsMotorEnabled(void*);
float b2RevoluteJoint_GetMotorSpeed(void*);
float b2RevoluteJoint_GetReactionTorque(void*, float);
void* b2RevoluteJoint_GetReactionForce(void*, float);
float b2RevoluteJoint_GetUpperLimit(void*);
float b2RevoluteJoint_GetMotorTorque(void*, float);
void b2RevoluteJoint_SetMaxMotorTorque(void*, float);
float b2RevoluteJoint_GetLowerLimit(void*);
void b2RevoluteJoint_SetMotorSpeed(void*, float);
float b2RevoluteJoint_GetJointAngle(void*);
void b2RevoluteJoint_EnableLimit(void*, unsigned char);
void* b2RevoluteJoint_GetAnchorA(void*);
void b2RevoluteJoint_SetLimits(void*, float, float);
void b2RevoluteJoint_EnableMotor(void*, unsigned char);
float b2RevoluteJoint_GetJointSpeed(void*);
unsigned char b2RevoluteJoint_IsLimitEnabled(void*);
void* b2RevoluteJoint_GetAnchorB(void*);

//
// Begin class 'b2Mat33'
//
void* b2Mat33__Create0();
void* b2Mat33__Create1(void*, void*, void*);
void* b2Mat33__CreateArray(int);
void b2Mat33__Destroy(void*);
void b2Mat33__DestroyArray(void*);
unsigned int b2Mat33__Size();
void b2Mat33_SetZero(void*);
void* b2Mat33_Solve33(void*, void*);
void* b2Mat33_Solve22(void*, void*);
void* b2Mat33__Get_Ex(void*);
void b2Mat33__Set_Ex(void*, void*);
void* b2Mat33__Get_Ey(void*);
void b2Mat33__Set_Ey(void*, void*);
void* b2Mat33__Get_Ez(void*);
void b2Mat33__Set_Ez(void*, void*);

//
// Begin class 'b2TimeStep'
//
void* b2TimeStep__Create();
void* b2TimeStep__CreateArray(int);
void b2TimeStep__Destroy(void*);
void b2TimeStep__DestroyArray(void*);
unsigned int b2TimeStep__Size();
float b2TimeStep__Get_Dt(void*);
void b2TimeStep__Set_Dt(void*, float);
float b2TimeStep__Get_InvDt(void*);
void b2TimeStep__Set_InvDt(void*, float);
float b2TimeStep__Get_DtRatio(void*);
void b2TimeStep__Set_DtRatio(void*, float);
int b2TimeStep__Get_VelocityIterations(void*);
void b2TimeStep__Set_VelocityIterations(void*, int);
int b2TimeStep__Get_PositionIterations(void*);
void b2TimeStep__Set_PositionIterations(void*, int);
unsigned char b2TimeStep__Get_WarmStarting(void*);
void b2TimeStep__Set_WarmStarting(void*, unsigned char);

//
// Begin class 'b2ContactImpulse'
//
void* b2ContactImpulse__Create();
void* b2ContactImpulse__CreateArray(int);
void b2ContactImpulse__Destroy(void*);
void b2ContactImpulse__DestroyArray(void*);
unsigned int b2ContactImpulse__Size();

//
// Begin class 'b2Sweep'
//
void* b2Sweep__Create();
void* b2Sweep__CreateArray(int);
void b2Sweep__Destroy(void*);
void b2Sweep__DestroyArray(void*);
unsigned int b2Sweep__Size();
void b2Sweep_Normalize(void*);
void b2Sweep_Advance(void*, float);
void b2Sweep_GetTransform(void*, void*, float);
void* b2Sweep__Get_LocalCenter(void*);
void b2Sweep__Set_LocalCenter(void*, void*);
void* b2Sweep__Get_C0(void*);
void b2Sweep__Set_C0(void*, void*);
void* b2Sweep__Get_C(void*);
void b2Sweep__Set_C(void*, void*);
float b2Sweep__Get_A0(void*);
void b2Sweep__Set_A0(void*, float);
float b2Sweep__Get_A(void*);
void b2Sweep__Set_A(void*, float);
float b2Sweep__Get_Alpha0(void*);
void b2Sweep__Set_Alpha0(void*, float);

//
// Begin class 'b2FrictionJoint'
//
void b2FrictionJoint__Destroy(void*);
void b2FrictionJoint__DestroyArray(void*);
unsigned int b2FrictionJoint__Size();
void b2FrictionJoint_SetMaxTorque(void*, float);
void* b2FrictionJoint_GetAnchorA(void*);
float b2FrictionJoint_GetReactionTorque(void*, float);
void b2FrictionJoint_SetMaxForce(void*, float);
float b2FrictionJoint_GetMaxForce(void*);
void* b2FrictionJoint_GetAnchorB(void*);
void* b2FrictionJoint_GetReactionForce(void*, float);
float b2FrictionJoint_GetMaxTorque(void*);

//
// Begin class 'b2MouseJointDef'
//
void* b2MouseJointDef__Create();
void* b2MouseJointDef__CreateArray(int);
void b2MouseJointDef__Destroy(void*);
void b2MouseJointDef__DestroyArray(void*);
unsigned int b2MouseJointDef__Size();
void* b2MouseJointDef__Get_Target(void*);
void b2MouseJointDef__Set_Target(void*, void*);
float b2MouseJointDef__Get_MaxForce(void*);
void b2MouseJointDef__Set_MaxForce(void*, float);
float b2MouseJointDef__Get_FrequencyHz(void*);
void b2MouseJointDef__Set_FrequencyHz(void*, float);
float b2MouseJointDef__Get_DampingRatio(void*);
void b2MouseJointDef__Set_DampingRatio(void*, float);

//
// Begin class 'b2Draw'
//
void b2Draw__Destroy(void*);
void b2Draw__DestroyArray(void*);
unsigned int b2Draw__Size();
void b2Draw_AppendFlags(void*, unsigned int);
void b2Draw_ClearFlags(void*, unsigned int);
void b2Draw_SetFlags(void*, unsigned int);
unsigned int b2Draw_GetFlags(void*);

//
// Begin class 'b2Vec2'
//
void* b2Vec2__Create0();
void* b2Vec2__Create1(float, float);
void* b2Vec2__Create2(void*);
void* b2Vec2__CreateArray(int);
void b2Vec2__Destroy(void*);
void b2Vec2__DestroyArray(void*);
unsigned int b2Vec2__Size();
float b2Vec2_Normalize(void*);
float b2Vec2_LengthSquared(void*);
void b2Vec2_Set(void*, float, float);
unsigned char b2Vec2_IsValid(void*);
void* b2Vec2_Skew(void*);
void b2Vec2_SetZero(void*);
float b2Vec2_Length(void*);
float b2Vec2__Get_X(void*);
void b2Vec2__Set_X(void*, float);
float b2Vec2__Get_Y(void*);
void b2Vec2__Set_Y(void*, float);

//
// Begin class 'b2PulleyJointDef'
//
void* b2PulleyJointDef__Create();
void* b2PulleyJointDef__CreateArray(int);
void b2PulleyJointDef__Destroy(void*);
void b2PulleyJointDef__DestroyArray(void*);
unsigned int b2PulleyJointDef__Size();
void b2PulleyJointDef_Initialize(void*, void*, void*, void*, void*, void*, void*, float);
void* b2PulleyJointDef__Get_GroundAnchorA(void*);
void b2PulleyJointDef__Set_GroundAnchorA(void*, void*);
void* b2PulleyJointDef__Get_GroundAnchorB(void*);
void b2PulleyJointDef__Set_GroundAnchorB(void*, void*);
void* b2PulleyJointDef__Get_LocalAnchorA(void*);
void b2PulleyJointDef__Set_LocalAnchorA(void*, void*);
void* b2PulleyJointDef__Get_LocalAnchorB(void*);
void b2PulleyJointDef__Set_LocalAnchorB(void*, void*);
float b2PulleyJointDef__Get_LengthA(void*);
void b2PulleyJointDef__Set_LengthA(void*, float);
float b2PulleyJointDef__Get_LengthB(void*);
void b2PulleyJointDef__Set_LengthB(void*, float);
float b2PulleyJointDef__Get_Ratio(void*);
void b2PulleyJointDef__Set_Ratio(void*, float);

//
// Begin class 'b2FixtureProxy'
//
void* b2FixtureProxy__Create();
void* b2FixtureProxy__CreateArray(int);
void b2FixtureProxy__Destroy(void*);
void b2FixtureProxy__DestroyArray(void*);
unsigned int b2FixtureProxy__Size();
void* b2FixtureProxy__Get_Aabb(void*);
void b2FixtureProxy__Set_Aabb(void*, void*);
int b2FixtureProxy__Get_ChildIndex(void*);
void b2FixtureProxy__Set_ChildIndex(void*, int);
int b2FixtureProxy__Get_ProxyId(void*);
void b2FixtureProxy__Set_ProxyId(void*, int);

//
// Begin class 'b2DistanceInput'
//
void* b2DistanceInput__Create();
void* b2DistanceInput__CreateArray(int);
void b2DistanceInput__Destroy(void*);
void b2DistanceInput__DestroyArray(void*);
unsigned int b2DistanceInput__Size();
void* b2DistanceInput__Get_ProxyA(void*);
void b2DistanceInput__Set_ProxyA(void*, void*);
void* b2DistanceInput__Get_ProxyB(void*);
void b2DistanceInput__Set_ProxyB(void*, void*);
void* b2DistanceInput__Get_TransformA(void*);
void b2DistanceInput__Set_TransformA(void*, void*);
void* b2DistanceInput__Get_TransformB(void*);
void b2DistanceInput__Set_TransformB(void*, void*);
unsigned char b2DistanceInput__Get_UseRadii(void*);
void b2DistanceInput__Set_UseRadii(void*, unsigned char);

//
// Begin class 'b2GearJoint'
//
void b2GearJoint__Destroy(void*);
void b2GearJoint__DestroyArray(void*);
unsigned int b2GearJoint__Size();
void* b2GearJoint_GetAnchorA(void*);
float b2GearJoint_GetReactionTorque(void*, float);
void b2GearJoint_SetRatio(void*, float);
float b2GearJoint_GetRatio(void*);
void* b2GearJoint_GetReactionForce(void*, float);
void* b2GearJoint_GetAnchorB(void*);

//
// Begin class 'b2SimplexCache'
//
void* b2SimplexCache__Create();
void* b2SimplexCache__CreateArray(int);
void b2SimplexCache__Destroy(void*);
void b2SimplexCache__DestroyArray(void*);
unsigned int b2SimplexCache__Size();
float b2SimplexCache__Get_Metric(void*);
void b2SimplexCache__Set_Metric(void*, float);
unsigned short b2SimplexCache__Get_Count(void*);
void b2SimplexCache__Set_Count(void*, unsigned short);

//
// Begin class 'b2Rot'
//
void* b2Rot__Create0();
void* b2Rot__Create1(float);
void* b2Rot__CreateArray(int);
void b2Rot__Destroy(void*);
void b2Rot__DestroyArray(void*);
unsigned int b2Rot__Size();
void b2Rot_Set(void*, float);
void* b2Rot_GetXAxis(void*);
void b2Rot_SetIdentity(void*);
void* b2Rot_GetYAxis(void*);
float b2Rot_GetAngle(void*);
float b2Rot__Get_S(void*);
void b2Rot__Set_S(void*, float);
float b2Rot__Get_C(void*);
void b2Rot__Set_C(void*, float);

//
// Begin class 'b2DistanceProxy'
//
void* b2DistanceProxy__Create();
void* b2DistanceProxy__CreateArray(int);
void b2DistanceProxy__Destroy(void*);
void b2DistanceProxy__DestroyArray(void*);
unsigned int b2DistanceProxy__Size();
void* b2DistanceProxy_GetVertex(void*, int);
void* b2DistanceProxy_GetSupportVertex(void*, void*);
void b2DistanceProxy_Set(void*, void*, int);
int b2DistanceProxy_GetVertexCount(void*);
int b2DistanceProxy_GetSupport(void*, void*);
void* b2DistanceProxy__Get_MVertices(void*);
void b2DistanceProxy__Set_MVertices(void*, void*);
int b2DistanceProxy__Get_MCount(void*);
void b2DistanceProxy__Set_MCount(void*, int);
float b2DistanceProxy__Get_MRadius(void*);
void b2DistanceProxy__Set_MRadius(void*, float);

//
// Begin class 'b2MouseJoint'
//
void b2MouseJoint__Destroy(void*);
void b2MouseJoint__DestroyArray(void*);
unsigned int b2MouseJoint__Size();
void b2MouseJoint_SetDampingRatio(void*, float);
void* b2MouseJoint_GetAnchorA(void*);
float b2MouseJoint_GetReactionTorque(void*, float);
void b2MouseJoint_SetFrequency(void*, float);
float b2MouseJoint_GetDampingRatio(void*);
void b2MouseJoint_SetTarget(void*, void*);
void b2MouseJoint_SetMaxForce(void*, float);
float b2MouseJoint_GetFrequency(void*);
void* b2MouseJoint_GetTarget(void*);
float b2MouseJoint_GetMaxForce(void*);
void* b2MouseJoint_GetAnchorB(void*);
void* b2MouseJoint_GetReactionForce(void*, float);

//
// Begin class 'b2WheelJointDef'
//
void* b2WheelJointDef__Create();
void* b2WheelJointDef__CreateArray(int);
void b2WheelJointDef__Destroy(void*);
void b2WheelJointDef__DestroyArray(void*);
unsigned int b2WheelJointDef__Size();
void b2WheelJointDef_Initialize(void*, void*, void*, void*, void*);
void* b2WheelJointDef__Get_LocalAnchorA(void*);
void b2WheelJointDef__Set_LocalAnchorA(void*, void*);
void* b2WheelJointDef__Get_LocalAnchorB(void*);
void b2WheelJointDef__Set_LocalAnchorB(void*, void*);
void* b2WheelJointDef__Get_LocalAxisA(void*);
void b2WheelJointDef__Set_LocalAxisA(void*, void*);
unsigned char b2WheelJointDef__Get_EnableMotor(void*);
void b2WheelJointDef__Set_EnableMotor(void*, unsigned char);
float b2WheelJointDef__Get_MaxMotorTorque(void*);
void b2WheelJointDef__Set_MaxMotorTorque(void*, float);
float b2WheelJointDef__Get_MotorSpeed(void*);
void b2WheelJointDef__Set_MotorSpeed(void*, float);
float b2WheelJointDef__Get_FrequencyHz(void*);
void b2WheelJointDef__Set_FrequencyHz(void*, float);
float b2WheelJointDef__Get_DampingRatio(void*);
void b2WheelJointDef__Set_DampingRatio(void*, float);

//
// Begin class 'b2Timer'
//
void* b2Timer__Create();
void* b2Timer__CreateArray(int);
void b2Timer__Destroy(void*);
void b2Timer__DestroyArray(void*);
unsigned int b2Timer__Size();
void b2Timer_Reset(void*);
float b2Timer_GetMilliseconds(void*);

//
// Begin class 'b2Transform'
//
void* b2Transform__Create0();
void* b2Transform__Create1(void*, void*);
void* b2Transform__CreateArray(int);
void b2Transform__Destroy(void*);
void b2Transform__DestroyArray(void*);
unsigned int b2Transform__Size();
void b2Transform_Set(void*, void*, float);
void b2Transform_SetIdentity(void*);
void* b2Transform__Get_P(void*);
void b2Transform__Set_P(void*, void*);
void* b2Transform__Get_Q(void*);
void b2Transform__Set_Q(void*, void*);

//
// Begin class 'b2DynamicTree'
//
void* b2DynamicTree__Create();
void* b2DynamicTree__CreateArray(int);
void b2DynamicTree__Destroy(void*);
void b2DynamicTree__DestroyArray(void*);
unsigned int b2DynamicTree__Size();
void* b2DynamicTree_GetFatAABB(void*, int);
void* b2DynamicTree_GetUserData(void*, int);
int b2DynamicTree_GetMaxBalance(void*);
int b2DynamicTree_GetHeight(void*);
float b2DynamicTree_GetAreaRatio(void*);
void b2DynamicTree_RebuildBottomUp(void*);
int b2DynamicTree_CreateProxy(void*, void*, void*);
unsigned char b2DynamicTree_MoveProxy(void*, int, void*, void*);
void b2DynamicTree_Validate(void*);
void b2DynamicTree_DestroyProxy(void*, int);

//
// Begin class 'b2Mat22'
//
void* b2Mat22__Create0();
void* b2Mat22__Create1(void*, void*);
void* b2Mat22__Create2(float, float, float, float);
void* b2Mat22__Create3(void*);
void* b2Mat22__CreateArray(int);
void b2Mat22__Destroy(void*);
void b2Mat22__DestroyArray(void*);
unsigned int b2Mat22__Size();
void b2Mat22_SetZero(void*);
void* b2Mat22_GetInverse(void*);
void b2Mat22_Set(void*, void*, void*);
void* b2Mat22_Solve(void*, void*);
void b2Mat22_SetIdentity(void*);
void* b2Mat22__Get_Ex(void*);
void b2Mat22__Set_Ex(void*, void*);
void* b2Mat22__Get_Ey(void*);
void b2Mat22__Set_Ey(void*, void*);

//
// Begin class 'b2Velocity'
//
void* b2Velocity__Create();
void* b2Velocity__CreateArray(int);
void b2Velocity__Destroy(void*);
void b2Velocity__DestroyArray(void*);
unsigned int b2Velocity__Size();
void* b2Velocity__Get_V(void*);
void b2Velocity__Set_V(void*, void*);
float b2Velocity__Get_W(void*);
void b2Velocity__Set_W(void*, float);

//
// Begin class 'b2StackAllocator'
//
void* b2StackAllocator__Create();
void* b2StackAllocator__CreateArray(int);
void b2StackAllocator__Destroy(void*);
void b2StackAllocator__DestroyArray(void*);
unsigned int b2StackAllocator__Size();
int b2StackAllocator_GetMaxAllocation(void*);
void* b2StackAllocator_Allocate(void*, int);
void b2StackAllocator_Free(void*, void*);

//
// Begin class 'b2RopeJoint'
//
void b2RopeJoint__Destroy(void*);
void b2RopeJoint__DestroyArray(void*);
unsigned int b2RopeJoint__Size();
void* b2RopeJoint_GetAnchorA(void*);
float b2RopeJoint_GetReactionTorque(void*, float);
float b2RopeJoint_GetMaxLength(void*);
void* b2RopeJoint_GetAnchorB(void*);
void* b2RopeJoint_GetReactionForce(void*, float);
unsigned int b2RopeJoint_GetLimitState(void*);

//
// Begin class 'b2WorldManifold'
//
void* b2WorldManifold__Create();
void* b2WorldManifold__CreateArray(int);
void b2WorldManifold__Destroy(void*);
void b2WorldManifold__DestroyArray(void*);
unsigned int b2WorldManifold__Size();
void b2WorldManifold_Initialize(void*, void*, void*, float, void*, float);
void* b2WorldManifold__Get_Normal(void*);
void b2WorldManifold__Set_Normal(void*, void*);

//
// Begin class 'b2Filter'
//
void* b2Filter__Create();
void* b2Filter__CreateArray(int);
void b2Filter__Destroy(void*);
void b2Filter__DestroyArray(void*);
unsigned int b2Filter__Size();
unsigned short b2Filter__Get_CategoryBits(void*);
void b2Filter__Set_CategoryBits(void*, unsigned short);
unsigned short b2Filter__Get_MaskBits(void*);
void b2Filter__Set_MaskBits(void*, unsigned short);
short b2Filter__Get_GroupIndex(void*);
void b2Filter__Set_GroupIndex(void*, short);

//
// Begin class 'b2ContactManager'
//
void* b2ContactManager__Create();
void* b2ContactManager__CreateArray(int);
void b2ContactManager__Destroy(void*);
void b2ContactManager__DestroyArray(void*);
unsigned int b2ContactManager__Size();
void b2ContactManager_FindNewContacts(void*);
void b2ContactManager_Collide(void*);
void b2ContactManager_AddPair(void*, void*, void*);
void b2ContactManager_Destroy(void*, void*);
void* b2ContactManager__Get_MBroadPhase(void*);
void b2ContactManager__Set_MBroadPhase(void*, void*);
int b2ContactManager__Get_MContactCount(void*);
void b2ContactManager__Set_MContactCount(void*, int);
void* b2ContactManager__Get_MContactFilter(void*);
void b2ContactManager__Set_MContactFilter(void*, void*);
void* b2ContactManager__Get_MContactListener(void*);
void b2ContactManager__Set_MContactListener(void*, void*);
void* b2ContactManager__Get_MAllocator(void*);
void b2ContactManager__Set_MAllocator(void*, void*);

//
// Begin class 'b2RayCastInput'
//
void* b2RayCastInput__Create();
void* b2RayCastInput__CreateArray(int);
void b2RayCastInput__Destroy(void*);
void b2RayCastInput__DestroyArray(void*);
unsigned int b2RayCastInput__Size();
void* b2RayCastInput__Get_P1(void*);
void b2RayCastInput__Set_P1(void*, void*);
void* b2RayCastInput__Get_P2(void*);
void b2RayCastInput__Set_P2(void*, void*);
float b2RayCastInput__Get_MaxFraction(void*);
void b2RayCastInput__Set_MaxFraction(void*, float);

//
// Begin class 'b2Color'
//
void* b2Color__Create0();
void* b2Color__Create1(float, float, float);
void* b2Color__CreateArray(int);
void b2Color__Destroy(void*);
void b2Color__DestroyArray(void*);
unsigned int b2Color__Size();
void b2Color_Set(void*, float, float, float);
float b2Color__Get_R(void*);
void b2Color__Set_R(void*, float);
float b2Color__Get_G(void*);
void b2Color__Set_G(void*, float);
float b2Color__Get_B(void*);
void b2Color__Set_B(void*, float);

//
// Begin class 'b2EdgeShape'
//
void* b2EdgeShape__Create();
void* b2EdgeShape__CreateArray(int);
void b2EdgeShape__Destroy(void*);
void b2EdgeShape__DestroyArray(void*);
unsigned int b2EdgeShape__Size();
void b2EdgeShape_Set(void*, void*, void*);
void b2EdgeShape_ComputeMass(void*, void*, float);
void* b2EdgeShape_Clone(void*, void*);
unsigned char b2EdgeShape_RayCast(void*, void*, void*, void*, int);
void b2EdgeShape_ComputeAABB(void*, void*, void*, int);
int b2EdgeShape_GetChildCount(void*);
unsigned char b2EdgeShape_TestPoint(void*, void*, void*);
void* b2EdgeShape__Get_MVertex1(void*);
void b2EdgeShape__Set_MVertex1(void*, void*);
void* b2EdgeShape__Get_MVertex2(void*);
void b2EdgeShape__Set_MVertex2(void*, void*);
void* b2EdgeShape__Get_MVertex0(void*);
void b2EdgeShape__Set_MVertex0(void*, void*);
void* b2EdgeShape__Get_MVertex3(void*);
void b2EdgeShape__Set_MVertex3(void*, void*);
unsigned char b2EdgeShape__Get_MHasVertex0(void*);
void b2EdgeShape__Set_MHasVertex0(void*, unsigned char);
unsigned char b2EdgeShape__Get_MHasVertex3(void*);
void b2EdgeShape__Set_MHasVertex3(void*, unsigned char);

//
// Begin class 'b2Joint'
//
unsigned int b2Joint__Size();
void* b2Joint_GetNext0(void*);
void* b2Joint_GetNext1(void*);
void* b2Joint_GetBodyA(void*);
void* b2Joint_GetBodyB(void*);
void* b2Joint_GetUserData(void*);
unsigned int b2Joint_GetType(void*);
void b2Joint_SetUserData(void*, void*);
unsigned char b2Joint_GetCollideConnected(void*);
unsigned char b2Joint_IsActive(void*);

//
// Begin class 'b2JointDef'
//
void* b2JointDef__Create();
void* b2JointDef__CreateArray(int);
void b2JointDef__Destroy(void*);
void b2JointDef__DestroyArray(void*);
unsigned int b2JointDef__Size();
unsigned int b2JointDef__Get_Type(void*);
void b2JointDef__Set_Type(void*, unsigned int);
void* b2JointDef__Get_BodyA(void*);
void b2JointDef__Set_BodyA(void*, void*);
void* b2JointDef__Get_BodyB(void*);
void b2JointDef__Set_BodyB(void*, void*);
unsigned char b2JointDef__Get_CollideConnected(void*);
void b2JointDef__Set_CollideConnected(void*, unsigned char);

//
// Begin class 'b2StackEntry'
//
void* b2StackEntry__Create();
void* b2StackEntry__CreateArray(int);
void b2StackEntry__Destroy(void*);
void b2StackEntry__DestroyArray(void*);
unsigned int b2StackEntry__Size();
int b2StackEntry__Get_Size(void*);
void b2StackEntry__Set_Size(void*, int);
unsigned char b2StackEntry__Get_UsedMalloc(void*);
void b2StackEntry__Set_UsedMalloc(void*, unsigned char);

//
// Begin class 'b2LoopShape'
//
void* b2LoopShape__Create();
void* b2LoopShape__CreateArray(int);
void b2LoopShape__Destroy(void*);
void b2LoopShape__DestroyArray(void*);
unsigned int b2LoopShape__Size();
void* b2LoopShape_GetVertices(void*);
void b2LoopShape_ComputeMass(void*, void*, float);
void b2LoopShape_Create(void*, void*, int);
void* b2LoopShape_GetVertex(void*, int);
void b2LoopShape_GetChildEdge(void*, void*, int);
unsigned char b2LoopShape_RayCast(void*, void*, void*, void*, int);
void b2LoopShape_ComputeAABB(void*, void*, void*, int);
int b2LoopShape_GetChildCount(void*);
unsigned char b2LoopShape_TestPoint(void*, void*, void*);
int b2LoopShape_GetCount(void*);
void* b2LoopShape_Clone(void*, void*);

//
// Begin class 'b2DestructionListener'
//
void b2DestructionListener__Destroy(void*);
void b2DestructionListener__DestroyArray(void*);
unsigned int b2DestructionListener__Size();

//
// Begin class 'b2GearJointDef'
//
void* b2GearJointDef__Create();
void* b2GearJointDef__CreateArray(int);
void b2GearJointDef__Destroy(void*);
void b2GearJointDef__DestroyArray(void*);
unsigned int b2GearJointDef__Size();
void* b2GearJointDef__Get_Joint1(void*);
void b2GearJointDef__Set_Joint1(void*, void*);
void* b2GearJointDef__Get_Joint2(void*);
void b2GearJointDef__Set_Joint2(void*, void*);
float b2GearJointDef__Get_Ratio(void*);
void b2GearJointDef__Set_Ratio(void*, float);

//
// Begin class 'b2ContactEdge'
//
void* b2ContactEdge__Create();
void* b2ContactEdge__CreateArray(int);
void b2ContactEdge__Destroy(void*);
void b2ContactEdge__DestroyArray(void*);
unsigned int b2ContactEdge__Size();
void* b2ContactEdge__Get_Other(void*);
void b2ContactEdge__Set_Other(void*, void*);
void* b2ContactEdge__Get_Prev(void*);
void b2ContactEdge__Set_Prev(void*, void*);
void* b2ContactEdge__Get_Next(void*);
void b2ContactEdge__Set_Next(void*, void*);

//
// Begin class 'b2Manifold'
//
void* b2Manifold__Create();
void* b2Manifold__CreateArray(int);
void b2Manifold__Destroy(void*);
void b2Manifold__DestroyArray(void*);
unsigned int b2Manifold__Size();
void* b2Manifold__Get_LocalNormal(void*);
void b2Manifold__Set_LocalNormal(void*, void*);
void* b2Manifold__Get_LocalPoint(void*);
void b2Manifold__Set_LocalPoint(void*, void*);
unsigned int b2Manifold__Get_Type(void*);
void b2Manifold__Set_Type(void*, unsigned int);
int b2Manifold__Get_PointCount(void*);
void b2Manifold__Set_PointCount(void*, int);

//
// Begin class 'b2AABB'
//
void* b2AABB__Create();
void* b2AABB__CreateArray(int);
void b2AABB__Destroy(void*);
void b2AABB__DestroyArray(void*);
unsigned int b2AABB__Size();
unsigned char b2AABB_IsValid(void*);
unsigned char b2AABB_Contains(void*, void*);
void* b2AABB_GetExtents(void*);
void* b2AABB_GetCenter(void*);
float b2AABB_GetPerimeter(void*);
void b2AABB_Combine0(void*, void*);
void b2AABB_Combine1(void*, void*, void*);
unsigned char b2AABB_RayCast(void*, void*, void*);
void* b2AABB__Get_LowerBound(void*);
void b2AABB__Set_LowerBound(void*, void*);
void* b2AABB__Get_UpperBound(void*);
void b2AABB__Set_UpperBound(void*, void*);

//
// Begin class 'b2FixtureDef'
//
void* b2FixtureDef__Create();
void* b2FixtureDef__CreateArray(int);
void b2FixtureDef__Destroy(void*);
void b2FixtureDef__DestroyArray(void*);
unsigned int b2FixtureDef__Size();
void* b2FixtureDef__Get_Shape(void*);
void b2FixtureDef__Set_Shape(void*, void*);
float b2FixtureDef__Get_Friction(void*);
void b2FixtureDef__Set_Friction(void*, float);
float b2FixtureDef__Get_Restitution(void*);
void b2FixtureDef__Set_Restitution(void*, float);
float b2FixtureDef__Get_Density(void*);
void b2FixtureDef__Set_Density(void*, float);
unsigned char b2FixtureDef__Get_IsSensor(void*);
void b2FixtureDef__Set_IsSensor(void*, unsigned char);
void* b2FixtureDef__Get_Filter(void*);
void b2FixtureDef__Set_Filter(void*, void*);

//
// Begin class 'b2ManifoldPoint'
//
void* b2ManifoldPoint__Create();
void* b2ManifoldPoint__CreateArray(int);
void b2ManifoldPoint__Destroy(void*);
void b2ManifoldPoint__DestroyArray(void*);
unsigned int b2ManifoldPoint__Size();
void* b2ManifoldPoint__Get_LocalPoint(void*);
void b2ManifoldPoint__Set_LocalPoint(void*, void*);
float b2ManifoldPoint__Get_NormalImpulse(void*);
void b2ManifoldPoint__Set_NormalImpulse(void*, float);
float b2ManifoldPoint__Get_TangentImpulse(void*);
void b2ManifoldPoint__Set_TangentImpulse(void*, float);

//
// Begin class 'b2BodyDef'
//
void* b2BodyDef__Create();
void* b2BodyDef__CreateArray(int);
void b2BodyDef__Destroy(void*);
void b2BodyDef__DestroyArray(void*);
unsigned int b2BodyDef__Size();
unsigned int b2BodyDef__Get_Type(void*);
void b2BodyDef__Set_Type(void*, unsigned int);
void* b2BodyDef__Get_Position(void*);
void b2BodyDef__Set_Position(void*, void*);
float b2BodyDef__Get_Angle(void*);
void b2BodyDef__Set_Angle(void*, float);
void* b2BodyDef__Get_LinearVelocity(void*);
void b2BodyDef__Set_LinearVelocity(void*, void*);
float b2BodyDef__Get_AngularVelocity(void*);
void b2BodyDef__Set_AngularVelocity(void*, float);
float b2BodyDef__Get_LinearDamping(void*);
void b2BodyDef__Set_LinearDamping(void*, float);
float b2BodyDef__Get_AngularDamping(void*);
void b2BodyDef__Set_AngularDamping(void*, float);
unsigned char b2BodyDef__Get_AllowSleep(void*);
void b2BodyDef__Set_AllowSleep(void*, unsigned char);
unsigned char b2BodyDef__Get_Awake(void*);
void b2BodyDef__Set_Awake(void*, unsigned char);
unsigned char b2BodyDef__Get_FixedRotation(void*);
void b2BodyDef__Set_FixedRotation(void*, unsigned char);
unsigned char b2BodyDef__Get_Bullet(void*);
void b2BodyDef__Set_Bullet(void*, unsigned char);
unsigned char b2BodyDef__Get_Active(void*);
void b2BodyDef__Set_Active(void*, unsigned char);
float b2BodyDef__Get_GravityScale(void*);
void b2BodyDef__Set_GravityScale(void*, float);

//
// Begin class 'b2WeldJointDef'
//
void* b2WeldJointDef__Create();
void* b2WeldJointDef__CreateArray(int);
void b2WeldJointDef__Destroy(void*);
void b2WeldJointDef__DestroyArray(void*);
unsigned int b2WeldJointDef__Size();
void b2WeldJointDef_Initialize(void*, void*, void*, void*);
void* b2WeldJointDef__Get_LocalAnchorA(void*);
void b2WeldJointDef__Set_LocalAnchorA(void*, void*);
void* b2WeldJointDef__Get_LocalAnchorB(void*);
void b2WeldJointDef__Set_LocalAnchorB(void*, void*);
float b2WeldJointDef__Get_ReferenceAngle(void*);
void b2WeldJointDef__Set_ReferenceAngle(void*, float);

//
// Begin class 'b2ClipVertex'
//
void* b2ClipVertex__Create();
void* b2ClipVertex__CreateArray(int);
void b2ClipVertex__Destroy(void*);
void b2ClipVertex__DestroyArray(void*);
unsigned int b2ClipVertex__Size();
void* b2ClipVertex__Get_V(void*);
void b2ClipVertex__Set_V(void*, void*);

//
// Begin class 'b2BroadPhase'
//
void* b2BroadPhase__Create();
void* b2BroadPhase__CreateArray(int);
void b2BroadPhase__Destroy(void*);
void b2BroadPhase__DestroyArray(void*);
unsigned int b2BroadPhase__Size();
float b2BroadPhase_GetTreeQuality(void*);
void* b2BroadPhase_GetFatAABB(void*, int);
void* b2BroadPhase_GetUserData(void*, int);
int b2BroadPhase_GetTreeHeight(void*);
int b2BroadPhase_GetProxyCount(void*);
unsigned char b2BroadPhase_TestOverlap(void*, int, int);
void b2BroadPhase_TouchProxy(void*, int);
int b2BroadPhase_GetTreeBalance(void*);
int b2BroadPhase_CreateProxy(void*, void*, void*);
void b2BroadPhase_MoveProxy(void*, int, void*, void*);
void b2BroadPhase_DestroyProxy(void*, int);

//
// Begin class 'b2Contact'
//
unsigned int b2Contact__Size();
float b2Contact_GetRestitution(void*);
void b2Contact_SetFriction(void*, float);
void b2Contact_SetRestitution(void*, float);
void* b2Contact_GetNext0(void*);
void* b2Contact_GetNext1(void*);
float b2Contact_GetFriction(void*);
void b2Contact_ResetFriction(void*);
unsigned char b2Contact_IsTouching(void*);
int b2Contact_GetChildIndexA(void*);
int b2Contact_GetChildIndexB(void*);
void b2Contact_GetWorldManifold(void*, void*);
unsigned char b2Contact_IsEnabled(void*);
void b2Contact_SetEnabled(void*, unsigned char);
void* b2Contact_GetFixtureB0(void*);
void* b2Contact_GetFixtureB1(void*);
void* b2Contact_GetFixtureA0(void*);
void* b2Contact_GetFixtureA1(void*);
void* b2Contact_GetManifold0(void*);
void* b2Contact_GetManifold1(void*);
void b2Contact_ResetRestitution(void*);
}
