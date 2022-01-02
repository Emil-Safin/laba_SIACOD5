#include "MyForm.h"
#include "Cont.h"
#include "Graf.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	labaSIACOD5::MyForm form;
	Application::Run(% form);
}
