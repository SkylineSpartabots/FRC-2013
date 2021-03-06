#include "CompetitionOI.h"

CompetitionOI::CompetitionOI(XboxController *xbox) :
		BaseOI("CompetitionOI") {
	TankLeftAxis = new Axis(xbox, xbox->LeftY);
	TankRightAxis = new Axis(xbox, xbox->RightY);
	ArcadeMagnitudeAxis = new Axis(xbox, xbox->LeftY);
	ArcadeRotationAxis = new Axis(xbox, xbox->RightX);
	DriveStraightAxis = new Axis(xbox, xbox->LeftY);
	ControlWinchAxis = NULL;
	
	DriveStraightButton = new JoystickButton(xbox, xbox->A);
	ToggleTransmissionButton = new JoystickButton(xbox, xbox->B);
	FireFrisbeeButton = new JoystickButton(xbox, xbox->X);
	ClimbRobotButton = new JoystickButton(xbox, xbox->Y);
}

CompetitionOI::~CompetitionOI() {
	delete TankLeftAxis;
	delete TankRightAxis;
	delete ArcadeMagnitudeAxis;
	delete ArcadeRotationAxis;
	delete DriveStraightAxis;
	delete ControlWinchAxis;
	
	delete DriveStraightButton;
	delete ToggleTransmissionButton;
	delete FireFrisbeeButton;
	delete ClimbRobotButton;
}


XboxTwoJoysticksOI::XboxTwoJoysticksOI(XboxController *xbox, Joystick *leftStick, Joystick *rightStick) :
		BaseOI("XboxTwoJoysticksOI") {
	TankLeftAxis = new Axis(xbox, xbox->LeftY);
	TankRightAxis = new Axis(xbox, xbox->RightY);
	DriveStraightAxis = new Axis(xbox, xbox->LeftY);
	RotateTurretAxis = new Axis(leftStick, Joystick::kDefaultXAxis);
	LiftTurretAxis = new Axis(leftStick, Joystick::kDefaultYAxis);
	ControlWinchAxis = new Axis(rightStick, Joystick::kDefaultYAxis);
	
	DriveStraightButton = new JoystickButton(xbox, xbox->LeftBumper);
	ToggleTransmissionButton = new JoystickButton(xbox, xbox->RightBumper);
	FireFrisbeeButton = new JoystickButton(xbox, xbox->A);
}

XboxTwoJoysticksOI::~XboxTwoJoysticksOI() {
	delete TankLeftAxis;
	delete TankRightAxis;
	delete DriveStraightAxis;
	delete RotateTurretAxis;
	delete LiftTurretAxis;
	delete ControlWinchAxis;
	
	delete DriveStraightButton;
	delete ToggleTransmissionButton;
	delete FireFrisbeeButton;
}


CompetitionJoystickOI::CompetitionJoystickOI(Joystick *rightJoystick, Joystick *leftJoystick, Joystick *twistJoystick) :
		BaseOI("CompetitionJoystickOI") {
	TankLeftAxis = new Axis(leftJoystick, Joystick::kDefaultYAxis);
	TankRightAxis = new Axis(rightJoystick, Joystick::kDefaultYAxis);
	ArcadeMagnitudeAxis = new Axis(twistJoystick, Joystick::kDefaultYAxis);
	ArcadeRotationAxis = new Axis(twistJoystick, Joystick::kDefaultTwistAxis);
	DriveStraightAxis = new Axis(leftJoystick, Joystick::kDefaultYAxis);
	ControlWinchAxis = new Axis(rightJoystick, Joystick::kDefaultXAxis);
	
	DriveStraightButton = new JoystickButton(leftJoystick, 3);
	ToggleTransmissionButton = NULL; // don't know yet
	FireFrisbeeButton = new JoystickButton(twistJoystick, 10);
	ClimbRobotButton = new JoystickButton(twistJoystick, 9);
}

CompetitionJoystickOI::~CompetitionJoystickOI() {
	delete TankLeftAxis;
	delete TankRightAxis;
	delete ArcadeMagnitudeAxis;
	delete ArcadeRotationAxis;
	delete DriveStraightAxis;
	delete ControlWinchAxis;
	
	delete DriveStraightButton;
	delete ToggleTransmissionButton;
	delete FireFrisbeeButton;
	delete ClimbRobotButton;
}
		
