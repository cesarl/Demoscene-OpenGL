#ifndef  __MATERIAL_HH__
# define __MATERIAL_HH__

#include <set>

#include "Utils/SmartPointer.hh"

namespace Component
{
	class MeshRenderer;
};
class MaterialManager;

class Material
{
public:
private:
	MaterialManager *_manager;
	std::set<std::string> _shaders;
	std::set<Component::MeshRenderer*> _meshs;
	std::string _name;
	// TODO ass an FB pointer for _lastFrameBuffer;
public:
	Material(MaterialManager *manager, const std::string &name);
	~Material();
	Material &pushShader(const std::string &shader);
	const std::set<std::string> &getShaders() const;
	void addObject(Component::MeshRenderer *object);
	void removeObject(Component::MeshRenderer *object);
	inline const std::string &getName() {return _name;}
	inline std::set<Component::MeshRenderer*> &getObjects() {return _meshs;}
private:
	Material(const Material &o);
	Material &operator=(const Material &o);
};

#endif   //!__MATERIAL_HH__