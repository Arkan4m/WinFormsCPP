#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
    
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    FormsLab1::Form1 form;
    Application::Run(% form);

    return 0;
}