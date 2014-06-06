#include "GeometryObject.h"

GeometryObject::GeometryObject()
{
	this->m_transform = glm::mat4();
}

GeometryObject::~GeometryObject()
{
	
}

int GeometryObject::getVertexCount() const
{
	return 4;
}

int GeometryObject::getTriangleCount() const
{
	return 2;
}

int GeometryObject::getVertices(vec3* verts) const
{
	if (sizeof(verts) >= this->getVertexCount())
	{
		verts[0] = vec3(-0.5f, 0.5f, 0.0f);
		verts[1] = vec3( 0.5f, 0.5f, 0.0f);
		verts[2] = vec3( 0.5f,-0.5f, 0.0f);
		verts[3] = vec3(-0.5f,-0.5f, 0.0f);
		return 4;
	}
	return 0;
}

int GeometryObject::getUVs(vec2 *uvs) const
{
	if (sizeof(uvs) >= this->getVertexCount())
	{
		uvs[0] = vec2( 0.0f, 1.0f);
		uvs[1] = vec2( 1.0f, 1.0f);
		uvs[2] = vec2( 1.0f, 0.0f);
		uvs[3] = vec2( 0.0f, 0.0f);
		return 4;
	}
	return 0;
}

int GeometryObject::getIndices(int *indices) const
{
	if (sizeof(indices) >= (this->getTriangleCount() * 3))
	{
		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;
		indices[4] = 1;
		indices[5] = 3;
		indices[6] = 2;
		return 6;
	}
	return 0;
}