#include "FrisbeeTurret.h"

BaseFrisbeeTurret::BaseFrisbeeTurret(const char *name) :
		BaseSubsystem(name) {
	// Empty
}

BaseFrisbeeTurret::~BaseFrisbeeTurret() {
	// Empty
}



PidFrisbeeTurret::PidFrisbeeTurret(
			SpeedController *horizontalMotor, 
			SpeedController *verticalMotor,
			Encoder *horizontalEncoder,
			Encoder *verticalEncoder) :
			BaseFrisbeeTurret("PidFrisbeeTurret"),
			m_offset(0.0f, 0.0f) {
	m_horizontalMotor = horizontalMotor;
	m_verticalMotor = verticalMotor;
	m_horizontalEncoder = horizontalEncoder;
	m_verticalEncoder = verticalEncoder;
	
	m_horizontalEncoder->SetPIDSourceParameter(m_horizontalEncoder->kDistance);
	m_verticalEncoder->SetPIDSourceParameter(m_verticalEncoder->kDistance);
	
	m_horizontalPid = new PIDController(
			0.1, 0.01, 0, 
			m_horizontalEncoder, 
			m_horizontalMotor);
	
	m_verticalPid = new PIDController(
			0.1, 0.01, 0,
			m_verticalEncoder,
			m_verticalMotor);
	
	m_horizontalPid->Enable();
	m_verticalPid->Enable();
	
	AddActuatorToLiveWindow("Horizontal PID", m_horizontalPid);
	AddActuatorToLiveWindow("Vertical PID", m_verticalPid);
	
	AddSensorToLiveWindow("Horizontal Encoder", m_horizontalEncoder);
	AddSensorToLiveWindow("Vertical Encoder", m_verticalEncoder);
}

PidFrisbeeTurret::~PidFrisbeeTurret() {
	// empty
}

void PidFrisbeeTurret::TurnHorizontal(float degrees) {
	m_offset.XOffset += degrees;
	m_horizontalPid->SetSetpoint(degrees);
}

void PidFrisbeeTurret::TurnVertical(float degrees) {
	m_offset.YOffset += degrees;
	m_verticalPid->SetSetpoint(degrees);
}

void PidFrisbeeTurret::TurnGivenOffset(Tracking::Offset offset) {
	TurnHorizontal(offset.XOffset);
	TurnVertical(offset.YOffset);
}

Tracking::Offset PidFrisbeeTurret::GetCurrentOffset() {
	return m_offset;
}

