==================
Ctypes API builder
==================
The Ctypes API builder works by first creating a structure describing packages, modules, classes, etc. and the relationships between them. This structure can be loaded from XML, or can be created using the classes provided in structure.py. After that, you can do some extra processing like cosmetic restructuring of the classes and removing ambigous method overloads, etc. As the last step this structure is passed into the export.export_structure which creates the directory structure and Python code described by the structure you pass to it.

When writing the classes used in the structure, I found myself to be writing lots of boiler-plate code to handle child nodes and loading from XML. So I've decided to move this code out of the classes and generate them automatically. The disadvantage of this approach that you can't find some standard methods when scanning through the code. So until a more elagant solution is found, I recommend running 'pydoc ctypes_builder.structure' in the root of this project to view the full API of structure.py.

An example says more than words, so I'll just use an example Ctypes XML to explain how the structure is set up.

<ctypes>
	<!--
	The root of the structure only contains packages and modules. The packages and modules you
	define here will be created in the directory you passed to the generate_ctypes_api.py
	script with the --output-path option.
	-->

	<package name="Box2D">
		<!--
		Every class and function contained in a package will be written to the package's __init__.py.
		You can also create modules with the <module> tag. Those work the same way as packages except
		that they cannot contain other modules and packages (obviously).
		-->

		<library name="Box2DC" path="./libBox2DC.so" default="true" />
		<!--
		Each package and module can use one or more libraries. The name and path are manditory
		and default defaults to false. If set default to true, every call in this package and
		its children will make its C calls to this library if you do not explicitly tell
		which library contains the call to be made,
		-->

		<package name="common">
			<class name="b2Vec2">
				<!--
				A class can contain methods and members. When it's implemented, you should
				also be able to specify its base classes and what should happen when
				the user derives from this class.
				-->

				<method name="__init__">
					<!--
					A function or method can respresent multiple C call depending on
					the amount of parameters passed. Currently, it is not supported for
					a function to contain C calls that don't share common arguments (the class
					to remove conflicting calls lives in generate_ctypes_api.ConflictingOverloadRemover).
					Als, default arguments are not supported yet.

					For each C call, you can specify which library to use by setting
					the library attribute to the name of a library. That library is
					looked up in the parents of the call. Maybe this behaviour should
					be changed so you can pass the full structure path (see below) to
					a library to the library attribute.

					For now, the return value of all calls made in the constructor is assumed to be
					a void pointer and is stored for later use in methods, getters and setters.
					-->

					<call symbol="b2Vec2__Create0" />
					<call symbol="b2Vec2__Create1">
						<!--
						Types of arguments and return values are specified by either
						ctypes.* or the full path to a class somewhere in the structure
						(e.g. Box2D.common.b2Vec2). After this file is read, all type strings
						are replaced by their actual Class instance so you don't have to worry
						about type paths when shuffling classes, methods and functions around in code.

						An a
						-->

						<argument name="x" type="ctypes.c_float" />
						<argument name="y" type="ctypes.c_float" />
					</call>
				</method>
				<method name="Length">
					<!--
					All calls in methods and members except for the __init__ method
					are passed an implicit first void* argument which is the value
					returned from a call in the __init__ method.
					-->

					<method name="Skew">
						<call symbol="b2Vec2_Skew">
							<!--
							A return value has a type string that like with the
							type of an argument is replaced with an actual Class
							instance once the XML file has been loaded. Also, if
							a class instance is returned from the C call, you can
							specify that the object returned is now owned by Python
							and should be destroyed along with Python object when
							it is no longer needed.
							-->
							<returns type="Box2D.b2Vec2" ownership="1" />
						</call>
					</method>
				</method>
				<member name="x">
					<!--
					A member is used to wrap a getter and a setter into a Python property.
					Both the getter and setter are optional and are represented by an
					anonymous Method instance.
					-->

					<getter>

						<call symbol="b2Vec2__GetX">
							<returns type="ctypes.c_float" />
						</call>
					</getter>
					<setter>
						<call symbol="b2Vec2__SetX">
							<argument type="ctypes.c_float" />
						</call>
					</setter>
				</member>
			</class>
		</package>
		<package name="collision">
			<package name="shapes">
				<class name="b2PolygonShape">
					<method name="__init__">
						<call symbol="b2PolygonShape__Create" />
					</method>
					<method name="SetAsBox">
						<!--
						This is an exaple of two calls that share common arguments.
						-->

						<call symbol="b2PolygonShape_SetAsBox0">
							<argument name="half_width" type="ctypes.c_float" />
							<argument name="half_height" type="ctypes.c_float" />
						</call>
						<call symbol="b2PolygonShape_SetAsBox1">
							<argument name="half_width" type="ctypes.c_float" />
							<argument name="half_height" type="ctypes.c_float" />
							<argument name="center" type="Box2D.common.b2Vec2" />
							<argument name="angle" type="ctypes.c_float" />
						</call>
					</method>
				</class>
			</package>
		</package>
		<package name="dynamics">
			<class name="b2World">
				<method name="__init__">
					<call symbol="b2World__Create">
						<argument name="gravity" type="Box2D.common.b2Vec2" />
						<argument name="doSleep" type="ctypes.c_ubyte" />
					</call>
				</method>
			</class>
		</package>
	</package>
</ctypes>

