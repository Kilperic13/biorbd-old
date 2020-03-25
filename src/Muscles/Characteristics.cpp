#define BIORBD_API_EXPORTS
#include "Muscles/Characteristics.h"

#include "Muscles/State.h"
#include "Muscles/FatigueParameters.h"

biorbd::muscles::Characteristics::Characteristics() :
    m_optimalLength(std::make_shared<biorbd::utils::Scalar>(0)),
    m_fIsoMax(std::make_shared<biorbd::utils::Scalar>(0)),
    m_PCSA(std::make_shared<biorbd::utils::Scalar>(0)),
    m_tendonSlackLength(std::make_shared<biorbd::utils::Scalar>(0)),
    m_pennationAngle(std::make_shared<biorbd::utils::Scalar>(0)),
    m_stateMax(std::make_shared<biorbd::muscles::State>(biorbd::muscles::State(1, 1))),
    m_minActivation(std::make_shared<double>(0.01)),
    m_torqueActivation(std::make_shared<double>(0.01)),
    m_torqueDeactivation(std::make_shared<double>(0.04)),
    m_fatigueParameters(std::make_shared<biorbd::muscles::FatigueParameters>(biorbd::muscles::FatigueParameters()))
{

}

biorbd::muscles::Characteristics::Characteristics(
        const biorbd::muscles::Characteristics &other) :
    m_optimalLength(other.m_optimalLength),
    m_fIsoMax(other.m_fIsoMax),
    m_PCSA(other.m_PCSA),
    m_tendonSlackLength(other.m_tendonSlackLength),
    m_pennationAngle(other.m_pennationAngle),
    m_stateMax(other.m_stateMax),
    m_minActivation(other.m_minActivation),
    m_torqueActivation(other.m_torqueActivation),
    m_torqueDeactivation(other.m_torqueDeactivation),
    m_fatigueParameters(other.m_fatigueParameters)
{

}

biorbd::muscles::Characteristics::Characteristics(
        biorbd::utils::Scalar optLength,
        biorbd::utils::Scalar fmax,
        biorbd::utils::Scalar PCSA,
        biorbd::utils::Scalar tendonSlackLength,
        biorbd::utils::Scalar pennAngle,
        const biorbd::muscles::State &emgMax,
        const biorbd::muscles::FatigueParameters &fatigueParameters,
        double torqueAct,
        double torqueDeact,
        double minAct):
    m_optimalLength(std::make_shared<biorbd::utils::Scalar>(optLength)),
    m_fIsoMax(std::make_shared<biorbd::utils::Scalar>(fmax)),
    m_PCSA(std::make_shared<biorbd::utils::Scalar>(PCSA)),
    m_tendonSlackLength(std::make_shared<biorbd::utils::Scalar>(tendonSlackLength)),
    m_pennationAngle(std::make_shared<biorbd::utils::Scalar>(pennAngle)),
    m_stateMax(std::make_shared<biorbd::muscles::State>(emgMax)),
    m_minActivation(std::make_shared<double>(minAct)),
    m_torqueActivation(std::make_shared<double>(torqueAct)),
    m_torqueDeactivation(std::make_shared<double>(torqueDeact)),
    m_fatigueParameters(std::make_shared<biorbd::muscles::FatigueParameters>(fatigueParameters))
{

}

biorbd::muscles::Characteristics::~Characteristics()
{

}

biorbd::muscles::Characteristics biorbd::muscles::Characteristics::DeepCopy() const
{
    biorbd::muscles::Characteristics copy;
    copy.DeepCopy(*this);
    return copy;
}

void biorbd::muscles::Characteristics::DeepCopy(
        const biorbd::muscles::Characteristics &other)
{
    *m_optimalLength = *other.m_optimalLength;
    *m_fIsoMax = *other.m_fIsoMax;
    *m_PCSA = *other.m_PCSA;
    *m_tendonSlackLength = *other.m_tendonSlackLength;
    *m_pennationAngle = *other.m_pennationAngle;
    *m_stateMax = other.m_stateMax->DeepCopy();
    *m_minActivation = *other.m_minActivation;
    *m_torqueActivation = *other.m_torqueActivation;
    *m_torqueDeactivation = *other.m_torqueDeactivation;
    *m_fatigueParameters = other.m_fatigueParameters->DeepCopy();
}

// Get et Set
void biorbd::muscles::Characteristics::setOptimalLength(biorbd::utils::Scalar val)
{
    *m_optimalLength = val;
}
biorbd::utils::Scalar biorbd::muscles::Characteristics::optimalLength() const
{
    return *m_optimalLength;
}

void biorbd::muscles::Characteristics::setForceIsoMax(biorbd::utils::Scalar val)
{
    *m_fIsoMax = val;
}
biorbd::utils::Scalar biorbd::muscles::Characteristics::forceIsoMax() const
{
    return *m_fIsoMax;
}

void biorbd::muscles::Characteristics::setTendonSlackLength(biorbd::utils::Scalar val)
{
    *m_tendonSlackLength = val;
}
biorbd::utils::Scalar biorbd::muscles::Characteristics::tendonSlackLength() const
{
    return *m_tendonSlackLength;
}

void biorbd::muscles::Characteristics::setPennationAngle(biorbd::utils::Scalar val)
{
    *m_pennationAngle = val;
}
biorbd::utils::Scalar biorbd::muscles::Characteristics::pennationAngle() const
{
    return *m_pennationAngle;
}

void biorbd::muscles::Characteristics::setPCSA(biorbd::utils::Scalar val)
{
    *m_PCSA = val;
}
biorbd::utils::Scalar biorbd::muscles::Characteristics::PCSA() const
{
    return *m_PCSA;
}

void biorbd::muscles::Characteristics::setMinActivation(double val)
{
    *m_minActivation = val;
}
biorbd::utils::Scalar biorbd::muscles::Characteristics::minActivation() const
{
    return *m_minActivation;
}

void biorbd::muscles::Characteristics::setTorqueActivation(double val)
{
    *m_torqueActivation = val;
}
double biorbd::muscles::Characteristics::torqueActivation() const
{
    return *m_torqueActivation;
}

void biorbd::muscles::Characteristics::setTorqueDeactivation(double val)
{
    *m_torqueDeactivation = val;
}
double biorbd::muscles::Characteristics::torqueDeactivation() const
{
    return *m_torqueDeactivation;
}


void biorbd::muscles::Characteristics::setStateMax(
        const biorbd::muscles::State &emgMax) {
    *m_stateMax = emgMax;
}
const biorbd::muscles::State &biorbd::muscles::Characteristics::stateMax() const {
    return *m_stateMax;
}

void biorbd::muscles::Characteristics::setFatigueParameters(const biorbd::muscles::FatigueParameters &fatigueParameters)
{
    *m_fatigueParameters = fatigueParameters;
}
const biorbd::muscles::FatigueParameters &biorbd::muscles::Characteristics::fatigueParameters() const
{
    return *m_fatigueParameters;
}

