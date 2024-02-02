/**************************************************************************/
/*  occluder.h                                                            */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef OCCLUDER_H
#define OCCLUDER_H

#include "scene/3d/spatial.h"
#include "scene/resources/occluder_shape.h"

class Occluder : public Spatial {
	GDCLASS(Occluder, Spatial);

	friend class OccluderSpatialGizmo;
	friend class OccluderEditorPlugin;

	RID _occluder_instance;
	Ref<OccluderShape> _shape;

	void resource_changed(RES res);

protected:
	void _notification(int p_what);
	static void _bind_methods();

public:
	void set_shape(const Ref<OccluderShape> &p_shape);
	Ref<OccluderShape> get_shape() const;

	String get_configuration_warning() const;

#ifdef TOOLS_ENABLED
	// for editor gizmo
	virtual AABB get_fallback_gizmo_aabb() const;
#endif

	Occluder();
	~Occluder();
};

#endif // OCCLUDER_H