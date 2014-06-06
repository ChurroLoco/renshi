#pragma once

#include <list>
#include <glm/glm.hpp>

using namespace std;
using namespace glm;

class GeometryObject
{
	GeometryObject();
	~GeometryObject();
	
	/**
	 * @returns The number of vertices in the geometry
	 */
	int getVertexCount() const;
	
	/**
	 * @returns The number of triangles in the geometry
	 */
	int getTriangleCount() const;
	
	/**
	 * Fill an array with this object's vertices.
	 * The array should be allocated to the size of GeometryObject::getVertCount().
	 * @returns The number of vertices put in the array
	 */
	int getVertices(vec3* verts) const;
	
	/**
	 * Fill an array with this object's UVs.
	 * The array should be allocated to the size of GeometryObject::getVertCount().
	 * @returns The number of UVs put in the array
	 */
	int getUVs(vec2* uvs) const;
	
	/**
	 * Fill an array with this object's indices.
	 * The array should be allocated to the size of GeometryObject::getTriangleCount() * 3.
	 * @returns The number of indices put in the array
	 */
	int getIndices(int* indices) const;
	
private:
	mat4 m_transform; ///< Describes the 3D orientation of this object
};
