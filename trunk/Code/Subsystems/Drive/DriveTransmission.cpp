#include "DriveTransmission.h"

BaseDriveTransmission::BaseDriveTransmission(const char *name) :
		BaseSubsystem(name) {
	// empty
}

BaseDriveTransmission::~BaseDriveTransmission() {
	// empty
}


SimpleDriveTransmission::SimpleDriveTransmission(Solenoid *leftPiston, Solenoid *rightPiston) :
		BaseDriveTransmission("SimpleDriveTransmision") {
	m_leftPiston = leftPiston;
	m_rightPiston = rightPiston;
}

SimpleDriveTransmission::~SimpleDriveTransmission() {
	// empty
}

void SimpleDriveTransmission::SetHighGear() {
	m_leftPiston->Set(true);
	m_rightPiston->Set(true);
}

void SimpleDriveTransmission::SetLowGear() {
	m_leftPiston->Set(false);
	m_rightPiston->Set(false);
}

SimpleDriveTransmission::TransmissionMode SimpleDriveTransmission::GetCurrentMode() {
	bool left = m_leftPiston->Get();
	bool right = m_rightPiston->Get();
	
	if (left != right) {
		return Error;
	} else if (left) {
		return HighGear;
	} else {
		return LowGear;
	}
}
