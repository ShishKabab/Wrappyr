#!/usr/bin/env python2.6
from wrappyr_runtime import arrayof

#from Box2D.common import b2Vec2
#from Box2D.collision.shapes import b2PolygonShape
#from Box2D.dynamics import b2World, b2Body, b2BodyDef, b2FixtureDef, b2RayCastCallback

from Box2D import *

class MyRayCastCallback(b2RayCastCallback):
	def ReportFixture(self, fixture, point, normal, fraction):
		print self, fixture, (point.x, point.y), (normal.x, normal.y), fraction
		return 1.0

gravity = b2Vec2(0.0, -9.8)
world = b2World(gravity, False)

groundBodyDef = b2BodyDef()
groundBodyDef.position = b2Vec2(0.0, -10.0)
groundBody = world.CreateBody(groundBodyDef)

groundBox = b2PolygonShape()
groundBox.SetAsBox(50.0, 10.0)

fixtureDef = b2FixtureDef()
fixtureDef.shape = groundBox
fixtureDef.density = 0.0
fixtureDef.friction = 0.3
groundBody.CreateFixture(fixtureDef)

bodyDef = b2BodyDef()
bodyDef.type = 2
bodyDef.position = b2Vec2(0.0, 4.0)
body = world.CreateBody(bodyDef)

dynamicBox = b2PolygonShape()
dynamicBox.SetAsBox(1.0, 1.0)

fixtureDef = b2FixtureDef()
fixtureDef.shape = dynamicBox
fixtureDef.density = 1.0
fixtureDef.friction = 0.3
body.CreateFixture(fixtureDef)

slopeBodyDef = b2BodyDef()
slopeBodyDef.position = b2Vec2(0.0, -9.0)
slopeBody = world.CreateBody(slopeBodyDef)

vertices = arrayof(b2Vec2, 3)
vertices[0].Set(0.0, 0.0)
vertices[1].Set(0.5, 0.0)
vertices[2].Set(0.0, 0.5)
for vertex in vertices:
	print vertex.x, vertex.y

slopeShape = b2PolygonShape()
slopeShape.Set(vertices, 3)

fixtureDef = b2FixtureDef()
fixtureDef.shape = slopeShape
fixtureDef.density = 0.0
fixtureDef.friction = 0.3
slopeBody.CreateFixture(fixtureDef)

print "-----"

timeStep = 1.0 / 60.0
velocityIterations = 6
positionIterations = 2
for i in range(60):
	world.Step(timeStep, velocityIterations, positionIterations)
	world.ClearForces()

	#position = body.position
	#angle = body.angle

	position = body.GetPosition()
	angle = body.GetAngle()

	print "%4.2f %4.2f %4.2f" % (position.x, position.y, angle)

import ipdb; ipdb.set_trace()

world.RayCast(MyRayCastCallback(), b2Vec2(-0.7, -9.0), b2Vec2(0.3, -9.0))
