#include "BlandRobotProfile.h"

BlandRobotProfile::BlandRobotProfile() :
		BaseRobotProfile("BlandRobotProfile") {
	CreateBasicHardwareObjects();
	CreateSubsystems();
	CreateOI();
}

BlandRobotProfile::~BlandRobotProfile() {
	// empty
}

void BlandRobotProfile::CreateBasicHardwareObjects() {
	m_leftFrontMotor = new Talon(
			Ports::Crio::Module1,
			Ports::DigitalSidecar::Pwm1);
	m_leftBackMotor = new Talon(
			Ports::Crio::Module1,
			Ports::DigitalSidecar::Pwm2);
	m_rightFrontMotor = new Talon(
			Ports::Crio::Module1,
			Ports::DigitalSidecar::Pwm3);
	m_rightBackMotor = new Talon(
			Ports::Crio::Module1,
			Ports::DigitalSidecar::Pwm4);
	m_leftTread = new Tread(
			m_leftFrontMotor,
			m_leftBackMotor);
	m_rightTread = new Tread(
			m_rightFrontMotor,
			m_rightBackMotor);
	m_xbox = new XboxController(
			Ports::Computer::Usb1);
}

void BlandRobotProfile::CreateSubsystems() {
	m_drive = new SimpleDrive(m_leftTread, m_rightTread);
}

void BlandRobotProfile::CreateOI() {
	m_oi = new SimpleOI(m_xbox);
}

void BlandRobotProfile::RobotInit() {
	// empty
}

void BlandRobotProfile::AutonomousInit() {
	// empty
}

void BlandRobotProfile::TeleopInit() {
	m_drive->SetDefaultCommand(new TankDriveCommand(
			m_drive, 
			m_oi->TankLeftAxis,
			m_oi->TankRightAxis));
}

