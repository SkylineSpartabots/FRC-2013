#include "CustomButtons.h"

CustomButton::PressTwo::PressTwo(Button *button1, Button *button2) :
		Button() {
	m_button1 = button1;
	m_button2 = button2;
}

CustomButton::PressTwo::~PressTwo() {
	// empty
}

bool CustomButton::PressTwo::Get() {
	bool a = m_button1->Get();
	bool b = m_button2->Get();
	SmartDashboard::PutBoolean("PressTwo a", a);
	SmartDashboard::PutBoolean("PressTwo b", b);
	SmartDashboard::PutBoolean("PressTwo combined", a && b);
	return a && b;
}



CustomButton::XboxTrigger::XboxTrigger(Joystick *joystick, int axis) :
		Button(),
		m_axis(axis){
	m_joystick = joystick; 
}

CustomButton::XboxTrigger::~XboxTrigger() {
	//empty
}

bool CustomButton::XboxTrigger::Get() {
	float value = m_joystick->GetRawAxis(m_axis);
	return (value > 0.5);
}
