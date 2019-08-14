#ifndef BIORBD_RIGIDBODY_KALMAN_RECONS_IMU_H
#define BIORBD_RIGIDBODY_KALMAN_RECONS_IMU_H

#include "biorbdConfig.h"
#include "RigidBody/KalmanRecons.h"

namespace biorbd { namespace utils {
class Attitude;
}}

namespace biorbd { namespace rigidbody {

class BIORBD_API KalmanReconsIMU : public biorbd::rigidbody::KalmanRecons
{
public:

    // Constructeur
    KalmanReconsIMU(
            s2mMusculoSkeletalModel&,
            biorbd::rigidbody::KalmanRecons::KalmanParam = biorbd::rigidbody::KalmanRecons::KalmanParam(100, 0.005, 1e-10));
    virtual ~KalmanReconsIMU();

    // Reconstruction d'un frame
    virtual void reconstructFrame(
            s2mMusculoSkeletalModel &m,
            const std::vector<biorbd::utils::Attitude> &IMUobs,
            biorbd::utils::GenCoord *Q,
            biorbd::utils::GenCoord *Qdot,
            biorbd::utils::GenCoord *Qddot);
    virtual void reconstructFrame(
            s2mMusculoSkeletalModel &m,
            const Eigen::VectorXd &IMUobs,
            biorbd::utils::GenCoord *Q,
            biorbd::utils::GenCoord *Qdot,
            biorbd::utils::GenCoord *Qddot);
    virtual void reconstructFrame();

    bool first();

protected:
    virtual void initialize();
    virtual void manageOcclusionDuringIteration(
            biorbd::utils::Matrix&,
            Eigen::VectorXd &measure,
            const std::vector<unsigned int> &occlusion);

    biorbd::utils::Matrix m_PpInitial; // Se souvenir de Pp inital
    bool m_firstIteration;
};

}}

#endif // BIORBD_RIGIDBODY_KALMAN_RECONS_IMU_H
