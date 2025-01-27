// =============================================================================
// PROJECT CHRONO - http://projectchrono.org
//
// Copyright (c) 2014 projectchrono.org
// All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be found
// in the LICENSE file at the top level of the distribution and at
// http://projectchrono.org/license-chrono.txt.
//
// =============================================================================
// Authors: Radu Serban
// =============================================================================
//
// LuGre tire constructed with data from file (JSON format).
//
// =============================================================================

#ifndef LUGRE_TIRE_H
#define LUGRE_TIRE_H

#include "chrono/assets/ChTriangleMeshShape.h"

#include "chrono_vehicle/ChApiVehicle.h"
#include "chrono_vehicle/wheeled_vehicle/tire/ChLugreTire.h"

#include "chrono_thirdparty/rapidjson/document.h"

namespace chrono {
namespace vehicle {

/// @addtogroup vehicle_wheeled_tire
/// @{

/// LuGre tire constructed with data from file (JSON format).
class CH_VEHICLE_API LugreTire : public ChLugreTire {
  public:
    LugreTire(const std::string& filename);
    LugreTire(const rapidjson::Document& d);
    ~LugreTire();

    virtual double GetRadius() const override { return m_radius; }

    virtual int GetNumDiscs() const override { return m_numDiscs; }
    virtual const double* GetDiscLocations() const override { return m_discLocs; }

    virtual double GetNormalStiffness() const override { return m_normalStiffness; }
    virtual double GetNormalDamping() const override { return m_normalDamping; }

    virtual double GetMass() const override { return m_mass; }
    virtual ChVector<> GetInertia() const override { return m_inertia; }

    virtual void SetLugreParams() override {}

    virtual void AddVisualizationAssets(VisualizationType vis) override;
    virtual void RemoveVisualizationAssets() override final;

    std::string GetMeshName() const override { return m_meshName; }
    std::string GetMeshFile() const override { return m_meshFile; }
    
  private:
    virtual void Create(const rapidjson::Document& d) override;

    double m_radius;
    int m_numDiscs;
    double* m_discLocs;

    double m_normalStiffness;
    double m_normalDamping;

    double m_mass;
    ChVector<> m_inertia;

    bool m_has_mesh;
    std::string m_meshName;
    std::string m_meshFile;
    std::shared_ptr<ChTriangleMeshShape> m_trimesh_shape;
};

/// @} vehicle_wheeled_tire

}  // end namespace vehicle
}  // end namespace chrono

#endif
