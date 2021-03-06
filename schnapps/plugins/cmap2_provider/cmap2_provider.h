/*******************************************************************************
* SCHNApps                                                                     *
* Copyright (C) 2016, IGG Group, ICube, University of Strasbourg, France       *
*                                                                              *
* This library is free software; you can redistribute it and/or modify it      *
* under the terms of the GNU Lesser General Public License as published by the *
* Free Software Foundation; either version 2.1 of the License, or (at your     *
* option) any later version.                                                   *
*                                                                              *
* This library is distributed in the hope that it will be useful, but WITHOUT  *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License  *
* for more details.                                                            *
*                                                                              *
* You should have received a copy of the GNU Lesser General Public License     *
* along with this library; if not, write to the Free Software Foundation,      *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.           *
*                                                                              *
* Web site: http://cgogn.unistra.fr/                                           *
* Contact information: cgogn@unistra.fr                                        *
*                                                                              *
*******************************************************************************/

#ifndef SCHNAPPS_PLUGIN_CMAP2_PROVIDER_H_
#define SCHNAPPS_PLUGIN_CMAP2_PROVIDER_H_

#include <schnapps/plugins/cmap2_provider/dll.h>
#include <schnapps/plugins/cmap2_provider/cmap2_handler.h>

#include <schnapps/core/types.h>
#include <schnapps/core/plugin_provider.h>

namespace schnapps
{

namespace plugin_cmap2_provider
{

class CMap2Provider_DockTab;

/**
* @brief CGoGN CMap2 provider
*/
class SCHNAPPS_PLUGIN_CMAP2_PROVIDER_API Plugin_CMap2Provider : public PluginProvider
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "SCHNApps.Plugin")
	Q_INTERFACES(schnapps::Plugin)

public:

	Plugin_CMap2Provider();
	inline ~Plugin_CMap2Provider() override {}	
	static QString plugin_name();

private:

	bool enable() override;
	void disable() override;

public:

	CMap2Handler* add_map(const QString& name);
	void remove_map(const QString& name);
	CMap2Handler* duplicate_map(const QString& name);
	CMap2Handler* map(const QString& name) const;

private slots:

	// slots called from SCHNApps signals
	void schnapps_closing();

private:

	CMap2Provider_DockTab* dock_tab_;
};

} // namespace plugin_cmap2_provider

} // namespace schnapps

#endif // SCHNAPPS_PLUGIN_CMAP2_PROVIDER_H_
