/***************************************************************************
 *   Copyright (C) 2005-2007 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

// Standard C++ library includes

// 3rd party library includes
#include <SDL.h>

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "util/purge.h"

#include "layer.h"
#include "instance.h"
#include "elevation.h"
#include "instancetree.h"

namespace FIFE {

	Layer::Layer(const std::string& identifier, Elevation* elevation, CellGrid* grid)
		: AttributedClass(identifier),
		m_elevation(elevation),
		m_instances_visibility(true),
		m_instanceTree(new InstanceTree()),
		m_grid(grid) {
	}

	Layer::~Layer() {
		purge(m_instances);
		delete m_instanceTree;
	}

	bool Layer::hasInstances() const {
		return !m_instances.empty();
	}

	Instance* Layer::addInstance(Object* object, const ModelCoordinate& p, const std::string& id) {
		Location l;
		l.setLayer(this);
		l.setLayerCoordinates(p);

		Instance* instance = new Instance(object, l, id);
		m_instances.push_back(instance);
		m_instanceTree->addInstance(instance);
		return instance;
	}

	Instance* Layer::addInstance(Object* object, const ExactModelCoordinate& p, const std::string& id) {
		Location l;
		l.setLayer(this);
		l.setExactLayerCoordinates(p);

		Instance* instance = new Instance(object, l, id);
		m_instances.push_back(instance);
		m_instanceTree->addInstance(instance);
		return instance;
	}
	
	void Layer::removeInstance(Instance* instance) {
		std::vector<Instance*>::iterator it = m_instances.begin();
		for(; it != m_instances.end(); ++it) {
			if(*it == instance) {
				delete *it;
				m_instances.erase(it);
				m_instanceTree->removeInstance(*it);
				break;
			}
		}
	}

	const std::vector<Instance*>& Layer::getInstances() {
		return m_instances;
	}

	std::vector<Instance*> Layer::getInstances(const std::string& field, const std::string& value) {
		std::vector<Instance*> matches;

		std::vector<Instance*>::iterator it = m_instances.begin();
		for(; it != m_instances.end(); ++it) {
			if((*it)->get(field) == value)
				matches.push_back(*it);
		}

		return matches;
	}

	void Layer::setInstancesVisible(bool vis) {
		m_instances_visibility = vis;
	}
	void Layer::toggleInstancesVisible() {
		m_instances_visibility = !m_instances_visibility;
	}

	void Layer::update() {
		unsigned int curticks = SDL_GetTicks();
		std::vector<Instance*>::iterator it = m_instances.begin();
		for(; it != m_instances.end(); ++it) {
			(*it)->update(curticks);
		}
	}

} // FIFE
